# 원본 pmap_update의 시간·active PT aging 경계

원본 mk-183.34.4의00191144 경로를 읽고 실행하여 시간 차이와 age byte의 경계를
조사했다. **합성 단일-node/빈 free queue의 분기 분석이며 실제 PT 제거 완료가 아니다.**
원본·공개 참고 소스·Ghidra/IDA DB/export·이전 보고서·07_kernel은 변경하지 않았다.
Ghidra 스킬로 원본 근거와 해석을 분리했고, 코딩 전 교차검토 및 root 재현을 수행했다.
계산·주소·해시·집계는 Python으로 수행했다.

## 확인한 동작

원본 byte 수준 근거는 [source-basis.json](source-basis.json), 실제 관찰은
[aging-cases.json](aging-cases.json), 선택 사례는 [boundary-examples.json](boundary-examples.json)이다.

| 조건 | 원본에서 관찰한 경계 |
|---|---|
| delta=1, age=8, present/unwired/unreferenced | age=9로 바꾸고 회수 분기에 도달한다. free PT/PD 회수 gate를 건너뛰는 것과 active aging은 별개다. |
| delta=8, age=4 | 새 age=12가 threshold=12와 같으므로 회수하지 않는다. |
| delta=256, age=0 | age는0으로 남고 threshold=32 이하이므로 회수하지 않는다. |
| delta=255, age=8 | 새 age=7이며 old>new 조건으로 회수 분기에 도달한다. |
| last=fffffffe, tick=0 |32-bit 차이는2다. 짧은 정상 wrap 자체는 음수 delta를 만들지 않는다. |
| last=1, tick=0 | signed delta=-1, index=-1로 표 직전001e25fc를 읽는다. 관찰값115는 인접 문자열 바이트이며 의도된 fallback 정책이 아니다. |
| 두 번째 PDE에만 A=1 | 선택된 첫 PDE의 A가0이면 두 번째 PDE의 A를 aging 판단에 사용하지 않는다. |

회수 분기 사례는 **001912f6 명령을 실행하기 전에 정지**한다. 이때 age 쓰기는
이미 완료됐지만 마지막 last 갱신은 아직 실행되지 않았다. 이를 실제 pmap_remove
실행이나 함수 정상 반환과 혼동하지 않는다.

## 산술·자료구조 근거

원본 SUB의32-bit 결과를 signed로 비교하고 SAR3으로 index를 만든다. aging 표는
001e2600의{8,12,16,24,32}, n은001e2614의5다. 상한 초과 시 마지막 원소를
선택하지만 음수 index를 막는 하한 검사는 없다. threshold 읽기는 active queue가
비었는지, wired인지, PDE가 present인지 확인하기 전에도 실행된다.

age는 extension+1d의 byte다. 덧셈에서 delta의 하위 byte만 사용하고,
old age>new age 또는 new age>threshold이면 회수 분기를 고른다. 모든32-bit
delta에서 경과량을 포화 덧셈한다고 해석하면 안 된다. 초기 last=0은 미초기화 표식으로
쓰이며, 실제 wrap 뒤 last가0이 되면 다음 호출의 초기화 분기에 영향을 준다.
이는 원본 제어 흐름에 따른 해석이며 실제 연속 scheduler 실행은 이번에 재현하지 않았다.

extension+1a의16-bit wired_count가 nonzero이면 age만0으로 만든다. NP에서도
age만0으로 만든다. present/unwired/referenced일 때에만 선택 PDE의 A를 지우고
age를0으로 만든다. wired 경로도 pmap→directory 역참조는 먼저 실행하지만 PDE byte
읽기는 하지 않는다. 두 PDE 중 선택되지 않은 이웃 값은 유지됨을 대조했다.

Darwin0.1의 `kernel/machdep/i386/pmap.c` pmap_update 및 `pmap_private.h` pg_exten
선언은 해당 연산·필드 폭의 대응 근거다. 전체 함수/구조체/컴파일러 ABI가 동일하다는
확정은 아니다. 원본 `_recompute_priorities`의00163d97에는 sched_tick의 INC,
`_sched_init`의00162e4d에는0 초기화가 있다. 실제 시간 진행/호출 간격/동시성에서
음수 delta가 도달 가능한지까지 입증하지 않았으며, 고의 경계 입력을 실제 장애로
확대 해석하지 않는다. 실제 GCC2.7 컴파일 검증도 별도로 남는다.

## 시험 범위와 결과

[aging-summary.json](aging-summary.json), [aging-audit.json](aging-audit.json)에
4,940행을 보존했다. age 모든 값과 선택 양의 delta 경계를 교차한4,608행에
시간/빈 active/flags·필드 폭/이웃 PDE 대조를 더했다. 정상RET452행, 회수 결정에서
중단4,484행, 명시적인 unmapped read 실패4행이다. 실패를 반환 성공으로 바꾸지 않았다.
원본 instruction head316,022개와 쓰기44,674개를 기록했다.

음수 index의 표 밖 읽기 또는 시도는20행이다. 그중 큰 음수 차이의4행은 flat UC
mapping 밖 접근으로 실패했다. 예를 들어 signed MIN delta의 operand offset은
c01e2600이며, DS.base=c0000000을 가정한32-bit linear 주소는801e2600이다.
**현재 flat UC에서의 unmapped 실패는 원래 OPENSTEP paging의 page fault 증명이 아니다.**

[audit_aging.py](audit_aging.py)는 독립적인 modular arithmetic 모델로 원본 분기
경로 전체, 선택 CMP flags/관측 피연산자, threshold EA/값, pmap/선택 PDE 읽기,
stack/global/age/PDE 쓰기 순서와 값, 최종 stack/callee-saved 상태를 대조한다.
일반 모든 GPR·모든CPU 명령·hardware A-bit 생성이나 실제TLB를 검증하는 실행기는 아니다.
원본 TEXT/DATA/OBJC만 flat 영역에 로드했으며 합성 queue와 pmap/extension은 실제
boot/object/zone 할당으로 생성한 상태가 아니다.

[negative-controls.json](negative-controls.json)은 기록 변조32개를 거부했다.
교차검토에서 발견한 관측 register→EA/CMP 및 stack/PC 연결 누락은 root가 직접
재현한 후 보완했다. 이것은 record 변조 검사이며 실제 CPU fault 주입이 아니다.
[reproducibility.json](reproducibility.json)은 같은 원본/Unicorn backend 재실행에서
주요 산출물5개의 해시가 동일함을 확인한 결과다.
다른 CPU 엔진이나 물리 CPU의 독립 동등성 증거로 쓰지 않는다.

```sh
python3 -B verify_basis.py
python3 -B run_aging.py
python3 -B audit_aging.py
python3 -B test_aging.py
python3 -B reproduce.py
python3 -B checkpoint_review.py
```

## 남은 분석

이번 회수 결정에서 원본 제거 함수로 실제 진입한 뒤 PT/PG/PV/queue/소유권이
어떻게 변하는지 연결해야 한다. free PD의 nonempty/alloc_count 분기와 실제 backing
회수, 실제 scheduler tick 진행/호출 간격/경합, 다중 active node, 실제 page-table A bit와
TLB/cache, 원본 GC→fault→handler→IRETD→retry도 남아 있다.
[이전 전체 잔여 의무](../continuous-review-20260912-36/OPEN_ITEMS.md)를 축소하지 않는다.
현재 경계와 나머지 의무는 [OPEN_ITEMS.md](OPEN_ITEMS.md)에 구분했다.
