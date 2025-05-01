def hash_function(name, size):
    return sum(ord(c) for c in name) % size

def insert(table, name, number, method="linear"):
    size = len(table)
    index = hash_function(name, size)
    i = 1
    while table[index] is not None:
        if method == "linear":
            index = (index + 1) % size
        elif method == "quadratic":
            index = (index + i ** 2) % size
            i += 1
        if i >= size:
            print("Hash table is full.")
            return
    table[index] = (name, number)
    print("Added successfully.")

def search(table, name, method="linear"):
    size = len(table)
    index = hash_function(name, size)
    i = 1
    while table[index] is not None:
        if table[index][0] == name:
            return table[index][1]
        if method == "linear":
            index = (index + 1) % size
        elif method == "quadratic":
            index = (index + i ** 2) % size
            i += 1
        if i >= size:
            break
    return None

def display(table):
    for i, entry in enumerate(table):
        print(f"[{i}] -> {entry}")

def menu():
    size = 10
    table = [None] * size

    while True:
        print("\n1. Insert (Linear)")
        print("2. Search (Linear)")
        print("3. Insert (Quadratic)")
        print("4. Search (Quadratic)")
        print("5. Display")
        print("6. Exit")

        choice = input("Enter choice: ")

        if choice == "1":
            name = input("Enter name: ")
            number = input("Enter number: ")
            insert(table, name, number, "linear")
        elif choice == "2":
            name = input("Enter name to search: ")
            number = search(table, name, "linear")
            print(f"Found: {number}" if number else "Not found.")
        elif choice == "3":
            name = input("Enter name: ")
            number = input("Enter number: ")
            insert(table, name, number, "quadratic")
        elif choice == "4":
            name = input("Enter name to search: ")
            number = search(table, name, "quadratic")
            print(f"Found: {number}" if number else "Not found.")
        elif choice == "5":
            display(table)
        elif choice == "6":
            break
        else:
            print("Invalid choice.")

menu()
