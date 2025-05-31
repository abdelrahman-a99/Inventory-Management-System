#include <iostream>
#include <string>
// #include <vector> // this head is not used in the code
#include <stack>
#include <queue>
// #include <limits> // this head to handle validation that the user will input it

using namespace std;

// SparePart class
class SparePart
{
private:
    // private attributes
    // vector<SparePart> existingParts;

    string partName;
    string partNumber;
    double cost;

public:
    // Default constructor
    SparePart() {}

    // Parameterized constructor
    SparePart(string partName, string partNumber, double cost)
        : partName(partName), partNumber(partNumber), cost(cost)
    {
        // existingParts.push_back(*this);
    }

    // Setter methods
    void setPartName(string newName) { partName = newName; }
    void setPartNumber(string newNumber) { partNumber = newNumber; }
    void setCost(double newCost) { cost = newCost; }

    // Getter methods
    string getPartName() const { return partName; }
    string getPartNumber() const { return partNumber; }
    double getCost() const { return cost; }

    // putdata function to input spare part attributes from the user
    void putdata()
    {
        cout << "Enter part name: ";
        cin >> partName;
        cout << "Enter part number: ";
        cin >> partNumber;
        cout << "Enter cost: ";
        cin >> cost;
    }

    // getdata function to display spare part attributes that the user is entered it
    void getdata()
    {
        cout << "Part Name: " << partName << endl;
        cout << "Part Number: " << partNumber << endl;
        cout << "Cost: " << cost << endl;
    }

    // modifydata function to modify spare part attributes
    void modifydata()
    {
        int choice;
        do
        {
            cout << "Select data to modify:" << endl;
            cout << "1. Part Name" << endl;
            cout << "2. Cost" << endl;
            cout << "0. Stop modifying" << endl;
            cin >> choice;

            switch (choice)
            {
            case 1:
                cout << "Enter new part name: ";
                cin >> partName;
                break;
            case 2:
                cout << "Enter new cost: ";
                cin >> cost;
                break;
            case 0:
                cout << "Modifying stopped." << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
            }
        } while (choice != 0);
    }
};

// Supplier class
class Supplier
{
private:
    // private attributes
    string supplierName;
    string supplierCode;
    string address;
    string telephone;
    string email;

public:
    // Default constructor
    Supplier() {}

    // Parameterized constructor
    Supplier(string Name, string Code, string addr, string tel, string mail)
        : supplierName(Name), supplierCode(Code), address(addr), telephone(tel), email(mail) {}

    // Setter methods
    void setSupplierName(string newName) { supplierName = newName; }
    void setSupplierCode(string newCode) { supplierCode = newCode; }
    void setAddress(string newAddress) { address = newAddress; }
    void setTelephone(string newTelephone) { telephone = newTelephone; }
    void setEmail(string newEmail) { email = newEmail; }

    // Getter methods
    string getSupplierName() { return supplierName; }
    string getSupplierCode() { return supplierCode; }
    string getAddress() { return address; }
    string getTelephone() { return telephone; }
    string getEmail() { return email; }

    // putdata function to input supplier attributes from the user
    void putdata()
    {
        cout << "Enter supplier name: ";
        cin >> supplierName;
        cout << "Enter supplier code: ";
        cin >> supplierCode;
        cout << "Enter address: ";
        cin >> address;
        cout << "Enter telephone: ";
        cin >> telephone;
        cout << "Enter email: ";
        cin >> email;
    }

    // getdata function to display supplier attributes that the user is entered it
    void getdata()
    {
        cout << "Supplier Name: " << supplierName << endl;
        cout << "Supplier Code: " << supplierCode << endl;
        cout << "Address: " << address << endl;
        cout << "Telephone: " << telephone << endl;
        cout << "Email: " << email << endl;
    }

