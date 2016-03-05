#ifndef SAMPLEEDITOR_H
#define SAMPLEEDITOR_H

#include <QDialog>
#include <QFormLayout>

class QLabel;
class QLineEdit;
class QPlainTextEdit;
class QDialogButtonBox;

class Editor : public QFormLayout{
	Q_OBJECT
	
	public:
		Editor();
		
	private slots:
	
	private:
		QLabel *sampleNameLabel;
		QLineEdit *sampleNameEdit;
		QLabel *sampleChemLabel;
		QLineEdit *sampleChemEdit;
		QLabel *sampleNoteLabel;
		QPlainTextEdit *sampleNoteEdit;

};

class Dialog : public QDialog{
	Q_OBJECT
	
	public:
		Dialog(QWidget *parent = 0);
		
	private slots:
		
	private:
		Editor *editPaneLayout;
		QDialogButtonBox *buttonBox;
		QVBoxLayout *mainLayout;
		
	
};

#endif