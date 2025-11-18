#include "FeatureExtractor.h"
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

namespace FeatureExtractor {

static EdgeFeature sampleEdgeFromMat(const Mat& Y, int edge, int nSamples) {
    EdgeFeature ef;
    int h = Y.rows;
    int w = Y.cols;
    ef.vals.resize(nSamples);

    for (int i = 0; i < nSamples; i++) {
        float t = float(i) / (nSamples - 1);
        int x, y;

        switch (edge) {
            case 0: x = t * (w - 1); y = 0; break;
            case 1: x = w - 1;      y = t * (h - 1); break;
            case 2: x = t * (w - 1); y = h - 1; break;
            default: x = 0; y = t * (h - 1); break;
        }

        ef.vals[i] = Y.at<uchar>(y, x);
    }
    return ef;
}

PieceFeature extract(const Mat& piece) {
    PieceFeature pf;
    pf.img = piece.clone();

    Mat yuv;
    cvtColor(piece, yuv, COLOR_BGR2YUV);
    vector<Mat> c;
    split(yuv, c);
    Mat Y = c[0];

    int N = 40;

    pf.top    = sampleEdgeFromMat(Y, 0, N);
    pf.right  = sampleEdgeFromMat(Y, 1, N);
    pf.bottom = sampleEdgeFromMat(Y, 2, N);
    pf.left   = sampleEdgeFromMat(Y, 3, N);

    return pf;
}

}
