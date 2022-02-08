#include <opencv2/imgcodecs.hpp> 
#include <opencv2/highgui.hpp> 
#include <opencv2/imgproc.hpp> 
#include <opencv2/objdetect.hpp>
#include <iostream> 

using namespace std;
using namespace cv;

void main() {

	VideoCapture cap(0);
	Mat img;

	CascadeClassifier licensePlate;
	licensePlate.load("Resources/haarcascade_russian_plate_number.xml");

	vector<Rect> plates;

	if (licensePlate.empty())cout << "Xml file not loaded" << endl;

	while (true) {
		cap.read(img);
		 
		licensePlate.detectMultiScale(img, plates, 1.1, 10);

		for (int i = 0; i < plates.size(); i++)
		{
			putText(img, "License Plate", plates[i].tl(), FONT_HERSHEY_PLAIN, 1, Scalar(256, 100, 0), 2);
			rectangle(img, plates[i].tl(), plates[i].br(), Scalar(255, 0, 255), 2);
		}

		imshow("Image", img);
		waitKey(1);
	}
}
