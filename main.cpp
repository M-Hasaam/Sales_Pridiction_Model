// NAME :           MUHAMMAD HASAAM
// ID :             24I-3107
// SECTION :        SE-24 / C
// ASSIGNMENT :     02

#include <iostream>
#include <random>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

// All used Structs
struct GeoCoorainates;
struct Employees;
struct Products;
struct StoreAnalytics;
struct SalesForecast;
struct Store;
struct Report;
struct SalesData;
struct Centriod;
struct SubCluster;
struct Cluster;

// Small Helping functions
void string_to_char_ptr(char *&ptr, const string &st);
bool is_All_Digit(string st);
string take_random_name();
string take_random_Store_name();

struct GeoCoorainates
{
    double gLat = 0;
    double gLong = 0;

    // Constructor
    GeoCoorainates(double lat = 0, double lon = 0) : gLat(lat), gLong(lon) {}
    // Setter
    void setData(double lat, double lon)
    {
        gLat = lat;
        gLong = lon;
    }
    // Display
    void display() const
    {
        cout << " | Latitude: " << left << setw(7) << gLat << " | Longitude: " << setw(7) << gLong << " |" << endl;
    }
};

struct Employees
{

    int eID = 0;
    char *eName = nullptr;
    double salary = 0;

    static int all_Manager_ID_count;
    static int all_Staff_ID_count;

    // Constructor
    Employees()
    {
        string_to_char_ptr(eName, "EM_Name");
    }
    Employees(int id, string name, double salary)
    {
        eID = id;
        this->salary = salary;
        string_to_char_ptr(eName, name);
    }

    // Deep Copy copy constructor
    Employees(const Employees &other)
    {
        eID = other.eID;
        salary = other.salary;
        string_to_char_ptr(eName, string(other.eName));
    }

    // Deep Copy Assignment operater
    Employees &operator=(const Employees &other)
    {
        if (this == &other)
            return *this;

        eID = other.eID;
        salary = other.salary;
        string_to_char_ptr(eName, string(other.eName));

        return *this;
    }

    // Setter
    void setData(int id, string name, double salary)
    {
        eID = id;
        this->salary = salary;
        string_to_char_ptr(eName, name);
    }

    // Display
    void display() const { cout << " | ID: " << left << setw(10) << eID << " | Name: " << setw(15) << eName << " | Salary: " << setw(10) << salary << " |" << endl; }

    // Destructor
    ~Employees() { delete[] eName; }
};
int Employees::all_Manager_ID_count = 200000;
int Employees::all_Staff_ID_count = 100000;

struct Products
{
    char *SKU = nullptr;
    char *pName = nullptr;
    double unitPrice = 0;

    static int All_Availible_Product_Count; // static Counter

    // Constructor
    Products()
    {
        string_to_char_ptr(SKU, "SKU_ID");
        string_to_char_ptr(pName, "PR_Name");
    }
    Products(string sku, string name, double price)
    {
        unitPrice = price;

        string_to_char_ptr(SKU, sku);

        string_to_char_ptr(pName, name);
    }

    // Deep Copy copy constructor
    Products(const Products &other)
    {
        unitPrice = other.unitPrice;

        string_to_char_ptr(SKU, other.SKU);

        string_to_char_ptr(pName, other.pName);
    }

    // Deep Copy Assignment operater
    Products &operator=(const Products &other)
    {
        if (this == &other)
            return *this;

        unitPrice = other.unitPrice;

        string_to_char_ptr(SKU, other.SKU);

        string_to_char_ptr(pName, other.pName);

        return *this;
    }

    // Setter
    void setData(string sku, string name, double price)
    {
        unitPrice = price;

        string_to_char_ptr(SKU, sku);

        string_to_char_ptr(pName, name);
    }

    // Display
    void display(int type = 0) const
    {
        // type == 0 ( ID , Name , Price )
        // type == 1 ( ID , Name , Price + Bar Graph )
        cout << "    - | SKU: " << left << setw(10) << SKU << " | Name: " << setw(35) << pName << " | Price: " << setw(10) << unitPrice << " |";
        if (type == 1)
        {
            for (int j = 0; j < unitPrice / 20000; j++)
                cout << "=";
        }
        cout << endl;
    }

    // Destructor
    ~Products()
    {
        delete[] SKU;
        delete[] pName;
    }
};
int Products::All_Availible_Product_Count = 0;

struct StoreAnalytics
{
    double totalsales = 0;
    double totaloperationalcost = 0;
    double profit = 0;

    double GrowthRates = 0;
    double OverallScore = 0;

    // Display
    void display() const
    {
        cout << " | Overall Score : " << OverallScore << " | Total Sales : " << totalsales << " | Profit : " << profit << " | Growth Rate : " << GrowthRates << " |\n";
    }
};

struct SalesForecast
{
    char *month = nullptr;
    double predictedSales = 0;
    double confidencelevel = 0;
    bool warningflag = 0;

    // Constructor
    SalesForecast()
    {
        string_to_char_ptr(month, "month");
    }

    // Deep Copy copy constructor
    SalesForecast(const SalesForecast &other)
    {

        predictedSales = other.predictedSales;
        confidencelevel = other.confidencelevel;
        warningflag = other.warningflag;

        string_to_char_ptr(month, other.month);
    }

    // Deep Copy Assignment operater
    SalesForecast &operator=(const SalesForecast &other)
    {

        if (this == &other)
            return *this;

        predictedSales = other.predictedSales;
        confidencelevel = other.confidencelevel;
        warningflag = other.warningflag;

        string_to_char_ptr(month, other.month);

        return *this;
    }

    // Display
    void display() const
    {
        cout << " | Expected Sales : " << predictedSales << " | Confidence Level: " << confidencelevel << " | Warning Flag: " << (warningflag ? "YES" : "NO") << " |\n";
    }

    // Destructor
    ~SalesForecast()
    {
        delete[] month;
    }
};

struct Store
{
    static int all_Stores_ID_count;

    char *sName = nullptr;
    int sID = 0;
    double sMonthlyCost = 0;
    int customerCountMonthly[24];
    double MonthlyRevenue[24];

    GeoCoorainates Location;

    Employees Manager;

    int no_of_Staff;
    Employees *Staff = nullptr;
    StoreAnalytics sA;
    SalesForecast sF;

    // Constructor
    Store()
    {
        string_to_char_ptr(sName, "St_Name");
        for (int i = 0; i < 24; i++)
        {
            customerCountMonthly[i] = 0;
            MonthlyRevenue[i] = 0;
        }
    }
    Store(int id, string name, double cost) : sID(id), sMonthlyCost(cost)
    {
        string_to_char_ptr(sName, name);

        for (int i = 0; i < 24; i++)
        {
            customerCountMonthly[i] = 0;
            MonthlyRevenue[i] = 0;
        }
    }

    // Deep Copy
    Store(const Store &other)
    {
        sID = other.sID;
        sMonthlyCost = other.sMonthlyCost;

        Location = other.Location;

        Manager = other.Manager;

        sA = other.sA;
        sF = other.sF;

        for (int i = 0; i < 24; i++)
        {
            customerCountMonthly[i] = other.customerCountMonthly[i];
            MonthlyRevenue[i] = other.MonthlyRevenue[i];
        }

        if (Staff)
            delete[] Staff;

        no_of_Staff = other.no_of_Staff;
        Staff = new Employees[no_of_Staff];
        for (int i = 0; i < no_of_Staff; i++)
        {
            Staff[i] = other.Staff[i];
        }

        string_to_char_ptr(sName, other.sName);
    }
    Store &operator=(const Store &other)
    {
        if (this == &other)
            return *this;

        sID = other.sID;
        sMonthlyCost = other.sMonthlyCost;

        Location = other.Location;

        Manager = other.Manager;

        sA = other.sA;
        sF = other.sF;

        for (int i = 0; i < 24; i++)
        {
            customerCountMonthly[i] = other.customerCountMonthly[i];
            MonthlyRevenue[i] = other.MonthlyRevenue[i];
        }

        if (Staff)
            delete[] Staff;

        no_of_Staff = other.no_of_Staff;
        Staff = new Employees[no_of_Staff];
        for (int i = 0; i < no_of_Staff; i++)
        {
            Staff[i] = other.Staff[i];
        }

        string_to_char_ptr(sName, other.sName);

        return *this;
    }

    // Setter
    void setData(int id, string name, double cost)
    {
        sID = id;
        sMonthlyCost = cost;
        string_to_char_ptr(sName, name);
    }

    // Generating Data
    void random_setData()
    {
        // Store ID
        {
            sID = ++all_Stores_ID_count;
        }
        // Store Name
        {
            string name = take_random_Store_name();
            string_to_char_ptr(sName, name);
        }
        // Manager
        {
            int id = ++Employees::all_Manager_ID_count;

            Manager.setData(id, take_random_name(), (rand() % 390 + 10) * 1000);
        }
        // Staff
        {
            int staff_count = rand() % 10 + 1;
            no_of_Staff = staff_count;

            Staff = new Employees[no_of_Staff];

            for (int i = 0; i < no_of_Staff; ++i)
            {
                int id = ++Employees::all_Staff_ID_count;

                double salary = (rand() % 190 + 10) * 1000;
                Staff[i].setData(id, take_random_name(), salary);
            }
        }
        // Location
        Location.setData(((double(rand() % 18000)) / 100) - 90, ((double(rand() % 36000)) / 100) - 180);
        // Monthly Cost
        calculating_sMonthlyCost();
    }

    // Store's Monthly Cost
    void calculating_sMonthlyCost()
    {
        sMonthlyCost = 0;

        sMonthlyCost += Manager.salary;

        for (int i = 0; i < no_of_Staff; i++)
        {
            sMonthlyCost += Staff[i].salary;
        }

        sMonthlyCost += 1000000;
    }

    // Display
    void display(int type = 0) const
    {
        cout << "   ==> " << left << setw(20) << "Store:-" << " | ID: " << left << setw(10) << sID << " | Name: " << setw(15) << sName << " | Cost: " << setw(12) << sMonthlyCost << " |" << endl;

        // type == 0 ( only ID,Name,MonthlyCost )
        // type == 1 ( ( type == 0 )  + Sales Anylatics + Sales Forecast + Manager + Location )
        // type == 2 ( ( type == 1 )  + Staff )
        // type == 3 ( ( type == 1 )  + Monthly Customer Count  )
        // type == 4 ( ( type == 1 )  + Staff + Monthly Customer Count  )

        if (1 <= type)
        {
            cout << "   --> " << setw(20) << "Sales Anylatics:- ";
            sA.display();
            cout << "   --> " << setw(20) << "Sales Forecast:- ";
            sF.display();
            cout << "   --> " << setw(20) << "Manager:- ";
            Manager.display();
            cout << "   --> " << setw(20) << "Location:- ";
            Location.display();
        }

        if (type == 2 || type == 4)
        {
            cout << "   --> Staffs:-\n";
            for (int i = 0; i < no_of_Staff; i++)
            {
                cout << "       - Staff No " << setw(3) << i + 1 << ":- ";
                Staff[i].display();
            }
        }

        if (type == 3 || type == 4)
        {
            cout << "   --> Customer Monthly Counts :-\n";
            for (int i = 0; i < 24; i++)
            {

                int month = i % 12 + 1;
                int year = i / 12 + 2025;

                cout << "       - [" << (month < 10 ? "0" : "") << month << "-" << year << "] : "
                     << setw(4) << customerCountMonthly[i] << "  |";

                for (int j = 0; j < customerCountMonthly[i]; j++)
                    cout << "=";
                cout << endl;
            }
        }
    }

    // Destructor
    ~Store()
    {
        delete[] sName;
        delete[] Staff;
    }
};
int Store::all_Stores_ID_count = 300000;

struct Report
{
    Store *topStores = nullptr;
    Store *bottomStores = nullptr;

    // Constructor
    Report() {}

    // Deep Copy
    Report(const Report &other)
    {
        if (topStores)
            delete[] topStores;
        if (bottomStores)
            delete[] bottomStores;

        topStores = new Store[10];
        bottomStores = new Store[5];

        for (int i = 0; i < 10; i++)
        {
            topStores[i] = other.topStores[i];
        }
        for (int i = 0; i < 5; i++)
        {
            bottomStores[i] = other.bottomStores[i];
        }
    }
    Report &operator=(const Report &other)
    {
        if (this == &other)
            return *this;

        if (topStores)
            delete[] topStores;
        if (bottomStores)
            delete[] bottomStores;

        topStores = new Store[10];
        bottomStores = new Store[5];

        for (int i = 0; i < 10; i++)
        {
            topStores[i] = other.topStores[i];
        }
        for (int i = 0; i < 5; i++)
        {
            bottomStores[i] = other.bottomStores[i];
        }

        return *this;
    }

