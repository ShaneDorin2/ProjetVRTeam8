// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MotionControllerInfo.generated.h"

USTRUCT(BlueprintType)
struct FMotionControllerInfo
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY()
	USceneComponent* MotionControllerComponent;
	UPROPERTY()
	bool IsRight;

	//
	//  bool FMotionControllerInfo::operator==(FMotionControllerInfo* A, FMotionControllerInfo& B)
	// {
	// 	return A->MotionControllerComponent == B.MotionControllerComponent && A->IsRight == B.IsRight;		
	// }


	//bool FMotionControllerInfo::operator==(const FMotionControllerInfo& other);
};
