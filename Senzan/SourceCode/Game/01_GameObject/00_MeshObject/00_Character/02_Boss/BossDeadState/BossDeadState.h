#pragma once
#include "System/Utility/StateMachine/StateBase.h"

class Boss;

/*********************************************************************
*	BossDeadClass
**/

class BossDeadState final
	: public StateBase<Boss>
{
public:
	BossDeadState(Boss* owner);
	~BossDeadState();

	//最初に入る.
	void Enter() override;
	//動作.
	void Update() override;
	//かかなくていい.
	void LateUpdate() override;
	//描画.
	void Draw() override;
	//終わるときに一回だけ入る.
	void Exit() override;

private:
};
