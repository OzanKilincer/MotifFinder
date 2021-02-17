#ifndef FILEIO_H
#define FILEIO_H
#include "genome.h"
#include <fstream>
#include <vector>

class FileIO{
protected:
    std::string filePath;
    int seqLength;

public:
    FileIO();
    FileIO(std::string filePath, unsigned int seqLength): filePath(filePath), seqLength(seqLength){}

    //Setters
    void setFile(std::string filePath){ this->filePath = filePath;}
    void setSize(int seqLength){ this->seqLength = seqLength;}

    QString convertToString(char* a, int size);

    std::vector<Genome> readFile();
};

#endif // FILEIO_H
