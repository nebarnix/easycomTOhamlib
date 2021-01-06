#include "mainwindow.h"
#include "ui_mainwindow.h"

QT_USE_NAMESPACE

MainWindow::MainWindow(QWidget *parent) :
   QMainWindow(parent),
   ui(new Ui::MainWindow)
   {
   ActiveTrack=false;

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
   serialPort = new QSerialPort(this);
   networkConnected  = false;
   ui->AzReadLabel->setEnabled(false);
   ui->ElReadLabel->setEnabled(false);
   serialConnected  = false;
   //inDataStream.setDevice(tcpSocket);
   //inDataStream.setVersion(QDataStream::Qt_4_0);

   //connect all the signals!
   connect(tcpSocket, SIGNAL(connected()), this, SLOT(TCPconnected()));
   connect(tcpSocket, SIGNAL(disconnected()), this, SLOT(TCPdisconnected()));
   connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(parseTCPIncoming()));
   //connect(serialPort, SIGNAL(readyRead()), this, SLOT(parseSerialIncoming()));
   connect(serialPort, &QSerialPort::readyRead, this, &MainWindow::parseSerialIncoming);
   typedef void (QAbstractSocket::*QAbstractSocketErrorSignal)(QAbstractSocket::SocketError);
   connect(tcpSocket, static_cast<QAbstractSocketErrorSignal>(&QAbstractSocket::error),this, &MainWindow::displayError);
   //We really need a second slot for connecting vs reading, but for testing...
   connect(ui->pushButton_Network, SIGNAL(clicked()), this, SLOT(toggleTCPConnection()));
   connect(ui->pushButton_Serial, SIGNAL(clicked()), this, SLOT(toggleSerialConnection()));
   connect(ui->pushButton_SendOnce, SIGNAL(clicked()), this, SLOT(sendOnce()));
   connect(ui->pushButton_STOP, SIGNAL(clicked()), this, SLOT(ESTOP()));
   connect(ui->pushButton_GO, SIGNAL(clicked()), this, SLOT(toggleActiveTracking()));
   connect(ui->pushbutton_AZ2CMD, SIGNAL(clicked()), this, SLOT(AZ2CMD()));
   connect(ui->pushbutton_EL2CMD, SIGNAL(clicked()), this, SLOT(EL2CMD()));

   //Init the polar plot
   //delete(ui->skyPlot); //get rid of the existing plot
   skyPlotObj = new Plot(ui->groupBox1);
   skyPlotObj->setObjectName(QStringLiteral("skyPlot"));
   ui->verticalLayout_2->addWidget(skyPlotObj);

   }

MainWindow::~MainWindow()
   {
   delete tcpSocket;
   delete ui;
   }

void MainWindow::EL2CMD()
   {
   CommandedRotorEl = CurrentRotorEl;
   updateDigitDisplay(); //OK now update everything
   }

void MainWindow::AZ2CMD()
   {
   CommandedRotorAz = CurrentRotorAz;
   updateDigitDisplay(); //OK now update everything
   }

void MainWindow::AzDD()
   {
   CommandedRotorAz = CommandedRotorAz-0.1;
   if(CommandedRotorAz < -999.9)
      CommandedRotorAz = -999.9;
   updateDigitDisplay(); //OK now update everything
   }

void MainWindow::AzDO()
   {
   CommandedRotorAz = CommandedRotorAz-1;
   if(CommandedRotorAz < -999.9)
      CommandedRotorAz = -999.9;
   updateDigitDisplay(); //OK now update everything
   }

void MainWindow::AzDT()
   {
   CommandedRotorAz = CommandedRotorAz-10;
   if(CommandedRotorAz < -999.9)
      CommandedRotorAz = -999.9;
   updateDigitDisplay(); //OK now update everything
   }

void MainWindow::AzDH()
   {
   CommandedRotorAz = CommandedRotorAz-100;
   if(CommandedRotorAz < -999.9)
      CommandedRotorAz = -999.9;
   updateDigitDisplay(); //OK now update everything
   }

void MainWindow::AzUD()
   {
   CommandedRotorAz = CommandedRotorAz+0.1;
   if(CommandedRotorAz > 999.9)
      CommandedRotorAz = 999.9;
   updateDigitDisplay(); //OK now update everything
   }

void MainWindow::AzUO()
   {
   CommandedRotorAz = CommandedRotorAz+1;
   if(CommandedRotorAz > 999.9)
      CommandedRotorAz = 999.9;
   updateDigitDisplay(); //OK now update everything
   }

