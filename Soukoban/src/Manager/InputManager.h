
#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include "../KeyDefinition.h"
#include "../Singleton.h"

// 入力管理クラス
class InputManager : public Singleton<InputManager>
{
private:
	// キー状態構造体
	struct KeyState
	{
		bool	old;	// 前回チェック時のフラグ状態

		bool	push;	// 押された瞬間
		bool	on;		// 押下されている
		bool	pull;	// 離された瞬間

		KeyState()
			: old ( false )
			, push( false )
			, on  ( false )
			, pull( false )
		{}
	};

public:
	InputManager();
	~InputManager();

	// キー入力更新
	void Update();

	// キーが押されたか
	bool IsPush( KeyType key ) const;
	// キーが押下されているか
	bool IsOn( KeyType key ) const;
	// キーが離されたか
	bool IsPull( KeyType key ) const;

private:
	KeyState m_State[KeyType_Max];
};

#endif	// #ifndef INPUT_MANAGER_H
