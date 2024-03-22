#ifndef CHORD_GUI_H
#define CHORD_GUI_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <vector>
#include <QString>

class ChordDictionary;

class ChordGui : public QWidget {
    Q_OBJECT

public:
    ChordGui();

private slots:
    void handleNoteButtonClicked(const QString& note);
    void handleSubmit();

private:
    ChordDictionary* chordDictionary;
    std::vector<QPushButton*> noteButtons;
    std::vector<QString> selectedNotes;

    void setupUi();
};

#endif
