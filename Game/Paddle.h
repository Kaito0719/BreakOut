// 多重インクルードの防止 =================================================
#pragma once


// クラスの定義 ============================================================
// <パドル> ----------------------------------------------------------
class Paddle
{
public:
	// クラス定数の宣言
	static const int WIDTH;
	static const int HEIGHT;


	// データメンバの宣言
	Vector2D  m_velocity;
	private:
		
	public:
		Point2D   m_position;

	// メンバ関数の宣言
	public:
		// コンストラクタ
		Paddle();

		// デストラクタ
		~Paddle();

	public:
		// 操作
		void Update(void);
		void Render(void);

};