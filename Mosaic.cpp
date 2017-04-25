#include<opencv2\opencv.hpp>
#include <algorithm>
using namespace cv;

void Mosaic(int n)
{
	Mat src1 = imread("origin.jpg");

	imshow("before", src1);

	int i, j;
	for (i = 1; i <= src1.rows/n-1; i++)
	{
		for (j = 1; j <= src1.cols/n-1; j++)
		{
			int sum1=0, sum2=0, sum3=0;
			for(int x=i*n;x<i*n+n;x++)
			{
				for (int y = j*n; y < j*n + n; y++)
				{
					sum1 += src1.at<Vec3b>(x, y)[0];
					sum2 += src1.at<Vec3b>(x, y)[1];
					sum3 += src1.at<Vec3b>(x, y)[2];
				}
			}
			sum1 = sum1 / n / n;
			sum2 = sum2 / n / n;
			sum3 = sum3 / n / n;
			for (int x = i*n-n; x<i*n; x++)
			{
				for (int y = j*n-n; y < j*n; y++)
				{
					src1.at<Vec3b>(x, y)[0] = sum1;
					src1.at<Vec3b>(x, y)[1] = sum2;
					src1.at<Vec3b>(x, y)[2] = sum3;
				}
			}
		}
	}
	
	imshow("after ", src1);

	return;
}

int main()
{
	int n = 10;
	Mosaic(n);
	waitKey(20170425);
	return 0;
}

