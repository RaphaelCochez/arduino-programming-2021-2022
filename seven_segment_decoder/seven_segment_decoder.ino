//segments
int a = 12;
int b = 11;
int c = 10;
int d = 9;
int e = 8;
int f = 7;
int g = 6;
int p = 5;
//digits
int d4 = A4;
int d3 = A3;
int d2 = A2;
int d1 = A1;
//other
int del = 100;
int buttoncount = 0;
int loopcount = 0;

void setup()
{
  pinMode(d1, OUTPUT);
  pinMode(d2, OUTPUT);
  pinMode(d3, OUTPUT);
  pinMode(d4, OUTPUT);
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(p, OUTPUT);
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(p, HIGH);
}

void loop()
{
  zigzag(1);

}

void pickDigit(int x)
{
  digitalWrite(d1, LOW);
  digitalWrite(d2, LOW);
  digitalWrite(d3, LOW);
  digitalWrite(d4, LOW);

  switch(x)
  {
  case 1: 
    digitalWrite(d1, HIGH); 
    break;
  case 2: 
    digitalWrite(d2, HIGH); 
    break;
  case 3: 
    digitalWrite(d3, HIGH); 
    break;
  default: 
    digitalWrite(d4, HIGH); 
    break;
  }
}

void clearLEDs()
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(p, HIGH);
}

void roulette(int x)
{
  loopcount = 0;
  while (loopcount < x)
  {
    digitalWrite(a, LOW);
    pickDigit(1);
    delay(del);
    pickDigit(2);
    delay(del);
    pickDigit(3);
    delay(del);
    pickDigit(4);
    delay(del);
    digitalWrite(a, HIGH);
    digitalWrite(b, LOW);
    delay(del);
    digitalWrite(b, HIGH);
    digitalWrite(c, LOW);
    delay(del);
    digitalWrite(c, HIGH);
    digitalWrite(d, LOW);
    delay(del);
    pickDigit(3);
    delay(del);
    pickDigit(2);
    delay(del);
    pickDigit(1);
    delay(del);
    digitalWrite(d, HIGH);
    digitalWrite(e, LOW);
    delay(del);
    digitalWrite(e, HIGH);
    digitalWrite(f, LOW);
    delay(del);
    clearLEDs();
    loopcount++;
  }
}

void zigzag(int x)
{
  loopcount = 0;
  while(loopcount < x)
  {
    digitalWrite(a, LOW);
    pickDigit(1);
    delay(del);
    pickDigit(2);
    delay(del);
    pickDigit(3);
    delay(del);
    pickDigit(4);
    delay(del);
    digitalWrite(a, HIGH);
    digitalWrite(b, LOW);
    delay(del);
    digitalWrite(b, HIGH);
    digitalWrite(g, LOW);
    delay(del);
    pickDigit(3);
    delay(del);
    pickDigit(2);
    delay(del);
    pickDigit(1);
    delay(del);
    digitalWrite(g, HIGH);
    digitalWrite(e, LOW);
    delay(del);
    digitalWrite(e, HIGH);
    digitalWrite(d, LOW);
    delay(del);
    pickDigit(2);
    delay(del);
    pickDigit(3);
    delay(del);
    pickDigit(4);
    delay(del);
    digitalWrite(d, HIGH);
    digitalWrite(c, LOW);
    delay(del);
    digitalWrite(c, HIGH);
    digitalWrite(g, LOW);
    delay(del);
    pickDigit(3);
    delay(del);
    pickDigit(2);
    delay(del);
    pickDigit(1);
    delay(del);
    digitalWrite(g, HIGH);
    digitalWrite(f, LOW);
    delay(del);
    clearLEDs();
    loopcount++;
  }
}

void circles(int x)
{
  loopcount = 0;
  while (loopcount < x)
  {
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
    pickDigit(1);
    delay(250);
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    pickDigit(2);
    delay(250);
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(f, LOW);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    pickDigit(3);
    delay(250);
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    pickDigit(4);
    delay(250);
    clearLEDs();
    loopcount++;
  }
}
