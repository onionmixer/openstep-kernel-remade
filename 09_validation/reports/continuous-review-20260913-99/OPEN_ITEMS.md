# 남은 원본 분석 — 99차 이후

이번에 PCB/K 초기화, bitmap 수정 gate, 선택 allocator/free/copy와 전파의 지역 계약을 확인했다.
이는 전체 원본 분석 완료가 아니며 다음 항목을 계속 미완료로 유지한다.

## 직접 후속 항목

1. **Allocator와 첫 bitmap 확장**: `0x16b364`의 실제 zone 할당·초기값·실패,
   runtime k_zone_maxsize/zone table 초기화와 수명, kfree(0,0)의 도달 전제 및
   zfree가 받는 element/zone의 유효성을 원본으로 연결한다. NULL free를 안전한 no-op으로
   가정하지도, 선택 경로만으로 native crash를 확정하지도 않는다.
2. **TSS 추가 바이트와 offset writer**: TSS+0x66 WORD, P+0xf0 ownership flag,
   P+0/+4/+8/+0xc, K+8/+0xc의 생성·복제·파괴·alias/bulk writer를 조사한다.
   복사로 쓰이지 않는 마지막 요청 바이트의 실제 초기값·후속 writer·CPU 소비는 미확인이다.
   모든 bitmap writer가 task_map_io_ports의 크기 상한을 보존한다고 아직 증명하지 않았다.
3. **할당 실패와 rollback**: PCB/K/bitmap/TSS의 NULL 결과 검사 부재를 각 하위 반환·상위
   호출 전제와 연결한다. memcpy DF, 유효 buffer, bitmap 수정 전/후 fault와 부분 상태,
   기존 allocation 해제 이후의 접근을 확인한다. 지역 검사 부재와 실제 오류를 구분한다.
4. **전파·lock·thread 수명**: K lock, task list/reference, PCB 소유, active-thread/TSS/GDT/LTR,
   hold/wait에서 현재 thread 제외와 release 균형, bootstrap zero-size skip 및 base-only
   LDT 비교가 전체 호출 계약과 맞는지 확인한다.
5. **Objective-C 실제 호출 계약**: deviceDescription/resourcesForKey:/count/objectAt:/range
   실제 method 구현·dispatch, range 반환 EAX/EDX와 mode/권한·입력 범위,
   caller가 map 오류를 무시하는 상위 결과를 원본에서 확인한다.
6. **Wired VM 계약**: vm_map_find, backing helper `0x173ebc`, vm_map_pageable,
   map/object 참조·page rounding·wire 실패 및 cleanup을 추적한다.
   97차 PC 생성자의 unchecked wired 결과도 이번 지역 0/1/6 계약과 연결해야 한다.

## 이전 미완료 항목 유지

- LDT 설정 gate의 실제 입력/권한, runtime descriptor/selector/GDTR writer,
  alias·함수 밖 LLDT 및 scheduler/IRQ/FPU/CR3/IRETD 계약.
- PC shared M은 task machine K와 별개다. M의 descriptor bound, R active/enable/pending,
  shared mapping 수명, callout queued/in-flight 취소 및 파괴, exception continuation을 확인해야 한다.
- Trap/copy recovery의 alias/bulk writer, DF/FS/ES/stack/segment fault, pathname·uio·IPC의
  길이와 부분 오류·cleanup, raw I/O/DMA/잔여량/완료 횟수 분석은 남아 있다.
- 모든 함수와 함수 밖 code/data/undefined, 경계·entry·ABI·타입, Ghidra 경고/IDA 실패,
  loader/common/bss/runtime fixup, VM COW/shadow/pager/PV/TLB,
  VFS/UFS/NFS/RPC/XDR/IPC/MIG/BSD/network/DriverKit/kernserv 전체 의미는 완료되지 않았다.

기존 범위·유보는 [98차 미완료 목록](../continuous-review-20260913-98/OPEN_ITEMS.md)과
[97차 미완료 목록](../continuous-review-20260913-97/OPEN_ITEMS.md)에 유지한다.
외부 코드 참조·복원·구현·빌드·포팅 없이 원본 정적 분석을 계속할 수 있다.
