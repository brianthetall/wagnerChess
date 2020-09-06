#include "player.h"

Player::Player(string c,unordered_map<string,Location*> locs):color{c},locations{locs}{

  if(color=="white"){
    pieces["king"]=unique_ptr<Piece>{new King(PieceType::KING,locations["H1"])};
    pieces["queen"]=unique_ptr<Piece>{new King(PieceType::QUEEN,locations["G0"])};
    pieces["bishop1"]=unique_ptr<Piece>{new King(PieceType::BISHOP,locations["H2"])};
    pieces["bishop2"]=unique_ptr<Piece>{new King(PieceType::BISHOP,locations["F0"])};
    pieces["knight1"]=unique_ptr<Piece>{new King(PieceType::KNIGHT,locations["H3"])};
    pieces["knight2"]=unique_ptr<Piece>{new King(PieceType::KNIGHT,locations["E0"])};
    pieces["rook1"]=unique_ptr<Piece>{new King(PieceType::ROOK,locations["H4"])};
    pieces["rook2"]=unique_ptr<Piece>{new King(PieceType::ROOK,locations["D0"])};
    
    pieces["pawn1"]=unique_ptr<Piece>{new King(PieceType::PAWN,locations["H0"])};
    pieces["pawn2"]=unique_ptr<Piece>{new King(PieceType::PAWN,locations["F1"])};
    pieces["pawn3"]=unique_ptr<Piece>{new King(PieceType::PAWN,locations["G2"])};
    pieces["pawn4"]=unique_ptr<Piece>{new King(PieceType::PAWN,locations["E3"])};
    pieces["pawn5"]=unique_ptr<Piece>{new King(PieceType::PAWN,locations["F2"])};
    pieces["pawn6"]=unique_ptr<Piece>{new King(PieceType::PAWN,locations["G3"])};
    pieces["pawn7"]=unique_ptr<Piece>{new King(PieceType::PAWN,locations["G1"])};
    pieces["pawn8"]=unique_ptr<Piece>{new King(PieceType::PAWN,locations["E1"])};

  }

  else{//black

    pieces["king"]=unique_ptr<Piece>{new King(PieceType::KING,locations["B7"])};
    pieces["queen"]=unique_ptr<Piece>{new King(PieceType::QUEEN,locations["A6"])};
    pieces["bishop1"]=unique_ptr<Piece>{new King(PieceType::BISHOP,locations["A5"])};
    pieces["bishop2"]=unique_ptr<Piece>{new King(PieceType::BISHOP,locations["C7"])};
    pieces["knight1"]=unique_ptr<Piece>{new King(PieceType::KNIGHT,locations["A4"])};
    pieces["knight2"]=unique_ptr<Piece>{new King(PieceType::KNIGHT,locations["D7"])};
    pieces["rook1"]=unique_ptr<Piece>{new King(PieceType::ROOK,locations["A3"])};
    pieces["rook2"]=unique_ptr<Piece>{new King(PieceType::ROOK,locations["E7"])};
    
    pieces["pawn1"]=unique_ptr<Piece>{new King(PieceType::PAWN,locations["A7"])};
    pieces["pawn2"]=unique_ptr<Piece>{new King(PieceType::PAWN,locations["C6"])};
    pieces["pawn3"]=unique_ptr<Piece>{new King(PieceType::PAWN,locations["B5"])};
    pieces["pawn4"]=unique_ptr<Piece>{new King(PieceType::PAWN,locations["B4"])};
    pieces["pawn5"]=unique_ptr<Piece>{new King(PieceType::PAWN,locations["C5"])};
    pieces["pawn6"]=unique_ptr<Piece>{new King(PieceType::PAWN,locations["D4"])};
    pieces["pawn7"]=unique_ptr<Piece>{new King(PieceType::PAWN,locations["B6"])};
    pieces["pawn8"]=unique_ptr<Piece>{new King(PieceType::PAWN,locations["D6"])};


  }
  
  cout<<"COMPLETED SETUP OF "<<toString()<<'\n';
    
  };


string Player::toString() const{
  return "Player: " + color;
}
