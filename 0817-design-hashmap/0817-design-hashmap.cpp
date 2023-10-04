class MyHashMap {
private:
    map<int,int> map;
public:
    MyHashMap() {

    }
    
    void put(int key, int value) {
        map[key] = value;
    }
    
    int get(int key) {
        if(map.contains(key))
            return map[key];
        else
            return -1;
    }
    
    void remove(int key) {
        map.erase(key);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */