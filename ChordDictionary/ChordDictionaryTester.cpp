#include "ChordDictionaryTester.h"
#include "ChordDictionary.h"
#include <cassert>

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
