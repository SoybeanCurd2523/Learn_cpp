# Python3 샘플 코드 #


import requests

url = 'http://api.data.go.kr/openapi/tn_pubr_public_lbrry_api'
params ={'serviceKey' : 'rfj3FuNmjqipIT1pkfMn41WhlqX+zvIbHZ3I4Dm6iYqAhAsZn1UB4hnVkjGQfv7pPg+XvwTKGoRk3gSkrVvNoA==', 'pageNo' : '0', 'numOfRows' : '100', 'type' : 'xml', 'LBRRY_NM' : '꿈이있는나무작은도서관', 'CTPRVN_NM' : '전라북도', 'SIGNGU_NM' : '전주시', 'LBRRY_SE' : '작은도서관', 'CLOSE_DAY' : '매주일요일, 법정공휴일', 'WEEKDAY_OPER_OPEN_HHMM' : '10:00', 'WEEKDAY_OPER_COLSE_HHMM' : '18:00', 'SAT_OPER_OPER_OPEN_HHMM' : '10:00', 'SAT_OPER_CLOSE_HHMM' : '15:00', 'HOLIDAY_OPER_OPEN_HHMM' : '00:00', 'HOLIDAY_CLOSE_OPEN_HHMM' : '00:00', 'SEAT_CO' : '100', 'BOOK_CO' : '12574', 'PBLICTN_CO' : '0', 'NONE_BOOK_CO' : '0', 'LON_CO' : '5', 'LON_DAYCNT' : '14', 'RDNMADR' : '전라북도 전주시 완산구 새터로 122-11', 'OPER_INSTITUTION_NM' : '(사)물댄동산', 'PHONE_NUMBER' : '063-229-6511', 'PLOT_AR' : '', 'BULD_AR' : '347', 'HOMEPAGE_URL' : '', 'LATITUDE' : '35.8351264', 'LONGITUDE' : '127.1206937649', 'REFERENCE_DATE' : '2020-08-31', 'instt_code' : '4640000' }

response = requests.get(url, params=params)
print(response.content)