void MainWindow::AzUT()
   {
   CommandedRotorAz = CommandedRotorAz+10;
   if(CommandedRotorAz > 999.9)
      CommandedRotorAz = 999.9;
   updateDigitDisplay(); //OK now update everything
   }

void MainWindow::AzUH()
   {
   CommandedRotorAz = CommandedRotorAz+100;
   if(CommandedRotorAz > 999.9)
      CommandedRotorAz = 999.9;
   updateDigitDisplay(); //OK now update everything
   }

void MainWindow::ElDD()
   {
   CommandedRotorEl = CommandedRotorEl-0.1;
   if(CommandedRotorEl < 0)
      CommandedRotorEl = 0;
   updateDigitDisplay(); //OK now update everything
   }

void MainWindow::ElDO()
   {
   CommandedRotorEl = CommandedRotorEl-1;
   if(CommandedRotorEl < 0)
      CommandedRotorEl = 0;
   updateDigitDisplay(); //OK now update everything
   }

void MainWindow::ElDT()
   {
   CommandedRotorEl = CommandedRotorEl-10;
   if(CommandedRotorEl < 0)
      CommandedRotorEl = 0;
   updateDigitDisplay(); //OK now update everything
   }

void MainWindow::ElDH()
   {
   CommandedRotorEl = CommandedRotorEl-100;
   if(CommandedRotorEl < 0)
      CommandedRotorEl = 0;
   updateDigitDisplay(); //OK now update everything
   }

void MainWindow::ElUD()
   {
   CommandedRotorEl = CommandedRotorEl+0.1;
   if(CommandedRotorEl > 999.9)
      CommandedRotorEl = 999.9;
   updateDigitDisplay(); //OK now update everything
   }

void MainWindow::ElUO()
   {
   CommandedRotorEl = CommandedRotorEl+1;
   if(CommandedRotorEl > 999.9)
      CommandedRotorEl = 999.9;
   updateDigitDisplay(); //OK now update everything
   }

void MainWindow::ElUT()
   {
   CommandedRotorEl = CommandedRotorEl+10;
   if(CommandedRotorEl > 999.9)
      CommandedRotorEl = 999.9;
   updateDigitDisplay(); //OK now update everything
   }

void MainWindow::ElUH()
   {
   CommandedRotorEl = CommandedRotorEl+100;
   if(CommandedRotorEl > 999.9)
      CommandedRotorEl = 999.9;
   updateDigitDisplay(); //OK now update everything
   }

void MainWindow::updateDigitDisplay()
   {
  // int idx;
   int AzD,AzO,AzT,AzH;
   int ElD,ElO,ElT,ElH;
   //float AbsCRA=fabs(CommandedRotorAz);
   //float AbsCRE=fabs(CommandedRotorEl);
   QString AbsCRA;
   QString AbsCRE;
   AbsCRA.sprintf("%06.1f", fabs(CommandedRotorAz));
   AbsCRE.sprintf("%06.1f", fabs(CommandedRotorEl));

   //qDebug() << QString::number(AbsCRA) << ":" << QString::number(AbsCRE);

   //AbsCRA = round(AbsCRA*10.0)/10.0; //round to the nearest tenth
   //AbsCRE = round(AbsCRE*10.0)/10.0; //round to the nearest tenth
   //qDebug() << AbsCRA << ":" << AbsCRE;
   //Azimuth first
   //Break into digits


   //idx = AbsCRA.indexOf('.');
   AzD = AbsCRA[5].digitValue();
   AzO = AbsCRA[3].digitValue();
   AzT = AbsCRA[2].digitValue();
   AzH = AbsCRA[1].digitValue();

   //AzD = (AbsCRA/1.0 - int(AbsCRA)/1.0) * 10;
   //AzO = (AbsCRA/10.0 - int(AbsCRA/10.0)) * 10;
   //AzT = (AbsCRA/100.0 - int(AbsCRA/100.0)) * 10;
   //AzH = (AbsCRA/1000.0 - int(AbsCRA/1000.0)) * 10;

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


   ElD = AbsCRE[5].digitValue();
   ElO = AbsCRE[3].digitValue();
   ElT = AbsCRE[2].digitValue();
   ElH = AbsCRE[1].digitValue();

   /*
   ElD = (AbsCRE/1.0 - int(AbsCRE)/1.0) * 10;
   ElO = (AbsCRE/10.0 - int(AbsCRE/10.0)) * 10;
   ElT = (AbsCRE/100.0 - int(AbsCRE/100.0)) * 10;
   ElH = (AbsCRE/1000.0 - int(AbsCRE/1000.0)) * 10;*/
   //Set the labels to the digits
   ui->ElContD->setText(QString::number(ElD));
   ui->ElContO->setText(QString::number(ElO));
   ui->ElContT->setText(QString::number(ElT));
   ui->ElContH->setText(QString::number(ElH));
   }

