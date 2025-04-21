/**
 * @param {string} word1
 * @param {string} word2
 * @return {string}
 */
var mergeAlternately = function(word1, word2) {
    let rtn = new String();
    let i = 0;

    while(i < word1.length && i < word2.length) {
        rtn += word1.charAt(i);
        rtn += word2.charAt(i);
        ++i;
    }

    while(i < word1.length)
        rtn += word1.charAt(i++);

    while(i < word2.length)
        rtn += word2.charAt(i++);

    return rtn;
};