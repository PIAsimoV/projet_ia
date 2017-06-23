#include <stdio.h>
#include "opencv2/opencv.hpp"
#include "opencv2/videoio.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;

int main()
{
    IplImage *image; //Une frame
    CvCapture *capture; //La capture
    char key; //Un input keyboard

    capture = cvCreateFileCapture("http://169.254.203.145/mjpg/video.mjpg?resolution=640x480&req_fps=10&.mjpg");



//capture = cvCreateCameraCapture(CV_CAP_ANY); //Ouvre le flux vidéo
    //Si ça ne mache pas remplacer CV CAP ANY par 0

    if (!capture) //Test l'ouverture du flux vidéo
    {
        printf("Ouverture du flux vidéo impossible !\n");
        return 1;
    }

    //Récupérer une image et l'afficher
    cvNamedWindow("Window", CV_WINDOW_AUTOSIZE); //Créé une fenêtre

    //Affiche les images une par une
    while(key != 'q' && key != 'Q') {

        // On récupère une image
        image = cvQueryFrame(capture);

        // On affiche l'image dans une fenêtre
        cvShowImage("Window", image);

	//On sauvegarde l'image
        //cvSaveImage("test.jpeg", image);
        
       Mat m = cvarrToMat(image);

        // On attend 10ms
        key = cvWaitKey(10);

    }

    //Ou CvDestroyWindow("Window") si on veut garder d'autres fenêtres
    cvDestroyAllWindows();
    cvReleaseCapture(&capture);

    return 0;
}
