#ifndef CLIENTE_H
#define CLIENTE_H
#include <QObject>
#include <QDate>

class QSqlTableModel;

class Cliente
{
public:
    Cliente();
    Cliente(QString, QString, QString, QString);
    void setNombreCliente(QString);
    void setCedulaCliente(QString);
    void setTelefonoCliente(QString);
    void setDirecionCliente(QString);
    QString getNombreCliente();
    QString getCedulaCliente();
    QString getTelefonoCliente();
    QString getDireccionCliente();
    QSqlTableModel *mModelClientes;
    bool buscarCliente(QString);
private:
    QString cedulaCliente;
    QString nombreCliente;
    QString telefonoCliente;
    QString direccionCliente;
};

#endif // CLIENTE_H
