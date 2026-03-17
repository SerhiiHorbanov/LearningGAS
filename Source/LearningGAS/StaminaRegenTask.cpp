// Fill out your copyright notice in the Description page of Project Settings.


#include "StaminaRegenTask.h"
#include "AbilitySystemComponent.h"
#include "MovementAttributeSet.h"
#include "GameplayTagContainer.h"

UStaminaRegenTask::UStaminaRegenTask()
{
	bTickingTask = true;
}

UStaminaRegenTask* UStaminaRegenTask::CreateStaminaRegenTask(UGameplayAbility* OwningAbility, TSubclassOf<UGameplayEffect> InRegenEffectClass, FGameplayTag InStaminaRegenTag)
{
	UStaminaRegenTask* MyObj = NewAbilityTask<UStaminaRegenTask>(OwningAbility);
	MyObj->RegenEffectClass = InRegenEffectClass;
	MyObj->StaminaRegenTag = InStaminaRegenTag;
	return MyObj;
}

void UStaminaRegenTask::TickTask(float DeltaTime)
{
	Super::TickTask(DeltaTime);

	UAbilitySystemComponent* MyASC = AbilitySystemComponent.Get();
	if (MyASC && RegenEffectClass)
	{
		float StaminaRegen = MyASC->GetNumericAttribute(UMovementAttributeSet::GetStaminaRegenerationAttribute());
		float RegenMagnitude = DeltaTime * StaminaRegen;

		FGameplayEffectContextHandle EffectContext = MyASC->MakeEffectContext();
		EffectContext.AddInstigator(GetAvatarActor(), GetAvatarActor());

		FGameplayEffectSpecHandle SpecHandle = MyASC->MakeOutgoingSpec(RegenEffectClass, 1.0f, EffectContext);
		if (SpecHandle.IsValid())
		{
			SpecHandle.Data.Get()->SetSetByCallerMagnitude(StaminaRegenTag, RegenMagnitude);
			MyASC->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
		}
	}
}