    // modifydata function to modify supplier attributes
    void modifydata()
    {
        int choice;
        do
        {
            cout << "Select data to modify:" << endl;
            cout << "1. Supplier Name" << endl;
            cout << "2. Address" << endl;
            cout << "3. Telephone" << endl;
            cout << "4. Email" << endl;
            cout << "0. Stop modifying" << endl;
            cin >> choice;

            switch (choice)
            {
            case 1:
                cout << "Enter new supplier name: ";
                cin >> supplierName;
                break;
            case 2:
                cout << "Enter new address: ";
                cin >> address;
                break;
            case 3:
                cout << "Enter new telephone: ";
                cin >> telephone;
                break;
            case 4:
                cout << "Enter new email: ";
                cin >> email;
                break;
            case 0:
                cout << "Modifying stopped." << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
            }
        } while (choice != 0);
    }
};

// Node class for the Spare part linked list
class NodeSP
{
public:
    // puplic attributes
    Supplier sdata;
    NodeSP *next;

    // Parameterized constructor
    NodeSP(Supplier s) : sdata(s), next(nullptr) {}
};

// Spare part linked list class
/*
Time complexity for operations:
-------------------------------
- Insertion: Best Case O(1), Worst Case O(n)
- Searching: Best Case O(1), Worst Case O(n) // i search from the BST
- Deletion:  Best Case O(1), Worst Case O(n) // i delete from the BST
*/
class LLsparepart
{
private:
    // private attribute
    NodeSP *head;

public:
    // Default constructor
    LLsparepart() : head(nullptr) {}

    // gethead function to return the head pointer
    NodeSP *gethead() { return head; }

    // this function add suppliers to the spare part
    void addtosparepart(Supplier s)
    {
        // Check if the spare part with the given part number already exists
        NodeSP *current = head;
        while (current != nullptr)
        {
            if (current->sdata.getSupplierCode() == s.getSupplierCode())
            {
                cout << "Supplier with code " << s.getSupplierCode() << " already exists. Please enter another one." << endl;
                return; // Exit the function without adding the duplicate spare part
            }
            current = current->next;
        }

        NodeSP *newNode = new NodeSP(s);
        // insert at head
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            // traverse untill the end to insert at the end
            NodeSP *current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void displayList() // i will print from the BST
    {
        NodeSP *current = head;
        while (current != nullptr)
        {
            current->sdata.getdata();
            cout << endl;
            current = current->next;
        }
    }
};

// Node class for the Supplier linked list
class NodeS
{
public:
    // puplic attributes
    SparePart spdata;
    NodeS *next;

    // parameterized constructor
    NodeS(SparePart s) : spdata(s), next(nullptr) {}
};

// Supplier linked list class
/*
Time complexity for operations:
-------------------------------
- Insertion: Best Case O(1), Worst Case O(n)
- Searching: Best Case O(1), Worst Case O(n) // i search from the BST
- Deletion:  Best Case O(1), Worst Case O(n) // i delete from the BST
*/
class LLsupplier
{
private:
    // private attribute
    NodeS *head;

public:
    // Default constructor
    LLsupplier() : head(nullptr) {}

    // gethead function to return the head pointer
    NodeS *gethead() { return head; }

    // this function add spare parts to the supplier
    void addtosupplier(SparePart sp)
    {
        // Check if the supplier with the given code already exists
        NodeS *current = head;
        while (current != nullptr)
        {
            if (current->spdata.getPartNumber() == sp.getPartNumber())
            {
                cout << "Spare part with part number " << sp.getPartNumber() << " already exists. Please enter another one." << endl;
                return; // Exit the function without adding the duplicate supplier
            }
            current = current->next;
        }

        NodeS *newNode = new NodeS(sp);
        // insert at head
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            // traverse untill the end and insert at the end
            NodeS *current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void displayList() // i will print from the BST
    {
        NodeS *current = head;
        while (current != nullptr)
        {
            current->spdata.getdata();
            cout << endl;
            current = current->next;
        }
    }
};

// Node class for the spare part binary search tree
class NodeSPbst
{
public:
    // puplic attributes
    SparePart spvalue;
    NodeSPbst *right;
    NodeSPbst *left;

    // Parameterized constructor
    NodeSPbst(SparePart sp) : spvalue(sp), right(nullptr), left(nullptr) {}
};

// spare part binary search tree
/*
Time complexity for operations:
-------------------------------
- Insertion: Best Case O(log n), Worst Case O(n) (if the tree is unbalanced) (if the tree become linear)
- Searching: Best Case O(log n), Worst Case O(n) (if the tree is unbalanced) (if the tree become linear)
- Deletion:  Best Case O(log n), Worst Case O(n) (if the tree is unbalanced) (if the tree become linear)
*/
class spBST
{
private:
    // private attribute
    NodeSPbst *root;

public:
    // Default constructor
    spBST() : root(nullptr) {}

