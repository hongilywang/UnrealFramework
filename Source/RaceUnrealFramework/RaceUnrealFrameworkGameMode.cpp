// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "RaceUnrealFrameworkGameMode.h"
#include "RaceUnrealFrameworkPawn.h"
#include "RaceUnrealFrameworkHud.h"

ARaceUnrealFrameworkGameMode::ARaceUnrealFrameworkGameMode()
{
	DefaultPawnClass = ARaceUnrealFrameworkPawn::StaticClass();
	HUDClass = ARaceUnrealFrameworkHud::StaticClass();
}
