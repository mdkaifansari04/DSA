function printPatterTriangle(n) {
  for (let i = 0; i < n; i++) {
    let line = "";
    for (let j = 0; j <= i; j++) {
      line += "* ";
    }
    console.log(line);
  }
}

// * 
// * * 
// * * * 
// * * * * 
// * * * * * 
printPatterTriangle(5);
