#include <iostream>
#include <cstring>
#include <string.h>

using namespace std;
const int longCad = 20;
struct costoPorArticulo{
    char nombreArticulo[longCad + 1]; //Cantidad de carácteres + 1, que corresponde al carácter especial de fin de cadena
    int cantidad;
    float precio;
    float costoPorArt;
}; 
float PedirInformacion(int n, costoPorArticulo articulo[]){
    string nombre;//Se declara la variable en que recibirá el nombre del artículo
    for (int i = 0; i < n; i++)
    {
        cout<<"Nombre del articulo a pagar: ";
        getline(cin,nombre, '\n');//Se emplea el getline por si se requiere un nombre con espacios, como Leche de soya
        strncpy(articulo[i].nombreArticulo,nombre.c_str( ),longCad);/*Se copia el nombre ingresado en el campo del arreglo: articulo[i]
        indicando que no debe de exceder 20 espacios*/
        articulo[i].nombreArticulo[longCad]='\0';//el último espacio se guarda para el carácter especial de fin de cadena
        cout<<"Introduzca la cantidad que lleva del articulo: ";cin>>articulo[i].cantidad;
        cout<<"Introduzca el precio del articulo: ";cin>>articulo[i].precio;
        cin.ignore(100,'\n');//Es utilizado para quitar el buffer del teclado
    }
    
}
float CostoxArticulo(int n, costoPorArticulo articulo[]){
    for (int i = 0; i < n; i++)
    {
        articulo[i].costoPorArt = (articulo[i].cantidad)*(articulo[i].precio);
        //El articulo[i].costoPorArt irá almacenando el producto para obtener el costo total del producto
    }
}
float MostrarInformacion(int n, costoPorArticulo articulo[]){
    cout<<"-----------------FACTURA DE COMPRA-------------------"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<articulo[i].nombreArticulo<<endl;
        cout<<articulo[i].cantidad<<" x "<<articulo[i].precio<<" = "<<articulo[i].costoPorArt<<endl;
    }
    
}
float CostoTotal(int n, costoPorArticulo articulo[]){
    float total;
    for (int i = 0; i < n; i++)
    {
        total = total + articulo[i].costoPorArt;
    }
    return total;
}
int main(){
    int n;

    cout<<"-----------------SUPERMERCADO------------------"<<endl;
    cout<<"Introduzca la cantidad de articulos a pagar: ";cin>>n;
    cin.ignore(100,'\n');
    costoPorArticulo Articulo[n];
    PedirInformacion(n,Articulo);
    CostoxArticulo(n, Articulo);
    MostrarInformacion(n, Articulo);
    cout<<"TOTAL A PAGAR: $"<<CostoTotal(n,Articulo);
    return 0;
}
