// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "AbilitySystemComponent.h"

class UAbilitySystemComponent;


void AMyCharacter::RefreshAbilitySystemActorInfo()
{
	UAbilitySystemComponent* ASC = GetComponentByClass<UAbilitySystemComponent>();
	
	if (ASC)
	{
		ASC->RefreshAbilityActorInfo();
	}
}

void AMyCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	
	RefreshAbilitySystemActorInfo();
}

void AMyCharacter::UnPossessed()
{
	Super::UnPossessed();

	RefreshAbilitySystemActorInfo();
}
