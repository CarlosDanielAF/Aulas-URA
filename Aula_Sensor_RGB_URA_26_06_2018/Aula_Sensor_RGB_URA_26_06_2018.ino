//Pinos de conexao do modulo TCS230  
const int s0 = 9;  
const int s1 = 8;  
const int s2 = 4;  
const int s3 = 5;  
const int out = 3;   
    
//Variaveis que armazenam o valor das cores  
int red = 0;  
int green = 0;  
int blue = 0;  
    
void setup()   
{  
  pinMode(s0, OUTPUT);  
  pinMode(s1, OUTPUT);  
  pinMode(s2, OUTPUT);  
  pinMode(s3, OUTPUT);  
  pinMode(out, INPUT);  
 
  Serial.begin(9600);  
  
  digitalWrite(s0, HIGH);  
  digitalWrite(s1, HIGH);  
}  
    
void loop() 
{  
  color(); //Chama a rotina que le as cores  
  //Mostra no serial monitor os valores detectados  
  Serial.print("Vermelho:");  
  Serial.print(red, DEC);  
  Serial.print(" Verde:");  
  Serial.print(green, DEC);  
  Serial.print(" Azul:");  
  Serial.print(blue, DEC);  
  Serial.println();  
  delay(500);
  
  //Verifica se a cor vermelha foi detectada  
  if (red < blue && red < green && red < 100)  
  {  
   Serial.println("Vermelho");  
  
  }  

  //Verifica se a cor azul foi detectada  
  else if (blue < red && blue < green)   
  {  
   Serial.println("Azul");  
  
  }  

  //Verifica se a cor verde foi detectada  
  else if (green < red && green < blue)  
  {  
   Serial.println("Verde");  
  }  
 
   Serial.println();  

 }  
    
void color()  
{  
  //Rotina que le o valor das cores  
  digitalWrite(s2, LOW);  
  digitalWrite(s3, LOW);  
  //count OUT, pRed, RED  
  red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s3, HIGH);  
  //count OUT, pBLUE, BLUE  
  blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s2, HIGH);  
  //count OUT, pGreen, GREEN  
  green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
}
