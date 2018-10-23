#include "mainwindow.h"
#include "ui_mainwindow.h"


void MainWindow::initButtons()
{
    vButtons[0] = ui->pushButton_000;
    vButtons[1] = ui->pushButton_001;
    vButtons[2] = ui->pushButton_002;
    vButtons[3] = ui->pushButton_003;
    vButtons[4] = ui->pushButton_004;
    vButtons[5] = ui->pushButton_005;
    vButtons[6] = ui->pushButton_006;
    vButtons[7] = ui->pushButton_007;
    vButtons[8] = ui->pushButton_008;
    vButtons[9] = ui->pushButton_009;

    vButtons[10] = ui->pushButton_010;
    vButtons[11] = ui->pushButton_011;
    vButtons[12] = ui->pushButton_012;
    vButtons[13] = ui->pushButton_013;
    vButtons[14] = ui->pushButton_014;
    vButtons[15] = ui->pushButton_015;
    vButtons[16] = ui->pushButton_016;
    vButtons[17] = ui->pushButton_017;
    vButtons[18] = ui->pushButton_018;
    vButtons[19] = ui->pushButton_019;

    vButtons[20] = ui->pushButton_020;
    vButtons[21] = ui->pushButton_021;
    vButtons[22] = ui->pushButton_022;
    vButtons[23] = ui->pushButton_023;
    vButtons[24] = ui->pushButton_024;
    vButtons[25] = ui->pushButton_025;
    vButtons[26] = ui->pushButton_026;
    vButtons[27] = ui->pushButton_027;
    vButtons[28] = ui->pushButton_028;
    vButtons[29] = ui->pushButton_029;

    vButtons[30] = ui->pushButton_030;
    vButtons[31] = ui->pushButton_031;
    vButtons[32] = ui->pushButton_032;
    vButtons[33] = ui->pushButton_033;
    vButtons[34] = ui->pushButton_034;
    vButtons[35] = ui->pushButton_035;
    vButtons[36] = ui->pushButton_036;
    vButtons[37] = ui->pushButton_037;
    vButtons[38] = ui->pushButton_038;
    vButtons[39] = ui->pushButton_039;

    vButtons[40] = ui->pushButton_040;
    vButtons[41] = ui->pushButton_041;
    vButtons[42] = ui->pushButton_042;
    vButtons[43] = ui->pushButton_043;
    vButtons[44] = ui->pushButton_044;
    vButtons[45] = ui->pushButton_045;
    vButtons[46] = ui->pushButton_046;
    vButtons[47] = ui->pushButton_047;
    vButtons[48] = ui->pushButton_048;
    vButtons[49] = ui->pushButton_049;

    vButtons[50] = ui->pushButton_050;
    vButtons[51] = ui->pushButton_051;
    vButtons[52] = ui->pushButton_052;
    vButtons[53] = ui->pushButton_053;
    vButtons[54] = ui->pushButton_054;
    vButtons[55] = ui->pushButton_055;
    vButtons[56] = ui->pushButton_056;
    vButtons[57] = ui->pushButton_057;
    vButtons[58] = ui->pushButton_058;
    vButtons[59] = ui->pushButton_059;

    vButtons[60] = ui->pushButton_060;
    vButtons[61] = ui->pushButton_061;
    vButtons[62] = ui->pushButton_062;
    vButtons[63] = ui->pushButton_063;
    vButtons[64] = ui->pushButton_064;
    vButtons[65] = ui->pushButton_065;
    vButtons[66] = ui->pushButton_066;
    vButtons[67] = ui->pushButton_067;
    vButtons[68] = ui->pushButton_068;
    vButtons[69] = ui->pushButton_069;

    vButtons[70] = ui->pushButton_070;
    vButtons[71] = ui->pushButton_071;
    vButtons[72] = ui->pushButton_072;
    vButtons[73] = ui->pushButton_073;
    vButtons[74] = ui->pushButton_074;
    vButtons[75] = ui->pushButton_075;
    vButtons[76] = ui->pushButton_076;
    vButtons[77] = ui->pushButton_077;
    vButtons[78] = ui->pushButton_078;
    vButtons[79] = ui->pushButton_079;

    vButtons[80] = ui->pushButton_080;
}


void MainWindow::initColumnGroups()
{
    for (int group=0; group<9; group++)
    {
        for (int i=0; i<9; i++)
        {
            m_vColumns[group][i] = i*9 + group;
        }
    }
}

