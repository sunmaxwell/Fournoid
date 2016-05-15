// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
#pragma once 
#include "Fournoid.h"
#include "GameFramework/HUD.h"
#include "FournoidHUD.generated.h"

USTRUCT()
struct FButtonStruct
{
	GENERATED_USTRUCT_BODY()

	//Vars
	int32		type;
	FString		toolTip;
	float 		minX;
	float 		maxX;
	float 		minY;
	float 		maxY;

	//~

	//default properties

	FButtonStruct()
	{
		type = -1;
		toolTip = "";
		minX = 0;
		maxX = 0;
		minY = 0;
		maxY = 0;
	}
};

UCLASS()
class AFournoidHUD : public AHUD
{
	GENERATED_BODY()

public:
	/** Verdana */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AFournoidHUD)
		UFont* VerdanaFont;

	/** Put Roboto Here */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AFournoidHUD)
		UFont* UE4Font;

	/** Font Scaling Used By Your HUD Code */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AFournoidHUD)
		float DefaultFontScale;

	/** HUD Scaling */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AFournoidHUD)
		float GlobalHUDMult;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AFournoidHUD)
		float InGameMenuXOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AFournoidHUD)
		float InGameMenuYOffset;

	// T2D 
	/** Cursor */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = T2D)
		UTexture2D* CursorMain;

	/** Hovering */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = T2D)
		UTexture2D* CursorHoveringButton;

	/** Button */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = T2D)
		UTexture2D* ButtonBackground;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = T2D)
		float ButtonXOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = T2D)
		float ButtonYIncrement;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = T2D)
		float TextXOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = T2D)
		float TextYOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = T2D)
		float TextScale;


	// Materials 
	/** Events */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Materials)
		UMaterialInterface* MaterialBackground;

	/* Health Bar Properties*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HealthBar)
		UMaterialInterface* HealthBarBackground;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HealthBar)
		float HealthBarXOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HealthBar)
		float HealthBarYOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HealthBar)
		float HealthBarHeight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HealthBar)
		float HealthBarWidth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HealthBar)
		float HealthBarScale;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HealthBar)
		class UTexture2D* HealthIcon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HealthBar)
		float HealthIconScale;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HealthBar)
		float HealthIconXOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HealthBar)
		float HealthIconYOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HealthBar)
		float HealthIndicatorOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HealthBar)
		float HealthIndicatorScale;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HealthBar)
	class UTexture2D* StaminaIcon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HealthBar)
		float StaminaIconScale;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HealthBar)
		float StaminaIconXOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HealthBar)
		float StaminaIconYOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HealthBar)
		float StaminaIndicatorOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HealthBar)
		float StaminaIndicatorScale;
	
	/* Ammo Bar Properties*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AmmoBar)
		UMaterialInterface* AmmoBarBackground;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AmmoBar)
		float AmmoBarXOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AmmoBar)
		float AmmoBarYOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AmmoBar)
		float AmmoBarHeight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AmmoBar)
		float AmmoBarWidth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AmmoBar)
		float AmmoBarScale;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AmmoBar)
	class UTexture2D* AmmoIcon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AmmoBar)
		float AmmoIconScale;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AmmoBar)
		float AmmoIconXOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AmmoBar)
		float AmmoIconYOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AmmoBar)
		float AmmoIndicatorOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AmmoBar)
		float AmmoIndicatorScale;

//Buttons
public:
	TArray<FButtonStruct> ButtonsMain;
	TArray<FButtonStruct> ButtonsConfirm;

	//Cursor In buttons
	FVector2D MouseLocation;
	void DrawHUD_CheckCursorInButtons();
	void DrawConfirm();
	void DrawConfirmButtons();
	void CheckCursorInButtonsMain();
	void CheckCursorInButtonsConfirm();

	const FButtonStruct* CurCheckButton;
	int32 CheckCursorInButton(const TArray<FButtonStruct>& ButtonArray);
	int32 ClickedButtonType;
	//States
	bool ConfirmDialogOpen;
	bool InMainMenu;

	int32 		ActiveButton_Type;
	FString 	ActiveButton_Tip;
	bool CursorHoveringInButton;
	
//Colors
public:
	const FLinearColor * ColorPtr;

	//Colors
	static const FColor		FColorBlack;
	static const FColor		FColorRed;
	static const FColor		FColorYellow;
	static const FColor		FColorBlue;
	static const FColor		FColor_White;

	static const FLinearColor LC_Black;
	static const FLinearColor LC_Pink;
	static const FLinearColor LC_Red;
	static const FLinearColor LC_Yellow;

//FString
public:

	//`Titles
	static const FString S_Title_Main;
	static const FString S_Title_Confirm;
	//`Button Text
	static const FString S_Button_Restart;
	static const FString S_Button_Exit;


	AFournoidHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

	virtual void PostInitializeComponents() override;

	void DrawCrossHair();
	
	void DrawInGameMenu();

	void DrawMainMenuButtons();

	void DrawHealthBar();

	void DrawAmmoBar();

	void PlayerInputCheckes();

	FORCEINLINE void VDrawTile(UTexture2D* tex, float x, float y, float screenX, float screenY, const FColor& TheColor)
	{
		if (!Canvas) return;
		if (!tex) return;
		//~

		Canvas->SetDrawColor(TheColor);

		//Draw
		Canvas->DrawTile(
			tex, x, y, //z pos
			screenX, //screen width
			screenY,  //screen height
			0, //texture start width
			0, //texture start height
			tex->GetSurfaceWidth(), //texture width from start
			tex->GetSurfaceHeight(), //texture height from start
			BLEND_Translucent
			);
	}

	FORCEINLINE void FDrawRect(
		float X, float Y,
		float Width, float Height,
		const FLinearColor& Color
		)
	{
		if (!Canvas) return;
		//

		FCanvasTileItem RectItem(
			FVector2D(X, Y),
			FVector2D(Width, Height),
			Color
			);

		RectItem.BlendMode = SE_BLEND_Translucent;
		Canvas->DrawItem(RectItem);
	}

	//DrawText
	FORCEINLINE void FDrawText(
		UFont*	TheFont,
		const FString& TheStr,
		const float& X, const float& Y,
		const FLinearColor& TheColor,
		const float& TheScale,
		bool DrawOutline = false,
		const FLinearColor OutlineColor = FLinearColor(0, 0, 0, 1)
		) {
		if (!Canvas) return;
		//

		//Text and Font
		FCanvasTextItem NewText(
			FVector2D(X, Y),
			FText::FromString(TheStr),
			TheFont,
			TheColor
			);

		//Text Scale
		NewText.Scale.Set(TheScale, TheScale);

		//Outline gets its alpha from the main color
		NewText.bOutlined = true;
		NewText.OutlineColor = OutlineColor;
		NewText.OutlineColor.A = TheColor.A * 2;

		//Draw
		Canvas->DrawItem(NewText);
	}

	//Stop Camera From Moving With Mouse
	FORCEINLINE void SetCursorMoveOnly(bool CursorOnly)
	{
		if (!ThePC) return;
		//
		ThePC->SetIgnoreLookInput(CursorOnly);

	}

	//Change Cursor State
	FORCEINLINE void SwitchCursorState() {
		ShowCursor = !ShowCursor;
		ThePC->bShowMouseCursor = ShowCursor;
		ThePC->bEnableClickEvents = ShowCursor;
		ThePC->bEnableMouseOverEvents = ShowCursor;
	}

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;
	APlayerController *ThePC;
	bool DrawInGameMenuFlag;
	bool ShowCursor;
	FLinearColor TextColor;
	FLinearColor TextOuterColor;
};
