#include <iostream>
//Deberá de emplearce la busqueda binaria
using namespace std;
int Busqueda(int, int *a, int, int);
int main(){
    int arreglo[] = {1,3,4,5,17,18,31,33};
    int n;
    cout<<"INGRESE EL NUMERO A BUSCAR: ";cin>>n;
    int low = 0;
    int high = 8;
    int buscar = Busqueda(n,arreglo,low,high);
    if (buscar == -1)
    {
        cout<<"El numero "<<n<<" no se encuentra"<<endl;
    }else
    {
        cout<<"El numero "<<n<<" si se encuentra"<<endl;
    }
    
    return 0;
}
int Busqueda(int n, int arreglo[], int start, int end){
    int middle;
    if (start > end)
    {
        return (-1);
    }else {
        middle = (start + end)/2;
    }
    if (n == arreglo[middle])
    {
        return (middle);
    }else if (n < arreglo[middle])
    {
        Busqueda(n,arreglo,start,(middle-1));
        
    }else
    {
        Busqueda(n,arreglo,(middle+1),end);
        
    }
}