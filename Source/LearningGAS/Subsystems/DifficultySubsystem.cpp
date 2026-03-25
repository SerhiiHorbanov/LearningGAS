// Fill out your copyright notice in the Description page of Project Settings.

#include "DifficultySubsystem.h"
#include "GameFramework/GameStateBase.h"
#include "Engine/World.h"
#include "LearningGAS/DifficultyComponent.h"
#include "LearningGAS/Settings/DifficultySettings.h"

EDifficulty UDifficultySubsystem::GetCurrentDifficulty()
{
	if (UDifficultyComponent* DifficultyComp = GetDifficultyComponent())
	{
		return DifficultyComp->Difficulty;
	}

	return EDifficulty::Medium;
}

UDifficultyComponent* UDifficultySubsystem::GetDifficultyComponent()
{
	if (CachedDifficultyComponent.IsValid())
	{
		return CachedDifficultyComponent.Get();
	}

	if (UWorld* World = GetWorld())
	{
		if (AGameStateBase* GameState = World->GetGameState())
		{
			UDifficultyComponent* DifficultyComp = GameState->FindComponentByClass<UDifficultyComponent>();
			CachedDifficultyComponent = DifficultyComp;
			return DifficultyComp;
		}
	}

	return nullptr;
}

void UDifficultySubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	const UDifficultySettings* DifficultySettings = GetDefault<UDifficultySettings>();
	

}
