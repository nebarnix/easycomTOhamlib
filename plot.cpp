#include "plot.h"
#include "ui_mainwindow.h"

Plot::Plot( QWidget *parent ):
    //QwtPolarPlot( QwtText( "SkyPlot" ), parent )
   QwtPolarPlot( parent )
   {
   setAutoReplot( false );
   //setPlotBackground( Qt::darkBlue );



   // scales
   setScale( QwtPolar::Azimuth, 360, 0, 90 );
   setScaleMaxMinor( QwtPolar::Azimuth, 2 );


   setScale( QwtPolar::Radius, 90, 0);
   setScaleMaxMinor( QwtPolar::Radius, 2 );
   setScaleMaxMajor( QwtPolar::Radius, 5 );

   //Rotate
   setAzimuthOrigin (M_PI_2);

   // grids
   d_grid = new QwtPolarGrid();
   d_grid->setPen( QPen( Qt::black ) );
   for ( int scaleId = 0; scaleId < QwtPolar::ScaleCount; scaleId++ )
      {
      d_grid->showGrid( scaleId );
      d_grid->showMinorGrid( scaleId );

      QPen minorPen( Qt::gray );
      d_grid->setMinorGridPen( scaleId, minorPen );
      }

   d_grid->setAxisPen( QwtPolar::AxisAzimuth, QPen( Qt::black ) );
   d_grid->setAxisPen( QwtPolar::Radius, QPen( Qt::gray ) );
   //d_grid->setAzimuthScaleDraw( new AzimuthScaleDraw() );
   d_grid->showAxis( QwtPolar::AxisAzimuth, false );
   d_grid->showAxis( QwtPolar::AxisLeft, false );
   d_grid->showAxis( QwtPolar::AxisRight, false );
   d_grid->showAxis( QwtPolar::AxisTop, true );
   d_grid->showAxis( QwtPolar::AxisBottom, false );
   d_grid->showGrid( QwtPolar::Azimuth, true );
   d_grid->showGrid( QwtPolar::Radius, true );
   d_grid->attach( this );

   //configure target marker
   markerDDE = new QwtPolarMarker();
   //markerTest->setSymbol( QwtSymbol( QwtSymbol::Diamond, Qt::red, Qt::NoPen, QSize( 10, 10 ) ) );
   //markerTest->setSymbol( QwtSymbol(QwtSymbol::Diamond,QBrush(Qt::red),QPen(Qt::red),QSize(5,5)) );
   markerDDE->setSymbol( new QwtSymbol( QwtSymbol::Ellipse, QBrush( Qt::green ), QPen( Qt::green ), QSize( 9, 9 ) ) );
   markerDDE->setLabelAlignment( Qt::AlignHCenter | Qt::AlignTop );
   markerDDE->setLabel( QwtText( "DDE" ));
   markerDDE->setPosition(QwtPointPolar( 45, 45 ) );
   markerDDE->attach( this );
   markerDDE->setZ(1);

   //configure CMD marker (a circle!)
   markerCMD = new QwtPolarMarker();
   //markerTest->setSymbol( QwtSymbol( QwtSymbol::Diamond, Qt::red, Qt::NoPen, QSize( 10, 10 ) ) );
   //markerTest->setSymbol( QwtSymbol(QwtSymbol::Diamond,QBrush(Qt::red),QPen(Qt::red),QSize(5,5)) );
   markerCMD->setSymbol( new QwtSymbol( QwtSymbol::Ellipse, QBrush( Qt::transparent ), QPen( Qt::red ), QSize( 9, 9 ) ) );
   markerCMD->setLabelAlignment( Qt::AlignHCenter | Qt::AlignTop );
   markerCMD->setLabel( QwtText( "CMD" ));
   markerCMD->setPosition(QwtPointPolar( 90+45, 45 ) );
   markerCMD->attach( this );
   markerDDE->setZ(2);

   //configure ACT marker (an X!)
   markerACT = new QwtPolarMarker();
   //markerTest->setSymbol( QwtSymbol( QwtSymbol::Diamond, Qt::red, Qt::NoPen, QSize( 10, 10 ) ) );
   //markerTest->setSymbol( QwtSymbol(QwtSymbol::Diamond,QBrush(Qt::red),QPen(Qt::red),QSize(5,5)) );
   markerACT->setSymbol( new QwtSymbol( QwtSymbol::Star1, QBrush( Qt::transparent ), QPen( Qt::black ), QSize( 9, 9 ) ) );
   markerACT->setLabelAlignment( Qt::AlignHCenter | Qt::AlignBottom );
   markerACT->setLabel( QwtText( "ACT" ));
   markerACT->setPosition(QwtPointPolar( 90+90+45, 45 ) );
   markerACT->attach( this );
   markerDDE->setZ(3);

   }
