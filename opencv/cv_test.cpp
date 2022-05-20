#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>

using namespace cv;

int main()(int ac, char** av) {
    std::string image_path = samples::findFile("starry_nigth.jpg");
    Mat img = imread(image_path, IMREAD_COLOR);

    if(img.empty()) {
        std::cout << "Could not read the image: " << image_path << std::endl;
        return 1;
    }

    imshow("Display window", img);
    int k = waitkey(0);

    if(k == 's') {
        imwrite("starry_nigth.png", img);
    }

    return 0;
}
