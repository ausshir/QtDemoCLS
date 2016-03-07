#ifndef SAMPLEBROWSER_H
#define SAMPLEBROWSER_H

#include <QWidget>
#include "sampleEditor.h"
#include "dataStructure.h"

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
		~Window();

	private slots:
		void newSample(void);
		void editSample(void);
		void showUpdate(void);

	private:
		QHBoxLayout *mainLayout;
		Editor *editPaneLayout;
		QVBoxLayout *selectPaneLayout;
		QListWidget *sampleSelectList;
		QPushButton *sampleCreateButton;
		
		SampleDataCollection *collection;
	
		Dialog *dialog;
		
		void updateSelectionPane(void);

};

#endif
