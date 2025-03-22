#include <iostream>
#include <string>
#define TAX_RATE 0.15

using namespace std;

enum Category {
    Electronics = 1,
    Grocery = 2,
    Clothing = 3,
    Stationery = 4,
    Miscellaneous = 5
};

Category productCategory;
const float taxRate = 0.15f ;
int initialInventory , productCategoryNum;
double pricePerUnit , tax , totalSales;
int numOfSoldItems ;
int currentInventory;
string inventoryStatus , productName ;

// these functions use global variables which can be accessed without being parameter

void helloppl();
void calculations (); 
void receipt();
void finally();




int main(){
    std::cout << "THIS IS A PROGRAM TO CALCUALTE YOUR TAX." <<endl;
    std::cout << "THIS IS COMPILED IN C PLUS PLUS." <<endl;
    helloppl();
    calculations( );
    receipt();
    finally();

    return 0;
}


void helloppl(){
    // accepts product name , category ,  initial inventory , price , sold items
    string sellingConfirmation;
    std::cout << "Product name : " ;
    getline(cin , productName);
    
    
    string tryAgain = "yes";
    while (tryAgain != "no"){
        std::cout <<"Enter the number(product category)[1-5] : ";
        std::cin >> productCategoryNum;
        if (productCategoryNum > 5 || productCategoryNum < 1){
            cout <<"You entered wrong value.Try again ";
            tryAgain = "yes";
        }else break;
         
     }
    cout <<"Product in Stock initially : "  ;
    cin >> initialInventory;
    std::cout <<"Price per unit : " ;
    std::cin >> pricePerUnit;
    
    std::cout <<"Have you sold some items:(yes / no [in lower case]) " ;
    std::cin >> sellingConfirmation ;
    if (sellingConfirmation == "yes"){  // there are sold products
        cout << "Amount of product sold : ";
        std::cin >> numOfSoldItems ;
}
    else numOfSoldItems = 0; // no sold items

}


void calculations(){
    totalSales = numOfSoldItems * pricePerUnit;
    tax = TAX_RATE * totalSales;
    double taxFromConst = taxRate * totalSales;
    currentInventory = initialInventory - numOfSoldItems;
    // ternary operator
    (currentInventory > 10) ? inventoryStatus = "Sufficient inventory" : inventoryStatus ="Low Inventory";
}

void receipt(){
    cout <<"RECEIPT FOR EACH ITEM SOLD" <<endl;
    for ( int i =  1; i <= numOfSoldItems ; i++){
        cout << " \t Item number : " << i  << endl;
        cout << " \t Price : " << pricePerUnit << endl;
        float taxFromEach = TAX_RATE * pricePerUnit;
        cout << " \t Tax from sales : " << taxFromEach  << endl;
        float profit =  pricePerUnit - taxFromEach;
        cout <<" \t Profit from this sale : " << profit << endl;
        auto copyOfInitialInventory = initialInventory;
        cout <<" \t Remaining Items : " << --copyOfInitialInventory <<endl;
        (copyOfInitialInventory > 10) ? inventoryStatus = "Sufficient inventory" : inventoryStatus ="Low Inventory";
        cout << inventoryStatus  <<endl;
    }
}

void finally (){
    cout <<'\n' <<endl;
    cout << "FINAL INFORMATION";
    cout << "Product Name : " << productName <<endl;
    productCategory = (Category) productCategoryNum;
    switch (productCategory){
        case 1:
            cout <<"Category 1: Electronics";
            break;
            
        case 2:
            cout <<"Category 2: Groceries" <<endl ;
            break; 
    
        case 3:
            cout <<"Category 3: Stationery" <<endl;
            break;
        case 4:
            cout <<"Category 4: Clothing line" <<endl;
            break;
    
        default:
            cout <<"Category 5:Other" <<endl;
        }

    cout <<"Product Name : " << productName <<endl;
    cout << "Tax from total sales : " << tax  <<endl;
    cout << "Profit from total sales : " << totalSales - tax <<endl;
    cout <<"Initial Inventory : " <<initialInventory <<endl;
    cout << "Price per unit : "  << pricePerUnit <<endl;
    cout << "Items sold : "  << numOfSoldItems <<endl;
    cout << "New Inventory : " << currentInventory  <<endl;
    cout << "Inventory Status : " << inventoryStatus;
}