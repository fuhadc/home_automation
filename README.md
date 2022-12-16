# Here is an example of Arduino code that you can use to control a light bulb using a NodeMCU board and a REST API:

This code sets up a WiFi connection using the ESP8266WiFi library, and creates a simple web server using the ESP8266WebServer library. It defines a function called handleRoot that is called when the server receives a request to the root URL. This function toggles the state of the light bulb by flipping its current state using the digitalWrite function.

To use this code, you will need to replace your-ssid and your-password with the SSID and password for your WiFi network. You will also need to set the pin for the light bulb using the lightPin variable.

To create a REST API for your home automation project using NodeMCU and Arduino, you can use a framework such as Flask or Django, or you can create a simple API using the Python Requests library.

Here is an example of how you might create a simple API using the Python Requests library:
```python

import requests

def toggle_light():
    url = "http://YOUR_NODEMCU_IP/toggle"
    response = requests.get(url)
    if response.status_code == 200:
        return True
    else:
        return False


```

flask implementation

```python

from flask import Flask, request
import requests

app = Flask(__name__)

@app.route('/toggle', methods=['GET'])
def toggle_light():
    url = "http://YOUR_NODEMCU_IP/toggle"
    response = requests.get(url)
    if response.status_code == 200:
        return "Light toggled", 200
    else:
        return "Error", 500

if __name__ == '__main__':
    app.run()
```
his code defines a Flask app with a single route, /toggle, that sends an HTTP GET request to the NodeMCU board at the specified IP address and URL. The NodeMCU code should include a handler for this URL that toggles the state of the light bulb.

To use this code, you will need to install Flask and the Python Requests library, and replace YOUR_NODEMCU_IP with the IP address of your NodeMCU board. You can find the IP address by printing it to the serial monitor in the Arduino IDE.

To deploy this API to a hosting service, you will need to follow the instructions provided by the hosting service to upload the code and set up the web server