byte a = 4;
int b = 5;
char c = 'a';
float d = 3.1425;

byte *a_pointer;
int *b_pointer;
char *c_pointer;
float *d_pointer;

void setup() {
Serial.begin(9600);
a_pointer = &a;
b_pointer = &b;
c_pointer = &c;
d_pointer = &d;

Serial.println("waarde byte");
Serial.print("pointer L waarde: ");
Serial.println((long)&a_pointer, DEC);
Serial.print("pointer R waarde: ");
Serial.println((long)a_pointer, DEC);
Serial.println();

Serial.println("waarde int");
Serial.print("pointer L waarde: ");
Serial.println((long)&b_pointer, DEC);
Serial.print("pointer R waarde: ");
Serial.println((long)b_pointer, DEC);
Serial.println();


Serial.println("waarde char");
Serial.print("pointer L waarde: ");
Serial.println((long)&c_pointer, DEC);
Serial.print("pointer R waarde: ");
Serial.println((long)c_pointer, DEC);
Serial.println();


Serial.println("waarde float");
Serial.print("pointer L waarde: ");
Serial.println((long)&d_pointer, DEC);
Serial.print("pointer R waarde: ");
Serial.println((long)d_pointer, DEC);
Serial.println();

}

void loop() {

}
