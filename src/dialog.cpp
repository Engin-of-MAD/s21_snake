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
Dialog::Dialog(QMainWindow *window, QGraphicsView *view, BoardView *boardView)
: window(window)
    , ui(new Ui::Dialog)
    , view(view)
    , boardView(boardView)
{
    ui->setupUi(this);
    ui->spinBoxWidht->setMinimum(boardView->getSize().width() / 20);
    ui->spinBoxHeigth->setMinimum(boardView->getSize().height() / 20);
    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(changeSizeField()) );
}

void Dialog::changeSizeField() {
    int fix_width = 20, fix_height = 66;

    boardView->resize(ui->spinBoxWidht->value(), ui->spinBoxHeigth->value());

    const QSize size(boardView->getSize().width() + fix_width,boardView->getSize().height() + fix_height);
    window->resize(size);
    window->setMinimumSize(size);
    window->setMaximumSize(size);
//    qDebug() << "Pointer: " << window << window->size();
//    qDebug() << "New size: " << size;
}

Dialog::~Dialog()
{
    delete ui;
}
