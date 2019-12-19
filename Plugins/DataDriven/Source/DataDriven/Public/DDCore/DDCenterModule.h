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
	//�������ñ�ģ���Լ���ģ���EditChangeModuleType����
	void IterChangeModuleType(UDDModule* Module, FName ModType);
	//�ݹ鴴��ģ��
	void IterCreateManager(UDDModule* Module);
	//�ݹ��ʼ��
	void IterModuleInit(UDDModule* Module);
	//�ݹ�BeginPlay
	void IterModuleBeginPlay(UDDModule* Module);
	//�ݹ�Tick
	void IterModuleTick(UDDModule* Module, float DeltaSeconds);
	//��ȡ����ģ�鵽ģ�����飬����ö������
	void TotalGatherModule(FName ModuleType);
	//��ȡ���е�ģ�鵽����
	void IterGatherModule(UDDModule* Module, TArray<UDDModule*>& GatherGroup);
protected:
	//����ģ������飬˳����ö����ͬ
	TArray<UDDModule*> ModuleGroup;
};
