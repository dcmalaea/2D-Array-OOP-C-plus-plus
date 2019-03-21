#ifndef MATRICE_H
#define MATRICE_H
#include <ostream>
#include <istream>

using namespace std;

template <class tType>
class Matrice
{
        tType **matrice;
        int nrLinii;
        int nrColoane;
    public:
        //CONSTRUCTORI
        Matrice();
        Matrice(int nrLiniiParam,int nrColoaneParam);
        Matrice(const Matrice<tType>& other);
        //DESTRUCTOR
        virtual ~Matrice();
        //OBTINE NR LINII SI NR COLOANE
        int get_nrLinii()  const  { return nrLinii; }
        int get_nrColoane() const { return nrColoane; }
        //Supraincarcarea operatorilor
        template<class ttType>
        friend ostream &operator<<(ostream& out,const Matrice<ttType> &MatrixToShow);
        template<class ttType>
        friend istream &operator>>(istream& in,Matrice<ttType> &MatrixToRead);

        Matrice<tType> operator+(const Matrice<tType>& MatrixToAdd) const;
        Matrice<tType> operator-(const Matrice<tType>& MatrixToSubtract) const;
        Matrice<tType> operator*(const Matrice<tType>& MatrixToMultiply) const;
        Matrice<tType> operator*(int scalar) const;
        Matrice<tType> &operator=(const Matrice<tType>& MatrixToCopy);
        tType* operator[](int line) const;
        //Calcularea determinantului
        tType get_det() const;
        //Verificare inversabilitate
        bool is_Inversable() const;
        //Eliminare linii si coloane
        void delete_line(int line);
        void delete_column(int column);
        void delete_line_column(int line,int column);

    protected:

    private:
        //Verificare matrice patratica
        bool ePatratica() const;
        //Calcularea determinantului
        tType compute_det(const Matrice<tType> &Matrix) const;
        //Eliminare linii si coloane (intoarce o matrice)
        Matrice<tType> delete_line_p(int line) const;
        Matrice<tType> delete_column_p(int column) const;
        Matrice<tType> delete_line_column_p(int line,int column) const;
};


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

    matrice=new tType*[nrLiniiParam];         //
    for(int i=0;i<nrLiniiParam;i++)           //  Alocare spatiu pentru matrice
        matrice[i]=new tType[nrColoaneParam]; //
}

template <class tType>
Matrice<tType>::~Matrice() //Destructor
{
    if(matrice==NULL)
        return;
    for(int i=0;i<nrLinii;i++)   //
        delete[] matrice[i];      // Eliberare spatiu
    delete[] matrice;             //
}
template <class tType>
Matrice<tType>::Matrice(const Matrice& other) //Constructor de copiere
{
    nrLinii=other.nrLinii;
    nrColoane=other.nrColoane;

    matrice=new tType*[nrLinii];        //
    for(int i=0;i<nrLinii;i++)        // Alocare spatiu
        matrice[i]=new tType[nrColoane];//

    if(matrice!=NULL)
    for(int i=0;i<nrLinii;i++)                 //
        for(int j=0;j<nrColoane;j++)           // Copierea valorior
            matrice[i][j]=other.matrice[i][j]; //
}

