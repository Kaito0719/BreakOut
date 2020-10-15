// 多重インクルードの防止 ==================================================
#pragma once


// クラスの定義 ============================================================
// <ブロック> ----------------------------------------------------------
class Block
{
public:
	// クラス定数の宣言
	static const int WIDTH;
	static const int HEIGHT;
	static const ColorCode COLORS[8];


	// データメンバの宣言
	private:
		ColorCode m_color;
	public:
		Point2D   m_position;


	// メンバ関数の宣言
	public:
		// コンストラクタ
		Block(int x, int y, int type);

		// デストラクタ
		~Block();

	public:
		// 操作
		void Render(void);
};