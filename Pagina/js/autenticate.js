

function enviar() {
    var pwd = 2019073
var log = "automacao"
    var senha = document.querySelector('#pwd')
    var login = document.querySelector('#login')

    if (pwd == senha && log == login) {
        document.write('ok')
    } else {
        location('192.168.1.5/index.html')
    }

}