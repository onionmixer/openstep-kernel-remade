# 남은 OPENSTEP 원본 분석

90차는 controller 전달, 디스크 등록과 maxTransfer의 raw I/O 소비를 연결했다.
실제 runtime controller, ID 표 게시, 정렬 임시 버퍼와 오류 전파 계약은 아직 닫히지 않았다.
전체 목표는 계속 미완료다.

1. **다음 우선: raw I/O 호출자·정렬 buffer의 유효 범위와 수명**.
   sdread/sdwrite 진입의 uio/iovec count·segment·base 소유권, 단일 vector 보장,
   copyin/copyout 실패와 짧은 전송 때 전체 길이 복사, alloc 실패, 반환 뒤 uio 재사용을 확인한다.
   physstrat `0x11ed10` 및 vslock/vsunlock/useracc의 실제 완료/복구 계약을 추적한다.
   minphys 캐시 0/geometry DIV/WORD CDB count·부분 성공/residual 범위도 유지한다.
2. **디스크 등록·ID 표 writer·controller 실제 연결**.
   super IODevice registerDevice, volCheckRegister `0x1a75e0`, 행 첫 DWORD와 partition 슬롯,
   행 WORD +0x20/+0x22 및 전역 unit·major·maxTransfer writer를 확인한다.
   물리 lookup의 unit 16 허용과 다른 호출자 경로, probe의 전역 unit 상한/lock/rollback,
   initResources의 worker 시작 시점, 늦은 orig IODisk init의 필드 변경과 실패를 연결한다.
   장치 설명 생성/directDevice IMP, actual isa/category/fixup, sc0 이름 등록이 남는다.
3. **inquiry·geometry·ready와 실제 전송**.
   sdInquiry `0x1ad0fc`, updatePhysicalParameters `0x1ac5a0`, scsiStartStop `0x1ad548`,
   updateReadyState `0x1ac88c`, inquiry 출력 길이/유효성, removable 재사용과 이름 lifetime,
   controller name 길이 및 filter 앞 BYTE 읽기 전제를 추적한다.
   실제 executeRequest override, DMA/map 변환, status/actual/sense writer,
   command 2–4 T 생성, reqSense의 고정 복사와 alignment/power-of-two/overflow는 미완료다.
4. **완료·조건 잠금·진단과 기존 연결 범위**.
   enqueue unlock 뒤 R.pending 재읽기/빠른 free, exactly-once 완료,
   NXConditionLock register TEST-loop와 native primitive, IOForkThread/IOExitThread,
   waiter/owner/quiescence, ready/eject/count, stats 및 allocator/string primitive를 유지한다.
   uiomove/copy recovery·DF/FS, pagemove/PTE/CR3/PV/TLB, buffer/VFS/UFS/NFS/RPC/XDR,
   오류·부분 성공·daemon·queue·sticky 상태의 잔여 계약도 제외하지 않는다.
5. **전체 분석 요건**.
   함수 밖 code/data/undefined와 누락 entry·경계·ABI/타입,
   Ghidra 경고/IDA 실패의 독립 대조 및 전체 함수·경로 ledger,
   loader/__common/__bss·scheduler/IRQ/context/fault/FPU/MMIO,
   pmap/PV/PT/PD·COW/shadow/cache/device pager·vnode hash/reuse/inactive,
   IPC/MIG/BSD/network/DriverKit/kernserv/Objective-C의 잔여 범위를 유지한다.

원본 정적 분석이 계속 가능하다. 외부 소스로 공백을 채우거나 구현 단계로 넘어가지 않는다.
계산은 Python만, 편집은 apply_patch만 사용한다. 미수신 교차검토는 통과가 아니며
실패 요청을 재시도·우회하지 않는다. 현재 전체 목표는 완료도 차단도 아니다.
