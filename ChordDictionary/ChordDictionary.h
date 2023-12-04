#ifndef CHORD_DICTIONARY_H
#define CHORD_DICTIONARY_H

#include <vector>
#include <unordered_map>
#include <QString>

class ChordDictionary {
public:
    ChordDictionary();

    QString determineChord(const std::vector<QString>& notes) const;

private:
    std::unordered_map<QString, std::vector<QString>> chordDictionary;

    void initializeChordDictionary();
    int noteToScaleDegree(const QString& note) const;
    bool isChordOfType(const std::vector<QString>& notes, const QString& chordType) const;
    // ... other private member functions

};

#endif // CHORD_DICTIONARY_H
