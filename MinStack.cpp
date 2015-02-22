class MinStack {
public:
    MinStack() {
        // do initialization if necessary

    }

    void push(int number) {
        // write your code here
        mainStack.push(number);
        if(minStack.empty()||number<=minStack.top()) 
            minStack.push(number);
    }

    int pop() {
        // write your code here
        int num=mainStack.top();
        mainStack.pop();
        if(num==minStack.top()) minStack.pop();
        return num;
    }

    int min() {
        // write your code here
        return minStack.top();
    }

private:
    stack<int> mainStack;
    stack<int> minStack;
};

