#include "reserva.h"

Reserva::Reserva()
{

}

Reserva::Reserva(int id,QString cedula, int numPersonas, QString fechaHora, int idmesa)
    :idReserva(id),cedulaCliente(cedula), numPersonasReserva(numPersonas), fechaHoraReserva(fechaHora), idMesa(idmesa){
}

int Reserva::getIdReserva(){
    return idReserva;
}

QString Reserva::getCedulaCliente(){
    return cedulaCliente;
}

int Reserva::getNumPersonasReserva(){
    return numPersonasReserva;
}

QString Reserva::getFechaHoraReserva(){
    return fechaHoraReserva;
}

int Reserva::getIdMesa(){
    return idMesa;
}

void Reserva::setIdMesa(int idmesa){
    idMesa = idmesa;
}

void Reserva::setIdReserva(int id){
    idReserva = id;
}

void Reserva::setCedulaCliente(QString cedula){
    cedulaCliente = cedula;
}

void Reserva::setFechaHoraReserva(QString fecha){
    fechaHoraReserva = fecha;
}

void Reserva::setNumPersonasReserva(int numPersonas){
    numPersonasReserva = numPersonas;
}








