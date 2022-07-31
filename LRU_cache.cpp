

//Lru cache - least recently used cache 
// we iumplement this using a map and a doubly linked list
//here we can make get and set function in o(1)time
//and its use cases are in browser and also OS cahces and everyhwere where we want to keep the 
//track of recently used items.



  struct Node{
      Node*prev;
      Node*next;
      int data;
      int key_val;
      
      
      Node(int x, int y)
      {
          data =x;
          key_val=y;
          prev=NULL;
          next=NULL;
      }
    };

class LRUCache
{
    private:

    public:
    //Constructor for initializing the cache capacity with the given value.
  
    
    
    Node* head= new Node(-1,-1);
    Node* tail= new Node(-1,-1);
  
    map<int,Node*>mymap;
    int maxsize;
    
    
    LRUCache(int cap)
    {
        // code here
        head->next=tail;
        tail->prev=head;
        maxsize=cap;
    }
    
    
    //Function to return value corresponding to the key.
    int get(int key)
    {
        
        if(mymap.find(key)==mymap.end())return -1;
        
        
        mymap[key]->prev->next=mymap[key]->next;
        mymap[key]->next->prev= mymap[key]->prev;
        
        Node*temp= head->next;
        mymap[key]->prev=head;
        head->next= mymap[key];
        mymap[key]->next=temp;
        temp->prev=mymap[key];
        
        return mymap[key]->data;
        // your code here
    }
    
    //Function for storing key-value pair.
    void set(int key, int value)
    {
        // your code here
        if(mymap.find(key)==mymap.end())
        {
            if(mymap.size()==maxsize)
            {
                //remove least recently used ie tail ke paas wala and add this 
                //to head
                
                Node*temp= tail->prev;
                mymap.erase(temp->key_val);
                temp->prev->next= tail;
                tail->prev= temp->prev;
                
                //add the new to head ke baju mein
                
                temp= new Node(value,key);
                mymap[key]=temp;
                
                Node*tp= head->next;
                temp->next=tp;
                temp->prev=head;
                
                head->next=temp;
                tp->prev=temp;
                
            }
            else
            {
                  
               Node* temp= new Node(value,key);
                mymap[key]=temp;
                
                Node*tp= head->next;
                temp->next=tp;
                temp->prev=head;
                
                head->next=temp;
                tp->prev=temp;
            }
        }
        else
        {
            
        mymap[key]->prev->next=mymap[key]->next;
        mymap[key]->next->prev= mymap[key]->prev;
        
        Node*temp= head->next;
        mymap[key]->prev=head;
        head->next= mymap[key];
        mymap[key]->next=temp;
        temp->prev=mymap[key];
        mymap[key]->data= value;
        
        }
    }
};
