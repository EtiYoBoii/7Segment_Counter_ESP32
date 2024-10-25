#include <WiFi.h>
#include <WebServer.h>
#include <Arduino.h>

// WiFi credentials
const char* ssid = "Your SSID";
const char* password = "Your password";

// Pins for the 7-segment display
const int segment_pins[] = {1, 2, 3, 4}; // Update to your pin configuration
volatile uint8_t counter = 0;

WebServer server(80);

// Function to set the segments based on the counter value using a switch statement
void Segments(uint8_t digit) {
  switch(digit) {
    case 0: digitalWrite(segment_pins[0], LOW); digitalWrite(segment_pins[1], LOW); digitalWrite(segment_pins[2], LOW); digitalWrite(segment_pins[3], LOW); break;
    case 1: digitalWrite(segment_pins[0], HIGH); digitalWrite(segment_pins[1], LOW); digitalWrite(segment_pins[2], LOW); digitalWrite(segment_pins[3], LOW); break;
    case 2: digitalWrite(segment_pins[0], LOW); digitalWrite(segment_pins[1], HIGH); digitalWrite(segment_pins[2], LOW); digitalWrite(segment_pins[3], LOW); break;
    case 3: digitalWrite(segment_pins[0], HIGH); digitalWrite(segment_pins[1], HIGH); digitalWrite(segment_pins[2], LOW); digitalWrite(segment_pins[3], LOW); break;
    case 4: digitalWrite(segment_pins[0], LOW); digitalWrite(segment_pins[1], LOW); digitalWrite(segment_pins[2], HIGH); digitalWrite(segment_pins[3], LOW); break;
    case 5: digitalWrite(segment_pins[0], HIGH); digitalWrite(segment_pins[1], LOW); digitalWrite(segment_pins[2], HIGH); digitalWrite(segment_pins[3], LOW); break;
    case 6: digitalWrite(segment_pins[0], LOW); digitalWrite(segment_pins[1], HIGH); digitalWrite(segment_pins[2], HIGH); digitalWrite(segment_pins[3], LOW); break;
    case 7: digitalWrite(segment_pins[0], HIGH); digitalWrite(segment_pins[1], HIGH); digitalWrite(segment_pins[2], HIGH); digitalWrite(segment_pins[3], LOW); break;
    case 8: digitalWrite(segment_pins[0], LOW); digitalWrite(segment_pins[1], LOW); digitalWrite(segment_pins[2], LOW); digitalWrite(segment_pins[3], HIGH); break;
    case 9: digitalWrite(segment_pins[0], HIGH); digitalWrite(segment_pins[1], LOW); digitalWrite(segment_pins[2], LOW); digitalWrite(segment_pins[3], HIGH); break;
    default: digitalWrite(segment_pins[0], LOW); digitalWrite(segment_pins[1], LOW); digitalWrite(segment_pins[2], LOW); digitalWrite(segment_pins[3], LOW); break;
  }
}

void handleRoot() {
  server.send(200, "text/html", R"rawliteral(
    <!DOCTYPE html>
    <html lang="en">
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>7-Segment Display Control</title>
        <style>
            body {
                font-family: Arial, sans-serif;
                display: flex;
                justify-content: center;
                align-items: center;
                height: 100vh;
                margin: 0;
                background-color: #f0f0f0;
            }
            .container {
                text-align: center;
                background: white;
                padding: 20px;
                border-radius: 10px;
                box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);
            }
            button {
                background-color: #007bff;
                color: white;
                border: none;
                padding: 15px 30px;
                text-align: center;
                text-decoration: none;
                display: inline-block;
                font-size: 16px;
                margin: 10px 2px;
                cursor: pointer;
                border-radius: 5px;
                transition: background-color 0.3s;
            }
            button:hover {
                background-color: #0056b3;
            }
        </style>
        <script>
            async function incrementCounter() {
                const response = await fetch('/increment', { method: 'POST' });
                if (response.ok) {
                    console.log('Counter incremented');
                } else {
                    console.error('Failed to increment counter');
                }
            }
        </script>
    </head>
    <body>
        <div class="container">
            <h1>Control the 7-Segment Display</h1>
            <button onclick="incrementCounter()">Increment Counter</button>
        </div>
    </body>
    </html>
  )rawliteral");
}

void handleIncrement() {
  counter = (counter + 1) % 10; // Increment counter and loop back to 0 after 9
  Segments(counter);             // Update display with the current counter value
  server.send(200, "application/json", "{\"success\": true}");
}

void setup() {
  Serial.begin(115200);

  // Initialize the segment pins
  for (int i = 0; i < 4; i++) {
    pinMode(segment_pins[i], OUTPUT);
  }
  Segments(counter); // Display initial value

  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Start the server
  server.on("/", handleRoot);
  server.on("/increment", HTTP_POST, handleIncrement);
  server.begin();
  Serial.println("Server started");
}

void loop() {
  server.handleClient();
}
