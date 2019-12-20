// Fill out your copyright notice in the Description page of Project Settings.


#include "DDObject/DDOO.h"

// Add default functionality here for any IDDOO functions that are not pure virtual.

void IDDOO::RegisterToModule(FName ModuleName, FName ObjectName /*= FName()*/, FName ClassName /*= FName()*/)
{
	//�ж��Ƿ��Ѿ�ע�ᵽ�����
	if (IDriver)
		return;
	//���ģ������Ϊ�գ�ֱ�ӷ���
	if (ModuleName.IsNone())
		return;
	//ָ��������������
	if (!ObjectName.IsNone())
		IObjectName = ObjectName;
	if (!ClassName.IsNone())
		IClassName = ClassName;
	//��ȡUObject����
	IBody = Cast<UObject>(this);
	//��ȡ������
	IDriver = UDDCommon::Get()->GetDriver();
	//ע�ᵽģ��
	if (IDriver)
	{
		//�����ȡ��IDΪ��ֱ�ӷ���
		ModuleIndex = DDH::GetEnumIndexFromName(IDriver->ModuleType.ToString(), ModuleName);
		if (ModuleIndex < 0)
		{
			DDH::Debug() << GetObjectName() << " Get " << ModuleName << " ModuleIndex Failed " << DDH::Endl();
			return;
		}
		//���ע�᲻�ɹ�˵����û��ʵ������Ӧ��Module
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
