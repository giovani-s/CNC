
#include "mbed.h"
#include <chrono>
#include <cstring>
#include "AsyncStepper.hpp"

#define ENABLE_PINX D13
#define STEP_PINX D3
#define DIR_PINX D2
#define MS1X_PIN D6
#define MS2X_PIN D7
#define MS3X_PIN D8

#define ENABLE_PINY D12
#define STEP_PINY D5
#define DIR_PINY D4
#define MS1Y_PIN D9
#define MS2Y_PIN D10
#define MS3Y_PIN D11

#define RPM 60

AsyncStepper stepperX(ENABLE_PINX, STEP_PINX, DIR_PINX,RPM,FULL,MS1X_PIN,MS2X_PIN,MS3X_PIN);
AsyncStepper stepperY(ENABLE_PINY, STEP_PINY, DIR_PINY,RPM,FULL,MS1Y_PIN,MS2Y_PIN,MS3Y_PIN);

static BufferedSerial pc(USBTX, USBRX);

int main()
{
    printf("%s\n","CONFIGURACION INICIAL:");
    pc.set_baud(9600);
    pc.set_format(8, BufferedSerial::None, 1);

    ThisThread::sleep_for(1s);
    int stepsPerRevolution = 0;

    int posX=0;
    int posY=0;

    int dataserialx=0;
    int dataserialy=0;

    char* dataArray[4];

    stepperX.SetStepMode(SIXTEENTH);
    
    stepperY.SetStepMode(SIXTEENTH);
    
    
    printf("%s\n","INICIO:");
    
    while (1) 
    {
        int i = 0;
        char buff[20];
        ssize_t numBytesRead = pc.read(buff, sizeof(buff));
        
        printf("serial data: %s\n size: %d\n",buff,numBytesRead);

        char *charDataArray = strtok(buff, "|");
        
        while (charDataArray != NULL ) {
            dataArray[i] = charDataArray;
            charDataArray = strtok(NULL, "|");
            i++;
        }
        
        if(numBytesRead>0)
        {
            /*
            printf(" Valor X comprobado[0] datax:%s\n",dataArray[0]);
            printf("Valor de X comprobado [1]\n");
            printf("serial datax:%s lenx: %d\n",dataArray[1],strlen(dataArray[1]));
            printf("x:%d\n",posX);
            printf("Valor de Y comprobado [2] datay:%s\n",dataArray[2]);
            printf("serial datay:%s leny: %d\n",dataArray[3],strlen(dataArray[3]));
                       
            printf("y:%i\n",posY);
            */

            if (*dataArray[0]=='x') 
            {
                dataserialx=atoi(dataArray[1]);
                stepsPerRevolution = abs(posX - dataserialx);

                if (dataserialx > posX) 
                {
                    // Mover el motor una revolución en una dirección
                    stepperX.Rotate(POSITIVE,stepsPerRevolution);

                } else if(dataserialx < posX) 
                {
                    // Mover el motor una revolución en una dirección
                    stepperX.Rotate(NEGATIVE,stepsPerRevolution);
                }

                // Esperar a que el movimiento se complete
                while (!stepperX.IsStopping()) {

                    ThisThread::sleep_for(1ms);
                    
                }

                posX = dataserialx;
            }

            if (*dataArray[2] == 'y') 
            {
                dataserialy=atoi(dataArray[3]);
                stepsPerRevolution = abs(posY - dataserialy);
                
                if (dataserialy > posY) 
                {
                    // Mover el motor una revolución en una dirección
                    stepperY.Rotate(NEGATIVE,stepsPerRevolution);

                } else if(dataserialy < posY)
                {
                    // Mover el motor una revolución en la dirección opuesta
                    stepperY.Rotate(POSITIVE,stepsPerRevolution);
                }

                // Esperar a que el movimiento se complete
                while (!stepperY.IsStopping()) {
                    ThisThread::sleep_for(1ms);
                }

                posY = dataserialy;

            }

        }

    }

}
