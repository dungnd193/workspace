$(function () {
  $('.menutren ul li:nth-child(1) a').on('click', function (e) {
    e.preventDefault();
    $('html,body').animate({scrollTop: $('.chapter1').offset().top},700,'easeOutExpo');
  });

  $('.menutren ul li:nth-child(2) a').on('click', function (e) {
    e.preventDefault();
    $('html,body').animate({scrollTop: $('.chapter2').offset().top},700,'easeOutExpo');
  });

  $('.menutren ul li:nth-child(3) a').on('click', function (e) {
    e.preventDefault();
    $('html,body').animate({scrollTop: $('.chapter3').offset().top},700,'easeOutExpo');
  });

  $('.menutren ul li:nth-child(4) a').on('click', function (e) {
    e.preventDefault();
    $('html,body').animate({scrollTop: $('.chapter4').offset().top},700,'easeOutExpo');
  });

  $('.menutren ul li:nth-child(5) a').on('click', function (e) {
    e.preventDefault();
    $('html,body').animate({scrollTop: $('.chapter5').offset().top},700,'easeOutExpo');
  });

  $('.menutren ul li:nth-child(6) a').on('click', function (e) {
    e.preventDefault();
    $('html,body').animate({scrollTop: $('.chapter6').offset().top},700,'easeOutExpo');
  });

  $('.nutlentren').click(function (e) { 
      e.preventDefault();
      $('html,body').animate({scrollTop: 0},700);
  });
});
