// ********************************************************************************************************************
// *                                                                                                                  *
// *                               The graphics representation of tengu.core.Task class                               *
// * ---------------------------------------------------------------------------------------------------------------- *
// *                                 Графическое представление класса tengu.core.Task                                 *
// *                                                                                                                  *
// * Eugene G. Sysoletin <e.g.sysoletin@gmail.com>                                       Created 09 jun 2017 at 10:58 *
// ********************************************************************************************************************

#include "TaskItem.h"

// ********************************************************************************************************************
// *                                                                                                                  *
// *                                                   The constructor.                                               *
// * ---------------------------------------------------------------------------------------------------------------- *
// *                                                     Конструктор.                                                 *
// *                                                                                                                  *
// ********************************************************************************************************************

tengu::TaskItem::TaskItem ( tengu::Task * task, QGraphicsItem * parent ) 
    : AbstractEntityItem ( task , parent )
{
    _boundingRect = QRectF( 0.0, 0.0, 400.0, 144.0 );
}

// ********************************************************************************************************************
// *                                                                                                                  *
// *                                                  The paint method.                                               *
// * ---------------------------------------------------------------------------------------------------------------- *
// *                                                   Метод отрисовки.                                               *
// *                                                                                                                  *
// ********************************************************************************************************************

void tengu::TaskItem::paint ( QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget ) {
    
    // Draw using a picture in memory to ensure smooth drawing
    // Рисуем через картинку в памяти для обеспечения плавности рисования.
    
    QPixmap pixmap( _boundingRect.width(), _boundingRect.height() );
    QPainter pixPainter( & pixmap );
    pixPainter.eraseRect( _boundingRect );
    
    // --------------------------------------------------------------------------------------------
    //                                              Shadow.
    //                                              Тенька.
    // --------------------------------------------------------------------------------------------
    
    int shSize = 16;
    
    QRect shadowRect( _boundingRect.x() + shSize, _boundingRect.y() + shSize, _boundingRect.width() - shSize - 1, _boundingRect.width()- shSize - 1 );
    pixPainter.fillRect( shadowRect, _processDiagram_shadowColor() );    
        
    // --------------------------------------------------------------------------------------------
    //                                    Body of task, with gradient.
    //                                     Тело задачи, с градиентом.
    // --------------------------------------------------------------------------------------------
        
    QColor gradientDarkColor = _processDiagram_darkFillColor();        
    QColor gradientBrightColor = _processDiagram_brightFillColor();
    
    QRect taskRect( _boundingRect.x() + 2, _boundingRect.y() + 2, _boundingRect.width() - shSize - 1, _boundingRect.height() - shSize - 1 );
    QRect taskRectUP ( taskRect.x(), taskRect.y(), taskRect.width(), taskRect.height() / 2 );
    QRect taskRectDown ( taskRect.x(), taskRect.y() + taskRect.height() / 2, taskRect.width(), taskRect.height() / 2 );
    
    QLinearGradient gradientUP( taskRectUP.topLeft(), taskRectUP.bottomLeft() ); 
    gradientUP.setColorAt(0, gradientDarkColor );
    gradientUP.setColorAt(1, gradientBrightColor );
    pixPainter.fillRect( taskRectUP, gradientUP );
    
    QLinearGradient gradientDown ( taskRectDown.topLeft(), taskRectDown.bottomLeft() );
    gradientDown.setColorAt( 0, gradientBrightColor );
    gradientDown.setColorAt( 1, gradientDarkColor );
    pixPainter.fillRect( taskRectDown, gradientDown );
        
    // --------------------------------------------------------------------------------------------
    //                                         Task picture. 
    //                                        Картинка задачи. 
    // --------------------------------------------------------------------------------------------
    
    QPixmap taskPicture(":cog_32.png");
    pixPainter.drawPixmap( 346, 8, taskPicture );
    
    // --------------------------------------------------------------------------------------------
    //                                            Borders
    //                                            Границы
    // --------------------------------------------------------------------------------------------
    
    
    QPen pen = _processDiagram_borderPen();
    pixPainter.setPen( pen );
    
    // Rectangle, but throught lines to avoid broken angles in rectangle.
    // Прямоугольник, но линиями, чтобы не было ломаных уголков у прямоугольника.
    
    pixPainter.drawLine( _boundingRect.x() + 1, _boundingRect.y() + 1, _boundingRect.width() - shSize, _boundingRect.y()+1 );
    pixPainter.drawLine( _boundingRect.width() - shSize, _boundingRect.y() + 1, _boundingRect.width()-shSize, _boundingRect.height() - shSize );
    pixPainter.drawLine( _boundingRect.x() + 1, _boundingRect.y() + 1, _boundingRect.x() + 1, _boundingRect.height() - shSize );
    pixPainter.drawLine( _boundingRect.x() + 1, _boundingRect.height()-shSize, _boundingRect.width()-shSize, _boundingRect.height()-shSize );
    
    //pixPainter.drawRect( _boundingRect.left()+1, _boundingRect.top()+1, _boundingRect.width() - 9, _boundingRect.height() - 9 );
    
    
    painter->drawPixmap( 0, 0, pixmap );
        
}

// ********************************************************************************************************************
// *                                                                                                                  *
// *                                          Get pointer to the represented task.                                    *
// * ---------------------------------------------------------------------------------------------------------------- *
// *                                      Получить указатель на представляемую задачу.                                *
// *                                                                                                                  *
// ********************************************************************************************************************

tengu::Task * tengu::TaskItem::__task() {
    return ( Task * ) _entity;
}

// ********************************************************************************************************************
// *                                                                                                                  *
// *                                                   The destructor.                                                *
// * ---------------------------------------------------------------------------------------------------------------- *
// *                                                      Деструктор.                                                 *
// *                                                                                                                  *
// ********************************************************************************************************************

tengu::TaskItem::~TaskItem() {

}


