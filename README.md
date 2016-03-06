<h2>Demo Qt App for CLS Job Application</h2>


Progess: Everything is there. But the memory leaks and performance issues are pretty serious... I admit I haven't used C++ on the desktop in a while! ;)

To Do: Fix all memory leaks, find a better way to transfer data around and clean up the public/private classes to be more sane.



To build, install Qt5 and make sure all paths are correct.
Then do:

    qmake
    mingw32-make

*Note this has only been tested on Windows 10*
