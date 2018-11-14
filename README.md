# `re-date`

[![Build Status](https://img.shields.io/travis/com/mobily/re-date.svg?style=flat-square)](https://travis-ci.com/mobily/re-date) [![npm](https://img.shields.io/npm/v/@mobily/re-date.svg?style=flat-square)](https://www.npmjs.com/package/@mobily/re-date) [![PRs Welcome](https://img.shields.io/badge/PRs-welcome-brightgreen.svg?style=flat-square)](http://makeapullrequest.com) [![All Contributors](https://img.shields.io/badge/all_contributors-2-orange.svg?style=flat-square)](#contributors) [![GitHub license](https://img.shields.io/badge/license-MIT-blue.svg?style=flat-square)](https://github.com/mobily/re-date/blob/master/LICENSE)

> …

## Installation

```shell
yarn add @mobily/re-date
```

## Api Reference

`ReDate` has (almost) the same API as the popular [`date-fns`](https://date-fns.org/v2.0.0-alpha.25/docs/Getting-Started). 

### Day helpers

#### `addDays: (Js.Date.t, int) => Js.Date.t;`

Add the specified number of days to the given date.
 
```reason
let date = Js.Date.make();
date->ReDate.addDays(1);
```

#### `subDays: (Js.Date.t, int) => Js.Date.t`

Subtract the specified number of days from the given date.

```reason
let date = Js.Date.make();
date->ReDate.subDays(1);
```

### Month helpers

#### `getDaysInMonth:  Js.Date.t => int`

Get the number of days in a month of the given date.

```reason
let date = Js.Date.(make()->setMonth(5.));
date->ReDate.getDaysInMonth;
```

## Status

Check the current status [here](STATUS.md).

## Contributors

<!-- ALL-CONTRIBUTORS-LIST:START - Do not remove or modify this section -->
<!-- prettier-ignore -->
| [<img src="https://avatars1.githubusercontent.com/u/1467712?v=4" width="100px;"/><br /><sub><b>Marcin Dziewulski</b></sub>](https://twitter.com/__marcin_)<br />[💻](https://github.com/mobily/re-date/commits?author=mobily "Code") | [<img src="https://avatars3.githubusercontent.com/u/1303365?v=4" width="100px;"/><br /><sub><b>Radek Kozieł</b></sub>](http://radoslawkoziel.pl)<br />[💻](https://github.com/mobily/re-date/commits?author=panr "Code") |
| :---: | :---: |
<!-- ALL-CONTRIBUTORS-LIST:END -->

This project follows the [all-contributors](https://github.com/kentcdodds/all-contributors) specification. Contributions of any kind welcome!

## License

The MIT License.

See [LICENSE](LICENSE)
