// Copyright UC Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Perception/AISightTargetInterface.h"
#include "GenericTeamAgentInterface.h"
#include "ECharacters.h"
#include "ECharacterState.h"
#include "BaseCharacter.generated.h"

class UBoxComponent;

UCLASS()
class SKYWAY_API ABaseCharacter : public ACharacter, public IAISightTargetInterface, public IGenericTeamAgentInterface
{
    GENERATED_BODY()

public:
    ABaseCharacter();

    UFUNCTION(BlueprintGetter, Category = "AI")
    const int32 GetId() { return ID; }

    UFUNCTION(BlueprintSetter, Category = "AI")
    const void SetId(int32 NewId);

    UFUNCTION(BlueprintGetter, Category = "BaseCharacter")
    const ECharacters GetCharacter() { return Character; }

    UFUNCTION(BlueprintGetter, Category = "BaseCharacter")
    const ECharacterState GetCharacterState() { return CharacterState; }

    UFUNCTION(BlueprintSetter, Category = "BaseCharacter")
    const void SetCharacterState(ECharacterState NewCharacterState);

    UFUNCTION(BlueprintGetter, Category = "BaseCharacter")
    UBoxComponent* GetWeaponCollision() const { return WeaponCollision; }

    UFUNCTION(Server, WithValidation, Reliable, //
        BlueprintCallable, Category = "BaseCharacter", meta = (DisplayName = "EnableWeaponCollision_SERVER"))
    void Server_EnableWeaponCollision();
    bool Server_EnableWeaponCollision_Validate();
    void Server_EnableWeaponCollision_Implementation();

    UFUNCTION(Server, WithValidation, Reliable, //
        BlueprintCallable, Category = "BaseCharacter", meta = (DisplayName = "DisableWeaponCollision_SERVER"))
    void Server_DisableWeaponCollision();
    bool Server_DisableWeaponCollision_Validate();
    void Server_DisableWeaponCollision_Implementation();
    
    UFUNCTION(BlueprintCallable, Category = "BaseCharacter")
    void Recoil(float MultiplierForce = 1.f);
    
protected:
    UFUNCTION(BlueprintNativeEvent, Category = "BaseCharacter")
    float GetWeaponDamage();
    float GetWeaponDamage_Implementation() { return 0.f; }

    UFUNCTION(BlueprintImplementableEvent, Category = "BaseCharacter")
    void OnWeaponCollisionBeginOverlapEvent(    //
        UPrimitiveComponent* OverlappedComponent, //
        AActor* OtherActor,                       //
        UPrimitiveComponent* OtherComp,           //
        int32 OtherBodyIndex,                     //
        bool bFromSweep,                          //
        const FHitResult& SweepResult);

private:
    UFUNCTION(Category = "BaseCharacter")
    void OnWeaponCollisionBeginOverlapHandler(    //
        UPrimitiveComponent* OverlappedComponent, //
        AActor* OtherActor,                       //
        UPrimitiveComponent* OtherComp,           //
        int32 OtherBodyIndex,                     //
        bool bFromSweep,                          //
        const FHitResult& SweepResult);
    

private:
    UPROPERTY(EditAnywhere, BlueprintGetter = GetId, BlueprintSetter = SetId, Category = "AI")
    int32 ID;

    UPROPERTY(EditDefaultsOnly, BlueprintGetter = GetCharacter, Category = "BaseCharacter")
    ECharacters Character;

    UPROPERTY(Replicated, EditAnywhere, BlueprintGetter = GetCharacterState, //
        BlueprintSetter = SetCharacterState, Category = "BaseCharacter")
    ECharacterState CharacterState;

protected:
    UPROPERTY(Replicated, EditAnywhere, BlueprintGetter = GetWeaponCollision, Category = "BaseCharacter")
    UBoxComponent* WeaponCollision;
};
