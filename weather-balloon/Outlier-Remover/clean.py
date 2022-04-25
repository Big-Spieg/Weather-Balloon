import numpy as np
from scipy import stats
import os
import sys

try:
  SMOOTHNESS = int(sys.argv[1])
  THRESHHOLD = float(sys.argv[1])
except:
  print("python3 clean.py <smoothness (default 20, must be integer)> <threshold (default 2.5, can be float)")
  SMOOTHNESS = 20
  THRESHHOLD = 2.5

def remove_outliers(an_array, threshhold):
  mean = np.mean(an_array)
  standard_deviation = np.std(an_array)
  distance_from_mean = abs(an_array - mean)
  max_deviations = threshhold
  not_outlier = distance_from_mean < max_deviations * standard_deviation
  no_outliers = an_array[not_outlier]
  return no_outliers

def average(numbers):
  total = 0
  for i in numbers:
    total+=i
  # print(numbers, total/len(numbers))
  return total/len(numbers)

for file in os.listdir('./data'):
  _ = open("data/"+file).read().split()
  data = []
  for i in _:
    data.append(float(i))
  
  a = np.array(data)
  a_no_outliers = remove_outliers(a, THRESHHOLD)
  print(a_no_outliers)
  
  count = 0
  smooth_data = []
  for i in a_no_outliers:
    if count<SMOOTHNESS:
      smooth_data.append(i)
    else:
      _ = []
      for i in range(count-SMOOTHNESS, count):
        _.append(a_no_outliers[i])
      # print(_)
      smooth_data.append(average(_))
    count+=1
  for i in smooth_data:
    print(i)
  
  with open("output/"+file, "w") as output:
    for i in smooth_data:
      output.write(str(i)+"\n")
    