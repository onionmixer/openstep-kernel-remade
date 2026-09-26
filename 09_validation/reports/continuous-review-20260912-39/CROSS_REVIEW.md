# 코딩 전 검토와 root 재현

vm_contract_review27에게 raw 명령/공개 소스/합성 fixture 설계를 읽기 전용으로
검토받았다. root는 signed gate/SAR/byte ADD/unsigned 비교와 실제 표 바이트를
별도로 확인했다. 코드 작성 전 받은 다음 지적을 반영했다.

- delta<=1의 gate는 free PT/PD에만 적용되고 active aging은 계속된다.
- threshold 읽기는 active-empty/wired/PDE 검사를 앞선다.
- decision stop에서 age는 이미 바뀌었지만 last tail은 실행 전이다.

이어 받은 선택 PDE/이웃 PDE 구분과 wired 경로의 선행 pmap 역참조 지적도 반영했다.
fixture section을8MiB 경계에 맞추고 선택 PDE/이웃 PDE에 서로 다른 A 값을 넣었다.
이 fixture가 실제8KiB PT backing/object 상태를 구성했다는 뜻은 아니다.

후속 감사 검토에서 실제 관측 register와 기대 EA/flags의 연결 누락이 발견됐다.
root가 Python 메모리 내 기록 변조로 직접 확인한 통과 반례:

- delta256/age0 행의191276 EDX=0인데 threshold 읽기는 기존 주소로 유지.
- 같은 행의1912eb EAX=123400ff인데 기대 age0에 대한 CMP flags는 유지.
- 1912af EDX를 이웃 PDE 주소로 변경.
- checkpoint ESP/EIP 및 decision final ESP/EBP를 무관한 값으로 변경.

현재 실제 producer 기록에서 그 모순이 관찰된 것은 아니다. 감사 입력을 바꿨을 때
거부하지 못했던 누락이다. 이후 관측 EDX/EBX→threshold EA, EDX/ECX→선택PDE,
AL/DL/ESI→CMP, 모든 checkpoint의EIP/EBP/ESP 및 decision/error stack을 연결했다.
추가 대조를 포함한30개 변조가 거부됐으며 모든 정상/의도된 실패 사례를 다시 감사했다.

원본을 고치거나 기대 RF 조건을 낮추지 않았다. 모든CPU/GPR 의미 검증이 아니라
현재 모델이 소비하는 경계 피연산자·stack/PC 연결의 보강이다.

추가 검토에서191174의 EBX를256 대신512로 바꾸어도 CMP flags가 같아 통과하는
반례와1913db의 EBX=0이 실제 last 쓰기 기록과 모순되어도 통과하는 반례를 받았다.
root가 두 조건을 직접 재현했고, Python 계산에서 두 CMP의 검사 flags=20,
mask=2261이 같음을 확인했다. flags의 일치가 피연산자의 동일성을 뜻하지 않는다.

이에 두 checkpoint에서 EBX==raw_delta를 직접 요구하고 음성 대조에 추가했다.
최종32개 변조 거부와4,940행 재감사, 주요 산출물5개 재현을 root가 확인했다.
독립 검토자도 마지막 반례 거부와 정상 행을 읽기 전용으로 확인했으며 추가 필수
오류를 찾지 못했다고 보고했다. 그 의견을 전체 CPU 의미 검증의 증거로 쓰지 않는다.
