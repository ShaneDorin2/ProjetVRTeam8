#pragma once

#include "CoreMinimal.h"
#include "EventEnums.h"
#include "Subsystems/WorldSubsystem.h"
#include "EventManagerSubSystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FEventManager_StopCar);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FEventManager_UnlockDoors);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FEventManager_LightFlicker);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FEventManager_RadioBug);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FEventManager_RoadTurn);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FEventManager_Silhouette);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FEventManager_Sound);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEventManager_RoadAppearance, ERoadAppearanceType, RoadAppearanceType);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEventManager_CarTalk, ECarSoundType, CarTalkSound);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEventManager_RadioStateChange, bool, IsOn);


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FEventManager_Reboot);

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
	FEventManager_RadioStateChange OnRadioStateChange;
	
	UPROPERTY(BlueprintAssignable)
	FEventManager_RoadAppearance OnRoadAppearanceEvent;
	
	UPROPERTY(BlueprintAssignable)
	FEventManager_RoadTurn OnRoadTurnEvent;

	UPROPERTY(BlueprintAssignable)
	FEventManager_CarTalk OnCarTalkEvent;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FEventManager_Reboot OnRebootEvent;

	UPROPERTY(BlueprintAssignable)
	FEventManager_StopCar OnCarStop;

	UPROPERTY(BlueprintAssignable)
	FEventManager_Silhouette OnSilhouette;

	UPROPERTY(BlueprintAssignable)
	FEventManager_Sound OnSound;
};
