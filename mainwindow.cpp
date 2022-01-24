#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QStandardPaths>
#include <QMessageBox>
#include <QStandardItemModel>
#include <QStandardItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(ui->Home);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_DipendentiPushButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->Dipendenti);
}


void MainWindow::on_HomePushButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->Home);
    ui->B1ComboBox->clear();
    ui->B2ComboBox->clear();
    ui->B3ComboBox->clear();
    ui->B7ComboBox->clear();
    ui->B8ComboBox->clear();
    ui->B9ComboBox->clear();
    ui->C4ComboBox->clear();
}


void MainWindow::on_ProgettiPushButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->Progetti);

    list<DipendenteSenior*> dipendentiSenior = gestore.getDipendentiSenior();

    for(auto d : dipendentiSenior){
        QString dipendente = QString::fromStdString(d->getMatricola()) + " " + QString::fromStdString(d->getNome()) + " " + QString::fromStdString(d->getCognome());
        ui->ResponsabileComboBox->addItem(dipendente);
    }

}

void MainWindow::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->OperazioniDipendenti);
}


void MainWindow::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->OperazioniProgetti);
}


void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->VisualizzaDipendenti);

    ui->DipendentiAllListWidget->clear();

    list<Dipendente*> dipendenti = gestore.getDipendenti();

    for(auto d : dipendenti){
        QString dipendente = QString::fromStdString(d->getMatricola()) + " " + QString::fromStdString(d->getNome()) + " " + QString::fromStdString(d->getCognome());
        ui->DipendentiAllListWidget->addItem(dipendente);
    }

}


void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->VisualizzaProgetti);

    ui->ProgettiListWidget->clear();

    list<Progetto*> progetti = gestore.getProgetti();



    for(auto p : progetti){
        unsigned int posPunto = to_string(p->getBudget()).find(".");
        string budgetStd = to_string(p->getBudget()).substr(0, posPunto + 3);
        QString progetto = QString::fromStdString(p->getNome()) + " " + QString::fromStdString(p->getDataInizio()) + " " + QString::fromStdString(to_string(p->getDurata())) + " " + QString::fromStdString(budgetStd) + " " + QString::fromStdString(p->getResponsabile());
        ui->ProgettiListWidget->addItem(progetto);
    }
}


void MainWindow::on_B1PushButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->B1);

    list<DipendenteSenior*> dipendeteSenior = gestore.getDipendentiSenior();
    for(auto d : dipendeteSenior){
        ui->B1ComboBox->addItem(QString::fromStdString(d->getMatricola()) + " " + QString::fromStdString(d->getNome()) + " " + QString::fromStdString(d->getCognome()));
    }

}


void MainWindow::on_B1ComboBox_currentTextChanged(const QString &arg1)
{
    ui->B1ListWidget->clear();


    string dipendenteSenior = arg1.toStdString();
    unsigned int posSpazio = dipendenteSenior.find(" ");
    string matricola = dipendenteSenior.substr(0, posSpazio);

    list<Progetto*> progetti = gestore.b1(matricola);

    for(auto p : progetti){
        ui->B1ListWidget->addItem(QString::fromStdString(p->getNome()));
    }
}


void MainWindow::on_B2PushButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->B2);

    list<DipendenteJunior*> dipendeteJunior = gestore.getDipendentiJunior();
    for(auto d : dipendeteJunior){
        ui->B2ComboBox->addItem(QString::fromStdString(d->getMatricola()) + " " + QString::fromStdString(d->getNome()) + " " + QString::fromStdString(d->getCognome()));
    }

}

void MainWindow::on_B2ComboBox_currentTextChanged(const QString &arg1)
{

    ui->B2ListWidget->clear();

    string dipendenteJunior = arg1.toStdString();
    unsigned int posSpazio = dipendenteJunior.find(" ");
    string matricola = dipendenteJunior.substr(0, posSpazio);

    list<Progetto*> progetti = gestore.b2(matricola);

    for(auto p : progetti){
        ui->B2ListWidget->addItem(QString::fromStdString(p->getNome()));
    }


}


