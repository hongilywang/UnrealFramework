// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DDTypes.generated.h"

/**
 * 
 */
UCLASS()
class DATADRIVEN_API UDDTypes : public UObject
{
	GENERATED_BODY()
	
};

//框架自定义Debug输出类
#pragma region LogDebug

class DATADRIVEN_API DDRecord
{
private:
	//自身单例
	static TSharedPtr<DDRecord> RecordInst;

public:

	//构造函数

};

#pragma endregion
