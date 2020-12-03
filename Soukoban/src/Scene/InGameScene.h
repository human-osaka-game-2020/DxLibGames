
#ifndef INGAME_SCENE_H
#define INGAME_SCENE_H

// 継承する、基底クラスのヘッダー
#include "SceneBase.h"

// インゲームシーンクラス
class InGameScene : public SceneBase
{
public:
	InGameScene();
	virtual ~InGameScene();

	virtual void Exec();	// 処理を行う
	virtual void Draw();	// 描画を行う

	virtual bool IsEnd() const;	// シーンが終了したかどうかを返す
};

#endif // #ifndef INGAME_SCENE_H
