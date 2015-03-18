#include "ColorSet.h"
#include <QFile>

ColorSet::ColorSet()
{
}


ColorSet::~ColorSet()
{
}


bool ColorSet::initColorSetFromFile(QString filename){
	QFile f(filename);
	if (!f.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		qDebug() << "Open ColorSetFile failed." << endl;
		return false;
	}

	QTextStream txtInput(&f);
	QString lineStr;
	while (!txtInput.atEnd())
	{

		txtInput >> lineStr ;
		bool ok = false;
		QColor newColor;
		newColor.setNamedColor(lineStr);
		//= QColor(lineStr.mid(0, 2).trimmed().toInt(&ok, 16), lineStr.mid(2, 2).trimmed().toInt(&ok, 16), lineStr.mid(4, 2).trimmed().toInt(&ok, 16), 255);
		colorSet.push_back(newColor);
		qDebug() << lineStr << lineStr.mid(0, 2).trimmed().toInt(&ok, 16)<<lineStr.mid(2, 2).trimmed().toInt(&ok, 16)<<lineStr.mid(4, 2).trimmed().toInt(&ok, 16) << endl;
	}

	f.close();

}

QVector<QColor> ColorSet::getColorSet(int num){

	return colorSet.mid(0, num);
}