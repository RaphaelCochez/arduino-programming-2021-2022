//aanmaken en waarde toewijzen variabelen
byte a = 4;
int b = 5;
char c = 'a';
float d = 3.1425;

//aanmaken van pointers
byte *a_pointer;
int *b_pointer;
char *c_pointer;
float *d_pointer;

void setup() {
//pointers aan variabelen toewijzen
a_pointer = &a;
b_pointer = &b;
c_pointer = &c;
d_pointer = &d;

//waarden pointers naar de serial monitor schrijven
Serial.begin(9600);
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

Serial.println("waarde variabelen");

Serial.print("pointer byte waarde: ");
Serial.println(*a_pointer);
Serial.print("pointer int waarde: ");
Serial.println(*b_pointer);
Serial.print("pointer char waarde: ");
Serial.println(*c_pointer);
Serial.print("pointer float waarde: ");
Serial.println(*d_pointer);
}

void loop() {

}