    // Display
    void display(int type = -1)
    {
        cout << " ==> Top 10 stores";

        // type == 0 ( Overall Score )
        // type == 1 ( Profit )
        // type == 2 ( Growth Rate )
        // type == 3 ( Revenue )

        if (type == 0)
            cout << " with respect to Overall Scores :-\n";
        else if (type == 1)
            cout << " with respect to Profit :-\n";
        else if (type == 2)
            cout << " with respect to Growth Rates :- \n";
        else if (type == 3)
            cout << " with respect to Revenue :- \n";
        else
            cout << " :- \n";

        double max = 0, min = 0;
        double value = 0;

        if (0 == type)
        {
            max = topStores[0].sA.OverallScore;
            min = bottomStores[0].sA.OverallScore;
        }
        else if (1 == type)
        {
            max = topStores[0].sA.profit;
            min = bottomStores[0].sA.profit;
        }
        else if (2 == type)
        {
            max = topStores[0].sA.GrowthRates;
            min = bottomStores[0].sA.GrowthRates;
        }
        else if (3 == type)
        {
            max = topStores[0].sA.totalsales;
            min = bottomStores[0].sA.totalsales;
        }

        int col = 40;
        double unit_col = max / col;

        for (int i = 0; i < 10; i++)
        {
            double value = 0;
            cout << "     - | ID : " << topStores[i].sID << " |";
            if (type == 0)
            {
                cout << " Overall Score : " << left << setw(12) << topStores[i].sA.OverallScore << " |";
                value = topStores[i].sA.OverallScore;
            }
            else if (type == 1)
            {
                cout << " Profit : " << setw(12) << topStores[i].sA.profit << " |";
                value = topStores[i].sA.profit;
            }
            else if (type == 2)
            {
                cout << " Growth Rates : " << setw(12) << topStores[i].sA.GrowthRates << " |";
                value = topStores[i].sA.GrowthRates;
            }
            else if (type == 3)
            {
                cout << " Revenue : " << setw(12) << topStores[i].sA.totalsales << " |";
                value = topStores[i].sA.totalsales;
            }

            // Bar Graph
            for (int j = 0; j < col + 2; j++)
            {

                if (value >= 0 && value >= j * unit_col)
                {
                    cout << "=";
                }
                else if (value < 0 && fabs(value) >= (col + 2 - j) * unit_col)
                {
                    cout << "=";
                }
                else
                {
                    cout << " ";
                }
            }

            cout << "|\n";
        }

        cout << " ==> Bottom 5 stores";

        if (type == 0)
            cout << " with respect to Overall Scores :-\n";
        else if (type == 1)
            cout << " with respect to Profit :-\n";
        else if (type == 2)
            cout << " with respect to Growth Rates :- \n";
        else if (type == 3)
            cout << " with respect to Revenue :- \n";
        else
            cout << " :- \n";

        for (int i = 4; i >= 0; i--)
        {
            cout << "     - | ID : " << bottomStores[i].sID << " |";
            if (type == 0)
            {
                cout << " Overall Score : " << left << setw(12) << bottomStores[i].sA.OverallScore << " |";
                value = bottomStores[i].sA.OverallScore;
            }
            else if (type == 1)
            {
                cout << " Profit : " << setw(12) << bottomStores[i].sA.profit << " |";
                value = bottomStores[i].sA.profit;
            }
            else if (type == 2)
            {
                cout << " Growth Rates : " << setw(12) << bottomStores[i].sA.GrowthRates << " |";
                value = bottomStores[i].sA.GrowthRates;
            }
            else if (type == 3)
            {
                cout << " Revenue : " << setw(12) << bottomStores[i].sA.totalsales << " |";
                value = bottomStores[i].sA.totalsales;
            }

            // Bar Graph
            for (int j = 0; j < col + 2; j++)
            {

                if (value >= 0 && value >= j * unit_col)
                {
                    cout << "=";
                }
                else if (value < 0 && fabs(value) >= (col + 2 - j) * unit_col)
                {
                    cout << "=";
                }
                else
                {
                    cout << " ";
                }
            }

            cout << "|\n";
        }
    }

    // Destructor
    ~Report()
    {
        delete[] topStores;
        delete[] bottomStores;
    }
};

struct SalesData
{
    Store store;
    Products *products = nullptr;
    int productCount = -1;
    string date;
    string time;
    double totalSaleAmount = -1;

    static bool Sale_File_Changed;

    // Constructor
    SalesData() {}
    SalesData(Store s, string d, string t, double total)
    {
        store = s;

        date = d;
        time = t;
        totalSaleAmount = total;

        products = new Products[1];
    }

    // Deep Copy
    SalesData(const SalesData &other)
    {
        store = other.store;
        date = other.date;
        time = other.time;
        totalSaleAmount = other.totalSaleAmount;

        if (products)
            delete[] products;

        productCount = other.productCount;
        products = new Products[productCount];

        for (int i = 0; i < productCount; i++)
        {
            products[i] = other.products[i];
        }
    }
    SalesData &operator=(const SalesData &other)
    {
        if (this == &other)
            return *this;

        store = other.store;
        date = other.date;
        time = other.time;
        totalSaleAmount = other.totalSaleAmount;

        if (products)
            delete[] products;

        productCount = other.productCount;
        products = new Products[productCount];

        for (int i = 0; i < productCount; i++)
        {
            products[i] = other.products[i];
        }

        return *this;
    }

    // Setter
    void setData(Store s, int count, string d, string t, double total)
    {
        store = s;
        productCount = count;
        date = d;
        time = t;
        totalSaleAmount = total;
        products = new Products[productCount];
    }

    // Generating Data
    void random_setData(Store *&Store_List, const int Store_Count, Products *&All_Availible_Products)
    {
        // Store
        {
            store = Store_List[rand() % Store_Count];
        }
        // Date
        {
            int day = rand() % 30 + 1;
            int month = rand() % 12 + 1;
            string d = (day / 10 == 0 ? "0" : "") + to_string(day) + "-" + (month / 10 == 0 ? "0" : "") + to_string(month) + "-20" + to_string(rand() % 2 + 25);
            date = d;
        }
        // Time
        {
            int min = rand() % 12 * 5;

            int hour = rand() % 12 + 1;
            string t = (hour < 10 ? "0" : "") + to_string(hour) + ":" + (min / 10 == 0 ? "0" : "") + to_string(min) + " " + ((rand() % 2 == 1) ? "AM" : "PM");
            time = t;
        }
        // Products
        {
            this->productCount = rand() % 4 + 1;

            if (products)
                delete[] products;

            products = new Products[productCount];

            for (int i = 0; i < productCount; i++)
            {
                int R = rand() % Products::All_Availible_Product_Count;

                products[i] = All_Availible_Products[R];
            }
        }
        // Total Sale Amount
        calculateTotalAmount();
    }

    // Destructor
    ~SalesData()
    {
        delete[] products;
    }

    // Total Sale Amount
    void calculateTotalAmount()
    {
        totalSaleAmount = 0;
        for (int i = 0; i < productCount; ++i)
        {
            totalSaleAmount += products[i].unitPrice;
        }
    }

    // Display
    void display(int type = 0) const
    {
        // type == 0 ( + Store ID,Name,MonthlyCost )
        // type == 1 ( + ( type == 0 ) + Sales Anylatics + Sales Forecast + Manager + Location )
        // type == 2 ( + ( type == 1 ) + Staff )
        // type == 3 ( + ( type == 1 ) + Monthly Customer Count  )
        // type == 4 ( + ( type == 1 ) + Staff + Monthly Customer Count  )

        cout << "===> | Sale Date: " << date << " | Time: " << time << " |" << endl;
        cout << "===> | Total Sale Amount: " << totalSaleAmount << " |" << endl;
        cout << "===> Store Details:" << endl;
        store.display(type);
        cout << "===> Products Sold:" << endl;
        for (int i = 0; i < productCount; ++i)
        {
            products[i].display();
        }
    }
};
bool SalesData::Sale_File_Changed = false;

struct Centriod
{
    double x = 0;
    double y = 0;
    // Setter
    void set(double x, double y)
    {
        this->x = x;
        this->y = y;
    }
    // Display
    void display()
    {
        cout << "(" << x << "," << y << ")\n";
    }
};

struct SubCluster
{
    char *ID = nullptr;
    char *Name = nullptr;
    Store *storesList = nullptr;
    int storeCount = 0;
    Centriod subCenter;

    // Constructor
    SubCluster() {}
    SubCluster(const SubCluster &other)
    {
        subCenter = other.subCenter;

        string_to_char_ptr(ID, other.ID);
        string_to_char_ptr(Name, other.Name);

        if (storesList)
            delete[] storesList;

        storeCount = other.storeCount;
        storesList = new Store[storeCount];

        for (int i = 0; i < storeCount; i++)
            storesList[i] = other.storesList[i];
    }

    // Deep Copy
    SubCluster &operator=(const SubCluster &other)
    {
        if (this == &other)
            return *this;

        subCenter = other.subCenter;

        string_to_char_ptr(ID, other.ID);
        string_to_char_ptr(Name, other.Name);

        if (storesList)
            delete[] storesList;

        storeCount = other.storeCount;
        storesList = new Store[storeCount];

        for (int i = 0; i < storeCount; i++)
            storesList[i] = other.storesList[i];

        return *this;
    }

    // Adding Store in StoreList
    void add_store(Store &St) { storesList[storeCount++] = St; }

    // Setter
    void set_ID_Name(string id, string name)
    {
        string_to_char_ptr(ID, id);
        string_to_char_ptr(Name, name);
    }

    // Adjusting Centriod Center
    void AdjustCenteriod()
    {
        if (storeCount != 0)
        {
            double X = 0, Y = 0;
            for (int i = 0; i < storeCount; i++)
            {
                X += storesList[i].sA.totalsales;
                Y += storesList[i].sA.profit;
            }

            X /= storeCount;
            Y /= storeCount;

            subCenter.set(X, Y);
        }
        // else
        // {
        //     subCenter.x;
        //     subCenter.y;
        // }
    }

    // Display
    void display()
    {
        cout << "       --> SubCluster:-\n";
        cout << "           -> ID : " << ID << " | Name : " << Name << " |\n";
        cout << "           -> Center (" << subCenter.x << "," << subCenter.y << ") \n";
        cout << "           -> Stores :-\n";
        if (storeCount != 0)
        {
            for (int i = 0; i < storeCount; i++)
            {
                cout << "               - | ID: " << storesList[i].sID << " | Location (" << setw(6) << storesList[i].Location.gLat << " ," << setw(7) << storesList[i].Location.gLong
                     << ") | Revenue :" << setw(12) << storesList[i].sA.totalsales << " | Profit : " << setw(12) << storesList[i].sA.profit << " |\n";
            }
        }
        else
        {
            cout << "                - ! Empty !\n";
        }
    }

    // Destructor
    ~SubCluster()
    {
        delete[] ID;
        delete[] Name;
        delete[] storesList;
    }
};

struct Cluster
{
    char *cID = nullptr;
    char *Name = nullptr;
    SubCluster *subClusterList = nullptr;
    Centriod center;

    Store *storesList = nullptr;
    int storeCount = 0;

    // Constructor
    Cluster() {}

    // Deep Copy
    Cluster(const Cluster &other)
    {
        center = other.center;

        string_to_char_ptr(cID, other.cID);
        string_to_char_ptr(Name, other.Name);

        if (storesList)
            delete[] storesList;

        storeCount = other.storeCount;
        storesList = new Store[storeCount];

        for (int i = 0; i < storeCount; i++)
            storesList[i] = other.storesList[i];
    }
    Cluster &operator=(const Cluster &other)
    {
        if (this == &other)
            return *this;

        center = other.center;

        string_to_char_ptr(cID, other.cID);
        string_to_char_ptr(Name, other.Name);

        if (storesList)
            delete[] storesList;

        storeCount = other.storeCount;
        storesList = new Store[storeCount];

        for (int i = 0; i < storeCount; i++)
            storesList[i] = other.storesList[i];

        return *this;
    }

    // Adding Store in StoreList
    void add_store(Store &St) { storesList[storeCount++] = St; }

