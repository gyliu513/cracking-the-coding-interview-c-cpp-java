from node import node

def delete_duplicates(head):  
    # Hashtable for marking the ocurrence of data  
    dic = {}  
    dic[head.data] = True  

    # The node right before the one under processing  
    node_pre = head  

    while node_pre.next != None:  
        node_current = node_pre.next  
	if dic.has_key(node_current.data):  
            # Delete the node  
            node_pre.next = node_current.next  
            del node_current  
        else:  
            dic[node_current.data] = True  
            node_pre = node_current  

if __name__ == "__main__":  
    n1 = node(4)  
    n2 = node(1)  
    n3 = node(1)  
    n4 = node(1)  
    n5 = node(2)  
    n1.next = n2  
    n2.next = n3  
    n3.next = n4  
    n4.next = n5  

    n = n1  
    print "Before deleting duplicates"  
    while n != None:  
        print n.data  
	n = n.next  
    delete_duplicates(n1)  
    n = n1  
    print "After deleting duplicates"  
    while n != None:  
        print n.data  
        n = n.next  
