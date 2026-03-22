// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthAttributeSet.h"

void UHealthAttributeSet::PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue)
{
	Super::PostAttributeChange(Attribute, OldValue, NewValue);
	
	bool ShouldCheckForMaxHealthCap = false;
	
	if (Attribute == GetHealthAttribute())
	{
		ShouldCheckForMaxHealthCap = true;
		FGameplayAbilityActorInfo* ActorInfo = GetActorInfo();
		
		if (!ActorInfo)
		{
			return;
		}

		TWeakObjectPtr<AActor> Actor = ActorInfo->AvatarActor;
		
		if (!Actor.IsValid())
		{
			return;
		}
		
		if (NewValue < 0)
		{
			Actor->Destroy();
			return;
		}
	}
	
	if (!ShouldCheckForMaxHealthCap)
	{
		ShouldCheckForMaxHealthCap = Attribute == GetMaxHealthAttribute();
	}
	
	if (ShouldCheckForMaxHealthCap)
	{
		const float MaxHealthValue = GetMaxHealth();
		if (NewValue > MaxHealthValue)
		{
			SetHealth(MaxHealthValue);
		}
	}
}
