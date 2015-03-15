#pragma once
#include "QtWidgets/QWidget"
#include "QtWidgets/QMenuBar"
#include "QtWidgets/QGroupBox"
#include "QtWidgets/QLabel"
#include "QtWidgets/QVBoxLayout"
#include "QtWidgets/QLineEdit"
#include "QtWidgets/QPushButton"
#include "QtWidgets/QFormLayout"
#include "QtWidgets/QSlider"
#include "QtWidgets/QSpinBox"
#include "QtWidgets/QComboBox"
#include "QtWidgets/QRadioButton"
#include "constant.h"
class InfoList : public QWidget
{
public:
	InfoList();
	~InfoList();
private:
	QGroupBox *mainViewControlGroup;
	QSlider *transitionTimeSlider;
	QSpinBox *transitionTimeSpinbox;
	QSlider *connectionStripeWidth;

	QGroupBox *selectionGroup;
	QRadioButton *cluster, *people;
	QRadioButton *married, *unmarried;
	QRadioButton *male, *female;
	//QLabel *selectionLabel;
	//QComboBox *selectionBox;

	QGroupBox *filterGroup;
	QLineEdit *playerId;
	QLineEdit *dateTimeFrom, *dateTimeTo;
	QLineEdit *roleAgeFrom, *roleAgeTo;
	QLineEdit *roleLevelFrom, *roleLevelTo;
	QLineEdit *toolFrom, *toolTo;//zhuangbei
	QLineEdit *forceFrom, *forceTo;//xiuwei
	QPushButton *filter;

	void createSelection(void);
	void createFilter(void);
	void createMainViewControl(void);
};

