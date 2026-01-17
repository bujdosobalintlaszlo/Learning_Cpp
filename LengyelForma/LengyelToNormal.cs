using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LengyelForma
{
    public class LengyelToNormal
    {
        string s;
        public LengyelToNormal(string s) {
            this.s = s;
        }

        public void LengyelKIertekeles() { 
            Stack<string> v = new Stack<string>();
            int i = 0;
            while (i < s.Length) {
                char x = s[i];
                if (Operator(x)) { 
                    string jobb = v.Pop();
                    string bal = v.Pop();
                    v.Push(CompleteOperation(bal, jobb, x));
                }
                if (Operandus(x)) {
                    v.Push(x.ToString());
                }
                ++i;
            }
            Console.WriteLine(v.Pop());
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
        string CompleteOperation(string bal, string jobb, char op)
        {
            return $"({bal}{op}{jobb})";
        }
    }
}
