// Fill out your copyright notice in the Description page of Project Settings.


#include "InGameWidgetBase.h"
#include "Components/EditableTextBox.h"
#include "Components/ScrollBox.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "LobbyController.h"
#include "MyGameInstance.h"
#include "Kismet/GameplayStatics.h"

void UInGameWidgetBase::NativeConstruct()
{
	Super::NativeConstruct();


	UE_LOG(LogTemp, Warning, TEXT("NativeConstruct"));

	InputBox = Cast<UEditableTextBox>(GetWidgetFromName(TEXT("InputBox")));
	if (InputBox)
	{
		UE_LOG(LogTemp, Warning, TEXT("InputBox init"));

		InputBox->OnTextChanged.AddDynamic(this, &UInGameWidgetBase::OnChangedText);
		InputBox->OnTextCommitted.AddDynamic(this, &UInGameWidgetBase::OnCommitedText);
	}

	StartGameButton = Cast<UButton>(GetWidgetFromName(TEXT("StartGame")));
	if (StartGameButton)
	{
		StartGameButton->OnClicked.AddDynamic(this, &UInGameWidgetBase::StartGame);
	}

	ChatScroll = Cast<UScrollBox>(GetWidgetFromName(TEXT("ChatScroll")));
}

void UInGameWidgetBase::OnChangedText(const FText& Text)
{
}

void UInGameWidgetBase::OnCommitedText(const FText& Text, ETextCommit::Type CommitMethod)
{
	switch (CommitMethod)
	{
		case ETextCommit::OnEnter:
		{
			//�޼��� ���� ������ ����
			ALobbyController* PC = Cast<ALobbyController>(GetOwningPlayer());
			if (PC)
			{
				UMyGameInstance* GI = Cast<UMyGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
				if (GI)
				{
					UE_LOG(LogTemp, Warning, TEXT("Send Message"));

					FString Temp = FString::Printf(TEXT("%s : %s"), *GI->Username, *Text.ToString());
					//Client -> Server�� ����
					PC->C2S_SendMessage(FText::FromString(Temp));
				}
			}
		}

	}
}

void UInGameWidgetBase::StartGame()
{
	//���Բ� �� �̵�
	GetWorld()->ServerTravel(TEXT("InGame"));
}

void UInGameWidgetBase::AddMessage(FText const& Message)
{
	UTextBlock* NewChat = NewObject<UTextBlock>();
	if (NewChat)
	{
		NewChat->SetText(Message);
		NewChat->Font.Size = 18;
		ChatScroll->AddChild(NewChat);
		ChatScroll->ScrollToEnd();
	}
}
