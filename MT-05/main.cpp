#include <Novice.h>
#include <assert.h>
#define _USE_MATH_DEFINES
#include <math.h>

const char kWindowTitle[] = "学籍番号";

struct Vector3
{
	float x;
	float y;
	float z;
};

struct Matrix4x4 {
	float m[4][4];
};

static const int kRowHeigth = 20;
static const int kColumWidth = 60;

void MatrixScrennPrint(int x, int y, const Matrix4x4& matrix, const char* label) {

	Novice::ScreenPrintf(x, y, "%s", label);
	for (int row = 0; row < 4; row++) {
		for (int colum = 0; colum < 4; colum++) {
			Novice::ScreenPrintf(x + colum * kColumWidth, y + (row + 1) * kRowHeigth, "%6.02f", matrix.m[row][colum]);
		}
	}
}




Matrix4x4 Multi(Matrix4x4 m1, Matrix4x4 m2) {
	Matrix4x4 answer;

	answer.m[0][0] = m1.m[0][0] * m2.m[0][0] + m1.m[0][1] * m2.m[1][0] +
		m1.m[0][2] * m2.m[2][0] + m1.m[0][3] * m2.m[3][0];
	answer.m[0][1] = m1.m[0][0] * m2.m[0][1] + m1.m[0][1] * m2.m[1][1] +
		m1.m[0][2] * m2.m[2][1] + m1.m[0][3] * m2.m[3][1];
	answer.m[0][2] = m1.m[0][0] * m2.m[0][2] + m1.m[0][1] * m2.m[1][2] +
		m1.m[0][2] * m2.m[2][2] + m1.m[0][3] * m2.m[3][2];
	answer.m[0][3] = m1.m[0][0] * m2.m[0][3] + m1.m[0][1] * m2.m[1][3] +
		m1.m[0][2] * m2.m[2][3] + m1.m[0][3] * m2.m[3][3];

	answer.m[1][0] = m1.m[1][0] * m2.m[0][0] + m1.m[1][1] * m2.m[1][0] +
		m1.m[1][2] * m2.m[2][0] + m1.m[1][3] * m2.m[3][0];
	answer.m[1][1] = m1.m[1][0] * m2.m[0][1] + m1.m[1][1] * m2.m[1][1] +
		m1.m[1][2] * m2.m[2][1] + m1.m[1][3] * m2.m[3][1];
	answer.m[1][2] = m1.m[1][0] * m2.m[0][2] + m1.m[1][1] * m2.m[1][2] +
		m1.m[1][2] * m2.m[2][2] + m1.m[1][3] * m2.m[3][2];
	answer.m[1][3] = m1.m[1][0] * m2.m[0][3] + m1.m[1][1] * m2.m[1][3] +
		m1.m[1][2] * m2.m[2][3] + m1.m[1][3] * m2.m[3][3];

	answer.m[2][0] = m1.m[2][0] * m2.m[0][0] + m1.m[2][1] * m2.m[1][0] +
		m1.m[2][2] * m2.m[2][0] + m1.m[2][3] * m2.m[3][0];
	answer.m[2][1] = m1.m[2][0] * m2.m[0][1] + m1.m[2][1] * m2.m[1][1] +
		m1.m[2][2] * m2.m[2][1] + m1.m[2][3] * m2.m[3][1];
	answer.m[2][2] = m1.m[2][0] * m2.m[0][2] + m1.m[2][1] * m2.m[1][2] +
		m1.m[2][2] * m2.m[2][2] + m1.m[2][3] * m2.m[3][2];
	answer.m[2][3] = m1.m[2][0] * m2.m[0][3] + m1.m[2][1] * m2.m[1][3] +
		m1.m[2][2] * m2.m[2][3] + m1.m[2][3] * m2.m[3][3];

	answer.m[3][0] = m1.m[3][0] * m2.m[0][0] + m1.m[3][1] * m2.m[1][0] +
		m1.m[3][2] * m2.m[2][0] + m1.m[3][3] * m2.m[3][0];
	answer.m[3][1] = m1.m[3][0] * m2.m[0][1] + m1.m[3][1] * m2.m[1][1] +
		m1.m[3][2] * m2.m[2][1] + m1.m[3][3] * m2.m[3][1];
	answer.m[3][2] = m1.m[3][0] * m2.m[0][2] + m1.m[3][1] * m2.m[1][2] +
		m1.m[3][2] * m2.m[2][2] + m1.m[3][3] * m2.m[3][2];
	answer.m[3][3] = m1.m[3][0] * m2.m[0][3] + m1.m[3][1] * m2.m[1][3] +
		m1.m[3][2] * m2.m[2][3] + m1.m[3][3] * m2.m[3][3];

	return answer;
}

Matrix4x4 MakeAffinMatrix(Vector3 scale, Vector3 rotate, Vector3 translate) {

	Matrix4x4 rotetaMatrix_X;

	Matrix4x4 rotetaMatrix_Y;

	Matrix4x4 rotetaMatrix_Z;

	Matrix4x4 rotate_answer;



	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {

			rotetaMatrix_X.m[i][j] = 0;
			rotetaMatrix_Y.m[i][j] = 0;
			rotetaMatrix_Z.m[i][j] = 0;
			if (i == j) {
				rotetaMatrix_X.m[i][j] = 1;
				rotetaMatrix_Y.m[i][j] = 1;
				rotetaMatrix_Z.m[i][j] = 1;
			}
		}
	}

	rotetaMatrix_X.m[1][1] = cosf(rotate.x);
	rotetaMatrix_X.m[1][2] = sinf(rotate.x);
	rotetaMatrix_X.m[2][1] = -sinf(rotate.x);
	rotetaMatrix_X.m[2][2] = cosf(rotate.x);

	rotetaMatrix_Y.m[0][0] = cosf(rotate.y);
	rotetaMatrix_Y.m[0][2] = -sinf(rotate.y);
	rotetaMatrix_Y.m[2][0] = sinf(rotate.y);
	rotetaMatrix_Y.m[2][2] = cosf(rotate.y);

	rotetaMatrix_Z.m[0][0] = cosf(rotate.z);
	rotetaMatrix_Z.m[0][1] = sinf(rotate.z);
	rotetaMatrix_Z.m[1][1] = cosf(rotate.z);
	rotetaMatrix_Z.m[1][0] = -sinf(rotate.x);

	rotate_answer = Multi(rotetaMatrix_X, Multi(rotetaMatrix_Y, rotetaMatrix_Z));


	Matrix4x4 worldMatrix;
	
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i == 0) {
				worldMatrix.m[i][j] = rotate_answer.m[i][j] * scale.x;
			}
			else if (i == 1) {
				worldMatrix.m[i][j] = rotate_answer.m[i][j] * scale.y;
			}
			else if (i == 2) {
				worldMatrix.m[i][j] = rotate_answer.m[i][j] * scale.z;
			}
			if (j == 4) {
				worldMatrix.m[i][j] = 0;
			}
		}
	}

	worldMatrix.m[3][0] = translate.x;
	worldMatrix.m[3][1] = translate.y;
	worldMatrix.m[3][2] = translate.z;
	worldMatrix.m[3][3] = 1;

	return worldMatrix;
}
 //Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		Vector3 scale{ 1.2f,0.79f,-2.1f };
		Vector3 rotate{ 0.4f,1.43f,-0.8f };
		Vector3 translate{ 2.7f,-4.15f,1.57f };

		Matrix4x4 worldMatrix = MakeAffinMatrix(scale, rotate, translate);



		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		MatrixScrennPrint(0, 0, worldMatrix, "worldMatrix");

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
