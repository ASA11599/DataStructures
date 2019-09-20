class Node {
    constructor(data, under) {
        this.data = data;
        this.under = under;
    }
}


class Stack {

    constructor() {
        this.top = null;
    }

    isEmpty() {
        return this.top === null;
    }

    push(item) {
        this.top = new Node(item, this.top);
    }

    peek() {
        return this.top.data;
    }

    pop() {
        const res = this.peek();
        this.top = this.top.under;
        return res;
    }

}