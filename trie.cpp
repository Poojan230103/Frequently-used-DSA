struct Node{
	Node* links[26];
	bool flag = false;

	bool containskey(char ch){
		return (links[ch - 'a'] != NULL);
	}

	void insertkey(char ch, Node* ref)
	{
		links[ch - 'a'] = ref;
	}

	Node* getkey(char ch){
		return links[ch - 'a'];
	}

};

class Trie
{
private: Node* root;

public:
	
	Trie()
	{
		root = new Node;
	}

	void insert(string word)
	{
		Node* current = root;
		for(int i = 0;i < word.length(); i++)
		{
			if(!current->containskey(word[i]))
			{
				current->insertkey(word[i],new Node);
			}
			current = current->getkey(word[i]);
		}
		current->flag = true;
	}

	bool search(string word)
	{
		Node* current = root;
		for(int i = 0;i < word.length(); i++)
		{
			if(!current->containskey(word[i])){
				return false;
			}
			else{
				current = current->getkey(word[i]);
			}
		}
		return current->flag;
	}

	bool beginswith(string word)
	{
		Node* current = root;
		for(int i = 0;i < word.length(); i++)
		{
			if(!current->containskey(word[i])){
				return false;
			}
			else{
				current = current->getkey(word[i]);
			}	
		}
		return true;
	}
};
