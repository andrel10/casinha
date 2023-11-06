#include <EtherCard.h>

// Caso queira definir um ip estático mude de 0 para 1
#define STATIC 0 

#if STATIC
// Endereço IP estático a ser definido a interface Ethernet
static byte myip[] = { 192,168,1,200 };
// Endereço IP do Gateway da sua rede
static byte gwip[] = { 192,168,1,1 };
#endif

// MAC Address da interface ethernet - deve ser único na sua rede local
static byte mymac[] = { 0x74,0x69,0x69,0x2D,0x30,0x31 };

byte Ethernet::buffer[500];

const char page[] PROGMEM =
   "HTTP/1.0 200 OK\r\n"
   "Content-Type: text/html\r\n"
   "Refresh: 5\r\n"
   "\r\n"
   "<html>"
   "   <head>"
   "      <title>Arduino Web Server</title>"
   "   </head>"
   "   <body>"
   "      <h3>Página resposta do seu Arduino.</h3>"
   "      <p><em>fabiotomio.com.br.<br />=D</em></p>"
   "   </body>"
   "</html>"
;

void setup(){
   Serial.begin(9600);
   Serial.println("\n[webserver]");

   if (ether.begin(sizeof Ethernet::buffer, mymac) == 0)
      Serial.println( "Failed to access Ethernet controller");
   #if STATIC
      ether.staticSetup(myip, gwip);
   #else
      if (!ether.dhcpSetup())
         Serial.println("DHCP failed");
   #endif

   ether.printIp("IP: ", ether.myip);
   ether.printIp("GW: ", ether.gwip);
   ether.printIp("DNS: ", ether.dnsip);
}

void loop(){
   if (ether.packetLoop(ether.packetReceive())) {
      memcpy_P(ether.tcpOffset(), page, sizeof page);
      ether.httpServerReply(sizeof page - 1);
   }
}