#include "VendingMachine.h"

VendingMachine::VendingMachine() {
    Containers = vector<Container>();
    Containers.push_back(Container(Product("CoCaKola", 5)));
    Containers.push_back(Container(Product("7UP", 5)));
    Containers.push_back(Container(Product("Miranda", 5)));
    Containers.push_back(Container(Product("Pepsi", 5)));
    Containers.push_back(Container(Product("Sprit", 5)));

    Containers.push_back(Container(Product("Galaxy Bar", 8.5)));
    Containers.push_back(Container(Product("Kit Kat", 9.5)));
    Containers.push_back(Container(Product("Mandolyne", 2.5)));

    Containers.push_back(Container(Product("Chipsi", 2)));
    Containers.push_back(Container(Product("Kajo", 0.5)));

    safe = Safe();
}

void VendingMachine::printItems(bool quantity) {
    int i = 1;
    for (Container container : Containers){
        cout<<"[("<<i++<<") ";
        cout<<container.getProductName()<<" ";
        cout<<container.getProductPrice()<<"L.E.";
        if(quantity) cout<<"quantity: "<<container.size();
        cout<<"]"<<endl;
    }
    cout<<"[(0) Cancel!!]"<<endl;
}

bool VendingMachine::isAvailable() {
    for (Container container : Containers){
        if (container.size() > 0) return true;
    }
    return  false;
}
void VendingMachine::run(bool verbose) {
    float amount;
    int choice;
    while(1){

        if(not isAvailable()){
            break;
        }


        printItems(verbose);
        cout<<"Enter The Amount Of Money"<<endl;
        cin>>amount;
        if(amount <= 0 ) continue;
        cout<<"Enter Your Choice"<<endl;
        cin>>choice;
        if (choice == 0 || choice > 10){
            cout<<"Money Out!!"<<endl;
            continue;
        }
        while(Containers[choice-1].size() == 0){
            cout<<"Sorry the required item is not available"<<endl;
            cout<<"Press One(1) to choose another item or zero(0) to return the money"<<endl;
            cout<<"Enter Your Choice"<<endl;
            cin>>choice;
            if (choice != 1) break;
            else{
                printItems(verbose);
                cout<<"Enter Your Choice"<<endl;
                cin>>choice;
                if (choice == 0) break;
            }
        }
        if (choice == 0 || choice > 10){
            cout<<"Money Out!!"<<endl;
            continue;
        }
        if(Containers[choice-1].getProductPrice() > amount){
            cout<<"Need More Money"<<endl;
            cout<<"Money Out!!"<<endl;
            continue;
        }

        Containers[choice-1].pop(amount);
        cout<<safe.pay(amount, Containers[choice-1].getProductPrice())<<endl;

        cout<<"\n\n"<<endl;
    }
}