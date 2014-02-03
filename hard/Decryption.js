var cipher = "012222 1114142503 0313012513 03141418192102 0113 2419182119021713 06131715070119",
    key = "BHISOECRTMGWYVALUZDNFJKPQX",
    alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
    plaintext;

plaintext = cipher.split(' ').map(function(word) {
  return word.match(/.{2}/g).map(function(letter) {
    return alpha[key.indexOf(alpha[parseInt(letter)])];
  }).join('');
}).join(' ');

console.log(plaintext);