void MainWindow::on_B3PushButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->B3);

    list<Progetto*> progetti = gestore.getProgetti();
    for(auto p: progetti){
        ui->B3ComboBox->addItem(QString::fromStdString(p->getNome()));
    }

}


void MainWindow::on_B3ComboBox_currentTextChanged(const QString &arg1)
{

    ui->B3ListWidget->clear();

    list<string> skills = gestore.b3(arg1.toStdString());

    for(auto s : skills){
        ui->B3ListWidget->addItem(QString::fromStdString(s));
    }

}



void MainWindow::on_B4PushButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->B4);

    ui->B4ListWidget->clear();

    list<string> skills = gestore.b4();

    for(auto s : skills){
        ui->B4ListWidget->addItem(QString::fromStdString(s));
    }

}


void MainWindow::on_B5PushButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->B5);

    ui->B5ListWidget->clear();

    vector<string> skills = gestore.b5();

    for(auto s : skills){
        ui->B5ListWidget->addItem(QString::fromStdString(s));
    }

}


void MainWindow::on_B6PushButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->B6);

    ui->B6ListWidget->clear();

    list<Progetto*> progetti = gestore.b6();
    for(auto p : progetti){
        ui->B6ListWidget->addItem(QString::fromStdString(p->getNome()));
    }

}


void MainWindow::on_B7PushButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->B7);

    list<DipendenteSenior*> dipendeteSenior = gestore.getDipendentiSenior();
    for(auto d : dipendeteSenior){
        ui->B7ComboBox->addItem(QString::fromStdString(d->getMatricola()) + " " + QString::fromStdString(d->getNome()) + " " + QString::fromStdString(d->getCognome()));
    }

}


void MainWindow::on_B7ComboBox_currentTextChanged(const QString &arg1)
{
    ui->B7ListWidget->clear();

    string dipendenteSenior = arg1.toStdString();
    unsigned int posSpazio = dipendenteSenior.find(" ");
    string matricola = dipendenteSenior.substr(0, posSpazio);

    list<Progetto*> progetti = gestore.b7(matricola);

    for(auto p : progetti){
        ui->B7ListWidget->addItem(QString::fromStdString(p->getNome()));
    }
}


void MainWindow::on_B8PushButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->B8);

    list<DipendenteSenior*> dipendeteSenior = gestore.getDipendentiSenior();
    for(auto d : dipendeteSenior){
        ui->B8ComboBox->addItem(QString::fromStdString(d->getMatricola()) + " " + QString::fromStdString(d->getNome()) + " " + QString::fromStdString(d->getCognome()));
    }

}

void MainWindow::on_B8ComboBox_currentTextChanged(const QString &arg1)
{
    ui->B8ListWidget->clear();

    string dipendenteSenior = arg1.toStdString();
    unsigned int posSpazio = dipendenteSenior.find(" ");
    string matricola = dipendenteSenior.substr(0, posSpazio);

    list<Progetto*> progetti = gestore.b8(matricola);

    for(auto p : progetti){
        ui->B8ListWidget->addItem(QString::fromStdString(p->getNome()));
    }
}



void MainWindow::on_B9PushButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->B9);

    list<DipendenteSenior*> dipendeteSenior = gestore.getDipendentiSenior();
    for(auto d : dipendeteSenior){
        ui->B9ComboBox->addItem(QString::fromStdString(d->getMatricola()) + " " + QString::fromStdString(d->getNome()) + " " + QString::fromStdString(d->getCognome()));
    }

}


void MainWindow::on_B9ComboBox_currentTextChanged(const QString &arg1)
{
    ui->B9lineEdit->clear();

    string dipendenteSenior = arg1.toStdString();
    unsigned int posSpazio = dipendenteSenior.find(" ");
    string matricola = dipendenteSenior.substr(0, posSpazio);

    double media = gestore.b9(matricola);

    unsigned int posPunto = to_string(media).find(".");
    string mediaStd = to_string(media).substr(0, posPunto + 3);

    ui->B9lineEdit->setText(QString::fromStdString(mediaStd));

}

