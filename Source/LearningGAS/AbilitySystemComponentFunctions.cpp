// Fill out your copyright notice in the Description page of Project Settings.

#include "AbilitySystemComponentFunctions.h"
#include "AbilitySystemComponent.h"
#include "Abilities/GameplayAbility.h"

bool UAbilitySystemComponentFunctions::IsAbilityActiveByClass(const UAbilitySystemComponent* ASC, TSubclassOf<UGameplayAbility> AbilityClass)
{
	if (!ASC || !AbilityClass)
	{
		return false;
	}

	for (const FGameplayAbilitySpec& Spec : ASC->GetActivatableAbilities())
	{
		if (Spec.Ability && Spec.Ability->GetClass() == AbilityClass)
		{
			if (Spec.IsActive())
			{
				return true;
			}
		}
	}

	return false;
}
