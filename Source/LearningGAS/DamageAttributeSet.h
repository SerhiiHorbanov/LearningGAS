// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "DamageAttributeSet.generated.h"

UCLASS()
class LEARNINGGAS_API UDamageAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY()
	FGameplayAttributeData Damage;
	ATTRIBUTE_ACCESSORS_BASIC(UDamageAttributeSet, Damage)
};