    // Setter
    void set_ID_Name(string id, string name)
    {
        string_to_char_ptr(cID, id);
        string_to_char_ptr(Name, name);
    }

    // Adjusting Centriod Center
    void AdjustCenteriod()
    {

        if (storeCount != 0)
        {
            double X = 0, Y = 0;
            for (int i = 0; i < storeCount; i++)
            {
                X += storesList[i].Location.gLat;
                Y += storesList[i].Location.gLong;
            }

            X /= storeCount;
            Y /= storeCount;

            center.set(X, Y);
        }
        // else
        // {
        //     center.x /= 2;
        //     center.y /= 2;
        // }
    }

    // Display
    void display(int type = 0)
    {
        // type==0  ( only Cluster )
        // type==1  ( Cluster + SubCluster )

        cout << "   ====> Cluster:-\n";
        cout << "       --> ID : " << cID << " | Name : " << Name << " |\n";
        cout << "       --> Center (" << center.x << "," << center.y << ") \n";
        cout << "       --> Stores :-\n";
        if (storeCount != 0)
        {

            for (int i = 0; i < storeCount; i++)
            {
                cout << "           - | ID: " << storesList[i].sID << " | Location (" << setw(6) << storesList[i].Location.gLat << " ," << setw(7) << storesList[i].Location.gLong << ") |\n";
            }
        }
        else
        {
            cout << "            - ! Empty !\n";
        }

        if (type == 1)
        {
            for (int i = 0; i < 3; i++)
            {
                cout << "----------------------------------------------------------------------------------------------------------------------\n";
                if (subClusterList)
                    subClusterList[i].display();
            }
        }
    }

    ~Cluster()
    {
        delete[] cID;
        delete[] Name;
        delete[] subClusterList;
        delete[] storesList;
    }
};

// Small Helping function 2
double CalDistance(SubCluster &SCl, Store &St); // Calcutaing 2D Distance ( Revenue & Profit )
double CalDistance(Cluster &Cl, Store &St);     // Calculating Geographic Distance
Products *Return_avaliable_Products();          // All 50 Availible Products

// filling related functions
void saveToFile(SalesData *salesList, int count);                                              // Saving Sales Data
void saveToFile(Store *&storelist, int count);                                                 // Saving Stores
void loadFromFile(SalesData *&salesList, int &loadedCount, Products *&All_Availible_Products); // Loading Sales Data
void loadFromFile(Store *&StoresList, int &loadedCount);                                       // Loading Stores

// Anylytic and forcast calculating functions
void Calculate_All_Store_Analytics(SalesData *&SalesList, int &SalesCount, Store *&StoreList, int &StoreCount); // Profit , TotalSales , OperationCost , GrowthRate , OverallScore , CustomersCount , MonthlyRevenue
void Calculate_Store_Forecast(Store &St, int type = 0);                                                         // type == 0 (only Calculate) || type == 1 ( + Also Display )

// Clusters finding functions
void Find_SubCluster(Cluster &CL);
Cluster *Find_Cluster(Store *&Stores_List, int &Stores_count, const int &Cluster_Count);

// Program Starting and Ending functions
void Start_Loading_Data(SalesData *&SalesList, int &SalesCount, Store *&StoreList, int &StoreCount, Products *&All_Availible_Products);
void End_Saving_Data(SalesData *&SalesList, int &SalesCount, Store *&StoreList, int &StoreCount);

// Report Finding Function ( 10 top & 5 Bottom )
void find_10Top_5Bottom_Stores(Store *StoreList, int StoreCount, Store *topStores, Store *bottomStores, int type);
Report *Create_Four_Report(Store *StoreList, int StoreCount);

// Graph Displying Function
void display_Monthly_Sale(const Store &St); // Bar Graph

// 2D Cluster Graph Displaying Function
void Graph_Clusters(Store *StoreList, int storeCount, Cluster *clusterList, int CLuster_count);

