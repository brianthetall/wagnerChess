#include "player.h"

Player::Player(string c,unordered_map<string,Location*> locs):color{c},locations{locs}{

  if(color=="white"){
    pieces["king"]=shared_ptr<Piece>{new King(PieceType::KING,Color::WHITE,locations["H1"])};
    pieces["queen"]=shared_ptr<Piece>{new Queen(PieceType::QUEEN,Color::WHITE,locations["G0"])};
    pieces["bishop1"]=shared_ptr<Piece>{new Bishop(PieceType::BISHOP,Color::WHITE,locations["H2"])};
    pieces["bishop2"]=shared_ptr<Piece>{new Bishop(PieceType::BISHOP,Color::WHITE,locations["F0"])};
    pieces["knight1"]=shared_ptr<Piece>{new Knight(PieceType::KNIGHT,Color::WHITE,locations["H3"])};
    pieces["knight2"]=shared_ptr<Piece>{new Knight(PieceType::KNIGHT,Color::WHITE,locations["E0"])};
    pieces["rook1"]=shared_ptr<Piece>{new Rook(PieceType::ROOK,Color::WHITE,locations["H4"])};
    pieces["rook2"]=shared_ptr<Piece>{new Rook(PieceType::ROOK,Color::WHITE,locations["D0"])};
    
    pieces["pawn1"]=shared_ptr<Piece>{new Pawn(PieceType::PAWN,Color::WHITE,locations["H0"])};
    pieces["pawn2"]=shared_ptr<Piece>{new Pawn(PieceType::PAWN,Color::WHITE,locations["F1"])};
    pieces["pawn3"]=shared_ptr<Piece>{new Pawn(PieceType::PAWN,Color::WHITE,locations["G2"])};
    pieces["pawn4"]=shared_ptr<Piece>{new Pawn(PieceType::PAWN,Color::WHITE,locations["E3"])};
    pieces["pawn5"]=shared_ptr<Piece>{new Pawn(PieceType::PAWN,Color::WHITE,locations["F2"])};
    pieces["pawn6"]=shared_ptr<Piece>{new Pawn(PieceType::PAWN,Color::WHITE,locations["G3"])};
    pieces["pawn7"]=shared_ptr<Piece>{new Pawn(PieceType::PAWN,Color::WHITE,locations["G1"])};
    pieces["pawn8"]=shared_ptr<Piece>{new Pawn(PieceType::PAWN,Color::WHITE,locations["E1"])};

  }

  else{//black

    pieces["king"]=shared_ptr<Piece>{new King(PieceType::KING,Color::BLACK,locations["B7"])};
    pieces["queen"]=shared_ptr<Piece>{new Queen(PieceType::QUEEN,Color::BLACK,locations["A6"])};
    pieces["bishop1"]=shared_ptr<Piece>{new Bishop(PieceType::BISHOP,Color::BLACK,locations["A5"])};
    pieces["bishop2"]=shared_ptr<Piece>{new Bishop(PieceType::BISHOP,Color::BLACK,locations["C7"])};
    pieces["knight1"]=shared_ptr<Piece>{new Knight(PieceType::KNIGHT,Color::BLACK,locations["A4"])};
    pieces["knight2"]=shared_ptr<Piece>{new Knight(PieceType::KNIGHT,Color::BLACK,locations["D7"])};
    pieces["rook1"]=shared_ptr<Piece>{new Rook(PieceType::ROOK,Color::BLACK,locations["A3"])};
    pieces["rook2"]=shared_ptr<Piece>{new Rook(PieceType::ROOK,Color::BLACK,locations["E7"])};
    
    pieces["pawn1"]=shared_ptr<Piece>{new Pawn(PieceType::PAWN,Color::BLACK,locations["A7"])};
    pieces["pawn2"]=shared_ptr<Piece>{new Pawn(PieceType::PAWN,Color::BLACK,locations["C6"])};
    pieces["pawn3"]=shared_ptr<Piece>{new Pawn(PieceType::PAWN,Color::BLACK,locations["B5"])};
    pieces["pawn4"]=shared_ptr<Piece>{new Pawn(PieceType::PAWN,Color::BLACK,locations["B4"])};
    pieces["pawn5"]=shared_ptr<Piece>{new Pawn(PieceType::PAWN,Color::BLACK,locations["C5"])};
    pieces["pawn6"]=shared_ptr<Piece>{new Pawn(PieceType::PAWN,Color::BLACK,locations["D4"])};
    pieces["pawn7"]=shared_ptr<Piece>{new Pawn(PieceType::PAWN,Color::BLACK,locations["B6"])};
    pieces["pawn8"]=shared_ptr<Piece>{new Pawn(PieceType::PAWN,Color::BLACK,locations["D6"])};


  }
      
  };


string Player::toString() {  
  return color;
}

int Player::addToGraveyard(Piece *p){

  if ( p==nullptr )
    return -1;

  //Add to the graveYard map:
  deadPieces.push_back(p);

  return 0;

}
