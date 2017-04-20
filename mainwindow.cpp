#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
   QMainWindow(parent),
   ui(new Ui::MainWindow)
   {
   ui->setupUi(this);

   //Set up and start our interval timer (this is used when manually sending position commands and also to poll the position of the rotor
   QTimer *timer = new QTimer(this);
   connect(timer, SIGNAL(timeout()), this, SLOT(runTimer()));
   timer->start(1000);

   //Set up signals for the up and down arrows
   connect(ui->AzContD_down, SIGNAL(clicked()), this, SLOT(AzDD()));
   connect(ui->AzContO_down, SIGNAL(clicked()), this, SLOT(AzDO()));
   connect(ui->AzContT_down, SIGNAL(clicked()), this, SLOT(AzDT()));
   connect(ui->AzContH_down, SIGNAL(clicked()), this, SLOT(AzDH()));
   connect(ui->AzContD_up, SIGNAL(clicked()), this, SLOT(AzUD()));
   connect(ui->AzContO_up, SIGNAL(clicked()), this, SLOT(AzUO()));
   connect(ui->AzContT_up, SIGNAL(clicked()), this, SLOT(AzUT()));
   connect(ui->AzContH_up, SIGNAL(clicked()), this, SLOT(AzUH()));

   connect(ui->ElContD_down, SIGNAL(clicked()), this, SLOT(ElDD()));
   connect(ui->ElContO_down, SIGNAL(clicked()), this, SLOT(ElDO()));
   connect(ui->ElContT_down, SIGNAL(clicked()), this, SLOT(ElDT()));
   connect(ui->ElContH_down, SIGNAL(clicked()), this, SLOT(ElDH()));
   connect(ui->ElContD_up, SIGNAL(clicked()), this, SLOT(ElUD()));
   connect(ui->ElContO_up, SIGNAL(clicked()), this, SLOT(ElUO()));
   connect(ui->ElContT_up, SIGNAL(clicked()), this, SLOT(ElUT()));
   connect(ui->ElContH_up, SIGNAL(clicked()), this, SLOT(ElUH()));

   //Setup display of commanded
   CommandedRotorAz = 0.4;
   CommandedRotorEl = 45.4;
   updateDigitDisplay();

   //Setup TCP/IP portion
   tcpSocket = new QTcpSocket(this);
   networkConnected  = false;
   //inDataStream.setDevice(tcpSocket);
   //inDataStream.setVersion(QDataStream::Qt_4_0);

   //connect all the signals!
   connect(tcpSocket, SIGNAL(connected()), this, SLOT(TCPconnected()));
   connect(tcpSocket, SIGNAL(disconnected()), this, SLOT(TCPdisconnected()));
   connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(parseTCPIncoming()));
   typedef void (QAbstractSocket::*QAbstractSocketErrorSignal)(QAbstractSocket::SocketError);
   connect(tcpSocket, static_cast<QAbstractSocketErrorSignal>(&QAbstractSocket::error),this, &MainWindow::displayError);
   //We really need a second slot for connecting vs reading, but for testing...
   connect(ui->pushButton_Network, SIGNAL(clicked()), this, SLOT(openTCPConnection()));
   connect(ui->pushButton_SendOnce, SIGNAL(clicked()), this, SLOT(sendOnce()));
   connect(ui->pushButton_STOP, SIGNAL(clicked()), this, SLOT(ESTOP()));

   }

MainWindow::~MainWindow()
   {
   delete tcpSocket;
   delete ui;
   }

void MainWindow::AzDD()
   {
   CommandedRotorAz = CommandedRotorAz-0.1;
   updateDigitDisplay(); //OK now update everything
   }

void MainWindow::AzDO()
   {
   CommandedRotorAz = CommandedRotorAz-1;
   updateDigitDisplay(); //OK now update everything
   }

void MainWindow::AzDT()
   {
   CommandedRotorAz = CommandedRotorAz-10;
   updateDigitDisplay(); //OK now update everything
   }

void MainWindow::AzDH()
   {
   CommandedRotorAz = CommandedRotorAz-100;
   updateDigitDisplay(); //OK now update everything
   }

void MainWindow::AzUD()
   {
   CommandedRotorAz = CommandedRotorAz+0.1;
   updateDigitDisplay(); //OK now update everything
   }

