class SimpleQueue{
    private arr: Array<number>;

    public enQueue(value:number):void {
        this.arr.push(value)
    }

    public deQueue():number {
        return this.arr.shift();
    }
}
