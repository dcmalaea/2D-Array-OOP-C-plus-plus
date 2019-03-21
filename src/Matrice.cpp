/*
#include "Matrice.h"
#include <iostream>

using namespace std;

template <class tType>
Matrice<tType>::Matrice() //Constructor fara parametrii
{
    matrice=NULL;
    nrLinii=0;    //Matrice fara valori si dimensiuni
    nrColoane=0;
}
template <class tType>
Matrice<tType>::Matrice(int nrLiniiParam,int nrColoaneParam) //Constructori cu nr de linii si de coloane ca parametrii
{
    nrLinii=nrLiniiParam;
    nrColoane=nrColoaneParam;

    matrice=new int*[nrLiniiParam];         //
    for(int i=0;i<nrLiniiParam;i++)         //  Alocare spatiu pentru matrice
        matrice[i]=new int[nrColoaneParam]; //
}

template <class tType>
Matrice<tType>::~Matrice() //Destructor
{
    for(int i=0;i<nrLinii;i++)  //
        delete[] matrice[i];      // Eliberare spatiu
    delete[] matrice;             //
}
template <class tType>
Matrice<tType>::Matrice(const Matrice& other) //Constructor de copiere
{
    nrLinii=other.nrLinii;
    nrColoane=other.nrColoane;

    matrice=new int*[nrLinii];        //
    for(int i=0;i<nrLinii;i++)        // Alocare spatiu
        matrice[i]=new int[nrColoane];//

    if(matrice!=NULL)
    for(int i=0;i<nrLinii;i++)                 //
        for(int j=0;j<nrColoane;j++)           // Copierea valorior
            matrice[i][j]=other.matrice[i][j]; //
}
template <class tType>
ostream &operator<<(ostream &out,Matrice<tType> &MatrixToShow) //Supraincarcarea operatorului << (Afisarea valorilor unei matrice)
{
    if(MatrixToShow.matrice!=NULL) //Functionieaza atunci cand matricea este nenula
    {
        for(int i=0;i<MatrixToShow.nrLinii;i++)         //
        {                                               //
            for(int j=0;j<MatrixToShow.nrColoane;j++)   //
                out<<MatrixToShow.matrice[i][j]<<" ";   // Parcurgerea valorilor matricei
            out<<"\n";                                  //
        }                                               //
        return out;                                     //
    }
    else //Mesaj de eroare atunci cand matricea este nula
    {
        out<<"Matricea este nula";
        return out;
    }
}

template <class tType>
istream &operator>>(istream &in,Matrice<tType> &MatrixToRead) //Supraincarcarea operatorului >> (Citirea valorilor unei matrice)
{
    int nrLiniiTemp,nrColoaneTemp;
    in>>nrLiniiTemp>>nrColoaneTemp; //citirea dimensiunilor
    Matrice<tType> Temp(nrLiniiTemp,nrColoaneTemp); //creare unei matrici temporare
    MatrixToRead=Temp;

    if(MatrixToRead.nrColoane!=0&&MatrixToRead.nrLinii!=0)
    {

        for(int i=0;i<MatrixToRead.nrLinii;i++)      //
            for(int j=0;j<MatrixToRead.nrColoane;j++)//  Parcurgerea matricei pentru incarcarea valorilor
                in>>MatrixToRead.matrice[i][j];      //
        return in;
    }
}
template <class tType>
Matrice<tType> Matrice<tType>::operator+(Matrice<tType> MatrixToAdd) //Supraincarcarea operatorului + (Adunarea a doua matrice)
{
    if(nrLinii==MatrixToAdd.nrLinii&&nrColoane==MatrixToAdd.nrColoane) //Functioneaza atunci cand matricele au aceleasi dimensiuni
    {
        Matrice<tType> MatrixToReturn(nrLinii,nrColoane);  //Matricea rezultata ce va fi returnata
        for(int i=0;i<nrLinii;i++)
            for(int j=0;j<nrColoane;j++)
                MatrixToReturn.matrice[i][j]=matrice[i][j]+MatrixToAdd.matrice[i][j]; //Incarcarea valorilor in matricea ce va fi returnata
        return MatrixToReturn;
    }
         Matrice<tType> MatrixToReturn;
         return MatrixToReturn;
}

template <class tType>
Matrice<tType> Matrice<tType>::operator-(Matrice<tType> MatrixToSubtract) //Supraincarcarea operatorului - (Scaderea a doua matrice)
{
     if(nrLinii==MatrixToSubtract.nrLinii&&nrColoane==MatrixToSubtract.nrColoane)
     { //Functioneaza atunci cand matricele au aceleasi dimensiuni
        Matrice<tType> MatrixToReturn(nrLinii,nrColoane); //Matricea rezultata ce va fi returnata
        for(int i=0;i<nrLinii;i++)
            for(int j=0;j<nrColoane;j++) //Incarcarea valorilor in matricea ce va fi returnata
                MatrixToReturn.matrice[i][j]=matrice[i][j]-MatrixToSubtract.matrice[i][j];
        return MatrixToReturn;
     }
     else
     {
         Matrice<tType> MatrixToReturn;
         return MatrixToReturn;
     }
}
template <class tType>
Matrice<tType> Matrice<tType>::operator*(Matrice<tType> MatrixToMultiply) //Supraincarcarea operatorului * (Inmultirea a doua matrice)
{
    if(nrColoane==MatrixToMultiply.nrLinii) //Conditia ca matricele sa pot fi inmultite
    {
        Matrice<tType> MatrixToReturn(nrLinii,MatrixToMultiply.nrColoane); //Matricea ce va fi returnata
        for(int i=0;i<nrLinii;i++)                          //
            for(int j=0;j<MatrixToMultiply.nrColoane;j++)   //
               {                                            //  Incarcarea valorilor in matricea ce va fi returnata
                   MatrixToReturn.matrice[i][j]=0;          //
                   for(int k=0;k<nrColoane;k++)             //
                     MatrixToReturn.matrice[i][j]+=matrice[i][k]*MatrixToMultiply.matrice[k][j];
               }
        return MatrixToReturn;
    }
    else
     {
         Matrice<tType> MatrixToReturn;
         return MatrixToReturn;
     }
}

template <class tType>
Matrice<tType> Matrice<tType>::operator*(int scalar) //Supraincararea operatorului * (Inmultirea unei matrice cu un scalar)
{
    Matrice<tType> MatrixToReturn(*this); //Matricea ce va fi returnata (identica cu cea initiala)
    for(int i=0;i<MatrixToReturn.nrLinii;i++)         //
        for(int j=0;j<MatrixToReturn.nrColoane;j++)   // Inmultirea elementelor cu nr scalar
            MatrixToReturn.matrice[i][j]*=scalar;     //
    return MatrixToReturn;
}

template <class tType>
Matrice<tType> Matrice<tType>::operator=(Matrice MatrixToCopy) //Supraincarcarea operatorului = (Copierea valorilor dintr-o matrice in alta)
{
    for(int i=0;i<nrLinii;i++) //
        delete[] matrice[i];   // Eliberare memorie
    delete[] matrice;          //

    nrLinii=MatrixToCopy.nrLinii;
    nrColoane=MatrixToCopy.nrColoane;

    matrice=new int*[nrLinii];          //
    for(int i=0;i<nrLinii;i++)          // Alocare memorie
        matrice[i]=new int [nrColoane]; //

    for(int i=0;i<nrLinii;i++)                         //
        for(int j=0;j<nrColoane;j++)                   // Copiere valori
            matrice[i][j]=MatrixToCopy.matrice[i][j];  //

    return *this;
}

template <class tType>
tType* Matrice<tType>::operator[](int line) //Supraincarcarea operatorului [] (Obtinerea liniei i din a unei matrice)
{
    tType *arrayToReturn=new tType[nrColoane]; //Alocam memorie pentru un vector de dimensiunea linei.
    for(int i=0;i<nrColoane;i++)
        arrayToReturn[i]=matrice[line-1][i]; //Copiem elementele liniei in vector
    return arrayToReturn; //Returnam vectorul
}

template <class tType>
Matrice<tType> Matrice<tType>::delete_line(int line) //Stergerea unei linii
{
    Matrice<tType> MatrixToReturn(nrLinii-1,nrColoane); //Creare matrice cu noile dimensiuni
    for(int i=0;i<line;i++)                                 //
        for(int j=0;j<nrColoane;j++)                        //
            MatrixToReturn.matrice[i][j]=matrice[i][j];     //
    for(int i=line-1;i<nrLinii-1;i++)                       //  Copierea valorilor mai putin linia ce se doreste eliminata
        for(int j=0;j<nrColoane;j++)                        //
            MatrixToReturn.matrice[i][j]=matrice[i+1][j];   //
   return MatrixToReturn;
}

template <class tType>
Matrice<tType> Matrice<tType>::delete_column(int column) //Stergerea unei coloane
{
    Matrice<tType> MatrixToReturn(nrLinii,nrColoane-1); //Creare matrice cu noile dimensiuni
    for(int i=0;i<nrLinii;i++)                              //
        for(int j=0;j<column;j++)                           //
            MatrixToReturn.matrice[i][j]=matrice[i][j];     //
    for(int i=0;i<nrLinii;i++)                              // Copierea valorilor mai putin coloana ce se doreste eliminata
        for(int j=column-1;j<nrColoane;j++)                 //
            MatrixToReturn.matrice[i][j]=matrice[i][j+1];   //
    return MatrixToReturn;
}

template <class tType>
Matrice<tType> Matrice<tType>::delete_line_column(int line,int column) //Stergerea unei linii si a unei coloane
{
    Matrice<tType> MatrixToReturn(this->delete_line(line));//  Se foloseste functiile anterioare
    MatrixToReturn=MatrixToReturn.delete_column(column); //
    return MatrixToReturn;
}
template <class tType>
int Matrice<tType>::get_det() //Returneaza determinantul
{
    if(nrColoane==nrLinii)  //Se calculeaza daca matricea este patratica
       return compute_det(*this);
    else
        return INT_MIN; //EROARE
}
template <class tType>
int Matrice<tType>::compute_det(Matrice<tType> &Matrix) //Calcularea determinantului recursiv
{
    int sum=0;
    if(Matrix.get_nrLinii()==2)
           return (Matrix.matrice[0][0]*Matrix.matrice[1][1])-(Matrix.matrice[0][1]*Matrix.matrice[1][0]);
    else
    {
        for(int i=0;i<Matrix.nrLinii;i++)
        {
            int multiplier=Matrix.matrice[0][i];
            Matrice TempMatrix=Matrix.delete_line_column(1,i+1);
            if(i%2==0)
                sum=sum+multiplier*compute_det(TempMatrix);
            else
                sum=sum-multiplier*compute_det(TempMatrix);
        }
        return sum;
    }
}
template <class tType>
bool Matrice<tType>::is_Inversable() //Verificare inversabilitatea matricei
{
    if(this->get_det()!=0) //Daca determinantul este diferit de 0
          return true;
    return false;
}

*/
