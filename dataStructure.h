#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H


#include <QString>
#include <QList>

struct SampleData {
	QString name;
	QString chemical;
	QString notes;
};

class SampleDataCollection {
	
	public:
		SampleDataCollection();
		QList<SampleData> list;
};


#endif