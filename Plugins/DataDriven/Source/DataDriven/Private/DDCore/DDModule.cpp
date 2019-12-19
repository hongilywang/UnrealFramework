// Fill out your copyright notice in the Description page of Project Settings.


#include "DDCore/DDModule.h"
#include "DDCore/DDMessage.h"
#include "DDCore/DDWealth.h"
#include "DDCore/DDModel.h"

// Sets default values for this component's properties
UDDModule::UDDModule()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

void UDDModule::CreateManager()
{
	//实例化组件，这里用NewObject实例化组件时不能再括号填写this,否则变压器运行游戏时会崩溃
	Model = NewObject<UDDModel>();
	Message = NewObject<UDDMessage>();
	Wealth = NewObject<UDDWealth>();
	//避免被垃圾回收器销毁
	Model->AddToRoot();
	Message->AddToRoot();
	Wealth->AddToRoot();
	//指定模组
	Model->AssignModule(this);
	Message->AssignModule(this);
	Wealth->AssignModule(this);
}

void UDDModule::ModuleInit()
{
	//调用Init函数
	Model->ModelInit();
	Message->MessageInit();
	Wealth->WealthInit();
}

void UDDModule::ModuleBeginPlay()
{
	//调用beginplay函数
	Model->ModelBeginPlay();
	Message->MessageBeginPlay();
	Wealth->WealthBeginPlay();
}

void UDDModule::ModuleTick(float DeltaSeconds)
{
	//调用tick函数
	Model->ModelTick(DeltaSeconds);
	Message->MessageTick(DeltaSeconds);
	Wealth->WealthTick(DeltaSeconds);
}

void UDDModule::ChangeModuleType(FName ModuleType)
{
	ModuleIndex = DDH::GetEnumIndexFromName(ModuleType.ToString(), GetFName());
	if (ModuleIndex < 0)
		DDH::Debug() << "Generate Module Index Error --> " << GetName() << DDH::Endl();
}
