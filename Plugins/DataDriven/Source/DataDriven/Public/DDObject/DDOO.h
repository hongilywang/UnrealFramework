// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "DDCore/DDModule.h"
#include "DDCore/DDDriver.h"
#include "DDOO.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UDDOO : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class DATADRIVEN_API IDDOO
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	//注册到框架
	void RegisterToModule(FName ModuleName, FName ObjectName = FName(), FName ClassName = FName());

	//获取对象名
	FName GetObjectName();

	//获取类名
	FName GetClassName();

	//获取模组Index
	int32 GetModuleIndex() const;

	//获取Object主体
	UObject* GetObjectBody() const;

protected:
	//保存自身的UObject
	UObject* IBody;

	//保存模组
	UDDModule* IModule;

	//保存驱动器
	ADDDriver* IDriver;

	//对象名字
	FName IObjectName;

	//对象类名字
	FName IClassName;

	//对应模组序号
	int32 ModuleIndex;
};