    // setRroot function to set a new root pointer
    void setRoot(NodeSPbst *newRoot) { root = newRoot; }

    // getroot function to return the root pointer
    NodeSPbst *getRoot() { return root; }

    // this function insert the suppliers inside the binary search tree with supplierCode attribute
    NodeSPbst *insert(NodeSPbst *root, SparePart sp)
    {
        if (root == nullptr)
            return new NodeSPbst(sp);

        // if the partNumber that the user insert it less than the root number
        if (sp.getPartNumber() < root->spvalue.getPartNumber())
            root->left = insert(root->left, sp);

        // if the partNumber that the user insert it greater than the root number
        else if (sp.getPartNumber() > root->spvalue.getPartNumber())
            root->right = insert(root->right, sp);

        return root;
    }

    // this function print the suppliers from the lowest supplier to the highest supplier by supplierCode attribute
    void inorder(NodeSPbst *root)
    {
        if (root == nullptr)
            return;

        // traverse from the left
        inorder(root->left);

        // print the data of the node
        root->spvalue.getdata();
        cout << endl;

        // traverse from the right
        inorder(root->right);
    }

    // this function search for the supplier by the supplierCode inside the binary search tree
    bool search(NodeSPbst *root, string partNumber)
    {
        if (root == nullptr)
            return false;

        int comparisonResult = partNumber.compare(root->spvalue.getPartNumber());

        // if the partNumber equal root number
        if (comparisonResult == 0)
        {
            cout << "Spare part with number " + partNumber + " found." << endl;
            return true;
        }

        // if the partNumber less than root number
        if (comparisonResult < 0)
            return search(root->left, partNumber);

        // if the partNumber greater than root number
        else
            return search(root->right, partNumber);
    }

    // this function like the search but the difference .. if found the node -> it will modify
    bool modify(NodeSPbst *root, string partNumber)
    {
        if (root == nullptr)
            return false;

        int comparisonResult = partNumber.compare(root->spvalue.getPartNumber());

        if (comparisonResult == 0)
        {
            root->spvalue.modifydata();
            return true;
        }

        if (comparisonResult < 0)
            return search(root->left, partNumber);

        else
            return search(root->right, partNumber);
    }

    // Helper function to find the minimum value node in a BST
    NodeSPbst *minValueNode(NodeSPbst *node)
    {
        NodeSPbst *current = node;
        while (current && current->left != nullptr)
            current = current->left;

        return current;
    }

    // Recursive function to delete a spare part from the BST by part number
    NodeSPbst *deleteNode(NodeSPbst *root, string partNumber)
    {
        if (root == nullptr)
            return root;

        if (partNumber < root->spvalue.getPartNumber())
            root->left = deleteNode(root->left, partNumber);

        else if (partNumber > root->spvalue.getPartNumber())
            root->right = deleteNode(root->right, partNumber);

        else
        {
            if (root->left == nullptr)
            {
                NodeSPbst *temp = root->right;
                delete root;
                return temp;
            }

            else if (root->right == nullptr)
            {
                NodeSPbst *temp = root->left;
                delete root;
                return temp;
            }

            NodeSPbst *temp = minValueNode(root->right);
            root->spvalue = temp->spvalue;
            root->right = deleteNode(root->right, temp->spvalue.getPartNumber());
        }
        return root;
    }

    // Wrapper function to delete a spare part from the BST
    void deleteSparePart(string partNumber)
    {
        root = deleteNode(root, partNumber);
    }
};

// Node class for the Supplier binary search tree
class NodeSbst
{
public:
    // puplic attributes
    Supplier svalue;
    NodeSbst *right;
    NodeSbst *left;

