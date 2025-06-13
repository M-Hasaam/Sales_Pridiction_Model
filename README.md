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

