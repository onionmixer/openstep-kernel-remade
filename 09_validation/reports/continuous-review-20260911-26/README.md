# 신중한 추가 검토26 — 원본 resident 권한 교정과 fault 재시작

## 판정

원본 VM/pmap 코드가 이미 resident인 페이지의 같은 물리 매핑을 RO→RW로 고치고,
원본 vm_fault가 성공을 반환한 뒤 IRETD가 **실제 fault 명령으로 돌아가 재실행**하는
경로를 확인했다. fault 이후 PTE를 API로 고치거나 함수 반환값을 mock하지 않았다.

이것은 **resident 매핑 권한 교정**이며 pager I/O/page-in·부재 페이지 할당은 아니다.
실제 CPU 모델 #PF를 관찰한 뒤 CPU exception frame을 명시적으로 주입했으므로
native IDT 전달·hardware error/frame 생성의 미검증 상태도 유지한다.

| 관찰 범위 | 결과 |
|---|---:|
| fresh resident 교정·실제 명령 재시작 사례 | 64 |
| 원본 PTE store | 128 |
| 원본 INVLPG FS 실행 | 128 |
| handler 연결 구간의 instruction 방문 | 52,032 |
| DF 설정 입력의 성공 대조 | 32 |
| 원본 activate로 만든 초기 active queue 대조 | 32 |

겹치는 항목이며 Python으로 계산했다. 전체 커널 coverage 또는 모든 fault 입력의
증명으로 사용하지 않는다. DF=1은 합성 flags 대조이지 정상 ABI 호출 전제라고
주장하지 않는다.

## 초기화와 관찰 경계

기존 높은 CS·분리된 A/B 사용자 root·원본 IDT/CR3 설정을 재사용했다.
VM entry 전체의 두 하드웨어 PTE는 RO이고 current VM protection은 READ|WRITE다.
VM page size0x2000과 하드웨어 page size0x1000을 구분한다. 원본 bootstrap이 만든
pmap protection table과 VM/PTE 비율을 검사했다.

object/page/pmap는 합성 기존 상태다. object의 크기·WORD 참조 수·WORD resident
수·paging 수와 memq, entry object/offset, pmap root와 CR3 및 active 조건을 명시했다.
원본 `vm_page_insert`를 object lock/page busy 조건에서 실행하여 hash·memq·tabled
bit·resident count를 만들었다. hash는 VM page 크기에 맞춘 shift 및 비영 offset을
사용하며 실제 bucket의 head와 lookup 결과를 검사했다.

초기 queue 상태는 두 종류다.

- unqueued 대조: tabled/nonbusy/nonwired이지만 queue에 속하지 않는 합성 descriptor.
- active 대조: fault 전에 queue lock 아래 원본 `vm_page_activate`를 실행하여
  active header/pageq/count를 구성. 그 뒤 준비 경계에서 object lock/busy를 해제.

모든 준비 호출 뒤 copy caller/GPR/ESP/flags를 다시 설정했다. 실제 fault 관찰 뒤에는
error/EIP/CS/EFLAGS의 same-CPL frame과 ESP만 주입하고 원본 stub을 실행했다.
error3과 saved flags는 명시적 입력이며 CPU의 자동 error/RF 처리 증거가 아니다.

전체 object/map/pmap 생성은 실행하지 않았다. 특히 object template/global list 및
pmap 전체 소유권·PV·통계 정합은 별도 의무다. pmap 통계 입력을 PTE 개수에서
추정하지 않았고, 이번 경로에서 미접근·불변임을 확인했다.

## 실제 원본 성공 경로

`copy #PF 관찰 → frame 주입 → stub/alltraps/kernel_trap → vm_map_lookup
→ vm_page_lookup → resident page 처리 → pmap_enter → vm_page_activate
→ map lock 해제/object 참조 해제 → vm_fault=0 → IRETD → fault 명령 재실행 → copy=0`

원본 lookup이 기대 object/offset의 page를 반환하고, pmap_enter에 실제 사용자
pmap·VM page base·기존 물리 frame·protection3·wired0이 전달되는 것을 검사했다.
`0x1907d0`의 같은 물리 분기를 거쳐 `0x1908b4`에서 대상 하드웨어 페이지들을
invalidate하고 `0x1908e8`에서 PTE를 갱신했다.

