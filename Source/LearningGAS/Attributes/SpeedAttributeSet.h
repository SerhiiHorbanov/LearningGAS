// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "SpeedAttributeSet.generated.h"

UCLASS()
class LEARNINGGAS_API USpeedAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY()
	FGameplayAttributeData Speed;
	ATTRIBUTE_ACCESSORS_BASIC(USpeedAttributeSet, Speed)
};
