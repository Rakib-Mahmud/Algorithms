#include<bits/stdc++.h>

using namespace std;

class Trie
{
public:
    map<char,Trie*>children;
    //Trie *children[70];
    bool endOfword;

    Trie(){
        this->endOfword=false;
//        for(int i=0;i<70;i++){
//            this->children[i]=nullptr;
//        }
    }

    void Insert(string word);
    bool Search(string word);
    void delAll();
    bool recursive_dlt(Trie *root,string word,int indx);
    bool Delete(string word){
        Trie *root=this;
        return recursive_dlt(root,word,0);
    }
    void dfs(Trie *curr);
};

int map_index_creator(char ch) {
	if (ch <= '9') return ch - '0';
	if (ch <= 'Z') return ch - 'A' + 10;
	return ch - 'a' + 36;
}

void Trie ::Insert(string word)
{
    Trie *curr=this;
    int ln=word.size();
    for(int i=0;i<ln;i++){
        char ch=word[i];
        Trie *node=curr->children[ch];
        if(node==nullptr){
            node=new Trie();
            curr->children[ch]=node;
        }
        curr=node;
    }
    curr->endOfword=true;
}

bool Trie ::Search(string word)
{
    if(this==nullptr)return false;

    Trie *curr=this;
    int ln=word.size();
    for(int i=0;i<ln;i++){
        char ch=word[i];
        Trie *tmp=curr->children[ch];
        if(tmp==nullptr){
            return false;
        }
        curr=tmp;
    }
    return curr->endOfword;
}

bool Trie ::recursive_dlt(Trie *root,string word,int indx)
{
    if(indx==word.size()){
        if(!(root->endOfword))return false;
        root->endOfword=false;
        return root->children.empty();
    }

    char ch=word[indx];
    Trie *node=root->children[ch];
    if(node==nullptr){
        return false;
    }
    bool shouldDelete=recursive_dlt(node,word,indx+1);

    if(shouldDelete){
        root->children.erase(ch);
        if(root==this)return true;
        return root->children.empty();
    }
    return false;

}

void Trie ::delAll()
{
		for(int i = 0; i < 10; i++)
			if(children[i] != NULL)
			{
				children[i]->delAll();
				delete children[i];
			}
}

map<char,Trie*>::iterator it;
void Trie ::dfs(Trie *curr)
{
    if(curr==nullptr){
        return;
    }
    map<char,Trie*>::iterator it;
    for(it=curr->children.begin();it!=curr->children.end();it++){
        dfs(it->second);
        cout<<it->first<<" ";
    }
}

int main()
{
   Trie *root=new Trie();
   ///cout<<root->Delete("rakib")<<endl;
   root->Insert("rakib");
   root->Insert("Noor");
   ///cout<<root->Search("rakib")<<endl;
   ///cout<<root->Search("Noor")<<endl;
   root->Insert("rahim");
   root->dfs(root);cout<<endl;
   cout<<root->Search("rahim")<<endl;
   cout<<root->Delete("rahim")<<endl;
   ///cout<<root->Search("rahim")<<endl;
   ///cout<<root->Search("rakib")<<endl;
   root->Insert("rahim");
   cout<<root->Search("rahim")<<endl;
   Trie *ob=new Trie();
   ob->Insert("rakib");
   ob->Insert("rahim");
   cout<<ob->Delete("rakib")<<endl;
   cout<<ob->Search("rakib")<<endl;
}
