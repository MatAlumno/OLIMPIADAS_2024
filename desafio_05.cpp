#include <iostream>
#include <vector>

using namespace std;
vector<int> result = {};

bool ascendente(vector<int> arr){  //comprovar si es ascendente
    for(int n = 1; n < arr.size(); n++){
        if(arr[n-1] > arr[n]){
            return false;
        }
    }
    result = arr;
    return true;
}
bool invertirSegmento(vector<int> arr, int start, int end) {
    while (start < end) {
        swap(arr[start], arr[end]); // intercambia el inicio y final del segmento hasta girar
        start += 1;
        end -= 1;
    }
    return ascendente(arr);
}

int main(){
    //arr es un vector jeje
    vector<int> arr = {2,1,3,4};   // ACA CAMBIAR ARREGLO
    int solutions = 0;

    //recorre cada segmento posible
    for (int start = 0; start < arr.size()-1; start++) {
        for (int end = 1+start; end < arr.size(); end++) {
            if (invertirSegmento(arr,start,end)){
                cout << "{";
                for(int num : arr){ cout << num << " ";}
                cout << "}" << endl;
                cout << "SI" << endl;
                cout << start << "  " << end << endl;
                solutions += 1;
            }
        } 
    }
    if(ascendente(arr)){ cout << "SI, ya esta correcta." << endl; }
    else if (solutions == 0){
        cout << "NO" << endl;
    }
    return 0;
}
