// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "LearningGAS/DifficultyTypes.h"
#include "DifficultySettings.generated.h"

UCLASS(Config=Game, DefaultConfig, meta=(DisplayName="Difficulty"))
class LEARNINGGAS_API UDifficultySettings : public UDeveloperSettings
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY(Config, EditAnywhere, Category = "Difficulty")
	EDifficulty InitialDifficulty;
};
