#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSqlDatabase>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class QSqlTableModel;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:

    void on_pushButton_2_clicked();

    void on_returnMain3_clicked();

    void on_agendarReserv0_clicked();

    void on_registroCliente0_clicked();

    void on_returnMain4_clicked();

    void on_returnMain2_clicked();

    void on_returnMain1_clicked();

    void on_guardarDetalle_clicked();

    void on_detalleReserva_clicked();

    void on_buscarCliente_clicked();

    void on_actualizarCliente_clicked();

    void on_guardarRegistroCliente_clicked();

    void on_eliminarCliente_clicked();

    void on_cancelarRegistroCliente_clicked();

    void on_tablaClientes_activated(const QModelIndex &index);

private:
    Ui::Widget *ui;
    QSqlTableModel *mModel;
    QSqlTableModel *mModelReservas;
    QSqlTableModel *mModelClientes;
    QSqlDatabase db;
};
#endif // WIDGET_H
