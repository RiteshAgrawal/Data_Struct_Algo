__author__ = 'ritesh'


class Node(object):
    """
        Node for the linked list
    """

    def __init__(self, value):
        """
            param: value for the node
        """
        self.value = value
        self.next = None


class LinkedList:
    """
        Linked List
    """

    def __init__(self):
        self.root = None

    def insert_begin(self, value):
        """
            Insert an element in the beginning of the linked list
        """
        new_node = Node(value)
        if self.root is None:
            self.root = new_node
        else:
            new_node.next = self.root
            self.root = new_node

    def insert_end(self, value):
        """
            Insert element in the end of the linked list
        """
        new_node = Node(value)
        if self.root is None:
            self.root = new_node
            return
        iteration_node = self.root
        while iteration_node.next is not None:
            iteration_node = iteration_node.next
        iteration_node.next = new_node

    def show(self):
        """
            Print all the elements of the linked list
        """
        node = self.root
        if node is None:
            return 'Linked list is empty'
        answer = ''
        while node is not None:
            # Not to display arrow after last node
            if node.next is not None:
                answer += str(node.value) + '->'
            else:
                answer += str(node.value)
            node = node.next
        return answer

link = LinkedList()
print link.show()
link.insert_end(1)
link.insert_begin(0)
print(link.show())