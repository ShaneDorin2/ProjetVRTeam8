#pragma once

#include "CoreMinimal.h"
#include "FEventInfo.h"
#include "Engine/DataAsset.h"
#include "SequenceEventData.generated.h"

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
	};
};

