#include <iostream>
#include <string>
using namespace std;

class Node{
    public:

    bool endOfWord;
    Node* children[26];

    Node(){

        endOfWord = false;
        for(int i = 0; i < 26; ++i){
            children[i] = NULL;
        }

    }

};

class Trie {

private:

    Node* head;

public:

    Trie() {
        head = new Node();
    }

    void insert(string word) {

        int letter = 0;
        Node* cur = head;

        for(int i = 0; i < word.size(); ++i){

            letter = word[i] - 'a'; // gives index a = 0 through z = 25

            if(cur->children[letter]==NULL){
                cur->children[letter] = new Node();
            }
            cur = cur->children[letter];

        }

        cur->endOfWord = true;
        cout << "'" << word << "' inserted successfully" << endl;
    }

    bool search(string word) {

        int letter = 0;
        Node* cur = head;

        for(int i = 0; i < word.length(); ++i){

            letter = word[i] - 'a';

            if(cur->children[letter] == NULL){
                cout << "'" << word << "' not found" << endl;
                return false;
            }else{
                cur = cur->children[letter];
            }

        }

        if(cur->endOfWord == false){
            cout << "'" << word << "' is not a full word, but is in the trie" << endl;
        }else{
            cout << "'" << word << "' is a word!" << endl;
        }

        return (cur->endOfWord == true);
    }

    bool startsWith(string prefix) {

        int letter = 0;
        Node* cur = head;

        for(int i = 0; i < prefix.length(); ++i){

            letter = prefix[i] - 'a';

            if(cur->children[letter]==NULL){
                cout << "'" << prefix << "' prefix not found" << endl;
                return false;
            }

            cur = cur->children[letter];

        }

        cout << "'" << prefix << "' prefix found" << endl;
        return true;
    }

};

int main(){

    Trie tree;

    string ap = "apple";
    string ba = "banana";
    string ab = "abacus";
    string ban = "ban";
    string app = "app";

    tree.insert(ap);
    tree.search(ap);
    tree.startsWith(ab);
    tree.startsWith(ban);
    tree.insert(ba);
    tree.search(ba);
    tree.startsWith(ban);
    tree.search(app);

}