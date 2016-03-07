<h2>Demo Qt App for CLS Job Application</h2>


Progess: Done! I think... :)


To build, install Qt5.5 and make sure all paths are correct.
Then do:

    qmake
    mingw32-make

Or on linux, make sure Qt5 and Qt-tools is installed
Then do:

     qmake
     make
	
And run the program in the release folder. On linux this may be generated in the same folder depending on how you have Qt configured.

Excecutatbles are included under releases but probably do not work outside of my environments.
*Note this has only been tested on Windows 10 and Ubuntu with dynamic libraries and has not yet been tested on OSX or other linux distibutions*
