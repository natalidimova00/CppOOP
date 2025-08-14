#include <iostream>
#include <cstring>
#include <vector>

struct ChessPosition{
    char file; // 'A'-'H'
    int rank;  // 1-8

    ChessPosition(char f = 'A', int r = 1) : file(f), rank(r) {}

    bool isValid() const {
        return file >= 'A' && file <= 'H' && rank >= 1 && rank <= 8;
    }

    bool operator==(const ChessPosition& other) const {
        return file == other.file && rank == other.rank;
    }
};

class ChessPiece{
protected:
    ChessPosition pos;
public:
    ChessPiece(const ChessPosition& p) : pos(p) {}
    virtual ~ChessPiece() {}
    
    ChessPosition getPosition() const {
        return pos;
    }

    virtual std::string getType() const = 0;

    virtual std::vector<ChessPosition> allowedMoves() const = 0;

    bool wins(const ChessPosition& target) const {
        std::vector<ChessPosition> moves = allowedMoves();
        for (size_t i = 0; i < moves.size(); i++){
            if (moves[i] == target) return true;
        }
        return false;
    }

    void setPosition(const ChessPosition& newPos) { pos = newPos; }
};

class Rook : public ChessPiece {
public:
    Rook(const ChessPosition& p) : ChessPiece(p) {}

    std::string getType() const { return "Rook"; }

    std::vector<ChessPosition> allowedMoves() const {
        std::vector<ChessPosition> moves;
        for (char f = 'A'; f <= 'H'; f++) {
            if (f != pos.file) moves.push_back(ChessPosition(f, pos.rank));
        }
        for (int r = 1; r <= 8; r++) {
            if (r != pos.rank) moves.push_back(ChessPosition(pos.file, r));;
        }
        return moves;
    }
};

class Knight : public ChessPiece {
public:
    Knight(const ChessPosition& p) : ChessPiece(p) {}

    std::string getType() const { return "Knight"; }

    std::vector<ChessPosition> allowedMoves() const {
        std::vector<ChessPosition> moves;
        int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
        int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};
        for (int i = 0; i < 8; i++) {
            char nf = pos.file + dx[i];
            int nr = pos.rank + dy[i];
            ChessPosition np(nf, nr);
            if (np.isValid()) moves.push_back(np);
        }
        return moves;
    }
};

bool isStable(const std::vector<ChessPiece*>& pieces) {
    for (size_t i = 0; i < pieces.size(); i++) {
        for (size_t j = 0; j < pieces.size(); j++) {
            if (i != j) {
                if (pieces[i]->wins(pieces[j]->getPosition())) {
                    return false;
                }
            }
        }
    }
    return true;
}

void allMoves(std::vector<ChessPiece*>& pieces) {
    for (size_t i = 0; i < pieces.size(); i++) {
        ChessPiece* piece = pieces[i];
        ChessPosition oldPos = piece->getPosition();
        std::vector<ChessPosition> moves = piece->allowedMoves();

        for (size_t m = 0; m < moves.size(); m++) {
            piece->setPosition(moves[m]);
            if (isStable(pieces)) {
                std:: cout << piece->getType() << " " 
                           << oldPos.file << oldPos.rank << " -> "
                           << moves[m].file << moves[m].rank << std::endl;
            }
        }
        piece->setPosition(oldPos);
    }
}

int main() {
    std::vector<ChessPiece*> pieces;

    pieces.push_back(new Rook(ChessPosition('A', 1)));
    pieces.push_back(new Knight(ChessPosition('B', 3)));

    allMoves(pieces);

    for (size_t i = 0; i < pieces.size(); i++) {
        delete pieces[i];
    }
    
    return 0;
}