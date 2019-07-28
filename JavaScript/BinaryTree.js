function BinaryTree() {
    function Node(item, leftNode, rightNode) {
        return {
            value: item,
            left: leftNode,
            right: rightNode
        }
    }
    return {
        root: null,
        add: function(item) {
            if (this.root === null) {
              this.root = Node(item, null, null);
              return;
            }
            let current = this.root;
            while (current != null) {
                if (item === current.value) return;
                if (item > current.value) {
                    if (current.right === null) {
                      current.right = Node(item, null, null)
                      return;
                    } else {
                      current = current.right;
                    }
                } else if (item < current.value) {
                    if (current.left === null) {
                      current.left = Node(item, null, null);
                      return;
                    } else {
                      current = current.left;
                    }
                }
            }
            current = Node(item, null, null);
        },
        contains: function(item) {
            let current = this.root;
            while (current != null) {
                if (item === current.value) return true;
                if (item > current.value) {
                    current = current.right;
                } else if (item < current.value) {
                    current = current.left;
                }
            }
            return false;
        }
    }
}