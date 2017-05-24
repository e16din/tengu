// ********************************************************************************************************************
// *                                                                                                                  *
// * Class for control right-aileron deflection. Based on array because it controls all existing ailerons togehter.   *
// * ---------------------------------------------------------------------------------------------------------------- *
// * Класс для управления отклонением правого элерона. Основан на массиве, потому что управляет всеми существующими   *
// *                                            у модели элеронами одновременно.                                      *
// *                                                                                                                  *
// * Eugene G. Sysoletin <e.g.sysoletin@gmail.com>                                       Created 10 may 2017 at 10:27 *
// ********************************************************************************************************************

#include "XChRightAileron.h"

// ********************************************************************************************************************
// *                                                                                                                  *
// *                                                  The constructor.                                                *
// * ---------------------------------------------------------------------------------------------------------------- *
// *                                                    Конструктор.                                                  *
// *                                                                                                                  *
// ********************************************************************************************************************

tengu::XChRightAileron::XChRightAileron() 
    : XChFloatArray ( "RightAileron" , "sim/flightmodel/controls/ail1_def" , -60 , 60 ) {
        
    // Indexes for RIGHT aileron. The minus sign due to the configuration, we want the negative values to deflect the aileron down.
    // Индексы для ПРАВОГО элерона. Знак минуса - из-за конфигурации, мы хотим, чтобы отрицательные значения отклоняли элерон вниз.
    
    _templateArray[9] = -1;        
    _templateArray[24] = -1;
}

// ********************************************************************************************************************
// *                                                                                                                  *
// *                                                 The desctructor.                                                 *
// * ---------------------------------------------------------------------------------------------------------------- *
// *                                                    Деструктор.                                                   *
// *                                                                                                                  *
// ********************************************************************************************************************

tengu::XChRightAileron::~XChRightAileron() {

}


