


#include "AI/BaseNPC.h"
#include "AI/BaseAIController.h"
#include "GameFramework/CharacterMovementComponent.h"


ABaseNPC::ABaseNPC(const FObjectInitializer& ObjInit):Super()
{
	PrimaryActorTick.bCanEverTick = true;
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
	AIControllerClass = ABaseAIController::StaticClass();

	bUseControllerRotationYaw = false;
	if(GetCharacterMovement())
	{
		GetCharacterMovement()->bUseControllerDesiredRotation = true;
		GetCharacterMovement()->RotationRate = FRotator(0.0f, 360.0f, 0.0f); 
	}
}

void ABaseNPC::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
}
bool ABaseNPC::CanBeSeenFrom(const FVector& ObserverLocation,FVector& OutSeenLocation,
								int32& NumberOfLoSChecksPerformed, float& OutSightStrength,
								const AActor* IgnoreActor,
								const bool* bWasVisible, int32* UserData) const
{
	static const FName NAME_AILineOfSight = FName(TEXT("TestPawnLineOfSight"));

	FHitResult HitResult;
	FVector SocketLocation = GetMesh()->GetSocketLocation(TargetBone);

	const bool bHitSocket 	= GetWorld()->LineTraceSingleByObjectType( HitResult, ObserverLocation, SocketLocation,
																		FCollisionObjectQueryParams(ECC_TO_BITFIELD(ECC_WorldStatic) | ECC_TO_BITFIELD(ECC_WorldDynamic)),
																		FCollisionQueryParams(NAME_AILineOfSight, true, IgnoreActor));
	NumberOfLoSChecksPerformed++;

	if(bHitSocket == false || (HitResult.GetActor() != nullptr && HitResult.GetActor()->IsOwnedBy(this)))
	{
		OutSeenLocation = SocketLocation;
		OutSightStrength = 1;

		return true;
	}				

	const bool bHit = GetWorld()->LineTraceSingleByObjectType( HitResult, ObserverLocation, GetActorLocation(),
																FCollisionObjectQueryParams(ECC_TO_BITFIELD(ECC_WorldStatic) | ECC_TO_BITFIELD(ECC_WorldDynamic)),
																FCollisionQueryParams(NAME_AILineOfSight, true, IgnoreActor));

	NumberOfLoSChecksPerformed++;

	if(bHit == false || (HitResult.GetActor() != nullptr && HitResult.GetActor()->IsOwnedBy(this)))
	{
		OutSeenLocation = GetActorLocation();
		OutSightStrength = 1;

		return true;
	}

	OutSightStrength = 0;
	return false;
}

void ABaseNPC::NextViewTarget()
{
	Index < ViewTargets.Num() - 1 ? Index++ : Index = 0;
	TargetBone = ViewTargets[Index];
}