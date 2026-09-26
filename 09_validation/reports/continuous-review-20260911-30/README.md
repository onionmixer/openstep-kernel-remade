# 신중한 추가 검토30 — PT 회수·재사용·NP 스캔과 신규 VA 확보 실패

## 판정

원본 pmap 함수를 실행하여 준비된 PT의 free→active→free 이동과 다른 section에서의
재사용, managed PV/PTE 제거, pmap 수준 wired/unwired count 처리를 검증했다.
별도 정상 고갈 kernel map에서는 원본 vm_map_find 실패→kmem 반환→expand 복귀와
호출자의 PDE 재검사를 관찰했다. 함수 patch/call mock/호출 도중 API 교정은 없다.

| Python 집계 | 결과 |
|---|---:|
| fresh 사례 | 12 |
| PT 재사용 lifecycle 사례 | 8 |
| 신규 VA 확보 실패 사례 | 4 |
| 원본 PDE 설치 / PTE 설치 / PTE clear | 32 / 32 / 32 |
| 원본 PDE Present-bit clear | 48 |
| 원본 NP 묶음 skip 호출 | 16 |
| 훼손 증거 거절 대조 | 22 |

재사용 matrix는 A/B root × wired=0/1 × NP residue 없음/있음이다. 각 사례에서
원본 FS scalar read로 mapping을 확인하고, NP 영역을 실제 스캔한 뒤 target을
제거하여 다른 section VA에 재사용한다. 신규 실패는 A/B × expand 직접 호출/
pmap_enter 호출자 재검사를 구별한다. **신규 wired PT 할당 성공은 미검증이다.**

## 원본과 합성 경계

보고서29 setup의 원본 startup/page init/free를 재사용하고 원본 allocator를 추가
실행해 data frame을 free queue에서 제거했다. data object/page는 시험 동안 그대로
유지한다. pmap 수준 wired flag/count와 VM page의 전체 wiring 수명은 다르다.

PT backing의 descriptor kernel PV VA/owner, wired PTE와 kernel pmap 국소 count,
free sentinel/free/total count는 명시적인 합성 준비다. 전체 boot pmap ownership은
아니다. 첫 빈 active PT는 deallocate helper를 직접 호출해 free로 만든다. 이후는
원본 pmap_enter/expand, pmap_remove가 실제 PV/PTE/count/queue를 변경한다.

PT pair는 다른 section에서 그대로 재사용된다. 원본은 재사용 때 zero-fill을 하지
않는다. NP residue 0xdeadbe00은 wired 잔여 bit를 포함하지만 Present=0이다.
원본 제거 함수로 이 NP 묶음을 실제 스캔했을 때 removed/wired 인자는 0/0이고
target mapping과 active PT는 유지된다. 뒤이어 target을 제거해야 마지막 PT가
free queue로 이동한다. residue는 지워지지 않는다.

FS read는 Accessed를 만들며 target 제거는 descriptor reference를 기록한다.
Dirty가 설정되지 않은 경로로 한정하여 phys→vm_page dirty lookup은 실행하지 않았다.
다른 root 보존은 directory 바이트와 기존 buffer 범위이며, 공유 kernel PT 전체의
A/D 불변이나 독립 하드웨어 TLB 동등성을 주장하지 않는다.

## 신규 VA 부족의 실제 원본 경로

별도 고갈 입력에는 등록된 PT 자원이 없다. kernel map의 유효한 범위를 기존 entry가
차지하도록 준비하고 원본 lock init을 실행한다. vm_map_find는 3을 반환하고,
kmem_alloc_wired는 이를 1로 축약하며 expand가 돌아온다. find 실패에서도 map
timestamp가 증가한다. physical-page 부족의 wait/sleep 경로와는 다른 조건이다.

pmap_enter 사례는 완료된 expand 실패 복귀를 두 번 관찰한 뒤 세 번째 expand의
첫 명령 실행 전에 멈췄다. 호출자가 최종 실패 반환하거나 이 반복이 영원히 계속됨을
증명한 것은 아니다. 관찰된 종료 경계·인자·EAX 값과 미변경 mapping을 기록했다.
expand의 관찰 EAX=1을 공개 오류 반환 ABI로 해석하지 않는다.

원본 신규 성공의 kernel map/object/zone/page/wiring 및 경쟁 정리 의존성은
[PT_CONTRACTS.md](PT_CONTRACTS.md)에 따로 기록했다. 반환0이나 기존 free PT 성공을
신규 물리 PT 생성의 증거로 쓰지 않는다.

## 독립 검산과 검토 수정

실행 코드를 import하지 않는 audit가 원본 Mach-O에서 명령/분기와 jump table을
읽어 trace를 대조한다. 초기 전역값, 준비 stack/실제 진입 인자, 전체 object/page/
descriptor arena/extension/pmap/queue/count 상태, PDE/PTE stores, FS read 결과를
독립 Python 모델로 검사한다. 새 kernel map lock init의 memset 간접 분기는
원본 PUSH 12와 raw table로 한정한다.

PDE Present-bit clear는 before byte의 `& 0xfe`로 계산하고 나머지 bit를 보존한다.
고갈 시 root 비교는 active kernel PDE의 단조 Accessed 설정만 허용한다. 원본 호출의
CPU write 기록이 허용된 stack/metadata/대상 user directory 밖이면 거절한다.
CPU의 page-table A/D 갱신은 이 write-hook 기록과 구별한다. inherited setup 전체에
이 write-hook을 적용한 것은 아니며, 준비 이력은 별도 trace/최종 상태 검사 범위다.

Codex 후속 검토에서 발견한 managed 전역값·PDE 권한 손실·준비 trace 누락을 root가
직접 재현하거나 원본에서 재확인하고 수정했다. 실제 NP-skip 시험도 코딩 전에 추가
검토했다. [계획](PLAN.md), [교차검토와 수정 근거](CROSS_REVIEW.md),
[음성 대조](negative-controls.json). 같은 backend 관찰의 독립 검산이며 별도 CPU
하드웨어 실행은 아니다. kernel backing walk는 실행 측 기록을 검산하는 범위다.

```sh
python3 -B 09_validation/reports/continuous-review-20260911-30/pt_lifecycle_review.py
python3 -B 09_validation/reports/continuous-review-20260911-30/audit_results.py
python3 -B 09_validation/reports/continuous-review-20260911-30/test_audit.py
python3 -B 09_validation/reports/continuous-review-20260911-30/reproduce_results.py
python3 -B 09_validation/reports/continuous-review-20260911-30/verify_artifacts.py
```

[원시 사례](pt-cases.json), [집계](pt-summary.json), [독립 audit](independent-audit.json),
[최근 진단](latest-diagnostic.json), [재현 해시](reproducibility.json),
[실행 전 보존](preservation-before.json), [실행 후 보존](preservation-after.json),
[입력 해시](input-hashes.json), [최종 보존 검증](verification.json),
[산출물 해시](artifact-hashes.json), [잔여 분석](OPEN_ITEMS.md).

Ghidra 스킬에 따라 원본 ASM/분석 해석/합성 준비/실제 관찰을 구분했다. 계산은
모두 Python이다. 원본 binary/DB/exports/reference·이전 보고서·07_kernel 보존.
전체 PT/VM/커널 분석, 신규 wired 성공, native CPU 예외 진입, GCC 2.7 구현·빌드·부팅과
후속 아키텍처는 계속 미완료이며 전체 목표를 완료 처리하지 않는다.