int main()
{
    srand(time(0));

    SalesData *Sales_List = nullptr;
    int Sales_count = 0;
    Store *Store_List = nullptr;
    int Store_count = 0;

    Products *All_Availible_Products = Return_avaliable_Products();

    Start_Loading_Data(Sales_List, Sales_count, Store_List, Store_count, All_Availible_Products);

    system("pause");
    system("cls");

    string option;

    while (true) // Main Loop
    {

        cout << "\n ===> Main Menu :- \n"
             << " 1) Want to See Stores. " << (Store_count <= 0 ? "[Disable]" : "") << "\n"
             << " 2) Want To See Sales. " << (Store_count <= 0 || Sales_count <= 0 ? "[Disable]" : "") << "\n"
             << " 3) Want To See Products. \n"
             << " 4) Want To See Clusters. " << ((Store_count < 20 || Sales_count < Store_count * 100) ? "[Disable]" : "") << "\n"
             << " 5) Want To See Reports. " << ((Store_count < 20 || Sales_count < Store_count * 100) ? "[Disable]" : "") << "\n"
             << " 6) Want To See Next Month Prediction. " << ((Store_count == 0 || Sales_count < Store_count * 100) ? "[Disable]" : "") << "\n"
             << " 7) Want To Change Data. \n"
             << " 8) Exit.\n"
             << " -Enter Option : ";
        getline(cin, option);

        if ("1" == option && Store_count > 0) // Stores
        {
            system("cls");
            while (true)
            {
                cout << "\n => Select :-\n"
                     << " 1) To see All the " << Store_count << " Stores.\n"
                     << " 2) To see a Single Store by searching its ID.\n"
                     << " 3) To see a range of stores. " << (Store_count <= 1 ? "[Disable]" : "") << "\n"
                     << " 4) To go Back to Main Menu.\n"
                     << " Enter Option : ";
                getline(cin, option);

                if ("1" == option) // All Stores
                {
                    system("cls");

                    for (int i = 0; i < Store_count; i++)
                    {
                        cout << "\n----------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
                        Store_List[i].display(4);
                    }
                    cout << "\n----------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
                }
                else if ("2" == option) // Specific Store
                {
                    system("cls");

                    cout << " Enter Store ID between ( " << Store_List[0].sID << " to " << Store_List[Store_count - 1].sID << " ) : ";
                    getline(cin, option);

                    while (!is_All_Digit(option) || !(Store_List[0].sID <= stoi(option) && stoi(option) <= Store_List[Store_count - 1].sID))
                    {
                        cout << " !! Invalid ID !! Again Enter Store ID between ( " << Store_List[0].sID << " to " << Store_List[Store_count - 1].sID << " ) : ";
                        getline(cin, option);
                    }

                    int ID = stoi(option);

                    cout << "\n----------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
                    Store_List[ID - Store_List[0].sID].display(4);
                    cout << "\n----------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
                }
                else if ("3" == option && !(Store_count <= 1)) // Range of Store
                {
                    system("cls");
                    cout << " Enter the Store ID between ( " << Store_List[0].sID << " to " << Store_List[Store_count - 2].sID << " ) from where do you want start the seacrh : ";
                    getline(cin, option);

                    while (!is_All_Digit(option) || !(Store_List[0].sID <= stoi(option) && stoi(option) <= Store_List[Store_count - 2].sID))
                    {
                        cout << " !! Invalid ID !! Again Enter Store ID between ( " << Store_List[0].sID << " to " << Store_List[Store_count - 2].sID << " ) : ";
                        getline(cin, option);
                    }

                    int Start_ID = stoi(option);

                    cout << " Enter the Store ID between ( " << Start_ID + 1 << " to " << Store_List[Store_count - 1].sID << " ) at which you want to stop the seacrh : ";
                    getline(cin, option);

                    while (!is_All_Digit(option) || !(Start_ID + 1 <= stoi(option) && stoi(option) <= Store_List[Store_count - 1].sID))
                    {
                        cout << " !! Invalid ID !! Again Enter Store ID between ( " << Start_ID + 1 << " to " << Store_List[Store_count - 1].sID << " ) : ";
                        getline(cin, option);
                    }

                    int End_ID = stoi(option);

                    for (int i = Start_ID - Store_List[0].sID; i <= End_ID - Store_List[0].sID; i++)
                    {

                        cout << "\n----------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
                        Store_List[i].display(4);
                    }
                    cout << "\n----------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
                }
                else if ("4" == option) // Exit
                {
                    system("cls");
                    break;
                }
                else // Invalid Input
                {
                    system("cls");
                    continue;
                }
                system("pause");
                system("cls");
            }
        }
        else if ("2" == option && !(Store_count <= 0 || Sales_count <= 0)) // Sales Data
        {
            while (true)
            {
                system("cls");

                cout << "\n => Select :-\n"
                     << " 1) To see All the ( " << Sales_count << " ) Sales Data, but it will be to long.\n"
                     << " 2) To see All the Sales Data Related to a specific Store.\n"
                     << " 3) To see a Single Sales Data by searching it.\n"
                     << " 4) To see a range of Sales Data. " << (Sales_count <= 1 ? "[Disable]" : "") << "\n"
                     << " 5) To go Back to Main Menu.\n"
                     << " Enter Option : ";
                getline(cin, option);

                if ("1" == option) // All Sales Data
                {
                    system("cls");

                    for (int i = 0; i < Sales_count; i++)
                    {
                        cout << "\n----------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
                        Sales_List[i].display();
                    }
                    cout << "\n----------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
                }
                else if ("2" == option) // Sales Data Related to a Store
                {
                    system("cls");

                    cout << " Enter Store ID between ( " << Store_List[0].sID << " to " << Store_List[Store_count - 1].sID << " ) for which you want to see Sales Data : ";
                    getline(cin, option);

                    while (!is_All_Digit(option) || !(Store_List[0].sID <= stoi(option) && stoi(option) <= Store_List[Store_count - 1].sID))
                    {
                        cout << " !! Invalid ID !! Again Enter Store ID between ( " << Store_List[0].sID << " to " << Store_List[Store_count - 1].sID << " ) for which you want to see Sales Data : ";
                        getline(cin, option);
                    }

                    int ID = stoi(option);

                    int count = 0;
                    for (int i = 0; i < Sales_count; i++)
                    {
                        if (ID == Sales_List[i].store.sID)
                        {
                            count++;
                        }
                    }

                    cout << " There are (" << count << ") Sales Data related to This Store.\n Do you also want to see them (Y/N) : ";
                    getline(cin, option);

                    while (option[0] != 'N' && option[0] != 'n' && option[0] != 'Y' && option[0] != 'y')
                    {
                        cout << "\n !! Invalid Input !! \n";
                        cout << " Again Enter (Y/N) : ";
                        getline(cin, option);
                    }

                    char yn1 = option[0];

                    if (yn1 == 'Y' || yn1 == 'y')
                    {
                        for (int i = 0; i < Sales_count; i++)
                        {
                            if (ID == Sales_List[i].store.sID)
                            {
                                cout << "\n----------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
                                Sales_List[i].display();
                            }
                        }
                        cout << "\n----------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
                    }
                }
                else if ("3" == option) // Single Sales Data
                {
                    system("cls");

                    cout << " Enter a Sales Data number between ( " << 1 << " to " << Sales_count << " ) : ";
                    getline(cin, option);

                    while (!is_All_Digit(option) || !(1 <= stoi(option) && stoi(option) <= Sales_count))
                    {
                        cout << " !! Invalid ID !! Again Enter a Sales Data number between ( " << 1 << " to " << Sales_count << " ) : ";
                        getline(cin, option);
                    }

                    int ID = stoi(option);

                    cout << "\n----------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
                    Sales_List[ID - 1].display();
                    cout << "\n----------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
                }
                else if ("4" == option && !(Sales_count <= 1)) // Range of Sales Data
                {
                    system("cls");

                    cout << " Enter the Sales Data number between ( " << 1 << " to " << Sales_count - 1 << " ) from where do you want start the seacrh : ";
                    getline(cin, option);

                    while (!is_All_Digit(option) || !(1 <= stoi(option) && stoi(option) <= Sales_count - 1))
                    {
                        cout << " !! Invalid ID !! Again Enter a Sales Data number between ( " << 1 << " to " << Sales_count - 1 << " ) : ";
                        getline(cin, option);
                    }

                    int Start_ID = stoi(option);

                    cout << " Enter the a Sales Data number between ( " << Start_ID + 1 << " to " << Sales_count << " ) at which you want to stop the seacrh : ";
                    getline(cin, option);

                    while (!is_All_Digit(option) || !(Start_ID + 1 <= stoi(option) && stoi(option) <= Sales_count))
                    {
                        cout << " !! Invalid ID !! Again Enter a Sales Data number between ( " << Start_ID + 1 << " to " << Sales_count << " ) : ";
                        getline(cin, option);
                    }

                    int End_ID = stoi(option);

                    for (int i = Start_ID - 1; i <= End_ID - 1; i++)
                    {
                        cout << "\n----------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
                        Sales_List[i].display();
                    }
                    cout << "\n----------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
                }
                else if ("5" == option) // Exit
                {
                    system("cls");
                    break;
                }
                else // Invalid Option
                {
                    system("cls");
                    continue;
                }

                system("pause");
                system("cls");
            }
        }
        else if ("3" == option) // Products
        {
            while (true)
            {
                system("cls");

                cout << "\n => Select :-\n"
                     << " 1) To see All the ( " << 50 << " ) Availible Products.\n"
                     << " 2) To see a Single Product by searching it.\n"
                     << " 3) To go Back to Main Menu.\n"
                     << " Enter Option : ";
                getline(cin, option);

                if ("1" == option) // All Products
                {
                    system("cls");

                    cout << "\n\n";
                    for (int i = 0; i < 50; i++)
                    {
                        All_Availible_Products[i].display(1);

                        cout << "\n";
                    }
                    cout << "\n\n";
                }
                else if ("2" == option) // Single Product
                {
                    system("cls");

                    int min = stoi(All_Availible_Products[0].SKU);
                    int max = min - 1 + Products::All_Availible_Product_Count;

                    cout << " Enter the Product ID between ( " << min << " to " << max << " ) : ";
                    getline(cin, option);

                    while (!is_All_Digit(option) || !(min <= stoi(option) && stoi(option) <= max))
                    {
                        cout << " !! Invalid ID !! Again Enter the Product ID between ( " << min << " to " << max << " ) : ";
                        getline(cin, option);
                    }

                    int ID = stoi(option);

                    All_Availible_Products[ID - 400001].display();
                }
                else if ("3" == option) // Exit
                {
                    system("cls");
                    break;
                }
                else // Invalid Option
                {
                    system("cls");
                    continue;
                }
                system("pause");
                system("cls");
            }
        }
        else if ("4" == option && !(Store_count < 20 || Sales_count < Store_count * 100)) // Cluster
        {
            system("cls");

            int min_C = 1, max_C = Store_count / 5;
            cout << " Enter Number of Clusters between ( " << min_C << " to " << max_C << " ) you want to make  : ";

            getline(cin, option);

            while (!is_All_Digit(option) || !(min_C <= stoi(option) && stoi(option) <= max_C))
            {
                cout << " !! Invalid ID !! Again Enter Number of Clusters between ( " << min_C << " , " << max_C << " ) you want to make  : ";
                getline(cin, option);
            }

            int Cluster_count = stoi(option);

            cout << " Do you also want to see SubCluster (Y/N) : ";
            getline(cin, option);

            while (option[0] != 'N' && option[0] != 'n' && option[0] != 'Y' && option[0] != 'y')
            {
                cout << "\n !! Invalid Input !! \n";
                cout << " Again Enter (Y/N) : ";
                getline(cin, option);
            }

            char yn1 = option[0];

            system("cls");

            Cluster *Geographic_Clusters = Find_Cluster(Store_List, Store_count, Cluster_count);

            for (int i = 0; i < Cluster_count; i++)
            {
                cout << "\n==========================================================================================================================================================\n\n";

                Geographic_Clusters[i].display(((yn1 == 'Y' || yn1 == 'y') ? 1 : 0));
            }
            cout << "\n==========================================================================================================================================================\n\n";

            Graph_Clusters(Store_List, Store_count, Geographic_Clusters, Cluster_count);

            system("pause");

            system("cls");
        }
        else if ("5" == option && !(Store_count < 20 || Sales_count < Store_count * 100)) // Report
        {
            Report *Four_Reports = Create_Four_Report(Store_List, Store_count);

            while (true)
            {
                system("cls");

                cout << "\n => Select :- \n"
                     << " 1) To See Report with respect to Overall Score of Stores.\n"
                     << " 2) To See Report with respect to Profit of Stores.\n"
                     << " 3) To See Report with respect to Growth Rate of Stores.\n"
                     << " 4) To See Report with respect to Revenue of Stores.\n"
                     << " 5) Move back to Main Menu. \n"
                     << " Enter : ";
                getline(cin, option);

                if (option == "1") // Overall Score
                {
                    system("cls");

                    Four_Reports[0].display(0);
                }
                else if (option == "2") // Profit
                {
                    system("cls");

                    Four_Reports[1].display(1);
                }
                else if (option == "3") // Growth Rate
                {
                    system("cls");

                    Four_Reports[2].display(2);
                }
                else if (option == "4") // Revenue
                {
                    system("cls");

                    Four_Reports[3].display(3);
                }
                else if (option == "5") // Exit
                {
                    system("cls");
                    break;
                }
                else // Invalid Option
                {
                    system("cls");
                    continue;
                }
                system("pause");
                system("cls");
            }
        }
        else if ("6" == option && !(Store_count == 0 || Sales_count < Store_count * 100)) // Prediction
        {
            system("cls");
            while (true)
            {
                system("cls");

                cout << "\n => Select :- \n"
                     << " 1) To See Predicted Sales of All ( " << Store_count << " ) Stores.\n"
                     << " 2) To See Predicted Sales of a specific Stores by searching its ID.\n"
                     << " 3) Move back to Main Menu. \n"
                     << " Enter : ";

                getline(cin, option);

                if (option == "1") // All Stores
                {
                    system("cls");

                    for (int i = 0; i < Store_count; i++)
                    {
                        cout << "\n==========================================================================================================================================================\n\n";
                        Calculate_Store_Forecast(Store_List[i], 1);
                    }
                    cout << "\n==========================================================================================================================================================\n\n";
                }
                else if (option == "2") // Single Store
                {
                    system("cls");

                    cout << " Enter Store ID between ( " << Store_List[0].sID << " to " << Store_List[Store_count - 1].sID << " ) : ";
                    getline(cin, option);

                    while (!is_All_Digit(option) || !(Store_List[0].sID <= stoi(option) && stoi(option) <= Store_List[Store_count - 1].sID))
                    {
                        cout << " !! Invalid ID !! Again Enter Store ID between ( " << Store_List[0].sID << " to " << Store_List[Store_count - 1].sID << " ) : ";
                        getline(cin, option);
                    }

                    int ID = stoi(option);

                    cout << "\n==========================================================================================================================================================\n\n";
                    Calculate_Store_Forecast(Store_List[ID - Store_List[0].sID], 1);
                    cout << "\n==========================================================================================================================================================\n\n";
                }
                else if (option == "3") // Exit
                {
                    system("cls");
                    break;
                }
                else // Invalid Option
                {
                    continue;
                }

                system("pause");
                system("cls");
            }
        }
        else if ("7" == option) // Data Geneation
        {
            system("cls");
            while (true)
            {
                system("cls");
                cout << " Current No of Stores : " << Store_count << endl;
                cout << " Current No of Sales Data : " << Sales_count << endl;
                cout << "\n Menu :\n"
                     << " 1) Delete All Stores. " << (Store_count <= 0 ? "[Disable]" : "") << "\n"
                     << " 2) Delete All Sales Data. " << (Sales_count <= 0 ? "[Disable]" : "") << "\n"
                     << " 3) Add New Stores. \n"
                     << " 4) Add New SalesData for " << Store_count << " Stores. " << (Store_count == 0 ? "[Disable]" : "") << "\n"
                     << " 5) Back to Main Menu.\n"
                     << " Enter Option ";
                getline(cin, option);

                if (option == "1" && !(Store_count <= 0)) // Deleting All Stores
                {
                    delete[] Store_List;
                    Store_List = nullptr;

                    Store::all_Stores_ID_count = 300000;
                    Employees::all_Manager_ID_count = 200000;
                    Employees::all_Staff_ID_count = 100000;

                    Store_count = 0;
                }
                else if (option == "2" && !(Sales_count <= 0)) // Deleting All Sales Data
                {
                    delete[] Sales_List;
                    Sales_List = nullptr;
                    Sales_count = 0;
                    SalesData::Sale_File_Changed = true;
                }
                else if (option == "3") // Add New Stores
                {
                    system("cls");

                    cout << " Enter Number of Store you want to add (Enter 0 to skip) : ";
                    getline(cin, option);

                    while (!is_All_Digit(option))
                    {
                        cout << " ! Invalid Input ! Again Enter Number of Store you want to add (Enter 0 to skip) : ";
                        getline(cin, option);
                    }

                    int Count = stoi(option);

                    if (Count == 0)
                    {
                        system("cls");
                        continue;
                    }

                    Store *temp = Store_List;

                    Store_List = new Store[Store_count + Count];

                    for (int i = 0; i < Store_count; i++)
                        Store_List[i] = temp[i];

                    for (int i = Store_count; i < Store_count + Count; i++)
                        Store_List[i].random_setData();

                    Store_count += Count;
                }
                else if (option == "4") // Add New Sales Data
                {
                    system("cls");

                    if (Store_count == 0)
                        continue;

                    cout << " Enter Number of Sales Data you want to add (Enter 0 to skip) : ";
                    getline(cin, option);

                    while (!is_All_Digit(option))
                    {
                        cout << " ! Invalid Input ! Again Enter Number of Sale Data you want to add (Enter 0 to skip) : ";
                        getline(cin, option);
                    }

                    int Count = stoi(option);

                    if (Count == 0)
                    {
                        system("cls");
                        continue;
                    }

                    SalesData *temp = Sales_List;

                    Sales_List = new SalesData[Sales_count + Count];

                    for (int i = 0; i < Sales_count; i++)
                        Sales_List[i] = temp[i];

                    for (int i = Sales_count; i < Sales_count + Count; i++)
                    {
                        Sales_List[i].random_setData(Store_List, Store_count, All_Availible_Products);
                    }

                    Sales_count += Count;
                    SalesData::Sale_File_Changed = true;
                }
                else if (option == "5") // Exit
                {
                    End_Saving_Data(Sales_List, Sales_count, Store_List, Store_count);
                    SalesData::Sale_File_Changed = false;
                    Start_Loading_Data(Sales_List, Sales_count, Store_List, Store_count, All_Availible_Products);

                    system("cls");
                    break;
                }
                else // Invalid Option
                {
                    system("cls");
                    continue;
                }

                system("pause");
                system("cls");
            }
        }
        else if ("8" == option) // Exit
        {
            system("cls");
            break;
        }
        else // Invalid Option
        {
            system("cls");
            continue;
        }
    }

    End_Saving_Data(Sales_List, Sales_count, Store_List, Store_count);
    return 0;
}

void Start_Loading_Data(SalesData *&SalesList, int &SalesCount, Store *&StoreList, int &StoreCount, Products *&All_Availible_Products)
{
    if (SalesList)
        delete[] SalesList;
    if (StoreList)
        delete[] StoreList;

    SalesList = nullptr;
    StoreList = nullptr;

    // Loading Data
    cout << "\n";
    loadFromFile(SalesList, SalesCount, All_Availible_Products);
    cout << "\n ----> All sales data loaded successfully!\n";
    loadFromFile(StoreList, StoreCount);

    cout << "\n ----> All store data loaded successfully!\n";

    // Incrementing Count
    Store::all_Stores_ID_count += StoreCount;
    Employees::all_Manager_ID_count += StoreCount;

    int Staff_count = 0;
    for (int i = 0; i < StoreCount; i++)
    {
        Staff_count += StoreList[i].no_of_Staff;
    }
    Employees::all_Staff_ID_count += Staff_count;

    cout << "\n =====> All Data Loaded Succesfully ";
    cout << "\n =====> Program Started  \n\n";

    // Calculating Store Anylatics And Forecast
    Calculate_All_Store_Analytics(SalesList, SalesCount, StoreList, StoreCount);

    for (int i = 0; i < StoreCount; i++)
    {
        Calculate_Store_Forecast(StoreList[i]);
    }
}

void End_Saving_Data(SalesData *&SalesList, int &SalesCount, Store *&StoreList, int &StoreCount)
{
    cout << "\n\n";
    // Saving Data
    if (SalesData::Sale_File_Changed)
    {
        saveToFile(SalesList, SalesCount);
        cout << "\n ----> All Sales Data Saved successfully!\n";
    }
    else
    {
        cout << " ----> All Sales Data is remained same!\n";
    }
    saveToFile(StoreList, StoreCount);
    cout << "\n ----> All Store data Saved successfully!\n";

    cout << "\n =====> All Data Saved Succesfully ";
    cout << "\n =====> Program Ended \n\n";
}

