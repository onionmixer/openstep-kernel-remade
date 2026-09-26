# 신중한 추가 검토 23 — copyout 순서와 paging fault 관찰

## 판정

분리된 합성 사용자 매핑에서 `_copyout`/`_copyoutmsg`의 정상 호출 4,032건을
검증했다. fresh fixture의 페이지 보호 조건 56건에서는 정상/예외 결과와 메모리
상태가 예상과 일치했고, 그중 paging fault 28건을 CPU 모델에서 관찰했다.

이번에 확인한 tail 쓰기 순서는 **원본 동작이며 canonical C에도 이미 보존되어 있다.**
새로운 디컴파일 누락 또는 원본 커널 결함으로 판정하지 않는다. 복원 시 최종 바이트만
맞추고 오류 전 쓰기 순서를 바꾸지 않아야 한다는 구체적인 검증 근거다.

원본·해석·Python 모델·실행 관찰을 Ghidra 스킬의 원칙에 따라 분리했다.
모든 계산은 Python으로 수행했다. 코딩 전 독립 Codex 교차검토를 사용했지만,
의견은 원본 명령과 독립 계산으로 재확인한 뒤에만 채택했다.

## 결과

| 범위 | 결과 |
|---|---:|
| 전체 정상 copyout/copyoutmsg 호출 | 4,032 |
| source 페이지 경계 횡단 | 864 |
| destination 페이지 경계 횡단 | 864 |
| 양쪽 모두 경계 횡단 | 240 |
| 길이 0 대조 | 288 |
| 잘못된 목적지/root 쓰기를 구별하는 정상 사례 | 3,744 |
| 정상 경로에서 실행한 FS store 위치 | 24 |
| 정상 진입의 정렬 조건상 실행하지 않는 FS store 위치 | 2 |
| caller destination 슬롯 변경 사례 | 864 |
| fresh paging 조건 시험 | 56 |
| 관찰된 vector14 paging fault | 28 |
| 그중 일부 바이트를 기록한 뒤 fault | 24 |
| 높은 tail offset을 먼저 쓰려다 fault | 12 |

경계 횡단 항목은 서로 겹치며 독립 합계로 더하지 않는다. 정상 결과와 paging
조건 결과도 scope가 다르다. 실제 커널 부팅이나 모든 입력의 증명으로 집계하지 않는다.

## 정상 복사 시험

report22의 검증된 입력 로더/초기 paging 및 private root/table fixture를 재사용했다.
CS는 flat `0x48`, DS/ES/SS는 높은 base의 `0x10`, FS는 flat `0x50`이다.
따라서 실제 최종 커널 CPU 상태 전체가 아니라 의도적인 혼합 세그먼트 시험이다.

원본 root 선택 구간으로 A/B/B/A를 선택했다. 각 함수에서 source와 destination을
독립적으로 정렬/페이지 경계 위치에 놓고 길이 0/1/2/3/4/7/15/16/17/19/31/32/63/64를
검사했다. 커널 source는 높은 DS 선형 주소로 읽고, 사용자 destination은 FS로 쓴다.
source와 destination 오프셋이 같아도 실제 backing 물리는 서로 다르다.

통과 조건:

- 접근 범위의 low/high 매핑을 Python page walker로 확인.
- active 사용자 전체 버퍼의 기대값, inactive 사용자 버퍼 및 커널 source 전체 버퍼 불변.
- 반환값·반환주소·ESP·callee-saved 레지스터와 원본 recover 동작.
- 실제 FS store의 PC·선형 주소·폭·값·순서와 독립 operand replay.
- caller 인자는 원본 명령에 따른 별도 Python 모델과 대조. copyout의 destination
  슬롯 변경은 허용하고, msg의 local 처리와 구분.
- 방문한 copy 명령 backing 바이트를 실행 후 원본 파일 바이트와 대조.

guard 검사는 지정한 버퍼 범위다. 전체 물리 RAM 쓰기 전수 검사나 실제 instruction
fetch 변환의 독립 증명이라고 부르지 않는다. 단일 store의 페이지 횡단을 포함하는
정상 사례가 있지만 fault 시험에서는 그 조건을 의도적으로 제외했다.

원본의 FS store는 각 함수에 13곳이며 REP 명령은 없다. `0x00189da9`와
`0x00189f51`은 정상 진입의 source 정렬 잔여값으로 계산한 dword 반복 횟수가
0이어서 실행되지 않는다. report02의 원본 흐름 근거와 Python 산술을 재확인했으며,
중간 PC에 임의 진입시켜 정상 coverage를 늘리지 않았다.

## 페이지 보호 조건과 fault 직전 쓰기