void MainWindow::on_B10PushButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->B10);

    ui->B10ListWidget->clear();

    list<Progetto*> progetti = gestore.b10();

    for(auto p : progetti){
        ui->B10ListWidget->addItem(QString::fromStdString(p->getNome()));
    }
}


void MainWindow::on_B11PushButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->B11);

    ui->B11ListWidget->clear();

    list<Progetto*> progetti = gestore.b11();

    for(auto p : progetti){
        ui->B11ListWidget->addItem(QString::fromStdString(p->getNome()));
    }
}


void MainWindow::on_B12PushButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->B12);

    ui->B12ListWidget->clear();

    list<Progetto*> progetti = gestore.b12();

    for(auto p : progetti){
        ui->B12ListWidget->addItem(QString::fromStdString(p->getNome()));
    }
}


void MainWindow::on_B13PushButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->B13);

    ui->B13ListWidget->clear();

    list<Progetto*> progetti = gestore.b13();

    for(auto p : progetti){
        ui->B13ListWidget->addItem(QString::fromStdString(p->getNome()));
    }
}


void MainWindow::on_B14pushButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->B14);

    ui->B14ListWidget->clear();

    list<Progetto*> progetti = gestore.b14();

    for(auto p : progetti){
        ui->B14ListWidget->addItem(QString::fromStdString(p->getNome()));
    }

}


void MainWindow::on_IndietroPushButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->OperazioniDipendenti);
    ui->B1ComboBox->clear();
}


void MainWindow::on_IndietroPushButton_2_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->OperazioniDipendenti);
    ui->B2ComboBox->clear();
}


void MainWindow::on_IndietroPushButton_3_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->OperazioniDipendenti);
    ui->B3ComboBox->clear();
}


void MainWindow::on_IndietroPushButton_4_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->OperazioniDipendenti);
}


void MainWindow::on_IndietroPushButton_5_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->OperazioniDipendenti);
}


void MainWindow::on_IndietroPushButton_6_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->OperazioniProgetti);
}


void MainWindow::on_IndietroPushButton_7_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->OperazioniProgetti);
    ui->B7ComboBox->clear();
}


void MainWindow::on_IndietroPushButton_8_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->OperazioniProgetti);
    ui->B8ComboBox->clear();
}


void MainWindow::on_IndietroPushButton_9_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->OperazioniProgetti);
    ui->B9ComboBox->clear();
}


void MainWindow::on_IndietroPushButton_10_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->OperazioniProgetti);
}


void MainWindow::on_IndietroPushButton_11_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->OperazioniProgetti);
}


void MainWindow::on_IndietroPushButton_12_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->OperazioniProgetti);
}


void MainWindow::on_IndietroPushButton_13_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->OperazioniProgetti);
}


void MainWindow::on_IndietroPushButton_14_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->OperazioniProgetti);
}


