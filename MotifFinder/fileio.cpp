#include "fileio.h"

FileIO::FileIO(){}

QString FileIO::convertToString(char* a, int size){

    QString s = "";

    for (int i = 0; i < size; i++) {

        s = s + a[i];
    }

    return s;
}

std::vector<Genome> FileIO::readFile(){

    std::vector<Genome> genomes;

    //Variables
    int i = 0;
    char* buffer = new char[this->seqLength];
    QString genome;

    //Creating & opening ifstream variable
    std::ifstream txtGenome;
    txtGenome.open(this->filePath, std::ios::in);

    if (txtGenome.is_open()) {

        //Measuring length of the file
        txtGenome.seekg(0, txtGenome.end);
        int length = txtGenome.tellg();
        txtGenome.seekg(0, txtGenome.beg);

        while(i < (length - this->seqLength + 2)){

            txtGenome.read(buffer, this->seqLength);
            genome = convertToString(buffer, this->seqLength);

            Genome g(genome, i);
            genomes.push_back(g);

            i++;

            txtGenome.seekg(i, txtGenome.beg);
        }

        //Returning resources
        txtGenome.close();

        return genomes;
    }

    else{

        Genome g("readFileError", 0);
        genomes.push_back(g);

        return genomes;
    }
}
