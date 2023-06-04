# -*- coding: utf-8 -*-

import matplotlib.pyplot as plt

# 시간과 제어 출력 데이터를 가정하고 리스트로 초기화
time = [0, 1, 2, 3, 4, 5]  # 시간 데이터 (예: 초 단위)
control_output = [0, 0.5, 0.9, 1.2, 1.1, 0.8]  # 제어 출력 데이터

# 그래프 그리기
plt.plot(time, control_output, 'b-', label='Control Output')
plt.axhline(y=0, color='k', linestyle='--')  # x축과 수평선 그리기
plt.axhline(y=1.1, color='r', linestyle='--')  # 목표 값에 해당하는 가로선 그리기

# 축 레이블과 범례 설정
plt.xlabel('Time')
plt.ylabel('Control Output')
plt.legend()

# 그래프 표시
plt.show()
