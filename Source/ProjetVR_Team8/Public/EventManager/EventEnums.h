#pragma once
#include "CoreMinimal.h"
#include "EventEnums.generated.h"

UENUM(BlueprintType)
enum ECarSoundType
{
	Left,
	Right
};

UENUM()
enum ERoadAppearanceType
{
	NormalSign = 0,
	WeirdSign = 1,
	Silhouette = 2,
	Cerf = 3
};