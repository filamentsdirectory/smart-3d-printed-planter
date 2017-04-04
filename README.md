Filaments.directory has teamed up with renowned 3D designer Augustin Flowalistik to create a 3D printable planter that will change the way you think about the potential of 3D printing. This functional device is equipped with an IoT module that will monitor the humidity of your plant’s soil, while also sprucing up the look of your home. 

Our DIY planter will measure humidity every 15 minutes, sending the data directly to the Adafruit cloud. Using an IFTTT, you can connect to the Adafruit API and constantly keep up-to-date with the latest value. The IoT module even allows you add actions to automate the reception of this data through SMS messaging, Twitter, and others.     

We decided to employ the Adafruit Feather HUZZAH ESP8266 board due to its battery powered option, affordability, and accessibility with the Arduino platform. This project is perfect for those looking to find functional uses for their 3D printer, or those wishing to add some IoT capabilities to their home. 

The design will be free to download (under GPL v3 licence for the source code). All you need to do is register on the website (https://www.filaments.directory) to obtain the STL file for the planter. With the help of Augustin Flowalistik, we’ve ensured that the project is compelling on many levels. 

For starters, the 3D printed planter is exceptionally functional, allowing you to use your FDM 3D printer for a project that is actually useful. The planter itself has a marvelous design, and will have your friends and family begging you to tell them where you bought it. The IoT module makes the planter a smart device, and is flexible thanks to compatibility with open source hardware and software. The entire project will only take a few hours to complete, and will cost you less than $50 to complete.    

The list of required materials is as follows:
 
1x - Adafruit Feather HUZZAH ESP8266
1x - lithium ion battery 
1x - Resistor 100 ohm
1x - Resistor 100 kohm
1x - Thermoretractable tubing
1x - 22 AWG wire

WARNING: Do not put water on your lithium ion battery otherwise it will explode. This planter is specifically designed for home use, it’s not safe for the outdoor environment.

To produce the planter, you only need these three tools:
-Filament (the higher the quality, the better the outcome!)
-FDM 3D printer
-Soldering Iron

Here are the steps to creating your own 3D printable smart planter:
- Download the STL file and print the planter
- Install the Arduino platform and dependencies (if you haven’t done this already)
- Change the WiFi access and Adafruit API in the source code provided on GitHub
- Program the electronics (It's pretty similar to https://learn.adafruit.com/adafruit-io-basics-esp8266-arduino/using-arduino-ide)
- Stick the electronics on the back of the 3D printed planter
- Enjoy your new functional IoT device!

The data flow starts at Huzzah before travelling through WiFi to the Adafruit Cloud. This data is sent to the IFTTT and can be connected to any device that is compatible with the Adafruit API. 

The ultimate goal of this project is to show the functional capabilities of desktop 3D printing, utilize IoT to its fullest potential, and offer you a DIY product that will improve the design of your home or office.   

If you’re wondering what filament will work best for your needs, head to Filaments.directory and scroll through our informative database. 

We want to send a special thanks to Agustin Flowalistik for his help on this project. Check out more of his design work on his website. 
