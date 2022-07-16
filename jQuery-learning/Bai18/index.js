$(function () {
  $(".tdkhoi").click(function (e) {
    e.preventDefault();

    $(this).toggleClass("xanh");
    $(this).next().slideToggle();

    $('html,body').animate({
      scrollTop: $(this).offset().top
    }, 700, "easeInOutQuart")
  });

  // Code cho phan phong to anh
  $(".vaicaianh a").fancybox();

  $(".ndkhoi").slideUp();
});