void display_Monthly_Sale(const Store &St)
{

    double DBL_MAX = 1.79769e+308;
    double DBL_MIN = 2.22507e-308;

    double max_Sale = DBL_MIN, min_Sale = DBL_MAX;

    for (int i = 0; i < 24; i++)
    {
        max_Sale = max(max_Sale, St.MonthlyRevenue[i]);
        min_Sale = min(min_Sale, St.MonthlyRevenue[i]);
    }
    int rows = 18; // Bounds
    double unit_rows = max_Sale / rows;
    rows += 2;
    // Graph loop
    for (int i = 0; i < rows; i++)
    {
        cout << setw(10) << int(unit_rows * (rows - i)) / 1000 * 1000;
        cout << " -|";
        for (int j = 0; j < 24; j++)
        {
            if (St.MonthlyRevenue[j] >= unit_rows * (rows - i))
            {
                cout << "  *  ";
            }
            else
            {
                cout << "     ";
            }
        }

        if (St.sF.predictedSales >= unit_rows * (rows - i))
        {
            cout << "  x  ";
        }
        else
        {
            cout << "     ";
        }
        cout << endl;
    }

    cout << setw(10) << "==========" << "==|";
    for (int j = 0; j < 25; j++)
    {
        cout << "=====";
    }
    cout << endl;

    cout << setw(10) << "Months " << "  |";
    for (int j = 0; j < 24; j++)
    {
        cout << " " << setw(2) << j + 1 << "  ";
    }
    cout << "|next|\n ";
}

void Graph_Clusters(Store *StoreList, int storeCount, Cluster *clusterList, int CLuster_count)
{
    const int x = 18; // Bounds
    const int y = 36;

    cout << "     ";
    for (int j = -y / 2; j <= y / 2; j++)
        cout << setw(4) << j * 10;
    cout << endl;

    cout << "     +";
    for (int j = -y; j <= y; j++)
        cout << "--";
    cout << "+" << endl;

    for (int i = -x; i <= x; i++)
    {
        if (i % 2 == 0)
            cout << setw(4) << (i / 2) * 10 << " |";
        else
            cout << setw(4) << "" << " |";

        for (int j = -y; j <= y; j++)
        {
            bool Cl = false, St = false;

            for (int k = 0; k < CLuster_count; k++) // Cluster
            {
                if (fabs(clusterList[k].center.x - (i * 5)) <= 2.5 &&
                    fabs(clusterList[k].center.y - (j * 5)) <= 2.5)
                {
                    Cl = true;
                    break;
                }
            }

            for (int k = 0; k < storeCount; k++) // Store
            {
                if (fabs(StoreList[k].Location.gLat - (i * 5)) <= 2.5 &&
                    fabs(StoreList[k].Location.gLong - (j * 5)) <= 2.5)
                {
                    St = true;
                    break;
                }
            }

            if (Cl && St)
                cout << (rand() % 2 ? "0." : ".0"); // both
            else if (Cl)
                cout << "O "; // only Cluster
            else if (St)
                cout << ". "; // only store
            else
                cout << "  "; // empty
        }

        cout << "|" << endl;
    }

    cout << "     +";
    for (int j = -y; j <= y; j++)
        cout << "--";
    cout << "+" << endl;
}

void Calculate_Store_Forecast(Store &St, int type)
{
    if (1 == type)
    {
        cout << " ========== Sales Forecast ==========" << endl;
        cout << " Store:- | Name : " << St.sName << " | ID : " << St.sID << " |\n\n\n";

        display_Monthly_Sale(St);
        cout << "\n\n";
    }

    double avg_4_Sales[21]; // moving Average
    double lastAvg = 0;
    int positive_count = 0, negative_count = 0; // count of Ups and Downs

    for (int i = 0; i < 21; i++) // Calculating Moving Averages
    {
        avg_4_Sales[i] = (St.MonthlyRevenue[i] +
                          St.MonthlyRevenue[i + 1] +
                          St.MonthlyRevenue[i + 2] +
                          St.MonthlyRevenue[i + 3]) /
                         4.0;

        if (i > 0)
        {
            if (avg_4_Sales[i] > avg_4_Sales[i - 1])
                positive_count++;
            else
                negative_count++;
        }
        lastAvg = avg_4_Sales[i];
    }

    double latest_Revenue = (St.MonthlyRevenue[21] +
                             St.MonthlyRevenue[22] +
                             St.MonthlyRevenue[23]) /
                            3.0;

    double trend_Factor = (positive_count - negative_count) * 0.3;              // positve or Negative
    St.sF.predictedSales = lastAvg + (lastAvg - latest_Revenue) * trend_Factor; // predicted Sales

    St.sF.confidencelevel = (double(positive_count) / (positive_count + negative_count)) * 100; // Confidence Level

    St.sF.warningflag = (negative_count > positive_count) && (negative_count > 12); // Warning Flag if Negative > Positive

    if (1 == type)
    {
        cout << " Increasing Trend : " << ((double)positive_count / 21.0) * 100 << " %\n";
        cout << " Decreasing Trend : " << ((double)negative_count / 21.0) * 100 << " %\n";

        if (St.sF.warningflag)
        {
            cout << " [!] Warning: Sales Decline Detected! \n";
        }

        cout << " Predicted Sales for Next Month : " << St.sF.predictedSales << "\n";
        cout << " Confidence Level : " << St.sF.confidencelevel << " %\n\n";
    }
}

double CalDistance(SubCluster &SCl, Store &St)
{
    long double X_X = pow(SCl.subCenter.x - St.sA.totalsales, 2);
    long double Y_Y = pow(SCl.subCenter.y - St.sA.profit, 2);

    return sqrt(X_X + Y_Y);
}

void Find_SubCluster(Cluster &CL)
{
    double DBL_MAX = 1.79769e+308;
    double DBL_MIN = 2.22507e-308;

    double Min_P = 0, Min_R = 0, Max_P = 0, Max_R = 0;

    Min_P = DBL_MAX;
    Max_P = DBL_MIN;
    Max_R = DBL_MIN;
    Min_R = DBL_MAX;

    for (int i = 0; i < CL.storeCount; i++) // Finding MAX and MIN
    {
        Max_P = max(Max_P, CL.storesList[i].sA.profit);
        Min_P = min(Min_P, CL.storesList[i].sA.profit);

        Max_R = max(Max_R, Max_R = CL.storesList[i].sA.totalsales);
        Min_R = min(Min_R, Max_R = CL.storesList[i].sA.totalsales);
    }
    CL.subClusterList = new SubCluster[3];

    CL.subClusterList[0].set_ID_Name(to_string(stoi(CL.cID) + 1), "Top-Stores"); // Dividing Cluster in to 3 groups
    CL.subClusterList[1].set_ID_Name(to_string(stoi(CL.cID) + 2), "Average-Stores");
    CL.subClusterList[2].set_ID_Name(to_string(stoi(CL.cID) + 3), "Struggling-Stores");

    // setting centers
    CL.subClusterList[0].subCenter.set(Max_R, Max_P);
    CL.subClusterList[1].subCenter.set((Max_R + Min_R) / 2, (Max_P + Min_P) / 2);
    CL.subClusterList[2].subCenter.set(Min_R, Min_P);

    // allocating memories
    for (int i = 0; i < 3; i++)
        CL.subClusterList[i].storesList = new Store[CL.storeCount];

    int iterationLimit = 100000;
    int iterations = 0;

    while (true)
    {
        if (iterations++ > iterationLimit) // limit to avoid infinite loop
        {
            cout << "Iteration limit (SUBCluster) reached, stopping!" << endl;
            break;
        }

        for (int I = 0; I < CL.storeCount; I++) // Movig through Every Store
        {

            double Min_distance = CalDistance(CL.subClusterList[0], CL.storesList[I]);
            int Min_J = 0;

            for (int J = 1; J < 3; J++) // Minimum distance
            {

                double current_distance = CalDistance(CL.subClusterList[J], CL.storesList[I]);
                if (Min_distance > current_distance)
                {
                    Min_distance = current_distance;
                    Min_J = J;
                }
            }
            CL.subClusterList[Min_J].add_store(CL.storesList[I]);
        }

        Centriod Center[3]; // for storing previous center value

        for (int J = 0; J < 3; J++)
        {
            Center[J] = CL.subClusterList[J].subCenter;
            CL.subClusterList[J].AdjustCenteriod();
        }

        bool is_Same = true;
        for (int J = 0; J < 3; J++)
        { // Compainring Previous and new centers
            if (Center[J].x != CL.subClusterList[J].subCenter.x || Center[J].y != CL.subClusterList[J].subCenter.y)
            {
                is_Same = false;
                break;
            }
        }

        if (is_Same)
            break;
        if (CL.storeCount <= 3 && iterations == 3)
            break;

        for (int i = 0; i < 3; i++)
        { // making array empty for again clustering
            CL.subClusterList[i].storeCount = 0;
        }
    }
}
double CalDistance(Cluster &Cl, Store &St)
{

    long double X_X = pow(Cl.center.x - St.Location.gLat, 2);
    long double Y_Y = pow(Cl.center.y - St.Location.gLong, 2);

    return sqrt(X_X + Y_Y);
}
Cluster *Find_Cluster(Store *&Stores_List, int &Stores_count, const int &Cluster_Count)
{

    Cluster *Geographic_clusters = new Cluster[Cluster_Count]; //  allocating memory

    for (int i = 0; i < Cluster_Count; i++)
        Geographic_clusters[i].set_ID_Name(to_string(100000 + ((1 + i) * 100)), "Geogaphic Cluster " + to_string(1001 + i));

    for (int i = 0; i < Cluster_Count; i++) // allocating memory
        Geographic_clusters[i].storesList = new Store[Stores_count];

    bool isempty = false;

    int iterationLimit_2 = 1000;
    int iterations_2 = 0;

    do
    {
        if (iterations_2++ > iterationLimit_2) // to avoid infinite loop
        {
            cout << " !! Iteration limit (MainCluster2) reached, stopping !!\n !! Some of the Geographic Cluster will be Empty !!\n";

            break;
        }

        for (int i = 0; i < Cluster_Count; i++)
        {
            Geographic_clusters[i].center.set(rand() % 181 - 90, rand() % 361 - 180);
            Geographic_clusters[i].storeCount = 0;
        }

        int iterationLimit = 10000;
        int iterations = 0;

        while (true)
        {
            if (iterations++ > iterationLimit)
            {
                cout << "Iteration limit (MainCluster1) reached, stopping!" << endl;
                break;
            }

            for (int I = 0; I < Stores_count; I++) // passing through every Store
            {

                double Min_distance = CalDistance(Geographic_clusters[0], Stores_List[I]);
                int Min_J = 0;

                for (int J = 1; J < Cluster_Count; J++) // Miniumum distance
                {
                    double current_distance = CalDistance(Geographic_clusters[J], Stores_List[I]);
                    if (Min_distance > current_distance)
                    {
                        Min_distance = current_distance;
                        Min_J = J;
                    }
                }

                Geographic_clusters[Min_J].add_store(Stores_List[I]); // adding store
            }

            Centriod Center[Cluster_Count]; // previous center

            for (int J = 0; J < Cluster_Count; J++)
            {
                Center[J] = Geographic_clusters[J].center;
                Geographic_clusters[J].AdjustCenteriod();
            }

            bool is_Same = true;
            for (int J = 0; J < Cluster_Count; J++)
            {
                // compairing previous and new centers
                if (Center[J].x != Geographic_clusters[J].center.x || Center[J].y != Geographic_clusters[J].center.y)
                {
                    is_Same = false;
                    break;
                }
            }

            if (is_Same)
                break;
            if (double(Stores_count) / Cluster_Count < 2 && iterations == 10)
                break;

            for (int i = 0; i < Cluster_Count; i++)
            {
                Geographic_clusters[i].storeCount = 0;
            }
        }

        isempty = false;
        for (int i = 0; i < Cluster_Count; i++)
        {
            if (Geographic_clusters[i].storeCount == 0)
            {
                isempty = true;
                break;
            }
        }

    } while (isempty);

    // Finding SubCLusters
    for (int i = 0; i < Cluster_Count; i++)
    {
        if (Geographic_clusters[i].storeCount >= 1)
            Find_SubCluster(Geographic_clusters[i]);
        else
        {
            Geographic_clusters[i].subClusterList = new SubCluster[3];
            Geographic_clusters[i].subClusterList[0].set_ID_Name("001", "Top-Stores");
            Geographic_clusters[i].subClusterList[1].set_ID_Name("002", "Average-Stores");
            Geographic_clusters[i].subClusterList[2].set_ID_Name("003", "Struggling-Stores");

            Geographic_clusters[i].subClusterList[0].storesList = nullptr;

            Geographic_clusters[i].subClusterList[1].storesList = new Store[Geographic_clusters[i].storeCount];
            Geographic_clusters[i].subClusterList[1].storeCount = Geographic_clusters[i].storeCount;

            for (int j = 0; j < Geographic_clusters[i].storeCount; j++)
            {
                Geographic_clusters[i].subClusterList[1].storesList[j] = Geographic_clusters[i].storesList[j];
            }

            Geographic_clusters[i].subClusterList[0].storesList = nullptr;
            Geographic_clusters[i].subClusterList[2].storesList = nullptr;
        }
    }

    return Geographic_clusters;
}

