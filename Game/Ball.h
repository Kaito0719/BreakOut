// 多重インクルードの防止 ==================================================
#pragma once


// クラスの定義 ============================================================
// <ボール> ----------------------------------------------------------
class Ball
{
public:
	// クラス定数の宣言
	static const int WIDTH = 10;
	static const int HEIGHT = 10;
	static const ColorCode COLORS[8];


	// データメンバの宣言
	Vector2D  m_velocity;
private:
	
	ColorCode m_color;
public:
	Point2D   m_position;

	// メンバ関数の宣言
public:
	// コンストラクタ
	Ball(int pointx, int pointy);

	// デストラクタ
	~Ball();

public:
	// 操作
	void Update(void);
	void Render(void);

};