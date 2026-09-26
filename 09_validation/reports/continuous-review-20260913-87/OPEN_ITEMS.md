# 남은 OPENSTEP 원본 분석

87차는 disk 메서드 정적 소유권, wrapper/errno ABI, ObjC lookup/super,
논리 geometry와 SCSI 요청 제출을 추가했다. 전체 분석은 아직 완료되지 않았다.

1. **다음 우선: SCSI 요청 수명과 실제 완료**. 원본 category-list 후보
   enqueue `0x1ad774`, alloc `0x1ad828`, free `0x1ad880`을 대조하고,
   pending B의 저장·대기·큐·성공/오류 완료에서 residual/WORD/flag/biodone을 연결한다.
   async enqueue 실패와 sdstrategy의 자체 완료가 중복되거나 누락되지 않는 조건,
   물리 buffer 주소와 client map의 변환·장치 접근도 미확정이다.
2. **실제 class와 등록**. disk table `0x1e7324`/control `0x1e7564` writer,
   receiver 생성 및 self `+0x184` 연결, class superclass 문자열→pointer fixup,
   category 등록·override·selector 일치, cache helper `0x1cd76c`, 초기화 `0x1cd284`,
   class lookup `0x1ced1c`와 forwarding `0x1cebb0`를 검토한다.
   정적 IODevice/IODisk errno 표만으로 모든 동적 override의 비영 반환을 보장하지 않는다.
3. **geometry 전제**. blockSize/diskSize와 logical `+0x188`/`+0x18c` writer,
   partition `+0x1a8` label flag, formatted/writeProtected/ready 정책을 확인한다.
   DIV의 비영 divisor·비율의 나머지, DWORD 합·곱 wrap 방지, zero length,
   끝에서 줄인 길이와 원래 B.request의 residual 처리가 필요하다.
4. **copy fault·native 주소 공간·buffer allocator**. 86차 uiomove/copywithin 오류
   미검사·진척, 짧은 copy recovery slot 잔존, fault fragment→parent frame 복귀,
   DF/FS, stack breadDirect의 physical 주소 유효 선형 mapping을 확인한다.
   pagemove PTE 선덮어쓰기·고정 크기·CR3 reload와 NULL/present/비중첩/PV/TLB 전제,
   allocbuf donor, brealloc bucket overlap, release 뒤 접근 및 stack hash 배타성도 남는다.
5. **NFS/UFS 및 상위 VM/pager**. rfscall/XDR count bounds, daemon 비지역 복귀·
   queue 배타성·flag-only 오류 도달성, sticky 오류, bmap/invalidation/credential,
   UFS size 선증가·부분 성공·uerror와 vm_fault/pageout/mfs 전체 정책,
   page/object event 및 pager ID/sentinel/bitmap/게시/shutdown 참조 균형을 유지한다.
6. **전역 원본 분석 요건**. 함수 밖 code/data/undefined·누락 entry·경계·ABI/타입,
   Ghidra 경고·IDA 실패의 독립 대조, 전역 함수·경로 ledger,
   loader/__common/__bss·scheduler/IRQ/context/fault/FPU/CR3/TLB/MMIO,
   pmap/PV/PT/PD·COW/shadow/cache/device pager, vnode hash/reuse/inactive,
   IPC/MIG/BSD/VFS/network/DriverKit/kernserv/Objective-C 잔여 범위를 축소하지 않는다.

외부 코드는 참고하지 않는다. 구현·복원·빌드·포팅·동적 실행은 범위 밖이다.
계산은 Python만, 파일 변경은 apply_patch만 사용한다. 독립 계획 교차검토 미수신을
통과로 간주하거나 실패 요청을 우회하지 않는다. 안전한 원본 정적 분석이 계속 가능하므로
전체 목표는 완료도 차단도 아니다.