void find_10Top_5Bottom_Stores(Store *StoreList, int StoreCount, Store *topStores, Store *bottomStores, int type)
{
    double DBL_MAX = 1.79769e+308;
    double DBL_MIN = 2.22507e-308;

    bool *selected = new bool[StoreCount]; // to Avoid repitition
    for (int i = 0; i < StoreCount; i++)
        selected[i] = false;

    for (int i = 0; i < 10; i++) // 10 Top Store
    {
        int maxIndex = -1;
        double maxValue = DBL_MIN;

        for (int j = 0; j < StoreCount; j++) // Moving Through all Store to find Top (Max)
        {
            if (selected[j])
                continue;

            double value = 0;

            switch (type)
            {
            case 0:
                value = StoreList[j].sA.OverallScore;
                break;
            case 1:
                value = StoreList[j].sA.profit;
                break;
            case 2:
                value = StoreList[j].sA.GrowthRates;
                break;
            case 3:
                value = StoreList[j].sA.totalsales;
                break;
            }

            if (value > maxValue)
            {
                maxValue = value;
                maxIndex = j;
            }
        }

        if (maxIndex != -1)
        {
            topStores[i] = StoreList[maxIndex]; // storing top store
            selected[maxIndex] = true;
        }
    }

    for (int i = 0; i < StoreCount; i++)
        selected[i] = false;

    for (int i = 0; i < 5; i++) // 5 Bottom Store
    {
        int minIndex = -1;
        double minValue = DBL_MAX;

        for (int j = 0; j < StoreCount; j++) // Moving Through all Stores to find (Minimum)
        {
            if (selected[j])
                continue;

            double value = 0;
            switch (type)
            {
            case 0:
                value = StoreList[j].sA.OverallScore;
                break;
            case 1:
                value = StoreList[j].sA.profit;
                break;
            case 2:
                value = StoreList[j].sA.GrowthRates;
                break;
            case 3:
                value = StoreList[j].sA.totalsales;
                break;
            }

            if (value < minValue)
            {
                minValue = value;
                minIndex = j;
            }
        }

        if (minIndex != -1)
        {
            bottomStores[i] = StoreList[minIndex]; // Storing minimum
            selected[minIndex] = true;
        }
    }
}

Report *Create_Four_Report(Store *StoreList, int StoreCount)
{
    if (StoreList == nullptr || StoreCount <= 0)
        return nullptr;

    Report *Four_Reports = new Report[4]; // 4 types of report

    for (int type = 0; type < 4; type++)
    {

        Four_Reports[type].topStores = new Store[10];
        Four_Reports[type].bottomStores = new Store[5];

        find_10Top_5Bottom_Stores(StoreList, StoreCount, Four_Reports[type].topStores, Four_Reports[type].bottomStores, type);
    }

    return Four_Reports;
}

void Calculate_All_Store_Analytics(SalesData *&SalesList, int &SalesCount, Store *&StoreList, int &StoreCount)
{
    double DBL_MAX = 1.79769e+308;
    double DBL_MIN = 2.22507e-308;

    for (int x = 0; x < StoreCount; x++)
    {
        int Store_ID = StoreList[x].sID;

        { // initiaizing all to null
            StoreList[x].sA.totalsales = 0;
            StoreList[x].sA.totaloperationalcost = 0;
            StoreList[x].sA.profit = 0;

            StoreList[x].sA.GrowthRates = 0;
            StoreList[x].sA.OverallScore = 0;

            for (int i = 0; i < 24; i++)
            {
                StoreList[x].customerCountMonthly[i] = 0;
                StoreList[x].MonthlyRevenue[i] = 0;
            }
        }

        for (int y = 0; y < SalesCount; y++) // moving through all Stores to calculate
        {
            int Sales_Store_ID = SalesList[y].store.sID;

            if (Store_ID == Sales_Store_ID)
            {
                // Total Sales (Revenue)
                {
                    StoreList[x].sA.totalsales += SalesList[y].totalSaleAmount;
                }

                // Customers Count & Monthly Sales
                {
                    string Sales_time = SalesList[y].date;

                    int month;
                    int year;
                    int ind = 0;
                    int Arr_i = 0;
                    int n = Sales_time.length();

                    while (Sales_time[ind] != '-')
                        ind++;

                    int start = ++ind;

                    while (Sales_time[ind] != '-')
                        ind++;

                    month = stoi(Sales_time.substr(start, ind - start));

                    ind++;

                    year = stoi(Sales_time.substr(ind, n - ind));

                    Arr_i = (month - 1) + 12 * (year - 2025);

                    if (0 <= Arr_i && Arr_i < 24)
                    {
                        StoreList[x].customerCountMonthly[Arr_i] += 1;
                        StoreList[x].MonthlyRevenue[Arr_i] += SalesList[y].totalSaleAmount;
                    }
                    else
                    {
                        cout << "\n ---- Error (1) ----\n";
                    }
                }
            }
        }

        // Calculating MonthlyCost , GrowhRates , Profit , OperationalCost
        {
            StoreList[x].calculating_sMonthlyCost();

            StoreList[x].sA.totaloperationalcost = 24 * (StoreList[x].sMonthlyCost) + 0.9 * StoreList[x].sA.totalsales;
            StoreList[x].sA.profit = StoreList[x].sA.totalsales - StoreList[x].sA.totaloperationalcost;

            {
                if (StoreList[x].MonthlyRevenue[0] == 0)
                {
                    StoreList[x].sA.GrowthRates = 100;
                }
                else
                {

                    StoreList[x].sA.GrowthRates = StoreList[x].MonthlyRevenue[23] - StoreList[x].MonthlyRevenue[0];
                    StoreList[x].sA.GrowthRates /= StoreList[x].MonthlyRevenue[0];
                    StoreList[x].sA.GrowthRates *= 100;
                }
            }
        }
    }

    // Calculating Max Min Profit , GrowthRate , Revenue
    double Max_Profit = DBL_MIN, Max_GrowthRates = DBL_MIN, Max_Revenue = DBL_MIN;
    double Min_Profit = DBL_MAX, Min_GrowthRates = DBL_MAX, Min_Revenue = DBL_MAX;

    for (int x = 0; x < StoreCount; x++)
    {
        Max_Profit = max(StoreList[x].sA.profit, Max_Profit);
        Max_GrowthRates = max(StoreList[x].sA.GrowthRates, Max_GrowthRates);
        Max_Revenue = max(StoreList[x].sA.totalsales, Max_Revenue);

        Min_Profit = min(StoreList[x].sA.profit, Min_Profit);
        Min_GrowthRates = min(StoreList[x].sA.GrowthRates, Min_GrowthRates);
        Min_Revenue = min(StoreList[x].sA.totalsales, Min_Revenue);
    }

    for (int x = 0; x < StoreCount; x++)
    {

        double Profit = StoreList[x].sA.profit;
        double GrowthRate = StoreList[x].sA.GrowthRates;
        double Revenue = StoreList[x].sA.totalsales;

        // Calculating Profit , GrowthRate , Revenue Score
        double Profit_Score = ((Profit - Min_Profit) / (Max_Profit - Min_Profit)) * 100;
        double Growth_Score = ((GrowthRate - Min_GrowthRates) / (Max_GrowthRates - Min_GrowthRates)) * 100;
        double Revenue_Score = ((Revenue - Min_Revenue) / (Max_Revenue - Min_Revenue)) * 100;

        if (Max_Profit == Min_Profit)
            Profit_Score = 50;
        if (Max_GrowthRates == Min_GrowthRates)
            Growth_Score = 50;
        if (Max_Revenue == Min_Revenue)
            Revenue_Score = 50;

        ///------- Overall Score --------///
        StoreList[x].sA.OverallScore = 0.5 * Profit_Score + 0.3 * Revenue_Score + 0.2 * Growth_Score;
    }

    for (int x = 0; x < StoreCount; x++)
    {
        int Store_ID = StoreList[x].sID;

        for (int y = 0; y < SalesCount; y++)
        {
            int Sales_Store_ID = SalesList[y].store.sID;

            if (Store_ID == Sales_Store_ID)
            {
                // Connecting Store of SaleData to it Store through DeepCopy
                SalesList[y].store = StoreList[x];
            }
        }
    }
}

// Fillig related functoins
void saveToFile(SalesData *salesList, int count)
{
    ofstream file("SalesData.txt");
    if (!file)
    {
        cout << " ! Sales File Not Found!\n";

        file << "=======\n";
        file << 0 << "\n";
        file << "=======\n";
        return;
    }
    file << "=====\n";
    file << count << "\n"; // Save number of records

    file << "=====\n";

    cout << " ..... Saving SalesData. ";
    for (int in = 0; in < count; in++)
    {

        SalesData &data = salesList[in];

        file << data.date << "|" // data time totalSale
             << data.time << "|"
             << data.totalSaleAmount << "\n";

        file << "==>" << data.store.sID << "|"; // Store ID

        file << data.store.sName << "\n"; // Store Name

        file << left << setw(2) << data.productCount << "|"; // Product
        for (int i = 0; i < data.productCount; i++)
        {
            file << data.products[i].SKU << "|"; // Product ID
        }
        file << "\n-------\n";
    }

    file.close();
}

void loadFromFile(SalesData *&salesList, int &loadedCount, Products *&All_Availible_Products)
{
    ifstream file("SalesData.txt");
    if (!file)
    {
        cerr << " ! Sales file not found !\n";
        SalesData::Sale_File_Changed = true;
        loadedCount = 0;
        return;
    }

    string st;
    int numRecords = 0;

    if (!getline(file, st))
    {
        cout << " Sales File is Empty !";
        SalesData::Sale_File_Changed = true;
        loadedCount = 0;
        return;
    }

    if (getline(file, st))
    {
        numRecords = stoi(st);
        loadedCount = numRecords;
        salesList = new SalesData[numRecords];
    }

    getline(file, st);

    cout << " ..... Loading SalesData. ";

    for (int in = 0; in < numRecords; in++)
    {

        SalesData &Data = salesList[in];

        if (getline(file, st))
        {
            Data.date = st.substr(0, 10); // Date time saleAmount

            Data.time = st.substr(11, 8);

            Data.totalSaleAmount = stod(st.substr(20));
        }

        // ===> Store
        if (getline(file, st))
        {
            Data.store.sID = stoi(st.substr(3, 6));
        }

        // ===> Products
        if (getline(file, st))
        {
            Data.productCount = stoi(st);
            Data.products = new Products[Data.productCount];

            {
                string ID;
                for (int j = 0; j < Data.productCount; j++)
                {
                    ID = st.substr(j * 7 + 3, 6);
                    string_to_char_ptr(Data.products[j].SKU, ID);

                    int index = stoi(ID) - 400001;
                    string_to_char_ptr(Data.products[j].pName, string(All_Availible_Products[index].pName));

                    Data.products[j].unitPrice = All_Availible_Products[index].unitPrice;
                }
            }
        }

        getline(file, st);
    }

    file.close();
}