void MainWindow::runTimer() //timer expired!
   {
   sendRotorPosition();
   requestRotorPosition();

   //update the polar plot markers
   if(skyPlotObj)
      {
      //skyPlotObj->markerDDE->setPosition(QwtPointPolar( DDETargetAz, DDETargetEl ) );
      skyPlotObj->markerDDE->setVisible(false);
      skyPlotObj->markerCMD->setPosition(QwtPointPolar( CommandedRotorAz, CommandedRotorEl ) );
      skyPlotObj->markerACT->setPosition(QwtPointPolar( CurrentRotorAz, CurrentRotorEl ) );
      //skyPlotObj->markerACT->setPosition(QwtPointPolar( CommandedRotorAz, CommandedRotorEl ) );
      skyPlotObj->replot();
      }
   }

void MainWindow::sendRotorPosition()
   {
   if(ActiveTrack==true && networkConnected == true)
      {

      tcpSocket->write("P");

      tcpSocket->write(QString::number(CommandedRotorAz).toLocal8Bit());
      tcpSocket->write(" ");
      tcpSocket->write(QString::number(CommandedRotorEl).toLocal8Bit());
      tcpSocket->write("\n");

      }
   }

void MainWindow::toggleActiveTracking()
   {
   if(ActiveTrack == true) //we're tracking, so stop it
      {
      ActiveTrack = false;
      ui->pushButton_GO->setText("Go");
      statusBar()->showMessage(tr("Tracking STOPPED"),10000);
      }
   else if(networkConnected == true) //else enable but only if we have network
      {
      ActiveTrack = true;
      ui->pushButton_GO->setText("Stop");
      statusBar()->showMessage(tr("Serial tracking enabled"),10000);
      }

   }

void MainWindow::requestRotorPosition()
   {
   if(networkConnected == true)
      tcpSocket->write("+\\get_pos\n"); //this is a better newer way to do it, because then we can ensure that we know exactly what response we get
   }

void MainWindow::toggleTCPConnection()
   {
   if(networkConnected  == true) //disconnect if already connected
      {
      tcpSocket->abort();
      ui->pushButton_Network->setText("Connect Network");
      networkConnected  = false;
      ui->AzReadLabel->setEnabled(false);
      ui->ElReadLabel->setEnabled(false);
      ActiveTrack=false;
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
   ui->AzReadLabel->setEnabled(true);
   ui->ElReadLabel->setEnabled(true);

   ui->pushButton_Network->setText("Disconnect Network");
   statusBar()->showMessage(tr("Connected to remote rotor"),10000);
   }

void MainWindow::TCPdisconnected()
   {
   //tcpSocket->write("p\r\np\r\n");
   ActiveTrack=false;
   networkConnected  = false;
   ui->AzReadLabel->setEnabled(false);
   ui->ElReadLabel->setEnabled(false);
   ui->pushButton_Network->setText("Connect Network");
   statusBar()->showMessage(tr("Disconnected from remote rotor"),10000);
   }

void MainWindow::displayError(QAbstractSocket::SocketError socketError)
   {
   switch (socketError) {
   case QAbstractSocket::RemoteHostClosedError:
      break;
   case QAbstractSocket::HostNotFoundError:
      QMessageBox::information(this, tr("easycomTOhamlib"),
                               tr("The host was not found. Please check the "
                                  "host name and port settings."));
      break;
   case QAbstractSocket::ConnectionRefusedError:
      QMessageBox::information(this, tr("easycomTOhamlib"),
                               tr("The connection was refused by the peer. "
                                  "Make sure the fortune server is running, "
                                  "and check that the host name and port "
                                  "settings are correct."));
      break;
   default:
      QMessageBox::information(this, tr("easycomTOhamlib"),
                               tr("The following error occurred: %1.")
                               .arg(tcpSocket->errorString()));
      }

   ui->pushButton_Network->setText("Connect Network");
   statusBar()->showMessage(tr("Error connecting to remote rotor"),10000);
   networkConnected  = false;
   ui->AzReadLabel->setEnabled(false);
   ui->ElReadLabel->setEnabled(false);
   ActiveTrack=false;
   }

void MainWindow::ESTOP()
   {
   ActiveTrack=false;
   if(networkConnected  == true)
      {
      tcpSocket->write("S\n");
      }
   statusBar()->showMessage(tr("Rotor STOPPED!!!"),10000);
   ui->pushButton_GO->setText("Go");

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
      statusBar()->showMessage(tr("Coordinates sent to rotor"),10000);
      }
   else
      statusBar()->showMessage(tr("Rotor not connected"),10000);
   }

