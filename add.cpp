#include<opencv2\opencv.hpp>
#include <algorithm>
using namespace cv;

void addUp()
{
	Mat add1 = imread("f5.jpg");
	Mat add2 = imread("f6.jpg");

	imshow("before1", add1);
	imshow("before2", add2);

	for (int i = 1; i < add1.rows; i++)
	{
		for (int j = 1; j < add1.cols; j++)
		{
			add1.at<Vec3b>(i, j)[0] = (2* add1.at<Vec3b>(i, j)[0] + add2.at<Vec3b>(i, j)[0])/3;
			add1.at<Vec3b>(i, j)[1] = (2* add1.at<Vec3b>(i, j)[1] + add2.at<Vec3b>(i, j)[1])/3;
			add1.at<Vec3b>(i, j)[2] = (2* add1.at<Vec3b>(i, j)[2] + add2.at<Vec3b>(i, j)[2])/3;
			
			//add1.at<Vec3b>(i, j)[0] = (add1.at<Vec3b>(i, j)[0] + add2.at<Vec3b>(i, j)[0]) / 2;
			//add1.at<Vec3b>(i, j)[1] = (add1.at<Vec3b>(i, j)[1] + add2.at<Vec3b>(i, j)[1]) / 2;
			//add1.at<Vec3b>(i, j)[2] = (add1.at<Vec3b>(i, j)[2] + add2.at<Vec3b>(i, j)[2]) / 2;
		}
	}
	imshow("final", add1);
	return;
}

int main()
{

	addUp();
	waitKey(20170425);
	return 0;
}

