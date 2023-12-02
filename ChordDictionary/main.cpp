#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <QApplication>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QString>
using namespace std;

class ChordDictionary {
public:
    ChordDictionary() {
        initializeChordDictionary();
    }

    QString determineChord(const vector<QString>& notes) const {
        vector<QString> uniqueNotes = notes;
        auto last = unique(uniqueNotes.begin(), uniqueNotes.end());
        uniqueNotes.erase(last, uniqueNotes.end());

        cout << "Notes: " << endl;
        for (const auto& note : uniqueNotes) {
            qDebug() << note;
        }

        switch (uniqueNotes.size()) {
        case 3:
            if (isMajorChord(uniqueNotes)) {
                return "Major Chord";
            } else if (isMajor1stInversion(uniqueNotes)) {
                return "Major 1st Inversion";
            } else if (isMajor2ndInversion(uniqueNotes)) {
                return "Major 2nd Inversion";
            } else if (isMinorChord(uniqueNotes)) {
                return "Minor Chord";
            } else if (isMinor1stInversion(uniqueNotes)) {
                return "Minor 1st Inversion";
            } else if (isMinor2ndInversion(uniqueNotes)) {
                return "Minor 2nd Inversion";
            } else if (isAugmentedChord(uniqueNotes)) {
                return "Augmented Chord";
            } else if (isDiminishedTriad(uniqueNotes)) {
                return "Diminished Triad";
            } else if (isSuspended4(uniqueNotes)) {
                return "Suspended 4";
            } else if (isSuspended2(uniqueNotes)) {
                return "Suspended 2";
            } else if (isLydianTriad(uniqueNotes)) {
                return "Lydian Triad";
            } else if (isPhrygianTriad(uniqueNotes)) {
                return "Phrygian Triad";
            } else if (isPhrygianTriad1stInversion(uniqueNotes)) {
                return "Phrygian Triad 1st Inversion";
            } else if (isPhrygianTriad2ndInversion(uniqueNotes)) {
                return "Phrygian Triad 2nd Inversion";
            } else if (isLocrianTriad(uniqueNotes)) {
                return "Locrian Triad";
            } else if (isMajorFlat5(uniqueNotes)) {
                return "Major Flat-5";
            } else if (isMajorFlat51stInversion(uniqueNotes)) {
                return "Major Flat-5 1st Inversion";
            } else if (isMajorFlat52ndInversion(uniqueNotes)) {
                return "Major Flat-5 2nd Inversion";
            } else if (isQuartalTriad(uniqueNotes)) {
                return "Quartal Triad";
            } else {
                return "Undocumented Chord";
            }
        default:
            cout << "Unique Notes size:" << uniqueNotes.size() << endl;
            cout << "Unique Notes:" << endl;
            for (const auto& note : uniqueNotes) {
                qDebug() << note;
            }
            return "Undocumented Chord";
        }
    }

private:
    unordered_map<QString, vector<QString>> chordDictionary;

    void initializeChordDictionary() {
        chordDictionary["Major"] = {"0", "4", "7"};
        chordDictionary["Major 1st Inversion"] = {"0", "3", "8"};
        chordDictionary["Major 2nd Inversion"] = {"0", "5", "9"};
        chordDictionary["Minor"] = {"0", "3", "7"};
        chordDictionary["Minor 1st Inversion"] = {"0", "4", "9"};
        chordDictionary["Minor 2nd Inversion"] = {"0", "5", "8"};
        chordDictionary["Augmented"] = {"0", "4", "8"};
        chordDictionary["Diminished Triad"] = {"0", "3", "6"};
        chordDictionary["Suspended 4"] = {"0", "5", "7"};
        chordDictionary["Suspended 2"] = {"0", "2", "7"};
        chordDictionary["Lydian Triad"] = {"0", "6", "7"};
        chordDictionary["Phrygian Triad"] = {"0", "1", "7"};
        chordDictionary["Phrygian Triad 1st Inversion"] = {"0", "6", "11"};
        chordDictionary["Phrygian Triad 2nd Inversion"] = {"0", "5", "6"};
        chordDictionary["Locrian Triad"] = {"0", "1", "6"};
        chordDictionary["Major Flat-5"] = {"0", "4", "6"};
        chordDictionary["Major Flat-5 1st Inversion"] = {"0", "2", "8"};
        chordDictionary["Major Flat-5 2nd Inversion"] = {"0", "6", "10"};
        chordDictionary["Quartal Triad"] = {"0", "5", "10"};
    }

