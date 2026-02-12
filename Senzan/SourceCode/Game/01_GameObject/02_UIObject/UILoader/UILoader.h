#pragma once
#include "02_UIObject/UIObject.h"

/**********************************************************************************
* @author    : 未定.
* @date      : 未定.
* @brief     : UI読込関連.
**********************************************************************************/
namespace UILoader
{
	/******************************************************
	* @brief SceneJsonでSpiteManagerから情報を取得.
	* @param name	SceneJsonのパス.
	* @param uis	std::vector<CUIObject*>.
	******************************************************/
	void LoadFromJson(
		const std::string& scenepath,
		std::vector<std::shared_ptr<UIObject>>& uis);
}
