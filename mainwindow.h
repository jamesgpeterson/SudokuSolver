#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

#include "Cell.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_000_clicked() { m_nCurrentCellIndex = 0;}
    void on_pushButton_001_clicked() { m_nCurrentCellIndex = 1;}
    void on_pushButton_002_clicked() { m_nCurrentCellIndex = 2;}
    void on_pushButton_003_clicked() { m_nCurrentCellIndex = 3;}
    void on_pushButton_004_clicked() { m_nCurrentCellIndex = 4;}
    void on_pushButton_005_clicked() { m_nCurrentCellIndex = 5;}
    void on_pushButton_006_clicked() { m_nCurrentCellIndex = 6;}
    void on_pushButton_007_clicked() { m_nCurrentCellIndex = 7;}
    void on_pushButton_008_clicked() { m_nCurrentCellIndex = 8;}
    void on_pushButton_009_clicked() { m_nCurrentCellIndex = 9;}
    void on_pushButton_010_clicked() { m_nCurrentCellIndex = 10;}
    void on_pushButton_011_clicked() { m_nCurrentCellIndex = 11;}
    void on_pushButton_012_clicked() { m_nCurrentCellIndex = 12;}
    void on_pushButton_013_clicked() { m_nCurrentCellIndex = 13;}
    void on_pushButton_014_clicked() { m_nCurrentCellIndex = 14;}
    void on_pushButton_015_clicked() { m_nCurrentCellIndex = 15;}
    void on_pushButton_016_clicked() { m_nCurrentCellIndex = 16;}
    void on_pushButton_017_clicked() { m_nCurrentCellIndex = 17;}
    void on_pushButton_018_clicked() { m_nCurrentCellIndex = 18;}
    void on_pushButton_019_clicked() { m_nCurrentCellIndex = 19;}
    void on_pushButton_020_clicked() { m_nCurrentCellIndex = 20;}
    void on_pushButton_021_clicked() { m_nCurrentCellIndex = 21;}
    void on_pushButton_022_clicked() { m_nCurrentCellIndex = 22;}
    void on_pushButton_023_clicked() { m_nCurrentCellIndex = 23;}
    void on_pushButton_024_clicked() { m_nCurrentCellIndex = 24;}
    void on_pushButton_025_clicked() { m_nCurrentCellIndex = 25;}
    void on_pushButton_026_clicked() { m_nCurrentCellIndex = 26;}
    void on_pushButton_027_clicked() { m_nCurrentCellIndex = 27;}
    void on_pushButton_028_clicked() { m_nCurrentCellIndex = 28;}
    void on_pushButton_029_clicked() { m_nCurrentCellIndex = 29;}
    void on_pushButton_030_clicked() { m_nCurrentCellIndex = 30;}
    void on_pushButton_031_clicked() { m_nCurrentCellIndex = 31;}
    void on_pushButton_032_clicked() { m_nCurrentCellIndex = 32;}
    void on_pushButton_033_clicked() { m_nCurrentCellIndex = 33;}
    void on_pushButton_034_clicked() { m_nCurrentCellIndex = 34;}
    void on_pushButton_035_clicked() { m_nCurrentCellIndex = 35;}
    void on_pushButton_036_clicked() { m_nCurrentCellIndex = 36;}
    void on_pushButton_037_clicked() { m_nCurrentCellIndex = 37;}
    void on_pushButton_038_clicked() { m_nCurrentCellIndex = 38;}
    void on_pushButton_039_clicked() { m_nCurrentCellIndex = 39;}
    void on_pushButton_040_clicked() { m_nCurrentCellIndex = 40;}
    void on_pushButton_041_clicked() { m_nCurrentCellIndex = 41;}
    void on_pushButton_042_clicked() { m_nCurrentCellIndex = 42;}
    void on_pushButton_043_clicked() { m_nCurrentCellIndex = 43;}
    void on_pushButton_044_clicked() { m_nCurrentCellIndex = 44;}
    void on_pushButton_045_clicked() { m_nCurrentCellIndex = 45;}
    void on_pushButton_046_clicked() { m_nCurrentCellIndex = 46;}
    void on_pushButton_047_clicked() { m_nCurrentCellIndex = 47;}
    void on_pushButton_048_clicked() { m_nCurrentCellIndex = 48;}
    void on_pushButton_049_clicked() { m_nCurrentCellIndex = 49;}
    void on_pushButton_050_clicked() { m_nCurrentCellIndex = 50;}
    void on_pushButton_051_clicked() { m_nCurrentCellIndex = 51;}
    void on_pushButton_052_clicked() { m_nCurrentCellIndex = 52;}
    void on_pushButton_053_clicked() { m_nCurrentCellIndex = 53;}
    void on_pushButton_054_clicked() { m_nCurrentCellIndex = 54;}
    void on_pushButton_055_clicked() { m_nCurrentCellIndex = 55;}
    void on_pushButton_056_clicked() { m_nCurrentCellIndex = 56;}
    void on_pushButton_057_clicked() { m_nCurrentCellIndex = 57;}
    void on_pushButton_058_clicked() { m_nCurrentCellIndex = 58;}
    void on_pushButton_059_clicked() { m_nCurrentCellIndex = 59;}
    void on_pushButton_060_clicked() { m_nCurrentCellIndex = 60;}
    void on_pushButton_061_clicked() { m_nCurrentCellIndex = 61;}
    void on_pushButton_062_clicked() { m_nCurrentCellIndex = 62;}
    void on_pushButton_063_clicked() { m_nCurrentCellIndex = 63;}
    void on_pushButton_064_clicked() { m_nCurrentCellIndex = 64;}
    void on_pushButton_065_clicked() { m_nCurrentCellIndex = 65;}
    void on_pushButton_066_clicked() { m_nCurrentCellIndex = 66;}
    void on_pushButton_067_clicked() { m_nCurrentCellIndex = 67;}
    void on_pushButton_068_clicked() { m_nCurrentCellIndex = 68;}
    void on_pushButton_069_clicked() { m_nCurrentCellIndex = 69;}
    void on_pushButton_070_clicked() { m_nCurrentCellIndex = 70;}
    void on_pushButton_071_clicked() { m_nCurrentCellIndex = 71;}
    void on_pushButton_072_clicked() { m_nCurrentCellIndex = 72;}
    void on_pushButton_073_clicked() { m_nCurrentCellIndex = 73;}
    void on_pushButton_074_clicked() { m_nCurrentCellIndex = 74;}
    void on_pushButton_075_clicked() { m_nCurrentCellIndex = 75;}
    void on_pushButton_076_clicked() { m_nCurrentCellIndex = 76;}
    void on_pushButton_077_clicked() { m_nCurrentCellIndex = 77;}
    void on_pushButton_078_clicked() { m_nCurrentCellIndex = 78;}
    void on_pushButton_079_clicked() { m_nCurrentCellIndex = 79;}
    void on_pushButton_080_clicked() { m_nCurrentCellIndex = 80;}

    void on_pushButton_ApplyRules_clicked();
    void on_pushButton_Reset_clicked();
    void on_pushButton_SaveGame_clicked();
    void on_pushButton_LoadGame_clicked();
    void on_pushButton_Rule0_clicked();
    void on_pushButton_Rule1_clicked();
    void on_pushButton_Rule2_clicked();
    void on_pushButton_Rule3_clicked();
    void on_pushButton_Save_clicked();
    void on_pushButton_Restore_clicked();

    bool on_pushButton_Guess_clicked();

