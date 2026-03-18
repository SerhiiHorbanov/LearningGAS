// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DifficultyTypes.h"
#include "DifficultyComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LEARNINGGAS_API UDifficultyComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UDifficultyComponent();

public:	
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Difficulty")
	EDifficulty Difficulty;
};
