#ifndef CHORD_GUI_H
#define CHORD_GUI_H

#include <QWidget>
#include <vector>
#include <QPushButton>
#include "ChordDictionary.h"

class ChordGui : public QWidget {
public:
    ChordGui();

private:
    ChordDictionary chordDictionary;
    std::vector<QPushButton*> noteButtons;
    std::vector<QString> selectedNotes;

    void setupUi();
    void handleNoteButtonClicked(const QString& note);
    void handleSubmit();
};

#endif // CHORD_GUI_H
