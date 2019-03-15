#include "BG96CellularMCB_CellularPower.h"
#include "DigitalOut.h"
#include "mbed_wait_api.h"

using namespace mbed;

#if defined (MBED_CONF_BG96_CELLULAR_MCB_POWER_PIN)
static DigitalOut modem_power_on(MBED_CONF_BG96_CELLULAR_MCB_POWER_PIN);
#endif

BG96CellularMCB_CellularPower::BG96CellularMCB_CellularPower(ATHandler &atHandler) : QUECTEL_BG96_CellularPower(atHandler)
{

}

nsapi_error_t BG96CellularMCB_CellularPower::on()
{
    #if defined (MBED_CONF_BG96_CELLULAR_MCB_POWER_PIN)
    modem_power_on = 1;
    wait_ms(250);
    modem_power_on = 0;
    #endif
    return NSAPI_ERROR_OK;
}

nsapi_error_t BG96CellularMCB_CellularPower::off()
{
    #if defined (MBED_CONF_BG96_CELLULAR_MCB_POWER_PIN)
    //Can we power down this somehow using the same pin?
    modem_power_on = 1;
    wait_ms(250);
    modem_power_on = 0;
    #endif
    return NSAPI_ERROR_OK;
}

nsapi_error_t BG96CellularMCB_CellularPower::reset()
{
    #if defined (MBED_CONF_BG96_CELLULAR_MCB_RESET_PIN)
    //TODO, use reset pin if we have one
    #endif
    return NSAPI_ERROR_OK;
}