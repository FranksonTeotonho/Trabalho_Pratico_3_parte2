
// Para executar:
// gcc -c cg2d.c
// gcc exemplo_2d.c -o exemplo_2d cg2d.o -lm -lX11
// ./exemplo_2d

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
  
  poligono1 = CreateObject(9);
  poligono2 = CreateObject(5);
  poligono3 = CreateObject(6);
  
  SetObject(SetPoint(-11,-1.0,1,3), poligono1);
  SetObject(SetPoint(-11.0,-11.0,1,3), poligono1);
  SetObject(SetPoint(-4.0,-11.0,1,3), poligono1);
  SetObject(SetPoint(-2.0,-9.0,1,3), poligono1);
  SetObject(SetPoint(-2.0,-7.0,1,3), poligono1);
  SetObject(SetPoint(-4.0,-5.0,1,3), poligono1);
  SetObject(SetPoint(-3.0,-4.0,1,3), poligono1);
  SetObject(SetPoint(-3.0,-2.0,1,3), poligono1);
  SetObject(SetPoint(-4.0,-1.0,1,3), poligono1);

  
  SetObject(SetPoint(-10.0,-2.0,1,3), poligono2);
  SetObject(SetPoint(-5.0,-2.0,1,3), poligono2);
  SetObject(SetPoint(-4.0,-3.0,1,3), poligono2);
  SetObject(SetPoint(-5.0,-4.0,1,3), poligono2);
  SetObject(SetPoint(-10.0,-4.0,1,3), poligono2);

  SetObject(SetPoint(-10.0,-6.0,1,3), poligono3);
  SetObject(SetPoint(-5.0,-6.0,1,3), poligono3);
  SetObject(SetPoint(-4.0,-7.0,1,3), poligono3);
  SetObject(SetPoint(-4.0,-8.0,1,3), poligono3);
  SetObject(SetPoint(-5.0,-9.0,1,3), poligono3);
  SetObject(SetPoint(-10.0,-9.0,1,3), poligono3);
  
  //janela = CreateWindow(-20.0, -20.0, 10.0, 15.0);
  //porta = CreateViewPort(0, 0, 639, 479);
  janela = CreateWindow(-12.0, -12.0, 0.0, 0.0);
  porta = CreateViewPort(195,115,445,365);

  DrawObject(poligono1,janela,porta,monitor,3);
  DrawObject(poligono2,janela,porta,monitor,3);
  DrawObject(poligono3,janela,porta,monitor,3); 
  

  Dump2X(monitor,palheta);
 
  return 0;
  }

