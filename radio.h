#ifndef RADIO_H
#define RADIO_H

#include <QWidget>

class QGroupBox;

class Radio : public QWidget
{
	Q_OBJECT

	public:
		Radio(QWidget *parent = 0);

	signals:
		void freqChanged(int freqVal);
		void volChanged(int volVal);
};


#endif
