typedef struct location* LocPtr;


typedef struct location{
  void* piece;
  LocPtr n;
  LocPtr nw;
  LocPtr w;
  LocPtr sw;
  LocPtr s;
  LocPtr se;
  LocPtr e;
  LocPtr ne;
  
} Location;

