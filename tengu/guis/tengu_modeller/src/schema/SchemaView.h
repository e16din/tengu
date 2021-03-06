// ********************************************************************************************************************
// *                                                                                                                  *
// *                            UML-like "schema", the graphics representation of model.                              *
// * ---------------------------------------------------------------------------------------------------------------- *
// *                             UML-подобная "схема", графическое представление модели.                              *
// *                                                                                                                  *
// * Eugene G. Sysoletin <e.g.sysoletin@gmail.com>                                       Created 28 may 2017 at 15:48 *
// ********************************************************************************************************************

#pragma once

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWheelEvent>
#include <QDebug>
#include <QMouseEvent>
// #include <QGLFormat>
#include <QPoint>
#include <QMenu>
#include <QAction>
#include <QPixmap>

#include "AbstractEntityItem.h"

namespace tengu {

    class SchemaView : public QGraphicsView {
        
        Q_OBJECT
        
        signals:
            
            void signalItemPressed( AbstractEntityItem * item, bool controlPressed );
            void signalItemDoubleClicked( AbstractEntityItem * item, bool controlPressed );
        
        public:
            
            SchemaView( QGraphicsScene * scene );
            virtual ~SchemaView();

            // mouse wheel event
            // событие колесика мышки
                        
        private:
            
            void mousePressEvent( QMouseEvent * event );
            void mouseReleaseEvent( QMouseEvent * event );
            void mouseMoveEvent( QMouseEvent * event );   
            void mouseDoubleClickEvent(QMouseEvent * event);
            void contextMenuEvent( QContextMenuEvent * event );
            
#ifndef QT_NO_WHEELEVENT
            void wheelEvent( QWheelEvent * event );
#endif
            
            bool __leftMouseButtonPressed;
            
            QMenu * __contextMenu;
            QMenu * __contextMenu__create;
            QAction * __actionCreateTask;
            
            void __createMenus();
            
            QPoint __scaleCenter;
            
            QPoint __mouseAtSchemaPos;
            
            // float __scaleFactor;
            
        private slots:
            
            void __on_action_create_task();            
                        
    };
};

