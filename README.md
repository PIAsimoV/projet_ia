![alt text](https://raw.githubusercontent.com/flexus404/projet_ia/master/graphics/logo_piasimov.png "PIAsimoV")

# PIAsimoV - Deep-learning through Vision on RaspBerry PI

**PIAsimoV** is a free, open-source project made by a small group of students as part of their course at the french engineering school **INSA Centre-Val-de-Loire**.

This project was intended to show how a RaspBerry PI performs with deep-learning without any GPU. One is warned **not** to expect fluidity and performances, for the PI3 still has **limited** hardware performance.

**PIAsimoV IS CURRENTLY NO LONGER ACTIVE. WE DO NOT GUARENTEE ANY ANSWERS TO ANY QUESTIONS OR REQUESTS**
## Ressources and references

We greatly thanks these projects which ressources and documentation were very useful for our work :

* [BVLC/Caffenet framework for deep-learning](https://github.com/BVLC/caffe)
* [Darknet/YOLO CNN project](https://github.com/pjreddie/darknet)
* [OpenCV - Open source Computer Vision](https://github.com/opencv/opencv)

And of course some publications among others that were useful to understand Deep-learning and CNN
* [Yann LeCun works on Deep-learning](http://www.cs.nyu.edu/~yann/talks/lecun-ranzato-icml2013.pdf)
* [Quick yet intuitive introduction to CNN](http://cs231n.github.io/convolutional-networks/)
* [Introduction to CNN through Caffe](http://www.panderson.me/images/Caffe.pdf)
* [!!!!!!!!W.I.P NEED A NAME!!!!!!!!!!!!!!](http://www.cs.unc.edu/~wliu/papers/GoogLeNet.pdf)



## Installation guide

#### Hardware requirements
One can find here the hardware used for this project :
* RaspBerry PI 3 model B
* Kuman Screen 3.5" for RaspBerry PI 
* USB or WI-FI camera


#### Software requirements
Although one does not need a GUI, it is recommended to install the latest version of RaspBian with the GUI extension to output the prediction on screen.
* [OpenCV 3.1 or higher - Official guide](http://docs.opencv.org/master/df/d65/tutorial_table_of_content_introduction.html)

The following projects are not required but they are interesting to use in order to produce benchmarkings and comparisons. One should note that they both support / are supported by OpenCV
* [Optional] [Caffenet framework - Official guide](http://caffe.berkeleyvision.org/installation.html)
* [Optional] [Darknet/YOLO - Official guide](https://pjreddie.com/darknet/install/)

#### Downloading CNN  caffemodels
In order to use a pre-trained CNN through OpenCV, one needs to download the dataset provided by **Caffenet**. Note that each caffemodel needs from 300 MB up to **520 MB** of free space.

Use the following commands in the root directory `projet_ia/` :
```bash
wget http://dl.caffe.berkeleyvision.org/bvlc_alexnet.caffemodel -P models/bvlc_alexnet/

wget http://dl.caffe.berkeleyvision.org/bvlc_googlenet.caffemodel -P models/bvlc_googlenet/

wget http://dl.caffe.berkeleyvision.org/bvlc_reference_caffenet.caffemodel -P models/bvlc_caffenet/
```

For further informations about the models, please refer to the [Caffenet repository](https://github.com/BVLC/caffe/tree/master/models).

PIAsimov's repository comes with the pre-existing **synset_words.txt** and **prototxt** in the `models/` folder. 

All **prototxt** files were modified to adopt the **former** input_parameter layer style for OpenCV 3.1 still uses it.

## Instruction guide

The code is already written and can be found in the `src/cam` folder. You must however change one line in each code.

At line 20, replace `PLEASE_FILL_ME` by your camera's address (IP or URL)
```
#define CAMERA_TO_USE PLEASE_FILL_ME
```



A simple Makefile was written to compile and execute the code. Here is a list of the usable options :
* `alexnet` : compile the code as **alexnet** at root project and indicates that it should use the **alexnet** CNN ;
* `usb` : compile the code as **usb_alexnet** at root project and indicates that it should use the **alexnet** CNN ;
* `googlenet` : compile the code as **googlenet** at root project and indicates that it should use the **googlenet** CNN ;
* `caffenet` : compile the code as **caffenet** at root project and indicates that it should use the **caffenet** CNN ;
* `minim` : compile the code as **minimale** at root project. This binary is only here to test whether the USB cam is working or not ;
* `clean` : remove all existing binaries in the folder.
 

**A WI-FI camera must be connected in order to ensure the code execute correctly**. If **usb_alexnet** is used, then a simple USB camera can be used.

Finally, just use the wanted binary to execute the code. Warnings during execution are expected but do not worry as long as no errors shows up everything should work fine.
