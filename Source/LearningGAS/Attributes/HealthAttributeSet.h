// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "HealthAttributeSet.generated.h"

UCLASS()
class LEARNINGGAS_API UHealthAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY()
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS_BASIC(UHealthAttributeSet, Health)
	
	UPROPERTY()
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS_BASIC(UHealthAttributeSet, MaxHealth)
	
	UPROPERTY()
	FGameplayAttributeData Armor;
	ATTRIBUTE_ACCESSORS_BASIC(UHealthAttributeSet, Armor)
	
	virtual void PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue) override;
};
