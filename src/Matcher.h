#pragma once
#include <vector>
#include <opencv2/opencv.hpp>
#include "FeatureExtractor.h"

struct PuzzleLayout {
    std::vector<std::vector<int>> grid;
};

namespace Matcher {
    std::vector<std::pair<int,double>> matchAll(const std::vector<PieceFeature>& features);
    PuzzleLayout buildLayout(int pieceCount);
}
