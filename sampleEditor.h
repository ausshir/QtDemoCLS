#ifndef SAMPLEEDITOR_H
#define SAMPLEEDITOR_H

#include <QDialog>
#include <QFormLayout>
#include "dataStructure.h"

class QLabel;
class QLineEdit;
class QPlainTextEdit;
class QDialogButtonBox;


// Editor widget used in main window and dialog
// See .cpp file for comments
class Editor : public QFormLayout{
	Q_OBJECT
	
	public:
		Editor(SampleData *sample, QWidget * parent = 0);
		void connectSample(SampleData *sample);
		~Editor();
	
	signals:
		editorUpdated();
		
	private slots:
		void updateName(void);
		void updateChem(void);
		void updateNote(void);
	
	private:
		QLabel *sampleNameLabel;
		QLabel *sampleChemLabel;
		QLabel *sampleNoteLabel;
		QLineEdit *sampleNameEdit;
		QLineEdit *sampleChemEdit;
		QPlainTextEdit *sampleNoteEdit;
		SampleData *activeSample;	
};


///////////////////////////////////////////////////////////////////////////////


// Dialog brought up by the main window to create new samples
// See .cpp file for comments
class Dialog : public QDialog{
	Q_OBJECT
	
	public:
		Dialog(SampleData *sample, QWidget * parent = 0);
		~Dialog();
		
	public slots:
		
	private:
		Editor *editPaneLayout;
		QDialogButtonBox *buttonBox;
		QVBoxLayout *mainLayout;
};

#endif