    // Parameterized constructor
    NodeSbst(Supplier s) : svalue(s), right(nullptr), left(nullptr) {}
};

// Supplier binary search tree
/*
Time complexity for operations:
-------------------------------
- Insertion: Best Case O(log n), Worst Case O(n) (if the tree is unbalanced) (if the tree become linear)
- Searching: Best Case O(log n), Worst Case O(n) (if the tree is unbalanced) (if the tree become linear)
- Deletion:  Best Case O(log n), Worst Case O(n) (if the tree is unbalanced) (if the tree become linear)
*/
class sBST
{
private:
    // private attribute
    NodeSbst *root;

public:
    // Default constructor
    sBST() : root(nullptr) {}

    // setRroot function to set a new root pointer
    void setRoot(NodeSbst *newRoot) { root = newRoot; }

    // getroot function to return the root pointer
    NodeSbst *getRoot() { return root; }

    // this function insert the suppliers inside the binary search tree with supplierCode attribute
    NodeSbst *insert(NodeSbst *root, Supplier s)
    {
        if (root == nullptr)
        {
            return new NodeSbst(s);
        }

        if (s.getSupplierCode() < root->svalue.getSupplierCode())
        {
            root->left = insert(root->left, s);
        }

        else if (s.getSupplierCode() > root->svalue.getSupplierCode())
        {
            root->right = insert(root->right, s);
        }

        return root;
    }

    // this function print the suppliers from the lowest supplier to the highest supplier by supplierCode attribute
    void inorder(NodeSbst *root)
    {
        if (root == nullptr)
            return;

        inorder(root->left);

        root->svalue.getdata();
        cout << endl;

        inorder(root->right);
    }

    // this function search for the supplier by the supplierCode inside the binary search tree
    bool search(NodeSbst *root, string supplierCode)
    {
        if (root == nullptr)
        {
            return false;
        }

        int comparisonResult = supplierCode.compare(root->svalue.getSupplierCode());

        if (comparisonResult == 0)
        {
            cout << "Supplier with code " + supplierCode + " found." << endl;
            return true;
        }

        if (comparisonResult < 0)
        {
            return search(root->left, supplierCode);
        }

        else
        {
            return search(root->right, supplierCode);
        }
    }

    bool modify(NodeSbst *root, string supplierCode)
    {
        if (root == nullptr)
            return false;

        int comparisonResult = supplierCode.compare(root->svalue.getSupplierCode());

        if (comparisonResult == 0)
        {
            root->svalue.modifydata();
            return true;
        }

        if (comparisonResult < 0)
            return search(root->left, supplierCode);

        else
            return search(root->right, supplierCode);
    }

    // Helper function to find the minimum value node in a BST
    NodeSbst *minValueNode(NodeSbst *node)
    {
        NodeSbst *current = node;
        while (current && current->left != nullptr)
            current = current->left;

        return current;
    }

    // Recursive function to delete a supplier from the BST by supplier code
    NodeSbst *deleteNode(NodeSbst *root, string supplierCode)
    {
        if (root == nullptr)
            return root;

        if (supplierCode < root->svalue.getSupplierCode())
            root->left = deleteNode(root->left, supplierCode);

        else if (supplierCode > root->svalue.getSupplierCode())
            root->right = deleteNode(root->right, supplierCode);

        else
        {
            if (root->left == nullptr)
            {
                NodeSbst *temp = root->right;
                delete root;
                return temp;
            }

            else if (root->right == nullptr)
            {
                NodeSbst *temp = root->left;
                delete root;
                return temp;
            }

            NodeSbst *temp = minValueNode(root->right);
            root->svalue = temp->svalue;
            root->right = deleteNode(root->right, temp->svalue.getSupplierCode());
        }
        return root;
    }

    // Wrapper function to delete a supplier from the BST
    void deleteSupplier(string supplierCode)
    {
        root = deleteNode(root, supplierCode);
    }
};

// Interaction class to store user interactions
class Interaction
{
private:
    string message;

public:
    Interaction(string msg) : message(msg) {}

    // Getter method to retrieve the interaction message
    string getMessage() { return message; }

    void display()
    {
        cout << message << endl;
    }
};

// InteractionStack class for managing user interactions
/*
Time complexity for operations:
-------------------------------
- Pushing interactions: O(1)
- popping interactions: O(1)
- Displaying interactions: O(n)
*/
class InteractionStack
{
private:
    stack<Interaction> interactions;

public:
    // Push a new interaction onto the stack
    void pushInteraction(string message)
    {
        interactions.push(Interaction(message));
    }

