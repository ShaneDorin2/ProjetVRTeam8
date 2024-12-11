#pragma once

#include "CoreMinimal.h"
#include "EEventType.h"
#include "EventEnums.h"
#include "FEventInfo.generated.h"

UCLASS(Abstract, EditInlineNew)
class UEventInfoClass : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TEnumAsByte<EEventType> EventType;
	
	UPROPERTY(EditAnywhere, Category="Event")
	float EventTime;
};

#pragma region EventDeclaration

UCLASS()
class UEventUnlockDoors : public UEventInfoClass
{
	GENERATED_BODY()
	UEventUnlockDoors()
	{
		EventType = TEnumAsByte<EEventType>(0);
	}
};

UCLASS()
class UEventLightFlicker : public UEventInfoClass
{
	GENERATED_BODY()
	UEventLightFlicker()
	{
		EventType = TEnumAsByte<EEventType>(1);
	}
};

UCLASS()
class UEventRadioBug : public UEventInfoClass
{
	GENERATED_BODY()
	UEventRadioBug()
	{
		EventType = TEnumAsByte<EEventType>(2);
	}
};

UCLASS()
class UEventRoadAppearance : public UEventInfoClass
{
	GENERATED_BODY()
	
public :
	UPROPERTY(EditAnywhere, Category="Event")
	TEnumAsByte<ERoadAppearanceType> RoadAppearanceType;
	
	UEventRoadAppearance()
	{
		EventType = TEnumAsByte<EEventType>(3);
	}
};

UCLASS()
class UEventRoadTurn : public UEventInfoClass
{
	GENERATED_BODY()
	UEventRoadTurn()
	{
		EventType = TEnumAsByte<EEventType>(4);
	}
};

UCLASS()
class UEventInfoCarTalk : public UEventInfoClass
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, Category="Event")
	TEnumAsByte<ECarSoundType> CarTalkSound;
	
	UEventInfoCarTalk()
	{
		EventType = TEnumAsByte<EEventType>(5);
	}
};

UCLASS()
class UEventStopCar : public UEventInfoClass
{
	GENERATED_BODY()
	UEventStopCar()
	{
		EventType = TEnumAsByte<EEventType>(6);
	}
};

UCLASS()
class UEventRadioStateChange : public UEventInfoClass
{
	GENERATED_BODY()
public:
	bool IsOn;
	
	UEventRadioStateChange()
	{
		EventType = TEnumAsByte<EEventType>(7);
	}
};

UCLASS()
class UEventSilhouette : public UEventInfoClass
{
	GENERATED_BODY()
	UEventSilhouette()
	{
		EventType = TEnumAsByte<EEventType>(8);
	}
};

UCLASS()
class UEventSound : public UEventInfoClass
{
	GENERATED_BODY()
	UEventSound()
	{
		EventType = TEnumAsByte<EEventType>(9);
	}
};

#pragma endregion