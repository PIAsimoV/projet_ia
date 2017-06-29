#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
using namespace cv;

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdio.h>
using namespace std;

/*
*  This simple function is an interface to quickly use OpenCV function putText
*/
void texte(Mat& image, const String& txt, int x, int y)
{
    putText(image, txt, Point(x,y), FONT_HERSHEY_SIMPLEX, 0.65, Scalar(0, 0, 255), 1,25);
}

int main()
{
    Mat      matImg;    // Matricial image
    IplImage *image;    // A single frame
    CvCapture *capture; // The flow opened from OpenCV
    char key;           // A keyboard input

    capture = cvCreateCameraCapture(CV_CAP_ANY); //Open video flow from USB

    if (!capture)
    {
        printf("Ouverture du flux vidéo impossible !\n");
        return 1;
    }

    namedWindow("Label", WINDOW_NORMAL);

    // While the key pressed is not q (for quit)
    while(key != 'q' && key != 'Q') {

        // Get the next frame received
        image = cvQueryFrame(capture);

        // Convert to a usable matrix
        matImg = cvarrToMat(image);
        resize(matImg, matImg, Size(227, 227));

        texte(matImg, "Ligne 1", 0, 15);
        texte(matImg, "Ligne 2", 0, 35);

        imshow("Label", matImg);

        // On attend 10ms
        key = cvWaitKey(10);

    }

    cvDestroyAllWindows();
    cvReleaseCapture(&capture);

    return 0;
}
