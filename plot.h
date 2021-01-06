#ifndef PLOT_H
#define PLOT_H

#include <qwt_polar_plot.h>
#include <qwt_polar_grid.h>
#include <qwt_polar_marker.h>
#include <qwt_symbol.h>

class Plot : public QwtPolarPlot
{
   Q_OBJECT
public:
   Plot( QWidget * = NULL );
   QwtPolarMarker *markerDDE;
   QwtPolarMarker *markerCMD;
   QwtPolarMarker *markerACT;

private:
    QwtPolarGrid *d_grid;

};

#endif // PLOT_H
