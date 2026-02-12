#pragma once

#include "..//BossAttackStateBase.h"	//基底クラス.

class BossIdolState;
class Boss;

/**********************************************************************************
* @author    : 未定.
* @date      : 未定.
* @brief     : ボス踏みつけ攻撃ステートクラス.
**********************************************************************************/
class BossStompState final
	: public BossAttackStateBase
{
public:
	enum class enAttack : byte
	{
		None,		//何もしない.
		Stomp,		//踏みつけ攻撃をする.
		CoolTime,	//クールタイム.
		Trans		//Idolに状態遷移.
	};

public:
	BossStompState(Boss* owner);
	~BossStompState() override;

	void Enter() override;
	void Update() override;
	void LateUpdate() override;
	void Draw() override;
	void Exit() override;

    // PlayerのParry成功時硬直させたいアニメーションとタイミング.
    std::pair<Boss::enBossAnim, float> GetParryAnimPair() override;

    // ImGui と設定の読み書き.
    void DrawImGui() override;
    void LoadSettings() override;
    void SaveSettings() const override;
    std::filesystem::path GetSettingsFileName() const override { return std::filesystem::path("BossStompState.json"); }
private:
    void BossAttack();
    // (基底クラスのタイミング/ウィンドウを使用)
private:
	enAttack m_List;

	std::shared_ptr<BossIdolState> m_pIdol;
	//====================================================.
	// 踏みつけに必要になるメンバ変数を書く.
	//====================================================.
	DirectX::XMFLOAT3 m_Velocity;

	//ジャンプの初速度.
	float m_JumpPower;
	//重力加速度.
	float m_Gravity;
	//ジャンプ中のフラグ.
	bool m_JumpFrag;
	// 前フレームの Y 値を保持してスムーズに移動させる.
	// float m_LastY; // 一時無効化: Y 制御オフ.
	//着地フラグ.
	//この時に時間を取得して3秒後にIdolに遷移等を書く.
	bool m_GroundedFrag;
	//===================================================.
	// タイマー変数.
	//===================================================.
	//タイマーの初期化変数.
	float m_Timer;
	//遷移させるタイミングの変数.
	float TransitionTimer;

	//上がる速度のスピード設定用.
	float m_UpSpeed;

	// ステートタイマー / フラグ.
	float m_WaitSeconds = 0.4f;    // アニメ減速前の待機秒数.
	float m_SlowAnimSpeed = 0.5f;  // 減速時のアニメ速度.
	bool  m_AnimSlowed = false;    // アニメが減速されたか.
	bool  m_IsMoving = false;      // ボスが移動中か (踏みつけフェーズ).
    // タイミングは基底クラスのm_CurrentTimeを使用.
    // 減速持続制御: 遅延後にアニメが減速し続ける時間.
    float m_SlowDuration = 1.5f;  // アニメ減速を保持する秒数.
    float m_SlowElapsed = 0.0f;   // 減速開始からの経過時間.
    // 踏みつけコライダー設定 (永続化).
    float m_StompRadius = 30.0f;
    float m_StompDamage = 15.0f;
    bool  m_StompActive = false;

	// 移動イージングパラメータ.
	float m_MoveDuration = 0.8f;   // 移動/イージングの持続時間 (秒).
	float m_MoveTimer = 0.0f;      // 移動開始からの経過時間.
	float m_Distance = 0.0f;       // 水平移動の総距離.
	DirectX::XMFLOAT3 m_MoveVec;   // 正規化された水平方向ベクトル.
    // 上昇/下降の垂直制御.
    bool m_UseVerticalEasing = true;
    float m_AscentHeight = 10.0f;       // 開始位置からの最高到達高さ.
    float m_AscentDuration = 0.25f;     // 上昇時間 (秒).
    float m_DescentDuration = 0.55f;    // 下降時間 (秒).
    MyEasing::Type m_AscentEasing = MyEasing::Type::OutSine;
    MyEasing::Type m_DescentEasing = MyEasing::Type::InQuad;
    float m_VerticalTimer = 0.0f;       // 垂直イージングタイマー.
    float m_StartY = 0.0f;

	//====================================================.
	// 飛びかかり（前方移動）用メンバ変数.
	//====================================================.
	float m_ForwardSpeed;           // 前方移動速度.
	DirectX::XMFLOAT3 m_TargetPos;  // 目標位置（プレイヤー位置）.
	DirectX::XMFLOAT3 m_StartPos_Stomp;   // 開始位置.
    bool m_HasLanded;               // 着地済みフラグ（ダメージ1回のみ）.
    // 基底クラスのm_ColliderWindowsを使用.

    float m_JumpedSoundTiming;
    bool m_JumpedSoundPlayed;
    bool m_LandedSoundPlayed;
};
