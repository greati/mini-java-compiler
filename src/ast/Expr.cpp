#include "ast/NodeVisitor.h"
#include "ast/Expr.h"

void Id::accept(NodeVisitor & visitor) {
    visitor.visitId(this);
};

void ConstructList::accept(NodeVisitor & visitor) {
    visitor.visitConstructList(this);
}
