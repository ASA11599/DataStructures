class Node {
    constructor(data, next) {
        this.data = data;
        this.next = next;
    }
}


class Queue {

    constructor() {
        this.front = null;
        this.back = null;
    }

    isEmpty() {
        return (this.front === null) && (this.back === null);
    }

    enqueue(item) {
        if (this.isEmpty()) {
            this.front = this.back = Node(item, null);
        } else {
            const newNode = Node(item, null);
            this.back.next = newNode;
            this.back = newNode;
        }
    }

    dequeue() {
        if (this.isEmpty()) {
            return undefined;
        } else {
            res = this.front.data;
            this.front = this.front.next;
            this.back = this.front === null ? null : this.back;
            return res;
        }
    }

}