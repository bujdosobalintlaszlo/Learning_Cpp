using System.Numerics;

namespace LengyelForma
{
    internal class Program
    {
        static void Main(string[] args)
        {
            string s = Console.ReadLine();
            /*
               ConvertToLengyel l = new ConvertToLengyel(s);
               l.LengyelFormat();
            */
            LengyelToNormal l = new LengyelToNormal(s);
            l.LengyelKIertekeles();
        }
    }
}
