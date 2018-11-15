
// Para executar:
// gcc -c a.c
// gcc a.c -o a cg2d.o -lm -lX11
// ./a

#include "cg2d.h"

int main(int argc, char ** argv) {
  
  palette * palheta;
  bufferdevice * monitor;
  window * janela;
  viewport * porta;
  object * poligono1, * poligono2, * poligono3;
  
  SetWorld(-20, -20, 10, 15); // Define o tamanho do mundo  
  monitor = CreateBuffer(640,480); // Cria um monitor virtual
  // monitor = CreateBuffer(1024,768); // conforme solicitado
  
  palheta = CreatePalette(5);  // Cria um colormap
  SetColor(0,0,0,palheta);
  SetColor(1,0,0,palheta);
  SetColor(0,1,0,palheta);
  SetColor(0,0,1,palheta);
  SetColor(1,1,1,palheta);
  
  //Pentagano
  poligono1 = CreateObject(5);
  //Quadrado
  poligono2 = CreateObject(4);
  
  //Pontos pentagono
  SetObject(SetPoint(-7.0,-3.0,1,1), poligono1);
  SetObject(SetPoint(-4.0,-4.0,1,1), poligono1);
  SetObject(SetPoint(-3.0,-6.0,1,1), poligono1);
  SetObject(SetPoint(-6.0,-9.0,1,1), poligono1);
  SetObject(SetPoint(-9.0,-8.0,1,1), poligono1);

  //Pontos quadrado
  SetObject(SetPoint(-1.0,-2.0,1,3), poligono2);
  SetObject(SetPoint(-1.0,-6.0,1,3), poligono2);
  SetObject(SetPoint(-6.0,-6.0,1,3), poligono2);
  SetObject(SetPoint(-6.0,-2.0,1,3), poligono2);
  
  //Poligono 3 eh o poligono 1 rotacionado 75 graus
  //Junto com a rotação houve uma translação do objeto
  poligono3 = TransObj(poligono1, SetRotMatrix(75));
  
  //janela = CreateWindow(-6.0, -5.0, 0.0, 0.0);
  janela = CreateWindow(-12.0, -20.0, 12.0, 0.0);
  porta = CreateViewPort(200,100,500,300);

  DrawObject(poligono1,janela,porta,monitor,1);
  DrawObject(poligono2,janela,porta,monitor,3);
  DrawObject(poligono3,janela,porta,monitor,2); 
  

  Dump2X(monitor,palheta);
 
  return 0;
  }

