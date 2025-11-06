import matplotlib.pyplot as plt
import numpy as np
import re
import math
expression=input("Enter the expression: ")
def prepare(expr):
    expr = re.sub(r'\bsinh', 'sinh', expr)
    expr = re.sub(r'\bcosh', 'cosh', expr)
    expr = re.sub(r'\btanh', 'tanh', expr)
    expr = re.sub(r'\basinh', 'asinh', expr)
    expr = re.sub(r'\bacosh', 'acosh', expr)
    expr = re.sub(r'\batanh', 'atanh', expr)
    expr = re.sub(r'\barcsin', 'arcsin', expr)
    expr = re.sub(r'\barccos', 'arccos', expr)
    expr = re.sub(r'\barctan', 'arctan', expr)
    expr = re.sub(r'\bsin', 'sin', expr)
    expr = re.sub(r'\bcos', 'cos', expr)
    expr = re.sub(r'\btan', 'tan', expr)
    expr = re.sub(r'\bexp', 'exp', expr)
    expr = re.sub(r'\bln', 'log', expr)
    expr = re.sub(r'\bsqrt', 'sqrt', expr)
    expr = re.sub(r'\bpi', 'pi', expr)
    expr = re.sub(r'\be', 'e', expr)
    expr = re.sub(r'\,', '.', expr)
    return expr

evalcontext={
    "pi": np.pi, 
    "e": np.e,
    "sin": np.sin,
    "cos": np.cos,
    "tan": np.tan,
    "sinh": np.sinh, 
    "cosh": np.cosh, 
    "tanh": np.tanh,
    "arcsin": np.arcsin, 
    "arccos": np.arccos, 
    "arctan": np.arctan,
    "asinh": np.asinh, 
    "acosh": np.acosh, 
    "atanh": np.atanh,
    "exp": np.exp,
    "log": np.log,
    "sqrt": np.sqrt
}

try:
    a = float(input("Enter a: "))
    b = float(input("Enter b: "))
    x = np.linspace(a,b,500)
    expression = prepare(expression)
    evalcontext["x"] = x 
    y = eval(expression,evalcontext)
    y[y>100] = np.nan
    y[y<-100] = np.nan
    y[np.isinf(y)] = np.nan
    plt.figure()
    plt.plot(x,y,c = "r",linewidth = 1.5,label = "f(x)")
    plt.xlabel("X")
    plt.ylabel("Y")
    plt.title("The graph of f(x)")
    plt.legend()
    plt.xlim(a,b)
    plt.grid()
    plt.axhline(0,color = 'blue',linewidth = 1.5)
    plt.axvline(0,color = 'blue',linewidth = 1.5)
    plt.show()
except Exception as e:
    print("Error in expression: ", e)