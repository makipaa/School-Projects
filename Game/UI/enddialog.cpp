#include "enddialog.h"
#include "ui_enddialog.h"


EndDialog::EndDialog(QWidget *parent, std::map<std::string,int> finalScore):
    QDialog(parent),
    ui_(new Ui::EndDialog)
{
    ui_->setupUi(this);

    connect(ui_->newGameButton, SIGNAL(clicked(bool)), this, SLOT(accept()));
    connect(ui_->exitButton, SIGNAL(clicked(bool)), this, SLOT(reject()));

    std::multimap<int,std::string> sortedScore;
    for(auto pair : finalScore){
       sortedScore.insert(std::pair<int,std::string>(pair.second,pair.first));
    }

    ui_->scoreLabel->setWordWrap(true);
    for (std::reverse_iterator<std::multimap<int,std::string>::iterator> r =
         sortedScore.rbegin();r != sortedScore.rend(); r++ ){
        ui_->scoreLabel->setText(ui_->scoreLabel->text()
                                + QString::fromStdString(r->second)
                                + " " + aligmentMarks(int(r->second.length()))
                                 + " " + QString::number(r->first) + "\n");
    }
}

EndDialog::~EndDialog()
{
    delete ui_;
}

QString EndDialog::aligmentMarks(int wordLength)
{
    QString marks = "";
    for(int i=0; i<12-wordLength;i++){
        marks = marks + "-";
    }
    return marks;
}
