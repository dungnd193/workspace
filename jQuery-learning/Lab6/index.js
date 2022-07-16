$(function() {
    var namePattern = /^[a-zA-Z ]+$/
    var emailPattern = /^[a-zA-Z0-9._-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,4}$/
    var phoneNumberPattern = /^0[35789]{1}[\d]{8}$/
    var datePattern = /^(0?[1-9]|[12][0-9]|3[01])[\/\-](0?[1-9]|1[012])[\/\-]\d{4}$/
    var validation
    $('.fullname-js').on('input', function(e) {
        var name = namePattern.exec(e.target.value)
        console.log(name)
        if(!name) {
            $('.fullname-js').next().css('display', 'block')
            validation = false;
        } else {
            $('.fullname-js').next().css('display', 'none')
            validation = true;
        }
    })

    $('.email-js').on('input', function(e) {
        var email = emailPattern.exec(e.target.value)
        console.log(email)
        if(!email) {
            $('.email-js').next().css('display', 'block')
            validation = false;
        } else {
            $('.email-js').next().css('display', 'none')
            validation = true;
        }
    })

    $('.phone-number-js').on('input', function(e) {
        var phoneNumber = phoneNumberPattern.exec(e.target.value)
        console.log(phoneNumber)
        if(!phoneNumber) {
            $('.phone-number-js').next().css('display', 'block')
            validation = false;
        } else {
            $('.phone-number-js').next().css('display', 'none')
            validation = true;
        }
    })
    
    $('.address-js').on('input', function(e) {
        if($('.address-js').val()) {
            $('.address-js').next().css('display', 'none')
            validation = true;
        } else {
            $('.address-js').next().css('display', 'block')
            validation = false;
        }
    })

    $('.order-date-js').on('input', function(e) {
        var date = datePattern.exec(e.target.value)
        console.log(date)
        if(!date) {
            $('.order-date-js').next().css('display', 'block')
            validation = false;
        } else {
            $('.order-date-js').next().css('display', 'none')
            validation = true;
        }
    })
    
    $('.paying-method-js').on('input', function(e) {
        if($('.paying-method-js').val()) {
            $('.paying-method-js').next().css('display', 'none')
            validation = true;
        } else {
            $('.paying-method-js').next().css('display', 'block')
            validation = false;
        }
    })

    $('.clear').click(function (e) { 
        e.preventDefault();
        $('.fullname-js').val("");
        $('.email-js').val("");
        $('.phone-number-js').val("");
        $('.address-js').val("");
        $('.order-date-js').val("");
        $('.paying-method-js').val("");

        $('.fullname-reciever-js').val("")
            $('.email-reciever-js').val("")
            $('.phone-number-reciever-js').val("")
            $('.address-reciever-js').val("")
            $('.note-js').val("")
            validation = false;
    });

    $('.reciever_ck-js').click(function (e) { 
        if($('.reciever_ck-js').prop('checked')) {
            $('.fullname-reciever-js').val($('.fullname-js').val())
            $('.email-reciever-js').val($('.email-js').val())
            $('.phone-number-reciever-js').val($('.phone-number-js').val())
            $('.address-reciever-js').val($('.address-js').val())
            if($('.address-js').val() && $('.order-date-js').val()) {
                $('.note-js').val('Ngày đặt: ' + $('.order-date-js').val() + '\n' + 'Phương thức thanh toán: ' + $('.paying-method-js').val())
            } else {
                $('.note-js').val("")    
            }
        } else {
            $('.fullname-reciever-js').val("")
            $('.email-reciever-js').val("")
            $('.phone-number-reciever-js').val("")
            $('.address-reciever-js').val("")
            $('.note-js').val("")
        }
    });

    $('.submit-js').click(function (e) { 
        e.preventDefault();
        if(validation) {
            if($('.send-mail_ck-js').prop('checked')) {
                alert('Đặt hàng thành công, email đã giửi tói cho quý khách')
                $('.clear').click()
                $('.send-mail_ck-js').click()
            } else {
                alert('Đặt hàng thành công')
                $('.clear').click()
            }
        } else {
            alert('Đặt hàng thất bại, hãy hoàn tất các trường dữ liệu!')
        }

        if($('.send-mail_ck-js').prop('checked')) {
            console.log(123)
        }
        
        console.log(validation)
    });
})