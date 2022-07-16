$(function () {
  $('.noidungthem').slideUp(0);

  $('.nutload').click(function (e) { 
    e.preventDefault();
    
    $('.noidungthem').slideDown(200);

    TweenMax.staggerFrom($('.noidungthem .to'),0.8,{top: 100,opacity: 0},0.3)

  });
});
