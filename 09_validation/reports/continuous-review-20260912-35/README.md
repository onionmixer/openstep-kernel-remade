# 예외 처리 및 기존 소비자 감사 회귀

이 보고서는 기존31–34의 보존된 실행 기록에 원래 감사와 더 강한 stack/store
검사를 적용한다. 확정 gate는 [최종 검증](verification.json)과
[산출물 해시](artifact-hashes.json)로 확인한다. 전체 분석/복원 완료가 아니다.

[계획](PLAN.md)을 코딩 전에 [독립 교차검토](CROSS_REVIEW.md)했으며 root가
원본과 반례를 Python으로 직접 재확인했다. Ghidra 스킬로 보존 ASM을 읽기 전용
대조했다. 원본/DB/export/기존 확정 보고서 및07_kernel은 수정하지 않았다.

## 결과와 의미

[소비자 회귀](consumer-regression.json)에서 기존 원감사와 새 검사를 통과했다.

| 입력 보고서 | 기록 수 | 새 검토 범위 |
|---|---:|---|
| 31 | 8 | PT 할당 경로의 stack/store |
| 32 | 32 | 합성 예외 입력 이후 handler, 실제 CALL/RET·PUSHAD/POPAD·IRETD |
| 33 | 32 | 사용자 매핑 제거 경로의 stack/store |
| 34 | 38 | PT backing GC 및 tick gate의 stack/store |

총110행이다. [훼손 대조](negative-controls.json)는41개를 거부한다.
별도 component positive 대조는 기존 감사가 잘못된 CALL을 허용했다는 재현과
POPAD가 savedESP 슬롯을 건너뛴다는 의미 검사다. 이를 잘못된 전체 기록의 통과로
혼동하지 않는다. [감사 재실행](reproducibility.json)은 같은 보존 입력에서 새
프로세스로 산출물4개의 일치를 검사한다. CPU producer의 새 실행이나 native
하드웨어 검증은 이번에 수행하지 않았다.

[inventory](consumer-inventory.json)는 기존 보고서 Python141개 파일에서
accessbit/trace/replay/stack 관련 패턴18개를 식별했다. 이는 lexical/AST triage이며
전체 소비자의 의미·안전성 검증 완료를 뜻하지 않는다.

## 감사기에서 실제로 찾은 누락

[새 검사](review.py)는 명령별 store 개수/폭을 decoder access 표시와 분리한다.
REP MOVSD의 종료 write0, PUSHAD write8, segment PUSH의 현재 backend write4를
원본과 기록형식에 맞게 구분한다. CALL 저장값·주소와 RET 실제 읽기를 연결한다.

32 handler에서는 기존 copy caller 반환 slot과 합성 예외 프레임을 분리하고
ESP/EBP, trap-base EBX의 저장·복원, POPAD의 savedESP 건너뛰기, IRETD의 실제
EIP/CS/EFLAGS 읽기를 검사한다. 보완 중 추가로 발견한 POP 값과 final CPU의
모순, IRETD 현재 NT/CS/SS 모순도 직접 재현해 거부 검사에 넣었다.

POP/POPAD에서 확인한 레지스터 값은 알려진 동안 checkpoint/final CPU와 비교하고
full/partial/high-byte register write시 unknown으로 내린다. 관찰된 값을 임의로
다시 주입하지 않는다. [대조 코드](test_review.py)에 coherent raw stack 변조와
실제 읽기 검사를 분리한 사례를 보존했다.

## 한계와 후속 작업

합성 CPU frame은 실제 IDT/error 전달 검증이 아니다. same-ring CS8/SS16 및
VM/NT 미설정인 현재 경로만 지원한다. segment PUSH의 backend slot 기록형식은
모든 실제 CPU의 upper-half 쓰기 동작을 보장하지 않는다.
일반 GPR/flags/EA 전체 모델, prefault prologue 쓰기,31 이전 소비자 회귀와
실제 free 자원 재사용·수명 검토 등이 남아 있다. [잔여 분석](OPEN_ITEMS.md)에
전체 의무를 유지했다. GCC2.7 구현·실컴파일·링크·부팅은 아직 수행하지 않았다.
