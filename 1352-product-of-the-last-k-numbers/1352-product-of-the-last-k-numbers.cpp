class ProductOfNumbers {
public:
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        container.push_back(num);
    }
    
    int getProduct(int k) {
        auto it = container.rbegin();
        int product = 1;
        for (int i = 0; i < k; i++){
            product *= *it;
            it++;
        }
        return product;
    }

private:
    vector<int> container;
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */