#include "dialog.h"
#include "ui_dialog.h"


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui_(new Ui::Dialog)
{
    ui_->setupUi(this);
    connect(ui_->acceptButton, &QPushButton::clicked, this, &Dialog::accept);
    connect(ui_->mapSizeSlider, &QSlider::valueChanged, this,
            &Dialog::showValue);
    connect(ui_->roundSlider, &QSlider::valueChanged, this,
            &Dialog::showValue);
    connect(ui_->addPlayersButton, &QPushButton::clicked, this,
            &Dialog::addPlayer);

    QPixmap pixmap(":/Images/pirkanmaa.png");
    ui_->pic1Label->setPixmap(pixmap);
    ui_->pic1Label->setScaledContents(true);
    ui_->pic1Label->setSizePolicy(QSizePolicy::Ignored,
                                 QSizePolicy::Ignored);

    QPalette pal;
    pal.setColor(QPalette::Background, Qt::black);

    ui_->lcdMapSize->setAutoFillBackground(true);
    ui_->lcdMapSize->setPalette(pal);

    ui_->lcdRounds->setAutoFillBackground(true);
    ui_->lcdRounds->setPalette(pal);

    ui_->lcdMapSize->display(ui_->mapSizeSlider->value());
    ui_->mapSizeSlider->setMinimum(10);
    ui_->mapSizeSlider->setMaximum(50);

    ui_->lcdRounds->display(ui_->roundSlider->value());
    ui_->roundSlider->setMinimum(10);
    ui_->roundSlider->setMaximum(50);

    colorOptions_ = {QColor(Qt::red),
                     QColor(Qt::green),
                     QColor(Qt::blue),
                     QColor(Qt::yellow)};

    updateColorOptions();

    ui_->acceptButton->setDisabled(true);

    ui_->showPlayersLabel->setAlignment(Qt::AlignTop);
    ui_->showPlayersLabel->setText("Players: \n");
    ui_->showPlayersLabel->setWordWrap(true);
}

Dialog::~Dialog()
{
    delete ui_;
}

void Dialog::accept()
{
    int mapValue = ui_->mapSizeSlider->value();
    emit sendMapValue(mapValue);

    int roundValue = ui_->roundSlider->value();
    emit sendRoundValue(roundValue);

    emit sendPlayer(players_);
    QDialog::accept();
}

void Dialog::showValue(){
    int mapValue = ui_->mapSizeSlider->value();
    ui_->lcdMapSize->display(mapValue);

    int roundValue = ui_->roundSlider->value();
    ui_->lcdRounds->display(roundValue);
}

void Dialog::updateColorOptions()
{
    ui_->comboBox->clear();
    QIcon colorIcon;
    QPixmap map(100,100);

    for (QColor color : colorOptions_){
        map.fill(color);
        colorIcon.addPixmap(map);
        ui_->comboBox->addItem(colorIcon, "");
    }
}

void Dialog::addPlayer()
{
    std::string name = ui_->nameInput->text().toStdString();
    if (name == ""){
        showMessage("Player needs a name.");
        return;
    }
    if(name.size() > 10){
        showMessage("Too lengthy name!");
        return;
    }
    for(auto player : players_){
        if (player->getName() == name){
            showMessage("Multiple players can't have the same name.");
            return;
        }
    }
    players_.push_back(std::make_shared<Student::Player>(
            Student::Player(name,{},colorOptions_[
                            ui_->comboBox->currentIndex()])));

    ui_->showPlayersLabel->setText(ui_->showPlayersLabel->text() +
                                   ui_->nameInput->text() + "\n");

    colorOptions_.erase(colorOptions_.begin() +
                        ui_->comboBox->currentIndex());
    ui_->nameInput->clear();

    updateColorOptions();

    ui_->acceptButton->setEnabled(true);

    if(colorOptions_.size() == 0){
        ui_->addPlayersButton->setDisabled(true);
        showMessage("Maximum number of players reached.");
    }

}

void Dialog::showMessage(QString message)
{
    ui_->infoLabel->setText(message);
}
