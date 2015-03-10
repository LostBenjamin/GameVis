#include "NetEase.h"
#include "Model.h"
#include "Controller.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	NetEase netEase;

	ClusterAll clusterAll;
	Player player;
	Model model(&clusterAll, &player);

	netEase.setModel(&model);

	Controller controller(&model, &netEase);

	netEase.show();

	netEase.paintMainView();

	return a.exec();
}
