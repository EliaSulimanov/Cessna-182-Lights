const int TAXI_LED =      0;
const int NAV_WING_LED =  1;
const int TX =            2;
const int TAIL_LED =      3;
const int LAND_LED =      4;

int state;
unsigned long tx;

void setup() {
  pinMode(TAXI_LED, OUTPUT);
  pinMode(NAV_WING_LED, OUTPUT);
  pinMode(TAIL_LED, OUTPUT);
  pinMode(LAND_LED, OUTPUT);
  pinMode(TX, INPUT);

  state = 0;
}

void loop() {
  tx = pulseIn(TX, HIGH, 25000);

  if(tx > 1700)
    state++;
    
  if(tx<1200)
    state--;
    
  delay(3000);
  
  switch(state){
    case 1: nav(); break;
    case 2: land(); break;
    default: taxi(); break;
  }
}

void taxi()
{
  digitalWrite(TAXI_LED,      HIGH);
  digitalWrite(NAV_WING_LED,  LOW);
  digitalWrite(TAIL_LED,      LOW);
  digitalWrite(LAND_LED,      LOW);
}

void land()
{
  digitalWrite(TAXI_LED,      LOW);
  digitalWrite(NAV_WING_LED,  LOW);
  digitalWrite(TAIL_LED,      LOW);
  digitalWrite(LAND_LED,      HIGH);
}

void nav()
{
  digitalWrite(TAXI_LED,      LOW);
  digitalWrite(LAND_LED,      LOW);
  digitalWrite(NAV_WING_LED, HIGH);

  for(int i = 0; i < 6; i++){
     digitalWrite(TAIL_LED, HIGH);
     delay(75);
     digitalWrite(TAIL_LED, LOW);
     delay(75);
    }
    delay(1000);
}
