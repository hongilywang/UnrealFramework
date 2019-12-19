// Fill out your copyright notice in the Description page of Project Settings.


#include "DDCore/DDDriver.h"

// Sets default values
ADDDriver::ADDDriver()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootScene = CreateDefaultSubobject<USceneComponent>(TEXT("RootScene"));
	RootComponent = RootScene;

	Center = CreateDefaultSubobject<UDDCenterModule>(TEXT("Center"));
	Center->SetupAttachment(RootComponent);
}

void ADDDriver::PostInitializeComponents()
{
	//
	Super::PostInitializeComponents();
	//注册世界和Driver到UDDCommon单例
	UDDCommon::Get()->InitDriver(this);
	//游戏运行之前必须进行一次模组 ID的设定，在这里会注册子模组到数组
	Center->IterChangeModuleType(Center, ModuleType);
	Center->TotalGatherModule(ModuleType);
	//创建所有模组的模块
	Center->IterCreateManager(Center);
}

#if WITH_EDITOR
void ADDDriver::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
	if (PropertyChangedEvent.Property && PropertyChangedEvent.Property->GetFName() == GET_MEMBER_NAME_CHECKED(ADDDriver, ModuleType))
		Center->IterChangeModuleType(Center, ModuleType);
}
#endif

// Called when the game starts or when spawned
void ADDDriver::BeginPlay()
{
	Super::BeginPlay();
	
	//迭代调用Init函数
	Center->IterModuleInit(Center);
}

// Called every frame
void ADDDriver::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!IsBeginPlay)
	{
		//迭代调用Begin函数
		Center->IterModuleBeginPlay(Center);
		IsBeginPlay = true;
	}
	else
	{
		//迭代调用tick函数
		Center->IterModuleTick(Center, DeltaTime);
	}


}

