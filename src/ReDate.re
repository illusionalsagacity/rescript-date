open Js.Date;

open ReDate__Internal;

type dates =
  | List(list(Js.Date.t))
  | Array(array(Js.Date.t));

type interval = {
  start: Js.Date.t,
  end_: Js.Date.t,
};

let isEqual = (firstDate, secondDate) => firstDate->getTime === secondDate->getTime;

let isAfter = (firstDate, secondDate) => firstDate->getTime > secondDate->getTime;

let isBefore = (firstDate, secondDate) => firstDate->getTime < secondDate->getTime;

let isFuture = date => date->isAfter(make());

let isPast = date => date->isBefore(make());

let compareAsc = ((-1), 1)->ascDescComparator;

let compareDesc = (1, (-1))->ascDescComparator;

let min = dates =>
  (
    switch (dates) {
    | List(dates) => dates->Belt.List.reduce(None, (<)->minMaxReducer)
    | Array(dates) => dates->Belt.Array.reduce(None, (<)->minMaxReducer)
    }
  )
  ->retrieveMinMax;

let max = dates =>
  (
    switch (dates) {
    | List(dates) => dates->Belt.List.reduce(None, (>)->minMaxReducer)
    | Array(dates) => dates->Belt.Array.reduce(None, (>)->minMaxReducer)
    }
  )
  ->retrieveMinMax;

let isWithinInterval = (date, ~start, ~end_) => {
  let ts = date->getTime;
  ts >= start->getTime && ts <= end_->getTime;
};

let areIntervalsOverlapping = (left, right) =>
  left.start->getTime < right.end_->getTime && right.start->getTime < left.end_->getTime;

let getOverlappingDaysInIntervals = (left, right) =>
  switch (left.start->getTime, left.end_->getTime, right.start->getTime, right.end_->getTime) {
  | (lst, let', rst, ret) when lst < ret && rst < let' =>
    let overlapStartTime = rst < lst ? lst : rst;
    let overlapEndTime = ret > let' ? let' : ret;
    let overlap = (overlapEndTime -. overlapStartTime) /. dayMs->float_of_int;

    overlap->Js.Math.ceil_int;
  | _ => 0
  };

let getDaysInMonth = date =>
  makeYMDWithResetHMS(~year=date->getFullYear, ~month=date->getMonth +. 1., ~date=0., ())->getDate;

let addDays = (date, days) => date->setDate(date->getDate +. days)->fromFloat;

let addWeeks = (date, weeks) => date->addDays(weeks *. 7.);

let addMonths = (date, months) =>
  makeWithYMD(
    ~year=date->getFullYear,
    ~month=date->getMonth +. months,
    ~date=Js.Math.min_float(date->getDaysInMonth, date->getDate),
    (),
  );

let addYears = (date, years) => date->addMonths(12. *. years);
