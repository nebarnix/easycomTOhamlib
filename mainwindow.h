#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QTcpSocket>
#include <QDataStream>
//#include <QNetworkSession>
#include <QDialog>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
   Q_OBJECT

public:
   explicit MainWindow(QWidget *parent = 0);
   ~MainWindow();

public slots:
   void runTimer();
   void updateDigitDisplay();

   void AzDT();
   void AzDH();
   void AzDO();
   void AzDD();
   void AzUT();
   void AzUH();
   void AzUO();
   void AzUD();
   void ElDT();
   void ElDH();
   void ElDO();
   void ElDD();
   void ElUT();
   void ElUH();
   void ElUO();
   void ElUD();

   void requestRotorPosition();
   void parseTCPIncoming();
   void displayError(QAbstractSocket::SocketError socketError);
   void TCPconnected();
   void TCPdisconnected();

   void toggleTCPConnection();
   void sendOnce();
   void ESTOP();

private:
   Ui::MainWindow *ui;
   float CurrentRotorEl;
   float CurrentRotorAz;
   float CommandedRotorEl;
   float CommandedRotorAz;
   QTcpSocket *tcpSocket;
   //QDataStream inDataStream;
   QString TCPDataIn;
   bool networkConnected;
   //QNetworkSession *networkSession;
};

#endif // MAINWINDOW_H
