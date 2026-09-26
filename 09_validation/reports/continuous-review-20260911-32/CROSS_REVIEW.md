# 보고서32 코딩 전 및 사후 교차검토

검토자는 `/root/vm_contract_review27`이다. 최초 검토 요청은 도구 오류로 끝났으며
완료된 검토로 세지 않았다. 이후 자료구조 사전조건 검토, 결합 설계 검토, 독립 audit
설계 검토를 각각 받았다. 새 코드는 해당 검토를 받은 뒤 작성했으며 root가 원본을
다시 읽고 의견을 확인했다. 원본 실행·수정은 root가 수행했다.

## 사전조건

원본 free head 제거와 tail append로 임시 alloc(PG)→free(PAGE)→free(PG)의
FIFO를 확인했다. 임시 alloc의 KO object lock, 두 free의 해당 object/global queue
lock, 내부 free/hash lock을 호출 전에 잡지 않을 조건을 구분했다. Python으로
free/resident 계수와 두 frame 범위·hash bucket을 계산했다. stale offset/last_alloc은
합성으로 지우지 않고 원본 준비의 이력으로 기록했다.

## 결합 설계와 audit 코딩 전

- 반복되는 allocator/pmap/zero PC는 순서·trace index·인자로 구분한다.
- 0x17269f의 data PAGE 반환과 0x173f04의 PT PG 반환을 구별한다.
- 첫 DATA zero 완료, 두 번째 PT zero 완료, IRETD 전, retry head와 실제 store
  완료 뒤를 나누어 관찰한다. retry head는 아직 완료된 store가 아니다.
- nested PT allocation 동안 data object의 paging reference와 page busy를 유지하고,
  복귀 뒤 원본 잠금 재획득·activate·busy 해제·paging 감소를 확인한다.
- vm_fault와 wire_fast의 fault counter와 vm_fault 전용 zero counter를 구분한다.
- saved_frame을 실제 raw stack과 연결하고, 입력 frame의 변경 범위와 copy 인자,
  원본 FS operand로 도출한 fault 주소/값을 묶어 검사한다.

root는 원본 vm_fault 0x17342d/0x17344c/0x173463 및 후속 activate/busy/paging,
wire_fast counter, 원본 free/addfree, trap/IRETD 명령을 읽고 반영했다. 전역/포인터/
크기/계수와 예상 바이트 계산은 Python으로만 수행했다.

## 사후 확인

검토자는 정상 메모리 대조가 통과한 뒤 증거 복사본의 saved_frame 분리, 지정 범위
밖의 주입 변경, 두 번째 allocator 반환의 PAGE 오기, nested busy 조기 해제,
retry head에서의 조기 PTE A/D를 시험했고 모두 거절됨을 확인했다. 파일을 수정하거나
producer를 실행하지 않았다. root는 이 연결을 공식 훼손 대조에도 포함했다.

root는 준비 마지막 상태와 copy 입력의 metadata 연결, 각 zero chunk의 정확한
trace index 대응을 추가 검사했다. CPU/state의 중복 관찰을 함께 변경한 잘못된 PG
반환과 raw walk를 함께 변경한 조기 A/D도 별도 대조로 거절했다.

## 제한

같은 emulator 관찰을 독립 검산한 것이며 모든 CPU flag나 일반 store 유효주소/값을
다른 CPU로 재실행한 것이 아니다. 준비 이력은 본 handler와 같은 전 영역 write
provenance 범위가 아니다. native 예외 frame, 전체 boot ownership, 자원 부족과 경합을
이 유한 사례로 입증하지 않는다. Codex 의견은 원본 재확인과 실행·검산을 대신하지 않는다.
