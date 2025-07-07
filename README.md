# 🎬 Movie Recommendation System (C++)

This is a simple **C++ console application** that recommends a movie based on user preferences. It compares the user's choices in genre, decade, and story structure with a predefined list of films and suggests the best match.

---

## 📌 Features

- Accepts user input for three preference categories:
  - **Genre** (e.g., Drama, Comedy, Sci-Fi)
  - **Decade** (e.g., 70's, 90's, 00's)
  - **Story Structure** (e.g., Twist-Driven, Flashback Based)
- Matches the input with the most relevant movie from a hardcoded list.
- Displays a recommendation or prompts the user to try again if no match is found.
- Uses dynamic memory allocation and properly deletes allocated objects to prevent memory leaks.

---

## 🛠 Technologies Used

- C++ Standard Library (`iostream`, `vector`, `string`)
- Object-Oriented Programming (OOP)
- Exception handling (`try` / `catch`)
- Command-line interface (CLI)

---

## ▶️ How to Run

1. **Compile the program:**
   ```bash
   g++ -o movie_recommender main.cpp
