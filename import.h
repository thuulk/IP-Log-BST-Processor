#ifndef IMPORT_H
#define IMPORT_H
#include <unordered_map>
#include <string>
#include <fstream>
#include <sstream>

class Importation {

    private:
    std:: string extractIp(const std::string& line) const {
        std::stringstream ss(line);
        std::string month, day, time, ip;

        if (!(ss >> month >> day >> time >> ip)) return "";

        size_t index = ip.find(':'); // indice del string donde esta :
        if (index == -1) return ""; // regresara nada en caso de no encontrar este caracter especial de la ip

        return ip.substr(0, index); // regresar la ip parseada desde el comienzo hasta el : que separa a la ip del protocolo
    }

    public:

    Importation() = default;
    
    std::unordered_map<std::string, size_t> loadLogs(const std::string& filename) const {
        
        /*
        Lee un archivo de bitácora, extrae las IPs y devuelve 
        un unordered_map donde:
            key   = dirección IP
            value = número de accesos
        */
        
        std::unordered_map<std::string, size_t> ipCount; // initialize Hash-Map

        std::ifstream file(filename); // crear un objeto ifstream que lee archivos .txt
        if (!file.is_open()) {
            throw std::runtime_error("File could not be opened");
        }

        std::string line;
        while (std::getline(file, line)) {
            if (line.empty()) continue;

            std::string ip = extractIp(line);
            if (!ip.empty()) {
                ++ipCount[ip];
            }
        }

        file.close();
        return ipCount;
    }
};

#endif 