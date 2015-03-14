#pragma once
#include "QtWidgets/QWidget"
#include "QtWidgets/QMenuBar"
#include "QtWidgets/QGroupBox"
#include "QtWidgets/QTextEdit"
#include "QtWidgets/QLabel"
#include "QtWidgets/QDialogButtonBox"
#include "QtWidgets/QVBoxLayout"
#include "QtWidgets/QLineEdit"
#include "QtWidgets/QPushButton"
#include "QtWidgets/QFormLayout"
#include "QtWidgets/QSpinBox"
#include "QtWidgets/QComboBox"
class InfoList : public QWidget
{
public:
	InfoList();
	~InfoList();
private:
	QGroupBox *selectionGroup;
	QLabel *selectionLabel;
	QComboBox *selectionBox;

	QGroupBox *filterGroup;

	void createSelection(void);
	void createFilter(void);
};

