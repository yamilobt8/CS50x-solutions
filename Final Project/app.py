from flask import Flask, redirect, render_template, request, session, flash, redirect, url_for
from werkzeug.security import generate_password_hash, check_password_hash
import sqlite3

app = Flask(__name__)
app.secret_key = 'yamilo'

def connect_db():
    conn = sqlite3.connect('project.db')
    conn.row_factory = sqlite3.Row
    return conn

def apology(message, code=400):
    """Render message as an apology to user."""
    def escape(s):
        """
        Escape special characters.

        https://github.com/jacebrowning/memegen#special-characters
        """
        for old, new in [("-", "--"), (" ", "-"), ("_", "__"), ("?", "~q"),
                         ("%", "~p"), ("#", "~h"), ("/", "~s"), ("\"", "''")]:
            s = s.replace(old, new)
        return s
    return render_template("apology.html", top=code, bottom=escape(message)), code

@app.route("/")
def home():
    return render_template("home.html")

@app.route("/portfolio")
def portfolio():
    return render_template("portfolio.html")

@app.route("/CyberSecurity")
def road():
    return render_template("cybersecurity.html")

@app.route("/mobiledev")
def dev():
    return render_template("mobiledev.html")

@app.route("/ai")
def ai():
    return render_template("ai.html")

@app.route("/tools")
def tool():
    return render_template("tools.html")

@app.route("/gamedev")
def game():
    return render_template("gamedev.html")

@app.route("/datasience")
def data():
    return render_template("data.html")

@app.route("/robot")
def robot():
    return render_template("robot.html")

@app.route('/register', methods=['GET', 'POST'])
def register():
    if request.method == 'POST':
        username = request.form['username']
        password = request.form['password']
        confirm_password = request.form['confirm_password']
        if "'" in username or "'" in password:
            return apology("Don't try to use SQL injection here", 'stupid')
        if not username or not password or not confirm_password:
            return apology('All fields are required', 'Something Went Wrong')
        elif password != confirm_password:
            return apology('Passwords do not match', 'Something Went Wrong')
        else:
            # Hash the password before storing it
            hashed_password = generate_password_hash(password, method='sha256')

            conn = connect_db()
            cursor = conn.cursor()
            cursor.execute('INSERT INTO user (username, password) VALUES (?, ?)', (username, hashed_password))
            conn.commit()
            conn.close()
            flash('Registration successful', 'success')
            return redirect(url_for('login'))

    return render_template('register.html')  # Create an HTML template for the registration form

# Route for user login
@app.route('/login', methods=['GET', 'POST'])
def login():
    if request.method == 'POST':
        username = request.form['username']
        password = request.form['password']

        if "'" in username or "'" in password:
            return apology("Don't try to use SQL injection here", 'stupid')

        conn = connect_db()
        cursor = conn.cursor()
        cursor.execute('SELECT * FROM user WHERE username = ?', (username,))
        user = cursor.fetchone()
        conn.close()

        if user and check_password_hash(user['password'], password):  # Compare hashed passwords
            flash('Login successful', 'success')
            return redirect(url_for('home'))  # Redirect to the home page
        else:
            return apology('Invalid username or password', 'Something Went Wrong')

    return render_template("login.html")  # Create an HTML template for the login form
