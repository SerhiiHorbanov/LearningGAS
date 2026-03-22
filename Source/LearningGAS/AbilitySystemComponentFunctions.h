// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Templates/SubclassOf.h"
#include "AbilitySystemComponentFunctions.generated.h"

class UAbilitySystemComponent;
class UGameplayAbility;

UCLASS()
class LEARNINGGAS_API UAbilitySystemComponentFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "AbilitySystem")
	static bool IsAbilityActiveByClass(const UAbilitySystemComponent* ASC, TSubclassOf<UGameplayAbility> AbilityClass);
};
