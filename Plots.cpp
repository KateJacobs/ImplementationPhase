#include "pbPlots.h"
#include "supportLib.h"

int main()
{
	RGBABitmapImageReference* imageRef = CreateRGBABitmapImageReference();

	//X and Y coordinates
	vector<double> x{-2, -1, 0, 1, 2};
	vector<double> y{2, -1, -2, -1, 2};

	//600 = width, 400 = height
	DrawScatterPlot(imageRef, 600, 400, &x, &y);

	vector<double> *pngData = ConvertToPNG(imageRef->image);
	WriteToFile(pngData, "plot.png");
	DeleteImage(imageRef->image);

	return 0;
}