#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PawnMovementComponent.h"
#include "SimplePawnMovementComponent.generated.h"

UCLASS()
class MEMOSIMPLEPAWN_API USimplePawnMovementComponent : public UPawnMovementComponent
{
	GENERATED_BODY()
	public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
        FActorComponentTickFunction* ThisTickFunction) override;
	
};
