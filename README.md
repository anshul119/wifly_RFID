wifly_RFID
==========
This is an Arduino Program which will help you read RFID tag serially from an RFID tag and transfer it over web Via wifi using WiFly shield.

<h3>Things you need</h3>

1. RFID reader, anyone which reads tag serrially would do. There are lot of options on web.
2. WiFly RN-XV Module. You can get one here from <a href="https://www.sparkfun.com/products/10822">Sparkfun</a>.
3. Arduino. Obviously you need an Arduino.


<h3>Connection</h3>

Though you can make your own connections and alter the code accoring to that. But these are the connection I used:

1. Wifly RX- 12
2. Wifly TX- 13
3. RFID RX- 8
4. RFID TX- 9

You can find the RX TX of your RFID reader and Wifly shield in their respectice datasheets.

<h3>Libraries</h3>

1. Software Serial (comes with your Arduino IDE)
2. <a href="https://github.com/harlequin-tech/WiFlyHQ">WiFlyHQ</a>

Change the SSID and pass to your own. Change the domain and the POST/GET request below and you are good to go. In case of any query. Please drop a query.
