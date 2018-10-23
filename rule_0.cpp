#include "mainwindow.h"

bool MainWindow::ApplyRule_0_ToGroup(int *group)
{

    QString sMsg = "Group: ";
    for (int i=0; i<9; i++)
    {
        sMsg += QString::number(group[i]);
        sMsg += " ";
    }
    //qDebug(sMsg.toLocal8Bit().data());

    bool bModificationMade = false;
    for (int i=0; i<9; i++)
    {
        CCell *pCell = &vCells[group[i]];
        int v = pCell->SolvedValue();
        if (v < 0)
        {
            continue;
        }

        for (int j=0; j<9; j++)
        {
            if (j == i)
            {
                continue;
            }
            CCell *pCell_2 = &vCells[group[j]];
            if (pCell_2->IsMarked(v))
            {
                bModificationMade = true;
                pCell_2->RemoveMark(v);
                DrawCell(group[j]);
            }
        }
    }

    return bModificationMade;
}


bool MainWindow::ApplyRowRule_0()
{
    bool bModificationMade = false;
    for (int i=0; i<9; i++)
    {
        bModificationMade |= ApplyRule_0_ToGroup(m_vRows[i]);
    }
    DisplayPossibilities();
    return(bModificationMade);
}


bool MainWindow::ApplyColumnRule_0()
{
    bool bModificationMade = false;
    for (int i=0; i<9; i++)
    {
        bModificationMade |= ApplyRule_0_ToGroup(m_vColumns[i]);
    }
    DisplayPossibilities();
    return(bModificationMade);
}

bool MainWindow::ApplyBoxRule_0()
{
    bool bModificationMade = false;
    for (int i=0; i<9; i++)
    {
        bModificationMade |= ApplyRule_0_ToGroup(m_vBoxes[i]);
    }
    DisplayPossibilities();
    return(bModificationMade);
}
