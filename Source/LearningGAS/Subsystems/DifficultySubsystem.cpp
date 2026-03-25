// Fill out your copyright notice in the Description page of Project Settings.

#include "DifficultySubsystem.h"
#include "Engine/World.h"
#include "LearningGAS/Settings/DifficultySettings.h"

EDifficulty UDifficultySubsystem::GetCurrentDifficulty()
{
	return Difficulty;
}

void UDifficultySubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	const UDifficultySettings* DifficultySettings = GetDefault<UDifficultySettings>();
	
	if (!DifficultySettings)
	{
		UE_LOG(LogTemp, Error, TEXT("No Difficulty Settings Found"));
		Difficulty = EDifficulty::Medium;
		return;
	}
	
	Difficulty = DifficultySettings->InitialDifficulty;
}
