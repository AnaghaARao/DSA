#include<bits/stdc++.h>
using namespace std;

template <typename V>
class MapNode{
    public:
        string key;
        V value;
        MapNode* next;

        MapNode(string key, V value){
            this->key = key;
            this->value = value;
            next = NULL;
        }
        ~MapNode(){
            delete next;
        }
};

template <typename V>
class myMap{
    MapNode<V>** buckets;
    int count;
    int numBuckets;

    public:
        myMap(){
            count = 0;
            numBuckets = 5;
            buckets = new MapNode<V>*[numBuckets];
            for(int i = 0 ; i < numBuckets ; i++){
                buckets[i] = NULL;
            }
        }

        ~myMap(){
            for(int i = 0 ; i < numBuckets ; i++){
                delete buckets[i];
            }
            delete [] buckets;
        }

        int size(){
            return count;
        }

        V getValue(string key){
            int bucketIndex = getBucketIndex(key);
            MapNode<V>* head = buckets[bucketIndex];
            while(head != NULL){
                if(head->key == key){
                    return head->value;
                }
                head = head->next;
            }
            return 0; // default
        }
    
    private:
        int getBucketIndex(string key){
            int hashcode = 0;
            int currentCoeff = 1;
            for(int i = key.length()-1 ; i >= 0 ; i--){
                hashcode += key[i] * currentCoeff;
                hashcode = hashcode % numBuckets;
                currentCoeff *= 37;
                currentCoeff = currentCoeff % numBuckets
            }
            return hashcode % numBuckets;
        }

    public:
        void insert(string key, V value){
            int bucketIndex = getBucketIndex(key);
            MapNode<V>* head = buckets[bucketIndex];
            while(head != NULL){
                if(head->key == key){
                    head->value = value;
                    return;
                }
                head = head->next;
            }
            head = buckets[bucketIndex];
            MapNode<V>* node = new MapNode<V>(key, value);
            node->next = head;
            buckets[bucketIndex] = node;
            count++;

        }

        V remove(string key){
            int bucketIndex = getBucketIndex(key);
            MapNode<V>* head = buckets[bucketIndex];
            MapNode<V>* prev = NULL;
            V val;
            while(head != NULL){
                if(head->key == key){
                    val = head->next;
                    if(prev == NULL){
                        buckets[bucketIndex] = head->next;
                        break;
                    }else{
                        prev->next = head->next;
                    }
                    head->next = NULL;
                    delete head;
                    count--;
                    return val;
                }
                prev = head;
                head = head->next;
            }
            return 0; // default
        } 
};