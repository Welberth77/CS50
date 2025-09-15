# Online Pizza Ordering System with Estimated Preparation Time

## 1. What (O quê?)

This project is a **web-based pizza ordering system** designed to provide a complete online experience for customers who want to order pizzas conveniently. Users can view an interactive menu with available pizzas, add items to a shopping cart, see the total price updated automatically, and get an estimate of the average preparation time based on the items selected.

The system focuses on providing a smooth and intuitive user experience. It was developed as the **final project for the CS50 course**, demonstrating the integration of front-end and back-end technologies, database management, and responsive design. Unlike traditional ordering methods that rely on phone calls or in-person visits, this system streamlines the process, reducing errors and saving time for both customers and pizzeria staff.

---

## 2. Why (Por quê?)

The main motivation behind this project is to address common problems faced by small pizzerias and their customers:

- **For Customers:**
  Ordering pizza using traditional methods can often lead to miscommunication, long waiting times, and uncertainty about prices or preparation times. This system allows customers to see the menu clearly, select exactly what they want, and know both the total price and the estimated preparation time before confirming their order.

- **For Learning and CS50 Final Project:**
  This project serves as a practical demonstration of skills acquired throughout the CS50 course. It covers:
  - **Front-end development:** HTML, CSS, and Bootstrap for creating a visually appealing and responsive user interface.
  - **Back-end development:** Python and Flask for handling server-side logic, routing, and interactions with the database.
  - **Database management:** SQLite is used to store menu items, prices, preparation times, and order details.
  - **Template rendering:** Jinja is used to dynamically generate HTML content based on the database and user actions.

By combining these technologies, the project demonstrates both **technical proficiency** and the ability to solve real-world problems with software.

---

## 3. Where (Onde?)

The application is **web-based**, which means it can be accessed using any modern web browser. Customers can use the system on:

- **Desktop computers:** Full experience with wide screens, easy navigation, and detailed menus.
- **Tablets and smartphones:** Responsive layout ensures functionality and readability on smaller screens.
- **Anywhere with internet access:** The system can be hosted locally or on a web server for remote access.

This accessibility ensures that customers can place orders conveniently from their home, office, or on the go.

---

## 4. When (Quando?)

- Developed during the **final phase of the CS50 course**, following the project submission timeline.
- The system can be further expanded in the future to support features such as online payments, multi-user sessions, or even real-time order tracking.
- It provides a foundation for real-world applications and can be adapted for deployment in small or medium-sized pizzerias.

---

## 5. Who (Quem?)

- **End Users (Customers):** People who want to order pizzas online efficiently and clearly.
- **Developer:** Responsible for designing, implementing, testing, and maintaining the system. This includes creating the database structure, Flask routes, HTML templates, and the responsive interface.

This project demonstrates the ability of a single developer to create a full-stack web application from scratch, covering all stages from planning to execution.

---

## 6. How (Como?)

### Technologies Used
- **HTML5:** Structuring web pages and displaying menu items, forms, and cart content.
- **CSS3:** Styling the pages to create a clean, user-friendly layout.
- **Bootstrap:** Ensuring responsive design across devices, providing grids, buttons, and pre-designed components.
- **Python and Flask:** Managing server-side logic, handling form submissions, and connecting to the database.
- **SQLite:** Storing menu items, prices, preparation times, and order data.
- **Jinja Templates:** Rendering dynamic HTML content based on the database and user interactions.

### Core Functionalities
1. **Interactive Menu:**
   - Dynamically loads pizzas from the database.
   - Displays each pizza with its name, description, price, and estimated preparation time.
   - Users can easily browse and select their preferred pizzas.

2. **Shopping Cart:**
   - Allows users to add multiple pizzas.
   - Automatically updates quantities, item totals, and overall price.
   - Users can remove items or change quantities before checkout.

3. **Total Price Calculation:**
   - Computes the sum of all selected items.
   - Displays the total price formatted to two decimal places.
   - Updates in real time as items are added or removed.

4. **Preparation Time Estimation:**
   - Calculates total preparation time by summing individual pizza times.
   - Converts the total time into hours and minutes for readability.
   - Helps customers understand how long their order will take.

5. **Checkout Form:**
   - Collects essential customer information: name, contact number, and address.
   - Provides a clear interface to finalize orders safely.
   - Validates input to avoid errors or incomplete orders.

6. **Responsive Design:**
   - Uses Bootstrap to adapt the layout to different screen sizes.
   - Ensures a smooth experience on desktops, tablets, and smartphones.
   - Improves accessibility and usability for all users.

---

## Challenges and Learning Outcomes

During development, several challenges were encountered:

- **Dynamic Data Handling:**
  Loading menu items and updating cart totals required careful database queries and logic in Flask.

- **User Interface:**
  Creating a responsive, intuitive design that works on multiple devices with Bootstrap.

- **Input Validation:**
  Ensuring that the checkout form collects complete and valid information.

- **Time Calculation Logic:**
  Converting total preparation minutes into hours and minutes to improve readability.

Through these challenges, I strengthened skills in **full-stack development, database management, Python programming, and problem-solving**.

---

## Future Improvements

- **Payment Integration:** Support for online payments using APIs like Stripe or PayPal.
- **Order Tracking:** Real-time updates on order status for customers.
- **Multi-user Support:** Allow multiple simultaneous orders with proper session management.
- **Enhanced UX:** Adding animations, images, and additional information for each pizza.

---

## Conclusion

This **Online Pizza Ordering System** demonstrates the complete workflow from browsing the menu to finalizing an order, including price calculation and preparation time estimation. It showcases technical skills in web development and practical application, providing a strong foundation for future projects or real-world deployment.

By completing this as the **CS50 final project**, it highlights both problem-solving ability and practical implementation skills, making it a comprehensive example of a full-stack web application.
