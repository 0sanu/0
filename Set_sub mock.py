'''To create ADT that implement the "set" concept.  
a. Add (newElement) -Place a value into the set  
b. Remove (element) Remove the value  
c. Contains (element) Return true if element is in collection  
d. Size () Return number of values in collection Iterator () Return an iterator used to loop over collection  
e. Intersection of two sets  
f. Union of two sets  
g. Difference between two sets  
h. Subset'''

class Set:

    def __init__(self):
        self.set1 = set()
        n = int(input("\nEnter the number of element: "))
        for i in range(n):
            val = int(input(f"Enter the value {i+1}: "))
            if val not in self.set1:
                self.set1.add(val)
            else:
                print("\nValue is already present !")
        print("\nSet contain elements: ",self.set1)

    def display(self):
        print("\nSet contain elements: ",self.set1)
    
    def insert(self):
        val = int(input(f"\nEnter the value to add: "))
        if val not in self.set1:
            self.set1.add(val)
            print("\nValue",val,"is added to the set !")
        else:
            print("\nValue is already present !")

    def delete(self):
        val = int(input(f"\nEnter the value to delete: "))
        if val in self.set1:
            self.set1.remove(val)
            print("\nValue",val,"is deleted from the set !")
        else:
            print("\nValue is not present !")
    
    def contain(self):
        val = int(input(f"\nEnter the value to search: "))
        if val in self.set1:
            print("\nValue is present !")
        else:
            print("\nValue is not present !")
    
    def size(self):
        print("\nSize of the set: ",len(self.set1))

    def intersection(self):
        print("\nCreate another set for intersection !")
        set2 = Set()
        result1 = set()
        for i in self.set1:
            if i in set2.set1:
                result1.add(i)
        print("\nIntersection of set1 and set2: ",result1)

    def union(self):
        print("\nCreate another set for intersection !")
        set2 = Set()
        result2 = set()
        for i in self.set1:
            if i not in result2:
                result2.add(i)
        for i in set2.set1:
            if i not in result2:
                result2.add(i)
        print("\nUnion of set1 and set2: ",result2)

    def difference(self):
        print("\nCreate another set for intersection !")
        set2 = Set()
        result3 = set()
        for i in self.set1:
            if i not in set2.set1:
                result3.add(i)
        print("\nDifference of set1 and set2: ",result3)

    def subset(self):
        print("\nCreate another set for intersection !")
        set2 = Set()
        flag = 1
        for i in set2.set1:
            if i not in self.set1:
                flag = 0
                break
        if flag == 1:
            print("\nset2 is the subset of set1 !")  
        else:
            print("\nset2 is not the subset of set1 !")  





import Set_sub
s = Set_sub.Set()

flag = 1
while flag == 1:
    print("\n*************************MENU**************************\n")
    print("1. Enter 1 to add an element in a set")
    print("2. Enter 2 to delete an element from the set")
    print("3. Enter 3 to check whether the set contains an element or not")
    print("4. Enter 4 to print the size of the set")
    print("5. Enter 5 to display the set")
    print("6. Enter 6 for the intersection of two sets")
    print("7. Enter 7 for the union of two sets")
    print("8. Enter 8 for the difference between two sets")
    print("9. Enter 9 to check for a subset")
    print("10. Exit")
    ch = int(input("Enter your choice: "))

    if ch == 1:
        s.insert()

    elif ch == 2:
        s.delete()

    elif ch == 3:
        s.contain()

    elif ch == 4:
        s.size()

    elif ch == 5:
        s.display()

    elif ch == 6:
        s.intersection()

    elif ch == 7:
        s.union()

    elif ch == 8:
        s.difference()

    elif ch == 9:
        s.subset()

    elif ch == 10:
        print("\nTHANK YOU!\n")
        flag = 0

    else:
        print("\nWRONG CHOICE!")
           