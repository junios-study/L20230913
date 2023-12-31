// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "LobbyController.generated.h"

/**
 * 
 */
UCLASS()
class NETWORKCPLUS_API ALobbyController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;

	//UFUNCTION(Server, Unreliable)
	UFUNCTION(Server, Reliable, WithValidation)
	void C2S_SendMessage(FText const& Message); //호출용 -> Network -> RPC
	bool C2S_SendMessage_Validate(FText const& Message);
	void C2S_SendMessage_Implementation(FText const& Message);

	UFUNCTION(Client, Reliable)
	void S2C_SendMessage(FText const& Message);  //호출용 -> Network -> RPC
	void S2C_SendMessage_Implementation(FText const& Message);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UUserWidget* InGameWidget;
};
