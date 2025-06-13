# Sales_Pridiction_Model
📊 Store Sales Prediction & Clustering System
A powerful C++ Console-Based Application for predicting sales, clustering stores, and visualizing insights with intuitive 2D ASCII graphs.
This tool helps businesses analyze performance metrics and make data-driven decisions based on past sales data.

🚀 Features
🔮 Sales Prediction
Implements Moving Average technique to forecast next month's sales for each store.

📍 Shop Clustering with K-Means
Groups 100 stores based on location into major clusters.

Further divides clusters into sub-clusters based on Profit and Revenue.

📈 Data Visualization
Displays 2D ASCII graphs directly in the console:

Cluster-wise performance

Sales trends

Growth and revenue metrics

📑 Sorting and Reports
Provides detailed reports and rankings based on:

ruby
Copy
Edit
=> Select :-
 1) Overall Score of Stores.
 2) Profit of Stores.
 3) Growth Rate of Stores.
 4) Revenue of Stores.
📂 Data Structure
Handles over 100,000 records stored in plain .txt files.

Optimized data processing for quick results.

🛠️ Built With
C++ — Core logic, clustering, sorting, graphing.

K-Means Clustering Algorithm — For grouping stores.

Moving Average — For forecasting sales.

Custom Graph Renderer — 2D visual display in the terminal.

📌 Use Cases
Sales forecasting for retail chains

Store performance benchmarking

Profit/revenue-based segmentation

Regional business analysis

📷 Console Preview
plaintext
Copy
Edit
+-----------------------------+
|  Cluster A (High Revenue)  |
+-----------------------------+
| Store 1 | ███████          |
| Store 2 | ██████████       |
| Store 3 | █████████████    |
+-----------------------------+
📁 Project Files
main.cpp — Complete application logic

salesdata.txt — Store sales data (~100,000 records)

README.md — Project documentation

✅ How to Run
Clone the repository:

bash
Copy
Edit
git clone https://github.com/yourusername/sales-clustering-cpp.git
Compile the code:

bash
Copy
Edit
g++ main.cpp -o sales_predictor
Run the program:

bash
Copy
Edit
./sales_predictor
🌟 Future Improvements
GUI-based interface

Export graph as image or CSV

Machine learning-based prediction

Dynamic store data import

📬 Contact
📧 For queries, suggestions or contributions:
M.Hasaam Bin Asif Imran — [your-email@example.com]

🧠 “Good data, better decisions.”
