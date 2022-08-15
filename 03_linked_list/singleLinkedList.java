class Node {
    public int data;
    public Node next;

    public Node(int data) {
        this.data = data;
        this.next = null;
    }
}

public class UserSolution {

    private final static int MAX_NODE = 10000;

    private Node[] node = new Node[MAX_NODE];
    private int nodeCnt = 0;
    private Node head;

    public Node getNode(int data) {
        node[nodeCnt] = new Node(data);
        return node[nodeCnt++];
    }

    public void init() {
        node = new Node[MAX_NODE];
        nodeCnt = 0;
        head = null;
    }

    public void addNode2Head(int data) {
        if (head == null) {
            head = getNode(data);
            return;
        }

        nodeCnt++;
        int count = nodeCnt;
        while (count > 0) {
            node[count] = node[count-1];
            count--;
        }
        Node tmp = head;
        head = new Node(data);
        head.next = tmp;
        node[count] = head;

    }

    public void addNode2Tail(int data) {
        if (head == null) {
            head = getNode(data);
            return;
        }
        Node cur = head;
        while (cur.next != null) {
            cur = cur.next;
        }
        cur.next = getNode(data);
    }

    public void addNode2Num(int data, int num) {
        num--;
        if (num == 0) {
            addNode2Head(data);
            return;
        }

        if (num+1 > nodeCnt) {
            addNode2Tail(data);
            return;
        }

        Node previous = head;
        for(int i = 0; i < num - 1; i++) {
            previous = previous.next;
        }
        Node next = previous.next;

        Node newNode = new Node(data);
        previous.next = newNode;
        newNode.next = next;

        nodeCnt++;
        int count = nodeCnt;
        while (count > num) {
            node[count] = node[count-1];
            count--;
        }
        node[count] = newNode;
    }

    public void removeNode(int data) {
        for(int i = 0; i < nodeCnt; i++){
            if (node[i].data == data) {
                if (i == 0) {
                    for(int j = i; j < nodeCnt-1; j++){
                        node[j] = node[j+1];
                    }
                    node[nodeCnt] = null;
                    nodeCnt--;
                    return;
                }
                int previousIndex = i - 1;
                int nextIndex = i + 1;
                if (nodeCnt == nextIndex) {
                    node[previousIndex].next = null;
                    node[i] = null;
                    nodeCnt--;
                    return;
                } else {
                    node[previousIndex].next = node[nextIndex];
                    node[i] = null;
                    for(int j = i; j < nodeCnt-1; j++){
                        node[j] = node[j+1];
                    }
                    node[nodeCnt] = null;
                    nodeCnt--;
                    return;
                }
            }
        }

    }

    public int getList(int[] output) {
        for(int i = 0; i < nodeCnt; i++){
            output[i] = node[i].data;
        }
        return nodeCnt;
    }
}
