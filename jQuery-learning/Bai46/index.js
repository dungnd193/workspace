$(function () {
  $('.nut').click(function (e) { 
    e.preventDefault();
    
    $('.noidung').addClass('noidunghienra');
    $('.momo').addClass('momodira');
  });

  $('.nutdong,.momo').click(function (e) { 
    $('.noidung').removeClass('noidunghienra');
    $('.momo').removeClass('momodira');
  });

 
});
