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

TypePiece Piece::getType() {
    return type;
}

void Piece::setPosition(PositionPiece pos) {
    position = pos;
}






