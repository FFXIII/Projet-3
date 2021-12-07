
#include <wiringPi.h>
#include <strin.h>
#include "gpio.h"





void set-gpio(int bcm_pin, string etat)
{
      int physPin;  // Varriable pour garder la PIN NUMÉRIQUE

      // Initialisation des PINs
      wiringPiSetupGpio(void);

      // On vériffie si le numero de bcm_pin existe
      // Si oui, on met sa valeur dans la Varriable
      // physPin.
      if(bcm_pin < 1 || bcm_pin > 17)
      {
          printf("BAKA!!!!! Entrer un # de bcm_pin VALIDE!!!!!\n");
      }
      else
      {
          physPin = physPinToGpio (bcm_pin);
      }

      // On définit la PIN physPin comme OUTPUT.
      pinMode(physPin, OUTPUT);

      // On regarde si on veux qu'il soit à ON ou à OFF
      if(etat == "on" || etat == "ON")
      {
          digitalWrite (physPin, HIGH);
      }
      else if(etat == "off" || etat == "OFF")
      {
          digitalWrite (physPin,  LOW);
      }
      else
      {
          printf("Choisisser entre on|off!!!!!\n");
      }
}
