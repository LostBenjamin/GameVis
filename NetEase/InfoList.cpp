#include "InfoList.h"


InfoList::InfoList()
{
	createSelection();
	createFilter();
	createMainViewControl();

	QVBoxLayout* mainLayout = new QVBoxLayout;
	mainLayout->addWidget(mainViewControlGroup);
	mainLayout->addWidget(selectionGroup);
	mainLayout->addWidget(filterGroup);

	setLayout(mainLayout);
	setFixedWidth(INFOLIST_WIDTH);
}

InfoList::~InfoList()
{
}

void InfoList::createSelection()
{
	selectionGroup = new QGroupBox(tr("Selection"));
	QHBoxLayout* layout = new QHBoxLayout;
	//selectionLabel = new QLabel(tr("selection:"));
	//selectionBox = new QComboBox();
	//selectionBox->addItem("Cluster");
	//selectionBox->addItem("People");

	//layout->addWidget(selectionLabel);
	//layout->addWidget(selectionBox);
	cluster = new QRadioButton(tr("cluster"));
	people = new QRadioButton(tr("people"));
	cluster->setChecked(true);

	layout->addWidget(cluster);
	layout->addWidget(people);
	
	selectionGroup->setFixedHeight(INFOLIST_SELECTION_HEIGHT);
	selectionGroup->setLayout(layout);
}

void InfoList::createFilter()
{
	filterGroup = new QGroupBox(tr("Filter"));
	QFormLayout* layout = new QFormLayout;

	playerId = new QLineEdit;
	layout->addRow(new QLabel(tr("Player ID:")), playerId);

	male = new QRadioButton(tr("Male"));
	female = new QRadioButton(tr("Female"));
	QHBoxLayout* genderLayout = new QHBoxLayout;
	genderLayout->addWidget(male);
	genderLayout->addWidget(female);
	layout->addRow(new QLabel(tr("Gender:")), genderLayout);

	married = new QRadioButton(tr("Yes"));
	unmarried = new QRadioButton(tr("No"));
	QHBoxLayout* marryLayout = new QHBoxLayout;
	marryLayout->addWidget(married);
	marryLayout->addWidget(unmarried);
	layout->addRow(new QLabel(tr("Marriaged:")), marryLayout);

	dateTimeFrom = new QLineEdit;
	dateTimeTo = new QLineEdit;
	QHBoxLayout* dateTimeLayout= new QHBoxLayout;
	dateTimeLayout->addWidget(dateTimeFrom);
	dateTimeLayout->addWidget(new QLabel(tr("to")));
	dateTimeLayout->addWidget(dateTimeTo);
	layout->addRow(new QLabel(tr("Date Time:")), dateTimeLayout);

	roleAgeFrom = new QLineEdit;
	roleAgeTo = new QLineEdit;
	QHBoxLayout* roleAgeLayout = new QHBoxLayout;
	roleAgeLayout->addWidget(roleAgeFrom);
	roleAgeLayout->addWidget(new QLabel(tr("to")));
	roleAgeLayout->addWidget(roleAgeTo);
	layout->addRow(new QLabel(tr("Role Age:")), roleAgeLayout);

	roleLevelFrom = new QLineEdit;
	roleLevelTo = new QLineEdit;
	QHBoxLayout* roleLevelLayout = new QHBoxLayout;
	roleLevelLayout->addWidget(roleLevelFrom);
	roleLevelLayout->addWidget(new QLabel(tr("to")));
	roleLevelLayout->addWidget(roleLevelTo);
	layout->addRow(new QLabel(tr("Role Level:")), roleLevelLayout);

	toolFrom = new QLineEdit;
	toolTo = new QLineEdit;
	QHBoxLayout* toolLayout = new QHBoxLayout;
	toolLayout->addWidget(toolFrom);
	toolLayout->addWidget(new QLabel(tr("to")));
	toolLayout->addWidget(toolTo);
	layout->addRow(new QLabel(tr("Tool Score:")), toolLayout);

	forceFrom = new QLineEdit;
	forceTo = new QLineEdit;
	QHBoxLayout* forceLayout = new QHBoxLayout;
	forceLayout->addWidget(forceFrom);
	forceLayout->addWidget(new QLabel(tr("to")));
	forceLayout->addWidget(forceTo);
	layout->addRow(new QLabel(tr("Force Score:")), forceLayout);

	filter = new QPushButton("Filter!");
	filter->setFixedWidth(100);
	layout->addRow(filter);


	filterGroup->setLayout(layout);
}

void InfoList::createMainViewControl()
{
	mainViewControlGroup = new QGroupBox(tr("MainView Control"));

	QFormLayout* layout = new QFormLayout;
	transitionTimeSlider = new QSlider(Qt::Horizontal);
	transitionTimeSpinbox = new QSpinBox;
	transitionTimeSlider->setRange(1, 15);
	transitionTimeSpinbox->setRange(1, 15);
	QObject::connect(transitionTimeSlider, &QSlider::valueChanged, transitionTimeSpinbox, &QSpinBox::setValue);
	void (QSpinBox:: *spinBoxSignal)(int) = &QSpinBox::valueChanged;
	QObject::connect(transitionTimeSpinbox, spinBoxSignal, transitionTimeSlider, &QSlider::setValue);
	QHBoxLayout *boxSliderLayout = new QHBoxLayout;
	boxSliderLayout->addWidget(transitionTimeSlider);
	boxSliderLayout->addWidget(transitionTimeSpinbox);
	layout->addRow(new QLabel(tr("Transition Time:")), boxSliderLayout);

	connectionStripeWidth = new QSlider(Qt::Horizontal);
	connectionStripeWidth->setRange(1, 10);
	layout->addRow(new QLabel(tr("Stripe Width:")), connectionStripeWidth);

	mainViewControlGroup->setLayout(layout);

}