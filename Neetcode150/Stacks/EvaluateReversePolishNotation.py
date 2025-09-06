from typing import *


class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        st = []
        op = ["+", "-", "*", "/"]

        for token in tokens:
            if token in op:
                op2 = int(st.pop())
                op1 = int(st.pop())
                if token == "+":
                    st.append(str(op1+op2))
                elif token == '-':
                    st.append(str(op1 - op2))
                elif token == '*':
                    st.append(str(op1*op2))
                elif token == "/":
                    st.append(str(int(op1/op2)))
            else:
                st.append(token)
        return int(st[0])