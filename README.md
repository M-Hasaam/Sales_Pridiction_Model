# 📊 Sales Prediction & Store Clustering System

A powerful **C++ Console Application** that predicts future sales using moving averages, clusters shops using **K-Means Clustering**, and visualizes results using intuitive **2D ASCII graphs**.  
Designed to assist businesses in analyzing store performance, regional trends, and key revenue/profit insights.

---

## 🚀 Key Features

### 🔮 Sales Prediction
- Predicts **next month's sales** using the **Moving Average** method.
- Helps monitor sales trends over time for each store.

### 📍 Store Clustering with K-Means
- Clusters **100 stores** based on their **location**.
- Divides each main cluster into **sub-clusters** using:
  - 📈 **Revenue**
  - 💰 **Profit**

### 📈 Graphical Visualization
- Displays **2D graphs in the console** using ASCII characters.
- Includes:
  - Cluster-wise store performance
  - Revenue & profit distribution
  - Sales trend graphs

### 📑 Smart Reporting & Sorting
Users can sort and view reports based on:
- ⭐ Overall Score of Stores  
- 💰 Profit of Stores  
- 📈 Growth Rate of Stores  
- 💵 Revenue of Stores

All views are shown in an **interactive graph format** for better understanding.

---

## 📂 Data Structure

- Handles over **100,000+ records** stored in simple `.txt` files.
- Efficient file-based access with **optimized processing**.
- Currently supports **100 unique stores**.

---

## 🛠️ Built With

- **C++** — Core application logic and performance
- **K-Means Clustering** — For shop grouping
- **Moving Average** — Sales forecasting
- **Custom 2D Graph Renderer** — ASCII visualization in terminal

---

## 📌 Ideal Use Cases

- 🔮 Forecasting retail chain sales  
- 📊 Benchmarking store performance  
- 📍 Location-based clustering and analysis  
- 📈 Growth and revenue insights  

---

## 📷 Sample Console Output

---

### 🧭 Main Menu
```

 ===> Main Menu :-
 1) Want to See Stores.
 2) Want To See Sales.
 3) Want To See Products.
 4) Want To See Clusters.
 5) Want To See Reports.
 6) Want To See Next Month Prediction.
 7) Want To Change Data.
 8) Exit.
 -Enter Option : 1

````

---

### 🗂 Cluster Data
```

==========================================================================================================================================================

   ====> Cluster:-
       --> ID : 101500 | Name : Geogaphic Cluster 1015 |
       --> Center (-63.82,-168.085)
       --> Stores :-
           - | ID: 300016 | Location (-56.94 ,-163.14) |
           - | ID: 300092 | Location ( -70.7 ,-173.03) |
----------------------------------------------------------------------------------------------------------------------
       --> SubCluster:-
           -> ID : 101501 | Name : Top-Stores |
           -> Center (3.26101e+09,2.91277e+08)
           -> Stores :-
               - | ID: 300016 | Location (-56.94 ,-163.14) | Revenue : 3.26101e+09 | Profit :  2.91277e+08 |
----------------------------------------------------------------------------------------------------------------------
       --> SubCluster:-
           -> ID : 101502 | Name : Average-Stores |
           -> Center (2.6503e+08,1.34542e+08)
           -> Stores :-
                - ! Empty !
----------------------------------------------------------------------------------------------------------------------
       --> SubCluster:-
           -> ID : 101503 | Name : Struggling-Stores |
           -> Center (2.6503e+08,-2.2193e+07)
           -> Stores :-
               - | ID: 300092 | Location ( -70.7 ,-173.03) | Revenue :  2.6503e+08 | Profit :  -2.2193e+07 |

==========================================================================================================================================================

````
---

