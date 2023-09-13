// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyController.h"

void ALobbyController::BeginPlay()
{
    Super::BeginPlay();

    APlayerController* PC = Cast<APlayerController>(GetWorld()->GetFirstPlayerController());

    if (PC)
    {
        PC->SetInputMode(FInputModeGameAndUI());
        PC->bShowMouseCursor = true;
    }
}

bool ALobbyController::C2S_SendMessage_Validate(FText const& Message)
{
    return false;
}

void ALobbyController::C2S_SendMessage_Implementation(FText const& Message)
{
}
