#include "gui.h"
#include <fstream>

Gui::Gui(){
  
  initscr();
  cbreak();                   /* immediate char return */
  //noecho();                   /* no immediate echo */
  boardwin = newwin(BDEPTH * 2 + 1, BWIDTH * 4 + 1, BOARDY, BOARDX);
  movewin = newwin(1,30,21,0);
  gravewin = newwin(18,14,BOARDY-2,BOARDX+4*8+3);
  scrollok(movewin, TRUE);
  keypad(movewin, TRUE);

  if (has_colors()) {
    int bg = COLOR_BLACK;
    start_color();
  }


}

int Gui::graveyard(Piece *p, Player *player,Player *attacker){

  if ( p!= nullptr && player!=nullptr){
    //add this piece to the player's graveyard
    player->addToGraveyard(p);

    init_pair(1, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);

    //refresh the gravewin from gui
    werase(gravewin);
    mvwaddstr(gravewin,0,0,"Grave Yard: ");

    if(player->toString() == "white")
      wattron(gravewin,COLOR_PAIR(1));
    else
      wattron(gravewin,COLOR_PAIR(2));
    
    int i=2;
    mvwaddstr(gravewin,1,0,player->toString().data());
    for(auto& piece : player->getDeadPieces()){
      mvwaddstr(gravewin,i++,4,piece->toString().data());
    }
    wattroff(gravewin,COLOR_PAIR(1));
    wattroff(gravewin,COLOR_PAIR(2));

    
    if(attacker->toString() == "white")
      wattron(gravewin,COLOR_PAIR(1));
    else
      wattron(gravewin,COLOR_PAIR(2));

    i=2;
    mvwaddstr(gravewin,1,8,attacker->toString().data());
    for(auto& piece : attacker->getDeadPieces()){
      mvwaddstr(gravewin,i++,12,piece->toString().data());
    }
    wattroff(gravewin,COLOR_PAIR(1));
    wattroff(gravewin,COLOR_PAIR(2));
    

  }else{return -1;}

  refresh();
  wrefresh(gravewin);
  return 0;

}

void Gui::dosquares(void){
  int i, j;

  mvaddstr(0, 13, "Wagner Chess");
  mvaddstr(1,4,"0   1   2   3   4   5   6   7");
  mvaddstr(19,4,"0   1   2   3   4   5   6   7");

  char c='A';
  for(i=0;i<=7;i++){

    mvaddch(3+i*2,1,c);
    mvaddch(3+i*2,35,c++);

  }

  //    init_pair(3, COLOR_WHITE, COLOR_BLACK);
    
    
  move(BOARDY, BOARDX);
  waddch(boardwin, ACS_ULCORNER);
  for (j = 0; j < 7; j++) {
    waddch(boardwin, ACS_HLINE);
    waddch(boardwin, ACS_HLINE);
    waddch(boardwin, ACS_HLINE);
    waddch(boardwin, ACS_TTEE);
  }
  waddch(boardwin, ACS_HLINE);
  waddch(boardwin, ACS_HLINE);
  waddch(boardwin, ACS_HLINE);
  waddch(boardwin, ACS_URCORNER);

  for (i = 1; i < BDEPTH; i++) {
    move(BOARDY + i * 2 - 1, BOARDX);
    waddch(boardwin, ACS_VLINE);
    for (j = 0; j < BWIDTH; j++) {
      waddch(boardwin, ' ');
      waddch(boardwin, ' ');
      waddch(boardwin, ' ');
      waddch(boardwin, ACS_VLINE);
    }
    move(BOARDY + i * 2, BOARDX);
    waddch(boardwin, ACS_LTEE);
    for (j = 0; j < BWIDTH - 1; j++) {
      waddch(boardwin, ACS_HLINE);
      waddch(boardwin, ACS_HLINE);
      waddch(boardwin, ACS_HLINE);
      waddch(boardwin, ACS_PLUS);
    }
    waddch(boardwin, ACS_HLINE);
    waddch(boardwin, ACS_HLINE);
    waddch(boardwin, ACS_HLINE);
    waddch(boardwin, ACS_RTEE);
  }

  move(BOARDY + i * 2 - 1, BOARDX);
  waddch(boardwin, ACS_VLINE);
  for (j = 0; j < BWIDTH; j++) {
    waddch(boardwin, ' ');
    waddch(boardwin, ' ');
    waddch(boardwin, ' ');
    waddch(boardwin, ACS_VLINE);
  }

  move(BOARDY + i * 2, BOARDX);
  waddch(boardwin, ACS_LLCORNER);
  for (j = 0; j < BWIDTH - 1; j++) {
    waddch(boardwin, ACS_HLINE);
    waddch(boardwin, ACS_HLINE);
    waddch(boardwin, ACS_HLINE);
    waddch(boardwin, ACS_BTEE);
  }
  waddch(boardwin, ACS_HLINE);
  waddch(boardwin, ACS_HLINE);
  waddch(boardwin, ACS_HLINE);
  waddch(boardwin, ACS_LRCORNER);
}

string Gui::update(map<Coordinate*,Piece*> pieces, bool isTurn){

  werase(boardwin);
  
  dosquares();
  
  ofstream debug;
  debug.open("debug");

  for(auto& element : pieces){
    
    Coordinate *c=element.first;
    Piece *p=element.second;

    debug<<p->toString()<<endl;
    
    int row=int(c->getRow()-65);//subtract 65 from row
    int col=c->getCol();

    debug<<"Row:"<<row<<" Col:"<<col<<endl;

    cellmove(row,col);

    const char *s=p->toString().data();

    debug<<"Adding s[0]="<<s[0]<<endl;

    start_color();
    init_pair(1, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);

    if(p->getColor()==Color::WHITE)
      wattron(boardwin,COLOR_PAIR(1));
    else
      wattron(boardwin,COLOR_PAIR(2));
    
    waddch(boardwin,s[0]);
    wattroff(boardwin,COLOR_PAIR(1));
    wattroff(boardwin,COLOR_PAIR(2));

  }



  refresh();
  wrefresh(boardwin);
  wrefresh(movewin);

  if(isTurn){
    mvwaddstr(movewin,0,0,"Enter Move: ");
    refresh();
    wrefresh(movewin);

    char move[16];
    mvwgetnstr(movewin,0,12,&move[0], 16);
    debug<<"asshat"<<endl;
    debug << "move=" << move << endl;
    return string{move};
  }
  
  debug.close();
  return string{""};//if not isTurn

}
