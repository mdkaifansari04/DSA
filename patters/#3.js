function printPatterNumberTriangle(n) {
  for (let i = 0; i < n; i++) {
    let line = "";
    for (let j = 0; j <= i; j++) {
      line += `${j + 1} `;
    }
    console.log(line);
  }
}

// 1 
// 1 2 
// 1 2 3 
// 1 2 3 4 
// 1 2 3 4 5 

printPatterNumberTriangle(5);
