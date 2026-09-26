# 100차 이후 남은 원본 분석

이번 검토는 zone allocation 본체, 초기화와 공급 경로, boot 초기값의 지역 전제를 좁혔다.
전체 allocator/VM/kernel 분석은 아직 완료되지 않았다.

## 직접 후속 경로

1. **PCB/K 객체 수명과 writer**: task machine state의 복제·종료, PCB terminate,
   K+8/+0xc bitmap과 P+0/+4/+8/+0xc/ownership flag의 전체 writer를 연결한다.
   99차 첫 kfree(0,0)는 선택 초기화 아래의 조건부 경로이지 native 실행 증거가 아니다.
2. **TSS 추가 바이트**: 초기/copied I/O offset, offset 변경 writer, TSS allocation의 실제 출처·재사용,
   header/bitmap 뒤의 바이트를 쓰는 다른 명령과 CPU 소비 범위를 확인한다.
   최초 pool zero-fill을 모든 후속 TSS 초기값 보장으로 일반화하지 않는다.
3. **Zone free-space 수명**: space 제거/반환·coalescing·GC·zone flag writer와 zone metadata 재사용,
   sorted extent·hint index·크기·정렬 불변식을 전체 caller와 연결한다.
   zinit의 +0x3c no-match 값, 보존 flags high nibble, size wrap의 실제 입력 도달성을 확인한다.
4. **실제 VM backing**: 0x173ebc의 대기/페이지 할당·초기값·실패, kmem_alloc_pageable,
   vm_map_find/insert/delete/pageable 및 map/object 참조·wire 오류를 확인한다.
   kmem_alloc_zone의 자체 0/1/6과 성공 output만으로 하위 VM 계약은 완료되지 않는다.
5. **대기·동시성**: zone busy wait/wakeup, local pointer 재검사와 free-list 재읽기의 다른 edge,
   lock/IRQ/scheduler·native 코드/메모리 상태를 연결한다.
   noblock 이름을 전체 no-sleep 보장으로, register-only spin을 실제 deadlock 재현으로 취급하지 않는다.
6. **부팅 전제**: start의 segment/descriptor 전환, loader/common/bss 및 초기 pool mapping,
   region allocator 정렬·범위·overflow, runtime page-size/space/global alias writer를 확인한다.
   이번 지정 literal write 조사는 전체 runtime writer closure가 아니다.

## 기존 미완료 항목 유지

- Objective-C I/O Ports method binding/range ABI/권한/오류 처리와 bitmap 전파·task/thread 참조.
- LDT 주소/size gate, descriptor/GDTR/LTR/LLDT, current-thread hold/release 균형,
  PC shared state M의 writer/descriptor bound, callout 및 exception continuation 수명.
- Trap/copy recovery alias/bulk writer, DF/FS/ES/stack/IRETD, FPU/CR3/TLB,
  pathname/uio/IPC 부분 오류와 raw I/O/DMA/완료 계약.
- 모든 함수와 함수 밖 code/data/undefined, 누락 entry/경계/ABI/타입,
  Ghidra 경고/IDA 실패, VM COW/shadow/pager/PV, VFS/UFS/NFS/RPC/XDR,
  IPC/MIG/BSD/network/DriverKit/kernserv/Objective-C의 전체 의미.

[99차 미완료 목록](../continuous-review-20260913-99/OPEN_ITEMS.md)의 나머지 유보도 유지한다.
원본 정적 분석을 계속할 수 있으며 외부 소스·복원·구현·빌드·포팅은 진행하지 않는다.
