// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Tasks/AbilityTask.h"
#include "GameplayTagContainer.h"
#include "GameplayEffectTypes.h"
#include "StaminaRegenTask.generated.h"


class UGameplayEffect;

UCLASS()
class LEARNINGGAS_API UStaminaRegenTask : public UAbilityTask
{
	GENERATED_BODY()

public:
	UStaminaRegenTask();

	UFUNCTION(BlueprintCallable, Category = "Ability|Tasks", meta = (HidePin = "OwningAbility", DefaultToSelf = "OwningAbility", BlueprintInternalUseOnly = "TRUE"))
	static UStaminaRegenTask* CreateStaminaRegenTask(UGameplayAbility* OwningAbility, TSubclassOf<UGameplayEffect> InRegenEffectClass, FGameplayTag InStaminaRegenTag);

	virtual void TickTask(float DeltaTime) override;

protected:
	UPROPERTY()
	TSubclassOf<UGameplayEffect> RegenEffectClass;

	UPROPERTY()
	FGameplayTag StaminaRegenTag;
};
