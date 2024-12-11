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
	CarTalk = 5,
	StopCar = 6,
	RadioStateChange = 7,
	Silhouette = 8,
	Sound = 9
};