#ifndef CHOOSEWINDOW_H
#define CHOOSEWINDOW_H

#include<QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class ChooseWindow; }
QT_END_NAMESPACE

class ChooseWindow : public QMainWindow{
    Q_OBJECT

public:
    ChooseWindow(QWidget *parent = nullptr);
    ~ChooseWindow();

private slots:
    void on_pushButton_clicked();

    void on_horizontalSlider_sliderMoved(int position);

    void on_fileLabel_linkActivated(const QString &link);

    void on_NLabel_linkActivated(const QString &link);

    void on_runBtn_clicked();

    void on_nextPage_Btn_clicked();

    void on_readPage_btn_clicked();

    void on_sequencePage_btn_clicked();

    void on_mainPage_btn2_clicked();

    void on_mainPage_btn_clicked();

    void on_findSequence_btn_clicked();

private:
    Ui::ChooseWindow *ui;

};

#endif // CHOOSEWINDOW_H
