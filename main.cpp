#include <iostream>
#include <fstream>
#include "Matrice.h"

//Compiler: GNU GCC Compiler

using namespace std;

int main()
{
    ifstream file("date.in");
    Matrice<double> MatriceTest,MatriceTest1,MatriceTest2;
    file>>MatriceTest1>>MatriceTest2;
    cout<<"Matricea initiala 1: "<<endl;
    cout<<MatriceTest1<<endl;
    cout<<"Matricea initiala 2: "<<endl;
    cout<<MatriceTest2<<endl;
    cout<<"Adunarea + "<<endl;
    MatriceTest=MatriceTest1+MatriceTest2;
    cout<<MatriceTest<<endl;
    cout<<"Afisarea unei linii "<<endl;
    double *p=new double[MatriceTest.get_nrColoane()];
    p=MatriceTest[2];
    for(int i=0;i<MatriceTest.get_nrColoane();i++)
        cout<<p[i]<<" ";
    cout<<endl<<endl;
    cout<<"Scaderea -"<<endl;
    MatriceTest=MatriceTest1-MatriceTest2;
    cout<<MatriceTest<<endl;
    cout<<"Inmultirea *"<<endl;
    MatriceTest=MatriceTest1*MatriceTest2;
    cout<<MatriceTest<<endl;
    cout<<"Determinantul primei matrici"<<endl;
    cout<<MatriceTest1.get_det()<<endl;
    cout<<"Verificare inversabilitatea primei matrici"<<endl;
    cout<<MatriceTest1.is_Inversable()<<endl;
    cout<<"Eliminarea primei linii a primei matrici"<<endl;
    MatriceTest1.delete_line(1);
    MatriceTest=MatriceTest1;
    cout<<MatriceTest<<endl;
    cout<<"Eliminarea primei coloane a primei matrici"<<endl;
    MatriceTest1.delete_column(1);
    MatriceTest=MatriceTest1;
    cout<<MatriceTest<<endl;
    cout<<"Eliminarea primei linii si primei coloane a primei matrici"<<endl;
    MatriceTest1.delete_line_column(1,1);
    MatriceTest=MatriceTest1;
    cout<<MatriceTest<<endl;
    cout<<"Nr. de linii a primei matrici"<<endl;
    cout<<MatriceTest1.get_nrLinii()<<endl;
    cout<<"Nr. de coloane a primei matrici"<<endl;
    cout<<MatriceTest1.get_nrColoane()<<endl;
    return 0;
}