PTE store는 instruction의 예정 주소·값, memory-write hook, 실행 후 page walker로
대조했다. 원본 순서는 invalidation들 → PTE store들 → IRETD → fault 명령이다.
이 관찰을 실제 하드웨어 TLB/cache 효과 전체의 검증으로 해석하지 않는다.

두 root의 낮은/높은 mapping을 전후 기록했다. PDE의 accessed 비트 및 PTE의
accessed/dirty 비트와 주소·권한을 구분해 비교했다. 대상 active low PTE의 write
권한 외에는 backing·권한이 보존되며, inactive root의 사용자 버퍼도 보존됐다.
메모리 hook 좌표는 실제 pmap root 읽기로 검증했다. 통계 미접근의 빈 결과만으로
hook이 작동했다고 가정하지 않았다.

## 실패 복구와 다른 성공 규약

원본 kernel_trap은 vm_fault=0이면 recover helper를 호출하지 않는다. 처음 원본
PUSH가 만든 frame을 fault snapshot과 대조하고, IRETD 전과 fault 명령 재방문 때
frame 전체가 바뀌지 않았음을 확인했다. 저장된 EIP·CS·EFLAGS가 그대로 복원됐다.

실패 경로와 달리 **성공에서는 DF를 강제로 해제하지 않는다.** 길이1 복사의 최종
recover 포인터도 기존 원본의 짧은 성공 경로 규약대로 남는다. 최종 반환0,
caller ESP/callee-saved, segment·제어 레지스터, uthread byte, 지정 버퍼와 stack
guards를 검사했다.

object/map/pmap 및 hash bucket의 지정 영역은 전체 byte 불변을 확인했다.
원본의 참조/paging 증가·감소 후 원래 값이 복원됐다. active 초기 대조에서는
원본 dequeue로 header=self/count0/active bit 해제 상태를 거친 뒤 재활성화됐다.
dequeue가 page 자신의 next/prev를 지우지 않는 원본 동작도 검사 모델에 반영했다.
최종 pageq/header/count는 올바른 active 상태다.

SPL helper 이름만 보고 효과를 추정하지 않았다. 이 원본의 `_splvm`/`_splimp`는
현재 IPL 값을 읽어 반환한다. 선택 경로의 `_splx`는 같은 IPL을 복원했고,
pending callback·OUT 분기는 실행하지 않았다. 해당 분기의 실제 동시성·I/O는
이번 시험 범위가 아니다.

## 검산·보존·잔여 분석

[코딩 전 계획](PLAN.md), [독립 Codex 검토](CROSS_REVIEW.md)를 원본과 대조했다.
Ghidra 스킬에 따라 원본 명령·decompiler 해석·공개 소스·합성 입력·실행 관찰을
분리하고 기존 정본 DB를 변경하지 않았다. 모든 계산은 Python이다.

별도 audit는 fixture 코드를 import하지 않는다. 원본 Mach-O 기반 decoder로
branch/call/return/IRETD 연결과 원본 명령 재실행을 검사하고, frame·예상 버퍼 해시·
queue·mapping 변경을 독립적으로 계산한다. 같은 backend 기록의 독립 검산이지
다른 하드웨어에서의 재실행 증거는 아니다.

```sh
python3 -B 09_validation/reports/continuous-review-20260911-26/resident_review.py
python3 -B 09_validation/reports/continuous-review-20260911-26/audit_results.py
python3 -B 09_validation/reports/continuous-review-20260911-26/verify_artifacts.py
```

[실행 코드](resident_review.py), [원시 결과](resident-cases.json), [집계](resident-review.json),
[독립 검산 코드](audit_results.py), [검산 결과](independent-audit.json),
[재현 검사 코드](reproduce_results.py), [재현 해시 대조](reproducibility.json),
[실행 전 보존](preservation-before.json), [실행 후 보존](preservation-after.json),
[입력 해시](input-hashes.json), [최종 보존](verification.json), [산출물 해시](artifact-hashes.json),
[잔여 분석](OPEN_ITEMS.md).

원본 바이너리·기존 Ghidra/IDA DB·reference sources·이전 보고서·07_kernel은 보존했다.
전체 분석, 원본 생성·PV/통계·pager/할당·다른 오류 경로, GCC 2.7 구현·빌드·부팅과
후속 아키텍처의 미완료 상태는 이번 통과로 바뀌지 않는다.
