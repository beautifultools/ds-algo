type SingleNode = {
    value: number;
    next: SingleNode;
}

class SingleLinkedList {
    head: SingleNode | undefined;
    tail: SingleNode | undefined;

    constructor(private size: number) {
        this.head = undefined;
        this.tail = undefined;
    }

    createSingleNodeLinkedList(value:number){
        const node = {
            value, next:undefined
        };
        this.head = node;
        this.tail = node;
        this.size = 1;
        return this.head;
    }


    public insertInLinkedList(value: number, location: number): void {
        if (!this.existLinkedList()) {
            console.log("The linked list does not exist")
            return;
        }

        const node = {
            value,
            next: undefined
        };

        if (location == 0) {
            node.next = this.head;
            this.head = node;
        } else if (location >= this.size) {
            this.tail.next = node;
            this.tail = node;
        } else {
            let tempNode = this.head;
            let index = 0;
            while (index !== location - 1) {
                tempNode = tempNode.next;
                index++;
            }
            const nextNode = tempNode.next;
            tempNode.next = node;
            node.next = nextNode;
        }
        this.size++;
    }

    private existLinkedList() {
        return this.head != null;
    }

    deletionOfNode(location: number): void {
        if (!this.existLinkedList()) {
            console.log("The linked list does not exist")
            return;
        } else if (location == 0) {
            this.head = undefined;
            this.size--;
            if(this.size == 0){
                this.tail = undefined;
            }
        } else if (location >= this.size){
            let tempNode:SingleNode = this.head;
            for(let i:number = 0; i < location - 1; i++){
                tempNode = tempNode.next;
            }

            if(tempNode == this.head){
                this.head = undefined;
                this.tail = undefined;
                return;
            }

            tempNode.next = undefined;
            this.tail = tempNode;
            this.size--;
        } else {
            let tempNode:SingleNode = this.head;
            for(let i:number = 0; i < location - 1; i++){
                tempNode = tempNode.next;
            }
            tempNode.next = tempNode.next.next;
            this.size--;
        }
    }
}