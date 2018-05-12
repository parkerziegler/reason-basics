module.exports = {
  findS(str) {
    const sCount = str.split('').filter(char => char === 's');
    return sCount.length;
  }
};