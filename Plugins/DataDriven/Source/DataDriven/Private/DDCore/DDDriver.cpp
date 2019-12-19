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
	//ע�������Driver��UDDCommon����
	UDDCommon::Get()->InitDriver(this);
	//��Ϸ����֮ǰ�������һ��ģ�� ID���趨���������ע����ģ�鵽����
	Center->IterChangeModuleType(Center, ModuleType);
	Center->TotalGatherModule(ModuleType);
	//��������ģ���ģ��
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
	
	//��������Init����
	Center->IterModuleInit(Center);
}

// Called every frame
void ADDDriver::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!IsBeginPlay)
	{
		//��������Begin����
		Center->IterModuleBeginPlay(Center);
		IsBeginPlay = true;
	}
	else
	{
		//��������tick����
		Center->IterModuleTick(Center, DeltaTime);
	}


}

