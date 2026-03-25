// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "StaminaAttributeSet.generated.h"

UCLASS()
class LEARNINGGAS_API UStaminaAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY()
	FGameplayAttributeData Stamina;
	ATTRIBUTE_ACCESSORS_BASIC(UStaminaAttributeSet, Stamina)
	
	UPROPERTY()
	FGameplayAttributeData StaminaRegeneration;
	ATTRIBUTE_ACCESSORS_BASIC(UStaminaAttributeSet, StaminaRegeneration)
	
	UPROPERTY()
	FGameplayAttributeData MaxStamina;
	ATTRIBUTE_ACCESSORS_BASIC(UStaminaAttributeSet, MaxStamina)
	
	virtual void PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue) override;
};
