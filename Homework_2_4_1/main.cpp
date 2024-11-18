#include <iostream>
#include <fstream>
#include <string>

class Adress{
    private:
        std::string city;
        std::string streat;
        int home;
        int appart;
    public:
        Adress(std::string city = "None", std::string streat = "None", int home = 0, int appart = 0){
            this->city = city;
            this->streat = streat;
            this->home = home;
            this->appart = appart;
        }
        std::string outAdress(){
            return city + ", " + streat + ", " + std::to_string(home) + ", " + std::to_string(appart);
        }
};

void crt_arrAdress(std::string filename, int &count, Adress *& adresses){
    std::ifstream file(filename);
    if(file.is_open()){
        std::string city;
        std::string streat;
        int home;
        int appart;
        file >> count;
        adresses = new Adress[count];
        for (int i = 0; i < count; i++)
        {
            file >> city >> streat >> home >> appart;
            adresses[i] = {city, streat, home, appart};
        }
        file.close();
    }
}

void outAdresses(std::string filename, int &count, Adress * adresses){
    std::ofstream file(filename);
    if(file.is_open())
    {
        file << count << std::endl;
        for(int i = 0; i<count; i++){
            file << adresses[i].outAdress() << std::endl;
        }
    }
    file.close();
}

int main(){
    std::string inFilename = "in.txt";
    std::string outFilename = "out.txt";
    int coutAdress = 0;
    Adress * adresses  = nullptr;
    crt_arrAdress(inFilename, coutAdress, adresses);
    outAdresses(outFilename, coutAdress, adresses);
    delete[]adresses;
}