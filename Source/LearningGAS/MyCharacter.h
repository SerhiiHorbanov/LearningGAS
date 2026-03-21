// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

UCLASS()
class LEARNINGGAS_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()
	
	void RefreshAbilitySystemActorInfo();
	
	virtual void PossessedBy(AController* NewController) override;
	virtual void UnPossessed() override;
};
