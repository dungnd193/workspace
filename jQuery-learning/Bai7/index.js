$(function() {
    // co nho noi dung
    $('.ndmotkhoi').slideUp(300)

    $('.motkhoi h3').click(function (e) { 
        // 300 miliseconds
        $(this).next().slideToggle(300);
        $(this).toggleClass('xanh')
        if($(this).children().hasClass('fa-chevron-down')) {
            $(this).children().removeClass('fa-chevron-down')
            $(this).children().addClass('fa-chevron-up')
        } else {
            $(this).children().removeClass('fa-chevron-up')
            $(this).children().addClass('fa-chevron-down')
        }
        
    });
})