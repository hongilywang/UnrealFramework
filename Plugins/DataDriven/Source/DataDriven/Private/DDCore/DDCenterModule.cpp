// Fill out your copyright notice in the Description page of Project Settings.


#include "DDCore/DDCenterModule.h"

void UDDCenterModule::IterChangeModuleType(UDDModule* Module, FName ModType)
{
	Module->ChangeModuleType(ModType);
	for (int i = 0; i < Module->GetAttachChildren().Num(); ++i)
	{
		UDDModule* ChildModule = Cast<UDDModule>(Module->GetAttachChildren()[i]);
		if (ChildModule)
		{
			Module->ChildrenModule.Push(ChildModule);
			IterChangeModuleType(ChildModule, ModType);
		}
	}
}

void UDDCenterModule::IterCreateManager(UDDModule* Module)
{
	Module->CreateManager();
	for (int i = 0; i < Module->ChildrenModule.Num(); ++i)
		IterCreateManager(Module->ChildrenModule[i]);
}

void UDDCenterModule::IterModuleInit(UDDModule* Module)
{
	Module->ModuleInit();
	for (int i = 0; i < Module->ChildrenModule.Num(); ++i)
		IterModuleInit(Module->ChildrenModule[i]);

}

void UDDCenterModule::IterModuleBeginPlay(UDDModule* Module)
{
	Module->ModuleBeginPlay();
	for (int i = 0; i < Module->ChildrenModule.Num(); ++i)
		IterModuleBeginPlay(Module->ChildrenModule[i]);
}

void UDDCenterModule::IterModuleTick(UDDModule* Module, float DeltaSeconds)
{
	Module->ModuleTick(DeltaSeconds);
	for (int i = 0; i < Module->ChildrenModule.Num(); ++i)
		IterModuleTick(Module->ChildrenModule[i], DeltaSeconds);
}

void UDDCenterModule::TotalGatherModule(FName ModuleType)
{
	if (ModuleType.IsNone())
		return;

	//先获取所有的模组到GatherGroup
	TArray<UDDModule*> GatherGroup;
	IterGatherModule(this, GatherGroup);

	//获取枚举的元素数量
	int32 ModuleNum = FindObject<UEnum>((UObject*)ANY_PACKAGE, *(ModuleType.ToString()), true)->GetMaxEnumValue();
	//填充空对象到ModuleGroup
	for (int i = 0; i < ModuleNum; ++i)
		ModuleGroup.Push(nullptr);
	//按模组ID填充模组到ModuleGroup
	for (int i = 0; i < GatherGroup.Num(); ++i)
		ModuleGroup[GatherGroup[i]->ModuleIndex] = GatherGroup[i];
}

void UDDCenterModule::IterGatherModule(UDDModule* Module, TArray<UDDModule*>& GatherGroup)
{
	GatherGroup.Push(Module);
	for (int i = 0; i < Module->ChildrenModule.Num(); ++i)
		IterGatherModule(Module->ChildrenModule[i], GatherGroup);
}
