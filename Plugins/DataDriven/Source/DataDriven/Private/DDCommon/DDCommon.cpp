// Fill out your copyright notice in the Description page of Project Settings.


#include "DDCommon/DDCommon.h"

UDDCommon* UDDCommon::DDInst = nullptr;

UDDCommon* UDDCommon::Get()
{
	if (!DDInst)
	{
		DDInst = NewObject<UDDCommon>();
		DDInst->AddToRoot();
	}
		
	return DDInst;
}

void UDDCommon::InitDriver(ADDDriver* InDriver)
{
	Driver = InDriver;
}

ADDDriver* UDDCommon::GetDriver()
{
	return Driver;
}
