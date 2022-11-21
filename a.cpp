#include <iostream>
#include<fstream>

using namespace std;

class shopping{
  
  private : 
  
  int product_code ;
  float price ;
  float discount ;
  string product_name ;
  
  public :
  
  void menu();
  
  void buyer();
  void admin();
  
  void list();
  void recipt();
  
    
  void add_product();
  void edit_product();
  void delete_product();
    
};




// list function 

void shopping :: list() {
    fstream data;
    data.open("store.txt" , ios :: in);
            
        cout <<"\n\t\t\t\t\t\t_____________________________________________________________________________________\n";
        cout <<"\n\t\t\t\t\t\t|                                                                                    |\n";
        cout <<"\n\t\t\t\t\t\t|product_code \t\t product_name \t\tPrice\t\tDiscount        |\n";
        cout <<"\n\t\t\t\t\t\t|____________________________________________________________________________________|\n";
    
    int pc , p , dis;
    string pn;
    
    data >> pc >> pn >> p >> dis ;
    
    while(!data.eof()) {
        cout <<"\n\t\t\t\t\t\t"<< pc <<"\t\t\t"<<pn<<"\t\t"<<p<<"\t\t" <<dis<<endl;
        data >> pc >> pn >> p >> dis ;
    }

    data.close();
    
}


// recipt function

void shopping :: recipt(){
    fstream data;
    
    int store_product_code[1001];
    int store_quantity[1001];
    string choice ;
    int p_c = 0 ;
    float amount = 0 , dis = 0 , total = 0 ;
    
    data.open("store.txt" , ios :: in);
    if(!data){
        cout <<"Empty Store !!";
    }else{
        
        data.close();
        
        // show list of product's to user
        list();
        
        
        cout <<"\n\t\t\t\t\t\t______________________________________________________________\n";
        cout <<"\n\t\t\t\t\t\t|                          Please place the order            |\n";
        cout <<"\n\t\t\t\t\t\t|____________________________________________________________|\n";
        
        do{
            m:
            cout << "\t\t\t Enter product code : " ;
            cin >> store_product_code[p_c] ;
            cout <<"\t\t\t Enter product quantity : ";
            cin >> store_quantity[p_c] ;
            
            // check if already taken same product_code
            
            for(int i = 0 ; i < p_c ; i++){
                if(store_product_code[p_c] == store_product_code[i]){
                   cout <<"\t\t\t duplicate product code found !!\n"; 
                    goto m ;
                }
            }
            p_c++;
            
            cout <<"\n\n\t\t\t Want to buy another product ? yes/no\n\n";
            cin >> choice ;
        }        
        while(choice != "no");
        
        cout <<"\n\t\t\t\t\t\t______________________________________________________________\n";
        cout <<"\n\t\t\t\t\t\t|                          RECIPT                            |\n";
        cout <<"\n\t\t\t\t\t\t|____________________________________________________________|\n";
        cout <<"\n____________________________________________________________________________________________________________________________________________________________\n";
        cout <<"\t\t\n Product No\t\tProduct Name\t\tProduct quantity\t\tprice\t\tAmount\t\tAfter Discount \n\n";

        int pc , p , d ;
        string pn;


        for(int i = 0 ; i < p_c ; i++){

            data.open("store.txt" , ios :: in);
            data >> product_code >> product_name >> price >> discount ;
            while(!data.eof()){
                if(store_product_code[i] == product_code){
                    amount = price * store_quantity[i];
                    dis = amount - (amount*discount/100);
                    total+=dis;
                    
                    cout <<"\n "<<product_code<<"\t\t\t"<<product_name <<"\t\t\t"<<store_quantity[i]<<"\t\t\t\t"<<price<<"\t\t"<<amount<<"\t\t\t"<<dis<<"\n";
                }
            data >> product_code >> product_name >> price >> discount ;
            }
        data.close();
        }
    }
    cout <<"\n____________________________________________________________________________________________________________________________________________________________\n";
    cout <<"\n\t\t Total Amount : " << total << "\n\n\n\n"; 
}


