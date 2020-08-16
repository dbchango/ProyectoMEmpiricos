#include "widget.h"
#include "ui_widget.h"
#include <QSqlTableModel>
#include <QSqlError>
#include <QMessageBox>
#include <QSqlQueryModel>
#include "reserva.h"
#include "cliente.h"
#include "menu.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("proyecto1reserva");
    db.setPort(3307);
    db.setUserName("root");
    db.setPassword("root");
    if(!db.open()){
        QMessageBox::critical(this, "Error", db.lastError().text());
    }
    //cargando datos a la tabla de menus
    mModel = new QSqlTableModel(this);
    mModel->setTable("menu");
    mModel->select();
    ui->tableView->setModel(mModel);
    //cargando datos a la tabla de reseras
    mModelReservas = new QSqlTableModel(this);
    mModelReservas->setTable("reserva");
    mModelReservas->select();
    ui->tableView_2->setModel(mModelReservas);
    //cargando datos a la tabla de clientes
    mModelClientes = new QSqlTableModel(this);
    mModelClientes->setTable("cliente");
    mModelClientes->select();
    ui->tablaClientes->setModel(mModelClientes);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void Widget::on_returnMain3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Widget::on_agendarReserv0_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void Widget::on_registroCliente0_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void Widget::on_returnMain4_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Widget::on_returnMain2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Widget::on_returnMain1_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Widget::on_guardarDetalle_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void Widget::on_detalleReserva_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);

}

void Widget::on_buscarCliente_clicked()
{
    QString filtro ="";
    filtro = ui->filtroNoCedula->text();
    if(filtro != ""){
        mModelClientes->setFilter("cedula_cliente = "+filtro);
        mModelClientes->select();
        return;
    }else{
        mModelClientes->setTable("cliente");
        mModelClientes->select();
        return;
    }
}

void Widget::on_actualizarCliente_clicked()
{
    if(ui->cedulaCliente->text()!=""){
        Cliente *cliente = new Cliente();
        cliente->setNombreCliente(ui->nombreCliente->text());
        cliente->setCedulaCliente(ui->cedulaCliente->text());
        cliente->setTelefonoCliente(ui->direccionCliente->text());
        cliente->setDirecionCliente(ui->direccionCliente->text());
        QSqlQueryModel *queryModel = new QSqlQueryModel(this);
        QString query = "update cliente set nombre_cliente='"+cliente->getNombreCliente()+
                "', telefono_cliente='"+cliente->getTelefonoCliente()+
                "', direccion_cliente='"+cliente->getDireccionCliente()+"' where cedula_cliente='"+cliente->getCedulaCliente()+"'";
        queryModel->setQuery(query);
        if(queryModel->lastError().text()!=""){
            QMessageBox::critical(this, "Atención!", queryModel->lastError().text());
            return;
        }else{
            QMessageBox::information(this, "Información", "Cliente actualizado con éxito");
            return;
        }

    }else{
        QMessageBox::critical(this, "Atención!", "No ha ingresado el numero de cedula del cliente");
    }
}

void Widget::on_guardarRegistroCliente_clicked()
{
    if(ui->cedulaCliente->text()!=""){
        Cliente *cliente = new Cliente();
        cliente->setNombreCliente(ui->nombreCliente->text());
        cliente->setCedulaCliente(ui->cedulaCliente->text());
        cliente->setTelefonoCliente(ui->direccionCliente->text());
        cliente->setDirecionCliente(ui->direccionCliente->text());
        QSqlQueryModel *queryModel = new QSqlQueryModel(this);
        QString query = "Insert into cliente values('"+cliente->getCedulaCliente()+
                "','"+cliente->getNombreCliente()+
                "','"+cliente->getTelefonoCliente()+
                "','"+cliente->getDireccionCliente()+"')";
        queryModel->setQuery(query);
        if(queryModel->lastError().text()!=""){
            QMessageBox::critical(this, "Atención!", "Ya existe un cliente registrado con este número de cédula");
            return;
        }else{
            QMessageBox::information(this, "Información", "Cliente registrado con éxito");
            return;
        }

    }else{
        QMessageBox::critical(this, "Atención!", "No ha ingresado el numero de cedula del cliente");
    }
}

void Widget::on_eliminarCliente_clicked()
{

    if(mModelClientes->removeRow(ui->tablaClientes->currentIndex().row())){
        QMessageBox::information(this, "Información", "Registro de cliente eliminado con éxito");
        mModelClientes->select();
        return;
    }else{
        QMessageBox::critical(this, "Atención!", mModelClientes->lastError().text());
        return;
    }


}

void Widget::on_cancelarRegistroCliente_clicked()
{
    ui->cedulaCliente->setText("");
    ui->nombreCliente->setText("");
    ui->telefonoCliente->setText("");
    ui->direccionCliente->setText("");
}

void Widget::on_tablaClientes_activated(const QModelIndex &index)
{
    mModelClientes->setFilter("cedula_cliente=");
}
