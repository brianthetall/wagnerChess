
enum cols {A,B,C,D,E,F,G,H};
enum rows {a,b,c,d,e,f,g,h};


typedef struct location* LocationPtr;


typedef struct location{
  void* piece;
  LocationPtr n;
  LocationPtr nw;
  LocationPtr w;
  LocationPtr sw;
  LocationPtr s;
  LocationPtr se;
  LocationPtr e;
  LocationPtr ne;

  enum cols col;
  enum rows row;
  
} Location;

void initLocation(LocationPtr,int,int);
