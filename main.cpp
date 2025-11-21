#include "bst.h"
#include <algorithm>

int main() {

    std::string filename;
    std::cout << "ingresa el nombre del archivo a importar: ";
    std::cin >> filename;

    try {
        Importation imp;
        auto ipCount = imp.loadLogs(filename);

        if (ipCount.empty()) {
            std::cout << "El archivo no se importo correctamente" << std::endl;
            return 0;
        }

        BST tree;

        for (const auto& par : ipCount) {
            const std::string& ip = par.first;
            const size_t& accessNum = par.second;
            tree.insert(accessNum, ip);
        }

        size_t k = 5;
        auto topMap = tree.topTier(k);               

        if (topMap.empty()) {
            std::cout << "No se encontraron IPs en la bitácora.\n";
            return 0;
        }

        
        std::vector<std::pair<std::string, std::size_t>> topVec(
            topMap.begin(), topMap.end()
        );

        std::sort(topVec.begin(), topVec.end(),
                  [](const auto& a, const auto& b) {
                      return a.second > b.second; 
                  });

        
        std::cout << "\n===== Top 5 IPs con mas accesos =====\n";
        std::size_t limite = std::min<std::size_t>(5, topVec.size());

        for (std::size_t i = 0; i < limite; ++i) {
            std::cout << i + 1 << ". "
                      << topVec[i].first << " -> "
                      << topVec[i].second << " accesos\n";
        }

    } catch (const std::exception& e) {
        std::cerr << "Error al procesar la bitácora: " << e.what() << '\n';
        return 1;
    }
    

    



    return 0;
}