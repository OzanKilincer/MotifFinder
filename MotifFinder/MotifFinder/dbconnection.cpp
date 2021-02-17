#include "dbconnection.h"
#include <iostream>

DbConnection::DbConnection(){}

bool DbConnection::postGenome(std::vector<Genome> genomes){

    const QString DRIVER("QSQLITE");
    QSqlDatabase db = QSqlDatabase::addDatabase(DRIVER);

    db.setDatabaseName(this->dbName);

    if(!db.open())
      return false;

    else{

        QSqlQuery query;

        query.prepare("insert into GenomsTable ("
                      "seq,"
                      "loc)"
                      "values(?, ?);");

        db.transaction();

        for(auto it : genomes){

            QString seq = it.getSeq();
            int loc = it.getLoc();

            query.addBindValue(seq);
            query.addBindValue(loc);

            if(!query.exec()){

                qDebug("Error adding values to db");
                return false;
            }
        }

        db.commit();

        //Returning resources
        db.close();

        return true;
    }
}

std::vector<Genome> DbConnection::getGenomes(QString seq){

    std::vector<Genome> genomes;

    const QString DRIVER("QSQLITE");
    QSqlDatabase db = QSqlDatabase::addDatabase(DRIVER);

    db.setDatabaseName(this->dbName);

    if(!db.open()){

        qDebug("Db cannot be opened");
    }

    else{

        qDebug("Db is online");

        QString command = "select * from GenomsTable g where g.seq = '" + seq + "';";

        QSqlQuery query;

        query.exec(command);
        db.transaction();

        while (query.next()) {

            QString seq = query.value(0).toString();
            int loc = query.value(1).toInt();

            Genome g(seq, loc);
            genomes.push_back(g);
        }

        db.commit();

        //Returning resources
        db.close();
    }

    return genomes;
}