private:
    void keyPressEvent(QKeyEvent *e);
    void initButtons();
    void initColumnGroups();
    void initRowGroups();
    void initBoxGroups();
    void initGroups();
    void DrawCell(int i);
    double CountPossibilities();
    void DisplayPossibilities();

    bool ApplyRule_0_ToGroup(int *group);
    bool ApplyRowRule_0();
    bool ApplyColumnRule_0();
    bool ApplyBoxRule_0();

    bool ApplyRule_1_ToGroup(int *group);
    bool ApplyRowRule_1();
    bool ApplyColumnRule_1();
    bool ApplyBoxRule_1();

    bool ApplyRule_2_ToGroup(int *group);
    bool ApplyRowRule_2();
    bool ApplyColumnRule_2();
    bool ApplyBoxRule_2();

    void InitRule3();
    bool ApplyRule_3_ToGroup(int *group);
    bool ApplyRowRule_3();
    bool ApplyColumnRule_3();
    bool ApplyBoxRule_3();

    bool ApplyAllRules();


private:
    Ui::MainWindow *ui;
    QPushButton *vButtons[81];
    CCell m_vCells[81];
    CCell vCells_saved[81];
    int m_nCurrentCellIndex;
    int m_vColumns[9][9];
    int m_vRows[9][9];
    int m_vBoxes[9][9];
};

#endif // MAINWINDOW_H
