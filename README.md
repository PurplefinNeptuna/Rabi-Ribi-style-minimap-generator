# Rabi-Ribi-style-minimap-generator
Generate tiles for minimap\
![Imgur](https://i.imgur.com/4UyrS0X.png)

## Usage with example
### Create minimap image with black as border color and white as fill color
```
MinimapGen
```
#### Result:
![Imgur](https://i.imgur.com/EGtgHW8.png)
### Create minimap image with desired border color and white as fill color
```
MinimapGen BorderR BorderG BorderB
```
Border(R/G/B) : Color(Red/Green/Blue) of border in decimal integer [0-255]
#### Example:
```
MinimapGen 255 0 0
```
#### Result:
![Imgur](https://i.imgur.com/hbQoIxd.png)
### Create minimap image with desired border and fill color
```
MinimapGen BorderR BorderG BorderB FillR FillG FillB
```
Border(R/G/B) : Color(Red/Green/Blue) of border in decimal integer [0-255]\
Fill(R/G/B) : Color(Red/Green/Blue) of fill in decimal integer [0-255]
#### Example:
```
MinimapGen 255 0 0 0 255 0
```
#### Result:
![Imgur](https://i.imgur.com/B20RFVS.png)
## Generated image name details
![Imgur](https://i.imgur.com/Bz2WpQT.png)
