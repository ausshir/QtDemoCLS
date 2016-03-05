#include <QApplication>
#include <QtWidgets>

#include "sampleBrowser.h"

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);
	
	// Root widget (sample browser)
	Window mainWindow;
	mainWindow.show();
	
	return app.exec();
}
