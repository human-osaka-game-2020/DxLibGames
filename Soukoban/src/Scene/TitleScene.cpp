
#include "TitleScene.h"
#include "DxLib.h"
#include "../Manager/SceneManager.h"
#include "../Manager/InputManager.h"

// 実行ステップ定義
enum
{
	STEP_LOGO_IN,	// ロゴ入場待ち
	STEP_INPUT,		// 入力待ち
	STEP_END,		// シーン終了
};

TitleScene::TitleScene()
{
	m_Step = STEP_LOGO_IN;
}

TitleScene::~TitleScene()
{
}

void TitleScene::Exec()
{
	switch( m_Step )
	{
	case STEP_LOGO_IN:	step_LogoIn();	break;
	case STEP_INPUT:	step_Input();	break;
	default:							break;
	};
}

void TitleScene::Draw()
{
	// 画面左上にデバッグ用の文字を黒で表示する
	DrawString( 20, 20, "TitleScene", GetColor(0,0,0) );
}

bool TitleScene::IsEnd() const
{
	return ( m_Step == STEP_END );
}

// ロゴ入場
void TitleScene::step_LogoIn()
{
	m_Step = STEP_INPUT;
}
// 入力受付
void TitleScene::step_Input()
{
	InputManager* pInputMng = InputManager::GetInstance();
	if( pInputMng->IsPush(KeyType_Enter) )
	{
		m_Step = STEP_END;
		SceneManager::GetInstance()->SetNextScene( SceneID_InGame );
	}
}

