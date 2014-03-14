using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

class StringList
{
    static SortedSet<string> words = new SortedSet<string>();
    static string letters;
    static int wordSize;

    static void Main(string[] args)
    {
        using (StreamReader reader = File.OpenText(args[0]))
        {
            while (!reader.EndOfStream)
            {
                string[] parts = reader.ReadLine().Split(',');
                wordSize = Int32.Parse(parts[0]);
                letters = parts[1];
                words.Clear();

                BuildWords("");

                Console.WriteLine(string.Join(",", words));
            }
        }
    }

    static void BuildWords(string word)
    {
        if (word.Length < wordSize)
            foreach (char c in letters)
                BuildWords(word + c);
        else
            words.Add(word);
    }
}
