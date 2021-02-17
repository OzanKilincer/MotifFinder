#include "choosewindow.h"
#include "ui_choosewindow.h"
#include "dbconnection.h"
#include "fileio.h"
#include "genome.h"
#include <vector>
#include <QFileDialog>
#include <QMessageBox>
#include <QTableWidget>
#include <QInputDialog>
#include <QPixmap>

ChooseWindow::ChooseWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ChooseWindow){

    ui->setupUi(this);

    QPixmap pix ("/Users/ozi/Downloads/MotifFinderQt/dna1.png");
    ui->img_label->setPixmap(pix);
}

ChooseWindow::~ChooseWindow(){

    delete ui;
}

//GenomeFile object for getting paramaters and calling readFile func
FileIO IO;

void ChooseWindow::on_pushButton_clicked(){

    QString file_name = QFileDialog::getOpenFileName(this, "Choose a file", QDir::homePath());

    ui->fileLabel->setText(file_name);
    IO.setFile(file_name.toStdString());
}

//QString qs;
//do things
//std::cout << qs.toStdString() << std::endl;
//MSSQL server name -> DESKTOP-IPMLKMD

void ChooseWindow::on_fileLabel_linkActivated(const QString &link){}

void ChooseWindow::on_NLabel_linkActivated(const QString &link){}

void ChooseWindow::on_horizontalSlider_sliderMoved(int position){

    ui->NLabel->setText(QString::number(position));
    IO.setSize(position);
}

void ChooseWindow::on_runBtn_clicked(){

    std::vector<Genome> genomes = IO.readFile();

    if(genomes[0].getSeq() == "readFileError")
        ui->fileLabel->setText("Okuma başarısız");

    else{

        ui->fileLabel->setText("Okuma başarılı");

        DbConnection db;

        if(db.postGenome(genomes)){

             ui->fileLabel->setText("Yazma başarılı");
        }

        else
            ui->fileLabel->setText("Yazma başarısız");
    }
}

void ChooseWindow::on_findSequence_btn_clicked(){

    QString seq =  QInputDialog::getText(this,"Insert Sequence","Sequence");



    DbConnection db;
    std::vector<Genome> genomes = db.getGenomes(seq);

    for(auto gen : genomes){

        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        ui->tableWidget->setItem(ui->tableWidget->rowCount() -1,0,new QTableWidgetItem(gen.getSeq()));
        QString location = QString::number(gen.getLoc());
        ui->tableWidget->setItem(ui->tableWidget->rowCount() -1,1,new QTableWidgetItem(location));
    }
}

//Navigation Buttons
void ChooseWindow::on_mainPage_btn_clicked(){

    ui->stackedWidget->setCurrentIndex(0);
}

void ChooseWindow::on_mainPage_btn2_clicked(){

    ui->stackedWidget->setCurrentIndex(0);
}

void ChooseWindow::on_readPage_btn_clicked(){

    ui->stackedWidget->setCurrentIndex(1);
}

void ChooseWindow::on_nextPage_Btn_clicked(){

    ui->stackedWidget->setCurrentIndex(2);
}

void ChooseWindow::on_sequencePage_btn_clicked(){

    ui->stackedWidget->setCurrentIndex(2);
}
