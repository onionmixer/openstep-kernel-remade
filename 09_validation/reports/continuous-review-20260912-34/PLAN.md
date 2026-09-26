# 보고서34 계획 — 신규 wired PT backing의 실제 회수

상태: 코딩 전 교차검토 및 원본 검토 후 실행/감사를 진행한다. 아직 완료 보고서가 아니다.
보고서33과 모든 이전 원본·입력·DB/export·보고서, `07_kernel`은 변경하지 않는다.
계산/주소/계수/해시는 Python만 사용한다. GCC 2.7 구현은 아직 시작하지 않는다.

## 출발점과 provenance

확정33과 같은 실제 fault/write/remove를 새 실행해 live CPU 상태를 이어간다.
확정33의 함수를 새 로컬 helper로 기계 복제하되 이전 save/main을 실행하지 않는다.
helper는 case에서 latest 파일 쓰기를 제거하고 `(uc, result)`를 반환하도록만 바꾼다.
Python으로 허용한 변환 외 차이가 없는지 검증한다. frozen32 prefix 및 frozen33의
동일 scenario와 정확 비교하며 원본/manifest를 사전에 검증한다.

새 GC 입력은 caller stack/ABI registers와 sched_tick/이전 tick, 유효한 PD free queue
sentinel 및 계수로 한정한다. 어떤 kernel/page/map/PTE 상태도 맞추기 위해 보정하지 않는다.
진입 이후 mock/patch/API memory correction/별도 CR3 reload 없이 `191144`를 실행한다.

## 원본과 독립 검토에서 도출한 경로

- last가 0이면 `19115c`가 tick으로 초기화하므로 tick만 증가시켜 GC를 강제할 수 없다.
  nonzero last와 delta>1 조건, 초기 호출/경계 delta에서의 미회수 동작을 구분한다.
- free PT와 PD free는 다르다. 이번 free PT 한 개 회수 뒤 PD free와 active PT가
  유효한 empty sentinel인지 확인한다. PD 회수/active aging은 별도 미검증이다.
- `1911b9` PT descriptor의 EXT backlink 제거 → `1911c8` extension zfree →
  `1911df` kmem_free → map 삭제 → `176458` vm_fault_unwire → `17647c`
  vm_object_page_remove → `179be4` pmap_remove_all → `179c08` vm_page_free.
- 뒤의 `1764b2` pmap_remove는 이미 NP인 KVA를 처리한다. 해당 중복 제거가 계수를
  다시 감소시키지 않아야 한다.
- `17365b`의 물리 조회는 PT segment→PG를 실제 실행한다. pmap_remove_all의
  wired 검사 전에 KVA의 HW PTE wired bit가 해제되어야 한다.
- PG wire가 마지막으로 해제되면 active tail에 잠시 들어갔다가 free queue로 이동한다.
  DATA의 queue.next도 중간에는 바뀐다. DATA의 payload/dirty/object와 최종 active
  상태는 보존하지만 queue 링크 전체 과정 불변을 요구하지 않는다.
- KO ref2→1이므로 object 자체는 존속한다. GC 전체 동안 KO lock을 합성 보유하면
  deallocate에서 교착한다. 실제 map/queue/hash/zone/KP/cache locking을 관찰한다.
  kernel-object page_remove 호출에서 KO lock이 어떤 상태인지 별도로 기록하며,
  일반 vm_page_free caller 예제의 lock 전제를 무조건 이 경로에 강제하지 않는다.
- PG 반환에는 zero 실행이 없다. PT 내용이 이미 0인 것과 zero routine 실행을
  구별한다. free된 PG/EXT/map entry 잔존 필드를 임의로 0으로 기대하지 않는다.

## 검증 gate

먼저 단일 진단으로 live continuation의 새 메모리 접근/전제 누락을 확인한다.
이어 입력 행렬과 tick gate 경계 대조를 실행한다. 독립 감사는 원본 Mach-O decoder,
trace/쓰기 기록/전체 캡처 메모리 replay, 전역/queue/lookup/map/object/PV/zone/PTE의
중간·최종 모델을 대조한다. 증거 훼손 대조와 새 실행 재현 및 원본/이전 보고서
보존 검증까지 끝나야 확정한다. 진단 실행만으로 성공 보고서를 만들지 않는다.

native CPU/IDT/실제 TLB/cache·전체 scheduler/boot/memory discovery·모든 ownership,
자원 부족/경합/PD/aging/pager/COW 경로와 실제 GCC 2.7 빌드·부팅/후속 아키텍처
등의 전체 의무는 그대로 유지한다.

## 감사기 반례를 반영한 추가 계획

독립 검토자가 제시한 CALL 반환값/stack slot 조작과 추가 PTE 쓰기를 root가
Python으로 재현했다. checkpoint raw/cursor/walk까지 일관되게 조작하면 기존
쓰기 replay만으로 거부하지 못했다. 보완 코딩 전에 검토자의 수정 설계 검토를 받았다.

- ESP/EBP를 원본 명령별 추적하고 CALL의 실제 저장값·위치와 RET의 실제 읽기값을
  연결한다. PUSH/CALL 누락·중복과 caller return slot 덮어쓰기를 거부한다.
- 명령당 write 개수/폭을 opcode와 operand 위치에서 판정한다. Capstone access
  metadata의 TEST 오표기를 root도 확인했으며 이 표시를 store 근거로 쓰지 않는다.
- PTE/descriptor의 허용 store 목록은 해당 PC의 쓰기뿐 아니라 해당 byte 범위와
  겹치는 모든 쓰기를 역방향으로 제한한다. DATA/PT payload와 보존 metadata에
  대한 CPU 쓰기를 금지한다. DATA page의 queue links는 이 금지에서 제외한다.
- 일관되게 재작성된 stack/PTE 반례와 부분 overlap 대조를 추가한다.
- 기존33에 일반 CALL/RET stack 검사를 읽기 전용으로 재적용한다. 발견한 movzx
  때문에 현재 GC 명령 whitelist를 조용히 확장하지 않는다. write-cardinality의
  이전 전체 소비자 적용과 IRETD/pushal을 포함한32 회귀는 별도 잔여 작업이다.

이는 모든 GPR/flags/일반 메모리 유효주소 계산의 독립 CPU 에뮬레이터가 아니다.
정상 사례 통과와 제한된 반례 거부를 전체 의미 검증으로 확대하지 않는다.
