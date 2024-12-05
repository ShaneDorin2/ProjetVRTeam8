#pragma once

#include "CoreMinimal.h"
#include "EventSettings.h"
#include "Subsystems/WorldSubsystem.h"
#include "EventManagerSubSystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FEventManager_UnlockDoors);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FEventManager_LightFlicker);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FEventManager_RadioBug);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FEventManager_RoadAppearance);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FEventManager_RoadTurn);

UCLASS()
class PROJETVR_TEAM8_API UEventManagerSubSystem : public UWorldSubsystem
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintAssignable)
	FEventManager_UnlockDoors OnUnlockDoorEvent;
	
	UPROPERTY(BlueprintAssignable)
	FEventManager_LightFlicker OnLightFlickerEvent;
	
	UPROPERTY(BlueprintAssignable)
	FEventManager_RadioBug OnRadioBugEvent;
	
	UPROPERTY(BlueprintAssignable)
	FEventManager_RoadAppearance OnRoadAppearanceEvent;
	
	UPROPERTY(BlueprintAssignable)
	FEventManager_RoadTurn OnRoadTurnEvent;

private:
	float TimeElapsed;
};
