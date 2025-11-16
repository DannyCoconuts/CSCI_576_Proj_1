#include <iostream>
#include <filesystem>
#include <opencv2/opencv.hpp>


#include "ImageIO/ImageLoader.h"
#include "Pieces/PieceExtractor.h"

int main() {
    //Note just hardcode the paths for now, I was having trouble with my paths because onedrive likes to virtualize some of my stuff and its messing with it
    std::string pathPNG = "";
    std::string pathRGB = "";
    std::cout << "Detectasded ";
    // Load PNG
    cv::Mat img = ImageLoader::loadPNG(pathPNG);
    if (img.empty()) return -1;

    int width  = img.cols;
    int height = img.rows;
    std::cout << "Detecta123123sded ";
    // Load raw RGB
    unsigned char* buffer = ImageLoader::loadRawRGB(pathRGB, width, height);
    if (!buffer) return -1;

    cv::Mat rgbImage(height, width, CV_8UC3, buffer);

    // Extract pieces
    std::vector<cv::Mat> pieces = PieceExtractor::extractPieces(rgbImage);

    // Draw contour overlay
    cv::Mat contourImg = PieceExtractor::drawContoursOnImage(rgbImage);

    std::cout << "Detected " << pieces.size() << " pieces." << std::endl;
    cv::imshow("Contours", contourImg);

    std::cout << "Press any key..." << std::endl;
    cv::waitKey(0);

    free(buffer);
    return 0;
}
