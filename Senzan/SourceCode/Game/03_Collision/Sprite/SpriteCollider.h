#pragma once

class SpriteCollider
{
public:
	// 点と四角のあたり判定.
	static bool PointInSquare(POINT point, DirectX::XMFLOAT2 pos, DirectX::XMFLOAT2 size);
};
