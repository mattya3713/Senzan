#pragma once

#include "Game//01_GameObject//00_MeshObject//MeshObject.h".

/*********************************************************************
*	空に画像を入れるクラス.
**/

class BackGround
	: public MeshObject
{
public:
	BackGround();
	~BackGround();

	void Update() override;
	void Draw() override;

private:

};
