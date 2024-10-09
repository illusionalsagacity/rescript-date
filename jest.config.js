/**
 * @type {import('@jest/types').Config.InitialOptions}
 */
module.exports = {
  testEnvironment: 'node',
  verbose: true,
  moduleFileExtensions: ['js'],
  rootDir: __dirname,
  testMatch: ['<rootDir>/__tests__/*_test.bs.js'],
}
