open Jest;

open Js.Date;

describe("lastDayOfMonth", () =>
  ExpectJs.(
    test("returns the date with the time setted to 00:00:00 and the date setted to the last day of a month", () => {
      let date = makeWithYMDHMS(~year=2018., ~month=0., ~date=12., ~hours=16., ~minutes=50., ~seconds=12., ());
      let expectedDate =
        setHoursMSMs(
          makeWithYMD(~year=2018., ~month=0., ~date=31., ()),
          ~hours=0.,
          ~minutes=0.,
          ~seconds=0.,
          ~milliseconds=0.,
          (),
        )
        |> fromFloat;

      date |> ReDate.lastDayOfMonth |> expect |> toEqual(expectedDate);
    })
  )
);
