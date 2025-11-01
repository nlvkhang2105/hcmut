import math
import re
def prepare(expr):
    expr = expr.replace('ln', 'math.log')
    expr = expr.replace('exp', 'math.exp')
    expr = expr.replace('arcsin', 'math.asin')
    expr = expr.replace('arccos', 'math.acos')
    expr = expr.replace('arctan', 'math.atan')
    expr = expr.replace('sinh', 'math.sinh')
    expr = expr.replace('cosh', 'math.cosh')
    expr = expr.replace('tanh', 'math.tanh')
    expr = expr.replace('sin', 'math.sin')
    expr = expr.replace('cos', 'math.cos')
    expr = expr.replace('tan', 'math.tan')
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