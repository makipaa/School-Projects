#include "enddialog.h"
#include "ui_enddialog.h"

EndDialog::EndDialog(QWidget *parent, std::map<std::string,int> finalScore) :
    QDialog(parent),
    ui(new Ui::EndDialog)
{
    ui->setupUi(this);

    connect(ui->newGameButton, SIGNAL(clicked(bool)), this, SLOT(accept()));
    connect(ui->exitButton, SIGNAL(clicked(bool)), this, SLOT(reject()));

    std::multimap<int,std::string> sortedScore;
    for(auto pair : finalScore){
        sortedScore.insert(std::pair<int,std::string>(pair.second,pair.first));
    }

    ui->scoreLabel->setWordWrap(true);
    for (std::reverse_iterator<std::multimap<int,std::string>::iterator> r = sortedScore.rbegin();r != sortedScore.rend(); r++ ){
        ui->scoreLabel->setText(ui->scoreLabel->text()
                                + QString::fromStdString(r->second)
                                + " " + aligmentMarks(int(r->second.length())) + " "
                                + QString::number(r->first)
                                + "\n");
    }

}

EndDialog::~EndDialog()
{
    delete ui;
}

QString EndDialog::aligmentMarks(int wordLength)
{
    QString marks = "";
    for(int i=0; i<12-wordLength;i++){
        marks = marks + "-";
    }
    return marks;
}