    // Display all interactions in the stack
    void displayInteractions()
    {
        cout << "Interaction History:" << endl
             << "====================" << endl;

        // Create a temporary stack to store interactions
        stack<Interaction> tempStack = interactions;

        while (!tempStack.empty())
        {
            tempStack.top().display();
            tempStack.pop();
        }
    }
};

// InteractionQueue class for managing user interactions using queues
/*
Time complexity for operations:
-------------------------------
- Enqueueing spare part messages: O(1) for each operation
- Enqueueing supplier messages: O(1) for each operation

- processing spare part messages: O(n) for each operation
- processing supplier messages: O(n) for each operation
*/
class InteractionQueue
{
private:
    queue<string> sparePartQueue;
    queue<string> supplierQueue;

public:
    // Enqueue spare part processing message
    void enqueueSparePartProcessing(string message)
    {
        sparePartQueue.push(message);
    }

    // Enqueue supplier processing message
    void enqueueSupplierProcessing(string message)
    {
        supplierQueue.push(message);
    }

    // Process spare part messages in the queue
    void processSparePartQueue()
    {
        // Create a temporary queue to store interactions
        queue<string> tempQueue = sparePartQueue;

        cout << "Spare Part Queue:" << endl;
        while (!tempQueue.empty())
        {
            cout << tempQueue.front() << endl;
            tempQueue.pop();
        }
    }

