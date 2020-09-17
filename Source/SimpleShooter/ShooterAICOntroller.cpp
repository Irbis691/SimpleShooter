// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAICOntroller.h"
#include "Kismet/GameplayStatics.h"
#include "ShooterCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"

void AShooterAICOntroller::BeginPlay()
{
	Super::BeginPlay();

	if (AIBehaviour)
	{
		RunBehaviorTree(AIBehaviour);

		GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), GetPawn()->GetActorLocation());
	}
}

void AShooterAICOntroller::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

bool AShooterAICOntroller::IsDead() const
{
	AShooterCharacter* ControllerCharacter = Cast<AShooterCharacter>(GetPawn());
	if (ControllerCharacter)
	{
		return ControllerCharacter->IsDead();
	}

	return true;
}