void MainWindow::on_A6PushButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "Apri file", QStandardPaths::writableLocation(QStandardPaths::DesktopLocation), "Text File (*.txt)");

    if(filename.isNull()){
        return;
    }

    QFile inputFile(filename);
    if(inputFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream in(&inputFile);

        QString line = in.readLine();
        while(!line.isNull()){
            QStringList elementi = line.split(";");
            QString tipologiaDato = elementi.at(0);
            if(tipologiaDato == "DJ"){
                QString matricola = elementi.at(1);
                QString nome = elementi.at(2);
                QString cognome = elementi.at(3);
                QString stipendio = elementi.at(4);
                QString skills = elementi.at(5);
                QString matricolaStagista = "";
                if(elementi.size() >= 7){
                    matricolaStagista = elementi.at(6);
                }

                QStringList skillsStringList = skills.split(",");

                string matricolaStd = matricola.toStdString();
                string nomeStd = nome.toStdString();
                string cognomeStd = cognome.toStdString();
                double stipendioStd = stipendio.toDouble();
                list<string> skillsStd;
                for(int i = 0; i < skillsStringList.size(); i++){
                    skillsStd.push_back(skillsStringList.at(i).toStdString());
                }
                string matricolaStagistaStd = "";
                if(elementi.size() >= 7){
                    matricolaStagistaStd = matricolaStagista.toStdString();
                }


                gestore.aggiungiDipendenteJunior(matricolaStd, nomeStd, cognomeStd, stipendioStd, skillsStd, matricolaStagistaStd);

            }else if(tipologiaDato == "DS"){
                QString matricola = elementi.at(1);
                QString nome = elementi.at(2);
                QString cognome = elementi.at(3);
                QString stipendio = elementi.at(4);
                QString reperibilita = elementi.at(5);
                QString subordinati = "";
                if(elementi.size() >= 7){
                    subordinati = elementi.at(6);
                }


                QStringList reperibilitaStringList = reperibilita.split(",");
                QStringList subordinatiStringList = subordinati.split(",");

                string matricolaStd = matricola.toStdString();
                string nomeStd = nome.toStdString();
                string cognomeStd = cognome.toStdString();
                double stipendioStd = stipendio.toDouble();
                list<string> reperibilitaStd;
                for(int i = 0; i < reperibilitaStringList.size(); i++){
                    reperibilitaStd.push_back(reperibilitaStringList.at(i).toStdString());
                }
                list<string> subordinatiStd;
                if(elementi.size() >= 7){
                    for(int i = 0; i < subordinatiStringList.size(); i++){
                        subordinatiStd.push_back(subordinatiStringList.at(i).toStdString());
                    }
                }
                gestore.aggiungiDipendenteSenior(matricolaStd, nomeStd, cognomeStd, stipendioStd, reperibilitaStd, subordinatiStd);

            }else{

                QString nome = elementi.at(1);
                QString data = elementi.at(2);
                QString durata = elementi.at(3);
                QString budget = elementi.at(4);
                QString matricolaResponsabile = elementi.at(5);

                string nomeStd = nome.toStdString();
                string dataStd = data.toStdString();
                int durataStd = durata.toInt();
                double budgetStd = budget.toDouble();
                string matricolaResponsabileStd = matricolaResponsabile.toStdString();

                gestore.aggiungiProgetto(nomeStd, dataStd, durataStd, budgetStd, matricolaResponsabileStd);

            }

            line = in.readLine();
        }
        statusBar()->showMessage("Dati aggiunti!", 3000);
    }else{
        QMessageBox::critical(this, "Errore", "Impossibile aprire il file" + filename + ": " + inputFile.errorString());
    }
}

void MainWindow::on_pushButton_8_clicked()
{
    ui->SubordinatilistWidget->clear();

    list<DipendenteJunior*> dipendentiJunior = gestore.getDipendentiJunior();
    int index = 0;

    for(auto d : dipendentiJunior){
        QString dipendenteJunior = QString::fromStdString(d->getMatricola()) + " " + QString::fromStdString(d->getNome()) + " " + QString::fromStdString(d->getCognome());
        ui->SubordinatilistWidget->addItem(dipendenteJunior);
        ui->SubordinatilistWidget->item(index)->setCheckState(Qt::Unchecked);
        index++;
    }
}

