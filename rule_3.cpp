#include "mainwindow.h"

static int CellTriples[84][3];

void MainWindow::InitRule3()
{
    int index = 0;
    for (int i=0; i<7; i++)
    {
        for (int j=i+1; j<8; j++)
        {
            for (int k=j+1; k<9; k++)
            {
                CellTriples[index][0] = i;
                CellTriples[index][1] = j;
                CellTriples[index][2] = k;
                index++;
            }
        }
    }

}


bool MainWindow::ApplyRule_3_ToGroup(int *group)
{
    bool bModificationMade = false;
    for (int i=0; i<84; i++)
    {
        int n1 = CellTriples[i][0];
        int n2 = CellTriples[i][1];
        int n3 = CellTriples[i][2];
        CCell *pCell1 = &vCells[group[n1]];
        CCell *pCell2 = &vCells[group[n2]];
        CCell *pCell3 = &vCells[group[n3]];

        if (pCell1->IsSolved() || pCell2->IsSolved() || pCell3->IsSolved())
        {
            return false;
        }

        CCell CellUnion;
        CellUnion.Copy(pCell1);
        CellUnion.Union(pCell2);
        CellUnion.Union(pCell3);
        if (CellUnion.GetMarkCount() != 3)
        {
            continue;
        }

        for (int j=0; j<9; j++)
        {
            if ((j == n1) || (j == n2) || (j == n3))
            {
                continue;
            }
            int n = group[j];
            CCell *pCell = &vCells[n];
            int m1, m2, m3;
            CellUnion.GetThreeMarks(&m1, &m2, &m3);
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
            if (pCell->IsMarked(m3))
            {
                pCell->RemoveMark(m3);
                bModificationMade = true;
                DrawCell(group[j]);
            }

        }
    }

    return bModificationMade;
}


bool MainWindow::ApplyRowRule_3()
{
    bool bModificationMade = false;
    for (int i=0; i<9; i++)
    {
        bModificationMade |= ApplyRule_3_ToGroup(m_vRows[i]);
    }
    DisplayPossibilities();
    return(bModificationMade);
}

bool MainWindow::ApplyColumnRule_3()
{
    bool bModificationMade = false;
    for (int i=0; i<9; i++)
    {
        bModificationMade |= ApplyRule_3_ToGroup(m_vColumns[i]);
    }
    DisplayPossibilities();
    return(bModificationMade);
}

bool MainWindow::ApplyBoxRule_3()
{
    bool bModificationMade = false;
    for (int i=0; i<9; i++)
    {
        bModificationMade |= ApplyRule_3_ToGroup(m_vBoxes[i]);
    }
    DisplayPossibilities();
    return(bModificationMade);
}


