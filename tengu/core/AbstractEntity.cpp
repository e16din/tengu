// ********************************************************************************************************************
// *                                                                                                                  *
// *                                An "entity" class, common parent for agents and sprouts.                          *
// * ---------------------------------------------------------------------------------------------------------------- *
// *                        Класс "сущности", общий предок для агентов и ростков (связей агентов)                     *
// *                                                                                                                  *
// * Eugene G. Sysoletin <e.g.sysoletin@gmail.com>                                       Created 11 jun 2017 at 12:36 *
// ********************************************************************************************************************

#include "AbstractEntity.h"

// ********************************************************************************************************************
// *                                                                                                                  *
// *                                                  The constructor.                                                *
// * ---------------------------------------------------------------------------------------------------------------- *
// *                                                     Конструктор.                                                 *
// *                                                                                                                  *
// ********************************************************************************************************************

tengu::AbstractEntity::AbstractEntity ( QObject* parent ) 
    : QObject ( parent )
{
    __name = QString("");
    __comment = QString("");
    
    // Temporary. You always can set it by setUUID().
    // Времянка. Вы всегда его можете переставить через setUUID().
    
    __uuid = QUuid::createUuid().toString();
    
    __execution_mode = EM_ALWAYS;
    
    _changed = false;

}

// ********************************************************************************************************************
// *                                                                                                                  *
// *                                             Get name of this agent.                                              *
// * ---------------------------------------------------------------------------------------------------------------- *
// *                                            Получить имя этого агента.                                            *
// *                                                                                                                  *
// ********************************************************************************************************************

QString tengu::AbstractEntity::getName() {
    return __name;
}

// ********************************************************************************************************************
// *                                                                                                                  *
// *                                              Set name of this agent.                                             *
// * ---------------------------------------------------------------------------------------------------------------- *
// *                                           Установить имя данного агента.                                         *
// *                                                                                                                  *
// ********************************************************************************************************************

void tengu::AbstractEntity::setName ( QString name ) {
    __name = name;
    _changed = true;
}

// ********************************************************************************************************************
// *                                                                                                                  *
// *                                             Return UUID of this agent.                                           *
// * ---------------------------------------------------------------------------------------------------------------- *
// *                                            Вернуть UUID данного агента.                                          *
// *                                                                                                                  *
// ********************************************************************************************************************

QString tengu::AbstractEntity::getUUID() {
    return __uuid;
}

// ********************************************************************************************************************
// *                                                                                                                  *
// *                                               Set this agent uuid                                                *
// * ---------------------------------------------------------------------------------------------------------------- *
// *                                          Установить uuid данного агента.                                         *
// *                                                                                                                  *
// ********************************************************************************************************************

void tengu::AbstractEntity::setUUID ( QString uuid ) {
    __uuid = uuid;
    _changed = true;
}

// ********************************************************************************************************************
// *                                                                                                                  *
// *                                               Get entity's comment.                                              *
// * ---------------------------------------------------------------------------------------------------------------- *
// *                                       Получить комментарий данноой "сущности".                                   *
// *                                                                                                                  *
// ********************************************************************************************************************

QString tengu::AbstractEntity::getComment() {
    return __comment;
}

// ********************************************************************************************************************
// *                                                                                                                  *
// *                                          Set comment for this "entity".                                          *
// * ---------------------------------------------------------------------------------------------------------------- *
// *                                      Установить комментарий данной "сущности".                                   *
// *                                                                                                                  *
// ********************************************************************************************************************

void tengu::AbstractEntity::setComment ( QString comment ) {
    __comment = comment;
    _changed = true;
}

// ********************************************************************************************************************
// *                                                                                                                  *
// *                                         Return execution mode of this entity.                                    *
// * ---------------------------------------------------------------------------------------------------------------- *
// *                                      Вернуть режим выполнения данной сущности.                                   *
// *                                                                                                                  *
// ********************************************************************************************************************

tengu::AbstractEntity::execution_mode_t tengu::AbstractEntity::getExecutionMode() {
    return __execution_mode;
};

// ********************************************************************************************************************
// *                                                                                                                  *
// *                                       Set execution mode for this entity.                                        *
// * ---------------------------------------------------------------------------------------------------------------- *
// *                                 Установить режим выполнения для данной сущности.                                 *
// *                                                                                                                  *
// ********************************************************************************************************************

void tengu::AbstractEntity::setExecutionMode( tengu::AbstractEntity::execution_mode_t mode ) {
    __execution_mode = mode;
    _changed = true;
};

// ********************************************************************************************************************
// *                                                                                                                  *
// *                                           Has been this entity changed?                                          *
// * ---------------------------------------------------------------------------------------------------------------- *
// *                                       Была ли данная "сущность" изменена?                                        *
// *                                                                                                                  *
// ********************************************************************************************************************

bool tengu::AbstractEntity::hasChanged() {
    return _changed;
}


// ********************************************************************************************************************
// *                                                                                                                  *
// *                                                    The destructor.                                               *
// * ---------------------------------------------------------------------------------------------------------------- *
// *                                                       Деструктор.                                                *
// *                                                                                                                  *
// ********************************************************************************************************************

tengu::AbstractEntity::~AbstractEntity() {

}

