
#include "ResultScene.h"
#include "DxLib.h"
#include "../Manager/SceneManager.h"
#include "../Manager/InputManager.h"

// 実行ステップ定義
enum
{
	STEP_INPUT,		// 入力待ち
	STEP_END,		// シーン終了
};

ResultScene::ResultScene()
{
	m_Step = STEP_INPUT;
}

ResultScene::~ResultScene()
{
}

void ResultScene::Exec()
{
	switch ( m_Step )
	{
	case STEP_INPUT:	step_Input();	break;
	default:							break;
	}
}

void ResultScene::Draw()
{
	// 画面左上にデバッグ用の文字を黒で表示する
	DrawString( 20, 20, "ResultScene", GetColor(0,0,0) );
}

bool ResultScene::IsEnd() const
{
	return ( m_Step == STEP_END );
}

// 入力受付
void ResultScene::step_Input()
{
	InputManager* pInputMng = InputManager::GetInstance();
	if( pInputMng->IsPush(KeyType_Enter) )
	{
		m_Step = STEP_END;
		SceneManager::GetInstance()->SetNextScene( SceneID_Title );
	}
}


