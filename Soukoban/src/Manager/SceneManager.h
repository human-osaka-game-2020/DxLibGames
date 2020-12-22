
#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "../Definition.h"
#include "../Singleton.h"

// シーン管理クラス
class SceneManager : public Singleton<SceneManager>
{
public:
	SceneManager();
	~SceneManager();

	void Exec();	// シーンの実行
	void Draw();	// シーンの描画

	void SetNextScene( SceneID next_ );	// 次のシーン設定

private:
	class SceneBase* create_NextScene();	// 次のシーンを作成

private:
	class SceneBase*	m_pScene;		// 実行中のシーン
	static SceneID 		m_NextSceneID;	// 次に作るシーンのID
};

#if 0
//------------------------------------------------------------
// シングルトンデザインパターン（クラスに直接書いていく場合）
private:
	// 自分自身のポインタ変数(自分自身の唯一の実体)
	static SceneManager*	m_pInstance;

public:
	// 実体を作る関数
	static void CreateInstance()
	{
		// すでに作られているなら新しく作らないことを保証
		if( m_pInstance == nullptr )
		{
			m_pInstance = new SceneManager();
		}
	}
	// 実体を破棄する関数
	static void DestroyInstance()
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}
	// 実体を取得する関数
	static SceneManager* GetInstance()
	{
		return m_pInstance;
	}
	// 実体が存在しないか確認する
	static bool IsNull()
	{
		return (m_pInstance == nullptr);
	}
};
// static メンバ変数を初期化
SceneManager* SceneManager::m_pInstance = nullptr;
#endif	// #if 0

#endif // #ifndef SCENEMANAGER_H
