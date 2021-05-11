package tree;

import java.util.LinkedList;
import java.util.Queue;

import lombok.Data;
import node.BinaryNode;

@Data
public class AVLTree {
	BinaryNode root;

	AVLTree(){root = null;}

	void insert(int value){
		root = insert(root, value);
	}

	BinaryNode insert(BinaryNode currentNode, int value){
		if(currentNode == null){
			return createNewNode(value);
		} else if(value == currentNode.getValue()){
			return currentNode;
		} else if(currentNode.getValue() > value) {
			currentNode.setRight(insert(currentNode.getRight(), value));
		} else {
			currentNode.setLeft(insert(currentNode.getLeft(), value));
		}

		int balance = checkBalance(currentNode.getLeft(), currentNode.getRight());
		if(balance > 1){
			if (checkBalance(currentNode.getLeft().getLeft(), currentNode.getLeft().getRight()) <= 0) {
				currentNode.setLeft(leftRotate(currentNode.getLeft()));
			}
			currentNode = rightRotate(currentNode);
		} else if(balance < -1){
			if (checkBalance(currentNode.getRight().getLeft(), currentNode.getRight().getRight()) >= 0) {
				currentNode.setRight(rightRotate(currentNode.getRight()));
			}
			currentNode = leftRotate(currentNode);
		}

		return currentNode;
	}

	private BinaryNode leftRotate(BinaryNode currentNode){
		BinaryNode newRoot = currentNode.getRight();
		currentNode.setRight(newRoot.getLeft());
		newRoot.setLeft(currentNode);
		currentNode.setHeight(calculateHeight(currentNode));
		newRoot.setHeight(calculateHeight(newRoot));
		return newRoot;
	}

	private BinaryNode rightRotate(BinaryNode currentNode){
		BinaryNode newRoot = currentNode.getLeft();
		currentNode.setLeft(newRoot.getRight());
		newRoot.setRight(currentNode);
		currentNode.setHeight(calculateHeight(currentNode));
		newRoot.setHeight(calculateHeight(newRoot));
		return newRoot;
	}

	private int checkBalance(BinaryNode rootLeft, BinaryNode rootRight){
		if(rootLeft == null && rootRight == null){
			return 0;
		} if(rootLeft == null){
			return -1*(rootRight.getHeight()+1);
		} if(rootRight == null){
			return rootLeft.getHeight()+1;
		} else {
			return rootLeft.getHeight() - rootRight.getHeight();
		}
	}

	private int calculateHeight(BinaryNode currentNode){
		if(currentNode == null) {
			return 0;
		}
		return 1 + Math.max(currentNode.getLeft() != null?currentNode.getLeft().getHeight():-1,
			currentNode.getRight() != null?currentNode.getRight().getHeight():-1);
	}

	private BinaryNode createNewNode(int value) {
		BinaryNode newNode = new BinaryNode();
		newNode.setValue(value);
		newNode.setHeight(0);
		return newNode;
	}


	void levelOrderTraversal(){
		if(getRoot() == null) return;

		Queue<BinaryNode> queue = new LinkedList<>();
		queue.add(getRoot());

		while(!queue.isEmpty()){
			BinaryNode targetNode = queue.poll();
			System.out.println(targetNode);

			if(targetNode.getLeft() != null) queue.add(targetNode.getLeft());
			if(targetNode.getRight() != null) queue.add(targetNode.getRight());
		}
	}

	public void deleteNodeOfBST(int value){
		root = deleteNodeOfBST(root, value);
	}

	public BinaryNode deleteNodeOfBST(BinaryNode currentNode, int value){
		if(currentNode == null) return null;

		if(value <currentNode.getValue()){
			currentNode.setRight(deleteNodeOfBST(currentNode.getRight(), value));
		} else if(value > currentNode.getValue()){
			currentNode.setLeft(deleteNodeOfBST(currentNode.getLeft(), value));
		} else {
			if(currentNode.getLeft() != null && currentNode.getRight() != null){
				BinaryNode temp = currentNode;
				BinaryNode minNodeForRight = minimumElement(temp.getRight());
				currentNode.setValue(minNodeForRight.getValue());
				deleteNodeOfBST(currentNode.getRight(), minNodeForRight.getValue());
			} else if(currentNode.getLeft() != null){
				currentNode = currentNode.getLeft();
			} else if(currentNode.getRight() != null){
				currentNode = currentNode.getRight();
			} else {
				currentNode = null;
			}

			// TODO: 1/30/21 Is this need to return currentNode here?
			return currentNode;
		}

		int balance = checkBalance(currentNode.getLeft(), currentNode.getRight());

		if(balance > 0){
			// left의 balance가 0일 때는 불필요하게 leftRotate 할필요가 없다고 판단되어 기존 코드에 있던 등호 제거
			if (checkBalance(currentNode.getLeft().getLeft(), currentNode.getLeft().getRight()) < 0) {
				currentNode.setLeft(leftRotate(currentNode.getLeft()));
			}
			currentNode = rightRotate(currentNode);
		} else if (balance < 0){
			// right의 balance가 0일 때는 불필요하게 rightRotate 할필요가 없다고 판단되어 기존 코드에 있던 등호 제거
			if (checkBalance(currentNode.getRight().getLeft(), currentNode.getRight().getRight()) >= 0) {
				currentNode.setRight(rightRotate(currentNode.getRight()));
			}
			currentNode = leftRotate(currentNode);
		}

		return currentNode;
	}

	public static BinaryNode minimumElement(BinaryNode root){
		if(root.getLeft() == null)
			return root;
		else
			return minimumElement(root.getLeft());
	}

	// TODO: 1/30/21 Study
	void printTreeGraphically(){
		Queue<BinaryNode> queue = new LinkedList<>();
		Queue<Integer> level = new LinkedList<>();

		int CurrentLevel = 1;
		boolean previousLevelWasAllNull = false;
		queue.add(root);
		level.add(1);

		if(root == null){
			return;
		}

		while (!queue.isEmpty()){
			if(CurrentLevel == level.peek()){
				if(queue.peek() == null){
					queue.add(null); level.add(CurrentLevel + 1);
				} else {
					queue.add(queue.peek().getLeft());level.add(CurrentLevel+1);
					queue.add(queue.peek().getRight());level.add(CurrentLevel+1);
					previousLevelWasAllNull = false;
				}
				System.out.print(queue.remove() + " "); level.remove();
			} else {
				System.out.println("\n");
				CurrentLevel++;
				if(previousLevelWasAllNull == true){
					break;
				}
				previousLevelWasAllNull = true;
			}
		}
	}
}
