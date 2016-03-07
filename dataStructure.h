#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H


#include <QString>
#include <QList>


// VERY basic data structure to store the information about a sample
// 	The samples are stored in a QList to allow easy manipulation by the widgets
// 	There is a lot of ways to make this more robust, such as using QModels,
//    but for a program of this size I decided that simpler was probably better.
struct SampleData {
	QString name;
	QString chemical;
	QString notes;
};

class SampleDataCollection {
	
	public:
		SampleDataCollection();
		QList<SampleData> list;
		~SampleDataCollection();
};


#endif