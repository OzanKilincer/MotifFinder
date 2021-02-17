#ifndef GENOME_H
#define GENOME_H
#include <QString>

QString convertToString(char* a, int size);

class Genome{
protected:
    //Variables
    QString seq;
    int loc;

public:
    //Constructors
    Genome(QString seq, int loc): seq(seq), loc(loc){}

    //Getter
    QString getSeq(){ return this->seq; }
    int getLoc(){ return this->loc; }
};

#endif // GENOME_H
