class Node:
    parent = None
    children=[]
    label=-1
    value=""

    def __init__(self):
        self.parent = None
        self.children = []
        self.label=-1
        self.value=""

    @staticmethod
    def MakeNode(val):
        node = Node()
        node.value=val
        return node

    def AddChildren(self, list):
        for item in list:
            node = Node.MakeNode(item)
            self.AddChild(node)
            node.parent = self

    def AddChild(self, node):
        self.children.append(node)

    def GetChild(self, index):
        return self.children[index]

def LabelPostOrder(node, label):
    for child in node.children:
        label = LabelPostOrder(child, label)+1
    node.label = label
    return label

def printTree(node):
    print('Value:{0}, Label:{1}'.format(node.value, node.label))
    for child in node.children:
        printTree(child)

tree1 = Node.MakeNode("A")
tree1.AddChildren(["B", "E"])
tree1.GetChild(0).AddChildren(["C","D"])
LabelPostOrder(tree1, 0)

tree2 = Node.MakeNode("A")
tree2.AddChildren(["B", "E"])
LabelPostOrder(tree2, tree1.label)

printTree(tree1)
printTree(tree2)
