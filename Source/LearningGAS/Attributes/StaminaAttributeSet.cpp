// Fill out your copyright notice in the Description page of Project Settings.


#include "StaminaAttributeSet.h"

void UStaminaAttributeSet::PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue)
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
