 void setup()
 {
   Serial.begin(9600);
   
   //void getSeconds(unsigned long *par);  This declaration not necessary.  }
 
void loop()
 {
   unsigned int var = 0;
   Serial.println("-------");
   Serial.print("seconds before function: ");
   Serial.println(var);
   Serial.print("Address of seconds: ");
   Serial.println((int)&var);//This is where I trouble displaying the memory address.
   getSeconds( &var); //
   Serial.print("seconds after function: ");
   Serial.println(var);// Through the pointer and function, the value at the address of seconds equals *par.
 }
void getSeconds(unsigned long *par)//Take what in the address of seconds (&seconds) and put that value in address of *par.
{
  Serial.print("Address of *par: ");
  Serial.println((long)&par);
  Serial.print("*par first: ");
  Serial.println(*par);
  *par = millis();//Make the value at the address at *par equal to millis().
  Serial.print("*par after millis: ");
  Serial.println(*par);
  delay(1000);
}
