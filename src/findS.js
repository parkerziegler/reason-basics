module.exports = {
  findS(str) {
    const sCount = str.split('').filter(char => char === 's');
    return sCount.length;
  },
  myJSObject: {
    language: "JavaScript",
    users: 5000000,
    color: "yellow"
  }
};