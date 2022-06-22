#include <IRremote.h>
#define led1 2
const byte IR_RECEIVE_PIN = 7;
bool state1 = false;
bool state2 = false;
void setup()
{
   Serial.begin(9600);
   Serial.println("IR Receive test");
   pinMode(2, OUTPUT);
   IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
}

void loop()
{
   if (IrReceiver.decode())
   {
      int recievedValue = IrReceiver.decodedIRData.command;

      switch (recievedValue) {
      case 0:
      // signaal onduidelijk
      break;
      case 4:

      break;
      case 5:

      break;
      case 6:

      break;
      case 7:

      break;
      case 8:
      // de 4H knop
      break;

      case 9:

      break;
      case 10:

      break;
      case 11:

      break;
      case 12:
      // de 3H knop
      break;
      case 13:

      break;
      case 14:

      break;
      case 15:

      break;
      case 16:
      // de 2H knop
      break;
      
      case 17:
      // jump 7 knop
      break;
      case 18:
      // de slow knop
      break;
      case 19:

      break;
      case 20:
      // de 1H knop
      break;
      case 21:
      //jump 3 knop
      break;
      case 22:
      // de quick knop
      break;

      case 23:

      break;
      case 24:

      break;
      case 25:

      break;
      case 26:

      break;
      case 27:

      break;
      case 28:

      break;
      case 29:

      break;
      case 30:

      break;
      case 31:

      break;
      case 64:
      // on knop
      break;
      case 65:
      // off knop
      break;
      case 68:
      //W knop
      break;
      case 69:
      //B knop
      break;
      case 72:

      break;

      case 73:

      break;
      case 76:

      break;
      case 77:

      break;
      case 80:

      break;
      case 81:

      break;
      case 84:

      break;
      case 85:

      break;
      case 88:
      // R knop
      break;
      case 89:
      //G knop
      break;
      case 92:
      //V+ knop
      break;
      case 93:
      //V- knop
      break;
      }
   
      }
      Serial.println(IrReceiver.decodedIRData.command);
      IrReceiver.resume();
      
   
}
