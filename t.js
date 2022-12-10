// highorder function
/* 여기에 inBetween과 inArray를 작성하세요 */
let arr = [1, 2, 3, 4, 5, 6, 7]
const inBetween = (a, b) => (value) => value >= a && value <= b
// prettier-ignore
const inArray = (arr) => (value) => arr.includes(value)
const a = arr.filter(inBetween(3, 6)) // 3, 4, 5, 6
const b = arr.filter(inArray([1, 2, 10])) // 1, 2

let users = [
  { name: 'John', age: 20, surname: 'Johnson' },
  { name: 'Pete', age: 18, surname: 'Peterson' },
  { name: 'Ann', age: 19, surname: 'Hathaway' },
]

const byField = (p) => (a, b) => a[p] > b[p] ? 1 : -1
users.sort(byField('age'))

function makeArmy() {
  let shooters = []

  let i = 0
  while (i < 10) {
    let j = i
    let shooter = function () {
      // shooter 함수
      console.log(j) // 자신의 숫자를 보여주어야 합니다.
    }
    shooters.push(shooter)
    i++
  }

  return shooters
}

let army = makeArmy()

// recursion 예제 두 개
const fac = (val) => (val == 1 ? val : fac(val - 1) * val)
console.log(fac(6))
const s = 'the lazy fox jumps over the brown dog'
const revStr = (str) => (str == '' ? str : revStr(str.substr(1)) + str[0])
console.log(revStr(s))
