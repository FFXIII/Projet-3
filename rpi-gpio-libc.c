#include <stdlib.h>
#include <strin.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>    // Pour ouvrir les fichiers
#include <unistd.h>   // Pour écrire dans les fichiers
#include <stdbool>
#include "gpio.h"





void set-gpio(int bcm_pin, string etat)
{

      int fileValueExp=0;   // Pour les code d'érreur en ÉCRITURE
      int fileErrorExp=0;   // Pour les code d'érreur en OUVERTURE

      int fileValueDir=0;   // Pour les code d'érreur en ÉCRITURE
      int fileErrorDir=0;   // Pour les code d'érreur en OUVERTURE

      int fileValueVal=0;   // Pour les code d'érreur en ÉCRITURE
      int fileErrorVal=0;   // Pour les code d'érreur en OUVERTURE

      int fileValueUnex=0;  // Pour les code d'érreur en ÉCRITURE
      int fileErrorUnex=0;  // Pour les code d'érreur en OUVERTURE

      int gpioLength=0;     // Pour garder le nombre de caractaire SANS le \0

      string gpio;          // string pour la valeur du gpio
      string pathExp = "/sys/class/gpio/export";
      string pathDir;       // chemin du fichier direction
      string pathVal;       // chemin du fichier value


      sprintf(gpio, "%d", bcm_pin);   // On convertie le bcm_pin en string

      // On met le chemin d'accès des fichier dans leurs string
      sprintf(pathDir, "/sys/class/gpio/gpio%s/direction", gpio);
      sprintf(pathVal, "/sys/class/gpio/gpio%s/value", gpio);

      gpioLength=strlen(gpio);  // On met le nombre de caractère
      gpioLength++;             // On ajoute le \0


      if(fileExiste(pathExp) == true || fileExiste(pathExp) == true || fileExiste(pathExp) == true)
      {
          if(bcm_pin >= 0 && bcm_pin <= 27)
          {
              if(etat == "on" || etat == "ON")
              {
                  fileErrorExp=open(pathExp, O_WRONLY | O_APPEND);
                  fileErrorDir=open(pathDir, O_WRONLY | O_APPEND);
                  fileErrorVal=open(pathVal, O_WRONLY | O_APPEND);
                  if(fileErrorExp<0 || fileErrorDir<0 || fileErrorVal<0)
                      printf("Il y a eu une erreur à l'ouverture d'un des fichiers\n");
                  else
                  {
                      fileValueExp=write(fileErrorExp,gpio,gpioLength);
                      fileValueDir=write(fileErrorExp,"out",4);
                      fileValueVal=write(fileErrorExp,"1",2);
                      if(fileValueExp != gpioLength || fileValueDir != 4 || fileValueVal != 2)
                          printf("Il y a eu une erreur lors de l'ecritur dans l'un des fichiers\n");
                      close(fileValueExp);
                      close(fileErrorDir);
                      close(fileErrorVal);
                  }
              }
              else if(etat == "off" || etat == "OFF")
              {
                  fileErrorUnex=open("/sys/class/gpio/unexport", O_WRONLY | O_APPEND);
                  if(fileErrorUnex<0)
                      printf("Il y a eu une erreur à l'ouverture d'un des fichiers\n");
                  else
                  {
                      fileValueUnex=write(fileErrorUnex,gpio,gpioLength);
                      if(fileValueUnex != gpioLength)
                          printf("Il y a eu une erreur lors de l'ecritur dans l'un des fichiers\n");
                      close(fileErrorUnex);
                  }
              }
              else
                  printf("BAKA!!!!! Entrer un etat VALIDE!!!!!\n");
          }
          else
            printf("BAKA!!!!! Entrer un # de bcm_pin VALIDE!!!!!\n");
      }
      else
        printf("Bye Bye");

}
