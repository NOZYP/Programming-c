namespace FuncionesRaras{
  //Oculta el cursor
  void hide() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 1;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
  }
  //Posiciona el cursor en la posicion dada
  void gotoxy(int x,int y){
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y= y;
    SetConsoleCursorPosition(hcon,dwPos);
    }
    //devuelve la posicion en x del cursor
  int WhereX (){
      CONSOLE_SCREEN_BUFFER_INFO sbi;
      GetConsoleScreenBufferInfo (GetStdHandle(STD_OUTPUT_HANDLE), &sbi);
      return sbi.dwCursorPosition.X;
  }
  //devuelve la posicion en Y del cursor
  int WhereY (){
      CONSOLE_SCREEN_BUFFER_INFO sbi;
      GetConsoleScreenBufferInfo (GetStdHandle(STD_OUTPUT_HANDLE), &sbi);
      return sbi.dwCursorPosition.Y;
  }
  //retrocede el cursor una posicion
  void CursorAtras() {
      int x=WhereX();
      int y=WhereY();
      gotoxy(x-1,y);
  }
  /*Nombre: Barritas
     Funcion: Imprime tantos guiones se necesiten para organizar la informacion
     guardada, a la hora de imprimirla.*/
  void BARRITAS(int q) {
    for (int t = 1; t <= q; t++) {
      printf("-");
    }
    printf("\n");
  }

}
