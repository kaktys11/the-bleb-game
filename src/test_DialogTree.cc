#include "model/DialogTree.h"
#include <string>
#include <vector>

int main() {
    DialogTree tree;
    tree.addChild(Choice("scene 0", "", "scene 0 preview"));
    tree.addChild(Choice("scene 1", "", "scene 1 preview"));
    tree.addChild(Choice("scene 2", "", "scene 2 preview"));
    tree.addChild(Choice("scene 3", "", "scene 3 preview"));
    tree.addChild(Choice("scene 4", "", "scene 4 preview"));
    tree.pointerToChild(1);
    tree.addChild(Choice("scene 2.1", "", "scene 2.1 preview"));
    tree.printTree();
    tree.pointerToRoot();


    std::vector<std::string> choices = tree.getChildrenChoiceDesc();
    for (std::string scene : choices) {
        std::cout << scene << "\n";
    }
}