### 📊 Cluster Graph
```
     -180-170-160-150-140-130-120-110-100 -90 -80 -70 -60 -50 -40 -30 -20 -10   0  10  20  30  40  50  60  70  80  90 100 110 120 130 140 150 160 170 180
     +--------------------------------------------------------------------------------------------------------------------------------------------------+
 -90 |                                                                                                                                                  |
     |                                        .           .         .                                       .                                           |
 -80 |                                                        .                       .                                                                 |
     |                        .                     O   .     .                   O                                               .                     |
 -70 |  .                                                       .                   . .                                                                 |
     |                              .                                                                                                                   |
 -60 |                                        .                                                                                                         |
     |      .                                           .                                                       .                                       |
 -50 |                                          .               .   .                     .                                                             |
     |                                              .           .                                                                                       |
 -40 |                          .                       O                                                                                               |
     |                                                                                            .                   O                                 |
 -30 |                      .             .                                                       .     .           .                                   |
     |        .                                                                                                                                         |
 -20 |              .                             .         .                                   O                   .                                   |
     |            . O                                                           .                                                                       |
 -10 |                                                                                              .                                                   |
     |                                                                                                                .               .                 |
   0 |                .       .                                               .                     . .               .                                 |
     |                                                        .               .                                                                         |
  10 |                .         .                                                 .                           .                                         |
     |        .                                                                                                                                         |
  20 |                                                                            . .         .                                                         |
     |  .                               .         .                 O                                 .         .           .                           |
  30 |  .                           .     .                                 .       .       .                   .   .                                   |
     |                                                                    .                                                                             |
  40 |              .                                       .                               .                         .   .                             |
     |      .             .                 .         .                                                               0.                                |
  50 |                      O                                                         .     O                                                           |
     |      .                                   .       .                                                                                               |
  60 |                                                                                                                                                  |
     |                                                                                              .                           .                       |
  70 |                                                                                                .                                                 |
     |  .               .                                                   .                                           .                               |
  80 |                                                                                                  .                                               |
     |                                              .       .                         .                                       .                         |
  90 |                                                                                                                                                  |
     +--------------------------------------------------------------------------------------------------------------------------------------------------+

````

---

### 📈 Report View


```
 ==> Top 10 stores with respect to Profit :-
     - | ID : 300010 | Profit : 3.06283e+008 |========================================= |
     - | ID : 300014 | Profit : 3.04674e+008 |========================================  |
     - | ID : 300018 | Profit : 3.01503e+008 |========================================  |
     - | ID : 300007 | Profit : 3.00218e+008 |========================================  |
     - | ID : 300001 | Profit : 2.97814e+008 |=======================================   |
     - | ID : 300005 | Profit : 2.95295e+008 |=======================================   |
     - | ID : 300009 | Profit : 2.95113e+008 |=======================================   |
     - | ID : 300003 | Profit : 2.93573e+008 |=======================================   |
     - | ID : 300015 | Profit : 2.92508e+008 |=======================================   |
     - | ID : 300004 | Profit : 2.9139e+008  |=======================================   |
 ==> Bottom 5 stores with respect to Profit :-
     - | ID : 300090 | Profit : -2.2719e+007 |                                        ==|
     - | ID : 300097 | Profit : -2.3147e+007 |                                       ===|
     - | ID : 300083 | Profit : -2.7202e+007 |                                       ===|
     - | ID : 300100 | Profit : -2.7639e+007 |                                       ===|
     - | ID : 300089 | Profit : -3.0619e+007 |                                       ===|
Press any key to continue . . .

````

---

### 📅 Monthly Prediction


```
==========================================================================================================================================================

 ========== Sales Forecast ==========
 Store:- | Name : NextGen Bazaar   | ID : 300001 |


180955000  -|
171907000  -|
162860000  -|            *
153812000  -|  *         *                                       *                                  *
144764000  -|  *    *    *         *                   *    *    *         *              *         *
135716000  -|  *    *    *         *    *    *         *    *    *         *    *    *    *         *    *              *         *
126668000  -|  *    *    *         *    *    *    *    *    *    *    *    *    *    *    *    *    *    *              *         *    x
117621000  -|  *    *    *         *    *    *    *    *    *    *    *    *    *    *    *    *    *    *         *    *         *    x
108573000  -|  *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *         *    *         *    x
99525000   -|  *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    x
90477000   -|  *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    x
81430000   -|  *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    x
72382000   -|  *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    x
63334000   -|  *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    x
54286000   -|  *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    x
45238000   -|  *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    x
36191000   -|  *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    x
27143000   -|  *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    x
18095000   -|  *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    x
9047000    -|  *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    x
============|=============================================================================================================================
Months      | 1    2    3    4    5    6    7    8    9    10   11   12   13   14   15   16   17   18   19   20   21   22   23   24  |next|


 Increasing Trend : 38.0952 %
 Decreasing Trend : 57.1429 %
 Predicted Sales for Next Month : 1.27351e+008
 Confidence Level : 40 %


==========================================================================================================================================================
````

---

## 📁 Project Files

- `main.cpp` — Complete C++ source code  
- `salesdata.txt` — Sales data (~100,000 entries)  
- `README.md` — Project documentation  

---

## ✅ Getting Started

### 1. Clone the Repository
```bash
git clone https://github.com/M-Hasaam/Sales_Pridiction_Model.git
````

### 2. Compile the Code

```bash
g++ main.cpp -o sales_predictor
```

### 3. Run the Application

```bash
./sales_predictor
```

---

## 🌟 Future Enhancements

* 🖼️ GUI-based Interface
* 📤 Export graphs as CSV or image
* 🤖 Use Machine Learning for better predictions
* 🔄 Dynamic store data import from Excel/CSV

---

## 📬 Contact

📧 For queries or collaboration:
**Muhammad Hasaam** — \[[m.hasaam.official@gmail.com](mailto:m.hasaam.official@gmail.com)]

---

> 🧠 *“Good data brings smart decisions.”*

