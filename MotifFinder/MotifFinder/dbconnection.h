#ifndef DBCONNECTION_H
#define DBCONNECTION_H
#include "genome.h"
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QVariant>
#include <vector>

class DbConnection{
protected:
     QString dbName = "your path to sqlite db";

public:
    DbConnection();

    bool postGenome(std::vector<Genome> genomes);
    std::vector<Genome> getGenomes(QString seq);
    Genome getGenome();
    std::vector<Genome> getGenomes();
};

#endif // DBCONNECTION_H
