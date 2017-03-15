#include<opencv2\opencv.hpp>

#include <algorithm>
using namespace cv;
int main()
{
	Mat picture = imread("airport.jpg");//图片必须添加到工程目录下
										  //也就是和test.cpp文件放在一个文件夹下！！！
	imshow("测试程序", picture);
	Mat src = imread("partial.jpg");
	imshow("before", src);
	int i, j;
	int cPointR, cPointG, cPointB, cPoint;//currentPoint;  
	for (i = 1; i < src.rows; i++)
	{
		for (j = 1; j < src.cols; j++)
		{
			cPointB = src.at<Vec3b>(i, j)[0];
			cPointG = src.at<Vec3b>(i, j)[1];
			cPointR = src.at<Vec3b>(i, j)[2];
			if (cPointB >= 245 & cPointR >= 245 & cPointG >= 245)
			{
				src.at<Vec3b>(i, j)[0] = 255;
				src.at<Vec3b>(i, j)[1] = 255;
				src.at<Vec3b>(i, j)[2] = 255;
			}
			else
			{
				src.at<Vec3b>(i, j)[0] = 0;
				src.at<Vec3b>(i, j)[1] = 0;
				src.at<Vec3b>(i, j)[2] = 0;
			}
		}
	}
	imshow("all white", src);
	

	src = imread("partial.jpg");
	for (i = 1; i < src.rows; i++)
	{
		for (j = 1; j < src.cols; j++)
		{
			cPointB = src.at<Vec3b>(i, j)[0];
			cPointG = src.at<Vec3b>(i, j)[1];
			cPointR = src.at<Vec3b>(i, j)[2];
			if (cPointB <= 11)// & cPointR <= 11 & cPointG <= 11)
			{
				src.at<Vec3b>(i, j)[0] = 255;
				src.at<Vec3b>(i, j)[1] = 255;
				src.at<Vec3b>(i, j)[2] = 255;
			}
			else
			{
				src.at<Vec3b>(i, j)[0] = 0;
				src.at<Vec3b>(i, j)[1] = 0;
				src.at<Vec3b>(i, j)[2] = 0;
			}
		}
	}
	imshow("keep black", src);

	src = imread("aaaaa.jpg");
	imshow("color", src);
	int average = 0;
	for (i = 1; i < src.rows; i++)
	{
		for (j = 1; j < src.cols; j++)
		{
			cPointB = src.at<Vec3b>(i, j)[0];
			cPointG = src.at<Vec3b>(i, j)[1];
			cPointR = src.at<Vec3b>(i, j)[2];

			average = (cPointB + cPointG + cPointR) / 3;

			src.at<Vec3b>(i, j)[0] = average;
			src.at<Vec3b>(i, j)[1] = average;
			src.at<Vec3b>(i, j)[2] = average;
		}
	}
	imshow("bandw", src);

	waitKey(20170115);
}
