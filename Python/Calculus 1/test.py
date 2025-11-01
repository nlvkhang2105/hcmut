import math
import re
def prepare(expr):
    expr = expr.replace('arcsin', 'math.asin', 1)
    expr = expr.replace('arccos', 'math.acos', 1)
    expr = expr.replace('arctan', 'math.atan', 1)
    expr = expr.replace('sinh', 'math.sinh', 0)
    expr = expr.replace('cosh', 'math.cosh', 0)
    expr = expr.replace('tanh', 'math.tanh', 0)
    expr = expr.replace('sin', 'math.sin', 0)
    expr = expr.replace('cos', 'math.cos', 0)
    expr = expr.replace('tan', 'math.tan', 0)
    expr = expr.replace('ln', 'math.log')
    expr = expr.replace('exp', 'math.exp')
    expr = expr.replace('sqrt', 'math.sqrt')
    expr = expr.replace('pi', 'math.pi')
    expr = expr.replace('e', 'math.e')
    return expr

expression = input("Input your expression: ")

try:
    expression = prepare(expression)
    result = eval(expression)
    print("OUTPUT: ", result)
except Exception as e:
    print("Error in expression: ", e)