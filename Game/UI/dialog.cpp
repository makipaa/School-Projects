#include "dialog.h"
#include "ui_dialog.h"



Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->acceptButton, &QPushButton::clicked, this, &Dialog::accept);
    connect(ui->mapSizeSlider, &QSlider::valueChanged, this, &Dialog::showValue);
    connect(ui->addPlayersButton, &QPushButton::clicked, this, &Dialog::addPlayer);

    QPalette pal;
    pal.setColor(QPalette::Background, Qt::black);

    ui->lcdMapSize->setAutoFillBackground(true);
    ui->lcdMapSize->setPalette(pal);

    ui->lcdMapSize->display(ui->mapSizeSlider->value());
    ui->mapSizeSlider->setMaximum(50);


    colorOptions_ = {QColor(Qt::red),
                     QColor(Qt::green),
                     QColor(Qt::blue),
                     QColor(Qt::yellow)};

    updateColorOptions();

    ui->acceptButton->setDisabled(true);

    ui->showPlayersLabel->setAlignment(Qt::AlignTop);
    ui->showPlayersLabel->setText("Players: \n");
    ui->showPlayersLabel->setWordWrap(true);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::accept(){

    int value = ui->mapSizeSlider->value();
    emit sendValue(value);
    emit sendPlayer(players_);
    QDialog::accept();
}

void Dialog::showValue(){
    int value = ui->mapSizeSlider->value();
    ui->lcdMapSize->display(value);
}

void Dialog::updateColorOptions()
{
    ui->comboBox->clear();
    QIcon colorIcon;
    QPixmap map(100,100);

    for (QColor color : colorOptions_){
        map.fill(color);
        colorIcon.addPixmap(map);
        ui->comboBox->addItem(colorIcon, "");
    }
}

void Dialog::addPlayer()
{
    std::string name = ui->nameInput->text().toStdString();
    if (name == ""){
        showMessage("Player needs a name.");
        return;
    }
    for(auto player : players_){
        if (player->getName() == name){
            showMessage("Multiple players can't have same name.");
            return;
        }
    }
    players_.push_back(std::make_shared<Student::Player>(
            Student::Player(name,{},colorOptions_[ui->comboBox->currentIndex()])));

    ui->showPlayersLabel->setText(ui->showPlayersLabel->text() + ui->nameInput->text() + "\n");

    colorOptions_.erase(colorOptions_.begin() + ui->comboBox->currentIndex());
    ui->nameInput->clear();

    updateColorOptions();



    ui->acceptButton->setEnabled(true);

    if(colorOptions_.size() == 0){
        ui->addPlayersButton->setDisabled(true);
        showMessage("Maximum number of players reached.");
    }

}

void Dialog::showMessage(QString message)
{
    ui->infoLabel->setText(message);
}
