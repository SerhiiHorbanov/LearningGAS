// Fill out your copyright notice in the Description page of Project Settings.


#include "MovementAttributeSet.h"

void UMovementAttributeSet::PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue)
{	Super::PostAttributeChange(Attribute, OldValue, NewValue);
	
	bool ShouldCheckForMaxStaminaCap = false;
	
	if (Attribute == GetStaminaAttribute())
	{
		ShouldCheckForMaxStaminaCap = true;
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
	
	if (!ShouldCheckForMaxStaminaCap)
	{
		ShouldCheckForMaxStaminaCap = Attribute == GetMaxStaminaAttribute();
	}
	
	if (ShouldCheckForMaxStaminaCap)
	{
		const float MaxStaminaValue = GetMaxStamina();
		if (NewValue > MaxStaminaValue)
		{
			SetStamina(MaxStaminaValue);
		}
	}
}
