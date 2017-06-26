/* [Thanh] La partie concernant OpenCV-CNN est inspire du site officiel
    Credits: http://docs.opencv.org/trunk/d5/de7/tutorial_dnn_googlenet.html
*/

#include "opencv2/opencv.hpp"
#include "opencv2/videoio.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/dnn.hpp>
#include <opencv2/imgproc.hpp>
//using namespace cv;
//using namespace cv::dnn;

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdio.h>
//using namespace std;


/* [T] : Voir Credits pour la source
Find best class for the blob (i. e. class with maximal probability) */
void getMaxClass(const cv::Mat &probBlob, int *classId, double *classProb)
{
    cv::Mat probMat = probBlob.reshape(1, 1); //reshape the blob to 1x1000 matrix
    cv::Point classNumber;
    cv::minMaxLoc(probMat, NULL, classProb, NULL, &classNumber);
    *classId = classNumber.x;
}

/* [T] : Voir Credits pour la source */
std::vector<String> readClassNames(const char *filename)
{
    std::vector<String> classNames;
    std::ifstream fp(filename);
    if (!fp.is_open())
    {
        std::cerr << "File with classes labels not found: " << filename << std::endl;
        exit(-1);
    }
    std::string name;
    while (!fp.eof())
    {
        std::getline(fp, name);
        if (name.length())
            classNames.push_back( name.substr(name.find(' ')+1) );
    }
    fp.close();
    return classNames;
}


int main()
{
    cv::IplImage *image;    //Une frame
    cv::CvCapture *capture; //La capture
    char key;           //Un input keyboard
    int classId;        //ID classe pour le CNN
    double classProb;   //Probabilite de la prediction

    /* Initialisation du CNN AlexNet */

    // [T] : Je ne sais pas comment on a installe la lib, donc je laisse ca ici
    //cv::dnn::initModule();  //Required if OpenCV is built as static libs

    // [T] : La doc n'explique pas si c'est un chemin ou une reference a la lib
    // [T] : Donc ici je mets la version PATH...
    cv::String modelTxt = "../models/bvlc_alexnet/bvlc_alexnet.prototxt";
    cv::String modelBin = "../models/bvlc_alexnet/bvlc_alexnet.caffemodel";

    // [T] : ... et la, la version 'librairie'
    //std::string modelTxt = "bvlc_alexnet.prototxt";
    //std::string modelBin = "bvlc_alexnet.caffemodel";

    // [T] : Creation du 'net' du CNN depuis les fichiers CAFFE
    cv::dnn:Net net = cv::dnn::readNetFromCaffe(modelTxt, modelBin);

    // [T] : Provient de la doc, voici
    if (net.empty())
    {
        std::cerr << "Impossible de charger le CNN deuis les fichiers suivants : " << std::endl;
        std::cerr << "prototxt:   " << modelTxt << std::endl;
        std::cerr << "caffemodel: " << modelBin << std::endl;
        exit(-1);
    }

    // Initialisation de la capture via la camera
    capture = cv::cvCreateFileCapture("http://169.254.203.145/mjpg/video.mjpg?resolution=640x480&req_fps=10&.mjpg");
    //capture = cvCreateCameraCapture(CV_CAP_ANY); //Ouvre le flux vidéo
    //Si ça ne mache pas remplacer CV CAP ANY par 0

    if (!capture) //Test l'ouverture du flux vidéo
    {
        printf("Ouverture du flux vidéo impossible !\n");
        return 1;
    }

    //Récupérer une image et l'afficher
    cv::cvNamedWindow("Window", CV_WINDOW_AUTOSIZE); //Créé une fenêtre

    //Affiche les images une par une
    while(key != 'q' && key != 'Q') {

        // On récupère une image
        image = cv::cvQueryFrame(capture);

        // On affiche l'image dans une fenêtre
        cv::cvShowImage("Window", image);

	    //On sauvegarde l'image
        //cvSaveImage("test.jpeg", image);
        
        // Passage sous forme matricielle
        cv::Mat matImg = cv::cvarrToMat(image);

        /* Traitement dans le CNN */
        /* AlexNet et GoogleNet ne prennent que des RGB 224x224 */
        cv::Mat inputBlob = cv::dnn::blobFromImage(img, 1, Size(224, 224),
                                       Scalar(104, 117, 123)); //Convert cv::Mat to batch of imagesnet.setInput(inputBlob, "data");         // On definit le label 'data' pour le CNN
        cv::Mat prob = net.forward("prob");                        // Prediction

        // [T] : Alors la, je ne suis pas sur que ca marche avec AlexNet.
        getMaxClass(prob, &classId, &classProb); // Recherche de la plus forte probabilite
        std::vector<String> classNames = readClassNames("../models/bvlc_alexnet/synset_words.txt");

        // [T] : Pour l'instant, on affiche sur la sortie standard
        std::cout << "-------------------" << std::endl;
        std::cout << "Classe proposee : #" << classId << " '" << classNames.at(classId) << "'" << std::endl;
        std::cout << "Probabilite    : " << classProb * 100 << "%" << std::endl;

        // On attend 10ms
        key = cv::cvWaitKey(10);
    }

    //Ou CvDestroyWindow("Window") si on veut garder d'autres fenêtres
    cv::cvDestroyAllWindows();
    cv::cvReleaseCapture(&capture);

    return 0;
}
