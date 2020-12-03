
#include "ResultScene.h"
#include "DxLib.h"
#include "../Manager/SceneManager.h"

ResultScene::ResultScene()
{
}

ResultScene::~ResultScene()
{
}

void ResultScene::Exec()
{
	// @@Dummy 遷移確認用の仮処理
	m_Step++;
	if( m_Step >= 120 )
	{
		SceneManager::SetNextScene( SceneID_Title );
	}
}

void ResultScene::Draw()
{
	// 画面左上にデバッグ用の文字を黒で表示する
	DrawString( 20, 20, "ResultScene", GetColor(0,0,0) );
}

bool ResultScene::IsEnd() const
{
	// @@Dummy 遷移確認用の仮処理
	return ( m_Step >= 120 );
}