각 조건마다 새 fixture를 만들었다. 낮은 destination PTE의 RO/NP 조건은 해당
root를 선택하기 전에 설치하고, 높은 kernel mapping이 그대로임을 확인했다.
첫 페이지는 read-only 또는 zero-length 대조이고, not-present 조건은 두 번째
페이지에만 적용했다. 따라서 root 선택 검사에 쓰는 첫 페이지 scalar 읽기는 유효하다.

WP=0/1 대조는 합성 EBX 값을 원본 `MOV CR0,EBX` 명령에 제공해 설정했다.
변경 전후 CR0를 기록했다. WP=0을 실제 OPENSTEP 부팅 상태라고 주장하지 않는다.
각 fixture에서 PG/PE 및 초기 WP 상태와 이 시험에 필요한 CR4 조건을 확인했다.

source는 fault 사례에서 dword 정렬 상태로 고정했다. 대표 사례는 다음과 같다.

| 원본 copyout의 예정 쓰기 | 결과 |
|---|---|
| `0x00189dfc` → `0x00600fee`, dword | 기록됨 |
| `0x00189e02` → `0x00600ff2`, dword | 기록됨 |
| `0x00189e09` → `0x00600ff6`, dword | 기록됨 |
| `0x00189e10` → `0x00600ffa`, dword | 기록됨 |
| `0x00189e47` → `0x00601000`, byte | vector14, CR2=`0x00601000` |

이는 길이19, destination=`0x00600fee`, 두 번째 페이지 NP인 조건이다.
앞선 16바이트는 기록됐지만 `0x00600ffe`와 `0x00600fff`는 아직 기록되지 않았다.
tail offset2를 먼저 쓰기 때문에, 단조 증가 복사라고 가정한 18바이트 prefix와 다르다.
copyoutmsg의 대응 tail 순서도 같은 방식으로 확인했다.

부분 쓰기의 근거는 전체 backing 버퍼 비교, 원본 완료 전 store operand replay,
독립 예상 상태의 일치다. fault 직전 pending store와 완료된 store를 구분했고,
선택한 fault store 및 앞선 store가 페이지를 가로지르지 않음을 확인했다.

각 fault에서 vector14·EIP·CR2·recover 포인터를 기록하고 즉시 중단했다.
**실제 IDT/trap handler, recovery helper, IRETD는 실행하지 않았다. PF error-code
비트도 수집·검증하지 않았다.** 따라서 이를 실제 커널의 EFAULT 반환이나 복구 완료로
해석하지 않는다. fault 시 recover는 아직 원본이 설정한 값으로 남아 있다.

## hook 주소와 canonical C 해석

이번 backend에서 memory-write hook 주소는 물리 주소로 관찰된다. 예를 들어
A의 선형 `0x00600fee` store는 hook에서 물리 `0x00900fee`로 기록된다.
Python 물리 변환 후 PC·주소·폭·값·순서를 대조했다. callback 주소와 선형 주소를
그대로 비교해 오류로 판정하지 않았다.

fault pending store의 hook이 없는 것은 보조 관찰일 뿐 commit의 독립 증명은 아니다.
CPU 모델 callback을 실제 bus cycle이나 하드웨어 원자성의 증거로 부르지 않는다.

canonical C도 tail offset2 store 뒤 offset1 label로 이동하고 마지막 offset0을 쓴다.
이 부분은 디컴파일 결과에서 빠진 것이 아니다. 남은 문제는 원본의 주소 공간·권한·
예외 효과까지 복원 규약과 구현에서 보존하는 것이다.

## 보존·재현·잔여 의무

[코딩 전 계획](PLAN.md), [Codex 교차검토와 독립 재확인](CROSS_REVIEW.md),
[잔여 분석 의무](OPEN_ITEMS.md)를 별도 기록했다. 원본 바이너리·기존 Ghidra/IDA DB,
기존 보고서와 `07_kernel`은 변경하지 않았다.

```sh
python3 -B 09_validation/reports/continuous-review-20260911-23/copyout_review.py
python3 -B 09_validation/reports/continuous-review-20260911-23/verify_artifacts.py
```

[실행 코드](copyout_review.py), [정상 호출 원시 결과](normal-copyout.json),
[paging 조건 원시 결과](paging-copyout.json), [집계·coverage 결과](copyout-review.json),
[실행 전 보존 검사](preservation-before.json), [입력 해시](input-hashes.json),
[보존 검사 코드](verify_artifacts.py), [최종 보존 검사](verification.json),
[산출물 해시](artifact-hashes.json).

현재 대상 사용자 buffer의 물리 페이지들은 연속 배치다. 비연속 물리 페이지,
실제 사용자 pmap 생성·전체 문맥 전환·최종 CS·CPL3 권한·descriptor limit·POP FS,
실제 예외 프레임/복구, 비동기 interrupt와 하드웨어 TLB/cache는 별도 의무로 남긴다.
GCC 2.7 구현·빌드·부팅 또는 전체 분석 완료로 판정하지 않는다.
