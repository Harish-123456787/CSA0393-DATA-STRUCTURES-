class Node:
    def __init__(self, key):
        self.key = key
        self.height = 1
        self.left = None
        self.right = None

def height(node):
    if node is None:
        return 0
    return node.height

def balance_factor(node):
    if node is None:
        return 0
    return height(node.left) - height(node.right)

def rotate_left(y):
    x = y.right
    T2 = x.left

    x.left = y
    y.right = T2

    y.height = 1 + max(height(y.left), height(y.right))
    x.height = 1 + max(height(x.left), height(x.right))

    return x

def rotate_right(x):
    y = x.left
    T2 = y.right

    y.right = x
    x.left = T2

    x.height = 1 + max(height(x.left), height(x.right))
    y.height = 1 + max(height(y.left), height(y.right))

    return y

def insert(root, key):
    if root is None:
        return Node(key)
    
    if key < root.key:
        root.left = insert(root.left, key)
    else:
        root.right = insert(root.right, key)
    
    root.height = 1 + max(height(root.left), height(root.right))
    
    balance = balance_factor(root)
    
    if balance > 1:
        if key < root.left.key:
            return rotate_right(root)
        else:
class Node:
    def __init__(self, key):
        self.key = key
        self.height = 1
        self.left = None
        self.right = None

def height(node):
    if node is None:
        return 0
    return node.height

def balance_factor(node):
    if node is None:
        return 0
    return height(node.left) - height(node.right)

def rotate_left(y):
    x = y.right
    T2 = x.left

    x.left = y
    y.right = T2

    y.height = 1 + max(height(y.left), height(y.right))
    x.height = 1 + max(height(x.left), height(x.right))

    return x

def rotate_right(x):
    y = x.left
    T2 = y.right

    y.right = x
    x.left = T2

    x.height = 1 + max(height(x.left), height(x.right))
    y.height = 1 + max(height(y.left), height(y.right))

    return y

def insert(root, key):
    if root is None:
        return Node(key)
    
    if key < root.key:
        root.left = insert(root.left, key)
    else:
        root.right = insert(root.right, key)
    
    root.height = 1 + max(height(root.left), height(root.right))
    
    balance = balance_factor(root)
    
    if balance > 1:
        if key < root.left.key:
            return rotate_right(root)
        else:
            root.left = rotate_left(root.left)
            return rotate_right(root)
    
    if balance < -1:
        if key > root.right.key:
            return rotate_left(root)
        else:
            root.right = rotate_right(root.right)
            return rotate_left(root)
    
    return root

def delete(root, key):
    if root is None:
        return root
    
    if key < root.key:
        root.left = delete(root.left, key)
    elif key > root.key:
        root.right = delete(root.right, key)
    else:
        if root.left is None:
            return root.right
        elif root.right is None:
            return root.left
        else:
            successor = find_min(root.right)
            root.key = successor.key
            root.right = delete(root.right, successor.key)
    
    root.height = 1 + max(height(root.left), height(root.right))
    
    balance = balance_factor(root)
    
    if balance > 1:
        if balance_factor(root.left) >= 0:
            return rotate_right(root)
        else:
            root.left = rotate_left(root.left)
            return rotate_right(root)
    
    if balance < -1:
        if balance_factor(root.right) <= 0:
            return rotate_left(root)
        else:
            root.right = rotate_right(root.right)
            return rotate_left(root)
    
    return root

def find_min(node):
    while node.left is not None:
        node = node.left
    return node

def search(root, key):
    if root is None or root.key == key:
        return root
    
    if key < root.key:
        return search(root.left, key)
    
    return search(root.right, key)

# Usage example
root = None
keys = [10, 20, 30, 40, 50, 25]
for key in keys:
    root = insert(root, key)

root = delete(root, 30)

key_to_search = 20
result = search(root, key_to_search)
if result:
    print(f"Key {key_to_search} found in the AVL tree.")
else:
    print(f"Key {key_to_search} not found in the AVL tree.")
￼Enter            root.left = rotate_left(root.left)
            return rotate_right(root)
    
    if balance < -1:
        if key > root.right.key:
            return rotate_left(root)
        else:
            root.right = rotate_right(root.right)
            return rotate_left(root)
    
    return root

def delete(root, key):
    if root is None:
        return root
    
    if key < root.key:
        root.left = delete(root.left, key)
    elif key > root.key:
        root.right = delete(root.right, key)
    else:
        if root.left is None:
            return root.right
        elif root.right is None:
            return root.left
        else:
      successor = find_min(root.right)
            root.key = successor.key
            root.right = delete(root.right, successor.key)
    
    root.height = 1 + max(height(root.left), height(root.right))
    
    balance = balance_factor(root)
    
    if balance > 1:
        if balance_factor(root.left) >= 0:
            return rotate_right(root)
        else:
            root.left = rotate_left(root.left)
            return rotate_right(root)
    
    if balance < -1:
        if balance_factor(root.right) <= 0:
            return rotate_left(root)
        else:
            root.right = rotate_right(root.right)
            return rotate_left(root)
    
    return root

def find_min(node):
    while node.left is not None:
