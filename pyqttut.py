from PyQt5 import QtWidgets
from PyQt5.QtWidgets import QApplication, QMainWindow
import sys
from testf import Ui_MainWindow
from sudoku1 import SodukuSolver
class myWindow(Ui_MainWindow):
    def __init__(self,bo):
        self.bo = bo
        app = QtWidgets.QApplication(sys.argv)
        self.MainWindow = QtWidgets.QMainWindow()
        self.ui = Ui_MainWindow()
        self.ui.setupUi(self.MainWindow,self.bo)
        self.MainWindow.show()
        sys.exit(app.exec_())
        #super(myWindow,self).__init__()
        #self.setGeometry(200,200,300,300)
        #self.setWindowTitle('deva GUI')
        #self.initUI()
        #win.setGeometry(xpos,ypos,width,height)

    def initUI(self):
        self.label = QtWidgets.QLabel(self)
        self.label.setText('deva')
        self.label.move(50,50)
        self.b1 = QtWidgets.QPushButton(self)
        self.b1.setText('PRESS')
        self.b1.move(50,100)
        self.b1.clicked.connect(self.clicked)

    def clicked(self):
        self.label.setText('you pressed the button ! ')
        self.update()

    def update(self):
        self.label.adjustSize()








def clicked():
    print("clicked")


def window():
    app = QApplication(sys.argv)
    win = myWindow()
    win.show()
    sys.exit(app.exec_())

board = [
    [7,8,0,4,0,0,1,2,0],
    [6,0,0,0,7,5,0,0,9],
    [0,0,0,6,0,1,0,7,8],
    [0,0,7,0,4,0,2,6,0],
    [0,0,1,0,5,0,9,3,0],
    [9,0,4,0,6,0,0,0,5],
    [0,7,0,3,0,0,0,1,2],
    [1,2,0,0,0,7,4,0,0],
    [0,4,9,2,0,6,0,0,7]]

m = myWindow(board)
