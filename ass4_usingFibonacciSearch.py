# Initialize phonebook
phonebook = [("Clice", 9371531588), ("Atharva", 4561237899), ("Bob", 9876543215)]
phonebook.sort()  # Ensure the phonebook is sorted

def fibonacciSearch(arr, name):
    """
    Perform Fibonacci search to find a name in the phonebook.
    Returns the index of the name if found, otherwise -1.
    """
    n = len(arr)
    
    # Initialize the Fibonacci numbers
    fibM2 = 0  # (m-2)'th Fibonacci number
    fibM1 = 1  # (m-1)'th Fibonacci number
    fibM = fibM2 + fibM1  # m'th Fibonacci number

    # Find the smallest Fibonacci number >= n
    while fibM < n:
        fibM2 = fibM1
        fibM1 = fibM
        fibM = fibM2 + fibM1

    # Marks the eliminated range from the front
    offset = -1

    # While there are elements to be inspected
    while fibM > 1:
        # Check if fibM2 is a valid index
        i = min(offset + fibM2, n - 1)

        # If name is greater, move the range to the right
        if arr[i][0] < name:
            fibM = fibM1
            fibM1 = fibM2
            fibM2 = fibM - fibM1
            offset = i
        # If name is smaller, move the range to the left
        elif arr[i][0] > name:
            fibM = fibM2
            fibM1 = fibM1 - fibM2
            fibM2 = fibM - fibM1
        else:
            return i  # Name found at index i

    # Check the last element if it matches the name
    if fibM1 and offset + 1 < n and arr[offset + 1][0] == name:
        return offset + 1

    return -1  # Name not found


def insertContact():
    """
    Inserts a new contact into the phonebook if not already present.
    """
    name, number = input("Enter Name, number (10 digits): ").split()
    number = int(number)

    # Search for the name using Fibonacci search
    index = fibonacciSearch(phonebook, name)
    if index != -1:
        print("Person with the same name is already present.")
    else:
        phonebook.append((name, number))
        phonebook.sort()
        print("Contact added successfully!")


def displayPhonebook():
    """
    Displays the phonebook in a sorted order.
    """
    print("\nPhonebook:")
    for name, number in phonebook:
        print(f"{name}: {number}")


# Menu-driven interface
def menu():
    while True:
        print("\n--- Phonebook Menu ---")
        print("1. Insert Contact")
        print("2. Search Contact (Fibonacci Search)")
        print("3. Display Phonebook")
        print("4. Exit")

        choice = input("Enter your choice (1-4): ")

        if choice == "1":
            insertContact()
        elif choice == "2":
            name = input("Enter the name to search: ")
            index = fibonacciSearch(phonebook, name)
            if index != -1:
                print(f"Phone number: {phonebook[index][1]}")
            else:
                print("Name not found in the phonebook.")
        elif choice == "3":
            displayPhonebook()
        elif choice == "4":
            print("Exiting the phonebook. Goodbye!")
            break
        else:
            print("Invalid choice. Please try again.")


# Run the program
menu()