void MainWindow::initRowGroups()
{
    for (int row=0; row<9; row++)
    {
        for (int i=0; i<9; i++)
        {
            m_vRows[row][i] = 9*row + i;
        }
    }
}


void MainWindow::initBoxGroups()
{

    int start;
    int box;

    box = 0;
    start = 0;
    m_vBoxes[box][0] = start;
    m_vBoxes[box][1] = start+1;
    m_vBoxes[box][2] = start+2;
    m_vBoxes[box][3] = start+9;
    m_vBoxes[box][4] = start+10;
    m_vBoxes[box][5] = start+11;
    m_vBoxes[box][6] = start+18;
    m_vBoxes[box][7] = start+19;
    m_vBoxes[box][8] = start+20;

    box = 1;
    start = 3;
    m_vBoxes[box][0] = start;
    m_vBoxes[box][1] = start+1;
    m_vBoxes[box][2] = start+2;
    m_vBoxes[box][3] = start+9;
    m_vBoxes[box][4] = start+10;
    m_vBoxes[box][5] = start+11;
    m_vBoxes[box][6] = start+18;
    m_vBoxes[box][7] = start+19;
    m_vBoxes[box][8] = start+20;

    box = 2;
    start = 6;
    m_vBoxes[box][0] = start;
    m_vBoxes[box][1] = start+1;
    m_vBoxes[box][2] = start+2;
    m_vBoxes[box][3] = start+9;
    m_vBoxes[box][4] = start+10;
    m_vBoxes[box][5] = start+11;
    m_vBoxes[box][6] = start+18;
    m_vBoxes[box][7] = start+19;
    m_vBoxes[box][8] = start+20;

    box = 3;
    start = 27;
    m_vBoxes[box][0] = start;
    m_vBoxes[box][1] = start+1;
    m_vBoxes[box][2] = start+2;
    m_vBoxes[box][3] = start+9;
    m_vBoxes[box][4] = start+10;
    m_vBoxes[box][5] = start+11;
    m_vBoxes[box][6] = start+18;
    m_vBoxes[box][7] = start+19;
    m_vBoxes[box][8] = start+20;

    box = 4;
    start = 30;
    m_vBoxes[box][0] = start;
    m_vBoxes[box][1] = start+1;
    m_vBoxes[box][2] = start+2;
    m_vBoxes[box][3] = start+9;
    m_vBoxes[box][4] = start+10;
    m_vBoxes[box][5] = start+11;
    m_vBoxes[box][6] = start+18;
    m_vBoxes[box][7] = start+19;
    m_vBoxes[box][8] = start+20;

    box = 5;
    start = 33;
    m_vBoxes[box][0] = start;
    m_vBoxes[box][1] = start+1;
    m_vBoxes[box][2] = start+2;
    m_vBoxes[box][3] = start+9;
    m_vBoxes[box][4] = start+10;
    m_vBoxes[box][5] = start+11;
    m_vBoxes[box][6] = start+18;
    m_vBoxes[box][7] = start+19;
    m_vBoxes[box][8] = start+20;

    box = 6;
    start = 54;
    m_vBoxes[box][0] = start;
    m_vBoxes[box][1] = start+1;
    m_vBoxes[box][2] = start+2;
    m_vBoxes[box][3] = start+9;
    m_vBoxes[box][4] = start+10;
    m_vBoxes[box][5] = start+11;
    m_vBoxes[box][6] = start+18;
    m_vBoxes[box][7] = start+19;
    m_vBoxes[box][8] = start+20;

    box = 7;
    start = 57;
    m_vBoxes[box][0] = start;
    m_vBoxes[box][1] = start+1;
    m_vBoxes[box][2] = start+2;
    m_vBoxes[box][3] = start+9;
    m_vBoxes[box][4] = start+10;
    m_vBoxes[box][5] = start+11;
    m_vBoxes[box][6] = start+18;
    m_vBoxes[box][7] = start+19;
    m_vBoxes[box][8] = start+20;

    box = 8;
    start = 60;
    m_vBoxes[box][0] = start;
    m_vBoxes[box][1] = start+1;
    m_vBoxes[box][2] = start+2;
    m_vBoxes[box][3] = start+9;
    m_vBoxes[box][4] = start+10;
    m_vBoxes[box][5] = start+11;
    m_vBoxes[box][6] = start+18;
    m_vBoxes[box][7] = start+19;
    m_vBoxes[box][8] = start+20;
}

