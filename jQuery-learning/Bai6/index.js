$(function () {
  // $('.dangnhap').animate({
  //     opacity: 0,
  //     marginLeft: -100,
  // })

  $('.dangky').animate({
      opacity: 0,
      marginLeft: -100,
  })

  $(".nutso2").click(() => {
    $(".dangnhap").animate({
      opacity: 0,
      marginLeft: -100,
    });

    $(".dangky").animate({
      opacity: 1,
      marginLeft: 0,
    });
  });

  $(".nutso1").click(() => {
    $(".dangnhap").animate({
      opacity: 1,
      marginLeft: 0,
    });

    $(".dangky").animate({
      opacity: 0,
      marginLeft: -100,
    });
  });
});
