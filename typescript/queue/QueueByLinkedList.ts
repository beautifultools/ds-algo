import SingleLinkedList from "../linkedlist/SingleLinkedList";

class QueueByLinkedList{
    private list: SingleLinkedList;

    constructor(){
        this.list = new SingleLinkedList();
    }

    public enQueue(value:number):void {
        this.list.insertInLinkedList(value, this.list.size);
    }

    public deQueue():number {
        const node = this.list.getNode(0);
        this.list.deletionOfNode(0);
        return node.value;
    }
}
