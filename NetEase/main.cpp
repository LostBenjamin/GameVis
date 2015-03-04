#include "NetEase.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	NetEase w;
	w.show();
	return a.exec();
}