    // Process supplier messages in the queue
    void processSupplierQueue()
    {
        // Create a temporary queue to store interactions
        queue<string> tempQueue = supplierQueue;

        cout << "Supplier Queue:" << endl;
        while (!tempQueue.empty())
        {
            cout << tempQueue.front() << endl;
            tempQueue.pop();
        }
    }
};

int main()
{
    // Create instances of linked lists and binary search trees
    LLsparepart sparePartList;
    LLsupplier supplierList;
    spBST sparePartBST;
    sBST supplierBST;

    // Create instances of Interaction stack and queue
    InteractionStack interactionStack;
    InteractionQueue interactionQueue;

    // Create instances of spare part and supplier
    SparePart sp;
    Supplier sup;

    int spCount;
    cout << "Enter the number of spare parts (up to 100): ";
    cin >> spCount;

    int supCount;
    cout << "Enter the number of suppliers (up to 20): ";
    cin >> supCount;

    // Input data for spare parts
    for (int i = 0; i < spCount; ++i)
    {
        cout << "\nEnter details for Spare Part " << i + 1 << ":" << endl;
        sp.putdata();
        supplierList.addtosupplier(sp);
        sparePartBST.setRoot(sparePartBST.insert(sparePartBST.getRoot(), sp));
        interactionStack.pushInteraction("Inserted spare part with number " + sp.getPartNumber() + ".");
        interactionQueue.enqueueSparePartProcessing("Spare Part with number " + sp.getPartNumber() + " data processing in progress.");
    }

    // Input data for suppliers
    for (int i = 0; i < supCount; ++i)
    {
        cout << "\nEnter details for Supplier " << i + 1 << ":" << endl;
        sup.putdata();
        sparePartList.addtosparepart(sup);
        supplierBST.setRoot(supplierBST.insert(supplierBST.getRoot(), sup));
        interactionStack.pushInteraction("Inserted supplier with code " + sup.getSupplierCode() + ".");
        interactionQueue.enqueueSupplierProcessing("Supplier with code " + sup.getSupplierCode() + " data processing in progress.");
    }

    // Print the data of the spare parts
    cout << "\nSpare Parts:" << endl;

    NodeS *supplierHead = supplierList.gethead();
    while (supplierHead != nullptr)
    {
        supplierHead->spdata.getdata();
        cout << endl;
        supplierHead = supplierHead->next;
    }

    // Print the data of the suppliers
    cout << "\nSuppliers:" << endl;

    NodeSP *sparepartHead = sparePartList.gethead();
    while (sparepartHead != nullptr)
    {
        sparepartHead->sdata.getdata();
        cout << endl;
        sparepartHead = sparepartHead->next;
    }

    // Main menu
    int mainChoice;
    do
    {
        cout << "\nMain Menu:" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Search" << endl;
        cout << "3. Delete" << endl;
        cout << "4. Show Data" << endl;
        cout << "5. Managing User Interactions" << endl;
        cout << "6. Modify Data" << endl;
        cout << "7. Time Complexity" << endl;
        cout << "0. Exit" << endl;
        cin >> mainChoice;

        switch (mainChoice)
        {
        case 1: // Insert
        {
            int insertChoice;
            cout << "\nSelect where to insert:" << endl;
            cout << "1. Spare Part" << endl;
            cout << "2. Supplier" << endl;
            cin >> insertChoice;

            switch (insertChoice)
            {
            case 1: // Insert to Spare Part
            {
                SparePart sp;
                cout << "\nEnter details for the new Spare Part:" << endl;
                sp.putdata();

                supplierList.addtosupplier(sp);
                sparePartBST.setRoot(sparePartBST.insert(sparePartBST.getRoot(), sp));

                interactionStack.pushInteraction("Inserted spare part with number " + sp.getPartNumber() + ".");
                interactionQueue.enqueueSparePartProcessing("Spare Part with number " + sp.getPartNumber() + " data processing in progress.");

                break;
            }
            case 2: // Insert to Supplier
            {
                Supplier sup;
                cout << "\nEnter details for the new Supplier:" << endl;
                sup.putdata();

                sparePartList.addtosparepart(sup);
                supplierBST.setRoot(supplierBST.insert(supplierBST.getRoot(), sup));

                interactionStack.pushInteraction("Inserted supplier with code " + sup.getSupplierCode() + ".");
                interactionQueue.enqueueSupplierProcessing("Supplier with code " + sup.getSupplierCode() + " data processing in progress.");

                break;
            }
            default:
                cout << "Invalid choice" << endl;
            }
            break;
        }
        case 2: // Search
        {
            int searchChoice;
            cout << "\nSelect where to search:" << endl;
            cout << "1. Spare Part" << endl;
            cout << "2. Supplier" << endl;
            cin >> searchChoice;

            switch (searchChoice)
            {
            case 1: // Search in Spare Part
            {
                string searchNumber;
                cout << "\nEnter spare part number to search: ";
                cin >> searchNumber;

                bool spfound = sparePartBST.search(sparePartBST.getRoot(), searchNumber);

                if (!spfound)
                {
                    cout << "Spare part with number " + searchNumber + " not found." << endl;
                }

                interactionStack.pushInteraction("Searched spare part with number " + searchNumber + ".");

                break;
            }
            case 2: // Search in Supplier
            {
                string searchCode;
                cout << "\nEnter supplier code to search: ";
                cin >> searchCode;

                bool sfound = supplierBST.search(supplierBST.getRoot(), searchCode);

                if (!sfound)
                {
                    cout << "Supplier with code " + searchCode + " not found." << endl;
                }

                interactionStack.pushInteraction("Searched supplier with code " + searchCode + ".");

                break;
            }
            default:
                cout << "Invalid choice" << endl;
            }
            break;
        }
        case 3: // Delete
        {
            int deleteChoice;
            cout << "\nSelect where to delete:" << endl;
            cout << "1. Spare Part" << endl;
            cout << "2. Supplier" << endl;
            cin >> deleteChoice;

            switch (deleteChoice)
            {
            case 1: // Delete in Spare Part
            {
                string deleteSparePartNumber;
                cout << "\nEnter spare part number to delete: ";
                cin >> deleteSparePartNumber;

                // Check if spare part exists before attempting to delete
                if (sparePartBST.search(sparePartBST.getRoot(), deleteSparePartNumber))
                {
                    sparePartBST.deleteSparePart(deleteSparePartNumber);
                    cout << "Spare part with number " + deleteSparePartNumber + " deleted." << endl;
                    interactionStack.pushInteraction("Deleted spare part with number " + deleteSparePartNumber + ".");
                }

                else
                {
                    cout << "Spare part with number " + deleteSparePartNumber + " not found. Cannot delete." << endl;
                }

                break;
            }
            case 2: // Delete in Supplier
            {
                string deleteSupplierCode;
                cout << "\nEnter supplier code to delete: ";
                cin >> deleteSupplierCode;

                // Check if supplier exists before attempting to delete
                if (supplierBST.search(supplierBST.getRoot(), deleteSupplierCode))
                {
                    supplierBST.deleteSupplier(deleteSupplierCode);
                    cout << "Supplier with code " + deleteSupplierCode + " deleted." << endl;
                    interactionStack.pushInteraction("Deleted supplier with code " + deleteSupplierCode + ".");
                }

                else
                {
                    cout << "Supplier with code " + deleteSupplierCode + " not found. Cannot delete." << endl;
                }

                break;
            }
            default:
                cout << "Invalid choice" << endl;
            }
            break;
        }
        case 4: // Show Data
            int showListChoice;
            cout << "\nSelect which Data to show:" << endl;
            cout << "1. Show Spare Part Data" << endl;
            cout << "2. Show Supplier Data" << endl;
            cout << "0. Back to Main Menu" << endl;
            cin >> showListChoice;

            switch (showListChoice)
            {
            case 1: // Show spare part Data
                cout << "\nSpare Part Data:" << endl;

                // supplierList.displayList();
                sparePartBST.inorder(sparePartBST.getRoot());
                break;
            case 2: // Show supplier Data
                cout << "\nSupplier Data:" << endl;

                // sparePartList.displayList();
                supplierBST.inorder(supplierBST.getRoot());
                break;
            case 0:
                // Back to the main menu
                break;
            default:
                cout << "Invalid choice" << endl;
            }
            break;
        case 5: // Managing User Interactions
        {
            int manageChoice;
            cout << "\nSelect managing operation:" << endl;
            cout << "1. Display Interaction History" << endl;
            cout << "2. Process Spare Part Queue" << endl;
            cout << "3. Process Supplier Queue" << endl;
            cin >> manageChoice;

            switch (manageChoice)
            {
            case 1: // Display Interaction History
                interactionStack.displayInteractions();
                break;
            case 2: // Process Spare Part Queue
                interactionQueue.processSparePartQueue();
                break;
            case 3: // Process Supplier Queue
                interactionQueue.processSupplierQueue();
                break;
            default:
                cout << "Invalid choice" << endl;
            }
            break;
        }
        case 6: // Modify Data
        {
            int modifyChoice;
            cout << "\nSelect what to modify:" << endl;
            cout << "1. Modify Spare Part Data" << endl;
            cout << "2. Modify Supplier Data" << endl;
            cin >> modifyChoice;

            string SpNumber;
            string SNumber;

            switch (modifyChoice)
            {
            case 1: // Modify spare part Data
                cout << "\nEnter spare part number to modify: ";
                cin >> SpNumber;

                if (sparePartBST.modify(sparePartBST.getRoot(), SpNumber)) // if the spare part data is founded
                {
                    cout << "Modification on spare part with number " + SpNumber + " successful." << endl;
                    interactionQueue.enqueueSparePartProcessing("Spare Part with number " + SpNumber + " modifying in progress.");
                    // interactionQueue.enqueueSparePartProcessing("Processing spare part modifying");
                }

                else
                    cout << "Spare part with number " + SpNumber + " not found." << endl;

                break;
            case 2: // Modify supplier Data
                cout << "\nEnter supplier code to modify: ";
                cin >> SNumber;

                if (supplierBST.modify(supplierBST.getRoot(), SNumber)) // if the supplier data is founded
                {
                    cout << "Modification on suppier with code " + SNumber + " successful." << endl;
                    interactionQueue.enqueueSupplierProcessing("Supplier with code " + SNumber + " modifying in progress.");
                    // interactionQueue.enqueueSupplierProcessing("Processing supplier modifying");
                }

                else
                    cout << "Supplier with code " + SNumber + " not found." << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
            }
            break;
        }
        case 7: // Time Complexity
        {
            int timeComplexityChoice;
            cout << "\nSelect Data Structure:" << endl;
            cout << "1. Linked Lists" << endl;
            cout << "2. Trees" << endl;
            cout << "3. Stack" << endl;
            cout << "4. Queue" << endl;
            cin >> timeComplexityChoice;

            switch (timeComplexityChoice)
            {
            case 1: // Linked Lists
            {
                int linkedListFunctionChoice;
                cout << "\nSelect Linked List Function:" << endl;
                cout << "1. Insert" << endl;
                cout << "2. Display" << endl;
                cin >> linkedListFunctionChoice;

                switch (linkedListFunctionChoice)
                {
                case 1: // Insert
                    cout << "Linked List Insertion - Best Case: O(1), Worst Case: O(n)" << endl;
                    break;
                case 2: // Display
                    cout << "Linked List Display - Best Case: O(n), Worst Case: O(n)" << endl;
                    break;
                default:
                    cout << "Invalid choice" << endl;
                }

                break;
            }
            case 2: // Trees
            {
                int treeFunctionChoice;
                cout << "\nSelect Tree Function:" << endl;
                cout << "1. Insert" << endl;
                cout << "2. Search" << endl;
                cout << "3. Modify" << endl;
                cout << "4. Delete" << endl;
                cout << "5. Inorder Traversal" << endl;
                cin >> treeFunctionChoice;

                switch (treeFunctionChoice)
                {
                case 1: // Insert
                    cout << "Tree Insertion - Best Case: O(log n), Worst Case: O(n)" << endl;
                    break;
                case 2: // Search
                    cout << "Tree Search - Best Case: O(log n), Worst Case: O(n)" << endl;
                    break;
                case 3: // Modify
                    cout << "Tree Modification - Best Case: O(log n), Worst Case: O(n)" << endl;
                    break;
                case 4: // Delete
                    cout << "Tree Deletion - Best Case: O(log n), Worst Case: O(n)" << endl;
                    break;
                case 5: // Inorder Traversal
                    cout << "Tree Inorder Traversal - Best Case: O(n), Worst Case: O(n)" << endl;
                    break;
                default:
                    cout << "Invalid choice" << endl;
                }

                break;
            }
            case 3: // Stack
            {
                int stackFunctionChoice;
                cout << "\nSelect Stack Function:" << endl;
                cout << "1. Pushing" << endl;
                cout << "2. Popping" << endl;
                cout << "3. Displaying" << endl;
                cin >> stackFunctionChoice;

                switch (stackFunctionChoice)
                {
                case 1: // Pushing
                    cout << "Stack Pushing - Best Case: O(1), Worst Case: O(1)" << endl;
                    break;
                case 2: // Popping
                    cout << "Stack Popping - Best Case: O(1), Worst Case: O(1)" << endl;
                    break;
                case 3: // Displaying
                    cout << "Stack Displaying - Best Case: O(n), Worst Case: O(n)" << endl;
                    break;
                default:
                    cout << "Invalid choice" << endl;
                }

                break;
            }
            case 4: // Queue
            {
                int queueFunctionChoice;
                cout << "\nSelect Queue Function:" << endl;
                cout << "1. Enqueueing Spare Part Messages" << endl;
                cout << "2. Enqueueing Supplier Messages" << endl;
                cout << "3. Processing Spare Part Messages" << endl;
                cout << "4. Processing Supplier Messages" << endl;
                cin >> queueFunctionChoice;

                switch (queueFunctionChoice)
                {
                case 1: // Enqueueing Spare Part Messages
                    cout << "Queue Enqueueing Spare Part Messages - Best Case: O(1), Worst Case: O(1)" << endl;
                    break;
                case 2: // Enqueueing Supplier Messages
                    cout << "Queue Enqueueing Supplier Messages - Best Case: O(1), Worst Case: O(1)" << endl;
                    break;
                case 3: // Processing Spare Part Messages
                    cout << "Queue Processing Spare Part Messages - Best Case: O(n), Worst Case: O(n)" << endl;
                    break;
                case 4: // Processing Supplier Messages
                    cout << "Queue Processing Supplier Messages - Best Case: O(n), Worst Case: O(n)" << endl;
                    break;
                default:
                    cout << "Invalid choice" << endl;
                }

                break;
            }
            default:
                cout << "Invalid choice" << endl;
            }

            break;
        }
        case 0: // Exit
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    } while (mainChoice != 0);

    return 0;
}