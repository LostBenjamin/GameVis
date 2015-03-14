#include "InfoList.h"


InfoList::InfoList()
{
	createSelection();

	QVBoxLayout* mainLayout = new QVBoxLayout;
	mainLayout->addWidget(selectionGroup);

	setLayout(mainLayout);
}

InfoList::~InfoList()
{
}

void InfoList::createSelection()
{
	selectionGroup = new QGroupBox(tr("Selection"));
	QHBoxLayout* layout = new QHBoxLayout;
	selectionLabel = new QLabel(tr("selection:"));
	selectionBox = new QComboBox();
	selectionBox->addItem("Cluster");
	selectionBox->addItem("People");

	layout->addWidget(selectionLabel);
	layout->addWidget(selectionBox);
	
	setLayout(layout);
}

void InfoList::createFilter()
{

}