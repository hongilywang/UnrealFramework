// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "DDMessage.h"
#include "DDModule.generated.h"

class UDDModel;
class UDDWealth;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DATADRIVEN_API UDDModule : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDDModule();

	void CreateManager();

	//Module的Init函数
	virtual void ModuleInit();

	//Module的BeginPlay函数
	virtual void ModuleBeginPlay();

	//Module的Tick函数
	virtual void ModuleTick(float DeltaSeconds);

public:
	TArray<UDDModule*> ChildrenModule;

protected:
	//数据模块指针
	UDDModel* Model;
	//消息模块指针
	UDDMessage* Message;
	//资源模块指针
	UDDWealth* Wealth;
};