void saveToFile(Store *&storelist, int count)
{

    ofstream file("Stores.txt");
    if (!file)
    {
        cout << " ! Store File Not Found!\n";

        file << "=======\n";
        file << 0 << "\n";
        file << "=======\n";

        return;
    }
    file << "=====\n";
    file << count << "\n"; // count

    file << "=====\n";

    cout << " ..... Loading Stores. ";
    for (int in = 0; in < count; in++)
    {

        Store &Data = storelist[in];

        file << in + 1 << "\n";
        file << "-------\n";

        file << "==> " << Data.sID << "|"; // id name monthlycost
        file << left << setw(16) << Data.sName << "|";
        file << Data.sMonthlyCost << "\n";

        file << left << setw(6) << Data.Location.gLat << "|" // location
             << Data.Location.gLong << "\n";

        file << Data.Manager.eID << "|" // Manager
             << left << setw(14) << string(Data.Manager.eName) << "|"
             << Data.Manager.salary << "\n";

        file << Data.no_of_Staff << "\n"; // Staff
        for (int i = 0; i < Data.no_of_Staff; i++)
        {
            file << Data.Staff[i].eID << "|"
                 << left << setw(14) << Data.Staff[i].eName << "|"
                 << Data.Staff[i].salary << "\n";
        }

        file << "-------\n";
    }

    file.close();
}

void loadFromFile(Store *&StoresList, int &loadedCount)
{
    ifstream file("Stores.txt");
    if (!file)
    {
        cerr << " Store File not found!\n";
        loadedCount = 0;
        return;
    }

    string st;
    int numRecords = 0;

    if (!getline(file, st))
    {
        cout << " Store File is Empty ! ";
        loadedCount = 0;
        return;
    }

    if (getline(file, st))
    {
        numRecords = stoi(st);
        loadedCount = numRecords;
        StoresList = new Store[numRecords];
    }

    getline(file, st);

    cout << " ..... Loading Stores.";
    for (int in = 0; in < numRecords; in++)
    {

        Store &Data = StoresList[in];

        getline(file, st);
        getline(file, st);

        // ===> Store
        if (getline(file, st))
        {
            Data.sID = stoi(st.substr(4, 6));
            string_to_char_ptr(Data.sName, st.substr(11, 16));
            Data.sMonthlyCost = stod(st.substr(29));
        }

        // Location
        if (getline(file, st))
        {
            Data.Location.gLat = stod(st.substr(0, 6));
            Data.Location.gLong = stod(st.substr(7));
        }

        // Manager
        if (getline(file, st))
        {

            Data.Manager.eID = stoi(st.substr(0, 6));

            string_to_char_ptr(Data.Manager.eName, st.substr(7, 14));
            Data.Manager.salary = stod(st.substr(22));
        }

        // Staff
        if (getline(file, st))
        {

            Data.no_of_Staff = stoi(st);
            Data.Staff = new Employees[Data.no_of_Staff];
            for (int j = 0; j < Data.no_of_Staff; j++)
            {
                if (getline(file, st))
                {
                    Data.Staff[j].eID = stoi(st.substr(0, 6));

                    string_to_char_ptr(Data.Staff[j].eName, st.substr(7, 14));

                    Data.Staff[j].salary = stod(st.substr(22));
                }
            }
        }

        // ===> Products

        getline(file, st);
        // getline(file, st);
    }

    file.close();

    return;
}

// Small Helping functions
void string_to_char_ptr(char *&ptr, const string &st)
{
    if (!st.empty())
    {
        if (ptr)
            delete[] ptr;

        ptr = new char[st.length() + 1];

        for (size_t i = 0; i < st.length(); i++)
            ptr[i] = st[i];

        ptr[st.length()] = '\0';
    }
}

bool is_All_Digit(string st)
{
    if (st.empty())
        return false;

    for (int i = 0; i < st.length(); i++)
    {
        if (!('0' <= st[i] && st[i] <= '9'))
        {
            return false;
        }
    }
    return true;
}

string take_random_name()
{
    string Human_Names[] = {"Aban", "Abbas", "Abbud", "Abbudin", "Abdul", "Abdel", "Abdul-Alim", "Abdul-Aliyy", "Abdul-Azim", "Abdul-Aziz", "Abdul-Bari", "Abdul-Basit", "Abdul-Fattah", "Abdul-Ghaffar", "Abdul-Ghafur", "Abdul-Hadi", "Abdul-Hafiz", "Abdul-Hakam", "Abdul-Hakim", "Abdul-Halim", "Abdul-Hamid", "Abdul-Haqq", "Abdul-Hasib", "Abdul-Jabbar", "Abdul-Jalil", "Abdul-Karim", "Abdul-Khaliq", "Abdul-Latif", "Abdul-Malik", "Abdul-Majid", "Abdul-Matin", "Abdul-Muhaimin", "Abdul-Muizz", "Abdul-Mujib", "Abdul-Mutaal", "Abdul-Muttalib", "Abdul-Nasser", "Abdul-Nasir", "Abdul-Qadir", "Abdul-Qahhar", "Abdul-Quddus", "Abdul-Rafi", "Abdul-Rahim", "Abdul-Rahman", "Abdul-Rashid", "Abdul-Rauf", "Abdul-Razzaq", "Abdul-Sabur", "Abdul-Salam", "Abdul-Samad", "Abdul-Sami", "Abdul-Shakur", "Abdul-Tawwab", "Abdul-Wadud", "Abdul-Wahhab", "Abdul-Wahid", "Abdullah", "Abraha", "Abu", "Abu", "Adel", "Adham", "Adnan", "Afif", "Afeef", "Ahmad", "Ahmed", "Akil", "Akram", "Ala", "Aladdin", "Ala", "Ali", "Aliyy", "Alim", "Altair", "Amid", "Amin", "Ameen", "Amir", "Ameer", "Amjad", "Ammar", "Amr", "Anbar", "Anis", "Anwar", "Arfan", "Arif", "Asad", "Asadel", "Ashraf", "Asif", "Asim", "Aswad", "Ata", "Atif", "Awad", "Ayman", "Ayyad", "Ayyub", "Ayoob", "Aza", "Azhar", "Azeem", "Azim", "Azzam", "Badr", "Badr", "Baha", "Baha", "Bahiyy", "Bahir", "Barakah", "Bashshar", "Basil", "Bassam", "Basim", "Bilal", "Bishr", "Boulos", "Burhan", "Bursuq", "Butrus", "Dabir", "Daud", "Dawud", "Dharr", "Dhul", "Diya", "Duqaq", "Emir", "Esam", "Essam", "Fadi", "Fadil", "Fahd", "Fahad", "Faisal", "Faysal", "Fakhir", "Fakhiri", "Fakhry", "Fakih", "Farid", "Fareed", "Fariq", "Fareeq", "Faris", "Farraj", "Faruq", "Farooq", "Fath", "Fatin", "Fateen", "Fawwaz", "Fawzi", "Ferran", "Fida", "Firas", "Fouad", "Fudail", "Gamal", "Gamali", "Ghalib", "Ghassan", "Ghazi", "Ghiyath", "Habib", "Hadad", "Haddad", "Hadi", "Hajjaj", "Hakeem", "Hakim", "Hakem", "Halim", "Hamal", "Hamdan", "Hamid", "Hamzah", "Hana", "Hanbal", "Hani", "Hanif", "Harith", "Haroun", "Harun", "Hashim", "Hassan", "Hatim", "Haytham", "Hilal", "Hilel", "Hisham", "Hud", "Houd", "Hudhayfah", "Humam", "Husain", "Hussein", "Husam", "Husam", "Husayn", "Ibrahim", "Idris", "Ihsan", "Imad", "Imad", "Imran", "Irfan", "Isa", "Eisa", "Isam", "Issam", "Ishaq", "Ismail", "Israil", "Izz", "Jabbar", "Jabir", "Jafar", "Jalal", "Jalil", "Jaleel", "Jamal", "Jamal", "Jamil", "Jameel", "Jawad", "Jawhar", "Jibril", "Jihad", "Jubair", "Jumah", "Kadar", "Kedar", "Kadeen", "Kadin", "Kadeer", "Kadir", "Kaim", "Kahil", "Kaliq", "Kamal", "Kamil", "Kameel", "Kardal", "Karif", "Kareef", "Karim", "Kareem", "Kasib", "Kaseeb", "Kaseem", "Kasim", "Kateb", "Khaldun", "Khaldoon", "Khalid", "Khaled", "Khalil", "Khaleel", "Kalil", "Khatib", "Khair", "Khairy", "Khayri", "Khoury", "Khuzaymah", "Kutaiba", "Labib", "Labeeb", "Labid", "Lahab", "Latif", "Luqman", "Lutfi", "Mahdi", "Mahir", "Mahmud", "Mahmoud", "Maimun", "Majdy", "Majid", "Majid", "Majd", "Makin", "Malik", "Mamdouh", "Mamun", "Man", "Mansur", "Marid", "Marzuq", "Mashal", "Masruq", "Masud", "Maudad", "Mazin", "Mikail", "Misbah", "Mohammed", "Muadh", "Muawiyah", "Muayyad", "Mubarak", "Mufid", "Mufeed", "Muhammad", "Muhanned", "Muhsin", "Muhtadi", "Mujahid", "Mukhtar", "Mundhir", "Munir", "Muneer", "Muntasir", "Murtadi", "Murtadhy", "Musa", "Moosa", "Musad", "Muslim", "Mustafa", "Muta", "Mutasim", "Mutazz", "Muti", "Muwaffaq", "Nabhan", "Nabih", "Nabil", "Nabeel", "Nadhir", "Nadim", "Nadeem", "Nadir", "Naif", "Nail", "Naim", "Naji", "Najib", "Najeeb", "Najjar", "Najm", "Nasih", "Nasim", "Nasir", "Nasser", "Nasir", "Nawaf", "Nawfal", "Nazih", "Nazeeh", "Nazim", "Nazeem", "Nuh", "Nooh", "Numair", "Numan", "Nur", "Nuri", "Noori", "Omar", "Omran", "Othman", "Qadir", "Qaraja", "Qasim", "Qays", "Qudamah", "Qutaybah", "Qutaiba", "Qutuz", "Rabah", "Rabi", "Radi", "Rafi", "Rafiq", "Raghib", "Ragheb", "Rahman", "Raid", "Rais", "Rakin", "Rashad", "Rashid", "Ratib", "Rayhan", "Reda", "Rida", "Ridha", "Ridwan", "Riyad", "Riyadh", "Sabih", "Sabeeh", "Sabir", "Sabeer", "Saad", "Sadaqat", "Saeed", "Said", "Safiy", "Safwan", "Sahir", "Sajid", "Salah", "Salah", "Saleh", "Salih", "Salim", "Saleem", "Salman", "Sameh", "Sami", "Samir", "Sameer", "Samman", "Saqr", "Sariyah", "Saud", "Sayyar", "Sayyid", "Seif", "Sayf", "Seif", "Shadi", "Shafiq", "Shafeeq", "Shakir", "Sharif", "Shareef", "Shihab", "Siraj", "Sofian", "Subhi", "Suhail", "Suhayl", "Suhayb", "Sulaiman", "Sulayman", "Suud", "Suoud", "Tahir", "Talal", "Talib", "Tamir", "Tamam", "Tarif", "Tareef", "Tariq", "Tawfiq", "Taymullah", "Taysir", "Tayyib", "Thabit", "Thaqib", "Ubadah", "Ubaida", "Ubaydah", "Ubaid", "Ubayy", "Umar", "Umarah", "Umayr", "Umair", "Usama", "Usamah", "Utbah", "Uthman", "Wadi", "Wafid", "Wafiq", "Wafeeq", "Wahid", "Wail", "Wajih", "Wajeeh", "Wakil", "Waleed", "Walid", "Walliyullah", "Wasim", "Waseem", "Wazir", "Yahyah", "Yaman", "Yaqub", "Yasar", "Yasser", "Yasin", "Yaseen", "Yasir", "Yazid", "Yazeed", "Youssef", "Yusef", "Yusuf", "Yunus", "Yoonus", "Yushua", "Zafar", "Zafir", "Zahid", "Zahir", "Zaid", "Zayd", "Zaim", "Zakariyya", "Zaki", "Zakiy", "Ziyad", "Zubair", "Zuhair", "Zuhayr"};

    const int count = sizeof(Human_Names) / sizeof(Human_Names[0]);
    string name;

    int R = rand() % count;

    name = Human_Names[R];

    return name;
}

