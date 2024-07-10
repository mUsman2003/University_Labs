void deleteFixup(Node* x) {
    while (x != root && (x == nullptr || x->color == 1)) {
        if (x == x->parent->left) {
            Node* w = x->parent->right;
            if (w->color == 0) {
                w->color = 1;
                x->parent->color = 0;
                leftRotate(x->parent);
                w = x->parent->right;
            }
            if ((w->left == nullptr || w->left->color == 1) &&
                (w->right == nullptr || w->right->color == 1)) {
                w->color = 0;
                x = x->parent;
            } else {
                if (w->right == nullptr || w->right->color == 1) {
                    if (w->left != nullptr) {
                        w->left->color = 1;
                    }
                    w->color = 0;
                    rightRotate(w);
                    w = x->parent->right;
                }
                w->color = x->parent->color;
                x->parent->color = 1;
                if (w->right != nullptr) {
                    w->right->color = 1;
                }
                leftRotate(x->parent);
                x = root;
            }
        } else {
            Node* w = x->parent->left;
            if (w->color == 0) {
                w->color = 1;
                x->parent->color = 0;
                rightRotate(x->parent);
                w = x->parent->left;
            }
            if ((w->right == nullptr || w->right->color == 1) &&
                (w->left == nullptr || w->left->color == 1)) {
                w->color = 0;
                x = x->parent;
            } else {
                if (w->left == nullptr || w->left->color == 1) {
                    if (w->right != nullptr) {
                        w->right->color = 1;
                    }
                    w->color = 0;
                    leftRotate(w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = 1;
                if (w->left != nullptr) {
                    w->left->color = 1;
                }
                rightRotate(x->parent);
                x = root;
            }
        }
    }
    if (x != nullptr) {
        x->color = 1;
    }
}