#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Medicine{ //uses class instead of struct as class is more powerful with functions than a struct
    private:
        double Dosage,Price;
        string Name,Active_material,Catagory;
        bool Expired;
        int Availble_stock,Expiry_day,Expiry_Month,Expiry_Year;
    public:
        Medicine(string n=" ",string a=" ",string c=" ",int ED=0,int EM=0,int EY=0,double D=0.0,double p=0.0,int stock=0){ //Date of expiry entered as ints to help in comparsions
            Name=n;
            Active_material=a;
            Catagory=c;
            Expiry_day=ED;
            Expiry_Month=EM;
            Expiry_Year=EY;
            Dosage=D;
            Price=p;
            Availble_stock=stock;
            if(Expiry_Year<=2025){ //compares years (Uses discussion date 15 june 2025 as "Current Day")
                if(Expiry_Year==2025){
                    if(Expiry_Month<=6){ //if year is 2025 compares months
                        if(Expiry_Month==6){
                            if(Expiry_day<=15){ //if year,month are equal compares day
                                Expired=true;
                            }
                            else{
                                Expired=false; //if year,month equal but expiry greater than 15
                            }
                        }
                        if(Expiry_Month<6){
                            Expired=true; //if year is 2025 and month is less than 6
                        }
                    else{
                        Expired=false; // if year is 2025 but month is greater than 6
                    }
                    }
                }
                else{
                    Expired=true; //if year of expiry less than 2025
                }
            }
            else{
                Expired=false; // if year of expiry greater than 2025
            }
            cout<<"Added "<<Name<<"\nActive Material: "<<Active_material<<",Category: "<<Catagory<<", Dosage: "<<Dosage<<"\nExpiry Date: "<<Expiry_day<<"/"<<Expiry_Month<<"/"<<Expiry_Year<<", Expired (1 for true 0 for false): "<<Expired<<"\nAvailable Stock: "<<Availble_stock<<", Price: "<<Price<<endl; //Conformation Message
        }
        void setName(string N){
            Name=N;
        }
        void setActiveMaterial(string A){
            Active_material=A;
        }
        void setCategory(string C){
            Catagory=C;
        }
        void setExpiryDate(int ED,int EM,int EY){ //sets expiry date and checks if items are expired or not
            Expiry_day=ED;
            Expiry_Month=EM;
            Expiry_Year=EY;
            if(Expiry_Year<=2025){ //compares years (Uses discussion date 15 june 2025 as "Current Day")
                if(Expiry_Year==2025){
                    if(Expiry_Month<=6){ //if year is 2025 compares months
                        if(Expiry_Month==6){
                            if(Expiry_day<=15){ //if year,month are equal compares day
                                Expired=true;
                            }
                            else{
                                Expired=false; //if year,month equal but expiry greater than 15
                            }
                        }
                        if(Expiry_Month<6){
                            Expired=true; //if year is 2025 and month is less than 6
                        }
                    else{
                        Expired=false; // if year is 2025 but month is greater than 6
                    }
                    }
                }
                else{
                    Expired=true; //if year of expiry less than 2025
                }
            }
        }
        void setDosage(double D){
            Dosage=D;
        }
        void setPrice(double P){
            Price=P;
        }
        void setStock(int S){
            Availble_stock=S;
        }
        string getName(){
            return Name;
        }
        string getActiveMaterial(){
            return Active_material;
        }
        string getCategory(){
            return Catagory;
        }
        int getExpiryDay(){
            return Expiry_day;
        }
        int getExpiryMonth(){
            return Expiry_Month;
        }
        int getExpiryYear(){
            return Expiry_Year;
        }
        bool getExpired(){
            return Expired;
        }
        double getDosage(){
            return Dosage;
        }
        double getPrice(){
            return Price;
        }
        int getStock(){
            return Availble_stock;
        }
        friend ostream& operator <<(ostream& os,Medicine M); //to overload the cout <<
        void make_empty(){ //turns object into empty object, since the pop back and empty functions cant alwasy be used
            Name=" ";
            Active_material=" ";
            Catagory=" ";
            Expiry_day=0;
            Expiry_Month=0;
            Expiry_Year=0;
            Expired=false;
            Dosage=0.0;
            Price=0.0;
            Availble_stock=0.0;
        }
        bool operator == (Medicine M2){
            if (this->Name==M2.Name &&this->Dosage==M2.Dosage){
                return true;
            }
            else{
                return false;
            }
        }
        Medicine operator +(Medicine M2){
            if(this->Expired || M2.Expired){
                cout<<"One or both of the products are expired.\n"<<this<<endl<<M2;
                Medicine Empty;
                return Empty;
            }
            else{
                if(*this==M2){ //checks if products are the same
                    Medicine Sum_M (this->Name,this->Active_material,this->Catagory,this->Expiry_day,this->Expiry_Month,this->Expiry_Year,this->Dosage,this->Price,(this->Availble_stock+M2.Availble_stock));
                    this->make_empty();
                    M2.make_empty();
                    return Sum_M;
                }
                else{
                    cout<<"Names are not equal.\n"<<this<<endl<<M2;
                    Medicine Empty;
                    return Empty;
                }
            }
        }
};
ostream& operator <<(ostream& os,Medicine M){ //overloading the << operator to ease printing
    cout<<"Name: "<<M.Name<<"\nActive Material: "<<M.Active_material<<"\nCategory: "<<M.Catagory<<"\nDate of Expiry: "<<M.Expiry_day<<"/"<<M.Expiry_Month<<"/"<<M.Expiry_Year<<"\nDosage: "<<M.Dosage<<"\nPrice: "<<M.Price<<"\nAvailable Stock: "<<M.Availble_stock<<endl;
    return os;
}

