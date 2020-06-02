function ligar() {
    fetch('http://192.168.1.51').then((res) => {

    }).catch((err) => {
        alert('erro' + err)
    })
}

function desligar() {
    alert('ok')
}