    int noteToScaleDegree(const QString& note) const {
        auto it = find(chromaticScale.begin(), chromaticScale.end(), note);
        if (it != chromaticScale.end()) {
            return distance(chromaticScale.begin(), it);
        } else {
            return -1;
        }
    }

    bool isChordOfType(const vector<QString>& notes, const QString& chordType) const {
        const auto& chordPattern = chordDictionary.find(chordType)->second;

        vector<QString> scaleDegrees;
        for (const auto& note : notes) {
            int degreeIndex = noteToScaleDegree(note);
            if (degreeIndex != -1) {
                scaleDegrees.push_back(QString::number(degreeIndex));
            } else {
                return false;
            }
        }

        sort(scaleDegrees.begin(), scaleDegrees.end());

        int baseDegree = noteToScaleDegree(notes[0]);
        for (auto& degree : scaleDegrees) {
            int normalizedDegree = (degree.toInt() - baseDegree + 12) % 12;
            degree = QString::number(normalizedDegree);
        }

        sort(scaleDegrees.begin(), scaleDegrees.end());

        QSet<QString> degreesSet(scaleDegrees.begin(), scaleDegrees.end());
        QSet<QString> chordPatternSet(chordPattern.begin(), chordPattern.end());

        return degreesSet == chordPatternSet;
    }

    bool isMajorChord(const vector<QString>& notes) const {
        return isChordOfType(notes, "Major");
    }

    bool isMajor1stInversion(const vector<QString>& notes) const {
        return isChordOfType(notes, "Major 1st Inversion");
    }

    bool isMajor2ndInversion(const vector<QString>& notes) const {
        return isChordOfType(notes, "Major 2nd Inversion");
    }

    bool isMinorChord(const vector<QString>& notes) const {
        return isChordOfType(notes, "Minor");
    }

    bool isMinor1stInversion(const vector<QString>& notes) const {
        return isChordOfType(notes, "Minor 1st Inversion");
    }

    bool isMinor2ndInversion(const vector<QString>& notes) const {
        return isChordOfType(notes, "Minor 2nd Inversion");
    }

    bool isAugmentedChord(const vector<QString>& notes) const {
        return isChordOfType(notes, "Augmented");
    }

    bool isDiminishedTriad(const vector<QString>& notes) const {
        return isChordOfType(notes, "Diminished Triad");
    }

    bool isSuspended4(const vector<QString>& notes) const {
        return isChordOfType(notes, "Suspended 4");
    }

    bool isSuspended2(const vector<QString>& notes) const {
        return isChordOfType(notes, "Suspended 2");
    }

    bool isLydianTriad(const vector<QString>& notes) const {
        return isChordOfType(notes, "Lydian Triad");
    }

    bool isPhrygianTriad(const vector<QString>& notes) const {
        return isChordOfType(notes, "Phrygian Triad");
    }

    bool isPhrygianTriad1stInversion(const vector<QString>& notes) const {
        return isChordOfType(notes, "Phrygian Triad 1st Inversion");
    }

    bool isPhrygianTriad2ndInversion(const vector<QString>& notes) const {
        return isChordOfType(notes, "Phrygian Triad 2nd Inversion");
    }

    bool isLocrianTriad(const vector<QString>& notes) const {
        return isChordOfType(notes, "Locrian Triad");
    }

    bool isMajorFlat5(const vector<QString>& notes) const {
        return isChordOfType(notes, "Major Flat-5");
    }

    bool isMajorFlat51stInversion(const vector<QString>& notes) const {
        return isChordOfType(notes, "Major Flat-5 1st Inversion");
    }

    bool isMajorFlat52ndInversion(const vector<QString>& notes) const {
        return isChordOfType(notes, "Major Flat-5 2nd Inversion");
    }

    bool isQuartalTriad(const vector<QString>& notes) const {
        return isChordOfType(notes, "Quartal Triad");
    }

    const vector<QString> chromaticScale = {"C", "C#/Db", "D", "D#/Eb", "E", "F", "F#/Gb", "G", "G#/Ab", "A", "A#/Bb", "B"};
};

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

void testMajorChord() {
    ChordDictionary chordDict;
    vector<QString> notes = {"C", "E", "G"};
    QString result = chordDict.determineChord(notes);
    assert(result == "Major Chord");
}

void testMinorChord() {
    ChordDictionary chordDict;
    vector<QString> notes = {"C", "D#/Eb", "G"};
    QString result = chordDict.determineChord(notes);
    assert(result == "Minor Chord");
}

