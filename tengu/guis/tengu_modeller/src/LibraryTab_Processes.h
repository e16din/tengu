// ********************************************************************************************************************
// *                                                                                                                  *
// *                                    The tab for items that are relevant to processes                              *
// * ---------------------------------------------------------------------------------------------------------------- *
// *                            Вкладка для элементов, которые имеют отношение к процессам.                           *
// *                                                                                                                  *
// * Eugene G. Sysoletin <e.g.sysoletin@gmail.com>                                       Created 12 jun 2017 at 15:14 *
// ********************************************************************************************************************

#pragma once

#include <QWidget>
#include <QPushButton>
#include <QToolButton>
#include <QHBoxLayout>
#include <QSizePolicy>
#include <QIcon>
#include <QPixmap>
#include <QDragEnterEvent>
#include <QMouseEvent>

#include "LibraryTab_Button.h"

namespace tengu {

    class LibraryTab__processes : public QWidget {
        Q_OBJECT
        public:
            
            explicit LibraryTab__processes ( QWidget* parent = 0, Qt::WindowFlags f = 0 );
            virtual ~LibraryTab__processes();
            
            LibraryTab_Button * button__process_begin;
            LibraryTab_Button * button__process_end;
            
        protected:
            
            // void mousePressEvent( QMouseEvent * event);
            // void mouseReleaseEvent( QMouseEvent * vent );
            // void mouseMoveEvent( QMouseEvent * event );
            
        private:
            
            // void __init_button( QPushButton * button );
    };
};

