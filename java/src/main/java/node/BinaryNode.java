package node;

import lombok.Data;
import lombok.ToString;

@Data
public class BinaryNode {
	private int value;
	private int height;
	private BinaryNode left;
	private BinaryNode right;
	private BinaryNode parent;

	public String toString(){
		return value + "";
	}
}
