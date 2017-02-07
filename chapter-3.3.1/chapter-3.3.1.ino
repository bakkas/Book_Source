#include <IRremote.h>
int recvPin = 11;
IRrecv irrecv(recvPin);

void  setup ( ) {
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void  ircode (decode_results *results) {
  if (results->decode_type == PANASONIC) {
    Serial.print(results->address, HEX);
    Serial.print(":");
  }
  Serial.print(results->value, HEX);
}

void  encoding (decode_results *results) {
  switch (results->decode_type) {
    default:
    case UNKNOWN:  Serial.print("UNKNOWN");    break ;
    case NEC:     Serial.print("NEC");      break ;
    case SONY:    Serial.print("SONY");     break ;
    case RC5:   Serial.print("RC5");      break ;
    case RC6:   Serial.print("RC6");      break ;
    case DISH:    Serial.print("DISH");     break ;
    case SHARP:   Serial.print("SHARP");      break ;
    case JVC:     Serial.print("JVC");      break ;
    case SANYO:   Serial.print("SANYO");    break ;
    case MITSUBISHI:  Serial.print("MITSUBISHI");   break ;
    case SAMSUNG:   Serial.print("SAMSUNG");    break ;
    case LG:    Serial.print("LG");       break ;
    case WHYNTER:   Serial.print("WHYNTER");    break ;
    case AIWA_RC_T501:  Serial.print("AIWA_RC_T501"); break ;
    case PANASONIC: Serial.print("PANASONIC");    break ;
    case DENON:   Serial.print("Denon");      break ;
  }
}
void  dumpInfo (decode_results *results) {
  if (results->overflow) {
    Serial.println("IR code too long. Edit IRremoteInt.h and increase RAWLEN");
    return;
  }
  Serial.print("Encoding  : ");
  encoding(results);
  Serial.println("");
  Serial.print("Code      : ");
  ircode(results);
  Serial.print(" (");
  Serial.print(results->bits, DEC);
  Serial.println(" bits)");
}

void  dumpCode (decode_results *results) {
   if (results->decode_type != UNKNOWN) {
    if (results->decode_type == PANASONIC) {
      Serial.print("unsigned int  addr = 0x");
      Serial.print(results->address, HEX);
      Serial.println(";");
    }
    Serial.print("unsigned int  data = 0x");
    Serial.print(results->value, HEX);
    Serial.println(";");
  }
}

void  loop ( ) {
  decode_results  results;     // Somewhere to store the results
  if (irrecv.decode(&results)) {  // Grab an IR code
    dumpInfo(&results);           // Output the results
    dumpCode(&results);           // Output the results as source code
    Serial.println("");          // Blank line between entries
    irrecv.resume();              // Prepare for the next value
  }
}