void MainWindow::on_AggiungiDSPushButton_clicked()
{
    if(ui->MatricolaDSLineEdit->text().isEmpty() || ui->NomeDSLineEdit->text().isEmpty() || ui->CognomeDSLineEdit->text().isEmpty() || ui->StipendioDSDoubleSpinBox->value() == 0.0 ||(!ui->LunCheckBox->isChecked() && !ui->MarCheckBox->isChecked() &&
                                                                                           !ui->MerCheckBox->isChecked() && !ui->GioCheckBox->isChecked() &&
                                                                                           !ui->VenCheckBox->isChecked() && !ui->SabCheckBox->isChecked() &&
                                                                                           !ui->DomCheckBox->isChecked())){
        QMessageBox errore(QMessageBox::Critical, "Errore", "Ci sono campi vuoti!", QMessageBox::Ok, this);
        errore.exec();
        return;
    }
    string matricola = ui->MatricolaDSLineEdit->text().toStdString();
    string nome = ui->NomeDSLineEdit->text().toStdString();
    string cognome = ui->CognomeDSLineEdit->text().toStdString();
    double stipendio = ui->StipendioDSDoubleSpinBox->value();
    QStringList giorni;
    if(ui->LunCheckBox->isChecked()){
        giorni.append("lun");
    }
    if(ui->MarCheckBox->isChecked()){
        giorni.append("mar");
    }
    if(ui->MerCheckBox->isChecked()){
        giorni.append("mer");
    }
    if(ui->GioCheckBox->isChecked()){
        giorni.append("gio");
    }
    if(ui->VenCheckBox->isChecked()){
        giorni.append("ven");
    }
    if(ui->SabCheckBox->isChecked()){
        giorni.append("sab");
    }
    if(ui->DomCheckBox->isChecked()){
        giorni.append("dom");
    }
    list<string> giorniStd;
    for(int i = 0; i < giorni.size(); i++){
        giorniStd.push_back(giorni.at(i).toStdString());
    }

    list<string> subordinati;

    for(int i = 0; i < ui->SubordinatilistWidget->count(); i++){
        if(ui->SubordinatilistWidget->item(i)->checkState() == Qt::Checked){
            string subordinato = ui->SubordinatilistWidget->item(i)->text().toStdString();
            unsigned int posSpazio = subordinato.find(" ");
            string matricolaSubordinato = subordinato.substr(0, posSpazio);
            subordinati.push_back(matricolaSubordinato);
        }
    }

    gestore.aggiungiDipendenteSenior(matricola, nome, cognome, stipendio, giorniStd, subordinati);
    statusBar()->showMessage("Dipendente Senior aggiunto!", 3000);
    ui->MatricolaDSLineEdit->clear();
    ui->NomeDSLineEdit->clear();
    ui->CognomeDSLineEdit->clear();
    ui->StipendioDSDoubleSpinBox->setValue(0);
    ui->LunCheckBox->setChecked(false);
    ui->SubordinatilistWidget->clear();
}

void MainWindow::on_StagistaComboBox_currentTextChanged(const QString &arg1)
{
    ui->SupervisoreComboBox->clear();
    if(arg1 == "Si"){
        list<DipendenteJunior*> dipendetiJunior = gestore.getDipendentiJunior();
        for(auto d : dipendetiJunior){
            ui->SupervisoreComboBox->addItem(QString::fromStdString(d->getMatricola()) + " " + QString::fromStdString(d->getNome()) + " " + QString::fromStdString(d->getCognome()));
        }
    }

}

