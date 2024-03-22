#ifndef CHORDDICTIONARY_H
#define CHORDDICTIONARY_H

#include <QSet>

class ChordDictionary {
public:
    ChordDictionary();
    QString determineChord(const std::vector<QString>& notes) const;

private:
    std::unordered_map<QString, std::vector<QString>> chordDictionary;
    void initializeChordDictionary();
    int noteToScaleDegree(const QString& note) const;
    bool isChordOfType(const std::vector<QString>& notes, const QString& chordType) const;
    bool isMajorChord(const std::vector<QString>& notes) const;
    bool isMajor1stInversion(const std::vector<QString>& notes) const;
    bool isMajor2ndInversion(const std::vector<QString>& notes) const;
    bool isMinorChord(const std::vector<QString>& notes) const;
    bool isMinor1stInversion(const std::vector<QString>& notes) const;
    bool isMinor2ndInversion(const std::vector<QString>& notes) const;
    bool isAugmentedChord(const std::vector<QString>& notes) const;
    bool isDiminishedTriad(const std::vector<QString>& notes) const;
    bool isSuspended4(const std::vector<QString>& notes) const;
    bool isSuspended2(const std::vector<QString>& notes) const;
    bool isLydianTriad(const std::vector<QString>& notes) const;
    bool isPhrygianTriad(const std::vector<QString>& notes) const;
    bool isPhrygianTriad1stInversion(const std::vector<QString>& notes) const;
    bool isPhrygianTriad2ndInversion(const std::vector<QString>& notes) const;
    bool isLocrianTriad(const std::vector<QString>& notes) const;
    bool isMajorFlat5(const std::vector<QString>& notes) const;
    bool isMajorFlat51stInversion(const std::vector<QString>& notes) const;
    bool isMajorFlat52ndInversion(const std::vector<QString>& notes) const;
    bool isQuartalTriad(const std::vector<QString>& notes) const;

    const std::vector<QString> chromaticScale = {"C", "C#/Db", "D", "D#/Eb", "E", "F", "F#/Gb", "G", "G#/Ab", "A", "A#/Bb", "B"};
};

#endif
