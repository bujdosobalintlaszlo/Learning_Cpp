using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LengyelForma
{
    public class ConvertToLengyel
    {
        string s;
        public ConvertToLengyel(string s) { 
            this.s = s;
        }
        public void LengyelFormat()
        {
            Stack<char> v = new Stack<char>();
            //string s = Console.ReadLine()!;
            char x = s[0];
            int i = 0;
            while (i < s.Length)
            {
                x = s[i];
                if (Operandus(x))
                {
                    Console.Write(x);
                }
                else if (x == '(')
                {
                    v.Push(x);
                }
                else if (x == ')')
                {
                    while (v.Peek() != '(')
                    {
                        Console.Write(v.Pop());
                    }
                    v.Pop();
                }
                else if (Operator(x))
                {
                    if (BalJobbOperator(x))
                    {
                        while (v.Count != 0 && v.Peek() != '(' && Precedence(x) <= Precedence(v.Peek()))
                        {
                            Console.Write(v.Pop());
                        }
                    }
                    else
                    {
                        while (v.Count != 0 && v.Peek() != '(' && Precedence(x) < Precedence(v.Peek()))
                        {
                            Console.Write(v.Pop());
                        }
                    }
                    v.Push(x);
                }
                ++i;
            }
            while (v.Count != 0)
            {
                Console.Write(v.Pop());
            }
        }

        static bool Operandus(char x)
        {
            return char.IsLetterOrDigit(x);
        }


        static bool Operator(char x)
        {
            switch (x)
            {
                case '+':
                    return true;
                case '-':
                    return true;
                case '*':
                    return true;
                case '/':
                    return true;
                case '^':
                    return true;
                default: return false;
            }
        }

        static bool BalJobbOperator(char x)
        {
            switch (x)
            {
                case '+':
                case '-':
                case '*':
                case '/':
                    return true;
                case '^':
                    return false;
                default: return true;
            }
        }


        static int Precedence(char op)
        {
            switch (op)
            {
                case '+':
                case '-':
                    return 1;
                case '*':
                case '/':
                    return 2;
                case '^':
                    return 3;
                default:
                    return 0;
            }
        }
    }
}