void MainWindow::on_AggiungiDJpushButton_clicked()
{

    if(ui->MarticolaDJLineEdit->text().isEmpty() || ui->NomeDJLineEdit->text().isEmpty() || ui->CognomeDJLineEdit->text().isEmpty() || ui->StipendioDJDoubleSpinBox->value() == 0 || ui->SkillLineEdit->text().isEmpty()){
        QMessageBox errore(QMessageBox::Critical, "Errore", "Ci sono campi vuoti!", QMessageBox::Ok, this);
        errore.exec();
        return;
    }

    string matricola = ui->MarticolaDJLineEdit->text().toStdString();
    string nome = ui->NomeDJLineEdit->text().toStdString();
    string cognome = ui->CognomeDJLineEdit->text().toStdString();
    double stipendio = ui->StipendioDJDoubleSpinBox->value();
    string matricolaSupervisore;
    if(ui->StagistaComboBox->currentText() == "Si"){
        string supervisore = ui->SupervisoreComboBox->currentText().toStdString();
        unsigned int posSpazio = supervisore.find(" ");
        matricolaSupervisore = supervisore.substr(0, posSpazio);
    }

    QStringList skills = ui->SkillLineEdit->text().split(",");
    list<string> skillsStd;
    for(int i = 0; i < skills.size(); i++){
        skillsStd.push_back(skills.at(i).toStdString());
    }

    gestore.aggiungiDipendenteJunior(matricola, nome, cognome, stipendio, skillsStd, matricolaSupervisore);
    statusBar()->showMessage("Dipendente Junior aggiunto!", 3000);
    ui->MarticolaDJLineEdit->clear();
    ui->NomeDJLineEdit->clear();
    ui->CognomeDJLineEdit->clear();
    ui->StipendioDJDoubleSpinBox->setValue(0);
    ui->StagistaComboBox->clear();
    ui->SupervisoreComboBox->clear();
    ui->SkillLineEdit->clear();

}

void MainWindow::on_pushButton_2_clicked()
{
    if(ui->NomeProglineEdit->text().isEmpty() || ui->DataIniziodateEdit->text().isEmpty() || ui->DurataSpinBox->value() == 0 || ui->BudgetProgDoubleSpinBox->value() == 0){
        QMessageBox errore(QMessageBox::Critical, "Errore", "Ci sono campi vuoti!", QMessageBox::Ok, this);
        errore.exec();
        return;
    }

    string nome = ui->NomeProglineEdit->text().toStdString();
    string dataInizio = ui->DataIniziodateEdit->text().toStdString();
    int durata = ui->DurataSpinBox->value();
    double budget = ui->BudgetProgDoubleSpinBox->value();

    string responsabile = ui->ResponsabileComboBox->currentText().toStdString();
    unsigned int posSpazio = responsabile.find(" ");
    string matricolaResponsabile = responsabile.substr(0, posSpazio);

    gestore.aggiungiProgetto(nome, dataInizio, durata, budget, matricolaResponsabile);
    statusBar()->showMessage("Progetto aggiunto!", 3000);
    ui->NomeProglineEdit->clear();
    ui->DataIniziodateEdit->clear();
    ui->DurataSpinBox->setValue(0);
    ui->BudgetProgDoubleSpinBox->setValue(0);

}

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->OperazioniSpeciali);
}

void MainWindow::on_pushButton_9_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->C1);

    ui->C1ListWidget->clear();

    list<string> skillsGuadagnoPiualto = gestore.c1();

    for(auto s : skillsGuadagnoPiualto){
        ui->C1ListWidget->addItem(QString::fromStdString(s));
    }
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->OperazioniSpeciali);
}




void MainWindow::on_pushButton_10_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->C2);

    ui->C2ListWidget->clear();

    list<DipendenteSenior*> dipendentiSeniorIndispensabili = gestore.c2();

    for(auto d : dipendentiSeniorIndispensabili){
        ui->C2ListWidget->addItem(QString::fromStdString(d->getMatricola() + " " + d->getNome() + " " + d->getCognome()));
    }

}


void MainWindow::on_pushButton_11_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->OperazioniSpeciali);
}


void MainWindow::on_pushButton_13_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->C4);

    list<Progetto*> progetti = gestore.getProgetti();

    for(auto p: progetti){
        ui->C4ComboBox->addItem(QString::fromStdString(p->getNome()));
    }

}

void MainWindow::on_C4ComboBox_currentTextChanged(const QString &arg1)
{
    ui->C4ListWidget->clear();

    list<Progetto*> progetti = gestore.c4(arg1.toStdString());

    for(auto p : progetti){
        ui->C4ListWidget->addItem(QString::fromStdString(p->getNome()));
    }

}



void MainWindow::on_IndietroPushButton_15_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->OperazioniSpeciali);
    ui->C4ComboBox->clear();

}

