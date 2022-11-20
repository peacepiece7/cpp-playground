const a = "100.00\n489.12\n12454.12\n1234.10\n823.05\n109.20\n5.27\n1542.25\n839.18\n83.99\n1295.01\n1.75"
const input = a.split("\n")

const mem = [];
for(let i = 0 ; i < input.length; i++) {
    mem[i] = input[i];
}
let sum = 0;
for(let i = 0; i < mem.length; i++) sum += Number(mem[i]);
console.log(`$${sum / 12}`)