#include <iostream>
#include <set>
#include <string>
#include <algorithm>

void flip(char arr[], int i){
    char aux;
    int start = 0;
    while (start < i) {
        aux = arr[start];
        arr[start] = arr[i];
        arr[i] = aux;
        start++;
        i--;
    }
}

bool dfs(std::string curr, std::string end, std::set<std::string>& visited, int depth, int max_depth, int& count){
    visited.insert(curr);
    count++;

    if (curr == end){
        return true;
    }

    if (depth == max_depth){
        return false;
    }

    for (int i = 1; i < curr.size(); i++){
        std::string next = curr;
        flip(&next[0], i);
        if (visited.count(next) == 0){
            if (dfs(next, end, visited, depth+1, max_depth, count)){
                return true;
            }
        }
    }

    return false;
}

int main(){
    std::string pancake = "abcdefghij";
    std::string pancakeEnd = pancake;
    std::random_shuffle(pancake.begin(), pancake.end());
    std::cout << "Pancake desordenado: ";
    std::cout << pancake << std::endl;
    std::cout << std::endl;
    std::set<std::string> visited;
    int count = 0;
    int max_depth = 30; // profundidad máxima de la búsqueda
    bool found = dfs(pancake, pancakeEnd, visited, 0, max_depth, count);
    std::cout << "Pancake: ";
    std::cout << pancake << std::endl;
    std::cout << std::endl;
    std::cout << "Pancake ordenado: ";
    std::cout << pancakeEnd << std::endl;
    std::cout << std::endl;
    if (found){
        std::cout << "Nodos visitados: " << count << std::endl;
    }
    else {
        std::cout << "No se encontro una solucion" << std::endl;
    }
    return 0;
}