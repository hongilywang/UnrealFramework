// Fill out your copyright notice in the Description page of Project Settings.


#include "DDObject/DDOO.h"

// Add default functionality here for any IDDOO functions that are not pure virtual.

void IDDOO::RegisterToModule(FName ModuleName, FName ObjectName /*= FName()*/, FName ClassName /*= FName()*/)
{
	//判断是否已经注册到框架了
	if (IDriver)
		return;
	//如果模组名字为空，直接返回
	if (ModuleName.IsNone())
		return;
	//指定对象名和类名
	if (!ObjectName.IsNone())
		IObjectName = ObjectName;
	if (!ClassName.IsNone())
		IClassName = ClassName;
	//获取UObject主体
	IBody = Cast<UObject>(this);
	//获取驱动器
	IDriver = UDDCommon::Get()->GetDriver();
	//注册到模组
	if (IDriver)
	{
		//如果获取的ID为负直接返回
		ModuleIndex = DDH::GetEnumIndexFromName(IDriver->ModuleType.ToString(), ModuleName);
		if (ModuleIndex < 0)
		{
			DDH::Debug() << GetObjectName() << " Get " << ModuleName << " ModuleIndex Failed " << DDH::Endl();
			return;
		}
		//如果注册不成功说明还没有实例化对应的Module
		if (!IDriver->RegisterToModule(this))
			DDH::Debug() << GetObjectName() << " Register To " << ModuleName << "Failed !" << DDH::Endl();
	}
	else
	{
		DDH::Debug() << GetObjectName() << " Get DDDriver Failed ! " << DDH::Endl();
	}
}

FName IDDOO::GetObjectName()
{
	if (!IObjectName.IsNone())
		return IObjectName;
	IObjectName = IBody->GetFName();
	return IObjectName;
}

FName IDDOO::GetClassName()
{
	if (!IClassName.IsNone())
		return IClassName;
	IClassName = IBody->StaticClass()->GetFName();
	return IClassName;
}

int32 IDDOO::GetModuleIndex() const
{
	return ModuleIndex;
}

UObject* IDDOO::GetObjectBody() const
{
	return IBody;
}
