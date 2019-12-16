// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "DDMessage.h"
#include "DDModule.generated.h"

class UDDModel;
class UDDWealth;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DATADRIVEN_API UDDModule : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDDModule();

	void CreateManager();

	//Module��Init����
	virtual void ModuleInit();

	//Module��BeginPlay����
	virtual void ModuleBeginPlay();

	//Module��Tick����
	virtual void ModuleTick(float DeltaSeconds);

public:
	TArray<UDDModule*> ChildrenModule;

protected:
	//����ģ��ָ��
	UDDModel* Model;
	//��Ϣģ��ָ��
	UDDMessage* Message;
	//��Դģ��ָ��
	UDDWealth* Wealth;
};
