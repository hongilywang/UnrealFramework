// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DDMM.h"
#include "DDMessage.generated.h"

/**
 * 
 */
UCLASS()
class DATADRIVEN_API UDDMessage : public UObject, public IDDMM
{
	GENERATED_BODY()
	
public:
	virtual void MessageInit();

	virtual void MessageBeginPlay();

	virtual void MessageTick(float DeltaSeconds);

};
