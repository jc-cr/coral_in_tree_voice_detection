#include <cstdio>


#include "libs/base/console_m7.h"
#include "libs/base/led.h"
#include "third_party/freertos_kernel/include/FreeRTOS.h"
#include "third_party/freertos_kernel/include/task.h"

// Blinks the green User LED.
// As a best practice, the Status LED also turns on to indicate board power.
//
// To build and flash from coralmicro root:
//    bash build.sh
//    python3 scripts/flashtool.py --elf_path 

namespace coralmicro 
{
    namespace 
    {
    [[noreturn]] void Main() 
        {
            printf("Blink LED Example!\r\n");
            // Turn on Status LED to show the board is on.
            LedSet(Led::kStatus, true);

            // Setup a char* msgs
            char on_msg[] = "LED is ON!\r\n";
            char off_msg[] = "LED is OFF!\r\n";

            bool on = true;
            while (true) 
            {
                on = !on;
                LedSet(Led::kUser, on);
                vTaskDelay(pdMS_TO_TICKS(500));

                if(on)
                {
                    coralmicro::ConsoleM7::GetSingleton()->Write(on_msg, 12);
                }
                else
                {
                    coralmicro::ConsoleM7::GetSingleton()->Write(off_msg, 13);
                }
            }
        }

        }  // namespace
}  // namespace coralmicro
extern "C" void app_main(void *param) {
  (void)param;
  coralmicro::Main();
}
