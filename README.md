<h1 align="center">📚 C++ Library Management System</h1>

<p align="center">
A robust, console-based <b>Library Management System</b> built from scratch using <b>C++</b>.  
This project demonstrates the implementation of <b>Linked Lists</b> for dynamic memory management and <b>File Handling</b> for data persistence.
</p>

<hr>
<h2>📌 Table of Contents</h2>
<ul>
  <li><a href="#-overview">📖 Overview</a></li>
  <li><a href="#-key-features">✨ Key Features</a></li>
  <li><a href="#-tech-stack">🛠 Tech Stack</a></li>
  <li><a href="#-login-credentials">🔑 Login Credentials</a></li>
  <li><a href="#-how-to-run">🚀 How to Run</a></li>
  <li><a href="#-future-roadmap-to-do">🧭 Future Roadmap (To-Do)</a></li>
  <li><a href="#-contributing">🤝 Contributing</a></li>
  <li><a href="#-contribution-guidelines">📜 Contribution Guidelines</a></li>
  <li><a href="#-license">📜 License</a></li>
</ul>

<hr>


<h2>📖 Overview</h2>
<p>
This application allows library administrators to manage books, students, and issue records efficiently.
Unlike simple array-based projects, this system uses custom <b>Linked List classes</b> to handle data,
ensuring efficient insertion and deletion operations.
</p>

<p>
It also simulates real-world date handling to calculate fines for overdue books.
</p>

<hr>

<h2>✨ Key Features</h2>
<ul>
  <li><b>🔐 Admin Authentication:</b> Secure login system to prevent unauthorized access.</li>
  <li><b>📚 Book Management:</b> Add, delete, search, and sort books by ID.</li>
  <li><b>👨‍🎓 Student Management:</b> Register and manage student details.</li>
  <li><b>📆 Issue & Return Logic:</b>
    <ul>
      <li>Tracks issue dates and calculates due dates (14 days).</li>
      <li><b>💰 Fine Calculation:</b> Automatically calculates fines (₹5 per day) for late returns.</li>
    </ul>
  </li>
  <li><b>💾 Data Persistence:</b> All data is saved to text files and reloaded on startup:
    <ul>
      <li><code>books.txt</code></li>
      <li><code>students.txt</code></li>
      <li><code>issues.txt</code></li>
    </ul>
  </li>
  <li><b>📦 Inventory Control:</b> Prevents issuing books that are already unavailable.</li>
</ul>

<hr>

<h2>🛠 Tech Stack</h2>
<ul>
  <li><b>Language:</b> C++</li>
  <li><b>Data Structures:</b> Singly Linked Lists (custom implementation)</li>
  <li><b>Storage:</b> File I/O (Text files)</li>
  <li><b>Time Management:</b> <code>&lt;ctime&gt;</code> for date arithmetic</li>
</ul>

<hr>

<h2>🔑 Login Credentials</h2>
<p>
Use the following default admin credentials:
</p>

<ul>
  <li><b>Username:</b> <code>admin</code></li>
  <li><b>Password:</b> <code>admin123</code></li>
</ul>

<blockquote>
<b>Note:</b> You can modify the <code>login()</code> function in the source code to change these credentials.
</blockquote>

<hr>

<h2>🚀 How to Run</h2>

<h3>1️⃣ Clone the Repository</h3>
<pre><code>git clone https://github.com/your-username/library-management-system.git</code></pre>

<h3>2️⃣ Compile the Code</h3>
<pre><code>g++ main.cpp -o library_app</code></pre>

<h3>3️⃣ Run the Application</h3>
<ul>
  <li><b>Windows:</b> <code>library_app.exe</code></li>
  <li><b>Linux / macOS:</b> <code>./library_app</code></li>
</ul>

<hr>

<h2>🧭 Future Roadmap (To-Do)</h2>
<ul>
  <li>☐ GUI Integration (Qt / wxWidgets)</li>
  <li>☐ Database Support (SQLite / MySQL)</li>
  <li>☐ Student User Accounts</li>
  <li>☐ Code Refactoring (Split into <code>.h</code> and <code>.cpp</code> files)</li>
</ul>

<hr>

<h2>🤝 Contributing</h2>
<p>
Contributions are welcome! This is an open-source project built for learning and improvement.
</p>

<b>How you can help:</b>
<ol>
  <li>Fork this repository</li>
  <li>Debug edge cases</li>
  <li>Optimize algorithms or memory usage</li>
  <li>Create a Pull Request with your improvements</li>
</ol>

<p>
If you find a bug, please open an issue.
</p>

<hr>

<hr>

<h2>🤝 Contribution Guidelines</h2>

<p>
Contributions are welcome and appreciated! This project is intended as a <b>learning-focused</b> and
<b>logic-driven</b> system. To maintain code quality and architectural clarity, contributors must follow
the rules below.
</p>

<h3>✅ Allowed Contributions</h3>
<ul>
  <li>🐞 Fix logical bugs or edge cases</li>
  <li>⚡ Optimize algorithms or memory management</li>
  <li>📂 Refactor code into proper <code>.h</code> and <code>.cpp</code> files (without changing logic)</li>
  <li>🧪 Add test cases or validation checks</li>
  <li>📖 Improve documentation and README</li>
  <li>🎨 Build a <b>GUI layer</b> on top of the existing system (see rules below)</li>
</ul>

<hr>

<h3>🚫 Restricted Changes (Important)</h3>
<ul>
  <li>❌ Do <b>NOT</b> modify <code>main.cpp</code></li>
  <li>❌ Do <b>NOT</b> alter the core business logic (Book, Student, Issue handling)</li>
  <li>❌ Do <b>NOT</b> change file formats (<code>.txt</code> storage structure)</li>
</ul>

<blockquote>
<b>Reason:</b> The core logic is intentionally kept stable to preserve learning outcomes
related to data structures and system design.
</blockquote>

<hr>

<h3>🖥 GUI Development Rules (Mandatory)</h3>

<p>
Contributors who wish to convert this project into a <b>GUI-based application</b> must follow these rules:
</p>

<ul>
  <li>✔ The GUI must act as a <b>presentation layer only</b></li>
  <li>✔ Core logic must remain untouched</li>
  <li>✔ GUI should interact with the system via:
    <ul>
      <li>Wrapper classes</li>
      <li>Controller modules</li>
      <li>Function calls without logic modification</li>
    </ul>
  </li>
  <li>✔ Preferred GUI frameworks:
    <ul>
      <li>Qt (C++)</li>
      <li>wxWidgets</li>
      <li>Console-to-GUI adapters</li>
    </ul>
  </li>
</ul>

<blockquote>
<b>Example:</b>  
You may create a <code>gui.cpp</code> or <code>ui/</code> directory that calls existing functions,
but <b>must not rewrite or duplicate logic</b>.
</blockquote>

<hr>

<h3>📌 Pull Request Rules</h3>
<ol>
  <li>Fork the repository</li>
  <li>Create a feature branch</li>
  <li>Follow all contribution rules</li>
  <li>Submit a Pull Request with:
    <ul>
      <li>Clear description of changes</li>
      <li>Confirmation that core logic is unchanged</li>
    </ul>
  </li>
</ol>

<p>
Pull requests that violate these rules will be <b>closed without merge</b>.
</p>


<h2>📜 License</h2>
<p>
This project is open-source and free to use and modify for learning purposes.
</p>

<p align="center">
⭐ If you find this project useful, consider giving it a star!
</p>