template <class tType>
ostream &operator<<(ostream &out,const Matrice<tType> &MatrixToShow) //Supraincarcarea operatorului << (Afisarea valorilor unei matrice)
{
    if(MatrixToShow.matrice!=NULL) //Functionieaza atunci cand matricea este nenula
    {
        for(int i=0;i<MatrixToShow.nrLinii;i++)         //
        {                                               //
            for(int j=0;j<MatrixToShow.nrColoane;j++)   //
                out<<MatrixToShow.matrice[i][j]<<" ";   //
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
            for(int j=0;j<MatrixToRead.nrColoane;j++)//
                in>>MatrixToRead.matrice[i][j];      //
    }
    return in;
}
template <class tType>
Matrice<tType> Matrice<tType>::operator+(const Matrice<tType>& MatrixToAdd) const //Supraincarcarea operatorului + (Adunarea a doua matrice)
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
Matrice<tType> Matrice<tType>::operator-(const Matrice<tType>& MatrixToSubtract) const //Supraincarcarea operatorului - (Scaderea a doua matrice)
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
Matrice<tType> Matrice<tType>::operator*(const Matrice<tType>& MatrixToMultiply) const //Supraincarcarea operatorului * (Inmultirea a doua matrice)
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
Matrice<tType> Matrice<tType>::operator*(int scalar) const //Supraincararea operatorului * (Inmultirea unei matrice cu un scalar)
{
    Matrice<tType> MatrixToReturn(*this); //Matricea ce va fi returnata (identica cu cea initiala)
    for(int i=0;i<MatrixToReturn.nrLinii;i++)         //
        for(int j=0;j<MatrixToReturn.nrColoane;j++)   // Inmultirea elementelor cu nr scalar
            MatrixToReturn.matrice[i][j]*=scalar;     //
    return MatrixToReturn;
}

template <class tType>
Matrice<tType> &Matrice<tType>::operator=(const Matrice<tType>& MatrixToCopy) //Supraincarcarea operatorului = (Copierea valorilor dintr-o matrice in alta)
{
    for(int i=0;i<nrLinii;i++) //
        delete[] matrice[i];   // Eliberare memorie
    delete[] matrice;          //

    nrLinii=MatrixToCopy.nrLinii;
    nrColoane=MatrixToCopy.nrColoane;

    matrice=new tType*[nrLinii];          //
    for(int i=0;i<nrLinii;i++)            // Alocare memorie
        matrice[i]=new tType[nrColoane];  //

    for(int i=0;i<nrLinii;i++)                         //
        for(int j=0;j<nrColoane;j++)                   // Copiere valori
            matrice[i][j]=MatrixToCopy.matrice[i][j];  //

    return *this;
}
template<class tType>
bool Matrice<tType>::ePatratica() const
{
    if(nrLinii==nrColoane)
       return true;
    return false;
}
template <class tType>
tType* Matrice<tType>::operator[](int line) const //Supraincarcarea operatorului [] (Obtinerea liniei i din a unei matrice)
{
    tType *arrayToReturn=new tType[nrColoane]; //Alocam memorie pentru un vector de dimensiunea linei.
    for(int i=0;i<nrColoane;i++)
        arrayToReturn[i]=matrice[line-1][i]; //Copiem elementele liniei in vector
    return arrayToReturn; //Returnam vectorul
}

template <class tType>
Matrice<tType> Matrice<tType>::delete_line_p(int line) const //Stergerea unei linii
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
void Matrice<tType>::delete_line(int line)
{
    *this=(this->delete_line_p(line));
}
template <class tType>
Matrice<tType> Matrice<tType>::delete_column_p(int column) const //Stergerea unei coloane
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
void Matrice<tType>::delete_column(int column)
{
    *this=(this->delete_column_p(column));
}
template <class tType>
Matrice<tType> Matrice<tType>::delete_line_column_p(int line,int column) const //Stergerea unei linii si a unei coloane
{
    Matrice<tType> MatrixToReturn(this->delete_line_p(line));//  Se foloseste functiile anterioare
    MatrixToReturn=MatrixToReturn.delete_column_p(column); //
    return MatrixToReturn;
}
template <class tType>
void Matrice<tType>::delete_line_column(int line,int column)
{
    *this=(this->delete_line_column_p(line,column));
}
template <class tType>
tType Matrice<tType>::get_det() const //Returneaza determinantul
{
    if(this->ePatratica())  //Se verifica daca matricea este patratica
       return compute_det(*this);
}

template <class tType>
tType Matrice<tType>::compute_det(const Matrice<tType> &Matrix) const //Calcularea determinantului recursiv
{
    tType sum=0;
    if(Matrix.get_nrLinii()==2)
           return (Matrix.matrice[0][0]*Matrix.matrice[1][1])-(Matrix.matrice[0][1]*Matrix.matrice[1][0]);
    else
    {
        for(int i=0;i<Matrix.nrLinii;i++)
        {
            tType multiplier=Matrix.matrice[0][i];
            Matrice<tType> TempMatrix=Matrix.delete_line_column_p(1,i+1);
            if(i%2==0)
                sum=sum+multiplier*compute_det(TempMatrix);
            else
                sum=sum-multiplier*compute_det(TempMatrix);
        }
        return sum;
    }
}
template <class tType>
bool Matrice<tType>::is_Inversable() const//Verificare inversabilitatea matricei
{
    if(this->get_det()!=0&&this->ePatratica()) //Daca determinantul este diferit de 0 sI matricea e patratica
          return true;
    return false;
}



#endif // MATRICE_H
