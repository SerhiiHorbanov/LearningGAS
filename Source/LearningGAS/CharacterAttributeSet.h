// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "CharacterAttributeSet.generated.h"

UCLASS()
class LEARNINGGAS_API UCharacterAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY()
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS_BASIC(UCharacterAttributeSet, Health)
	
	UPROPERTY()
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS_BASIC(UCharacterAttributeSet, MaxHealth)
	
	UPROPERTY()
	FGameplayAttributeData Armor;
	ATTRIBUTE_ACCESSORS_BASIC(UCharacterAttributeSet, Armor)
	
	UPROPERTY()
	FGameplayAttributeData Damage;
	ATTRIBUTE_ACCESSORS_BASIC(UCharacterAttributeSet, Damage)
	
	UPROPERTY()
	FGameplayAttributeData Speed;
	ATTRIBUTE_ACCESSORS_BASIC(UCharacterAttributeSet, Speed)
	
	virtual void PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue) override;
};
