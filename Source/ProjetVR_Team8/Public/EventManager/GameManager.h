#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "GameManager.generated.h"

UCLASS()
class PROJETVR_TEAM8_API UGameManager : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite)
	bool IsDoorLocked;
};
