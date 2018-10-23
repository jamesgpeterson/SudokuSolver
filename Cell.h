#ifndef CELL_H
#define CELL_H



class CCell
{
public:
    CCell();

    void SetAllMarks();
    bool IsMarked(int i);
    void SetMark(int index);
    bool IsSolved();
    int SolvedValue();
    int GetMarkCount();
    bool RemoveMark(int index);
    void ToggleMark(int index);
    void GetTwoMarks(int *pN1, int *pN2); // returns the first two marks set
    void GetThreeMarks(int *pN1, int *pN2, int *pN3); // returns the first three marks set

    static bool equal(CCell *pCell1, CCell *pCell2);
    void Copy(CCell *pSrc);
    void Union(CCell *pSrc);

private:
    bool mMarks[9];  // possible numbers for this cell
};


#endif // CELL_H
