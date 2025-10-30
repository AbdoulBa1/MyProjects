Constellation Viewer (cmu-graphics)

This is a simple interactive Python program that draws a moving constellation on a dynamic, starry background using the cmu-graphics library.

About CMU Graphics

CMU Graphics is a persistent-object graphics package geared towards beginner computer science students. 
To write animations using CMU Graphics, you start with the line from cmu_graphics import * and end the file with cmu_graphics.run(). You can find more details about how to use the graphics framework here on their documentation page.

Prerequisites

To run this project, you need the following installed on your system:

Python 3.x

Visual Studio Code (VS Code) (with Jupyter support if you are using .ipynb files)

Setup and Installation

This project requires the third-party graphics library cmu-graphics.

Step 1: Install the Library

Open your terminal or VS Code integrated terminal (Terminal > New Terminal) and run the following command to install the required package:

pip install cmu-graphics


(If the command fails, try pip3 install cmu-graphics.)

Step 2: Prepare Your File (main.ipynb)

Since your file is a Jupyter Notebook (main.ipynb), you should paste all the Python code into a single code cell within that notebook.

Ensure the code is pasted entirely, from from cmu_graphics import * down to cmu_graphics.run().

from cmu_graphics import *
# ... (rest of the constellation code)
cmu_graphics.run()


Step 3: Run the Program in VS Code

To run the program in your Jupyter Notebook (main.ipynb), you need to execute the code cell:

Open your main.ipynb file in VS Code.

Navigate to the code cell containing your program.

Click the Run Cell button (a small play triangle  to the left of the cell's In [ ]: text).

A new window should pop up displaying the constellation and playing the background music!
### Have fun!
