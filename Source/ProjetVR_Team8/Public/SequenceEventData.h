#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "SequenceEventData.generated.h"

struct FEventInfo;

UCLASS()
class PROJETVR_TEAM8_API USequenceEventData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	TArray<FEventInfo> Events;
	
	enum EEventType
	{
		WaitForTime
		//SequenceData = StartData   Sequence Data
	};
};

