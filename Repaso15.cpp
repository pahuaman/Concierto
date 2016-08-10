#include <iostream>
#include <limits>

using namespace std;

class Concierto
{
protected:
    string Auditorio;
    string Grupo;
    int    Duracion;

public:
    Concierto(){} //constructor sin parametros

    Concierto(string auditorio, string grupo, int duracion)
    {
        Auditorio = auditorio;
        Grupo     = grupo;
        Duracion  = duracion;
    }//constructor

    void ImprimirConc()
    {
        cout<<"\nNombre del Auditorio "     <<Auditorio
            <<"\nGrupo  que se presenta "   <<Grupo
            <<"\nDuracion del evento Aprox."<<Duracion<<endl;

    }//funcion para imprimir datos
};

class Boleto
{
protected:
    float  Costo;
    string noFolio;
    string Dir;

public:
    Boleto(){}//constructor sin parametros
    Boleto(float costo, string nofolio, string dir)
    {
        Costo   = costo;
        noFolio = nofolio;
        Dir     = dir;
    }//constructor

    void ImprimirBoleto()
    {
        cout<<"\nCosto del boleto "        <<Costo
            <<"\nNumero de folio "         <<noFolio
            <<"\nLugar de la presentacion" <<Dir<<endl;
    }//impresion de datos
};

class PuntoDeVenta: public Concierto, public Boleto
{
private:
    string Descrip;
    string FechaEv;
    string HoraEv;

public:
    PuntoDeVenta(){}
    PuntoDeVenta(string Auditorio, string Grupo, int Duracion,
                 float Costo, string noFolio, string Dir,
                 string descrip, string fechaev, string horaev):
                 Concierto(Auditorio, Grupo, Duracion), Boleto(Costo, noFolio, Dir)
                 {
                     Descrip = descrip;
                     FechaEv = fechaev;
                     HoraEv  = horaev;
                 }//constructor

    void Imprime()
    {
        cout<<"\nDescripcion breve "<<Descrip
            <<"\nFecha del evento " <<FechaEv
            <<"\nHora del evento"   <<HoraEv<<endl;
    }//imprimir los datos

};


PuntoDeVenta Captura()
{
    string nombreAu, grupo, folio, dir, descrip, fechaEv, horaEv;
    int    duracion;
    float  costo;

    cout<<"\nNombre del auditorio: ";  getline(cin, nombreAu);
    cout<<"Grupo que se presentara: "; getline(cin, grupo);
    cout<<"Duracion del evento: ";     cin>>duracion;
    cin.ignore(numeric_limits <streamsize> ::max(), '\n'); //se necesita incluir la libreria <limits>
    cout<<"Costo del boleto: ";        cin>>costo;
    cin.ignore(numeric_limits <streamsize> ::max(), '\n');
    cout<<"Numero de folio: ";         getline(cin, folio);
    cout<<"Lugar del evento: ";        getline(cin, dir);
    cout<<"Descripcion del evento: ";  getline(cin, descrip);
    cout<<"Fecha del evento: ";        getline(cin, fechaEv);
    cout<<"Hora del evento: ";         getline(cin, horaEv);

    PuntoDeVenta Venta(nombreAu, grupo, duracion, costo, folio, dir, descrip, fechaEv, horaEv);

    return Venta;

}//funcion para capturar


int main()
{
    PuntoDeVenta Venta01;

    Venta01 = Captura();

    cout<<"\n\n\t\tDetalles de la venta "<<endl<<endl;
    Venta01.Imprime();
    Venta01.ImprimirConc();
    Venta01.ImprimirBoleto();

    return 0;

}//main

