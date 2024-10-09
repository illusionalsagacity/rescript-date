open ReDate_types
open ReDate_utils

let getDay = date => date->Js.Date.getDay->int_of_float->toDayMagic
let isSunday = date => is(Sunday, date)
let isMonday = date => is(Monday, date)
let isTuesday = date => is(Tuesday, date)
let isWednesday = date => is(Wednesday, date)
let isThursday = date => is(Thursday, date)
let isFriday = date => is(Friday, date)
let isSaturday = date => is(Saturday, date)
let isWeekend = date => is(Saturday, date) || is(Sunday, date)
let isWeekDay = (date, weekday) => is(weekday, date)
