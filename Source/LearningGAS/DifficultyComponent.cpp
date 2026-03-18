// Fill out your copyright notice in the Description page of Project Settings.


#include "DifficultyComponent.h"

UDifficultyComponent::UDifficultyComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	Difficulty = EDifficulty::Medium;
}

