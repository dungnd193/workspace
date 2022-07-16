$(function () {
  $(window).scroll(function () { 
    var vitri = $(document).scrollTop();
    if(vitri >= 400) {
      $('.menutren').addClass('bienhinh');
    } else {
      $('.menutren').removeClass('bienhinh');
    }
  });
});
