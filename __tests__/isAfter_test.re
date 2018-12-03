open Jest;

open Js.Date;

describe("isAfter", () => {
  open ExpectJs;

  test("returns true if the first date is after the second one", () => {
    let fstDate = makeWithYMD(~year=2018., ~month=0., ~date=2., ());
    let sndDate = makeWithYMD(~year=2018., ~month=0., ~date=1., ());

    fstDate |> ReDate.isAfter(sndDate) |> expect |> toBeTruthy;
  });

  test("returns false if the first date is after the second one", () => {
    let fstDate = makeWithYMD(~year=2018., ~month=0., ~date=1., ());
    let sndDate = makeWithYMD(~year=2018., ~month=0., ~date=2., ());

    fstDate |> ReDate.isAfter(sndDate) |> expect |> toBeFalsy;
  });
});
