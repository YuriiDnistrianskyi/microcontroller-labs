#include "../include/html.h"

const char* html = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Led</title>
    <style>
        .led {
            display: flex;
            margin: auto;
            width: 100px;
            height: 100px;
            border-style: solid;
        }

        .button {
            display: flex;
            margin: auto;
            margin-top: 10px;
            width: 200px;
            height: 50px;
            border: none;

            border-radius: 20px;
            background-color: #5d5be8;

            font-size: 20px;
            transition: linear 0.3s;
        }

        .button:active {
            transform: scale(1.1);
            background-color: #0c0c79;
        }
        
    </style>
</head>
<body>
    <div class="led" id="led"></div>
    <button class="button" onClick="sendCommand()">On/Off</button>
</body>
<script>
    let ledState = 0;

    function checkLedState() {
        const led = document.getElementById("led");
        let color;
        if (ledState == 0) {
            color = "#ffffff";
        } else {
            color = "#1f9c0e";
        }

        led.style.backgroundColor = color;
    }

    function sendCommand() {
        fetch("/click", {method: "POST"});
    }

    function getLedState() {
        fetch("/get_state", {method: "GET"})
            .then(response => response.text())
            .then(data => {
                ledState = data;
                console.log(ledState);
                checkLedState();
            })
            .catch(error => console.log(error))
    }

    setInterval(getLedState, 500);
</script>
</html>
)rawliteral";
