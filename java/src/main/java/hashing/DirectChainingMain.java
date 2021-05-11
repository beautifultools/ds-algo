package hashing;

import java.util.LinkedList;

public class DirectChainingMain {
	public static void main(String[] args){
		DirectChaining directChaining = new DirectChaining();

		directChaining.insertKeyInHashTable("The");
		directChaining.insertKeyInHashTable("quick");
		directChaining.insertKeyInHashTable("brown");
		directChaining.insertKeyInHashTable("fox");
		directChaining.insertKeyInHashTable("over");
		directChaining.insertKeyInHashTable("lazy");
		directChaining.displayHashTable();

		directChaining.insertKeyInHashTable("fox"); // use for showing collision
		directChaining.displayHashTable();

		directChaining.insertKeyInHashTable("fox");
		directChaining.displayHashTable();

		directChaining.insertKeyInHashTable("fox");
		directChaining.displayHashTable();

		directChaining.insertKeyInHashTable("fox");
		directChaining.displayHashTable();
	}
}
