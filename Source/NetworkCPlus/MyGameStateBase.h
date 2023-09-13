// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "MyGameStateBase.generated.h"

/**
 * 
 */
UCLASS()
class NETWORKCPLUS_API AMyGameStateBase : public AGameStateBase
{
	GENERATED_BODY()
public:
	AMyGameStateBase();

	//UPROPERTY(Replicated)
	UPROPERTY(ReplicatedUsing="OnRep_Timer")
	float Timer = 0;

	UFUNCTION()
	void OnRep_Timer();


	UFUNCTION(NetMulticast, Unreliable)
	void UpdateTime(float NewTimer);
	void UpdateTime_Implementation(float NewTimer);

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	virtual void Tick(float DeltaSeconds) override;

};
