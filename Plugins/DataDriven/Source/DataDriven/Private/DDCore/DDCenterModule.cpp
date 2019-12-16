// Fill out your copyright notice in the Description page of Project Settings.


#include "DDCore/DDCenterModule.h"

void UDDCenterModule::IterChangeModuleType(UDDModule* Module, FName ModType)
{
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
