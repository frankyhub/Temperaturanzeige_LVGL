
<a name="oben"></a>

<div align="center">

|[:skull:ISSUE](https://github.com/frankyhub/Temperaturanzeige_LVGL/issues?q=is%3Aissue)|[:speech_balloon: Forum /Discussion](https://github.com/frankyhub/Temperaturanzeige_LVGL/discussions)|[:grey_question:WiKi](https://github.com/frankyhub/Temperaturanzeige_LVGL/wiki)||
|--|--|--|--|
| | | | |
|![Static Badge](https://img.shields.io/badge/RepoNr.:-%2088-blue)|<a href="https://github.com/frankyhub/Temperaturanzeige_LVGL/issues">![GitHub issues](https://img.shields.io/github/issues/frankyhub/Temperaturanzeige_LVGL)![GitHub closed issues](https://img.shields.io/github/issues-closed/frankyhub/Temperaturanzeige_LVGL)|<a href="https://github.com/frankyhub/Temperaturanzeige_LVGL/discussions">![GitHub Discussions](https://img.shields.io/github/discussions/frankyhub/Temperaturanzeige_LVGL)|<a href="https://github.com/frankyhub/Temperaturanzeige_LVGL/releases">![GitHub release (with filter)](https://img.shields.io/github/v/release/frankyhub/Temperaturanzeige_LVGL)|
|![GitHub Created At](https://img.shields.io/github/created-at/frankyhub/Temperaturanzeige_LVGL)| <a href="https://github.com/frankyhub/Temperaturanzeige_LVGL/pulse" alt="Activity"><img src="https://img.shields.io/github/commit-activity/m/badges/shields" />| <a href="https://github.com/frankyhub/Temperaturanzeige_LVGL/graphs/traffic"><img alt="ViewCount" src="https://views.whatilearened.today/views/github/frankyhub/github-clone-count-badge.svg">  |<a href="https://github.com/frankyhub?tab=stars"> ![GitHub User's stars](https://img.shields.io/github/stars/frankyhub)|
</div>


## Temperaturanzeige_LVGL

![Bild](pic/Temperaturanzeige.png)


## Button, Toggle, Slider


![Bild](pic/Button.png)

## Verdrahtung

| TFT LCD | ESP32 | 
| -------- | -------- | 
| T_IRQ	|   GPIO 36| 
| T_OUT	|   GPIO 39| 
| T_DIN| 	  GPIO 32| 
| T_CS	 |  GPIO 33| 
| T_CLK	 |  GPIO 25| 
| SDO(MISO)| 	GPIO 12| 
| LED	|   GPIO 21| 
| SCK	|   GPIO 14| 
| SDI(MOSI)| 	GPIO 13| 
| D/C| 	  GPIO 2| 
| RESET| 	EN/RESET| 
| CS	|   GPIO 15| 
| GND	|   GND| 
| VCC	|   5V (or 3.3V)*| 
| -------- | -------- | 
| *| | 
| VCC = 5V | J1=OPEN| 
| VCC = 3.3V | J1=CLOSE| 
| -------- | -------- | 
---


| DS18B20 | ESP32 | Pullup | 
| -------- | -------- | --------- | 
| Vcc|   3,3V|  | 
| Signal	|   GPIO 27| 4,7k | 
| GND | 	  GND|  | 
| -------- | -------- | ------ | 
---

![Bild](pic/DS18B20.png)

---


<div style="position:absolute; left:2cm; ">   
<ol class="breadcrumb" style="border-top: 2px solid black;border-bottom:2px solid black; height: 45px; width: 900px;"> <p align="center"><a href="#oben">nach oben</a></p></ol>
</div>  

---



