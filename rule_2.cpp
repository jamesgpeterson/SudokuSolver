#include "mainwindow.h"

static int CellPairs[36][2] =
{
    {0, 1}, {0, 2},  {0, 3}, {0, 4}, {0, 5}, {0, 6}, {0, 7}, {0, 8},
    {1, 2},  {1, 3}, {1, 4}, {1, 5}, {1, 6}, {1, 7}, {1, 8},
    {2, 3}, {2, 4}, {2, 5}, {2, 6}, {2, 7}, {2, 8},
    {3, 4}, {3, 5}, {3, 6}, {3, 7}, {3, 8},
    {4, 5}, {4, 6}, {4, 7}, {4, 8},
    {5, 6}, {5, 7}, {5, 8},
    {6, 7}, {6, 8},
    {7, 8}
};

bool MainWindow::ApplyRule_2_ToGroup(int *group)
{
    bool bModificationMade = false;
    for (int i=0; i<36; i++)
    {
        int n1 = CellPairs[i][0];
        int n2 = CellPairs[i][1];
        CCell *pCell1 = &m_vCells[group[n1]];
        CCell *pCell2 = &m_vCells[group[n2]];
        if ( (pCell1->GetMarkCount() == 2) && (CCell::equal(pCell1, pCell2)) )
        {
            int m1, m2;
            pCell1->GetTwoMarks(&m1, &m2);
            for (int j=0; j<9; j++)
            {
                if ((j==n1) || (j==n2))
                {
                    continue;
                }
                CCell *pCell = &m_vCells[group[j]];
                if (pCell->IsMarked(m1))
                {
                    pCell->RemoveMark(m1);
                    bModificationMade = true;
                    DrawCell(group[j]);
                }
                if (pCell->IsMarked(m2))
                {
                    pCell->RemoveMark(m2);
                    bModificationMade = true;
                    DrawCell(group[j]);
                }
            }
        }
    }

    return bModificationMade;
}

bool MainWindow::ApplyRowRule_2()
{
    bool bModificationMade = false;
    for (int i=0; i<9; i++)
    {
        bModificationMade |= ApplyRule_2_ToGroup(m_vRows[i]);
    }
    DisplayPossibilities();
    return(bModificationMade);
}

bool MainWindow::ApplyColumnRule_2()
{
    bool bModificationMade = false;
    for (int i=0; i<9; i++)
    {
        bModificationMade |= ApplyRule_2_ToGroup(m_vColumns[i]);
    }
    DisplayPossibilities();
    return(bModificationMade);
}

bool MainWindow::ApplyBoxRule_2()
{
    bool bModificationMade = false;
    for (int i=0; i<9; i++)
    {
        bModificationMade |= ApplyRule_2_ToGroup(m_vBoxes[i]);
    }
    DisplayPossibilities();
    return(bModificationMade);
}

