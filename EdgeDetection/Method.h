#pragma once
#include "opencv2\opencv.hpp"
#include "opencv2\core.hpp"
#include "opencv2\highgui\highgui.hpp"
#include <iostream>
// Tạo enum các hướng
enum directOfGrad
{
	East,
	East_North,
	North,
	West_North
};

//Tạo enum kiểm tra điểm biên cạnh
enum testEdgePoint
{
	Edge_Point,
	Not_Edge_Point,
	Undone
};

const float PI = 3.14;

using namespace std;
using namespace cv;

//Tính tổng các phần tử của vector
float sum(vector<float>X);
//Tạo ma trận kernel Gaussian
vector<float>createGaussKernel(int height, int width, float sigma);
//Lọc bằng Gaussian
int gaussBlur(const Mat& srcImg, Mat& dstImg);
//Tính tích chập
int convolution(const Mat& srcImg, Mat& dstImg, vector<float> kernel);
//Xác định độ lớn của đạo hàm và hướng của điểm ảnh
void calcGradient(const Mat& img, Mat& weightOfGrad, Mat& directOfGrad);

int detectBySobel(const Mat& srcImg, Mat& dstImg);
int detectByPrewitt(const Mat& srcImg, Mat& dstImg);
int detectByLaplace(const Mat& srcImg, Mat& dstImg);
int detectByCanny(const Mat& srcImg, Mat& dstImg, int lowThresh, int highThresh);
