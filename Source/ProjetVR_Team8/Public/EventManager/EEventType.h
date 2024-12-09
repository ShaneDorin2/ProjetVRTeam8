#pragma once
#include "CoreMinimal.h"
#include "EEventType.generated.h"

UENUM()
enum EEventType
{
	UnlockDoors = 0,
	LightFlicker = 1,
	RadioBug = 2,
	RoadAppearance = 3,
	RoadTurn = 4,
	CarTalk = 5
};