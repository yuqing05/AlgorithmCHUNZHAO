/*
 * @Author: 周雨晴
 * @Date: 2021-01-23 21:45:59
 * @LastEditTime: 2021-01-24 14:22:06
 * @LinkPath: https://leetcode.com/problems/design-circular-deque/
 */

#include <vector>
using namespace std;

// 设计实现双端队列。
// 你的实现需要支持以下操作：
//    MyCircularDeque(k)：构造函数,双端队列的大小为k。
//    insertFront()：将一个元素添加到双端队列头部。 如果操作成功返回 true。
//    insertLast()：将一个元素添加到双端队列尾部。如果操作成功返回 true。
//    deleteFront()：从双端队列头部删除一个元素。 如果操作成功返回 true。
//    deleteLast()：从双端队列尾部删除一个元素。如果操作成功返回 true。
//    getFront()：从双端队列头部获得一个元素。如果双端队列为空，返回 -1。
//    getRear()：获得双端队列的最后一个元素。 如果双端队列为空，返回 -1。
//    isEmpty()：检查双端队列是否为空。
//    isFull()：检查双端队列是否满了。
//

class MyCircularDeque {
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k): buffer(k + 1), size(k + 1), front(0), rear(0) {
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }
        front = (front - 1 + size) % size;
        buffer[front] = value;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }
        buffer[rear] = value;
        rear = (rear + 1) % size;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }
        front = (front + 1) % size;
        return true;

    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }
        rear = (rear - 1 + size) % size;
        return true;

    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if (isEmpty()) {
            return -1;
        }
        return buffer[front];

    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if (isEmpty()) {
            return -1;
        }
        return buffer[(rear - 1 + size) % size];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return front == rear;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return (rear + 1) % size == front;
    }
private:
    vector<int> buffer;
    int front;
    int rear;
    int size;
};


/* vim: set ts=4 sw=4 sts=4 tw=100 */
