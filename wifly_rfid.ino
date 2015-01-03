#include <WiFlyHQ.h>
#include <SoftwareSerial.h>

SoftwareSerial RFID(12, 13);
SoftwareSerial wifiSerial(8, 9);

// Wifi configuration for a WPA network.
const char mySSID[] = "your_SSID";
const char myPassword[] = "Your_password";
WiFly wifly;
String S="";

void setup()
{
  // Setup ports.
  Serial.begin(9600);
  Serial.println("Serial Ready");
  RFID.begin(9600);
  Serial.println("RFID Ready");
  wifiSerial.begin(9600);
  

  wifiSerial.listen(); //new thing 1
  
  if (!wifly.begin(&wifiSerial, &Serial)) {
        Serial.println(F("Failed to start wifly"));
	wifly.terminal();
     }

    /* Join wifi network if not already associated */
    if (!wifly.isAssociated()) {
	/* Setup the WiFly to connect to a wifi network */
	Serial.println(F("Joining network"));
	wifly.setSSID(mySSID);
	wifly.setPassphrase(myPassword);
	wifly.enableDHCP();
	wifly.save();
	if (wifly.join()) {
	    Serial.println(F("Joined wifi network"));
	} else {
	    Serial.println(F("Failed to join wifi network"));
	    wifly.terminal();
	}
    } else {
        Serial.println(F("Already joined network"));
    }

}

void loop () {  

  
int index =0 ;  
char unit;
String msg;
int flag=0;
int count;

RFID.listen();//new thing 2

while(RFID.available()>0){

unit = RFID.read();
index++;
msg += unit;
 
if(index == 12)  {

if(msg==S)
	{
		flag=1;
	}

if(flag==0)
{

 S=msg;
 Serial.print("Tag ID: ");
 Serial.println(msg);}
 wifiSerial.listen();

 if(wifly.open("example.com", 80)){
     Serial.print("done");
     wifly.println( "POST /your_http_request HTTP/1.1");
     wifly.println();
     wifly.close();
 }
}

}
count++;   
}