void MainWindow::AzUO()
   {
   CommandedRotorAz = CommandedRotorAz+1;
   updateDigitDisplay(); //OK now update everything
   }

void MainWindow::AzUT()
   {
   CommandedRotorAz = CommandedRotorAz+10;
   updateDigitDisplay(); //OK now update everything
   }

void MainWindow::AzUH()
   {
   CommandedRotorAz = CommandedRotorAz+100;
   updateDigitDisplay(); //OK now update everything
   }

void MainWindow::ElDD()
   {
   CommandedRotorEl = CommandedRotorEl-0.1;
   updateDigitDisplay(); //OK now update everything
   }

void MainWindow::ElDO()
   {
   CommandedRotorEl = CommandedRotorEl-1;
   updateDigitDisplay(); //OK now update everything
   }

void MainWindow::ElDT()
   {
   CommandedRotorEl = CommandedRotorEl-10;
   updateDigitDisplay(); //OK now update everything
   }

void MainWindow::ElDH()
   {
   CommandedRotorEl = CommandedRotorEl-100;
   updateDigitDisplay(); //OK now update everything
   }

void MainWindow::ElUD()
   {
   CommandedRotorEl = CommandedRotorEl+0.1;
   updateDigitDisplay(); //OK now update everything
   }

void MainWindow::ElUO()
   {
   CommandedRotorEl = CommandedRotorEl+1;
   updateDigitDisplay(); //OK now update everything
   }

void MainWindow::ElUT()
   {
   CommandedRotorEl = CommandedRotorEl+10;
   updateDigitDisplay(); //OK now update everything
   }

void MainWindow::ElUH()
   {
   CommandedRotorEl = CommandedRotorEl+100;
   updateDigitDisplay(); //OK now update everything
   }

void MainWindow::updateDigitDisplay()
   {
   int AzD,AzO,AzT,AzH;
   int ElD,ElO,ElT,ElH;
   float AbsCRA=fabs(CommandedRotorAz);
   float AbsCRE=fabs(CommandedRotorEl);

   //Azimuth first
   //Break into digits
   AzD = (AbsCRA/1.0 - int(AbsCRA)/1.0) * 10;
   AzO = (AbsCRA/10.0 - int(AbsCRA/10.0)) * 10;
   AzT = (AbsCRA/100.0 - int(AbsCRA/100.0)) * 10;
   AzH = (AbsCRA/1000.0 - int(AbsCRA/1000.0)) * 10;

   //Set the labels to the digits
   ui->AzContD->setText(QString::number(AzD));
   ui->AzContO->setText(QString::number(AzO));
   ui->AzContT->setText(QString::number(AzT));
   ui->AzContH->setText(QString::number(AzH));

   //Set the sign
   if(CommandedRotorAz < 0)
      ui->AzContS->setText("-");
   else
      ui->AzContS->setText("+");

   //Elevation second
   //Break into digits
   ElD = (AbsCRE/1.0 - int(AbsCRE)/1.0) * 10;
   ElO = (AbsCRE/10.0 - int(AbsCRE/10.0)) * 10;
   ElT = (AbsCRE/100.0 - int(AbsCRE/100.0)) * 10;
   ElH = (AbsCRE/1000.0 - int(AbsCRE/1000.0)) * 10;
   //Set the labels to the digits
   ui->ElContD->setText(QString::number(ElD));
   ui->ElContO->setText(QString::number(ElO));
   ui->ElContT->setText(QString::number(ElT));
   ui->ElContH->setText(QString::number(ElH));
   }

void MainWindow::runTimer() //timer expired!
{

      requestRotorPosition();
}

void MainWindow::requestRotorPosition()
   {
   if(networkConnected == true)
      tcpSocket->write("+\\get_pos\n"); //this is a better newer way to do it, because then we can ensure that we know exactly what response we get
   }

void MainWindow::openTCPConnection()
   {
   if(networkConnected  == true)
      {
      tcpSocket->abort();
      ui->pushButton_Network->setText("Connect Network");
      networkConnected  = false;
      }
   else
      {
      ui->pushButton_Network->setText("Connecting...");
   //This is reconnecting literally every time. This is stupid, only connect when the button is pressed and then read on the timer.
   //But this is for testing

      tcpSocket->connectToHost(ui->lineEdit_IPAdd->text(), ui->lineEdit_IPPort->text().toInt());
      }
   }

