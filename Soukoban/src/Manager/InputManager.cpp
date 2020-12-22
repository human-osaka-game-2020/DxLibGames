
#include "InputManager.h"

InputManager::InputManager()
{
}

InputManager::~InputManager()
{
}

// キー入力更新
void InputManager::Update()
{
	for( int i = 0; i < KeyType_Max; i++ )
	{
		// 現在のキーの入力状態を取得
		const bool now = (CheckHitKey(KEY_ASSIGN[i]) == 1);

		// 前回のキー情報と比較をして現在の状態を更新
		m_State[i].on   = now;
//		m_State[i].push = (now == true)  && (m_State[i].old == false);
//		m_State[i].pull = (now == false) && (m_State[i].old == true);
		m_State[i].push =  now & !m_State[i].old;
		m_State[i].pull = !now &  m_State[i].old;

		// 現在の値をoldへ代入
		m_State[i].old = now;
	}
}

// キーが押されたか
bool InputManager::IsPush( KeyType key ) const
{
	if( key == KeyType_Max ){ return false; }
	return m_State[key].push;
}

// キーが押下されているか
bool InputManager::IsOn( KeyType key ) const
{
	if( key == KeyType_Max ){ return false; }
	return m_State[key].on;
}

// キーが離されたか
bool InputManager::IsPull( KeyType key ) const
{
	if( key == KeyType_Max ){ return false; }
	return m_State[key].pull;
}

