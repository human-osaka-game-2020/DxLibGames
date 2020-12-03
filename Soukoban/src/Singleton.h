
#ifndef SINGLETON_H
#define SINGLETON_H

// シングルトンデザインパターン
class Singleton
{
	//-----
	// クラスの実際の処理


	//-----
	// シングルトンデザイン
private:
	Singleton(){ }				// コンストラクタ抑制
	virtual ~Singleton(){ }		// デストラクタ抑制

private:
	// 自分自身のポインタ変数(自分自身の唯一の実体)
	static Singleton*	m_pInstance;

public:
	// 実体を作る関数
	static void CreateInstance()
	{
		// すでに作られているなら新しく作らないことを保証
		if( m_pInstance == nullptr )
		{
			m_pInstance = new Singleton();
		}
	}
	// 実体を破棄する関数
	static void DestroyInstance()
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}
	// 実体を取得する関数
	static Singleton* GetInstance()
	{
		return m_pInstance;
	}
	// 実体が存在しないか確認する
	static bool IsNull()
	{
		return (m_pInstance == nullptr);
	}
};

#endif	// #ifndef SINGLETON_H



