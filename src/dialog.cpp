#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->spinBoxWidht->setMinimum(10);
    ui->spinBoxHeigth->setMinimum(20);
}
Dialog::Dialog(QMainWindow *window, QGraphicsView *view, BoardView *boardView, QSize* fixSize)
: window(window)
    , ui(new Ui::Dialog)
    , view(view)
    , boardView(boardView)
    , fixSize(fixSize)
{
    ui->setupUi(this);
    ui->spinBoxWidht->setMinimum(boardView->getSize().width() / 20);
    ui->spinBoxHeigth->setMinimum(boardView->getSize().height() / 20);
    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(changeSizeField()) );


}

void Dialog::changeSizeField() {
//    QRect fixSize ;

    qDebug() << "Correct Width: " << fixSize->width();
    qDebug() << "Correct Height: " << fixSize->height();
    boardView->resize(ui->spinBoxWidht->value(), ui->spinBoxHeigth->value());
    view->resize(boardView->getSize());
    const QSize size(boardView->getSize().width() + fixSize->width(),boardView->getSize().height() + fixSize->height());
    window->resize(size);
    window->setMinimumSize(size);
    window->setMaximumSize(size);

}

Dialog::~Dialog()
{
    delete ui;
}
