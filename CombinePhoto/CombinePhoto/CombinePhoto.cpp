#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
string path = "C:/11/coding/photo/";
Mat encode(Mat p1, Mat p2)
{
    for (int i = 0; i < p2.rows; i++)
    {
        for (int j = 0; j < p2.cols; j++)
        {
            Vec3b c1 = p1.ptr<Vec3b>(i)[j];
            Vec3b c2 = p2.ptr<Vec3b>(i)[j];
            c1[0] = ((c1[0] + c2[0]) % 256);
            c1[1] = ((c1[1] + c2[1]) % 256);
            c1[2] = ((c1[2] + c2[2]) % 256);
            p1.ptr<Vec3b>(i)[j] = c1;
        }
    }
    return p1;
}
Mat decode(Mat p1, Mat p2)
{
    for (int i = 0; i < p1.rows; i++)
    {
        for (int j = 0; j < p1.cols; j++)
        {
            Vec3b c1 = p1.ptr<Vec3b>(i)[j];
            Vec3b c2 = p2.ptr<Vec3b>(i)[j];
            for (int i = 0; i < 3; i++)
            {
                int temp = c1[i] - c2[i];
                if (temp >= 0)
                {
                    c1[i] = temp;
                }
                else
                {
                    c1[i] = 255 + temp + 1;
                }
            }

            p1.ptr<Vec3b>(i)[j] = c1;
        }
    }
    return p1;
}
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
int main()
{
    string v1, v2;
    char a;
    cin >> a;
    if (a == 'e')
    {
        cout << "Enter the path of key:";
        cin >> v1;
        cout << "Enter the path of ciphertext：";
        cin >> v2;
        Mat p1 = imread(v1);
        Mat p2 = imread(v2);
        p1 = encode(p1, p2);
        imwrite(path + "output.png", p1);
    }
    else
    {
        cout << "Enter the path of code:";
        cin >> v1;
        cout << "Enter the path of key：";
        cin >> v2;
        Mat p1 = imread(v1);
        Mat p2 = imread(v2);
        p1 = decode(p1, p2);
        imwrite(path + "result.png", p1);
    }

   
    return 0;
}
