#include <SPI.h>
#include <Ethernet.h>
//#include <EtherCard.h>


byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};

EthernetServer server(80);

int numPins = 5;
int pins[]={10, 11, 12, 13};
int pinState[]={0, 0, 0, 0};
char line1[100];

void setup()
{
  for (int i = 0; i < numPins; i++)
  {
    pinMode(pins[i], OUTPUT);
  }
  Serial.begin(9600);
  Ethernet.begin(mac);
  server.begin();
  Serial.print("Servidor ligado on:");
  Serial.println(Ethernet.localIP());
}

void loop() {
  EthernetClient client = server.available();
  if (client)
  {
    while (client.connected())
    {
      readHeader(client);
      if (! pageNameIs("/"))
      {
        client.stop();
        return;
      }
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println();

      //envie o corpo (body) do arquivo html ao navegador
      client.println("<html><body>");
      client.println("<h1>Output pins</h1>");
      client.println("<form method='GET'>");
      setValuesFromParams();
      setPinStates();
      for (int i = 0; i < numPins; i++)
      {
        writeHTMLforPin(client, i);
      }
      client.println("<input type='submit' value='Update'/>");
      client.println("</form>");
      client.println("</body></html>");

      client.stop();
    }
  }
}

void writeHTMLforPin(EthernetClient client, int i)
  {
    client.print("<p>D");
    client.print(pins[i]);
    client.print("<select name='");
    client.print(i);
    client.println("'>");
    client.print("<option value='0'");
    if (pinState[i] == 0)
    {
      client.print("selected");
    }
    client.println(">Off</option>");
    client.print ("<option value='1'");
    if (pinState[i] == 1)
    {
      client.print(" selected");
    }
    client.println(">On</option>");
    client.println("</select></p>");
  }

  void setPinStates()
  {
    int i = 0;
    for (int i = 0; i < numPins; i++);
    {
      digitalWrite(pins[i], pinState[i]);
    }
  }

  void setValuesFromParams()
  {
    for(int i = 0; i < numPins; i++)
    {
      pinState[i] = valueOfParam(i + '0');
    }
  }

  void readHeader(EthernetClient client)
  {
    char ch;
    int i = 0;
    while (ch !='\n')
    {
      if (client.available())
      {
        ch = client.read();
        line1[i] = ch;
        i ++;
      }
    }
    line1 [i] ="\0";
    Serial.println(line1);
  }
  boolean pageNameIs (char* name)
  {
    int i = 4;
    char ch = line1[i];
    while (ch != ' ' && ch != '\n' && ch != '?')
    {
      if (name[i-4] != line1[i])
      {
        return false;
      }
      i++;
      ch = line1[i];
    }
    return true;
  }

  int valueOfParam(char param)
  {
    for (int i = 0; i < strlen(line1); i++)
    {
      if (line1[i] == param && line1[i+1] == '=')
      {
        return (line1[i+2] - '0');
      }
    }
    return 0;
  }