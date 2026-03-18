#pragma once

#include "CoreMinimal.h"
#include "DifficultyTypes.generated.h"

UENUM(BlueprintType)
enum class EDifficulty : uint8
{
	Easy,
	Medium,
	Hard,
	Nightmare
};
