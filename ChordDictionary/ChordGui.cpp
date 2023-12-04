#include "ChordGui.h"
#include <QVBoxLayout>

class ChordGui : public QWidget {
public:
    ChordGui() {
        setupUi();
    }

private:
    ChordDictionary chordDictionary;
    vector<QPushButton*> noteButtons;
    vector<QString> selectedNotes;

    void setupUi() {
        QVBoxLayout* layout = new QVBoxLayout;

        for (const QString& note : {"A", "A#/Bb", "B", "C", "C#/Db", "D", "D#/Eb", "E", "F", "F#/Gb", "G", "G#/Ab"}) {
            QPushButton* button = new QPushButton(note);

            //if (note.contains("#") || note.contains("b")) {
            //button->setStyleSheet("background-color: black; color: white;");
            //}

            noteButtons.push_back(button);
            connect(button, &QPushButton::clicked, [this, note]() { handleNoteButtonClicked(note); });

            layout->addWidget(button);
        }

        QPushButton* submitButton = new QPushButton("Submit");
        connect(submitButton, &QPushButton::clicked, this, &ChordGui::handleSubmit);

        layout->addWidget(submitButton);

        setFixedWidth(175);

        setLayout(layout);
    }

    void handleNoteButtonClicked(const QString& note) {
        auto it = std::find(selectedNotes.begin(), selectedNotes.end(), note);

        if (it == selectedNotes.end()) {
            selectedNotes.push_back(note);
        }

        if (selectedNotes.size() > 3) {
            auto firstDuplicate = std::adjacent_find(selectedNotes.begin(), selectedNotes.end());
            if (firstDuplicate != selectedNotes.end()) {
                selectedNotes.erase(firstDuplicate);
            }
        }
    }

    void handleSubmit() {
        if (selectedNotes.size() == 3) {
            QString chordType = chordDictionary.determineChord(selectedNotes);
            cout << "Chord type: " << chordType.toStdString() << endl;
        } else {
            cout << "Please enter 3 notes." << endl;
        }

        selectedNotes.clear();
    }

};
