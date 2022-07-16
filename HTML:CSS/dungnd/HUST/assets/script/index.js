const tongHop = document.querySelector('.th');
const daoTaoDaiHoc = document.querySelector('.dtdh');
const daoTaoSauDaiHoc = document.querySelector('.dtsdh');
const vuaLamVuaHoc = document.querySelector('.vlvh');


tongHop.onclick = function() {
    document.getElementById("th").style.display = 'block';
    document.getElementById("dtdh").style.display = 'none';
    document.getElementById("dtsdh").style.display = 'none';
    document.getElementById("vlvh").style.display = 'none';

    tongHop.classList.add('general__task-item--clicked');
    daoTaoDaiHoc.classList.remove('general__task-item--clicked');
    daoTaoSauDaiHoc.classList.remove('general__task-item--clicked');
    vuaLamVuaHoc.classList.remove('general__task-item--clicked');
}

daoTaoDaiHoc.onclick = function() {
    document.getElementById("th").style.display = 'block';
    document.getElementById("dtdh").style.display = 'none';
    document.getElementById("dtsdh").style.display = 'none';
    document.getElementById("vlvh").style.display = 'none';

    tongHop.classList.remove('general__task-item--clicked');
    daoTaoDaiHoc.classList.add('general__task-item--clicked');
    daoTaoSauDaiHoc.classList.remove('general__task-item--clicked');
    vuaLamVuaHoc.classList.remove('general__task-item--clicked');
}

daoTaoSauDaiHoc.onclick = function() {
    document.getElementById("th").style.display = 'none';
    document.getElementById("dtdh").style.display = 'none';
    document.getElementById("dtsdh").style.display = 'block';
    document.getElementById("vlvh").style.display = 'none';

    tongHop.classList.remove('general__task-item--clicked');
    daoTaoDaiHoc.classList.remove('general__task-item--clicked');
    daoTaoSauDaiHoc.classList.add('general__task-item--clicked');
    vuaLamVuaHoc.classList.remove('general__task-item--clicked');
}

vuaLamVuaHoc.onclick = function() {
    document.getElementById("th").style.display = 'none';
    document.getElementById("dtdh").style.display = 'none';
    document.getElementById("dtsdh").style.display = 'none';
    document.getElementById("vlvh").style.display = 'block';

    tongHop.classList.remove('general__task-item--clicked');
    daoTaoDaiHoc.classList.remove('general__task-item--clicked');
    daoTaoSauDaiHoc.classList.remove('general__task-item--clicked');
    vuaLamVuaHoc.classList.add('general__task-item--clicked');
}





