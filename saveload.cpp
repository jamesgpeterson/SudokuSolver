#include "mainwindow.h"
#include "QFileDialog"



void MainWindow::on_pushButton_SaveGame_clicked()
{
    QString sFilename =  QFileDialog::getSaveFileName(
          this,
          "Open Document",
          QDir::currentPath(),
          "Text files (*.txt) ;; All files (*.*) ");
    if (sFilename.isEmpty())
    {
        return;
    }

    FILE *fp = fopen(sFilename.toLocal8Bit().data(), "w");
    if (fp == nullptr)
    {
        return;
    }

    for (int i=0; i<81; i++)
    {
        CCell *pCell = &vCells[i];
        int n = pCell->SolvedValue();
        fprintf(fp, "%d\n", n);
    }
    fclose(fp);
}

void MainWindow::on_pushButton_LoadGame_clicked()
{
    QString sFilename =  QFileDialog::getOpenFileName(
          this,
          "Open Document",
          QDir::currentPath(),
          "Text files (*.txt) ;; All files (*.*)");
    if (sFilename.isEmpty())
    {
        return;
    }

    FILE *fp = fopen(sFilename.toLocal8Bit().data(), "r");
    if (fp == nullptr)
    {
        return;
    }

    for (int i=0; i<81; i++)
    {
        int n;
        fscanf(fp, "%d\n", &n);
        //qDebug("%d", n);
        CCell *pCell = &vCells[i];
        if (n == -1)
        {
            pCell->SetAllMarks();
        }
        else
        {
            pCell->SetMark(n);
        }
        DrawCell(i);
    }
    fclose(fp);

    DisplayPossibilities();
}
