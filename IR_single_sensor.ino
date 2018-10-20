/******** start code ********/
/*
 *  created   2013-07-12
 *  by    lisper (leyapin@gmail.com)
 *  function  test gp2d12, read value from A0
 *      
 *      VCC -- VCC  
 *      GND -- GND  
 *      Signal -- Analog 0 
 */

#define pin A1

void setup () {
  Serial.begin (9600);
  pinMode (pin, INPUT);
}

void loop () {
  uint16_t value = analogRead (pin);
  uint16_t range = get_gp2d12 (value);

  Serial.println (range);


}

uint16_t get_gp2d12 (uint16_t value) {
  if (value < 10) value = 10;
  return ((67870.0 / (value - 3.0)) - 40.0)/ 10 ;
}

/******** end code ********/
