
#include "../Definition.h"

// シーン管理クラス
class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	void Exec();	// シーンの実行
	void Draw();	// シーンの描画

	// 次のシーンを設定する関数をstatic関数にすることで
	// 実体がどこにあっても良い状態を作る
	static void SetNextScene( SceneID next_ );	// 次のシーン設定

private:
	class SceneBase* create_NextScene();	// 次のシーンを作成

private:
	class SceneBase*	m_pScene;		// 実行中のシーン
	static SceneID 		m_NextSceneID;	// 次に作るシーンのID
};