void MainWindow::TCPconnected()
   {
   //tcpSocket->write("p\r\np\r\n");
   networkConnected  = true;
   ui->pushButton_Network->setText("Disconnect Network");
   }

void MainWindow::TCPdisconnected()
   {
   //tcpSocket->write("p\r\np\r\n");
   networkConnected  = false;
   ui->pushButton_Network->setText("Connect Network");
   }

void MainWindow::displayError(QAbstractSocket::SocketError socketError)
{
    switch (socketError) {
    case QAbstractSocket::RemoteHostClosedError:
        break;
    case QAbstractSocket::HostNotFoundError:
        QMessageBox::information(this, tr("Fortune Client"),
                                 tr("The host was not found. Please check the "
                                    "host name and port settings."));
        break;
    case QAbstractSocket::ConnectionRefusedError:
        QMessageBox::information(this, tr("Fortune Client"),
                                 tr("The connection was refused by the peer. "
                                    "Make sure the fortune server is running, "
                                    "and check that the host name and port "
                                    "settings are correct."));
        break;
    default:
        QMessageBox::information(this, tr("Fortune Client"),
                                 tr("The following error occurred: %1.")
                                 .arg(tcpSocket->errorString()));
    }

    ui->pushButton_Network->setText("Connect Network");
    networkConnected  = false;
}

void MainWindow::ESTOP()
   {
   if(networkConnected  == true)
      {
      tcpSocket->write("S\n");
      }
   }

void MainWindow::sendOnce()
   {
   if(networkConnected  == true)
      {
      tcpSocket->write("P");

      tcpSocket->write(QString::number(CommandedRotorAz).toLocal8Bit());
      tcpSocket->write(" ");
      tcpSocket->write(QString::number(CommandedRotorEl).toLocal8Bit());
      tcpSocket->write("\n");
      }
   }

void MainWindow::parseTCPIncoming()
{
   //this needs to be a state machine that knows which command we just sent, which lines we've already read, and which ones we're waiting for.
   //all commands that make things more report back with an error number (0 is no error) "RPRT 0"

   //Azimuth: 0.000000

   QRegularExpression RegAz("^Azimuth.*(\\d+\\.\\d+)$");
   QRegularExpression RegEl("^Elevation.*(\\d+\\.\\d+$)");
   //QRegularExpression Reg("[^(?<name>\\w+).*(\\d+.\\d+$)]");
   QRegularExpressionMatch *match;

   while (tcpSocket->canReadLine())
      {
      QString TCPLineIn = QString(tcpSocket->readLine());
      /*
          if(RegAz.indexIn(data) >=  0)
            ui->AzReadLabel->setText(data.remove(QRegExp("[\\n\\t\\r]")));
          else if(RegEl.indexIn(data) >= 0)
            ui->ElReadLabel->setText(data.remove(QRegExp("[\\n\\t\\r]")));
            */

      match = new QRegularExpressionMatch(RegAz.match(TCPLineIn));
      if (match->hasMatch())
         {
         ui->AzReadLabel->setText(match->captured(1));
         CurrentRotorAz = match->captured(1).toDouble();
         //qDebug() << TCPLineIn << ":" << match->captured(0) << ":" << match->captured(1) << match->hasMatch();
         }
      delete match;

      match = new QRegularExpressionMatch(RegEl.match(TCPLineIn));
      if (match->hasMatch())
         {
         ui->ElReadLabel->setText(match->captured(1));
         CurrentRotorEl = match->captured(1).toDouble();
         }
      delete match;
      }
   //tcpSocket->readLine(TCPDataIn
   //QString dataIn;
    /*
    ui->AzReadLabel->setText("Data?");
    inDataStream.startTransaction();
    ui->AzReadLabel->setText("Data!");
    //QString nextFortune;
    inDataStream >> dataIn;


    //if (!inDataStream.commitTransaction())
    //    return;
    */
    //Only a successful read will get us this far


    //ui->pushButton_Network->setEnabled(true);
}