// menu function
void shopping :: menu(){
    m:
    int choice ; 
    string email , password ;

        cout <<"\n\t\t\t\t\t\t______________________________________________________________\n";
        cout <<"\n\t\t\t\t\t\t|                                                            |\n";
        cout <<"\n\t\t\t\t\t\t|                          Main Menu                         |\n";
        cout <<"\n\t\t\t\t\t\t|____________________________________________________________|\n";

        cout <<"\n\t\t\t\t\t\t_____________________________________________________________|\n";
        cout <<"\n\t\t\t\t\t\t|                                                            |\n";
        cout <<"\n\t\t\t\t\t\t|                           1) Admin                         |\n";
        cout <<"\n\t\t\t\t\t\t|                                                            |\n";
        cout <<"\n\t\t\t\t\t\t|                           2) Buyer                         |\n";
        cout <<"\n\t\t\t\t\t\t|                                                            |\n";
        cout <<"\n\t\t\t\t\t\t|                           3) Exit                          |\n";
        cout <<"\n\t\t\t\t\t\t|____________________________________________________________|\n";    
  
    cout <<"\n\n\t\t\t  Please enter your choice : ";
    cin >> choice ;
    
    switch(choice){
        case 1 : {

        cout <<"\n\t\t\t\t\t\t______________________________________________________________\n";
        cout <<"\n\t\t\t\t\t\t|                                                            |\n";
        cout <<"\n\t\t\t\t\t\t|                          Login                             |\n";
        cout <<"\n\t\t\t\t\t\t|____________________________________________________________|\n";

            cout <<"\n\t\t\t Enter Email : \t\t";
            cin >> email ;
            cout <<"\n\t\t\t Enter Password : \t\t";
            cin >> password ;    
            
            if(email == "admin@gmail.com" and password == "apple"){
                admin();
            }else{
                cout << "Invalid username or password !!\n";
            }
            
            break;
            
        }
        
        case 2:{
            buyer();
            break;
        }
        case 3:{
            exit(0);
        }
        default :{
            cout << "Please select from given options !!!\n";
            break;
        }
        
    }
    goto m;
     
} 

// admin function

void shopping :: admin() {
    
    // label
    m:
    
    int choice ;

        cout <<"\n\t\t\t\t\t\t______________________________________________________________\n";
        cout <<"\n\t\t\t\t\t\t|                                                            |\n";
        cout <<"\n\t\t\t\t\t\t|                          Admin Menu                        |\n";
        cout <<"\n\t\t\t\t\t\t|____________________________________________________________|\n";

         cout <<"\n\t\t\t\t\t\t______________________________________________________________\n";
        cout <<"\n\t\t\t\t\t\t|                                                            |\n";
        cout <<"\n\t\t\t\t\t\t|                         1) Add product                     |\n";
        cout <<"\n\t\t\t\t\t\t|                                                            |\n";
        cout <<"\n\t\t\t\t\t\t|                         2) Edit product                    |\n";
        cout <<"\n\t\t\t\t\t\t|                                                            |\n";
        cout <<"\n\t\t\t\t\t\t|                         3) Delete product                  |\n";
        cout <<"\n\t\t\t\t\t\t|                                                            |\n";
        cout <<"\n\t\t\t\t\t\t|                         4) Main Menu                       |\n";
        cout <<"\n\t\t\t\t\t\t|____________________________________________________________|\n";
    
      
    cout <<"\n\n\t\t\t  Please enter your choice : ";
    cin >> choice ;
    
    switch(choice){
        case 1:{
            add_product();
            break;
        }
        case 2:{
            edit_product();
            break;
        }
    
        case 3 :{
            delete_product();
            break;
        }
        
        case 4 :{
            menu();
            break;
        }
        
        default :{
            cout <<"\t\t\t Enter valid choice !!!\n";
            break;
        }
    }
    
    goto m;
    
}

// Buyer function

void shopping :: buyer(){
    
    m:
    int choice ;

    
        cout <<"\n\t\t\t\t\t\t______________________________________________________________\n";
        cout <<"\n\t\t\t\t\t\t|                                                            |\n";
        cout <<"\n\t\t\t\t\t\t|                          Customer Menu                     |\n";
        cout <<"\n\t\t\t\t\t\t|____________________________________________________________|\n";

         cout <<"\n\t\t\t\t\t\t______________________________________________________________\n";
        cout <<"\n\t\t\t\t\t\t|                                                            |\n";
        cout <<"\n\t\t\t\t\t\t|                          1) Buy product                    |\n";
        cout <<"\n\t\t\t\t\t\t|                                                            |\n";
        cout <<"\n\t\t\t\t\t\t|                          2) Main Menu                      |\n";
        cout <<"\n\t\t\t\t\t\t|____________________________________________________________|\n";
      
    // cout <<"\t\t\t\t_______Customer Menu________\n" ;
    // cout <<"\t\t\t\t____________________________\n" ;
    // cout <<"\t\t\t\t                             \n";
    // cout <<"\t\t\t\t  1) Buy product             \n";
    // cout <<"\t\t\t\t                             \n";
    // cout <<"\t\t\t\t  2) Main Menu               \n\n";
    
    cout <<"\n\n\t\t\t  Please enter your choice : ";
    cin >> choice ;   
    
    switch(choice) {
        case 1 :{
            recipt();
            break;
        }
        case 2 :{
            menu();
            break;
        }
        default : {
            cout <<"\t\t\t  Enter valid choice !!!\n\n"; 
        }
    }
    goto m;
}

// add function 

