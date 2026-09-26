# 보고서34 코딩 전 교차검토

독립 검토자 `/root/vm_contract_review27`에게 읽기전용 원본 검토를 요청했다.
검토자는 producer/파일수정 없이 결과를 전달했으며 root가 원본 ASM을 직접 읽었다.
Ghidra 스킬은 보존된 ASM/C와 원본 호출 관계 대조에 사용하며 live DB를 변경하지 않는다.

root가 확인한 핵심 의견:

- last==0 초기화와 delta>1 GC gate, PD free queue 별도 sentinel.
- 실제 free 순서에서 vm_fault_unwire와 pmap_remove_all을 누락하지 않을 것.
- unwire가 PT segment를 실제 조회하며, PG의 일시적 active 삽입으로 DATA queue
  링크가 변한다는 점. DATA payload/dirty/object 보존과 구분한다.
- KO ref2→1 및 반환, object-cache/pager teardown 미실행. KO를 합성 잠금한 채
  전체 GC를 호출하지 않을 것.
- kernel-map 전체 entry 범위/동일 kernel object/main-map 조건과 미보유 lock들.
- free된 PG/EXT/entry의 stale field, zero 실행 없음, high direct alias를 전체
  PV ownership과 혼동하지 않을 것.

추가 실행 설계에서는 frozen33의 helper 복제 범위와 prefix provenance의 압축 기록
선택을 별도로 검토 요청했다. 의견은 독립 CPU 실행 증거로 간주하지 않으며,
모든 계산 및 실제 결과는 root의 Python 검사와 후속 감사 산출물로 확인한다.

추가 설계 검토 응답을 코딩 전에 받았다. compact prefix 기록은 새 실행 result 전체의
canonical hash에서 계산하고, 동일 scenario의 frozen33 hash 및 직전 상태와 각각
비교하는 조건으로 채택했다. 이는 producer의 full-row 동등성 검사에 의존한다.
독립 GC 감사의 출발점은 명시적 입력 경계이며 새 prefix의 중간 CPU를 독립 감사했다고
주장하지 않는다. 합성 seed 이전의 tick/last/PD/aging raw도 캡처한다.

root의 최초 진단에서 GC 전체 정상 반환, PT segment→PG lookup, PG의 일시적
active 삽입과 free 반환을 관찰했다. 이때 kernel-object page_remove 경로에서 KO
lock은 0이었고, 나중 object_deallocate 안에서만 KO lock을 획득·반환했다.
map write lock과 queue/hash/KP lock의 실행 순서는 후속 독립 감사로 확인해야 한다.
기존 예제에서 합성 보유한 object lock을 모든 free 경로의 실측값으로 일반화하지 않는다.

## 감사기 자체의 반례와 수정 교차검토

검토자가 CALL1911c8의 기록된 반환값/쓰기 누락·중복과 PUSH16b851 주소 훼손을
발견했다. root는 checkpoint stack bytes와 cursor까지 일관되게 재작성한 반례가
기존 감사에 통과함을 Python으로 직접 재현했다. 단순 abstract call graph와
쓰기 replay의 일치만으로 실제 RET 동작이 증명되지 않았다.

또한16b8d0 및 그 뒤15b5e7에 추가 KVA PTE clear/restore 쓰기를 넣고 raw translation,
파생 walk와 cursor를 맞추면 통과하는 반례도 root가 직접 재현했다. 기존 store
목록은 특정 PC의 출력만 검사해 다른 PC가 같은 주소를 쓰는 것을 놓쳤다.

보완 코딩 전 검토자와 다음 설계를 대조했다. 원본 명령별 ESP/EBP·CALL/PUSH
쓰기 위치·RET 실제 읽기를 연결하고, 명령당 store 개수/폭을 검사하며, 보호 대상
byte interval에 겹치는 모든 쓰기를 역방향 검사한다. root/검토자 모두 Capstone의
TEST access metadata가 write로 잘못 표시됨을 확인했으므로 opcode/operand
위치로 제한된 store 모델을 구성했다. 원본16b858는 TEST byte [ESI+2c],1이다.

수정 후 root와 검토자가 별도로 확인한 거부 지점:

- 잘못된 CALL 반환값은 `CALL return word`, PUSH 주소는 `implicit stack slot`.
- CALL 쓰기 누락·중복은 명령당 cardinality. stack 검사 단독으로도 거부.
- 올바른 CALL 뒤16b8d0의 추가 stack write로 복귀 slot을 덮으면16b902의
  `actual RET word/slot`에서 거부. 공식 대조는 이 핵심 검사를 직접 호출한다.
- 추가/부분 겹침 KVA 쓰기는 PTE 보호, PT owner/backlink 부분 쓰기는 descriptor 보호.
- TEST16b858의 width1 가짜 write는 cardinality에서 거부.

일관된 stack/PTE 대조는 일반 replay를 먼저 통과함까지 확인하여 단순 snapshot
불일치 때문에 거부된 사례와 구분했다. 훼손은 deepcopy 기록에만 가했고 원본
바이너리/실행 메모리/기존 보고서는 변경하지 않았다.

기존33의 stack 검사도 root/검토자 각각 Python으로 전체32행 통과를 확인했다.
별도 cardinality 적용은 원본190ff4/19100d의 MOVZX가 GC whitelist에 없어
거절된다. 이 보고서는 whitelist를 조용히 확장하지 않고 stack 회귀만 기록한다.
32의 pushal/IRETD와 이전 전체 소비자에 대한 의미 회귀는 미완료로 남긴다.
독립 검토자 의견은 근거 자체가 아니며 원본 및 실행/감사 결과와 구분한다.
