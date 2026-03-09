// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "MovementAttributeSet.generated.h"

UCLASS()
class LEARNINGGAS_API UMovementAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY()
	FGameplayAttributeData Stamina;
	ATTRIBUTE_ACCESSORS_BASIC(UMovementAttributeSet, Stamina)
	
	UPROPERTY()
	FGameplayAttributeData StaminaRegeneration;
	ATTRIBUTE_ACCESSORS_BASIC(UMovementAttributeSet, StaminaRegeneration)
	
	UPROPERTY()
	FGameplayAttributeData MaxStamina;
	ATTRIBUTE_ACCESSORS_BASIC(UMovementAttributeSet, MaxStamina)
};
