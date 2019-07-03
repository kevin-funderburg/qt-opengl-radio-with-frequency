/**
*
*   Author: Kevin Funderburg
*   File:   radio.cpp
*
**/
#include <QApplication>
#include <QHBoxLayout>
#include <QSlider>
#include <QSpinBox>
#include <QDial>
#include <QLCDNumber>
#include <QPushButton>
#include <QRadioButton>
#include <QWidget>
#include <QString>
#include <QLabel>
#include <QDebug>

#include "radio.h"
#include "ranges.h"
#include "frequency.h"

LCDRange::LCDRange(QWidget *parent)
        : QWidget(parent)
{
    QLCDNumber *lcd = new QLCDNumber(3);
    lcd->setSegmentStyle(QLCDNumber::Flat);

    slider = new QSlider(Qt::Horizontal);
    // Connect the signal change of the slider to the LCD output
    connect(slider, SIGNAL(valueChanged(int)),
            lcd, SLOT(display(int)));
    // Connect the signal change of the slider to object itself
    connect(slider, SIGNAL(valueChanged(int)),
            this, SIGNAL(valueChanged(int)));

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(lcd);
    layout->addWidget(slider);
    setLayout(layout);
}

// Public function to get the value of a LCD/slider combo
int LCDRange::value() const 
{ 
    return slider->value();
}

// Public function to adjust the value of a LCD/slider combo
void LCDRange::setValue(int value)
{
    slider->setValue(value);
}

void LCDRange::setRange(int minValue, int maxValue)
{
    if (minValue < 0 || maxValue > 100 || minValue > maxValue) {
        qWarning("LCDRange::setRange(%d, %d)\n"
                 "\tRange must be 0..99\n"
                 "\tand minValue must not be greater than maxValue",
                 minValue, maxValue);
        return;
    }
    slider->setRange(minValue, maxValue);
}

/*************** end of LCDRange ***************/

DialRange::DialRange(QWidget *parent)
    : QWidget(parent)
{
    QLCDNumber *lcd = new QLCDNumber(3);
    lcd->setSegmentStyle(QLCDNumber::Flat);

    QDial *dial = new QDial;
    dial->setNotchesVisible(true);
    dial->setMinimum(-50);
    dial->setMaximum(50);
    dial->setValue(0);
    /// Connect the dial's signal change to the LCD to output
    /// the dials value
    connect(dial, SIGNAL(valueChanged(int)),
            lcd, SLOT(display(int)));

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(lcd);
    layout->addWidget(dial);
    setLayout(layout);
}


/*************** end of DialRange ***************/


/// Class that creates a series of widgets organized into a
/// radio
Radio::Radio(QWidget *parent)
: QWidget(parent)
{
    // Quit
    QPushButton *quit = new QPushButton(tr("Exit"));
    quit->setFont(QFont("Helvetica", 15, QFont::Bold));
    // Connect the signal of the button click to the quit action
    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));

    LCDRange *frequency = new LCDRange;
    frequency->setRange(1,100);
    frequency->setValue(45);
    // Connect the signal change of the slider to the radio object itself
    connect(frequency, SIGNAL(valueChanged(int)),
            this, SIGNAL(freqChanged(int)));

    LCDRange *volume = new LCDRange;
    volume->setRange(0,5);
    volume->setValue(4);
    // Connect the signal change of the slider to the radio object itself
    connect(volume, SIGNAL(valueChanged(int)),
            this, SIGNAL(volChanged(int)));

    QRadioButton *fm = new QRadioButton("FM");
    QRadioButton *am = new QRadioButton("AM");
    am->toggle();   // toggle AM button by default
    QGridLayout *grid = new QGridLayout;
    grid->setVerticalSpacing(2);
    // Iteratively add the widgets into desired locations
    for (int row = 0; row < 3; ++row) {
        for (int column = 0; column < 3; ++column) {
            switch (row) {
                case 0: {
                    switch (column) {
                        case 0: grid->addWidget(fm, row, column); break;
                        case 2: grid->addWidget(am, row, column); break;
                    }
                    break;
                }
                case 1: {
                    DialRange *dialRange = new DialRange;
                    grid->addWidget(dialRange, row, column);
                    break;
                }
                case 2: {
                    QString txt;
                    switch (column) {
                        case 0: txt = "Bass"; break;
                        case 1: txt = "Mid"; break;
                        case 2: txt = "Treble"; break;
                    }
                    QLabel *lbl = new QLabel(txt);
                    lbl->setIndent(20-txt.length());
                    grid->addWidget(lbl, row, column);
                }
                default: break;
            }
        }
    }
    // Add labels to the sliders so you can tell which slider does what
    QLabel *freqLbl = new QLabel("Frequency");
    freqLbl->setIndent(70);     // center label
    QLabel *volLbl = new QLabel("Volume");
    volLbl->setIndent(80);      // center label

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(quit);
    layout->addWidget(volLbl);
    layout->addWidget(volume);
    layout->addWidget(freqLbl);
    layout->addWidget(frequency);
    layout->addLayout(grid);
    setLayout(layout);
}

