#include <QApplication>
#include <QtWidgets>

#include "sampleBrowser.h"

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);
	
	// Root widget (sample browser)
	Window window;
	window.show();
	
	return app.exec();
}
