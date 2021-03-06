// ********************************************************************************************************************
// *                                                                                                                  *
// *                              Abstract graphics object, representation of AbstractEntity.                         *
// * ---------------------------------------------------------------------------------------------------------------- *
// *                            Абстрактный графический объект, представление AbstractEntity.                         *
// *                                                                                                                  *
// * Eugene G. Sysoletin <e.g.sysoletin@gmail.com>                                       Created 08 jun 2017 at 09:00 *
// ********************************************************************************************************************

#include "AbstractEntityItem.h"

// ********************************************************************************************************************
// *                                                                                                                  *
// *                                                  The constructor.                                                *
// * ---------------------------------------------------------------------------------------------------------------- *
// *                                                    Конструктор.                                                  *
// *                                                                                                                  *
// ********************************************************************************************************************

tengu::AbstractEntityItem::AbstractEntityItem( AbstractEntity * entity, QGraphicsItem * parent ) 
    : QGraphicsObject( parent )
{
    _entity = entity;
    _boundingRect = QRectF(0, 0, 20, 20);
    _selected = false;
    _decomposite = false;
    
    __mousePressed = false;
    
    // setAcceptHoverEvents( true );
    // setAcceptTouchEvents( true );
}

// ********************************************************************************************************************
// *                                                                                                                  *
// *                                   Overrided function for bounding the rectangle.                                 *
// * ---------------------------------------------------------------------------------------------------------------- *
// *                                  Перекрытая функция для привязки прямоугольника.                                 *
// *                                                                                                                  *
// ********************************************************************************************************************

QRectF tengu::AbstractEntityItem::boundingRect() const {
    return _boundingRect;
}

// ********************************************************************************************************************
// *                                                                                                                  *
// *                    Paint function for abstract graphics agent (only for demonstrate it is empty)                 *
// * ---------------------------------------------------------------------------------------------------------------- *
// *             Функция рисования абстрактного графического агента (только чтобы показать, что он пустой)            *
// *                                                                                                                  *
// ********************************************************************************************************************

void tengu::AbstractEntityItem::paint( QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget) {
    painter->drawRect(  _boundingRect );
}

// ********************************************************************************************************************
// *                                                                                                                  *
// *                                      Return agent this graphics item based on.                                   *
// * ---------------------------------------------------------------------------------------------------------------- *
// *                        Вернуть агента, на котором основывается данный графический элемент.                       *
// *                                                                                                                  *
// ********************************************************************************************************************

tengu::AbstractEntity * tengu::AbstractEntityItem::entity() {
    return _entity;
}

// ********************************************************************************************************************
// *                                                                                                                  *
// *                                              Is this agent selected?                                             *
// * ---------------------------------------------------------------------------------------------------------------- *
// *                                    Является ли данный агент выбранным (отмеченным)?                              *
// *                                                                                                                  *
// ********************************************************************************************************************

bool tengu::AbstractEntityItem::isSelected() {
    return _selected;
}


// ********************************************************************************************************************
// *                                                                                                                  *
// *                                              Set this agent selection.                                           *
// * ---------------------------------------------------------------------------------------------------------------- *
// *                                        Установка выбранности данного агента.                                     *
// *                                                                                                                  *
// ********************************************************************************************************************

void tengu::AbstractEntityItem::setSelected ( bool selection ) {
    _selected = selection;
    update();
}

// ********************************************************************************************************************
// *                                                                                                                  *
// *                                    Make R-G-B constituent of color to some brighter.                             *
// * ---------------------------------------------------------------------------------------------------------------- *
// *                                     Сделать R-G-B составляющую цвета чуть поярче.                                *
// *                                                                                                                  *
// ********************************************************************************************************************

int tengu::AbstractEntityItem::_brighter ( int color ) {
    color += color / 5;
    if ( color > 255 ) color = 255;
    return color;
}

// ********************************************************************************************************************
// *                                                                                                                  *
// *                                         Get border's color for process diagrams.                                 *
// * ---------------------------------------------------------------------------------------------------------------- *
// *                                       Получить цвет границ для диаграмм процессов.                               *
// *                                                                                                                  *
// ********************************************************************************************************************

QColor tengu::AbstractEntityItem::_processDiagram_borderColor() {
    
    QColor bgColor = ORDINAR_BORDER_COLOR;
    if ( _selected ) bgColor = ORDINAR_SELECTED_BORDER_COLOR;
    
    /*
    if ( entity()->isFocused() ) {
        if ( _selected ) bgColor = FOCUSED_SELECTED_BORDER_COLOR;
        else bgColor = FOCUSED_BORDER_COLOR;
    };
    
    if ( entity()->isActive() ) {
        if ( _selected ) bgColor = ACTIVE_SELECTED_BORDER_COLOR;
        else bgColor = ACTIVE_BORDER_COLOR;
    };
    */
    
    return bgColor;
    
}

// ********************************************************************************************************************
// *                                                                                                                  *
// *                                   Get shadow's color for processes diagrams.                                     *
// * ---------------------------------------------------------------------------------------------------------------- *
// *                                   Получить цвет теней для диаграмм процессов.                                    *
// *                                                                                                                  *
// ********************************************************************************************************************

QColor tengu::AbstractEntityItem::_processDiagram_shadowColor() {
    QColor c = QColor( 240, 240, 240 );
    if ( _selected ) c = QColor( 220, 220, 220 );
    return c;
}

// ********************************************************************************************************************
// *                                                                                                                  *
// *                                     Get "dark" fill color for process diagrams.                                  *
// * ---------------------------------------------------------------------------------------------------------------- *
// *                               Получить "темный" цвет заполнения для диаграмм процессов.                          *
// *                                                                                                                  *
// ********************************************************************************************************************

