#include <EtherCard.h>

#define STATIC 0  // set to 1 to disable DHCP (adjust myip/gwip values below)

// mac address
static byte mymac[] = { 0x74,0x69,0x69,0x2D,0x30,0x31 };
// ethernet interface ip address
static byte myip[] = { 192,168,0,200 };
// gateway ip address
static byte gwip[] = { 192,168,0,1 };

// LED to control output
int ledPin10 = 5;

int valIntensidade = 0;

byte Ethernet::buffer[500];

const char page[] PROGMEM =
"HTTP/1.0 503 Service Unavailable\r\n"
"Content-Type: text/html\r\n"
"Retry-After: 600\r\n"
"\r\n"
"<html>"
  "<head><title>"
    "Arduino example"
  "</title></head>"
  "<body>"
    "<h3>Arduino example</h3>"
    "<p><em>"
      "Arduino example"
      "Arduino example"
    "</em></p>"
  "</body>"
"</html>"
;

void setup () {
  pinMode(ledPin10, OUTPUT);

  Serial.begin(9600);
  Serial.println("Trying to get an IP...");

  Serial.print("MAC: ");
  for (byte i = 0; i < 6; ++i) {
    Serial.print(mymac[i], HEX);
    if (i < 5)
      Serial.print(':');
  }
  Serial.println();
  
  if (ether.begin(sizeof Ethernet::buffer, mymac) == 0) 
    Serial.println( "Failed to access Ethernet controller");

#if STATIC
  Serial.println( "Getting static IP.");
  if (!ether.staticSetup(myip, gwip)){
    Serial.println( "could not get a static IP");
    blinkLed();     // blink forever to indicate a problem
  }
#else

  Serial.println("Setting up DHCP");
  if (!ether.dhcpSetup()){
    Serial.println( "DHCP failed");
    blinkLed();     // blink forever to indicate a problem
  }
#endif
  
  ether.printIp("My IP: ", ether.myip);
  ether.printIp("Netmask: ", ether.myip);
  ether.printIp("GW IP: ", ether.gwip);
  ether.printIp("DNS IP: ", ether.dnsip);
}

void loop () {
 
  word len = ether.packetReceive();
  word pos = ether.packetLoop(len);

  // IF LED10=ON turn it ON
  if(strstr((char *)Ethernet::buffer + pos, "GET /?LED10=ON") != 0) {
      Serial.println("Received ON command");
      analogWrite(ledPin10, 0);
      valIntensidade = 0;
    }

    // IF LED10=OFF turn it OFF  
    if(strstr((char *)Ethernet::buffer + pos, "GET /?LED10=OFF") != 0) {
      Serial.println("Received OFF command");
      analogWrite(ledPin10, 0);
    }

    if(strstr((char *)Ethernet::buffer + pos, "GET /?LED10=MAIS") != 0) {
      Serial.println("Received MAIS command");
      digitalWrite(ledPin10, HIGH);
      if (valIntensidade <= 255 || valIntensidade >=0){
        valIntensidade = valIntensidade + 51;
        analogWrite(ledPin10,valIntensidade);
      }
    }

    // IF LED10=OFF turn it OFF  
    if(strstr((char *)Ethernet::buffer + pos, "GET /?LED10=MENOS") != 0) {
      Serial.println("Received MENOS command");
      digitalWrite(ledPin10, LOW);
      if (valIntensidade <= 255 || valIntensidade >=0){
        valIntensidade = valIntensidade - 51;
        analogWrite(ledPin10,valIntensidade);
      }
    }


    // show some data to the user
    memcpy_P(ether.tcpOffset(), page, sizeof page);
    ether.httpServerReply(sizeof page - 1);
}

void blinkLed(){
  while (true){
    digitalWrite(ledPin10, HIGH);
    delay(500);
    digitalWrite(ledPin10, LOW);
    delay(500);
  }
}