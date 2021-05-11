package hashing;

import java.util.ArrayList;
import java.util.logging.Level;

public class LinearProbing {
	String[] hashTable;
	int noOfCellsUsedInHashTable;

	LinearProbing(){
		hashTable = new String[13];
		noOfCellsUsedInHashTable = 0;
	}

	public int simpleASCIIHashFunction(String x, int M){
		char ch[];
		ch = x.toCharArray();
		int sum = 0;
		for(int i = 0; i < ch.length; i++){
			sum += ch[i];
		}

		return sum % M;
	}

	public double getLoadFactor(){
		double loadFactor = noOfCellsUsedInHashTable * 1.0 /hashTable.length;
		return loadFactor;
	}

	public void insertKeyInHashTable(String value){
		double loadFactor = getLoadFactor();
		if(loadFactor >= 0.75) {
			System.out.println("load factor of this HashTable was exceeded 0.75, hence we need to rehash");
			rehashKeys(value);
		} else {
			System.out.println("inserting \"" + value + "\" in HashTable");
			int index = simpleASCIIHashFunction(value, hashTable.length);
			for(int i = index; i < index + hashTable.length; i++){
				int newIndex = i % hashTable.length;
				if(hashTable[newIndex] == null){
					hashTable[newIndex] = value;
					System.out.println("Index: " + newIndex + " is blank. Inserting there");
					System.out.println("Succesfully inserted \"" +value + "\" in location: " +newIndex);
					System.out.println("---------------------------\n");
					break;
				} else {
					System.out.println("Index : " + newIndex + "is already occupied. Trying next empty cell...");
				}
			}
			noOfCellsUsedInHashTable++;
		}
	}

	public void rehashKeys(String newStringToBeInserted){
		noOfCellsUsedInHashTable = 0;
		ArrayList<String> data = new ArrayList<String>();
		for(String s : hashTable){
			if(s != null) data.add(s);
		}
		data.add(newStringToBeInserted);
		hashTable = new String[hashTable.length * 2]; // make new table with double size
		for(String s : data){
			insertKeyInHashTable(s);
		}
	}

	public boolean searchKeyInHashTable(String stringToBeSearched){
		int index = simpleASCIIHashFunction(stringToBeSearched, hashTable.length);
		for(int i = index; i < index + hashTable.length; i++){
			int newIndex = i % hashTable.length;
			if(hashTable[newIndex] != null && hashTable[newIndex].equals(stringToBeSearched)){
				System.out.println("\n\"" + stringToBeSearched + "\"" + " found in HashTable at location: " + newIndex);
				return true;
			}
		}
		System.out.println("\n\"" + stringToBeSearched + "\"" + " not found in HashTable ");
		return false;
	}

	public void deleteKeyFromHashTable(String stringToBeDeleted){
		int index = simpleASCIIHashFunction(stringToBeDeleted, hashTable.length);
		for (int i = index; i < index + hashTable.length; i++){
			int newIndex = i % hashTable.length;
			if(hashTable[newIndex] != null && hashTable[newIndex].equals(stringToBeDeleted)){
				hashTable[newIndex] = null;
				System.out.println("\n\"" + stringToBeDeleted + "\" has been bound in Hashtable and deleted!");
			}
		}
		System.out.println("\n\"" + stringToBeDeleted + "\"" + " not found in HashTable ");
	}

	public void displayHashTable(){
		if(hashTable == null){
			System.out.println("\nhash table does not exist!");
			return;
		} else {
			System.out.println("\n----------- Hash Table ------------");
			for(int i = 0; i < hashTable.length; i++){
				System.out.println("Index:" + i + ". Key:"+hashTable[i]);
			}
		}
		System.out.println("\n");
	}

	public void deleteHashTable(){
		hashTable = null;
		System.out.println("hash table is deleted!!");
	}
}
