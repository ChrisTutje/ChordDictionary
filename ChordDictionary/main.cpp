#include <QApplication>
#include "chordtester.h"
#include "ChordGUI.h"
#include "ChordDictionary.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    ChordGui gui;
    gui.show();

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

    return app.exec();
}
