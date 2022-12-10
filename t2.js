// // ! 가공 경로를 기존 /processing에서 /rpcessing/[manufacture] 로 변경합니다!

const fs = require("fs")
const { get } = require("http")
// import { PDFDocument, StandardFonts } from 'pdf-lib'

// 1. await new Promise를 반환하는 함수
// 2. fs.readdir를 기다리는 기능
// 3. pdfs만 찾아서 꺼내오는 기능


// // Create a new PDFDocument
// const pdfDoc = await PDFDocument.create()

// // Embed the Times Roman font
// // const timesRomanFont = await pdfDoc.embedFont(StandardFonts.TimesRoman)
// // // Add a page and draw some text on it
// // const page = pdfDoc.addPage([500, 600])
// // page.setFont(timesRomanFont)
// // page.drawText('The Life of an Egg', { x: 60, y: 500, size: 50 })
// // page.drawText('An Epic Tale of Woe', { x: 125, y: 460, size: 25 })

// // Set all available metadata fields on the PDFDocument. Note that these fields
// // are visible in the "Document Properties" section of most PDF readers.
// pdfDoc.setTitle('🥚 The Life of an Egg 🍳')
// pdfDoc.setAuthor('Humpty Dumpty')
// pdfDoc.setSubject('📘 An Epic Tale of Woe 📖')
// pdfDoc.setKeywords(['eggs', 'wall', 'fall', 'king', 'horses', 'men'])
// pdfDoc.setProducer('PDF App 9000 🤖')
// pdfDoc.setCreator('pdf-lib (https://github.com/Hopding/pdf-lib)')
// pdfDoc.setCreationDate(new Date('2018-06-24T01:58:37.228Z'))
// pdfDoc.setModificationDate(new Date('2019-12-21T07:00:11.000Z'))

// // Serialize the PDFDocument to bytes (a Uint8Array)
// const pdfBytes = await pdfDoc.save()

// // For example, `pdfBytes` can be:
// //   • Written to a file in Node
// //   • Downloaded from the browser

const sortOutPdfFiles = (files) => files.filter((file) => file.toLowerCase().includes('.pdf'))
const getDirectories = (dirs) => dirs.filter((dirs) => dirs.isDirectory())

const safely = async (fn) => await new Promise((res) => fn(res))
const servePdfFiles = (dir, res) => fs.readdir(dir, (err, files) => err ? res([]) : res(sortOutPdfFiles(files)))
const serveDirectories = (dir, res) => fs.readdir(dir,{withFileTypes : true}, (err, files) => err ? res([]) : res(getDirectories(files).map((v) => v.name)))

const obj = await Object.create({}, {
  pdfFiles : {
    async get() {
      return await safely((resolve) => servePdfFiles(dir, resolve))
    },
    set(files) {
      return sortOutPdfFiles(files)
    }
  },
  directories : {
    async get() {
      return await safely((resolve) => servePdfFiles(dir, resolve))
    },
    set(dirs) {
      return getDirectories(dirs)
    }
  }
 })

const convertPdfMetaData = async (dir) => {
  try {
    /** @type {string[]} */
   const directories = await safely((resolve) => serveDirectories(dir, resolve))


  } catch (err) {
    console.log(err)
  }
}
convertPdfMetaData('C:\\Users\\lynil\\OneDrive\\processing')