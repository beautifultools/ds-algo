package tree;

public class AVLTreeMain {

	public static void main(String[] args){
		AVLTree tree = new AVLTree();

		tree.insert(4);
		tree.insert(2);
		tree.insert(1);
		tree.insert(10);
		tree.insert(9);
		tree.insert(7);
		tree.printTreeGraphically();
	}
}
