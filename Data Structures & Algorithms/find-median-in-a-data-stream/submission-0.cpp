class MedianFinder {
   private:
    priority_queue<int, vector<int>, greater<>> right;
    priority_queue<int> left;

   public:
    MedianFinder() {}

    void addNum(int num) {
        if (left.size() == 0) { left.push(num);return;}
        if (num <= left.top())
            left.push(num);
        else 
            right.push(num);

        int totalSize = left.size() + right.size();

        if (totalSize % 2 == 0) {
            while (right.size() > left.size()) {
                left.push(right.top());
                right.pop();
            }

            while (left.size() > right.size()) {
                right.push(left.top());
                left.pop();
            }
        }

        else {
            while (right.size() + 1 > left.size()) {
                left.push(right.top());
                right.pop();
            }

           while (left.size() > right.size() + 1) {
                right.push(left.top());
                left.pop();
            }
        }
    }

    double findMedian() {
        int totalSize = left.size() + right.size();

        if (totalSize%2==0){
            return (left.top() + right.top()) / 2.0;
        } else {
            return left.top();
        }
    }
};
