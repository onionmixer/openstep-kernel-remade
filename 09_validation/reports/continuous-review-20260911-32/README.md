# 신중한 추가 검토32 — NP fault부터 신규 PT와 복사 재시작까지

## 판정

원본 copyout/copyoutmsg에서 NP write event를 관찰하고, 명시적인 예외 frame 입력
경계 뒤 원본 fault 처리 코드의 data page 할당 → 신규 PT 할당·wiring → user mapping
→ IRETD → 원래 복사 명령의 실제 완료까지 연결했다. 보고서29의 기존 PT 조건이나
보고서31의 pmap 직접 호출만으로 이 통합 성공을 대신하지 않았다.

| Python 집계 | 결과 |
|---|---:|
| fresh 통합 사례 | 32 |
| handler 명령 head 관찰 | 294,336 |
| 두 frame의 zero-fill DWORD stores | 131,072 |
| kernel/user PTE stores | 128 |
| user PDE stores | 64 |
| 원래 fault 명령의 byte store 완료 | 32 |
| 훼손 증거 거절 대조 | 40 |

matrix는 A/B root × copyout/copyoutmsg × destination offset 0x100/0x1100 ×
flags 2/0x602 × zone sleepable/spin이다. 단일-byte 시험이며 VM 경계를 넘는
다중-byte 복사를 검증한 것은 아니다.
[원본 사례](fault-new-pt-cases.json), [집계](fault-new-pt-summary.json),
[독립 검산](independent-audit.json), [훼손 대조](negative-controls.json).

## 새로 연결한 원본 동작

보고서31 setup의 원본 allocator로 PT page를 잠시 할당한 뒤 data PAGE, PT page를
원본 free로 차례로 반환해 FIFO를 PAGE→PG로 준비했다. queue를 수동 재배열하지 않는다.
object 및 global queue 잠금은 명시적인 호출자 선행조건이다. 기존 last_alloc와
해제된 page의 stale object/offset 필드는 원본 이력으로 유지한다.

실제 fault 처리 중 먼저 data PAGE가 소비되고, 중첩된 kmem wired allocation에서
별도 PG가 소비된다. 각 allocator 인자/반환과 두 zero 완료를 따로 기록했다.
kernel allocation 중 data object의 paging reference와 busy page는 유지되며,
user pmap_enter 복귀 뒤 원본이 다시 잠그고 data page를 activate하고 busy를 해제한다.
PT page는 별도의 wired page로 남는다.

fault counter는 vm_fault와 wire_fast에서 각각 증가한다. 두 frame을 zero-fill하지만
vm_fault 전용 zero counter는 한 번만 증가한다. global wired count, object resident/ref,
active/free queue, kernel/data PV, extension/active PT, kernel/user PTE/PDE를 함께 검사한다.

IRETD 직전과 원래 명령의 재시작 head에서는 DATA가 아직 모두 0이고 user PTE에
retry 접근의 A/D가 없다. 다음 instruction head에서 정확한 목적지 한 바이트가 바뀌고,
해당 user PTE에만 A/D와 해당 PDE에 A가 생긴다. 최종 함수 반환값·callee-saved
register·flags 및 recover/uthread 상태도 별도로 검사한다.

## 원본·합성·관찰의 경계

예외 event는 emulator 실행 중 관찰했지만 CPU error/EIP/CS/EFLAGS frame은 시험이
명시적으로 입력한다. 원본 trap stub와 처리·복귀를 실행한 것이지 native IDT/CPU frame
생성을 입증한 것은 아니다. 프레임 입력 후 함수 patch/mock, API PTE 교정이나 임의
CR3 reload를 하지 않는다. 실제 하드웨어의 TLB/cache·비동기 인터럽트는 별도 의무다.

kernel map/object/zone/free-page/descriptor와 bootstrap ownership은 기존 합성 준비
범위를 유지한다. 원본으로 모든 object/map/zone을 생성하거나 zone backing 성장·자원
부족·scheduler/pageout·경합을 검증하지 않았다. quiescent IPL7 조건이다. 원본 binary,
DB/exports/reference, 이전 보고서 및 07_kernel은 변경하지 않는다.

## 독립 검산 및 교차검토

실행 모듈을 import하지 않는 audit가 raw Mach-O 명령·분기/call/return/IRETD와
runtime protection table의 원본 초기화 근거를 검사한다. 별도 Python 모델로 초기/
최종 object/page/map/zone/PV/PT/queue/count 바이트를 구성하고 중요 시점에 모든
기록된 CPU writes를 재생한다. 일반 store의 유효주소·값과 모든 CPU flag를 별도 CPU로
재실행하는 완전한 하드웨어 검증은 아니다.

saved_frame은 각 시점의 실제 raw stack slice와 연결한다. frame 주입은 관찰된
fault snapshot에 따른 지정된 stack 바이트와 ESP 변경만 허용한다. copy 인자·함수
entry·fault terminal head·FS operand로 계산한 CR2/byte 값을 서로 대조한다.
DATA/PT의 필수 high alias와 kernel low/high 공유 PTE는 raw table을 별도 walk한다.
retry의 A/D는 단순 IRETD 이후가 아니라 원래 store 완료 이후의 정확한 PTE/PDE에
한정하며, 기존 kernel alias의 단조 A/D 허용과 구분한다.

준비 호출은 원본 trace와 명시적인 metadata 경계 검증이며, 준비 처음부터 본 실행과
같은 전 영역 write 기록을 다시 수집한 것은 아니다. 마지막 준비 상태에서 실제 copy
입력까지는 선언된 잠금 해제와 copy setup 밖의 metadata 변경을 거절한다.

코딩 전 독립 검토를 수행했고 root가 원본으로 다시 확인했다. 사후 읽기 전용 검토의
saved-frame 분리·추가 주입 변경·잘못된 두 번째 할당 반환·nested busy 해제·조기 A/D
훼손도 거절했다. 정상 통과를 검산기 무결성의 대체 증거로 쓰지 않는다.
[계획](PLAN.md), [교차검토](CROSS_REVIEW.md).

## 재현과 보존

```sh
python3 -B 09_validation/reports/continuous-review-20260911-32/fault_new_pt_review.py
python3 -B 09_validation/reports/continuous-review-20260911-32/audit_results.py
python3 -B 09_validation/reports/continuous-review-20260911-32/test_audit.py
python3 -B 09_validation/reports/continuous-review-20260911-32/reproduce_results.py
python3 -B 09_validation/reports/continuous-review-20260911-32/verify_artifacts.py
```

[진단](latest-diagnostic.json), [재현 해시](reproducibility.json),
[실행 전 보존](preservation-before.json), [실행 후 보존](preservation-after.json),
[입력 해시](input-hashes.json), [보존 검증](verification.json),
[산출물 해시](artifact-hashes.json), [잔여 분석](OPEN_ITEMS.md).

Ghidra 스킬에 따라 보존 ASM의 사실·분석 해석·합성 준비·관찰 결과를 분리했고
계산은 Python으로 수행했다. 전체 커널 분석, GCC 2.7 실제 구현/컴파일/링크/부팅과
후속 아키텍처는 계속 미완료다.
