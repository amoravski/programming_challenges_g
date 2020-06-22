#include"BinTrees.cpp"

int sumInOrder(const Node<int>* root, double sum, int &nodes)
{
	if (!root) return 0 ;
    nodes++;
	return root->data + sumInOrder(root->left,sum,nodes) + sumInOrder(root->right,sum,nodes);
}


int main(int argc, char const* argv[])
{
	Node<int>* root = nullptr;
    int nodes = 0;
    createTree(root);
    std::cout << sumInOrder(root, 0, nodes) / nodes;
    return 0;
}
