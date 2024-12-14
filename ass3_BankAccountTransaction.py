class Bank:
    def __init__(self, num, bal):
        self.balance = bal
        self.number = num

    def transact(self):
        while True:
            # Prompt for transaction in the format "char integer"
            transaction = input("Enter transaction (D/W followed by amount): ").strip().lower()
            if len(transaction.split()) != 2:
                print("Invalid input. Please follow the format: char integer (e.g., D 200)")
                continue
            
            method, amount = transaction.split()
            try:
                amount = int(amount)
            except ValueError:
                print("Invalid amount. Please enter a valid number.")
                continue

            if method == 'd':
                self.deposit(amount)
            elif method == 'w':
                self.withdraw(amount)
            else:
                print("Invalid transaction type. Use 'D' for deposit and 'W' for withdrawal.")
                continue

            # Ask if user wants to perform more transactions
            more = input("Do you want to perform another transaction? (yes/no): ").strip().lower()
            if more != 'yes':
                print(f"Thank you for banking with us! Your final balance is {self.balance}.")
                break

    def deposit(self, amt):
        self.balance += amt
        print(f"Amount deposited successfully. Available balance: {self.balance}")

    def withdraw(self, amt):
        if self.balance >= amt:
            self.balance -= amt
            print(f"Withdrawal successful. Available balance: {self.balance}")
        else:
            print("Insufficient funds!")

# Create a bank account with an initial balance of 1000
b1 = Bank(1, 1000)

# Start transactions
b1.transact()
