#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>   
#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;
string path = "C:/11/coding/photo/";
Mat randImage(Size s)
{

	Mat h(s, 16);
	for (int i = 0; i < h.rows; i++)
	{
		for (int j = 0; j < h.cols; j++)
		{
			Vec3b c;
			for (int k = 0; k < 3; k++)
			{
				c[k] = rand() % 256;
			}

			h.ptr<Vec3b>(i)[j] = c;
		}
		
	}
	return h;
}
Mat encode(Mat p1, Mat p2)
{
	for (int i = 0; i < p2.rows; i++)
	{
		for (int j = 0; j < p2.cols; j++)
		{
			Vec3b c1 = p1.ptr<Vec3b>(i)[j];
			Vec3b c2 = p2.ptr<Vec3b>(i)[j];
			Vec3b nV(1, 1, 1);
			nV[0] = ((c1[0] + c2[0]) % 256);
			nV[1] = ((c1[1] + c2[1]) % 256);
			nV[2] = ((c1[2] + c2[2]) % 256);
			p2.ptr<Vec3b>(i)[j] = nV;
		}
	}
	return p2;
}
Mat decode(Mat p1, Mat p2)
{
	for (int i = 0; i < p1.rows; i++)
	{
		for (int j = 0; j < p1.cols; j++)
		{
			Vec3b c1 = p1.ptr<Vec3b>(i)[j];
			Vec3b c2 = p2.ptr<Vec3b>(i)[j];
			Vec3b nV(1, 1, 1);
			for (int i = 0; i < 3; i++)
			{
				int temp = c1[i] - c2[i];
				if (temp >= 0)
				{
					nV[i] = temp;
				}
				else
				{
					nV[i] = 255 + temp + 1;
				}
			}

			p1.ptr<Vec3b>(i)[j] = nV;
		}
	}
	return p1;
}
Mat mList[60];
int main()
{
	srand(time(0));
	char t;
	string s1, s2;
	cin >> t;
	
	if (t == 'e')
	{
		cout << "enter path or the target: ";
		cin >> s1;
		VideoCapture v;
		v.open(s1);

		Size size(v.get(CAP_PROP_FRAME_WIDTH), v.get(CAP_PROP_FRAME_HEIGHT));
		int fps = v.get(CAP_PROP_FPS);
		long totalFrames = v.get(CAP_PROP_FRAME_COUNT);
		VideoWriter key(path + "key.avi", cv::VideoWriter::fourcc('I', '4', '2', '0'), fps, size);
		VideoWriter r(path + "rand.avi", cv::VideoWriter::fourcc('I', '4', '2', '0'), fps, size);
		Mat bmp = imread(path + "white.png");
		for (int i = 0; i < fps; i++)
		{
			mList[i] = randImage(size);
			key.write(mList[i]);
		}
		for (long i = 0; i < totalFrames; i++)
		{
			Mat temp;
			if (v.read(temp))
				r.write(encode(temp, bmp));
		}
	}
	else if (t == 'd')
	{
		cout << "enter path or the code: ";
		cin >> s1;
		cout << "enter path or the key: ";
		cin >> s2;
		VideoCapture v1;
		VideoCapture v2;
		
		v1.open(s1);
		//v2.open(s2);
		vector<Mat> array;

		/*while (true)
		{
			Mat t;

			if (v2.read(t))
			{
				array.push_back(t);
			}
			else
			{
				break;
			}
		}*/
		int v1fps = v1.get(CAP_PROP_FPS);
		long totalFrames = v1.get(CAP_PROP_FRAME_COUNT);
		//long v2totalFrames = v2.get(CAP_PROP_FRAME_COUNT);
		Size size(v1.get(CAP_PROP_FRAME_WIDTH), v1.get(CAP_PROP_FRAME_HEIGHT));
		VideoWriter r(path + "result.avi", cv::VideoWriter::fourcc('I', '4', '2', '0'), v1fps, size);
		Mat bmp = imread(path + "white.png");
		for (int i = 0; i < totalFrames; i++)
		{
			Mat t;
			if (v1.read(t))
				r.write(decode(t, bmp));
		}
		
	}
	
	return 0;
}
