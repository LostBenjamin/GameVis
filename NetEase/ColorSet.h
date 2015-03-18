#pragma once

#include <QtWidgets/QWidget>
#include <QColor>
#include "QDebug"


class ColorSet
{
public:
	ColorSet();
	~ColorSet();

	bool initColorSetFromFile(QString filePath);
	QVector<QColor> getColorSet(int num);
private:
	QVector<QColor> colorSet;

};

