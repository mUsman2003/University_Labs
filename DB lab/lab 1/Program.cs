using System;

namespace lab1
{
    class lab
    {
        public int Reccursion(int val) 
        {
            if (val == 1)
                return 1;
            return val * Reccursion(val - 1);
        }
        public int Length_Word(string ch)
        {
            if (ch == null)
                return 0;
            int len = ch.Length;
            int wordlen = 0;
            int largest = wordlen;
            int n = 0;
            while(n< len)
            {
                if (ch[n] == ' ')
                {
                    if(wordlen>largest)
                        largest = wordlen;
                    wordlen = 0;
                }
                if (ch[n] == ',')
                {
                    if (wordlen > largest)
                        largest = wordlen;
                    wordlen = 0;
                }
                if (ch[n] == '.')
                {
                    if (wordlen > largest)
                        largest = wordlen;
                    wordlen = 0;
                }
                if (ch[n] == '!')
                {
                    if (wordlen > largest)
                        largest = wordlen;
                    wordlen = 0;
                }
                wordlen++;
                n++;

            }
            if (wordlen > largest)
                largest = wordlen;
            return largest-1;
        }
        public bool Palindrome(string val)
        {
            if(val==null)
                return false;
            int len = val.Length;
            int mid = len / 2;
            len--;
            int n = 0;
            while(n<= mid) 
            {
                if (val[n] != val[len])
                    return false;
                n++;
                len--;
            }
            return true;
        }
        public void ReverseWordHelper(char[] characters, int start, int end)
        {
            while (start < end)
            {
                char temp = characters[start];
                characters[start] = characters[end];
                characters[end] = temp;

                start++;
                end--;
            }
        }
        public string ReverseWord(string sentence)
        {
            char[] characters = sentence.ToCharArray();
            int start = 0;

            // Reverse the entire sentence
            ReverseWordHelper(characters, 0, characters.Length - 1);

            for (int end = 0; end < characters.Length; end++)
            {
                if (characters[end] == ' ')
                {
                    // Reverse the word
                    ReverseWordHelper(characters, start, end - 1);
                    start = end + 1;
                }
                else if (end == characters.Length - 1)
                {
                    // Last word in the sentence
                    ReverseWordHelper(characters, start, end);
                }
            }

            return new string(characters);
        }
        public string ReverseString(string input)
        {
            char[] characters = input.ToCharArray();

            int start = 0;
            int end = characters.Length - 1;

            while (start < end)
            {
                char temp = characters[start];
                characters[start] = characters[end];
                characters[end] = temp;

                start++;
                end--;
            }

            return new string(characters);
        }
        public int CharToAscii(char c)
        {
            return 'Z' - c + 1;
        }
        public bool IsSuperString(string input)
        {
            int len=input.Length;
            int count = 0;
            int condition = 0;
            int n = 0;
            while(n<len)
            {
                char temp = input[n];
                condition=CharToAscii(temp);
                for(int m=0;m<len;m++)
                {
                    if (temp == input[m])
                        count++;
                    if (count > condition)
                        return false;
                }
                condition = 0;
                count = 0;
                n++;
            }
            return true;
        }
        static void Main()
        {
            
            string v1;
            Console.WriteLine("");
            Console.WriteLine("--------------------Q1---------------------");
            Console.WriteLine("");
            Console.WriteLine("-------------Calculator-------------");
            Console.WriteLine("  1). Addition");
            Console.WriteLine("  2). Subtraction");
            Console.WriteLine("  3). Division");
            Console.WriteLine("  4). Multiplication");
            Console.WriteLine("  5). Prime Number");
            Console.WriteLine("  6). Factorial");
            Console.WriteLine("  7). Square root");
            Console.WriteLine("  8). Modular Division");

            v1 = Console.ReadLine();

            if(v1 == "1") {
                string a="", b="";
                Console.Write("Enter value of v1 : ");
                a = Console.ReadLine();
                int a1 = Convert.ToInt32(a);
                Console.Write("Enter value of v2 : ");
                b = Console.ReadLine();
                int a2 = Convert.ToInt32(b);
                int sum = a1 + a2;
                Console.Write("Addition : ");
                Console.Write(sum);
            }
            if(v1 == "2") {
                string a = "", b = "";
                Console.Write("Enter value of v1 : ");
                a = Console.ReadLine();
                int a1 = Convert.ToInt32(a);
                Console.Write("Enter value of v2 : ");
                b = Console.ReadLine();
                int a2 = Convert.ToInt32(b);
                int sum = a1 - a2;
                Console.Write("Subtraction : ");
                Console.Write(sum);
            }
            if(v1 == "3") {
                string a = "", b = "";
                Console.Write("Enter value of v1 : ");
                a = Console.ReadLine();
                int a1 = Convert.ToInt32(a);
                Console.Write("Enter value of v2 : ");
                b = Console.ReadLine();
                int a2 = Convert.ToInt32(b);
                int sum = a1 / a2;
                Console.Write("Division : ");
                Console.Write(sum);
            }
            if(v1 == "4") {
                string a = "", b = "";
                Console.Write("Enter value of v1 : ");
                a = Console.ReadLine();
                int a1 = Convert.ToInt32(a);
                Console.Write("Enter value of v2 : ");
                b = Console.ReadLine();
                int a2 = Convert.ToInt32(b);
                int sum = a1 * a2;
                Console.Write("Product : ");
                Console.Write(sum);
            }
            if(v1 == "5") {
                string a = "";
                Console.Write("Enter value to check if it's a prime : ");
                a = Console.ReadLine();
                int val = Convert.ToInt32(a);
                bool check = true;
                for(int n=2;n<val; n++) 
                {
                    if(val%n==0)
                    {
                        Console.Write("Not a prime");
                        check = false;
                        break;
                    }
                }
                if (check == true)
                    Console.WriteLine("Number is a Prime");
            }
            if(v1 == "6") {
                string a = "";
                Console.Write("Enter Number to find its factorial : ");
                a = Console.ReadLine();
                int val = Convert.ToInt32(a);
                lab rec=new lab();
               
                Console.Write("Factorial : ");
                Console.WriteLine(rec.Reccursion(val));
            }
            if(v1 == "7") {
                string a1 = "";
                Console.Write("Enter Number to find it's Square Root : ");
                a1 = Console.ReadLine();
                int val = Convert.ToInt32(a1);
                int n = 1;
                bool check = false;
                int current = 0;
                while(current<=val)
                {
                    current = n * n;
                    if (current == val)
                    {
                        Console.Write("Square Root of number is : ");
                        Console.WriteLine(n);
                        check = true;
                        break;
                    }
                    n++;
                }
                if (check == false) Console.WriteLine("Number does not have a exact square root");

            }
            if(v1 == "8") {
                string a1 = "",b1="",m1="";
                Console.Write("Enter value of a : ");
                a1 = Console.ReadLine();
                int a = Convert.ToInt32(a1);
                Console.Write("Enter value of b : ");
                b1 = Console.ReadLine();
                int b = Convert.ToInt32(b1);
                Console.Write("Enter value of m : ");
                m1 = Console.ReadLine();
                int m = Convert.ToInt32(m1);

                int to_find = a % m;
                int val = 1;
                while((val*b)%m != to_find)
                {
                    val++;
                }
                Console.Write("Modular Division : ");
                Console.WriteLine(val);
            }

            Console.WriteLine("");
            Console.WriteLine("--------------------Q2---------------------");
            Console.WriteLine("");

            string Q2a = "Hello, my Name is Muhammad Usman. I live is Islamabad";
            lab l = new lab();
            Console.Write("the maximum length in the string is : ");
            Console.WriteLine(l.Length_Word(Q2a));


            Console.WriteLine("");
            Console.WriteLine("--------------------Q3---------------------");
            Console.WriteLine("");

            string pal = "";
            Console.Write("Enter Number to check if it's Palindrome or not? : ");
            pal = Console.ReadLine();
        
            if (l.Palindrome(pal))
                Console.WriteLine("The Number is Palindrome");
            else
                Console.WriteLine("The Number is not palindrome");

            Console.WriteLine("");
            Console.WriteLine("--------------------Q4---------------------");
            Console.WriteLine("");

            string Q4a = "Display the pattern like pyramid using the alphabet.";
            Console.WriteLine("Reverse word String : "+ l.ReverseWord(Q4a));

            Console.WriteLine("");
            Console.WriteLine("--------------------Q5---------------------");
            Console.WriteLine("");

            string Q5a = "Reversing a string";
            Console.WriteLine("Reverse String : " +l.ReverseString(Q5a));

            Console.WriteLine("");
            Console.WriteLine("--------------------Q6---------------------");
            Console.WriteLine("");

            string Q6a = "YYZ";
            string Q6b = "ZYYZ";

            if (l.IsSuperString(Q6a))
                Console.WriteLine(Q6a+" is a Super String");
            else
                Console.WriteLine(Q6a+" is not a Super String");

            if(l.IsSuperString(Q6b))
                Console.WriteLine(Q6b+" is a Super String");
            else
                Console.WriteLine(Q6b+" is not a Super String");


        }

    }
}

