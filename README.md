# -digital-marketing-tool
# 📊 Digital Marketing Funnel Tree (CRUD) – C Project

## 📌 Project Overview

This project implements a **Digital Marketing Funnel** using a **Tree Data Structure in C**. It supports **CRUD operations (Create, Read, Update, Delete)** to manage marketing stages like Awareness, Interest, Consideration, and Conversion.

---

## 🎯 Objective

* Learn tree data structures
* Implement CRUD operations
* Simulate a real-world marketing funnel

---

## 🌳 Funnel Structure Example

```
Marketing Funnel
├── Awareness
│   ├── SocialMedia
│   │   └── Instagram
│   └── Ads
├── Interest
└── Conversion
```

---

## ⚙️ Features

* Add new stages
* Display funnel
* Update stage names
* Delete stages
* Search nodes

---

## 🛠️ Technologies Used

* C Programming
* Tree Data Structure
* Dynamic Memory Allocation

---

## ▶️ How to Run

### Compile

```
gcc marketing_funnel.c -o funnel
```

### Run

```
./funnel
```

---

# 📸 Sample Input & Output (Screenshots)

## 🖥️ Screenshot 1: Program Start

```
--- Marketing Funnel Menu ---
1. Add Stage
2. Display Funnel
3. Update Stage
4. Delete Stage
5. Exit
Enter choice: 1
Enter parent stage: Marketing Funnel
Enter new stage name: Awareness
```

---

## 🖥️ Screenshot 2: Adding More Stages

```
Enter choice: 1
Enter parent stage: Awareness
Enter new stage name: SocialMedia

Enter choice: 1
Enter parent stage: SocialMedia
Enter new stage name: Instagram
```

---

## 🖥️ Screenshot 3: Display Funnel (OUTPUT)

```
Marketing Funnel Structure:
- Marketing Funnel
  - Awareness
    - SocialMedia
      - Instagram
```

---

## 🖥️ Screenshot 4: Update Stage

```
Enter choice: 3
Enter old name: Instagram
Enter new name: InstagramAds
Updated successfully!
```

---

## 🖥️ Screenshot 5: Delete Stage

```
Enter choice: 4
Enter parent name: SocialMedia
Enter node to delete: InstagramAds
Deleted successfully!
```

---

## 🖥️ Screenshot 6: Final Output

```
Marketing Funnel Structure:
- Marketing Funnel
  - Awareness
    - SocialMedia
```

---

## 📂 File Structure

```
project/
│── marketing_funnel.c
│── README.md
```

---

## 💡 Future Enhancements

* Add budget tracking
* Add conversion rates
* Save data using file handling
* Add analytics (node count, depth)

---

## 📚 Learning Outcomes

* Tree traversal and recursion
* CRUD operations in C
* Real-world data modeling

---

## 👨‍🎓 Author

* Name: Your Name
* Course: Data Structures

---

## 📜 License

For educational purposes only.


