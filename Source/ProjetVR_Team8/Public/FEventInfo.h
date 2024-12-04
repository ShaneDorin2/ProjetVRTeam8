#pragma once

#include "CoreMinimal.h"
#include "EEventType.h"
#include "FEventInfo.generated.h"

USTRUCT(BlueprintType)
struct FEventInfo
{
	GENERATED_USTRUCT_BODY()
	
	UPROPERTY(EditAnywhere)
	TEnumAsByte<EEventType> EventType;
	
	UPROPERTY(EditAnywhere)
	float EventTime;
};