#pragma once

#include "pbPlots.h"
#include "supportLib.h"
#include <vector>
#include <string>

using namespace std;

class GraphicalReport {
public:
    void generateGraph(double cognitiveRisk, double lifestyleRisk, double geneticRisk, double totalRisk, const std::string& filename) {
        RGBABitmapImageReference* imageRef = CreateRGBABitmapImageReference();

        // Data for the X-axis (categories)
        vector<double> x{ 1, 2, 3, 4 };
        // Data for the Y-axis (risk scores)
        vector<double> y{ cognitiveRisk, lifestyleRisk, geneticRisk, totalRisk };

        // Customize the graph (size: 600x400 pixels)
        DrawScatterPlot(imageRef, 600, 400, &x, &y);

        // Save the graph as a PNG file
        vector<double>* pngData = ConvertToPNG(imageRef->image);
        WriteToFile(pngData, filename);
        DeleteImage(imageRef->image);
    }
};