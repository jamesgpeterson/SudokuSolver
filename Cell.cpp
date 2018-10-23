#include "Cell.h"

CCell::CCell()
{
    for (int i=0; i<9; i++)
    {
        mMarks[i] = true;
    }
}

void CCell::Copy(CCell *pSrc)
{
    for (int i=0; i<9; i++)
    {
        mMarks[i] = pSrc->mMarks[i];
    }
}


bool CCell::equal(CCell *pCell1, CCell *pCell2)
{
    for (int i=0; i<9; i++)
    {
        if (pCell1->mMarks[i] != pCell2->mMarks[i])
        {
            return false;
        }
    }
    return true;
}

void CCell::Union(CCell *pSrc)
{
    for (int i=0; i<9; i++)
    {
        mMarks[i] = mMarks[i] || pSrc->mMarks[i];
    }
}



void CCell::SetAllMarks()
{
    for (int i=0; i<9; i++)
    {
        mMarks[i] = true;
    }
}


bool CCell::IsMarked(int i)
{
    return mMarks[i];
}


void CCell::SetMark(int index)
{
    for (int n=0; n<9; n++)
    {
        mMarks[n] = false;
    }
    mMarks[index] = true;
}



void CCell::ToggleMark(int index)
{
    if (SolvedValue() == index)
    {
        return;
    }

    mMarks[index] = !mMarks[index];
}


bool CCell::IsSolved()
{
    int count = 0;
    for (int i=0; i<9; i++)
    {
        if (mMarks[i])
        {
            count++;
        }
    }
    return (count == 1);
}


int CCell::SolvedValue()
{
    if (!IsSolved())
    {
        return -1;
    }

    for (int i=0; i<9; i++)
    {
        if (mMarks[i])
        {
            return i;
        }
    }
    return -1;
}


int CCell::GetMarkCount()
{
    int count = 0;
    for (int i=0; i<9; i++)
    {
        if (mMarks[i])
        {
            count++;
        }
    }
    return count;
}


bool CCell::RemoveMark(int index)
{
    if (!mMarks[index])
    {
        return false;
    }
    mMarks[index] = false;
    return true;
}

void CCell::GetTwoMarks(int *pN1, int *pN2)
{
    *pN1 = *pN2 = -1;
    for (int i=0; i<9; i++)
    {
        if (mMarks[i])
        {
            if (*pN1 == -1)
            {
                *pN1 = i;
            }
            else
            {
                *pN2 = i;
            }
        }
    }
}


void CCell::GetThreeMarks(int *pN1, int *pN2, int *pN3)
{
    *pN1 = *pN2 = *pN3 = -1;
    for (int i=0; i<9; i++)
    {
        if (mMarks[i])
        {
            if (*pN1 == -1)
            {
                *pN1 = i;
            }
            else if (*pN2 == -1)
            {
                *pN2 = i;
            }
            else
            {
                *pN3 = i;
            }
        }
    }
}
