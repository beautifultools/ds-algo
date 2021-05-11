package trie;

import java.util.HashMap;
import java.util.Map;

public class Trie {

	private class TrieNode {
		Map<Character, TrieNode> children;
		boolean endOfWord;

		public TrieNode(){
			children = new HashMap<>();
			endOfWord = false;
		}
	}

	private final TrieNode root;

	public Trie() { root = new TrieNode();}

	public void insert(String word){
		TrieNode current = root;
		for (int i = 0; i < word.length(); i++){
			char ch = word.charAt(i);
			TrieNode node = current.children.get(ch);
			if( node == null ){
				node = new TrieNode();
				current.children.put(ch, node);
			}
			current = node;
		}
		current.endOfWord = true;
		System.out.println("Successfully inserte" + word+"\" in Trie");
	}

	public boolean search(String word){
		TrieNode currentNode = root;
		for (int i = 0; i < word.length(); i++){
			char ch = word.charAt(i);
			TrieNode node = currentNode.children.get(ch);
			if(node == null) return false;
			currentNode = node;
		}
		return currentNode.endOfWord == true;
	}

	public void delete(String word){
		if(search(word) == true){
			delete(root, word, 0);
		}
	}

	// CASE#1 -- Some other word's prefix is same as Prefix of this word (BCDE, BCKG)
	// CASE#2 -- We are at last character of this word and This word is a Prefix of some other word (BCDE, BCDEFG)
	// CASE#3 -- Some other word is a Prefix of this word (BCDE, BC)
	// CASE#4 -- No one is dependent on this Word (BCDE, BCDE)
	private boolean delete(TrieNode parentNode, String word, int index) {
		char ch = word.charAt(index);
		TrieNode currentNode = parentNode.children.get(ch);

		boolean canThisNodeBeDeleted;

		if(currentNode.children.size() > 1){
			System.out.println("Entering Case # 1");
			delete(currentNode, word, index + 1);
		}

		if(index == word.length() -1){
			if(currentNode.children.size() >= 1){
				System.out.println("Entering Case#2");
				currentNode.endOfWord = false;
				return false;
			} else {
				parentNode.children.remove(ch);
				return true;
			}
		}

		canThisNodeBeDeleted = delete(currentNode, word, index+1);

		if(currentNode.endOfWord == true) {// CASE#3
			System.out.println("Entering Case#3");
			delete(currentNode, word, index+1);
			return false;
		}

		System.out.println("Entering Case#4");
		if(canThisNodeBeDeleted == true){
			System.out.println("Character \"" + ch + " has no dependency, hence deleting it");
			parentNode.children.remove(ch);
			return true;
		} else {
			return false;
		}
	}
}
