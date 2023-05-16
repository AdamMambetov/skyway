// Copyright UC Games, Inc. All Rights Reserved.

#include "BaseCharacter.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Net/UnrealNetwork.h"
#include "Components/BoxComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

ABaseCharacter::ABaseCharacter() : Super()
{
    ID = 0;
    WeaponCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Weapon Collision"));
    WeaponCollision->SetupAttachment(RootComponent);
    WeaponCollision->SetRelativeLocation(FVector(90.f, 0.f, 0.f));
    WeaponCollision->SetBoxExtent(FVector(50.f, 50.f, 80.f));
    WeaponCollision->SetCollisionProfileName(FName("Weapon"));
    WeaponCollision->OnComponentBeginOverlap.AddDynamic(this, &ABaseCharacter::OnWeaponCollisionBeginOverlapHandler);
}

const void ABaseCharacter::SetId(int32 NewId)
{
    UE_LOG(LogTemp, Display, TEXT("Set new ID in %s from %i to %i"), *UKismetSystemLibrary::GetDisplayName(this), ID, NewId);
    ID = NewId;
}

const void ABaseCharacter::SetCharacterState(ECharacterState NewCharacterState)
{
    CharacterState = NewCharacterState;
}

void ABaseCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    DOREPLIFETIME(ABaseCharacter, CharacterState);
    DOREPLIFETIME(ABaseCharacter, WeaponCollision);
}

bool ABaseCharacter::Server_EnableWeaponCollision_Validate()
{
    if (!WeaponCollision) return false;
    return !WeaponCollision->IsCollisionEnabled();
}

void ABaseCharacter::Server_EnableWeaponCollision_Implementation()
{
    WeaponCollision->SetCollisionEnabled(ECollisionEnabled::Type::QueryOnly);
}

bool ABaseCharacter::Server_DisableWeaponCollision_Validate()
{
    if (!WeaponCollision) return false;
    return WeaponCollision->IsCollisionEnabled();
}

void ABaseCharacter::Server_DisableWeaponCollision_Implementation()
{
    WeaponCollision->SetCollisionEnabled(ECollisionEnabled::Type::NoCollision);
}

void ABaseCharacter::OnWeaponCollisionBeginOverlapHandler( //
    UPrimitiveComponent* OverlappedComponent,              //
    AActor* OtherActor,                                    //
    UPrimitiveComponent* OtherComp,                        //
    int32 OtherBodyIndex,                                  //
    bool bFromSweep,                                       //
    const FHitResult& SweepResult)
{
    if (OtherActor == this) return;
    ABaseCharacter* OtherCharacter = Cast<ABaseCharacter>(OtherActor);
    if (!OtherCharacter) return;
    if (OtherCharacter->ID == this->ID) return;
    OtherCharacter->TakeDamage(GetWeaponDamage(), FDamageEvent(UDamageType::StaticClass()), GetController(), this);
    Server_DisableWeaponCollision();
    OnWeaponCollisionBeginOverlapEvent(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
}

void ABaseCharacter::Recoil(float MultiplierForce)
{
    const float ForceBack = -1000000.0f, ForceZ = 2000000.0f;
    FVector ResultForce = (GetActorForwardVector() * ForceBack + FVector(0.f, 0.f, ForceZ)) * MultiplierForce;
    GetCharacterMovement()->AddForce(ResultForce);
}
