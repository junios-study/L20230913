// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameStateBase.h"
#include "Net/UnrealNetwork.h"

AMyGameStateBase::AMyGameStateBase()
{
	PrimaryActorTick.bCanEverTick = true;
	UE_LOG(LogTemp, Warning, TEXT("AMyGameStateBase"));
}

void AMyGameStateBase::OnRep_Timer()
{
	//UI Update
	UE_LOG(LogTemp, Warning, TEXT("OnRep_Timer : %f"), Timer);
}

void AMyGameStateBase::UpdateTime_Implementation(float NewTimer)
{
	Timer = NewTimer;
	UE_LOG(LogTemp, Warning, TEXT("Timer : %f"), Timer);
}

void AMyGameStateBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AMyGameStateBase, Timer);
}

void AMyGameStateBase::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	//UE_LOG(LogTemp, Warning, TEXT("GS Time %f"), Timer);
}
