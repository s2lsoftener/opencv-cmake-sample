#include "loadimage.hpp"

cv::Mat loadImage(std::string imgName)
{
    std::string imageRelPath{imgName};
    std::cout << "Loading image: " << imageRelPath << std::endl;

    cv::Mat img = cv::imread(imageRelPath);

    if (img.empty())
    {
        std::cout << "Could not read the image" << std::endl;
    }

    return img;
}