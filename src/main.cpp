#include "WiFi.h"

void setup()
{
  Serial.begin(115200);
  Serial.println("Iniciando WiFi...");
  WiFi.mode(WIFI_STA);
  Serial.println("Configuração concluída!");
}

void loop()
{
  Serial.println("Procurando...");

  int qtdeRedes = WiFi.scanNetworks();
  Serial.println("Verificação concluída.");

  if (qtdeRedes == 0)
  {
    Serial.println("Nenhuma rede encontrada.");
  }
  else
  {
    Serial.print("Total de rede(s) encontrada(s): ");
    Serial.println(qtdeRedes);

    for (int i = 0; i < qtdeRedes; i++)
    {
      Serial.print(i + 1);
      Serial.print(": ");

      Serial.print(WiFi.SSID(i)); // nome da rede encontrada
      Serial.print(" - Sinal (");

      Serial.print(WiFi.RSSI(i)); // intensidade do sinal
      Serial.print(") - Possui senha? ");

      Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN) ? "Não" : "Sim");
      delay(10);
    }

    Serial.println("Verificando a rede aberta com melhor sinal");
    for (int i = 0; i < qtdeRedes; ++i)
    {
      if (WiFi.encryptionType(i) == WIFI_AUTH_OPEN)
      {
        Serial.println("Rede aberta com melhor sinal: ");
        Serial.print("Nome da Rede: ");
        Serial.print(WiFi.SSID(i));
        Serial.print(" - Sinal: ");
        Serial.print(WiFi.RSSI(i));
        Serial.println();
        break;
      }
    }

    delay(5000);
  }
}