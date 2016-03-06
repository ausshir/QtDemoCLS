#ifndef SAMPLEEDITOR_H
#define SAMPLEEDITOR_H

#include <QDialog>
#include <QFormLayout>
#include "dataStructure.h"

class QLabel;
class QLineEdit;
class QPlainTextEdit;
class QDialogButtonBox;

class Editor : public QFormLayout{
	Q_OBJECT
	
	public:
		Editor();
		SampleData *sample;
		QLineEdit *sampleNameEdit;
		QLineEdit *sampleChemEdit;
		QPlainTextEdit *sampleNoteEdit;
	
	public slots:
		void refresh(void);	
		
	private slots:
		void updateName(void);
		void updateChem(void);
		void updateNote(void);
	
	private:
		QLabel *sampleNameLabel;
		QLabel *sampleChemLabel;
		QLabel *sampleNoteLabel;
		
};

class Dialog : public QDialog{
	Q_OBJECT
	
	public:
		Dialog(QWidget *parent = 0);
		
	public slots:
		SampleData* getData(void);
		
	private:
		Editor *editPaneLayout;
		QDialogButtonBox *buttonBox;
		QVBoxLayout *mainLayout;
		
	
};

#endif