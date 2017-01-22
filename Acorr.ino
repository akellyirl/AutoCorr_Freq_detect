//#include "AltoSaxVib_C4.h"
//#include "Piano_C4_Clean.h"
//#include "Guitar_C5.h"
#include "C4.h"

// Sample Frequency in kHz
const float sample_freq = 22050;

int len = sizeof(rawData);
int i,k;
long sum, sum_old;
int thresh = 0;
float freq_per = 0;
byte pd_state = 0;
  
void setup() {
  Serial.begin(115200);

  sum = 0;
  pd_state = 0;
  int period = 0;
  for(i=0; i < len; i++)
  {
    // Autocorrelation
    sum_old = sum;
    sum = 0;
    for(k=0; k < len-i; k++) sum += (rawData[k]-128)*(rawData[k+i]-128)/256;
  /*  // RX8 [h=43] @1Key1 @0Key1
    Serial.print("C");
    Serial.write((rawData[i]-128)>>8);
    Serial.write((rawData[i]-128)&0xff); */
    
  /*  // RX8 [h=43] @1Key1 @0Key1
    Serial.print("C");
    Serial.write(sum>>8);
    Serial.write(sum&0xff); */
    
    // Peak Detect State Machine
    if (pd_state == 2 && (sum-sum_old) <=0) 
    {
      period = i;
      pd_state = 3;
    }
    if (pd_state == 1 && (sum > thresh) && (sum-sum_old) > 0) pd_state = 2;
    if (!i) {
      thresh = sum * 0.5;
      pd_state = 1;
    }
  }
  // Frequency identified in kHz
  freq_per = sample_freq/period;
  Serial.println(freq_per);
  }

void loop() {
  // put your main code here, to run repeatedly: 
  
}
