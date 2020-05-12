#include"Method.h"

int main(int argc, char** argv)
{
	if (argc != 3)
	{
		cout << "Chuong trinh phat hien bien canh cua anh" << endl;
		cout << "<tenchuongtrinh><duongdantaptinanh><malenh>" << endl;
		cout << "Ma lenh: " << endl << "1. By Sobel"
			<< endl << "2. By Prewitt" << endl << "3. By Laplace" << endl <<
			"4. By Canny (low threshold =10, high threshold=50)" << endl;
		return -1;
	}
	Mat image;
	image = imread(argv[1], IMREAD_GRAYSCALE);
	if (!image.data)
	{
		cout << "Khong the mo anh" << std::endl;
		return -1;
	}
	namedWindow("Display window", WINDOW_AUTOSIZE);
	imshow("Display window", image);

	Mat dstImg = Mat::zeros(image.size(), image.type());

	if (strcmp(argv[2], "1") == 0)
	{
		detectBySobel(image, dstImg);
		imshow("Sobel output", dstImg);
	}
	if (strcmp(argv[2], "2") == 0)
	{
		detectByPrewitt(image, dstImg);
		imshow("Prewitt output", dstImg);
	}
	if (strcmp(argv[2], "3") == 0)
	{
		detectByLaplace(image, dstImg);
		imshow("Laplace output", dstImg);
	}
	if (strcmp(argv[2], "4") == 0)
	{
		detectByCanny(image, dstImg, 10, 50);
		imshow("Canny output", dstImg);
	}
	waitKey(0);
	return 0;
}