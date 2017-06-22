#include <stdio.h>
#include "highgui.h"
#include "cv.h"


int main()
{
    IplImage *image; //Une frame
    CvCapture *capture; //La capture
    char key; //Un input keyboard
    capture = cvCreateFileCapture("chemindudossier/nomvideo.avi");

    capture = cvCreateCameraCapture(CV CAP ANY); //Ouvre le flux vidéo
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
 
        // On attend 10ms
        key = cvWaitKey(10);
 
    }

    //Ou CvDestroyWindow("Window") si on veut garder d'autres fenêtres
    CvDestroyAllWindows();
    cvReleaseCapture($capture);

    return 0;
}
