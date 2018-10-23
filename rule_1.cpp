#include "mainwindow.h"

//
//
bool MainWindow::ApplyRule_1_ToGroup(int *group)
{
    bool bModificationMade = false;
    for (int v=0; v<9; v++)
    {
        // count the cells that contain v
        std::vector<int> vList;
        for (int i=0; i<9; i++)
        {
            CCell *pCell = &vCells[group[i]];
            if (pCell->IsMarked(v))
            {
                vList.push_back(group[i]);
            }
        }
        if (vList.size() != 1)
        {
            continue;
        }
        CCell *pCell = &vCells[vList[0]];
        if (pCell->SolvedValue() < 0)
        {
            pCell->SetMark(v);
            bModificationMade = true;
            DrawCell(vList[0]);
        }
    }
    return bModificationMade;
}


bool MainWindow::ApplyRowRule_1()
{
    bool bModificationMade = false;
    for (int i=0; i<9; i++)
    {
        bModificationMade |= ApplyRule_1_ToGroup(m_vRows[i]);
    }
    DisplayPossibilities();
    return(bModificationMade);
}


bool MainWindow::ApplyColumnRule_1()
{
    bool bModificationMade = false;
    for (int i=0; i<9; i++)
    {
        bModificationMade |= ApplyRule_1_ToGroup(m_vColumns[i]);
    }
    DisplayPossibilities();
    return(bModificationMade);
}

bool MainWindow::ApplyBoxRule_1()
{
    bool bModificationMade = false;
    for (int i=0; i<9; i++)
    {
        bModificationMade |= ApplyRule_1_ToGroup(m_vBoxes[i]);
    }
    DisplayPossibilities();
    return(bModificationMade);
}


