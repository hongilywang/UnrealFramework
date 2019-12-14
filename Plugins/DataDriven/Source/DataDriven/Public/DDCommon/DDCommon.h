// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DDCommon/DDDefine.h"
#include "DDCommon.generated.h"

class ADDDriver;

namespace DDH
{
	FORCEINLINE DDRecord& Debug(float InTime = 3000.f, FColor InColor = FColor::Yellow)
	{
		DDRecord::Get()->PatternID = 0;
		DDRecord::Get()->InitParam(InTime, InColor);
		return *DDRecord::Get();
	}

	FORCEINLINE DDRecord& Debug(FColor InColor)
	{
		return Debug(3000.f, InColor);
	}

	FORCEINLINE DDRecord& Log()
	{
		DDRecord::Get()->PatternID = 1;
		return *DDRecord::Get();
	}

	FORCEINLINE DDRecord& Warning()
	{
		DDRecord::Get()->PatternID = 2;
		return *DDRecord::Get();
	}

	FORCEINLINE DDRecord& Error()
	{
		DDRecord::Get()->PatternID = 3;
		return *DDRecord::Get();
	}

	FORCEINLINE DDRecord& Endl()
	{
		return *DDRecord::Get();
	}
}

/**
 * 
 */
UCLASS()
class DATADRIVEN_API UDDCommon : public UObject
{
	GENERATED_BODY()
	
public:
	static UDDCommon* Get();

	void InitDriver(ADDDriver* InDriver);

	ADDDriver* GetDriver();

private:

	static UDDCommon* DDInst;

	ADDDriver* Driver;
};
