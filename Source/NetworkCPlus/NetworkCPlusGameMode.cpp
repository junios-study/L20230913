// Copyright Epic Games, Inc. All Rights Reserved.

#include "NetworkCPlusGameMode.h"
#include "NetworkCPlusCharacter.h"
#include "UObject/ConstructorHelpers.h"

ANetworkCPlusGameMode::ANetworkCPlusGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
