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
	//ע�ᵽ���
	void RegisterToModule(FName ModuleName, FName ObjectName = FName(), FName ClassName = FName());

	//��ȡ������
	FName GetObjectName();

	//��ȡ����
	FName GetClassName();

	//��ȡģ��Index
	int32 GetModuleIndex() const;

	//��ȡObject����
	UObject* GetObjectBody() const;

protected:
	//���������UObject
	UObject* IBody;

	//����ģ��
	UDDModule* IModule;

	//����������
	ADDDriver* IDriver;

	//��������
	FName IObjectName;

	//����������
	FName IClassName;

	//��Ӧģ�����
	int32 ModuleIndex;
};