void shopping :: add_product() {
    m:
    fstream data;
    int p_c , token = 0;
    float p , d ;
    string p_n ;
    
    cout <<"\t\t\t_____________Add new Product___________";
    cout <<"\t\t\t______________________________________\n";

     cout <<"\n\t\t\t\t\t\t______________________________________________________________\n";
        cout <<"\n\t\t\t\t\t\t|                          Please place the order            |\n";
        cout <<"\n\t\t\t\t\t\t|____________________________________________________________|\n";
    
    cout <<"\n\n\t Enter Procuct code \n";
    cin >> product_code ;
    
    cout<<"\n\n\t Enter Name of Procuct\n";
    cin >> product_name ;
    
    cout <<"\n\n\t Price of Procuct \n";
    cin >> price ;
        
    cout <<"\n\n\t Discount of Procuct \n";
    cin >> discount ;
    
    // opening file in reading mode
    
    data.open("store.txt" , ios :: in);

    int flag = false;
    
    if(!data){
        flag = true;
        data.open("store.txt" , ios ::app| ios ::out);
        data <<"  " << product_code <<" " << product_name <<" " << price <<" " << discount <<endl;
        data.close();
    }else{
    data >> p_c >> p_n >> p >> d ;
        
        while(!data.eof()){
            
            if(p_c == product_code){
                token++;
            }
             data >> p_c >> p_n >> p >> d ;
        }
        
        data.close();
        
    }
    if(token > 0){
        cout <<"product_code already exists !! \n";
        goto m;
    }else if(!flag){
        // file open in writting mode
        data.open("store.txt" , ios ::app| ios ::out);
        data <<"  " << product_code <<" " << product_name <<" " << price <<" " << discount <<endl;
        data.close();        
    }
    cout <<"\t\t\t  Record Inserted successfully !!\n\n";
    
}

// edit function

void shopping :: edit_product() {
    fstream data_1 , data_2 ;
    int p_key , token = 0  , p_c, p , d;
    string p_n;
    cout <<"\n\t\t\t_________________________________________________Modefy Record______________________________________________________\n";
    cout <<"\n\t\t\t  Procuct Code :" ;
    cin >> p_key ;
    
    // open file in read mode
    data_1.open("store.txt" , ios :: in);
    
    if(!data_1){
        cout <<"\n\n\t File doesn't exists !! \n";
    }else{
        data_2.open("temp_store.txt" , ios :: app | ios :: out);
        data_1  >> product_code >> product_name >> price >> discount;
        // data_1 >>p_c >> p_n >> p >> d ;   
        while(!data_1.eof()){
            if(p_key == product_code){
                cout << "\n\t\t Procuct new code : \n";
                cin >> p_c;
                cout << "\n\t\t Name the product : \n";
                cin >> p_n;
                cout << "\n\t\t Name the price : \n";
                cin >> p;
                cout << "\n\t\t Name the discount : \n";
                cin >> d;     
                
                data_2 << " " << p_c <<" " << p_n <<"  "<< p << " " << d << "\n";
                cout <<"\t\t\t\t\tRecord edited successfully !!! \n";
                token++;
                // break;
            }else{
                data_2 << " " << product_code <<" " << product_name <<"  "<< price << " " << discount <<"\n" ;
            }
            // cout <<"e";
            data_1  >> product_code >> product_name >> price >> discount;
            // data_1 >>product_code >> product_name >> price >> discount ;   
        }
        data_1.close();
        data_2.close();
        
        remove("store.txt");
        rename("temp_store.txt" , "store.txt");
        
        if(token == 0){
            cout <<"\n\t\t\t  Record Not Found !!! \n";
        }
        
    }
    
    
}


// remove function 

void shopping :: delete_product() {
    
    fstream data_1 , data_2 ;
    int p_key , token = 0 , p_c , p_n , p , d;
    
    cout <<"\n\n\t\t\t Delete product\n\n";
    cout <<"\n\t\t product code: \n" ;
    cin >> p_key ;
    
    data_1.open("store.txt" , ios :: in);
    
    if(!data_1){
        cout <<"\n\t\t File doesn't exists !!\n";
    }else{
        data_2.open("temp_store.txt" , ios :: app | ios :: out);
        data_1  >> product_code >> product_name >> price >> discount;

        
        while(!data_1.eof()){
            
            if(product_code == p_key){
                cout <<"Record deleted successfully !!\n"; 
                token++;
            }else{
                data_2 << " " << product_code <<" " << product_name <<"  "<< price << " " << discount <<"\n" ;
            }
        data_1  >> product_code >> product_name >> price >> discount;
        }
        data_1.close();
        data_2.close();
        
        remove("store.txt");
        rename("temp_store.txt" , "store.txt");        
        
        if(token == 0){
            cout <<"\n\t\t\t Record doesn't Found !!!\n"; 
        }
    }
    
    
    
    
}


int main()
{
    shopping s;
    s.menu();

    return 0;
}













