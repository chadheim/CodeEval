(ns even-numbers
  (:gen-class))

(with-open [rdr (clojure.java.io/reader (first *command-line-args*))]
  (doseq [line (remove empty? (line-seq rdr))]
    (println
      (if (even? (Integer/parseInt line))
        1
        0))))