string take_random_Store_name()
{
    string Store_Names[] = {"Digital Zone", "Infinity Bazaar", "Ultra Nest", "Tech Center", "Cyber Point", "Ultra Zone", "Tech Outlet", "Infinity Store", "Infinity Hub", "Electro Mart", "Electro Center", "Tech Mart", "Tech Hub", "Infinity Bazaar", "Digital Center", "NextGen Mart", "Future Hub", "Tech Nest", "Gadget Point", "Digital Hub", "Digital Outlet", "Infinity Point", "Digital Center", "Gadget Store", "Cyber Outlet", "Smart Point", "Tech Bazaar", "Future Nest", "Smart Hub", "Ultra Bazaar", "Future Bazaar", "Infinity Nest", "Smart Point", "NextGen Bazaar", "Cyber Outlet", "Tech Point", "Gadget Mart", "Ultra Outlet", "Cyber Express", "NextGen Hub", "Tech Center", "Infinity Zone", "NextGen Bazaar", "Gadget Zone", "Ultra Store", "Digital Store", "NextGen Point", "Future Hub", "Smart Outlet", "Digital Outlet", "Cyber Mart", "Infinity Mart", "Ultra Express", "Future Mart", "Cyber Outlet", "Cyber Express", "NextGen Zone", "Gadget Nest", "Tech Center", "Cyber Point", "Tech Point", "Ultra Zone", "Cyber Mart", "Cyber Nest", "Future Mart", "Smart Hub", "Cyber Zone", "Electro Nest", "Future Point", "NextGen Zone", "Digital Store", "Electro Outlet", "Smart Bazaar", "Smart Point", "NextGen Mart", "Future Outlet", "Future Center", "Smart Point", "Ultra Hub", "Ultra Hub", "Future Express", "Tech Express", "Electro Point", "Electro Point", "NextGen Hub", "Electro Point", "Tech Nest", "Gadget Store", "Gadget Zone", "Tech Nest", "Future Bazaar", "Future Bazaar", "Tech Express", "Cyber Nest", "Smart Hub", "Gadget Center", "Digital Bazaar", "Cyber Store", "Electro Point", "Smart Outlet", "Ultra Point", "NextGen Outlet", "Cyber Bazaar", "Electro Nest", "Digital Outlet", "Cyber Express", "Electro Express", "Ultra Bazaar", "Smart Bazaar", "Cyber Center", "Future Point", "Future Center", "Smart Hub", "Future Express", "NextGen Point", "Smart Mart", "Digital Outlet", "Tech Bazaar", "Ultra Outlet", "Smart Express", "Tech Bazaar", "Ultra Mart", "Tech Bazaar", "Infinity Mart", "Smart Mart", "Future Nest", "Cyber Point", "Tech Point", "Electro Outlet", "Future Nest", "Cyber Point", "Infinity Express", "Digital Nest", "Digital Express", "Tech Hub", "Cyber Zone", "Digital Hub", "NextGen Point", "Electro Outlet", "NextGen Express", "NextGen Point", "Gadget Mart", "Electro Center", "Gadget Express", "Tech Zone", "Tech Express", "Electro Express", "Gadget Hub", "Gadget Nest", "NextGen Center", "Gadget Hub", "Digital Outlet", "Cyber Mart", "Smart Zone", "Smart Outlet", "Tech Point", "Digital Outlet", "Smart Bazaar", "Smart Mart", "Electro Center", "Tech Bazaar", "Electro Mart", "Electro Nest", "Smart Bazaar", "Cyber Express", "Smart Store", "Cyber Mart", "Digital Nest", "Future Outlet", "Infinity Mart", "Tech Point", "Tech Store", "Gadget Zone", "Smart Center", "Infinity Point", "Gadget Zone", "Future Outlet", "Digital Hub", "Infinity Bazaar", "Tech Center", "NextGen Hub", "Infinity Point", "Smart Nest", "Smart Nest", "Gadget Point", "Tech Store", "NextGen Outlet", "NextGen Zone", "NextGen Point", "Ultra Center", "Future Bazaar", "Electro Nest", "Electro Outlet", "Smart Outlet", "Tech Nest", "Electro Bazaar", "Infinity Point", "Cyber Point", "Smart Mart", "Digital Center", "Cyber Express", "Tech Zone", "Future Store", "Cyber Center", "Cyber Bazaar", "Electro Bazaar", "Gadget Mart", "Infinity Zone", "Smart Nest", "Smart Store", "Smart Store", "NextGen Outlet", "Electro Zone", "Infinity Bazaar", "Digital Nest", "NextGen Outlet", "Ultra Center", "Tech Nest", "Cyber Center", "Digital Center", "Infinity Bazaar", "NextGen Express", "Digital Outlet", "Tech Store", "Gadget Hub", "NextGen Express", "Infinity Bazaar", "Infinity Point", "Electro Bazaar", "Digital Bazaar", "Infinity Outlet", "Ultra Hub", "Gadget Mart", "Future Outlet", "Cyber Mart", "Cyber Nest", "Electro Center", "Ultra Store", "Gadget Mart", "Tech Nest", "Smart Zone", "Ultra Outlet", "Smart Nest", "Smart Outlet", "Digital Zone", "NextGen Outlet", "Future Outlet", "Gadget Express", "Future Outlet", "Electro Point", "NextGen Hub", "Cyber Nest", "Infinity Zone", "Infinity Nest", "Electro Nest", "Gadget Center", "Smart Store", "NextGen Store", "Digital Outlet", "Electro Store", "Infinity Bazaar", "Gadget Zone", "Tech Zone", "NextGen Bazaar", "NextGen Mart", "Cyber Store", "Tech Mart", "Infinity Center", "Electro Center", "Tech Zone", "Electro Nest", "NextGen Zone", "Smart Point", "NextGen Center", "NextGen Express", "Infinity Center", "Smart Express", "Electro Store", "Tech Express", "Digital Store", "Electro Point", "Cyber Outlet", "Future Nest", "Tech Nest", "NextGen Express", "Tech Nest", "Ultra Nest", "Electro Express", "Cyber Nest", "Electro Nest", "Future Outlet", "Future Center", "Smart Mart", "Gadget Hub", "Future Express", "Electro Zone", "Electro Hub", "Ultra Express", "Digital Store", "Future Hub", "Ultra Outlet", "Ultra Zone", "Digital Store", "Smart Hub", "Gadget Outlet", "NextGen Zone", "Gadget Center", "Gadget Point", "Future Zone", "Infinity Mart", "Infinity Center", "Smart Zone", "Ultra Mart", "Infinity Mart", "NextGen Bazaar", "Digital Hub", "NextGen Express", "Digital Center", "Smart Nest", "Cyber Bazaar", "Tech Outlet", "Gadget Center", "NextGen Bazaar", "Digital Point", "Future Point", "Gadget Zone", "Smart Store", "Smart Mart", "Future Outlet", "Ultra Store", "Future Zone", "Tech Zone", "Tech Mart", "Ultra Express", "Gadget Mart", "Digital Outlet", "NextGen Hub", "Infinity Express", "Future Hub", "Ultra Nest", "Cyber Center", "Ultra Outlet", "Smart Express", "Digital Outlet", "Digital Point", "Gadget Zone", "Cyber Point", "Digital Zone", "Electro Express", "Electro Point", "Ultra Center", "Infinity Express", "Cyber Outlet", "Future Nest", "Tech Outlet", "Tech Point", "Cyber Mart", "Cyber Zone", "Infinity Express", "Digital Point", "Tech Point", "Infinity Outlet", "Digital Store", "Tech Mart", "Ultra Outlet", "Future Point", "Infinity Mart", "Gadget Zone", "Infinity Point", "Gadget Point", "Gadget Mart", "Cyber Center", "Cyber Store", "Ultra Center", "Digital Bazaar", "Electro Express", "Ultra Nest", "Electro Hub", "Infinity Bazaar", "Infinity Center", "NextGen Hub", "Future Zone", "Ultra Express", "Smart Store", "Infinity Zone", "Tech Point", "Gadget Mart", "Ultra Bazaar", "Ultra Outlet", "Ultra Express", "Electro Nest", "Electro Store", "Electro Outlet", "Smart Nest", "Gadget Hub", "NextGen Express", "Future Zone", "Infinity Hub", "NextGen Express", "Digital Outlet", "Ultra Express", "Cyber Hub", "Smart Hub", "Electro Center", "Infinity Store", "Gadget Mart", "Smart Express", "NextGen Point", "Ultra Nest", "Electro Hub", "Future Hub", "NextGen Bazaar", "NextGen Express", "Cyber Point", "Infinity Outlet", "NextGen Outlet", "Electro Center", "Infinity Express", "Electro Nest", "Future Point", "Digital Zone", "Future Bazaar", "Tech Zone", "NextGen Express", "Cyber Store", "Gadget Mart", "Cyber Hub", "Tech Nest", "Gadget Hub", "Ultra Point", "Gadget Bazaar", "NextGen Express", "Future Express", "Electro Hub", "Infinity Nest", "Digital Center", "Infinity Center", "Smart Store", "Smart Express", "Digital Hub", "Electro Nest", "Ultra Store", "Infinity Mart", "Future Hub", "Smart Zone", "Electro Point", "Future Center", "Future Zone", "Tech Store", "Gadget Bazaar", "Smart Center", "Cyber Mart", "Cyber Store", "Electro Mart", "NextGen Zone", "Digital Point", "NextGen Mart", "Infinity Point", "Tech Hub", "Future Mart", "Tech Store", "NextGen Center", "Future Center", "Ultra Mart", "Digital Nest", "Ultra Center", "Ultra Nest", "Electro Point", "Tech Center", "Future Express", "Electro Express", "NextGen Outlet", "Tech Express", "NextGen Bazaar", "Cyber Center", "Future Express", "Electro Store", "Ultra Center", "NextGen Mart", "Future Center", "Tech Nest", "Digital Zone", "NextGen Store", "Tech Center", "Cyber Center", "Future Outlet", "Gadget Center", "Digital Outlet", "Electro Bazaar", "Tech Nest", "Digital Express", "Ultra Nest", "Electro Point", "Gadget Nest", "Smart Bazaar", "Ultra Nest", "Digital Zone", "Future Mart", "Ultra Point", "Ultra Nest"};

    int count = sizeof(Store_Names) / sizeof(Store_Names[0]);
    string name;

    int R = rand() % count;

    name = Store_Names[R];

    return name;
}

Products *Return_avaliable_Products()
{

    const int Id_start = 400000;

    string Product_Name[] = {"iPhone 15 Pro Max", "Samsung S24 Ultra", "MacBook Pro M3", "Sony 85 4K TV", "PlayStation 5", "NVIDIA RTX 4090", "Apple Vision Pro", "Dell XPS 17", "iPad Pro M2", "Samsung QLED 8K TV", "Microsoft Surface Laptop 6", "Bose Soundbar 900", "Home Theater System", "AirPods Max", "Canon EOS R5", "Nikon Z9", "Gaming PC Pro", "Xbox Series X", "Smart Refrigerator", "Jura Coffee Machine", "Samsung Ultrawide Monitor", "Alienware Gaming Laptop", "High-End Drone (DJI Inspire 3)", "Apple Studio Display", "Professional DJ Set", "Apple Mac Studio", "Samsung Fold 5", "High-End Gaming Chair", "Professional Espresso Machine", "Smart Oven", "Smart Washing Machine", "Sony 7.1 Surround Sound System", "Electric Scooter", "Dyson Cordless Vacuum", "Apple Watch Ultra 2", "Logitech Pro Racing Wheel", "Sony A7R V Camera", "8TB NVMe SSD", "GoPro Hero 12 Black", "Bose Wireless Earbuds", "BenQ 4K Projector", "Smart Home Security System", "Samsung Freestyle Projector", "DJI FPV Combo Drone", "Apple AirPods Pro 2", "LG OLED 77 TV", "Razer Blade 18 Gaming Laptop", "Sony WH-1000XM5 Headphones", "Apple Magic Keyboard & Mouse Set", "Insta360 X3 Camera"};
    double Product_Price[] = {540000, 500000, 750000, 900000, 190000, 580000, 850000, 670000, 320000, 1400000, 450000, 200000, 350000, 160000, 800000, 1050000, 950000, 170000, 850000, 1200000, 400000, 650000, 1500000, 600000, 1000000, 900000, 450000, 250000, 900000, 280000, 400000, 550000, 1300000, 180000, 250000, 300000, 950000, 320000, 180000, 140000, 500000, 400000, 180000, 650000, 120000, 1200000, 950000, 150000, 120000, 180000};

    const int count = sizeof(Product_Name) / sizeof(Product_Name[0]);
    Products *Ptr = new Products[count];

    for (int i = 0; i < count; i++)
    {
        Ptr[i].setData(to_string(Id_start + i + 1), Product_Name[i], Product_Price[i]);
        Products::All_Availible_Product_Count++;
    }

    return Ptr;
}