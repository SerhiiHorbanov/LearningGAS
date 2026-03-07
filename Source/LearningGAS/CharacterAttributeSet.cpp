// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterAttributeSet.h"

void UCharacterAttributeSet::PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue)
{
	Super::PostAttributeChange(Attribute, OldValue, NewValue);
	
	if (Attribute == GetHealthAttribute())
	{
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
		}
		else
		{
			const float MaxHealthValue = GetMaxHealth();
			if (NewValue > MaxHealthValue)
			{
				SetHealth(MaxHealthValue);
			}
		}
	}
}
