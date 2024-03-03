#include "Piece.h"

Piece::Piece() {
}

Piece::~Piece() {
}

CouleurPiece Piece::getCouleur() {
    return couleur;
}

PositionPiece Piece::getPosition() {
    return position;
}

void Piece::setPosition(PositionPiece pos) {
    position = pos;
}





