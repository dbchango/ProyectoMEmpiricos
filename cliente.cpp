#include "cliente.h"

Cliente::Cliente(QString nombre, QString cedula, QString telefono, QString direccion):
    cedulaCliente(cedula),
    nombreCliente(nombre),
    telefonoCliente(telefono),
    direccionCliente(direccion){}

Cliente::Cliente(){}

QString Cliente::getCedulaCliente(){
    return cedulaCliente;
}

QString Cliente::getNombreCliente(){
    return nombreCliente;
}

QString Cliente::getTelefonoCliente(){
    return telefonoCliente;
}

QString Cliente::getDireccionCliente(){
    return direccionCliente;
}

void Cliente::setCedulaCliente(QString cedula){
    cedulaCliente = cedula;
}

void Cliente::setNombreCliente(QString nombre){
    nombreCliente = nombre;
}

void Cliente::setTelefonoCliente(QString telefono){
    telefonoCliente = telefono;
}

void Cliente::setDirecionCliente(QString direccion){
    direccionCliente=direccion;
}

