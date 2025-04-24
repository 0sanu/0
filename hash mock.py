def hash_function(name, size):
    return sum(ord(c) for c in name) % size

# Insert using Linear Probing
def insert_linear(table, name, number):
    index = hash_function(name, len(table))
    while table[index] is not None:
        index = (index + 1) % len(table)
    table[index] = (name, number)

# Search using Linear Probing
def search_linear(table, name):
    index = hash_function(name, len(table))
    while table[index] is not None:
        if table[index][0] == name:
            return table[index][1]
        index = (index + 1) % len(table)
    return None

# Display the hash table
def display(table):
    for i, entry in enumerate(table):
        print(f"[{i}] -> {entry}")

# Menu to interact with the hash table
def menu():
    size = 10  # Table size
    table = [None] * size

    while True:
        print("\n1. Insert a client")
        print("2. Search for a number")
        print("3. Display hash table")
        print("4. Exit")

        choice = input("Enter your choice (1-4): ")

        if choice == "1":
            name = input("Enter client's name: ")
            number = input("Enter client's phone number: ")
            insert_linear(table, name, number)
            print("Client inserted.")

        elif choice == "2":
            name = input("Enter the name to search: ")
            number = search_linear(table, name)
            if number:
                print(f"Found number: {number}")
            else:
                print("Client not found.")

        elif choice == "3":
            display(table)

        elif choice == "4":
            break

        else:
            print("Invalid choice. Please try again.")

# Start the program
menu()