void MainWindow::toggleSerialConnection()
   {
   if(serialConnected == false)
      {
      //QSerialPort serialPort;
      //QString serialPortName = argumentList.at(1);
      serialPort->setPortName(ui->lineEdit_serPort->text());

      //int serialPortBaudRate = ui->lineEdit_serPort QSerialPort::Baud19200;
      serialPort->setBaudRate(19200);

      if (!serialPort->open(QIODevice::ReadOnly))
         {
         QMessageBox::information(this, tr("Easycomm2Hamlib"), QObject::tr("Failed to open port %1, error %2").arg(ui->lineEdit_serPort->text()).arg(serialPort->errorString()));
         }
      else
         {
         serialConnected = true;
         ui->pushButton_Serial->setText("Disconnect Serial");
         statusBar()->showMessage(tr("Connected to serial port"),10000);

         ui->AzContD_down->setEnabled(false);
         ui->AzContO_down->setEnabled(false);
         ui->AzContT_down->setEnabled(false);
         ui->AzContH_down->setEnabled(false);

         ui->AzContD_up->setEnabled(false);
         ui->AzContO_up->setEnabled(false);
         ui->AzContT_up->setEnabled(false);
         ui->AzContH_up->setEnabled(false);

         ui->ElContD_down->setEnabled(false);
         ui->ElContO_down->setEnabled(false);
         ui->ElContT_down->setEnabled(false);
         ui->ElContH_down->setEnabled(false);

         ui->ElContD_up->setEnabled(false);
         ui->ElContO_up->setEnabled(false);
         ui->ElContT_up->setEnabled(false);
         ui->ElContH_up->setEnabled(false);

         ui->pushbutton_AZ2CMD->setEnabled(false);
         ui->pushbutton_EL2CMD->setEnabled(false);
         }
      }
   else
      {
      serialPort->close();
      serialConnected = false;
      ui->pushButton_Serial->setText("Connect Serial");
      statusBar()->showMessage(tr("Disconnected from serial port"),10000);

      ui->AzContD_down->setEnabled(true);
      ui->AzContO_down->setEnabled(true);
      ui->AzContT_down->setEnabled(true);
      ui->AzContH_down->setEnabled(true);

      ui->AzContD_up->setEnabled(true);
      ui->AzContO_up->setEnabled(true);
      ui->AzContT_up->setEnabled(true);
      ui->AzContH_up->setEnabled(true);

      ui->ElContD_down->setEnabled(true);
      ui->ElContO_down->setEnabled(true);
      ui->ElContT_down->setEnabled(true);
      ui->ElContH_down->setEnabled(true);

      ui->ElContD_up->setEnabled(true);
      ui->ElContO_up->setEnabled(true);
      ui->ElContT_up->setEnabled(true);
      ui->ElContH_up->setEnabled(true);

      ui->pushbutton_AZ2CMD->setEnabled(true);
      ui->pushbutton_EL2CMD->setEnabled(true);
      }
   }

void MainWindow::parseSerialIncoming()
   {
   //examples from easycomm
   //AZ236 EL0
      //AZ235.3 EL0
      QRegularExpression RegAz("^AZ(-?\\d+\\.?\\d*) EL(-?\\d+\\.?\\d*)\\W*");


   while(serialPort->canReadLine())
      {
      QString SerLineIn = QString(serialPort->readLine());
      //qDebug() << SerLineIn;
      QRegularExpressionMatch match(RegAz.match(SerLineIn));
      if (match.hasMatch())
         {
         CommandedRotorAz = match.captured(1).toDouble();
         CommandedRotorEl = match.captured(2).toDouble();
         updateDigitDisplay();
         }
      }
   }

void MainWindow::parseTCPIncoming()
   {
   //this needs to be a state machine that knows which command we just sent, which lines we've already read, and which ones we're waiting for.
   //all commands that make things more report back with an error number (0 is no error) "RPRT 0"

   //Azimuth: 0.000000

   //feedback from +\get_pos
   //"Azimuth: 30.900000\n"
   //"Elevation: 166.500000\n"
   //"RPRT 0\n"
   QRegularExpression RegAz("^Azimuth: (-?\\d+\\.\\d+)$");
   QRegularExpression RegEl("^Elevation: (-?\\d+\\.\\d+$)");
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
      //qDebug() << TCPLineIn;
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
