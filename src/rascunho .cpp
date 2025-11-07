//---------------------------BLUETOOTH SLAVE
/*#include <Arduino.h>
#include <BluetoothSerial.h>

BluetoothSerial BT;


void setup() {
 Serial.begin(9600);
 Serial.setTimeout(5000);

 if (BT.begin("EspSlaveJuly"))
 {
  Serial.println("Bluetooth iniciado com sucesso");
  Serial.print("Endereço bluetooth ESP: ");
  Serial.println(BT.getBtAddressString());

 }else
 {
  Serial.println("Erro ao iniciar bluetooth");
 }
 
 

}

void loop() {
  if (BT.available())
  {
    String mensagemRecebida = BT.readStringUntil('\n');
    mensagemRecebida.trim();
    Serial.printf("Mensagem recebida: %s", mensagemRecebida);
  }

  if (Serial.available())
  {
    String mensagemEnviar = Serial.readStringUntil('\n');
    mensagemEnviar.trim();
    BT.println(mensagemEnviar);
  }
  
  

}*/


//------------------ BLUETOOTH MASTER
#include <Arduino.h>
#include <BluetoothSerial.h>

BluetoothSerial BT;
//14:33:5C:0B:2B:76
u_int8_t enderecoSlave[] = {0xF4, 0x65, 0x0B, 0x54, 0xA3, 0x86};

void setup(){
  Serial.begin(9600);
  Serial.setTimeout(5000);

  if (BT.begin("EspMasterJuly", true))
  {
    Serial.println("Bluetooth iniciado com sucesso");
  }else
  {
    Serial.println("eRRO ao iniciar o bluetoth");
  }
  
  if (BT.connect(enderecoSlave))
  {
    Serial.println("Conectado com sucesso");
  }else
  {
    Serial.println("Erro ao conectar");
  }

}
  
  
  void loop() {
  if (BT.available())
  {
    String mensagemRecebida = BT.readStringUntil('\n');
    mensagemRecebida.trim();
    Serial.print('\n');
    Serial.printf("Mensagem recebida: %s", mensagemRecebida);
  }

  if (Serial.available())
  {
    String mensagemEnviar = Serial.readStringUntil('\n');
    mensagemEnviar.trim();
    BT.println(mensagemEnviar);
  }

}