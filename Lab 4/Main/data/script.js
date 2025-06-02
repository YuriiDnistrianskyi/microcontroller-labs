let socket = new WebSocket("ws://" + location.host + "/ws");
let buttonState = 0;

function setButtonState() {
    let data = {
        setState: 1
    };
    socket.send(JSON.stringify(data));
}

function checkButtonState() {
    console.log("button state: " + buttonState);
    const button = document.getElementById("button");
    if (buttonState == 1) {
        button.textContent = "OFF";
        button.style.backgroundColor = "#ba3c3c";
    } else {
        button.textContent = "ON";
        button.style.backgroundColor = "#579954";
    }
}

function setLedColor()
{
    let data = {
        red: document.getElementById("volume-red").value,
        green: document.getElementById("volume-green").value,
        blue: document.getElementById("volume-blue").value,
        }
    socket.send(JSON.stringify(data));
}

socket.onmessage = function(event) {
    console.log("Get data");
    let data = JSON.parse(event.data);
    document.getElementById("volume-red").value = data.red;
    document.getElementById("volume-green").value = data.green;
    document.getElementById("volume-blue").value = data.blue;
    buttonState = data.button;
    checkButtonState();
}
