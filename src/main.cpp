#include "loadimage.hpp"
#include <iostream>

int main()
{
    cv::Mat img = loadImage("images/image1.png");
    cv::imshow("Display Image", img);
    cv::waitKey(0);

    img = loadImage("images/image2.png");
    cv::imshow("Display Image", img);
    cv::waitKey(0);

    return 0;
}