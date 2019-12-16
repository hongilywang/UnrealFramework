// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DDCenterModule.h"
#include "DDCommon/DDCommon.h"
#include "DDDriver.generated.h"

UCLASS()
class DATADRIVEN_API ADDDriver : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADDDriver();

	virtual void PostInitializeComponents() override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(EditAnywhere, NoClear, BlueprintReadOnly, Category = "DataDriven")
		USceneComponent* RootScene;

	UPROPERTY(EditAnywhere, NoClear, BlueprintReadOnly, Category = "DataDriven")
		UDDCenterModule* Center;

	//模组对应的枚举名字
	UPROPERTY(EditDefaultsOnly, Category = "DataDriven")
		FName* ModuleType;

protected:
	//是否已经运行BeginPlay函数
	bool IsBeginPlay;
};
