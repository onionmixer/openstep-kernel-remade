# 신중한 추가 검토25 — VM entry의 쓰기 권한 거절

## 결과와 범위

주소를 포함하는 합성 VM entry에서 **원본** `_vm_map_lookup`의 protection 검사를
실행했다. 빈 map miss를 사용했던 보고서24와 달리 실제 entry 발견 후 쓰기 권한을
거절하고 반환값2를 내는 원본 경로를 확인했다. canonical C 및 공개 소스에도 이
검사가 있으므로 새로운 디컴파일 누락으로 판정하지 않는다.

| 구분 | 결과 |
|---|---:|
| fresh CPU fixture 사례 | 64 |
| protection 거절 → 원본 recovery/IRETD/EFAULT | 32 |
| protection 허용 분기 직전 중단 대조 | 32 |
| sentinel에서 원본 목록 탐색을 거친 사례 | 32 |
| 원본 lock_init 실행 | 64 |

항목은 겹친다. 계산·집계는 모두 Python이다. 모든 경우 실제 CPU 모델 #PF를
관찰했지만, 그 뒤의 CPU exception frame은 명시적으로 주입했다. **native IDT
진입 및 hardware error/frame 생성은 미검증**이라는 보고서24의 제한을 유지한다.

## VM page와 PTE page를 구분한 준비

원본 page_mask=0x1fff에서 VM page는0x2000, 하드웨어 PTE page는0x1000이다.
VM entry는 `[0x600000,0x602000)` 전체를 포함하고, 대응하는 낮은 사용자 PTE를
모두 RO로 설정했다. 높은 kernel mapping은 writable인 별도 backing으로 유지하고
Python page walker로 권한과 물리 주소를 확인했다. 원본 CR3 선택 구간을 실행하기
전에 PTE를 설정했다.

대상은 A/B root, copyout/copyoutmsg, entry/sentinel hint, destination offset
0x100/0x1100, flags2/0x602, 길이1, current protection1/3의 조합이다.
두 destination의 fault 주소 모두 원본 vm_fault에는 같은 VM page base로 전달된다.
이 시험에서는 첫 store부터 fault하므로 부분 쓰기가 없다.

합성 entry와 sentinel의 양방향 연결, 범위, hint를 구성했다. entry flags는0이다.
max_protection/wired 등 거절 전에 사용되지 않은 필드의 초기화를 의미 검증으로
세지 않는다. map의 pmap pointer를 CR3와 동일시하지 않으며, 원본 vm_map_create
전체 또는 완전히 생성된 사용자 map의 검증이라고 주장하지 않는다.

원본 `_lock_init(map,1)` 및 그 안의 원본 bzero/memset을 DF=0에서 실행했다.
그 뒤 copy caller/GPR/ESP와 시험 flags를 준비했다. fault 후 lock_init을 실행하여
스냅샷을 훼손하는 방식은 사용하지 않았다. lock owner/read count/can_sleep/
interlock의 원본 초기화 결과를 검사했다.

## 원본 거절 경로

`stub → alltraps → kernel_trap → vm_fault → vm_map_lookup → protection 거절
→ lock_done → 반환2 → vm_fault 조기 반환 → recovery → IRETD → EFAULT`

코드 patch와 함수 반환 mock은 없다. 원본 함수의 인자, entry 선택, 실제 읽은
protection, 반환2가 호출자에게 전파되는 지점을 기록했다. SDK의
KERN_PROTECTION_FAILURE=2와 원본 immediate를 함께 대조했다.

entry hint의 빠른 경로와 sentinel hint의 목록 탐색을 실행 trace로 구분했다.
반환값이 같다는 이유만으로 목록 탐색을 실행했다고 판단하지 않는다.

거절 완료 시 검사:

- read-lock 해제 후 map 전체의 지정 범위 복원, entry 불변.
- fault counter 증가, uthread byte 저장·초기화·복원, recover 초기화.
- 원본 PUSH frame layout과 recovery의 EIP/CS low word/DF만 바뀌는 정확한 byte delta.
- IRETD 직전 GPR·segment 복원, landing의 flags 및 caller 구간·ESP.
- 최종 EAX=14, caller ESP/callee-saved, DS/ES/SS/FS/GS/CS/CR0/CR4 보존,
  CR2/CR3 및 IF 유지·DF 해제.
- fault 전후 지정 사용자/커널 버퍼와 stack guards.

이는 지정 영역 검사이지 전체 RAM 쓰기 전수 검사나 실제 경합·interrupt·TLB/cache
하드웨어 효과 검증은 아니다.

## 허용 분기 대조는 성공 반환이 아니다

protection3에서는 원본 `request & protection` 검사를 통과하여 `0x17817c`의
instruction **실행 직전**에 중단했다. PTE는 여전히 RO다. 이 대조는 소프트웨어
protection 검사와 하드웨어 PTE 상태를 구분하며, 원본 page-in 성공이 아니다.

그 시점에는 map read lock이 잡혀 있고 recover가 남아 있으며 uthread 임시 byte는
0이다. 이를 별도로 검사했고, 거절 경로의 “해제·반환 완료” 조건을 적용하지 않았다.
원본 `_vm_map_lookup` 성공 반환, object/page 생성, fault 명령 재시작은 실행하지 않았다.

## 검토·독립 검산·보존

[코딩 전 계획](PLAN.md)과 [Codex 교차검토](CROSS_REVIEW.md)를 먼저 기록했다.
VM/PTE page 크기를 혼동한 독립 검토자의 제안은 root가 원본 인자·Python 계산으로
반박해 폐기했다. 사후 검토의 최종 버퍼 해시 누락 지적은 증거 기록에 반영했다.

Ghidra 스킬을 사용해 원본 명령·decompiler 해석·공개 소스·fixture와 관찰을
구분했다. 원본 Ghidra/IDA DB는 수정하지 않았다. 별도 audit는 fixture 코드를
import하지 않고 원본 Mach-O 기반 instruction decoder와 독립 예상 버퍼·frame
계산으로 trace의 branch/call/return, 권한 검사, 최종 상태를 대조한다.
이는 같은 CPU 관찰의 독립 검산이며 다른 하드웨어 backend 검증은 아니다.

```sh
python3 -B 09_validation/reports/continuous-review-20260911-25/protection_review.py
python3 -B 09_validation/reports/continuous-review-20260911-25/audit_results.py
python3 -B 09_validation/reports/continuous-review-20260911-25/verify_artifacts.py
```

[실행 코드](protection_review.py), [사례 원시 결과](protection-cases.json),
[집계](protection-review.json), [독립 검산 코드](audit_results.py),
[독립 검산 결과](independent-audit.json), [재현 검사](reproducibility.json),
[실행 전 보존](preservation-before.json), [실행 후 보존](preservation-after.json),
[입력 해시](input-hashes.json), [최종 보존 검사](verification.json),
[산출물 해시](artifact-hashes.json), [잔여 분석](OPEN_ITEMS.md).

원본·reference sources·기존 DB·이전 보고서·07_kernel은 수정하지 않았다.
전체 분석, GCC 2.7 구현·빌드·부팅, 후속 아키텍처는 미완료다.
