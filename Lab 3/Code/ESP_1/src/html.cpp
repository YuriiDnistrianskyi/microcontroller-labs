#include "../include/html.h"

const char html[] PROGMEM = R"rawliteral(
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>ESP32 WebSite</title>
    <style>
        .block {
            top: 60%;
        }

        .text {
            text-align: center;
            font-family:'Gill Sans', 'Gill Sans MT', Calibri, 'Trebuchet MS', sans-serif
        }
        
        .button-block {
            display: flex;
            flex-direction: column;
            justify-content: space-between;
            margin: 0 auto;
            width: 60%;
            height: 20rem;
        }

        .button {
            margin: 0 auto;
            width: 100%;
            height: 30%;
            border-radius: 40px;
            border: none;

            color: #ffffff;
            background-color: #2369b4;

            transition: linear 0.3s;
        }

        .button:hover {
            transform: scale(1.1);
            color: #000000;
            background-color: #62aeff;
        }

        .button:active {
            transform: scale(0.9);
            background-color: #0053ac;
        }

        .time {
            text-align: center;
            font-size: 5rem;
            font-family:'Lucida Sans', 'Lucida Sans Regular', 'Lucida Grande', 'Lucida Sans Unicode', Geneva, Verdana, sans-serif
        }


    </style>
</head>
<body>
    <div class="block">
        <h1 class="text">ESP32 Web Site</h1>
        <p class="time" id="time">12:12:12</p>
        <div class="button-block">
            <button class="button" onclick="sendCommandFirst()">Start/Stop/Reset</button>
            <button class="button" onclick="sendCommandSetHour()">Set Hour</button>
            <button class="button" onclick="sendCommandSetMinutes()">Set Minutes</button>
        </div>
    </div>
    <script>
        let time = "00:00:00";

        function setTime() {
            const timeElement = document.getElementById("time");
            timeElement.textContent = time;
        }

        async function sendCommand() {
            fetch("/command", { method: "POST" });
        }

        async function sendCommandSetHour() {
            fetch("/set_hours", { method: "POST" });
        }

        async function sendCommandSetMinutes() {
            fetch("/set_minutes", { method: "POST" });
        }

        function getTime() {
            fetch("/time", { method: "GET"})
                .then(response => response.json())
                .then(data => {
                    time = data.time;
                    setTime();
                })
                .catch(error => console.log(error));
        }

        setInterval(getTime, 200);

    </script>
</body>
</html>
)rawliteral";
