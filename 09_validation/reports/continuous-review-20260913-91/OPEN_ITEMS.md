# 남은 OPENSTEP 원본 분석

91차는 여러 vector가 raw I/O에 그대로 도달하는 조건부 정적 경로, physstrat 완료 대기와
VM wrapper 전제를 확인했다. 전체 분석 목표는 미완료이며 다음 안전한 원본 분석이 가능하다.

1. **다음 우선: 실제 wiring·페이지 수명과 copy fault**.
   vm_map_pageable `0x175b2c`의 오류/부분 성공/wired count/rollback을
   physio의 vslock 반환 무시와 연결한다. pmap_extract `0x190c24`, region 생성/PA 범위,
   vsunlock의 page flag writer와 NULL/소유권 계약, map entry lock/hint 안정성을 확인한다.
   copyin/copyout fault/recovery·부분 복사와 sdread 전체 copyback·sdwrite 반환 무시를 연결한다.
2. **벡터·dispatch·완료의 실행 전제**.
   cdev 초기 행 14와 runtime major 설치/표 교체, file/vnode operation 생성,
   syscall 문맥 error/result 초기화·복귀, count 0/선두 길이 0 처리와 단위별 B 초기화/재사용,
   여러 vector에서 segment 변경, 실제 DMA alignment/강제 page 정렬 값이 필요하다.
   sleep/splbio/splx/wakeup·비동기 flag·strategy 실패·exactly-once 완료와 B lifetime을 유지한다.
3. **오류 후 재시도와 buffered 경로**.
   fspause 문맥 +0x6c/+0x70 writer, error 0x1c와 rpsleep/fssleep의 반환 전제,
   동일 uio 재호출 시 임시 버퍼 포인터/segment 복원 여부를 확인한다.
   buffered spec의 DIV/곱셈/residual, uiomove 오류 뒤 writeback,
   bwrite/bawrite/bdwrite 자체 오류와 상위 error 전파·부분 갱신도 미완료다.
4. **디스크/controller 등록·실제 명령·inquiry**.
   ID 표 첫 DWORD·partition 슬롯·행 WORD writer, super 등록·volCheckRegister,
   전역 unit/major/maxTransfer의 lock/상한/rollback, 초기 worker와 늦은 IODisk init,
   directDevice와 실제 class/category/fixup, inquiry/geometry/ready/name lifetime,
   실제 executeRequest/DMA/status/actual/sense writer와 CDB WORD count 전제를 계속 확인한다.
5. **기존·전체 분석 요건**.
   enqueue 뒤 R 접근/완료/free·조건 잠금·scheduler/IRQ/context/fault/FPU,
   VM COW/shadow/pager·PTE/PV/PT/PD/CR3/TLB·buffer/VFS/UFS/NFS/RPC/XDR,
   IPC/MIG/BSD/network/DriverKit/kernserv/Objective-C와 loader/__common/__bss 잔여 범위,
   함수 밖 code/data/undefined·누락 entry·경계·ABI/타입,
   Ghidra 경고/IDA 실패의 독립 대조와 전역 함수·경로 ledger를 축소하지 않는다.

다른 코드로 공백을 메우지 않는다. 계산은 Python만, 편집은 apply_patch만 사용한다.
독립 계획 교차검토 미수신은 통과가 아니며 실패 요청을 재시도·우회하지 않는다.
현재 전체 목표는 완료도 차단도 아니다.
