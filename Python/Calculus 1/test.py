import math
import re
def prepare(expr):
    expr = re.sub(r'\bsinh', 'math.sinh', expr) #r'' means a raw string — it tells Python not to treat \ as an escape character
    expr = re.sub(r'\bcosh', 'math.cosh', expr) # => r'\b' is literally the characters \ and b
    expr = re.sub(r'\btanh', 'math.tanh', expr) # => \b is a word boundary in regex.
    expr = re.sub(r'\basinh', 'math.asinh', expr)
    expr = re.sub(r'\bacosh', 'math.acosh', expr)
    expr = re.sub(r'\batanh', 'math.atanh', expr)
    expr = re.sub(r'\barcsin', 'math.asin', expr)
    expr = re.sub(r'\barccos', 'math.acos', expr)
    expr = re.sub(r'\barctan', 'math.atan', expr)
    expr = re.sub(r'\bsin', 'math.sin', expr)
    expr = re.sub(r'\bcos', 'math.cos', expr)
    expr = re.sub(r'\btan', 'math.tan', expr)
    expr = re.sub(r'\bexp', 'math.exp', expr)
    expr = re.sub(r'\bln', 'math.log', expr)
    expr = re.sub(r'\bsqrt', 'math.sqrt', expr)
    expr = re.sub(r'\bpi', 'math.pi', expr)
    expr = re.sub(r'\be', 'math.e', expr)
    expr = re.sub(r'\,', '.', expr)
    return expr
expression = input("Input your expression: ")

try:
    expression = prepare(expression)
    result = eval(expression)
    print("OUTPUT: ", result)
except Exception as e:
    print("Error in expression: ", e)