// Fill out your copyright notice in the Description page of Project Settings.


#include "DDObject/DDActor.h"

// Sets default values
ADDActor::ADDActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADDActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADDActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

