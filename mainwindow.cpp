#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QKeyEvent"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_nCurrentCellIndex(-1)
{
    ui->setupUi(this);

    initButtons();
    initColumnGroups();
    initRowGroups();
    initBoxGroups();
    InitRule3();
    DisplayPossibilities();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::keyPressEvent(QKeyEvent *e)
{
    if ((m_nCurrentCellIndex < 0) || (m_nCurrentCellIndex >= 81))
    {
        return;
    }

    if (e->key() == Qt::Key_Return)
    {
        m_nCurrentCellIndex = -1;
        return;
    }

    if ((e->key() < Qt::Key_0) || (e->key() > Qt::Key_9))
    {
        return;
    }

    CCell *pCell = &m_vCells[m_nCurrentCellIndex];
    int nMarkIndex = e->key() - Qt::Key_1;

    if (ui->checkBox_Mark->isChecked())
    {
        if (e->key() != Qt::Key_0)
        {
            pCell->ToggleMark(nMarkIndex);
        }
    }
    else
    {
        if (e->key() == Qt::Key_0)
        {
            pCell->SetAllMarks();
        }
        else
        {
            int nMarkIndex = e->key() - Qt::Key_1;
            pCell->SetMark(nMarkIndex);
        }
    }

    DrawCell(m_nCurrentCellIndex);
    DisplayPossibilities();
}


double  MainWindow::CountPossibilities()
{
    double fPossibilities = 1.0;
    for (int i=0; i<81; i++)
    {
        CCell *pCell = &m_vCells[i];
        int n = pCell->GetMarkCount();
        fPossibilities *= n;
    }
    return fPossibilities;
}

void MainWindow::DisplayPossibilities()
{
    double count = CountPossibilities();
    QString sMsg;
    sMsg = "Combinations: " + QString::number(count);
    ui->statusBar->showMessage(sMsg, 0);
}


void MainWindow::on_pushButton_Reset_clicked()
{
    for (int i=0; i<81; i++)
    {
        CCell *pCell = &m_vCells[i];
        pCell->SetAllMarks();
        DrawCell(i);
    }
    DisplayPossibilities();
}



void MainWindow::DrawCell(int i)
{
    QPushButton *pButton = vButtons[i];
    CCell *pCell = &m_vCells[i];
    QString sText;
    int nSolvedValue = pCell->SolvedValue();
    if (nSolvedValue < 0)
    {
        sText += pCell->IsMarked(0) ? "1 " : "  ";
        sText += pCell->IsMarked(1) ? "2 " : "  ";
        sText += pCell->IsMarked(2) ? "3 " : "  ";
        sText += "\n";
        sText += pCell->IsMarked(3) ? "4 " : "  ";
        sText += pCell->IsMarked(4) ? "5 " : "  ";
        sText += pCell->IsMarked(5) ? "6 " : "  ";
        sText += "\n";
        sText += pCell->IsMarked(6) ? "7 " : "  ";
        sText += pCell->IsMarked(7) ? "8 " : "  ";
        sText += pCell->IsMarked(8) ? "9 " : "  ";
    }
    else
    {
        sText = QString("\n%1").arg(nSolvedValue+1);
    }

    pButton->setText(sText);
}

bool MainWindow::ApplyAllRules()
{
    bool bModificationMade;

    do
    {
        bModificationMade = false;
        bModificationMade |= ApplyRowRule_0();
        bModificationMade |= ApplyColumnRule_0();
        bModificationMade |= ApplyBoxRule_0();
        bModificationMade |= ApplyRowRule_1();
        bModificationMade |= ApplyColumnRule_1();
        bModificationMade |= ApplyBoxRule_1();
        bModificationMade |= ApplyRowRule_2();
        bModificationMade |= ApplyColumnRule_2();
        bModificationMade |= ApplyBoxRule_2();
        bModificationMade |= ApplyRowRule_3();
        bModificationMade |= ApplyColumnRule_3();
        bModificationMade |= ApplyBoxRule_3();
    } while (bModificationMade);

    return bModificationMade;
}



void MainWindow::on_pushButton_ApplyRules_clicked()
{
    ApplyAllRules();
}


void MainWindow::on_pushButton_Rule0_clicked()
{
    ApplyColumnRule_0();
    ApplyRowRule_0();
    ApplyBoxRule_0();
}

void MainWindow::on_pushButton_Rule1_clicked()
{
    ApplyColumnRule_1();
    ApplyRowRule_1();
    ApplyBoxRule_1();
}

void MainWindow::on_pushButton_Rule2_clicked()
{
    ApplyRowRule_2();
    ApplyColumnRule_2();
    ApplyBoxRule_2();
}


void MainWindow::on_pushButton_Rule3_clicked()
{
    ApplyRowRule_3();
    ApplyColumnRule_3();
    ApplyBoxRule_3();
}


void MainWindow::on_pushButton_Save_clicked()
{
    for (int i=0; i<81; i++)
    {
        vCells_saved[i].Copy(&m_vCells[i]);
    }
}

void MainWindow::on_pushButton_Restore_clicked()
{
    for (int i=0; i<81; i++)
    {
        m_vCells[i].Copy(&vCells_saved[i]);
        DrawCell(i);
    }

    DisplayPossibilities();
}

bool MainWindow::on_pushButton_Guess_clicked()
{
    // find cells with two possibilities
    std::vector<int> vCellIndices;
    for (int i=0; i<81; i++)
    {
        if (m_vCells[i].GetMarkCount() == 2)
        {
            vCellIndices.push_back(i);
        }
    }
    if (vCellIndices.size() == 0)
    {
        return false;
    }

    // save game
    CCell vCells_backup[81];
    for (int i=0; i<81; i++)
    {
        vCells_backup[i].Copy(&m_vCells[i]);
    }

    for (unsigned int i=0; i<vCellIndices.size(); i++)
    {
        int m1, m2;
        CCell *pCell = &m_vCells[vCellIndices[i]];
        pCell->GetTwoMarks(&m1, &m2);

        // Restore saved state
        for (int i=0; i<81; i++)
        {
            m_vCells[i].Copy(&vCells_backup[i]);
        }

        pCell->SetMark(m1);
        ApplyAllRules();
        double count = CountPossibilities();
        if (count == 1.0)
        {
            DrawCell(vCellIndices[i]);
            return true;
        }

        // Restore saved state
        for (int i=0; i<81; i++)
        {
            m_vCells[i].Copy(&vCells_backup[i]);
        }

        pCell->SetMark(m2);
        ApplyAllRules();
        count = CountPossibilities();
        if (count == 1.0)
        {
            DrawCell(vCellIndices[i]);
            return true;
        }
    }

    return false;
}
