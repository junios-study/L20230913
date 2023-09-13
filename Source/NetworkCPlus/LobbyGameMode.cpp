// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyGameMode.h"
#include "MyGameStateBase.h"


ALobbyGameMode::ALobbyGameMode()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ALobbyGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//UE_LOG(LogTemp, Warning, TEXT("Tick"));

	ElapsedTime += DeltaTime;

	if (ElapsedTime >= 1.0f)
	{
		ElapsedTime = 0;
		AMyGameStateBase* GS = GetGameState<AMyGameStateBase>();
		if (GS)
		{
			GS->Timer++;
			if (HasAuthority())
			{
				GS->OnRep_Timer();
			}
			//GS->UpdateTime(GS->Timer);
			//S2A_Call();
		}
	}
}

