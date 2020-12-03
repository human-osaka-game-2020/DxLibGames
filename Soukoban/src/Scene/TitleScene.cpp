
#include "TitleScene.h"
#include "DxLib.h"
#include "../Manager/SceneManager.h"

TitleScene::TitleScene()
{
}

TitleScene::~TitleScene()
{
}

void TitleScene::Exec()
{
	// @@Dummy 遷移確認用の仮処理
	m_Step++;
	if( m_Step >= 120 )
	{
		SceneManager::SetNextScene( SceneID_InGame );
	}
}

void TitleScene::Draw()
{
	// 画面左上にデバッグ用の文字を黒で表示する
	DrawString( 20, 20, "TitleScene", GetColor(0,0,0) );
}

bool TitleScene::IsEnd() const
{
	// @@Dummy 遷移確認用の仮処理
	return ( m_Step >= 120 );
}

