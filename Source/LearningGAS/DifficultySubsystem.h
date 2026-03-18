// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "DifficultyTypes.h"
#include "DifficultySubsystem.generated.h"

class UDifficultyComponent;

UCLASS()
class LEARNINGGAS_API UDifficultySubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Difficulty")
	EDifficulty GetCurrentDifficulty();

private:
	TWeakObjectPtr<UDifficultyComponent> CachedDifficultyComponent;

	UDifficultyComponent* GetDifficultyComponent();
};
