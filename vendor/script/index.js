let array = []
let result = []
let i = 0

 function shuffle(a) {
    var j, x, i;
    for (i = a.length - 1; i > 0; i--) {
        j = Math.floor(Math.random() * (i + 1));
        x = a[i];
        a[i] = a[j];
        a[j] = x;
    }
    return a;
}
while(i < 500) { 
    array.push(i)
    i++
}
shuffle(array)
array.forEach((e) => {
    console.log("%d", e)
})