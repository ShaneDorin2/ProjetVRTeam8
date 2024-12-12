#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "GameManager.generated.h"
enum class EHandGrabState : uint8;

DECLARE_DYNAMIC_MULTICAST_DELEGATE( FOnDie);

UCLASS()
class PROJETVR_TEAM8_API UGameManager : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite)
	bool IsCarStarted;
	UPROPERTY(BlueprintReadWrite)
	bool IsDoorLocked;
	UPROPERTY(BlueprintReadWrite)
	bool IsRadioOn;

	UPROPERTY(BlueprintReadOnly)
	EHandGrabState CurrentHandState;


	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category="Game Manager")
	FOnDie OnDie;
	
};
