#ifndef SAMPLEBROWSER_H
#define SAMPLEBROWSER_H

#include <QWidget>
#include "sampleEditor.h"

class QHBoxLayout;
class QVBoxLayout;
class QFormLayout;

class QLineEdit;
class QPlainTextEdit;
class QLabel;
class QListWidget;
class QPushButton;

class Window : public QWidget
{
    Q_OBJECT

	public:
		Window();

	private slots:
		// No slots yet

	private:
		QHBoxLayout *mainLayout;
		Editor *editPaneLayout;
		QVBoxLayout *selectPaneLayout;
		QListWidget *sampleSelectList;
		QPushButton *sampleCreateButton;
		
		Dialog *dialog;

};

#endif
