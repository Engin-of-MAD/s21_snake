#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QGraphicsView>

#include "../view/boardview.h"
#include "mainwindow.h"
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    Dialog(QMainWindow* window, QGraphicsView* view, BoardView* boardView);
    ~Dialog();
public slots:
    void changeSizeField();
private:
    Ui::Dialog *ui;
    QGraphicsView* view;
    BoardView* boardView;
    QMainWindow* window;
};


#endif // DIALOG_H
