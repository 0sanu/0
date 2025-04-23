def hash_function(name, size):
    return sum(ord(c) for c in name) % size

# Insert using Linear Probing
def insert_linear(table, name, number):
    index = hash_function(name, len(table))
    original_index = index
    while table[index] is not None:
        index = (index + 1) % len(table)
        if index == original_index:
            print("Hash table is full! Cannot insert.")
            return
    table[index] = (name, number)

# Search using Linear Probing and count comparisons
def search_linear(table, name):
    index = hash_function(name, len(table))
    comparisons = 0
    original_index = index
    while table[index] is not None:
        comparisons += 1
        if table[index][0] == name:
            return table[index][1], comparisons
        index = (index + 1) % len(table)
        if index == original_index:
            break
    return None, comparisons

# Display the hash table
def display(table):
    print("\nLinear Probing Hash Table:")
    for i, entry in enumerate(table):
        print(f"[{i}] -> {entry}")

# Menu to interact with the hash table
def menu():
    size = 10  # Table size
    table = [None] * size
    total_comparisons = 0

    while True:
        print("\n--- TELEPHONE BOOK MENU ---")
        print("1. Insert a client")
        print("2. Search for a number")
        print("3. Display hash table")
        print("4. Show total comparisons")
        print("5. Exit")

        choice = input("Enter your choice (1-5): ")

        if choice == "1":
            name = input("Enter client's name: ")
            number = input("Enter client's phone number: ")
            insert_linear(table, name, number)
            print("Client inserted.")

        elif choice == "2":
            name = input("Enter the name to search: ")
            number, comparisons = search_linear(table, name)
            if number:
                print(f"Found number: {number} (Comparisons: {comparisons})")
            else:
                print(f"Client not found. (Comparisons: {comparisons})")
            total_comparisons += comparisons

        elif choice == "3":
            display(table)

        elif choice == "4":
            print(f"\nTotal comparisons during all searches: {total_comparisons}")

        elif choice == "5":
            print("Exiting the telephone book program. Goodbye!")
            break

        else:
            print("Invalid choice. Please try again.")

# Start the program
menu()
