
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.Iterator;
import java.util.Set;
import java.util.TreeSet;

public class Main {

    static class StringList implements Iterable<String> {

        Set<String> words;
        char[] letters;
        int wordSize;

        public StringList(String l, int ws) {
            letters = l.toCharArray();
            wordSize = ws;
            words = new TreeSet<>();
            BuildWords("");
        }

        private void BuildWords(String word) {
            if (word.length() < wordSize) {
                for (char c : letters) {
                    BuildWords(word + c);
                }
            } else {
                words.add(word);
            }
        }

        @Override
        public Iterator<String> iterator() {
            return words.iterator();
        }
        
    }

    public static void main(String[] args) throws FileNotFoundException, IOException {
        BufferedReader r = new BufferedReader(new FileReader(args[0]));
        String line;
        while ((line = r.readLine()) != null) {
            String[] parts = line.split(",");

            StringList list = new StringList(parts[1], Integer.parseInt(parts[0]));

            Boolean comma = false;
            for (String word : list) {
                if (comma) {
                    System.out.print(",");
                }
                comma = true;

                System.out.print(word);
            }
            System.out.println();
        }
        r.close();
    }
}
