// Fill out your copyright notice in the Description page of Project Settings.


#include "DamageExecutionCalculation.h"
#include "HealthAttributeSet.h"
#include "DamageAttributeSet.h"
#include "DifficultySubsystem.h"
#include "DifficultyTypes.h"

struct FDamageStatics
{
	DECLARE_ATTRIBUTE_CAPTUREDEF(Damage);
	DECLARE_ATTRIBUTE_CAPTUREDEF(Armor);

	FDamageStatics()
	{
		// Capture Damage from the Source (damager)
		DEFINE_ATTRIBUTE_CAPTUREDEF(UDamageAttributeSet, Damage, Source, true);
		
		// Capture Armor from the Target
		DEFINE_ATTRIBUTE_CAPTUREDEF(UHealthAttributeSet, Armor, Target, false);
	}
};

static const FDamageStatics& DamageStatics()
{
	static FDamageStatics DStatics;
	return DStatics;
}

UDamageExecutionCalculation::UDamageExecutionCalculation()
{
	RelevantAttributesToCapture.Add(DamageStatics().DamageDef);
	RelevantAttributesToCapture.Add(DamageStatics().ArmorDef);
}

void UDamageExecutionCalculation::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	UAbilitySystemComponent* TargetASC = ExecutionParams.GetTargetAbilitySystemComponent();
	UAbilitySystemComponent* SourceASC = ExecutionParams.GetSourceAbilitySystemComponent();

	if (!TargetASC || !SourceASC)
	{
		return;
	}

	FAggregatorEvaluateParameters EvaluationParameters;

	float DamageValue = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(DamageStatics().DamageDef, EvaluationParameters, DamageValue);
	
	float ArmorValue = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(DamageStatics().ArmorDef, EvaluationParameters, ArmorValue);

	float DamageDone = FMath::Max(1.0f, DamageValue - (ArmorValue * GetArmorMultiplier(TargetASC->GetWorld())));
	
	OutExecutionOutput.AddOutputModifier(FGameplayModifierEvaluatedData(UHealthAttributeSet::GetHealthAttribute(), EGameplayModOp::Additive, -DamageDone));
}

float UDamageExecutionCalculation::GetArmorMultiplier(const UWorld* World) const
{
	check(World)
	UDifficultySubsystem* DifficultySubsystem = World->GetSubsystem<UDifficultySubsystem>();
	check(DifficultySubsystem)
	
	EDifficulty Difficulty = DifficultySubsystem->GetCurrentDifficulty();
	switch (Difficulty)
	{
		default: 
			return 0.5f;
		case EDifficulty::Hard:
			return 0.75f;
		case EDifficulty::Nightmare:
			return 1.0f;
	}
}
