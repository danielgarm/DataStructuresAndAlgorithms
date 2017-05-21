//Daniel Garcia Molero
//Juan Alberto Camino Saez
//Grupo 14

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printDarts(const vector<int> &sectorList, const int &objectivePoints, const vector<vector<int>> &matrix) {
    size_t i = sectorList.size() - 1;
    if(matrix[i + 1][objectivePoints] == 100000) {
        cout << "Imposible" << endl;
        return;
    } else {
       cout << matrix[i + 1][objectivePoints] << ": ";
    }
    int j = objectivePoints;
    while(j > 0){
        if (sectorList[i] <= j && matrix[i + 1][j] == matrix[i + 1][j - sectorList[i]] + 1) {
            cout << sectorList[i];
            j = j - sectorList[i];
            if(j > 0) cout << " ";
            else cout << endl;
        } else {
            --i;
        }
    }
}

//El coste en tiempo y espacio es de O(x*y), donde x es los puntos objetivo e y es el número de sectores.
//Dardos (i, j):
//      Es Dardos(i - 1, j) si Sector(i) > j
//      Es min(Dardos(i - 1, j), Dardos(i, j - Sector(i - 1)) + 1) si Sector(i) <= j
//      Donde 1 <= i <= sectorsNum y 1 <= j <= objectivePoints
//      Casos base: Dardos(i, 0) = 0 y Dardos(0, j) = 100000 (Infinito para nuestro proposito)
//      Dardos se refiere a matrix, y Sector a sectorList
void minDarts(const vector<int> &sectorList, const int &objectivePoints, vector<vector<int>> &matrix) {
    for (int i = 1; i <= sectorList.size(); ++i) {
        matrix[i][0] = 0;
        for (int j = 1; j <= objectivePoints; ++j) {
            if (sectorList[i - 1] > j)
                matrix[i][j] = matrix[i - 1][j];
            else
                matrix[i][j] = min(matrix[i - 1][j], matrix[i][j - sectorList[i - 1]] + 1);
        }
    }
}

bool solve() {
    int objectivePoints, sectorsNum, sectorValue;
    vector<int> sectorList;
    cin >> objectivePoints >> sectorsNum;
    if(!cin) return false;
    for (int i = 0; i < sectorsNum; ++i) {
        cin >> sectorValue;
        sectorList.push_back(sectorValue);
    }
    vector<vector<int>> matrix (sectorsNum + 1, vector<int> (objectivePoints + 1, 100000));
    minDarts(sectorList, objectivePoints, matrix);
    printDarts(sectorList, objectivePoints, matrix);
    return true;
}

int main() {
    while (solve()) {}
    return 0;
}
