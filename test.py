import psutil
import requests

cpu_red_threshold = 25

while True:
    cpu_usage = psutil.cpu_percent(interval = 1)
    print("CPU usage is", cpu_usage)
    if cpu_usage > cpu_red_threshold:
        requests.get("http://blynk-cloud.com/tVibLYhKjpFtuaI5Hr927L5bhQH5pSRl/update/D5?value=0")
        requests.get("http://blynk-cloud.com/tVibLYhKjpFtuaI5Hr927L5bhQH5pSRl/update/D4?value=1")
        requests.get("https://api.telegram.org/bot1539393749:AAG6KTpCdfJ8yN6ZPu5u1DOoMou1-EOypAA/sendMessage?chat_id=@iottheft&text=Usage Exceeded")
    else:
        requests.get("http://blynk-cloud.com/tVibLYhKjpFtuaI5Hr927L5bhQH5pSRl/update/D5?value=1")
        requests.get("http://blynk-cloud.com/tVibLYhKjpFtuaI5Hr927L5bhQH5pSRl/update/D4?value=0")
	h1 = requests.get("http://blynk-cloud.com/tVibLYhKjpFtuaI5Hr927L5bhQH5pSRl/get/V5")
	# mV=h1.content
	mV=h1.text
	AV=int(mV[2]+mV[3]+mV[4])
	MILLIV=AV/1024
	MILLIV=MILLIV*3300
	celsius=MILLIV/10
	if celsius > 30:
		requests.get("https://api.telegram.org/bot1539393749:AAG6KTpCdfJ8yN6ZPu5u1DOoMou1-EOypAA/sendMessage?chat_id=@iottheft&text=Server overheated. Current temperature is: ")