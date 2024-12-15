# Initial phonebook
phonebook = [("Clice", 9371531588), ("Atharva", 4561237899), ("Bob", 9876543215)]
phonebook.sort()


def binarySearch(key):
    start = 0
    end = len(phonebook) - 1

    while start <= end:
        mid = (start + end) // 2
        if phonebook[mid][0] == key:
            return phonebook[mid][1]
        elif phonebook[mid][0] < key:
            start = mid + 1
        else:
            end = mid - 1
    return -1


def binary_search_recursive(phonebook, name, low, high):
    if low > high:
        return -1  # Not found
    mid = (low + high) // 2
    if phonebook[mid][0] == name:  # Compare with the name in the tuple
        return phonebook[mid][1]
    elif phonebook[mid][0] < name:
        return binary_search_recursive(phonebook, name, mid + 1, high)
    else:
        return binary_search_recursive(phonebook, name, low, mid - 1)


def insertContact():
    name, number = input("Enter Name, number (10 digits): ").split()
    number = int(number)

    # Check if contact exists using binary search
    res = binarySearch(name)
    if res != -1:
        print("Person with the same name is already present.")
    else:
        phonebook.append((name, number))
        phonebook.sort()
        print("Contact added successfully!")


def displayPhonebook():
    print("\nPhonebook:")
    for name, number in phonebook:
        print(f"{name}: {number}")


# Menu-driven interface
def menu():
    while True:
        print("\n--- Phonebook Menu ---")
        print("1. Insert Contact")
        print("2. Search Contact (Iterative)")
        print("3. Search Contact (Recursive)")
        print("4. Display Phonebook")
        print("5. Exit")

        choice = input("Enter your choice (1-5): ")

        if choice == "1":
            insertContact()
        elif choice == "2":
            name = input("Enter the name to search: ")
            result = binarySearch(name)
            if result != -1:
                print(f"Phone number: {result}")
            else:
                print("Name not found in the phonebook.")
        elif choice == "3":
            name = input("Enter the name to search: ")
            result = binary_search_recursive(phonebook, name, 0, len(phonebook) - 1)
            if result != -1:
                print(f"Phone number: {result}")
            else:
                print("Name not found in the phonebook.")
        elif choice == "4":
            displayPhonebook()
        elif choice == "5":
            print("Exiting the phonebook. Goodbye!")
            break
        else:
            print("Invalid choice. Please try again.")


# Run the program
menu()
