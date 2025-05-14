﻿#include "Main.h"
#include "Ggraphic\\DirectX\\DirectX12.h"
#include "Ggraphic\\PMD\\PMDActor.h"
#include "Ggraphic\\PMD\\PMDRenderer.h"
#include "Ggraphic\\PMX\\PMXActor.h"
#include "Ggraphic\\PMX\\PMXRenderer.h"

#ifdef _DEBUG
#include <crtdbg.h>
#endif

// ウィンドウを画面中央で起動を有効にする.
#define ENABLE_WINDOWS_CENTERING

#define ISOMX 0

//=================================================
// 定数.
//=================================================
const TCHAR WND_TITLE[] = _T("DirectX12");
const TCHAR APP_NAME[] = _T("DirectX12");

//=================================================
// コンストラクタ.
//=================================================
Main::Main()
    : m_hWnd            ( nullptr )
    , m_pDx12           ( nullptr )
    , m_pPmdActor       ( nullptr )
    , m_pPMDRenderer    ( nullptr )
    , m_pPMXActor       ( nullptr )
    , m_pPMXRenderer    ( nullptr )
{
}

//=================================================
// デストラクタ.
//=================================================
Main::~Main()
{
}

// 構築処理.
HRESULT Main::Create()
{
    m_pDx12 = std::make_shared<DirectX12>();
    m_pDx12->Create(m_hWnd);

    //m_pPMDRenderer = std::make_shared<CPMDRenderer>(*m_pDx12);
    //m_pPmdActor = std::make_shared<CPMDActor>("Data\\Model\\PMD\\Cube\\Cube.pmd", *m_pPMDRenderer);
#if ISOMX
    m_pPMDRenderer = std::make_shared<CPMDRenderer>(*m_pDx12);
    m_pPmdActor = std::make_shared<CPMDActor>("Data\\Model\\PMD\\Cube\\Cube.pmd", *m_pPMDRenderer);
    
#else 
    m_pPMXRenderer = std::make_shared<PMXRenderer>(*m_pDx12);
    m_pPMXActor = std::make_shared<PMXActor>("Data\\Model\\PMX\\Hatune\\REM式プロセカ風初音ミクN25.pmx", *m_pPMXRenderer);
    // Data\\Model\\PMX\\Hatune\\REM式プロセカ風初音ミクN25.pmx
    // Data\\Model\\PMX\\HatuneVer2\\初音ミクVer2.pmx
    // Data\\Model\\PMX\\Cube\\Cube.pmx"
#endif

    return S_OK;
}

// データロード処理.
HRESULT Main::LoadData()
{
    // 必要に応じてデータロード処理を追加.
    return S_OK;
}

// 更新処理.
void Main::Update()
{
    if (m_pPmdActor) {
        m_pPmdActor->Update();
    }


    if (m_pPMXActor) {
        m_pPMXActor->Update();
    }

    if (m_pDx12) {
        m_pDx12->Update();
    }
}

// 描画処理.
void Main::Draw()
{
    if (!m_pDx12) return;

    // 全体の描画準備.
    m_pDx12->BeginDraw();

#if ISOMX
	//PMD用の描画パイプラインに合わせる
    m_pDx12->GetCommandList()->SetPipelineState(m_pPMDRenderer->GetPipelineState());
    //ルートシグネチャもPMD用に合わせる
    m_pDx12->GetCommandList()->SetGraphicsRootSignature(m_pPMDRenderer->GetRootSignature());

#else 
    //PMD用の描画パイプラインに合わせる
    m_pDx12->GetCommandList()->SetPipelineState(m_pPMXRenderer->GetPipelineState());
    //ルートシグネチャもPMX用に合わせる
    m_pDx12->GetCommandList()->SetGraphicsRootSignature(m_pPMXRenderer->GetRootSignature());
#endif
    m_pDx12->GetCommandList()->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

    m_pDx12->SetScene();

    if (m_pPmdActor) {
        m_pPmdActor->Draw();
    }

    if (m_pPMXActor) {
        m_pPMXActor->Draw();
    }

    // 終了処理.
    m_pDx12->EndDraw();

    // フリップ.
    m_pDx12->GetSwapChain()->Present(1, 0);
}