class Paitent{
    private:
        string Name;
        float Age;
        int Phone_Number;
    public:
        vector <Medicine> Current_Medicine; //public to ensure lack of issues when modifing contents and when looping through vector
        Paitent(string N=" ",float a=0.0,int P=0){
            Name=N;
            Age=a;
            Phone_Number=P;
            cout<<"Added "<<Name<<", Age: "<<Age<<", Phone Number: "<<Phone_Number<<" to the paitent database.\n"; //Conformation Message
        } 
        void setName(string N){
            Name=N;
        }
        void setAge(float A){
            Age=A;
        }
        void setPhoneNumber(int P){
            Phone_Number=P;
        }
        string getName(){
            return Name;
        }
        float getAge(){
            return Age;
        }
        int getPhoneNumber(){
            return Phone_Number;
        }
        void make_empty(){
            Name=" ";
            Age=0.0;
            Phone_Number=0;
        }
        friend ostream& operator <<(ostream& os,Paitent P);
        bool operator == (Paitent P2){
            if(this->Name==P2.Name && this->Phone_Number==P2.Phone_Number){
                return true;
            }
            else{
                return false;
            }
        }
        //add medicine
};
ostream& operator <<(ostream& os,Paitent P){
    cout<<P.Name<<", Age: "<<P.Age<<", Phone Number: "<<P.Phone_Number<<endl<<"Medicine paitent is taking:\n";
    for(int i=0;i<P.Current_Medicine.size();i++){
        cout<<P.Current_Medicine[i]<<endl;
    }
    return os;
}
class Transaction{ 
    private:
        Paitent Buying_Paitent;
        double Cost;
        int Quantity;
        Medicine Product;
        string Payment_Method;
    public:
        Transaction(){
            Buying_Paitent;
            Product;
            Quantity=0;
            Payment_Method=" ";
            Cost=0.0;
        }
        Transaction(Paitent P,Medicine M,int Q=0,string Method=" "){
            Buying_Paitent=P;
            Product=M;
            Quantity=Q;
            Payment_Method=Method;
            Cost=Product.getPrice()*Quantity; //Calculates cost based of quantity times price
            cout<<"Created Transaction with "<<Buying_Paitent.getName()<<" Purchasing "<<Quantity<<" of "<<Product.getName()<<" for a total price of "<<Cost<<" by "<<Payment_Method<<endl; //conformation message
        }
        void setPaitent(Paitent P){
            Buying_Paitent=P;
        }
        void setProduct(Medicine M){
            Product=M;
        }
        void setQuantity(int Q){
            Quantity=Q;
        }
        void setPayment_Method(string Method){
            Payment_Method+Method;
        }
        Paitent getBuyingPaitent(){
            return Buying_Paitent;
        }
        Medicine getProduct(){
            return Product;
        }
        int getQuantity(){
            return Quantity;
        }
        string getPayemntMethod(){
            return Payment_Method;
        }
        void make_empty(){
            Buying_Paitent.make_empty();
            Product.make_empty();
            Quantity=0;
            Payment_Method=" ";
            Cost=0.0;
        }
        friend ostream& operator <<(ostream& os,Transaction T); 
        //operator + to add quantity and make new price if paitent and product are equal
        Transaction operator + (Transaction T2){
            if(T2.Buying_Paitent==this->Buying_Paitent && this->Product==T2.Product && this->Payment_Method==T2.getPayemntMethod()){ //only adds if the transactions are the same person same product and same payment method
                Transaction T(this->Buying_Paitent,this->Product,this->Quantity+T2.Quantity,this->Payment_Method);
                return T;
            }
            else{
                Transaction T;
                return T;
            }
        }
};
ostream& operator <<(ostream& os,Transaction T){
    cout<<T.Buying_Paitent<<" Purchasing "<<T.Quantity<<" of "<<T.Product<<" for a total price of "<<T.Cost<<" by "<<T.Payment_Method<<endl;
    return os;
}
// add functions to search 
int main(){
    int option,sub_option;
    vector <Medicine> Medicine_Catalouge(0); //uses vectors to store all the paitents and medicine as they are more flexible.
    vector <Paitent> Paitent_Database(0);//if have time could add them to files for easier readblity
    vector <Transaction> All_Transactions(0); //stores every transaction no mattter the paitent
    vector <Transaction> Current_Trasnasaction(0); //stores the current set of transactions
    cout<<"Hello, please select one of the options.\n";
    do
    {
        cout<<"1-Products.\n2-Paitents.\n3-Sales Transactions.\n4-Generate Receipt.\n5-Terminate.\n";
        cin>>option;
        if(option==1){
            cout<<"\n1.1 Add Product.\n1.2 Remove Product.\n1.3 Update Product.\n1.4 Display Product.\n1.5 Return to main menu.\n1.6 Display All.";
            cin>>sub_option;
            if(sub_option==1){
                string product_name,active_material,category;
                int Expiry_day,Expiry_Month,Expiry_Year,available_stock;
                double Dosage,price;
                bool dupelicate=false;
                cout<<"Enter the Product Name: ";
                cin.ignore();
                getline(cin,product_name);
                cout<<"Enter the active material: ";
                getline(cin,active_material);
                cout<<"Enter Category: ";
                getline(cin,category);
                cout<<"Enter Expiry Date (Day,Month,Year): ";
                cin>>Expiry_day>>Expiry_Month>>Expiry_Year;
                cout<<"Enter Dosage: ";
                cin>>Dosage;
                cout<<"Enter the price: ";
                cin>>price;
                cout<<"Enter Available Stock: ";
                cin>>available_stock;
                Medicine M(product_name,active_material,category,Expiry_day,Expiry_Month,Expiry_Year,Dosage,price,available_stock);
                for(int i=0;i<Medicine_Catalouge.size();i++){
                    if(M==Medicine_Catalouge[i]){
                        Medicine_Catalouge.push_back(M+Medicine_Catalouge[i]);
                        dupelicate=true;
                    }
                }
                if(!dupelicate){
                    Medicine_Catalouge.push_back(M);
                }
                else{
                    cout<<"Product already exists";
                }
            }
            else if(sub_option==2){
                int remove_index;
                string remove_name;
                bool found=false;
                cout<<"Enter the name of the medicine you want to remove: ";
                cin.ignore();
                getline(cin,remove_name);
                for(int i=0;i<Medicine_Catalouge.size();i++){
                    if(Medicine_Catalouge[i].getName()==remove_name){
                        remove_index=i;
                        found=true;
                    }
                }
                if(found){
                    Medicine_Catalouge[remove_index].make_empty(); // makes object empty instead of removing since this isnt nessicalry the last element so we cant use pop back
                }
                else{
                    cout<<"Medicine Not Found.\n";
                }
            }
            else if(sub_option==3){
                string target_name,target_edit;
                int index;
                bool found_2=false;
                cout<<"\nEnter the name of the product you want to edit: ";
                cin.ignore();
                getline(cin,target_name);
                cout<<"What do you want to edit: ";
                getline(cin,target_edit);
                for(int i=0;i<Medicine_Catalouge.size();i++){
                    if(Medicine_Catalouge[i].getName()==target_name){
                        index=i;
                        found_2=true;
                    }
                }
                if(found_2){
                    if(target_edit=="name"){
                        string new_product_name;
                        cout<<"Enter New Name: ";
                        getline(cin,new_product_name);
                        Medicine_Catalouge[index].setName(new_product_name);
                    }
                    else if(target_edit=="active material"){
                        string new_product_active_material;
                        cout<<"Enter New Active Material: ";
                        getline(cin,new_product_active_material);
                        Medicine_Catalouge[index].setActiveMaterial(new_product_active_material);
                    }
                    else if(target_edit=="category"){
                        string new_product_category;
                        cout<<"Enter New Category: ";
                        getline(cin,new_product_category);
                        Medicine_Catalouge[index].setCategory(new_product_category);
                    }
                    else if(target_edit=="date of expiry"){
                        int new_day,new_month,new_year;
                        cout<<"Enter New Date of Expiry: ";
                        cin>>new_day>>new_month>>new_year;
                        Medicine_Catalouge[index].setExpiryDate(new_day,new_month,new_year);
                    }
                    else if(target_edit=="dosage"){
                        double new_dosage;
                        cout<<"Enter New Dosage: ";
                        cin>>new_dosage;
                        Medicine_Catalouge[index].setDosage(new_dosage);
                    }
                    else if (target_edit=="price"){
                        double new_price;
                        cout<<"Enter New Price: ";
                        cin>>new_price;
                        Medicine_Catalouge[index].setPrice(new_price);
                    }
                    else if(target_edit=="stock"){
                        int new_stock;
                        cout<<"Enter New Available Stock: ";
                        cin>>new_stock;
                        Medicine_Catalouge[index].setStock(new_stock);
                    }
                    else{
                        cout<<"Invaild edit, Please enter a correct edit.\n";
                    }
                }
                else{
                    cout<<"Medicine Not Found.\n";
                }
            }
            else if(sub_option==4){
                //display medicine
                string display_name;
                int display_index;
                bool found_3=false;
                cout<<"Enter the name of the medicine you want to dispaly the information for: ";
                cin.ignore();
                getline(cin,display_name);
                for(int i=0;i<Medicine_Catalouge.size();i++){
                    if(Medicine_Catalouge[i].getName()==display_name){
                        display_index=i;
                        found_3=true;
                    }
                }
                if(found_3){
                    cout<<Medicine_Catalouge[display_index];
                }
                else{
                    cout<<"Medicine Not Found\n.";
                }
            }
            else if(sub_option==5){
                cout<<"\n1-Products.\n2-Paitents.\n3-Sales Transactions.\n4-Generate Receipt.\n5-Terminate.\n";
                cin>>option;
            }
            else if(sub_option==6){
                for(int i=0;i<Medicine_Catalouge.size();i++){
                    cout<<Medicine_Catalouge[i]<<endl;
                }
            }
            else{
                cout<<"Invalid input, please enter the option again (1.1-1.6): ";
                cin>>sub_option;
            }
        }
        else if (option==2){
            cout<<"\n2.1 Add Patient Profile.\n2.2 Remove Patient Profile.\n2.3 Update Patient Profile.\n2.4 View Patient Profile.\n2.5 Return to main menu.\n2.6 Display All Paitents";
            cin>>sub_option;
            if(sub_option==1){
                //add paitent
                string Paitent_Name;
                float Paitent_Age;
                int Paitent_PhoneNumber;
                bool paitent_duplicate=false;
                cout<<"Enter Paitent Name: ";
                cin.ignore();
                getline(cin,Paitent_Name);
                cout<<"Enter The age of "<<Paitent_Name<<":";
                cin>>Paitent_Age;
                cout<<"Enter the phone number of "<<Paitent_Name<<":";
                cin>>Paitent_PhoneNumber;
                Paitent P(Paitent_Name,Paitent_Age,Paitent_PhoneNumber);
                for(int i=0;i<Paitent_Database.size();i++){
                    if(P==Paitent_Database[i]){
                        paitent_duplicate=true;
                    }
                }
                if(paitent_duplicate){
                    cout<<"Paitent Already Exists.\n";
                }
                else{
                    Paitent_Database.push_back(P);
                }
            }
            else if(sub_option==2){
                //remove paitent
                string target_paitent;
                int target_phone_number,paitent_index;
                bool found_paitent=false;
                cout<<"Enter the name of the paitnet to remove: ";
                getline(cin,target_paitent);
                cout<<"Enter the phone number of "<<target_paitent<<": ";
                cin>>target_phone_number;
                for(int i=0;i<Paitent_Database.size();i++){
                    if(Paitent_Database[i].getName()==target_paitent && Paitent_Database[i].getPhoneNumber()==target_phone_number){
                        paitent_index=i;
                        found_paitent=true;
                    }
                }
                if(found_paitent){
                    Paitent_Database[paitent_index].make_empty();// makes object empty instead of removing since this isnt nessicalry the last element so we cant use pop back
                }
                else{
                    cout<<"Paitent not found (incorrect name or phone number). ";
                }
            }
            else if(sub_option==3){
                //update paitent
                string target_paitent_name,target_paitent_edit;
                int target_paitent_number,paitent_index;
                bool found_paitent_update=false;
                cout<<"Enter the name of the paitent to update: ";
                getline(cin,target_paitent_name);
                cout<<"Enter the phone number of "<<target_paitent_name<<": ";
                cin>>target_paitent_number;
                for(int i=0;i<Paitent_Database.size();i++){
                    if(Paitent_Database[i].getName()==target_paitent_name && Paitent_Database[i].getPhoneNumber()==target_paitent_number){
                        paitent_index=i;
                        found_paitent_update=true;
                    }
                }
                if(found_paitent_update){
                    cout<<"What do yu want to edit: ";
                    getline(cin,target_paitent_edit);
                    if(target_paitent_edit=="Name"){
                        string new_paitent_name;
                        cout<<"Enter the new name: ";
                        getline(cin,new_paitent_name);
                        Paitent_Database[paitent_index].setName(new_paitent_name);
                    }
                    else if(target_paitent_edit=="Age"){
                        double new_paitent_age;
                        cout<<"Enter the new age: ";
                        cin>>new_paitent_age;
                        Paitent_Database[paitent_index].setAge(new_paitent_age);
                    }
                    else if(target_paitent_edit=="Phone Number"){
                        int new_paitent_phone_number;
                        cout<<"Enter the new name: ";
                        cin>>new_paitent_phone_number;
                        Paitent_Database[paitent_index].setPhoneNumber(new_paitent_phone_number);
                    }
                    else if(target_paitent_edit=="Medicine"){
                        int choice;
                        cout<<"Do you want to add, remove or view all medicine of "<<target_paitent_name<<"(1 to add, 2 to remove, 3 to view all): ";
                        cin>>choice;
                        if(choice==1){
                            //add medicine to paitent
                            string new_medicine_name;
                            bool found_medicine_database=false;
                            int new_index;
                            cout<<"Enter the name of the medicine you want to add: ";
                            getline(cin,new_medicine_name);
                            for(int i=0;i<Medicine_Catalouge.size();i++){
                                if(new_medicine_name==Medicine_Catalouge[i].getName()){
                                    found_medicine_database=true;
                                    new_index=i;
                                }
                            }
                            if(found_medicine_database){
                                Paitent_Database[paitent_index].Current_Medicine.push_back(Medicine_Catalouge[new_index]);
                            }
                            else{
                                cout<<"Could not find medicine.\n";
                            }
                        }
                        if(choice==2){
                            string remove_medicine_name;
                            cout<<"Enter the name of the medicine you want to remove: ";
                            getline(cin,remove_medicine_name);
                            for(int i=0;i<Paitent_Database[paitent_index].Current_Medicine.size();i++){
                                if(remove_medicine_name==Paitent_Database[paitent_index].Current_Medicine[i].getName()){
                                    Paitent_Database[paitent_index].Current_Medicine[i].make_empty();
                                }
                            }
                        }
                        if(choice==3){
                            cout<<target_paitent_name<<" is taking: ";
                            for(int i=0;i<Paitent_Database[paitent_index].Current_Medicine.size();i++){
                                cout<<Paitent_Database[paitent_index].Current_Medicine[i]<<endl;
                            }
                        }
                        else{
                            cout<<"Invalid Choice.\n";
                        }
                    }
                    else{
                        cout<<"Invalid Edit.\n";
                    }
                }
                else{
                    cout<<"Paitent not found.\n";
                }
            }
            else if(sub_option==4){
                //view paitent
                string target_paitent_name_view;
                int target_paitent_number_view,paitent_index_view;
                bool found_paitent_view=false;
                cout<<"Enter the name of the paitent to update: ";
                getline(cin,target_paitent_name_view);
                cout<<"Enter the phone number of "<<target_paitent_name_view<<": ";
                cin>>target_paitent_number_view;
                for(int i=0;i<Paitent_Database.size();i++){
                    if(Paitent_Database[i].getName()==target_paitent_name_view && Paitent_Database[i].getPhoneNumber()==target_paitent_number_view){
                        paitent_index_view=i;
                        found_paitent_view=true;
                    }
                }
                if(found_paitent_view){
                    cout<<Paitent_Database[paitent_index_view]<<endl;
                }
                else{
                    cout<<"Paitent not found";
                }
            }
            else if(sub_option==5){
                cout<<"\n1-Products.\n2-Paitents.\n3-Sales Transactions.\n4-Generate Receipt.\n5-Terminate.\n";
                cin>>option;
            }
            else if(sub_option==6){
                for(int i=0;i<Paitent_Database.size();i++){
                    cout<<Paitent_Database[i]<<endl;
                }
            }
            else{
                cout<<"Invalid input, please enter the option again (2.1-2.6): ";
                cin>>sub_option;
            }
        }
        else if(option==3){
            cout<<"\n3.1 Create Transaction.\n3.2 Remove Transaction.\n3.3 Update Transaction.\n3.4 Display All Transactions\n3.5 Return to main menu.\n";
            cin>>sub_option;
            if(sub_option==1){
                //create transaction paitent product quantity method
                string paitent_name,medicine_name,transaction_method;
                int quantity,paitent_phone_number,transaction_paitent_index,transaction_medicine_index;
                bool found_paitent,found_product,stock_availble;
                double medicine_dosage;
                cout<<"Enter the name of the paitent: ";
                cin.ignore();
                getline(cin,paitent_name);
                cout<<"Enter the phone number of "<<paitent_name<<": ";
                cin>>paitent_phone_number;
                for(int i=0;i<Paitent_Database.size();i++){
                    if(Paitent_Database[i].getName()==paitent_name &&Paitent_Database[i].getPhoneNumber()==paitent_phone_number){
                        transaction_paitent_index=i;
                        found_paitent=true;
                    }
                }
                cout<<"Enter the name of the product: ";
                cin.ignore();
                getline(cin,medicine_name);
                cout<<"Enter the dosage of "<<medicine_name<<": ";
                cin>>medicine_dosage;
                for(int x=0;x<Medicine_Catalouge.size();x++){
                    if(Medicine_Catalouge[x].getName()==medicine_name && Medicine_Catalouge[x].getDosage()==medicine_dosage){
                        found_product=true;
                        transaction_medicine_index=x;
                    }
                }
                cout<<"Enter the Quantity Purchased: ";
                cin>>quantity;
                if((Medicine_Catalouge[transaction_medicine_index].getStock()-quantity)>0){
                    stock_availble=true;
                }
                else{
                    stock_availble=false;
                }
                cout<<"Enter the method of transaction (cash or credit etc.): ";
                cin.ignore();
                getline(cin,transaction_method);
                if(found_paitent && found_product && stock_availble){
                    int inital_stock=Medicine_Catalouge[transaction_medicine_index].getStock();
                    Medicine_Catalouge[transaction_medicine_index].setStock(quantity-inital_stock);
                    Transaction T(Paitent_Database[transaction_paitent_index],Medicine_Catalouge[transaction_medicine_index],quantity,transaction_method);
                    All_Transactions.push_back(T);
                    Current_Trasnasaction.push_back(T);
                }
                else{
                    cout<<"Could not create transaction (Paitent or medicine does not exist).\n";
                }
            }
            else if(sub_option==2){
                string remove_paitent_name,remove_medicine_name;
                int remove_paitent_phone_number,remove_paitent_index,remove_medicine_index,remove_quantity,remove_index,remove_index_2;
                double remove_medicine_dosage;
                bool remove_paitent,remove_product,remove_transaction;
                cout<<"Enter the name of the paitent linked to the transaction you wish to remove: ";
                cin.ignore();
                getline(cin,remove_paitent_name);
                cout<<"Enter the phone number of "<<remove_paitent_name<<": ";
                cin>>remove_paitent_phone_number;
                for(int i=0;i<Paitent_Database.size();i++){
                    if(Paitent_Database[i].getName()==remove_paitent_name &&Paitent_Database[i].getPhoneNumber()==remove_paitent_phone_number){
                        remove_paitent_index=i;
                        remove_paitent=true;
                    }
                }
                cout<<"Enter the name of the product: ";
                getline(cin,remove_medicine_name);
                cout<<"Enter the dosage of "<<remove_medicine_name<<": ";
                cin>>remove_medicine_dosage;
                for(int x=0;x<Medicine_Catalouge.size();x++){
                    if(Medicine_Catalouge[x].getName()==remove_medicine_name && Medicine_Catalouge[x].getDosage()==remove_medicine_dosage){
                        remove_product=true;
                        remove_medicine_index=x;
                    }
                }
                cout<<"Enter the Quantity Purchased: ";
                cin>>remove_quantity;
                for(int z=0;z<Current_Trasnasaction.size();z++){
                    if(Current_Trasnasaction[z].getProduct()==Medicine_Catalouge[remove_medicine_index] && Current_Trasnasaction[z].getBuyingPaitent()==Paitent_Database[remove_paitent_index] && Current_Trasnasaction[z].getQuantity()==remove_quantity){
                        remove_transaction=true;
                        remove_index=z;
                    }
                }
                for(int a=0;a<All_Transactions.size();a++){ //to remove from both current and all transactions
                    if(All_Transactions[a].getProduct()==Medicine_Catalouge[remove_medicine_index] && All_Transactions[a].getBuyingPaitent()==Paitent_Database[remove_paitent_index] && All_Transactions[a].getQuantity()==remove_quantity){
                        remove_index_2=a;
                    }
                }
                if(remove_transaction){
                    Current_Trasnasaction[remove_index].make_empty();
                    All_Transactions[remove_index_2].make_empty();
                }
            }
            else if(sub_option==3){ //could implent most of this code into function if have time
                string update_paitent_name,update_medicine_name;
                int update_paitent_phone_number,update_paitent_index,update_medicine_index,update_quantity,update_index,update_index_2;
                double update_medicine_dosage;
                bool update_paitent,update_product,update_transaction;cout<<"Enter the name of the paitent linked to the transaction you wish to remove: ";
                cin.ignore();
                getline(cin,update_paitent_name);
                cout<<"Enter the phone number of "<<update_paitent_name<<": ";
                cin>>update_paitent_phone_number;
                for(int i=0;i<Paitent_Database.size();i++){
                    if(Paitent_Database[i].getName()==update_paitent_name &&Paitent_Database[i].getPhoneNumber()==update_paitent_phone_number){
                        update_paitent_index=i;
                        update_paitent=true;
                    }
                }
                cout<<"Enter the name of the product: ";
                getline(cin,update_medicine_name);
                cout<<"Enter the dosage of "<<update_medicine_name<<": ";
                cin>>update_medicine_dosage;
                for(int x=0;x<Medicine_Catalouge.size();x++){
                    if(Medicine_Catalouge[x].getName()==update_medicine_name && Medicine_Catalouge[x].getDosage()==update_medicine_dosage){
                        update_product=true;
                        update_medicine_index=x;
                    }
                }
                cout<<"Enter the Quantity Purchased: ";
                cin>>update_quantity;
                for(int z=0;z<Current_Trasnasaction.size();z++){
                    if(Current_Trasnasaction[z].getProduct()==Medicine_Catalouge[update_medicine_index] && Current_Trasnasaction[z].getBuyingPaitent()==Paitent_Database[update_paitent_index] && Current_Trasnasaction[z].getQuantity()==update_quantity){
                        update_transaction=true;
                        update_index=z;
                    }
                }
                for(int a=0;a<All_Transactions.size();a++){ //to remove from both current and all transactions
                    if(All_Transactions[a].getProduct()==Medicine_Catalouge[update_medicine_index] && All_Transactions[a].getBuyingPaitent()==Paitent_Database[update_paitent_index] && All_Transactions[a].getQuantity()==update_quantity){
                        update_index_2=a;
                    }
                }
                if(update_transaction){
                    int new_quantity;
                    cout<<"Enter the new Quantity: ";
                    cin>>new_quantity;
                    Current_Trasnasaction[update_index].setQuantity(new_quantity);
                    All_Transactions[update_index_2].setQuantity(new_quantity);
                }
            }
            else if(sub_option==4){
                bool all;
                cout<<"Do you want to dispaly all transactions (full history) or all the current transactions (Reciept) (1 for history, 0 for reciept): ";
                cin>>all;
                if(all){
                    for(int i=0;i<All_Transactions.size();i++){
                        cout<<All_Transactions[i]<<endl;
                    }
                }
                else{
                    for(int i=0;i<Current_Trasnasaction.size();i++){
                        cout<<Current_Trasnasaction[i]<<endl;
                    }
                }
            }
            else if(sub_option==5){
                cout<<"\n1-Products.\n2-Paitents.\n3-Sales Transactions.\n4-Generate Receipt.\n5-Terminate.\n";
                cin>>option;
            }
            else{
                cout<<"Invalid input, please enter the option again (3.1-3.5): ";
                cin>>sub_option;
            }
        }
        else if(option==4){
            for(int i=0;i<Current_Trasnasaction.size();i++){
                cout<<Current_Trasnasaction[i]<<endl;
            }
            Current_Trasnasaction.clear();
        }
        else if(option==5){
            break;
        }
        else{
            cout<<"Invalid input, please enter the option again (1-5): "; //uses else if and else to conserve memmory and cpu by not having to cehck for every option.
            cin>>option;
        }
    } while (option!=5); //do while to ensure the first iteration happens.
    cout<<"End of program.";
}