QColor tengu::AbstractEntityItem::_processDiagram_darkFillColor() {
    
    QColor c = ORDINAR_FILL_COLOR;
    if ( _selected ) c = ORDINAR_SELECTED_FILL_COLOR;
 
    /*
    if ( agent()->isFocused() ) {
        if ( _selected ) c = FOCUSED_SELECTED_FILL_COLOR;
        else c = FOCUSED_FILL_COLOR;
    };
    
    if ( agent()->isActive() ) {
        if ( _selected ) c = ACTIVE_SELECTED_FILL_COLOR;
        else c = ACTIVE_FILL_COLOR;
    };
    */
    
    return c;
    
}


// ********************************************************************************************************************
// *                                                                                                                  *
// *                                   Get "bright" fill color for process'es diagrams.                               *
// * ---------------------------------------------------------------------------------------------------------------- *
// *                                Получить "яркий" цвет заполнения для диаграмм процессов.                          *
// *                                                                                                                  *
// ********************************************************************************************************************

QColor tengu::AbstractEntityItem::_processDiagram_brightFillColor() {
    
    QColor d = _processDiagram_darkFillColor();
    int r = _brighter( d.red() );
    int g = _brighter( d.green() );
    int b = _brighter( d.blue() );
    return QColor( r, g, b );
    
}

// ********************************************************************************************************************
// *                                                                                                                  *
// *                       Get the "pen" for painting borders of elements of process diagram.                         *
// * ---------------------------------------------------------------------------------------------------------------- *
// *                   Получить "карандаш" для рисования границ элементов на диаграммах процессов.                    *
// *                                                                                                                  * 
// ********************************************************************************************************************

QPen tengu::AbstractEntityItem::_processDiagram_borderPen() {
    QPen pen;
    pen.setWidth( 3 );
    pen.setStyle( Qt::SolidLine );
    pen.setColor( _processDiagram_borderColor() );
    return pen;
}

// ********************************************************************************************************************
// *                                                                                                                  *
// *                                               Mouse press event handler.                                         *
// * ---------------------------------------------------------------------------------------------------------------- *
// *                                            Обработчик события нажатия мышки.                                     *
// *                                                                                                                  *
// ********************************************************************************************************************
/*
void tengu::AbstractAgentItem::mousePressEvent ( QGraphicsSceneMouseEvent * event ) {
    qDebug() << "AbstractAgentItem::mousePressEvent()" ;
    __mousePressed = true;
    QGraphicsItem::mousePressEvent ( event );
}
*/
// ********************************************************************************************************************
// *                                                                                                                  *
// *                                             Mouse release event handler.                                         *
// * ---------------------------------------------------------------------------------------------------------------- *
// *                                        Обработчик события отпускания мыши.                                       *
// *                                                                                                                  *
// ********************************************************************************************************************
/*
void tengu::AbstractAgentItem::mouseReleaseEvent ( QGraphicsSceneMouseEvent * event ) {
    qDebug() << "AbstractAgentItem::mouseReleaseEvent()" ;
    __mousePressed = false;
    QGraphicsItem::mouseReleaseEvent ( event );
}
*/
// ********************************************************************************************************************
// *                                                                                                                  *
// *                                             Mouse move event handler.                                            *
// * ---------------------------------------------------------------------------------------------------------------- *
// *                                         Обработчик события перемещения мыши.                                     *
// *                                                                                                                  *
// ********************************************************************************************************************
/*
void tengu::AbstractAgentItem::mouseMoveEvent ( QGraphicsSceneMouseEvent * event ) {
    qDebug() << "AbstractAgentItem::mouseMoveEvent()";
    QGraphicsItem::mouseMoveEvent ( event );
}
*/
// ********************************************************************************************************************
// *                                                                                                                  *
// *                                   Return properties list for this abstract agent.                                *
// * ---------------------------------------------------------------------------------------------------------------- *
// *                                       Вернуть список свойств данного агента.                                     *
// *                                                                                                                  *
// ********************************************************************************************************************

QList<QPair<QString, QVariant>> tengu::AbstractEntityItem::properties() {

    QList<QPair<QString, QVariant>> result;
    
    if ( entity() ) {
        result.append( QPair<QString, QVariant>("UUID", QVariant( entity()->getUUID() ) ) );    
        result.append( QPair<QString, QVariant>( tr("Name"), QVariant( entity()->getName() ) ) );
        result.append( QPair<QString, QVariant>( tr("Comment"), QVariant( entity()->getComment() ) ) );
    }
    
    return result;
    
}

// ********************************************************************************************************************
// *                                                                                                                  *
// *                                  Is this entity the subject for decomposition?                                   *
// * ---------------------------------------------------------------------------------------------------------------- *
// *                                   Является ли данная сущность декомпозируемой?                                   *
// *                                                                                                                  *
// ********************************************************************************************************************

bool tengu::AbstractEntityItem::isDecomposite() {
    
    // "Decomposite" mean either forcibly decomposition or this base is exactly an agent and he has children.
    // "Декомпозиция" означает либо принудительную декомпозицию, либо в основании лежит точно агент и он имеет детей.
    
    AbstractAgent * agent = qobject_cast<AbstractAgent * >( _entity );
    bool agentHasChildren = false;
    if ( agent ) agentHasChildren = agent->hasChildren();
    return ( _decomposite || agentHasChildren  );
    
}

// ********************************************************************************************************************
// *                                                                                                                  *
// *                                                   The destructor.                                                *
// * ---------------------------------------------------------------------------------------------------------------- *
// *                                                      Деструктор.                                                 *
// *                                                                                                                  *
// ********************************************************************************************************************

tengu::AbstractEntityItem::~AbstractEntityItem() {
}