void testAugmentedChord() {
    ChordDictionary chordDict;
    vector<QString> notes = {"C", "E", "G#/Ab"};
    QString result = chordDict.determineChord(notes);
    assert(result == "Augmented Chord");
}

void testDiminishedChord() {
    ChordDictionary chordDict;
    vector<QString> notes = {"C", "D#/Eb", "F#/Gb"};
    QString result = chordDict.determineChord(notes);
    assert(result == "Diminished Triad");
}

void testMajor1stInversion() {
    ChordDictionary chordDict;
    vector<QString> notes = {"E", "G", "C"};
    QString result = chordDict.determineChord(notes);
    assert(result == "Major 1st Inversion");
}

void testMajor2ndInversion() {
    ChordDictionary chordDict;
    vector<QString> notes = {"G", "C", "E"};
    QString result = chordDict.determineChord(notes);
    assert(result == "Major 2nd Inversion");
}

void testMinor1stInversion() {
    ChordDictionary chordDict;
    vector<QString> notes = {"D#/Eb", "G", "C"};
    QString result = chordDict.determineChord(notes);
    assert(result == "Minor 1st Inversion");
}

void testMinor2ndInversion() {
    ChordDictionary chordDict;
    vector<QString> notes = {"G", "D#/Eb", "C"};
    QString result = chordDict.determineChord(notes);
    assert(result == "Minor 2nd Inversion");
}

void testSuspended4() {
    ChordDictionary chordDict;
    vector<QString> notes = {"C", "F", "G"};
    QString result = chordDict.determineChord(notes);
    assert(result == "Suspended 4");
}

void testSuspended2() {
    ChordDictionary chordDict;
    vector<QString> notes = {"C", "D", "G"};
    QString result = chordDict.determineChord(notes);
    assert(result == "Suspended 2");
}

void testLydianTriad() {
    ChordDictionary chordDict;
    vector<QString> notes = {"C", "F#/Gb", "G"};
    QString result = chordDict.determineChord(notes);
    assert(result == "Lydian Triad");
}

void testPhrygianTriad() {
    ChordDictionary chordDict;
    vector<QString> notes = {"C", "C#/Db", "G"};
    QString result = chordDict.determineChord(notes);
    assert(result == "Phrygian Triad");
}

void testPhrygianTriad1stInversion() {
    ChordDictionary chordDict;
    vector<QString> notes = {"C#/Db", "G", "C"};
    QString result = chordDict.determineChord(notes);
    assert(result == "Phrygian Triad 1st Inversion");
}

void testPhrygianTriad2ndInversion() {
    ChordDictionary chordDict;
    vector<QString> notes = {"G", "C", "C#/Db"};
    QString result = chordDict.determineChord(notes);
    assert(result == "Phrygian Triad 2nd Inversion");
}

void testLocrianTriad() {
    ChordDictionary chordDict;
    vector<QString> notes = {"C", "C#/Db", "F#/Gb"};
    QString result = chordDict.determineChord(notes);
    assert(result == "Locrian Triad");
}

void testMajorFlat5() {
    ChordDictionary chordDict;
    vector<QString> notes = {"C", "E", "F#/Gb"};
    QString result = chordDict.determineChord(notes);
    assert(result == "Major Flat-5");
}

void testMajorFlat51stInversion() {
    ChordDictionary chordDict;
    vector<QString> notes = {"E", "F#/Gb", "C"};
    QString result = chordDict.determineChord(notes);
    assert(result == "Major Flat-5 1st Inversion");
}

void testMajorFlat52ndInversion() {
    ChordDictionary chordDict;
    vector<QString> notes = {"F#/Gb", "C", "E"};
    QString result = chordDict.determineChord(notes);
    assert(result == "Major Flat-5 2nd Inversion");
}

void testQuartalTriad() {
    ChordDictionary chordDict;
    vector<QString> notes = {"C", "F", "A#/Bb"};
    QString result = chordDict.determineChord(notes);
    assert(result == "Quartal Triad");
}


int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    ChordGui gui;
    gui.show();

    /*
    testMajorChord();
    testMajor1stInversion();
    testMajor2ndInversion();
    testMinorChord();
    testMinor1stInversion();
    testMinor2ndInversion();
    testAugmentedChord();
    testDiminishedChord();
    testSuspended4();
    testSuspended2();
    testLydianTriad();
    testPhrygianTriad();
    testPhrygianTriad1stInversion();
    testPhrygianTriad2ndInversion();
    testLocrianTriad();
    testMajorFlat5();
    testMajorFlat51stInversion();
    testMajorFlat52ndInversion();
    testQuartalTriad();
    */

    return app.exec();
}
