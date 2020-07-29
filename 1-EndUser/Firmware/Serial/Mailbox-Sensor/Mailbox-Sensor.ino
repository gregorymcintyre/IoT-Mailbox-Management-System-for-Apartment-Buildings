#include <SPI.h>
#include <Ethernet.h>
#include <PubSubClient.h>

// Function prototypes
void subscribeReceive(char* topic, byte* payload, unsigned int length);

byte mac[]    = {0x54, 0x34, 0x41, 0x30, 0x30, 0x31};  // Ethernet shield (W5100) MAC address
IPAddress ip(10, 0, 0, 15);                           // Ethernet shield (W5100) IP address
const char* server = "broker.mqttdashboard.com";

EthernetClient ethClient;
PubSubClient mqttClient(ethClient);

int ledpin1=11;// initialize pin 11 - Green
int ledpin2=12;// initialize pin 12 - Red
int inpin=7;// initialize pin 7
int val;// define val
bool flag=false;

void reconnect(){
  // Loop until we're reconnected
  while (!mqttClient.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (mqttClient.connect("clientId-vqJHu5wipy")) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      mqttClient.publish("myTopic/mail","Init Complete");
      mqttClient.subscribe("myTopic/mail");
    } else {
      Serial.print("failed, rc=");
      Serial.print(mqttClient.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i=0;i<length;i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}

void setup(){
  Serial.begin(9600);
  Serial.print("Starting...\n");
  
  pinMode(ledpin1,OUTPUT);
  pinMode(ledpin2,OUTPUT);
  pinMode(inpin,INPUT);

  //Init W5100
  Ethernet.begin(mac, ip);
  while(!Ethernet.begin(mac)) {
    Serial.println(F("failed. Retrying in 1 seconds."));
    delay(1000);
    Serial.print(F("Starting W5100..."));
  }
  Serial.println(F("W5100 initialized"));

  
  mqttClient.setServer(server, 1883);
  mqttClient.setCallback(callback);
  
  Serial.print("Complete\n");
}

void loop(){
    if (!mqttClient.connected()) {
      //reconnect();
    }
    
    val=digitalRead(inpin);           // read the level value of pin 7 and assign if to val
    if(val==HIGH && flag==false){
      flag=true;
      Serial.print("Mail has been delivered\n");
      mqttClient.publish("testopic/mail", "Delivered");
      digitalWrite(ledpin1,LOW);
      digitalWrite(ledpin2,HIGH);
      delay(3000);
    }else if(val==LOW && flag==true){
      flag=false;
      Serial.print("Mail has been collected\n");
      mqttClient.publish("testtopic/mail", "Collected");
      digitalWrite(ledpin1,HIGH);
      digitalWrite(ledpin2,LOW);
      delay(3000);
    }else{
      //Serial.print("Standby")
    }

    mqttClient.loop();
}
    
