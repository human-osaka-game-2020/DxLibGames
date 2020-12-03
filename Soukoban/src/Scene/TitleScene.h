﻿
#ifndef TITLE_SCENE_H
#define TITLE_SCENE_H

// 継承する、基底クラスのヘッダー
#include "SceneBase.h"

// タイトルシーンクラス
class TitleScene : public SceneBase
{
public:
	TitleScene();
	virtual ~TitleScene();

	virtual void Exec();	// 処理を行う
	virtual void Draw();	// 描画を行う

	virtual bool IsEnd() const;	// シーンが終了したかどうかを返す
};

#endif // #ifndef TITLE_SCENE_H
