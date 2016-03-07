#include <QtWidgets>

#include "sampleBrowser.h"
#include "sampleEditor.h"
#include "dataStructure.h"

Window::Window() {	
	
	// Right Editor Pane
	//	 A dummy sample is created at startup, as there are no samples to edit
	//	 This will be replaced once a sample is selected in the list
	SampleData sample;
	editPaneLayout = new Editor(&sample, this);
	
	// Left Selection Pane
	//	 Consists of a list and button for a new sample
	//	 When list item is clicked, the right editor pane updates
	// 	 When button is clicked, an editor dialog opens
	//	 When editor pane is updated, list item updates
	sampleSelectList = new QListWidget();
	sampleCreateButton = new QPushButton("New Sample");
	selectPaneLayout = new QVBoxLayout();
	selectPaneLayout->addWidget(sampleSelectList);
	selectPaneLayout->addWidget(sampleCreateButton);
	connect(sampleCreateButton, SIGNAL(clicked()), this, SLOT(newSample()));
	connect(sampleSelectList, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(editSample()));
	connect(editPaneLayout, SIGNAL(editorUpdated()), this, SLOT(showUpdate()));
	
	// Assemble the main layout
	mainLayout = new QHBoxLayout();
	mainLayout->addLayout(selectPaneLayout);
	mainLayout->addLayout(editPaneLayout);	
	setLayout(mainLayout);
	
	// Create the data collection which stores all the samples
	collection = new SampleDataCollection();
}

Window::~Window() {
	// Remaining widgets should be deleted automatically
	delete collection;	
}


// Show the Dialog and get return state
//	If dialog is canceled, delete the sample that was created for it
//	If accepted, add the sample to the list
//	Also make sure the dialog itself is removed by the parent (window) when closed
// 	Note that the sample is created here and passed to the dialog for editing!
void Window::newSample() {
	SampleData *sample = new SampleData;
	dialog = new Dialog(sample, this);
	dialog->setAttribute(Qt::WA_DeleteOnClose);
	
	if(dialog->exec() == QDialog::Accepted) {
		collection->list.insert(0, *sample);
		updateSelectionPane();
	}
	else delete sample;
}


// Updates the selection pane when an item is created by the dialog
// Simply adds the name to the list. The item is tracked by its index
void Window::updateSelectionPane() {
	sampleSelectList->addItem(collection->list[0].name + " " + collection->list[0].chemical);
}


// Updates the editor pane when a sample is clicked on in the list
// 	Note samples are appended to the start of the collection but the end of the list, so the order must be inverted
void Window::editSample() {
	int index = sampleSelectList->count() - sampleSelectList->currentRow() - 1;
	editPaneLayout->connectSample(&(collection->list[index])); 
}

// Updates list when an item in the editor pane is changed
//	Note, this is done by deleting and readding the list item at the old location
void Window::showUpdate() {
	int row = sampleSelectList->currentRow();
	int index = sampleSelectList->count() - row - 1;
	
	// I feel like there should be a built-in method for this.. couldn't find it in the docs!
	sampleSelectList->takeItem(row);
	sampleSelectList->insertItem(row, collection->list[index].name + " " + collection->list[index].chemical);
	sampleSelectList->setCurrentRow(row);

}

