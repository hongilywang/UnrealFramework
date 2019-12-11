// Fill out your copyright notice in the Description page of Project Settings.


#include "DDCore/DDDriver.h"

// Sets default values
ADDDriver::ADDDriver()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADDDriver::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADDDriver::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

