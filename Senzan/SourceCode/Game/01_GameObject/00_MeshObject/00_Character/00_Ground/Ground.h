#pragma once

#include "Game/01_GameObject/00_MeshObject/MeshObject.h"

/*********************************************************
*	地面クラス
**/
class Ground
	: public MeshObject
{
public:
	Ground();
	virtual ~Ground();

	virtual void Update() override;
	virtual void Draw() override;

protected:

};
