//
// Created by 奶学霸 on 2019-06-17.
//

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;


int main(){
    Point top_left = Point(20, 20);
    Point bottom_right = Point(200, 200);
    Mat srcImage = imread("/Users/wenjun/Codes/ecarx/DBSCAN/faro.jpg");

    rectangle(srcImage, top_left, bottom_right, Scalar(255, 255, 255), 5, 8);

    imshow("draw bounding box", srcImage);

    waitKey(0);
}

