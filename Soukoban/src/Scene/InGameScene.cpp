
#include "InGameScene.h"
#include "DxLib.h"
#include "../Manager/SceneManager.h"

InGameScene::InGameScene()
{
}

InGameScene::~InGameScene()
{
}

void InGameScene::Exec()
{
	// @@Dummy 遷移確認用の仮処理
	m_Step++;
	if( m_Step >= 120 )
	{
		SceneManager::SetNextScene( SceneID_Result );
	}
}

void InGameScene::Draw()
{
	// 画面左上にデバッグ用の文字を黒で表示する
	DrawString( 20, 20, "InGameScene", GetColor(0,0,0) );
}

bool InGameScene::IsEnd() const
{
	// @@Dummy 遷移確認用の仮処理
	return ( m_Step >= 120 );
}

