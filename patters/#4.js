function printReverseStarTriangle(n) {
  for (let i = 0; i < n; i++) {
    let line = "";
    for (let j = 0; j < n - i; j++) {
      line += "* ";
    }
    console.log(line);
  }
}

// * * * * *
// * * * *
// * * *
// * *
// *
printReverseStarTriangle(5);
