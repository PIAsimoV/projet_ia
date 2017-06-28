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

void texte(Mat& image, const String& txt, int x, int y)
{
    putText(image, txt, Point(x,y), FONT_HERSHEY_SIMPLEX, 0.65, Scalar(0, 0, 255), 1,25);
}

int main()
{
    Mat      matImg;
    IplImage *image;    //Une frame
    CvCapture *capture; //La capture
    char key;           //Un input keyboard

    // Initialisation de la capture via la camera
    //capture = cvCreateFileCapture("http://169.254.203.145/mjpg/video.mjpg?resolution=640x480&req_fps=10&.mjpg");
    capture = cvCreateCameraCapture(CV_CAP_ANY); //Ouvre le flux vidéo
    //Si ça ne mache pas remplacer CV CAP ANY par 0

    if (!capture) //Test l'ouverture du flux vidéo
    {
        printf("Ouverture du flux vidéo impossible !\n");
        return 1;
    }

    //Récupérer une image et l'afficher
    namedWindow("Label", WINDOW_NORMAL); //Créé une fenêtre

    //Affiche les images une par une
    while(key != 'q' && key != 'Q') {

        // On récupère une image
        image = cvQueryFrame(capture);

        // Conversion matricielle
        matImg = cvarrToMat(image);
        resize(matImg, matImg, Size(227, 227));

        texte(matImg, "Ligne 1", 0, 15);
        texte(matImg, "Ligne 2", 0, 35);

        // Affichage de la matrice
        imshow("Label", matImg);
        // On attend 10ms
        key = cvWaitKey(10);


    }

    //Ou CvDestroyWindow("Window") si on veut garder d'autres fenêtres
    cvDestroyAllWindows();
    cvReleaseCapture(&capture);

    return 0;
}
