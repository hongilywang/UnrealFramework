// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DDCore/DDModule.h"
#include "DDCenterModule.generated.h"

/**
 * 
 */
UCLASS()
class DATADRIVEN_API UDDCenterModule : public UDDModule
{
	GENERATED_BODY()
	
public:
	//迭代调用本模组以及子模组的EditChangeModuleType方法
	void IterChangeModuleType(UDDModule* Module, FName ModType);
	//递归创建模组
	void IterCreateManager(UDDModule* Module);
	//递归初始化
	void IterModuleInit(UDDModule* Module);
	//递归BeginPlay
	void IterModuleBeginPlay(UDDModule* Module);
	//递归Tick
	void IterModuleTick(UDDModule* Module, float DeltaSeconds);
};
