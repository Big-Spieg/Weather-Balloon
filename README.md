# Weather-Balloon

Instructions:


### Data Collection
Connect the data wires of the sensors to A0-A-3. Install this code on the Arduino (make sure to sync RTC for accurate results). Data collection rate is 5000ms.


### Cleanup
Due to the innacurate and inconsistent results from the sensors, I created some code in class to clean it up. Place the data from each sensor (would clean using google sheets), in the /weather-balloon/Outlier-Remover/data directory. 
```
pip3 install -r requirements.txt

python3 clean.py <SMOOTHNESS (number of elements to gradient average)> <THRESHOLD (variable to remove outliers)>
```
The output should appear in the /output directory and you can import that into google sheets.


### Results:

##### Mean throughout the experiment:
```
Sunbum	6.622
Aus Gold	10.664
Bare Republic	4.73
Control	36.722
```
##### Zinc/Titanium Oxide Percentages:
```
Bare Republic 18% Zinc Oxide Sunscreen	
Titanium Dioxide:	0.00%
Zinc Oxide	18.20%
Sun Bum Mineral SPF 30 Non-Tinted Sunscreen Face Lotion	
Titanium Dioxide:	5.30%
Zinc Oxide	2.40%
Australian Gold Botanical Sunscreen Mineral Lotion SPF 50	
Titanium Dioxide:	4%
Zinc Oxide:	4%
```
