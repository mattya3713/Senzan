﻿#include "Main.h"
#include <crtdbg.h>	//_ASSERT_EXPR()で必要.


//================================================
//	メイン関数.
//================================================
INT WINAPI WinMain(
	_In_ HINSTANCE hInstance,	//インスタンス番号（ウィンドウの番号）.
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ PSTR lpCmdLine,
	_In_ INT nCmdShow)
{
	// メモリリーク検出
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	std::unique_ptr<Main> pCMain = std::make_unique<Main>();	//初期化＆クラス宣言.
	
	if (pCMain != nullptr)
	{
		//ウィンドウ作成成功したら.
		if( SUCCEEDED(
			pCMain->InitWindow(
				hInstance,
				0, 0,
				WND_W, WND_H)))
		{
			//Dx11用の初期化.
			if( SUCCEEDED( pCMain->Create() ))
			{
				//メッセージループ.
				pCMain->Loop();
			}
		}
		//終了.
		pCMain->Release();	//Direct3Dの解放.

	}

	return 0;
}