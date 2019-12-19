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
	//ʵ���������������NewObjectʵ�������ʱ������������дthis,�����ѹ��������Ϸʱ�����
	Model = NewObject<UDDModel>();
	Message = NewObject<UDDMessage>();
	Wealth = NewObject<UDDWealth>();
	//���ⱻ��������������
	Model->AddToRoot();
	Message->AddToRoot();
	Wealth->AddToRoot();
	//ָ��ģ��
	Model->AssignModule(this);
	Message->AssignModule(this);
	Wealth->AssignModule(this);
}

void UDDModule::ModuleInit()
{
	//����Init����
	Model->ModelInit();
	Message->MessageInit();
	Wealth->WealthInit();
}

void UDDModule::ModuleBeginPlay()
{
	//����beginplay����
	Model->ModelBeginPlay();
	Message->MessageBeginPlay();
	Wealth->WealthBeginPlay();
}

void UDDModule::ModuleTick(float DeltaSeconds)
{
	//����tick����
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
