function Node(data) {

    return {
        data: data,
        next: null
    };

}

function linkedList() {

    return {

        head: null,
        size: 0,

        add: function(data) {
            if (this.size === 0) {
                this.head = Node(data);
                this.size++;
            } else {
                let newNode = Node(data);
                let current = this.head;
                while (current.next !== null) {
                    current = current.next;
                }
                current.next = newNode;
                this.size++;
            }
        },

        get: function(index) {
            let i = 0;
            let current = this.head;
            while (i <= index) {
                current = current.next;
                i++;
            }
            return current.data;
        },

        remove: function(index) {
            if (index === 0) {
                this.head = this.head.next;
                this.size--;
            } else {
                let i = 0;
                let current = this.head;
                while (i < index) {
                    current = current.next;
                    i++;
                }
                current.next = current.next.next;
                this.size--;
            }
        }

    };

}