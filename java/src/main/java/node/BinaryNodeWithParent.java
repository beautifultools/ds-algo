package node;

import lombok.Data;

@Data
public class BinaryNodeWithParent {
	private int value;
	private int height;
	private BinaryNodeWithParent left;
	private BinaryNodeWithParent right;
}
