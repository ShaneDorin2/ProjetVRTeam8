#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EHandGrabState : uint8
{
	NO_HAND = 0,
	ONE_HAND,
	TWO_HANDS,
};