// 解放処理.
void Main::Release()
{
    if (m_pPmdActor) {
        m_pPmdActor.reset();
    }

    if (m_pPMDRenderer) {
        m_pPMDRenderer.reset();
    }
    if (m_pPMXActor) {
        m_pPMXActor.reset();
    }

    if (m_pPMXRenderer) {
        m_pPMXRenderer.reset();
    }

#if _DEBUG
    // オブジェクトの解放ミスを検出.
    MyComPtr<ID3D12DebugDevice> debugDevice;
    if (SUCCEEDED(m_pDx12->GetDevice()->QueryInterface(IID_PPV_ARGS(debugDevice.GetAddressOf())))) {
        debugDevice->ReportLiveDeviceObjects(D3D12_RLDO_DETAIL);
    }
#endif  // _DEBUG

    if (m_pDx12) {
        m_pDx12.reset();
    }
}

// メッセージループ.

void Main::Loop()
{
    float rate = 0.0f;   // フレームレート制御用.
    DWORD syncOld = timeGetTime();
    DWORD syncNow;

    MSG msg = {};
    while (msg.message != WM_QUIT) {
        syncNow = timeGetTime();

        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else if (syncNow - syncOld >= rate) {
            syncOld = syncNow;

            Update();
            Draw();
        }
    }
}

// ウィンドウ初期化関数.
HRESULT Main::InitWindow(HINSTANCE hInstance, INT x, INT y, INT width, INT height)
{
    WNDCLASSEX wc = {};
    wc.cbSize = sizeof(wc);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = MsgProc;
    wc.hInstance = hInstance;
    wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)GetStockObject(LTGRAY_BRUSH);
    wc.lpszClassName = APP_NAME;

    if (!RegisterClassEx(&wc)) {
        return E_FAIL;
    }

    RECT rect = { 0, 0, width, height };
    AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, FALSE);

    INT winWidth = rect.right - rect.left;
    INT winHeight = rect.bottom - rect.top;
    INT winX = (GetSystemMetrics(SM_CXSCREEN) - winWidth) / 2;
    INT winY = (GetSystemMetrics(SM_CYSCREEN) - winHeight) / 2;

    m_hWnd = CreateWindow(
        APP_NAME, WND_TITLE,
        WS_OVERLAPPEDWINDOW,
        winX, winY, winWidth, winHeight,
        nullptr, nullptr, hInstance, this
    );

    if (!m_hWnd) {
        return E_FAIL;
    }

    ShowWindow(m_hWnd, SW_SHOW);
    UpdateWindow(m_hWnd);

    return S_OK;
}

// ウィンドウ関数（メッセージ毎の処理）.
LRESULT CALLBACK Main::MsgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    // hWndに関連付けられたCMainを取得.
    // MEMO : ウィンドウが作成されるまでは nullptr になる可能性がある.
    Main* pMain = reinterpret_cast<Main*>(GetWindowLongPtr(hWnd, GWLP_USERDATA));

    // ウィンドウが初めて作成された時.
    if (uMsg == WM_NCCREATE) {
        // CREATESTRUCT構造体からCMainのポインタを取得.
        CREATESTRUCT* pCreateStruct = reinterpret_cast<CREATESTRUCT*>(lParam);
        // SetWindowLongPtrを使用しhWndにCMainインスタンスを関連付ける.
        SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pCreateStruct->lpCreateParams));
        // デフォルトのウィンドウプロシージャを呼び出して処理を進める.
        return DefWindowProc(hWnd, uMsg, wParam, lParam);
    }

    if (pMain) {
        switch (uMsg) {
            // ウィンドウが破棄されるとき.
        case WM_DESTROY:
            // GPUの終了を待ってからウィンドウを閉じる.
            pMain->m_pDx12->WaitForGPU();
            PostQuitMessage(0);
            break;

            // キーボードが押されたとき.
        case WM_KEYDOWN:
            if (wParam == VK_ESCAPE) {
                if (MessageBox(hWnd, _T("ゲームを終了しますか？"), _T("警告"), MB_YESNO) == IDYES) {
                    DestroyWindow(hWnd);
                }
            }
            break;

        default:
            return DefWindowProc(hWnd, uMsg, wParam, lParam);
        }
    }

    return DefWindowProc(hWnd, uMsg, wParam, lParam);
}
