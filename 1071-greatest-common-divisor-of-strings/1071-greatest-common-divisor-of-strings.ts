function gcdOfStrings(str1: string, str2: string): string {
    if(str1 + str2 != str2 + str1)
        return "";
    return str1.substring(0, getGcd(str1.length, str2.length));
};

function getGcd(length1 : number, length2 : number) {
    if(length2 === 0)
        return length1;
    return getGcd(length2, length1 % length2);
};