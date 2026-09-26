# 신중한 추가 검토31 — 신규 PT 원본 wired 할당 성공

## 판정과 범위

명시적으로 준비한 kernel map/object/zone/free-page 조건에서 원본 `pmap_expand`의
신규 물리 PT 할당 성공 경로를 실행했다. 기존 free PT 재사용이 아니다.
원본의 map entry 확보·삭제·재삽입 → page alloc/zero-fill → VM wiring과 kernel PTE/PV
설치 → extension zone 확보 → 물리 역변환/backlink → 사용자 PDE 설치를 연결했다.
호출자 사례에서는 이어지는 사용자 PTE 설치까지 확인했다. 함수 patch/call mock이나
호출 도중 API 상태 교정은 없다.

| Python 집계 | 결과 |
|---|---:|
| fresh 사례 | 8 |
| 원본 명령 head 관찰 | 43,380 |
| zero-fill DWORD stores | 16,384 |
| kernel/user PTE stores 합계 | 24 |
| user PDE stores | 16 |
| 훼손 증거 거절 대조 | 33 |

matrix는 A/B root × zone sleepable/spin × expand 직접 호출/pmap_enter 호출자다.
표는 [원본 실행](new-pt-cases.json), [Python 집계](new-pt-summary.json),
[독립 검산](independent-audit.json), [훼손 대조](negative-controls.json)에 근거한다.
원본 전체 PT/VM/커널의 정확성이나 native 하드웨어 성공을 뜻하지 않는다.

## 실제 연결한 상태

- 빈 kernel map의 main-map 설정으로 entry protection/current=3, max=7,
  inheritance=1을 원본이 초기화한다. entry zone은 원본 pop→free→pop으로 같은
  element를 재사용하며, extension은 별도 원본 zalloc으로 확보한다.
- kernel object의 페이지 offset은 선택 KVA다. detached free page를 원본 allocator가
  제거·등록하고 실제 물리 frame을 zero-fill한 뒤 busy를 해제한다.
- 원본 wire-fast가 VM page WORD wire_count와 global wired count를 증가시키고
  kernel pmap의 resident/wired count, PV 및 supervisor RW/wired PTE를 설치한다.
  반환 0만 확인하지 않으며 fallback vm_fault는 이번 경로에서 실행되지 않는다.
- 새 물리 PT 주소를 원본이 kernel mapping에서 역변환하고 descriptor/extension
  backlink와 active queue를 등록한 뒤 user PDE를 설치한다. 직접 expand는 user
  PTE와 user resident count가 비어 있고, caller 사례에서는 data PV/PTE/count가 증가한다.

## 합성 준비와 미검증 경계

기존 bootstrap/high-CS 시험에 kernel map/object, 기존 free zone element와 free-page
seed를 명시적으로 준비했다. map lock과 sleepable zone lock은 원본 lock_init,
페이지 seed는 원본 init/free를 실행했다. map/object/zone 자체의 생성과 zone backing의
신규 성장, 전체 physical descriptor 소유권은 아직 증명하지 않았다.

KVA의 기존 identity PTE만 준비 단계에서 NP로 만들고 원본 CR3 write를 실행한다.
PT frame의 high direct alias는 유지한다. kernel_pmap의 root는 CR3가 아닌 directory
slice이므로 정렬 내림하지 않고 low logical VA로 계산한다. active high kernel VA와
kernel low VA는 실제 공유 PTE를 참조한다. 다른 root의 directory/buffer 보존은
공유 kernel PT까지 불변이라는 의미가 아니다.

SPL/zone 시험은 명시적인 quiescent IPL7이다. 실제 인터럽트 경합·pending IRQ·MMIO와
pageout/scheduler 자원 부족은 제외했다. wiring의 전체 수명/해제·GC, race cleanup,
페이지 fault부터 신규 PT까지의 trap 통합은 다음 의무다. 사용자 PTE 설치 후 실제
FS 복사 재시작이나 새 native trap 진입을 이번 사례로 주장하지 않는다.

## 독립 검산과 교차검토

실행 모듈을 import하지 않는 audit가 원본 Mach-O의 명령·분기·call/return과
bootstrap protection 초기화 jump table을 읽는다. protection table은 BSS이므로
파일의 상수 배열로 오인하지 않고 원본 MOV 즉시값으로 기대값을 계산했다.

초기/최종 object/page/map/entry/zone/PV/descriptor/PT/queue/count의 전체 관련 바이트,
실제 stack 인자, 중요 시점, zero loop 진행과 모든 zero/PDE/PTE stores를 검사한다.
raw directory/shared PT snapshot으로 별도 Python page walk를 수행하고 기록된 walk와
대조한다. PT frame의 필수 high alias와 kernel low/high 연결·권한을 별도로 강제한다.
CPU writes를 각 중요 시점의 전체 기록 영역에 재생하며, 원본 명령의 write operand/폭과
PUSH/CALL의 stack store 조건을 검사한다.

하드웨어의 A/D 갱신은 CPU store hook과 별개다. 기존 공유 kernel alias의 단조 A/D,
active high PDE의 단조 A만 허용하며 새 KVA PTE와 user PDE의 값은 엄격하게 검사한다.
모든 read의 A/D 원인을 개별 증명하거나 전체 CPU 조건 플래그·store 유효주소를 재실행하는
모델은 아니다. 같은 backend 증거의 독립 검산이지 별도 CPU 하드웨어 실행이 아니다.

코딩 전 및 사후 Codex 교차검토를 수행했다. 필수 high alias 누락과 비-store 명령의
write 기록도 통과하던 초기 audit 오류는 root가 직접 재현하고 수정했다.
[계획](PLAN.md), [검토·수정 근거](CROSS_REVIEW.md)를 참조한다.

## 재현 및 보존

```sh
python3 -B 09_validation/reports/continuous-review-20260911-31/new_pt_review.py
python3 -B 09_validation/reports/continuous-review-20260911-31/audit_results.py
python3 -B 09_validation/reports/continuous-review-20260911-31/test_audit.py
python3 -B 09_validation/reports/continuous-review-20260911-31/reproduce_results.py
python3 -B 09_validation/reports/continuous-review-20260911-31/verify_artifacts.py
```

[최근 진단](latest-diagnostic.json), [재현 해시](reproducibility.json),
[실행 전 보존](preservation-before.json), [실행 후 보존](preservation-after.json),
[입력 해시](input-hashes.json), [최종 보존 검증](verification.json),
[산출물 해시](artifact-hashes.json), [잔여 분석](OPEN_ITEMS.md).

Ghidra 스킬을 적용하여 보존 export의 원본 ASM과 분석 해석·합성 준비·실제 관찰을
구분했다. 계산은 Python으로 수행했다. 원본 binary/DB/exports/reference 및 이전
보고서와 `07_kernel`은 보존한다. GCC 2.7 실제 구현/컴파일/링크/부팅과 후속 아키텍처를
포함한 전체 목표는 계속 미완료다.
