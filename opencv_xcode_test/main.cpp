//
//  main.cpp
//  opencv_xcode_test
//
//  Created by Park Billy on 26/08/2019.
//  Copyright © 2019 Park Billy. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, const char * argv[]) {
    
    std::cout << "OpenCV Version : " << CV_VERSION << std::endl;

    Mat img;
    VideoCapture webcam(0);
    VideoWriter writer;
    Size size = Size((int)webcam.get(CAP_PROP_FRAME_WIDTH), (int)webcam.get(CAP_PROP_FRAME_HEIGHT));
    double fps = 30;
    
    writer.open("output.avi", VideoWriter::fourcc('M', 'J', 'P', 'G'), fps, size, true);
    if (!writer.isOpened()) {
        std::cout << "Writer Open Error...!!\n";
        return -1;
    }
    
    if (!webcam.isOpened()) {
        std::cout << "Camera Open Error...!!!\n";
        return -1;
    }
    
    while(1) {
        webcam.read(img);
        if (img.empty()) {
            std::cout << "Video Load Error!!\n";
            break;
        }
        
        writer.write(img);
        imshow("Webcam", img);
        if (waitKey(1) == 27    ) {
            break;
        }
    }
    
    
    return 0;
}
