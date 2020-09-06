#include "player.h"

Player::Player(string c,unordered_map<string,Location*> locs):color{c},locations{locs}{

  if(color=="white"){
    pieces["king"]=unique_ptr<Piece>{new King(PieceType::KING,Color::WHITE,locations["H1"])};
    pieces["queen"]=unique_ptr<Piece>{new King(PieceType::QUEEN,Color::WHITE,locations["G0"])};
    pieces["bishop1"]=unique_ptr<Piece>{new King(PieceType::BISHOP,Color::WHITE,locations["H2"])};
    pieces["bishop2"]=unique_ptr<Piece>{new King(PieceType::BISHOP,Color::WHITE,locations["F0"])};
    pieces["knight1"]=unique_ptr<Piece>{new King(PieceType::KNIGHT,Color::WHITE,locations["H3"])};
    pieces["knight2"]=unique_ptr<Piece>{new King(PieceType::KNIGHT,Color::WHITE,locations["E0"])};
    pieces["rook1"]=unique_ptr<Piece>{new King(PieceType::ROOK,Color::WHITE,locations["H4"])};
    pieces["rook2"]=unique_ptr<Piece>{new King(PieceType::ROOK,Color::WHITE,locations["D0"])};
    
    pieces["pawn1"]=unique_ptr<Piece>{new King(PieceType::PAWN,Color::WHITE,locations["H0"])};
    pieces["pawn2"]=unique_ptr<Piece>{new King(PieceType::PAWN,Color::WHITE,locations["F1"])};
    pieces["pawn3"]=unique_ptr<Piece>{new King(PieceType::PAWN,Color::WHITE,locations["G2"])};
    pieces["pawn4"]=unique_ptr<Piece>{new King(PieceType::PAWN,Color::WHITE,locations["E3"])};
    pieces["pawn5"]=unique_ptr<Piece>{new King(PieceType::PAWN,Color::WHITE,locations["F2"])};
    pieces["pawn6"]=unique_ptr<Piece>{new King(PieceType::PAWN,Color::WHITE,locations["G3"])};
    pieces["pawn7"]=unique_ptr<Piece>{new King(PieceType::PAWN,Color::WHITE,locations["G1"])};
    pieces["pawn8"]=unique_ptr<Piece>{new King(PieceType::PAWN,Color::WHITE,locations["E1"])};

  }

  else{//black

    pieces["king"]=unique_ptr<Piece>{new King(PieceType::KING,Color::BLACK,locations["B7"])};
    pieces["queen"]=unique_ptr<Piece>{new King(PieceType::QUEEN,Color::BLACK,locations["A6"])};
    pieces["bishop1"]=unique_ptr<Piece>{new King(PieceType::BISHOP,Color::BLACK,locations["A5"])};
    pieces["bishop2"]=unique_ptr<Piece>{new King(PieceType::BISHOP,Color::BLACK,locations["C7"])};
    pieces["knight1"]=unique_ptr<Piece>{new King(PieceType::KNIGHT,Color::BLACK,locations["A4"])};
    pieces["knight2"]=unique_ptr<Piece>{new King(PieceType::KNIGHT,Color::BLACK,locations["D7"])};
    pieces["rook1"]=unique_ptr<Piece>{new King(PieceType::ROOK,Color::BLACK,locations["A3"])};
    pieces["rook2"]=unique_ptr<Piece>{new King(PieceType::ROOK,Color::BLACK,locations["E7"])};
    
    pieces["pawn1"]=unique_ptr<Piece>{new King(PieceType::PAWN,Color::BLACK,locations["A7"])};
    pieces["pawn2"]=unique_ptr<Piece>{new King(PieceType::PAWN,Color::BLACK,locations["C6"])};
    pieces["pawn3"]=unique_ptr<Piece>{new King(PieceType::PAWN,Color::BLACK,locations["B5"])};
    pieces["pawn4"]=unique_ptr<Piece>{new King(PieceType::PAWN,Color::BLACK,locations["B4"])};
    pieces["pawn5"]=unique_ptr<Piece>{new King(PieceType::PAWN,Color::BLACK,locations["C5"])};
    pieces["pawn6"]=unique_ptr<Piece>{new King(PieceType::PAWN,Color::BLACK,locations["D4"])};
    pieces["pawn7"]=unique_ptr<Piece>{new King(PieceType::PAWN,Color::BLACK,locations["B6"])};
    pieces["pawn8"]=unique_ptr<Piece>{new King(PieceType::PAWN,Color::BLACK,locations["D6"])};


  }
  
  cout<<"COMPLETED SETUP OF "<<toString()<<'\n';
    
  };


string Player::toString() const{
  return "Player: " + color;
}
