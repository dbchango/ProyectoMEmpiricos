#ifndef RESERVA_H
#define RESERVA_H

#include <QObject>

class Reserva
{
private:
    int idReserva;
    QString cedulaCliente;
    int numPersonasReserva;
    QString fechaHoraReserva;
    int idMesa;
public:
    Reserva();
    Reserva(int , QString , int , QString , int);
    void setIdReserva(int );
    int getIdReserva();
    void setCedulaCliente(QString );
    QString getCedulaCliente();
    void setNumPersonasReserva(int );
    int getNumPersonasReserva();
    void setFechaHoraReserva(QString );
    QString getFechaHoraReserva();
    void setIdMesa(int );
    int getIdMesa();
};



#endif // RESERVA_H
