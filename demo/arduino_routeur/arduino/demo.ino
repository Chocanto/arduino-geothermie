#include <SPI.h>         // needed for Arduino versions later than 0018
#include <Ethernet.h>
#include <EthernetUdp.h>         // UDP library from: bjoern@cs.stanford.edu 12/30/2008


byte mac[] = {  
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192, 168, 0, 177);
char packetBuffer[UDP_TX_PACKET_MAX_SIZE]; //buffer to hold incoming packet,
const char mdp[7]="templz";

IPAddress ipdes(192, 168, 0, 15);
int portdest = 8888;

unsigned int localPort = 8888;      // local port to listen on

// An EthernetUDP instance to let us send and receive packets over UDP
EthernetUDP Udp;

void setup() {
  // start the Ethernet and UDP:
  Ethernet.begin(mac,ip);
  Udp.begin(localPort);
  Serial.begin(9600);
  analogReference(INTERNAL);
}

void loop() {
    int packetSize = Udp.parsePacket();
    if(packetSize){
        Udp.beginPacket(Udp.remoteIP(), 8888);
        int sensor = analogRead(A3);
        char nombre[4];
        sprintf(nombre,"%d", sensor);
        Serial.println(nombre);
        Udp.write(nombre);
        Udp.endPacket();
      
    }
    delay(2000);
}




