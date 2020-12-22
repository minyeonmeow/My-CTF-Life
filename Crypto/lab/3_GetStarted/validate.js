const fs = require('fs')
const lib = require('./lib')(require('./config'))

async function main () {
	let factory = lib.contract('0x16cf9e5a5848E40E27751f1c9277291993fE6C4E', JSON.parse(fs.readFileSync('GetStartedFactory.abi')))
	await factory.call('validate', '0xbfe1807aa18fa42d69b6f2d152508fbfcc95bbfdc8dbae3e5a33b5a86cdc51fb')
}

main()
