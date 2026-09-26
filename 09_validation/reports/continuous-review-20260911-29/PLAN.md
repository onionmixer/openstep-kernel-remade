# 보고서29 계획 — 부재 페이지에서 원본 명령 재시작까지

분석용 검증 코드를 작성하기 전에 기록한다. 전체 잔여 의무는 보고서28
OPEN_ITEMS.md를 계승하며, 이 경로의 성공을 전체 VM/커널 완료로 바꾸지 않는다.

## 사전 원본 확인과 독립 검토

독립 Codex reviewer `/root/vm_contract_review27`가 코딩 전에 읽기 전용으로
다음 선행조건을 지적했다. 의견 자체는 증거가 아니며 root가 정본 ASM과
기존 fixture를 읽고 Python 관찰로 다시 확인했다.

- `vm_page_zero_fill` → `pmap_zero_page` → `page_set`은 DS:[physical]에 쓴다.
  높은 DS 아래 supervisor high direct alias가 필요하다. low identity mapping이
  필요하다는 해석은 채택하지 않는다. 원본 주소 0x17b9a6, 0x191438, 0x1019cc.
- `pmap_allocate_mapping`은 데이터 frame뿐 아니라 PT physical descriptor의
  extension을 역참조한다(0x190f57–0x190f7d). kernel pmap으로 바꾸어 우회하지 않는다.
- report28의 caller-held object/queue lock을 vm_fault 진입에 그대로 가져오면
  안 된다. 원본 init/free 준비 이후 잠금을 해제한 합성 경계를 명시한다.
- present PDE/nonpresent PTE 아래 managed frame의 빈 PV head 등록을 관찰한다.
  PDE 확장, 추가 PV 노드, pager I/O, 실제 물리 메모리 발견은 별도 미검증이다.

root 추가 확인: 기존 Q22의 단일 private PDE1 table은 원본 PT VM-page 단위
통계에 충분하지 않다. F25의 기존 FS calibration 및 high-CS 전환 이후 active
root user 영역을 비우고 연속 PT pair를 준비한다. 원본 CR3 write로 사전 갱신한다.
high shared supervisor mappings는 그대로 둔다. 이 빈 user 영역의 mapping count는
0이며, 공유 kernel direct alias는 user PV 소유권의 근거로 취급하지 않는다.

Python 사전 진단은 VM size=8192, hardware page=4096, PT section=8388608,
PT pair 후보 0x810000/0x811000 및 frame 후보 0xb00000의 writable supervisor
high aliases를 확인했다. bootstrap 단계의 managed bounds/descriptor base는 0이다.
따라서 이들은 원본 전체 pmap_init 결과가 아니라 명시적인 합성 입력이어야 한다.
descriptor arena는 물리 범위와 index 식에서 Python으로 계산하고 충돌 검사한다.

## 실행 및 관찰

1. 보존 해시를 확인하고 F25 초기 상태를 재사용한다. 원본 startup prefix,
   page init/free로 detached free seed를 만든다. allocator를 mock하지 않는다.
2. 익명 단일 object, pager/shadow/copy 없음, policy=0, 충분한 free reserve 조건,
   빈 대상 hash/memq, 비어 있는 user mapping과 PT extension을 명시적으로 준비한다.
3. 실제 copyout/copyoutmsg의 nonpresent fault를 관찰한다. CPU 자동 frame 생성은
   기존 backend에서 증명되지 않았으므로 error=nonpresent write인 합성 frame
   경계를 명시한다. 기존 RO error frame을 재사용하지 않는다.
4. 원본 trap/vm_fault/allocator/zero-fill/pmap/IRETD/원래 fault 명령을 실행한다.
   함수 patch, call mock, fault 이후 API PTE 수정이나 성공을 위한 TLB flush 금지.
5. lookup miss, alloc 반환, zero-fill 직후 전체 frame=0, PV/통계/PTE stores,
   vm_fault=0, 동일 CPU frame의 IRETD, 재시작 및 실제 payload와 나머지 zero 보존을
   서로 다른 관찰 지점으로 고정한다. A/B roots, 대상 hardware halves, flags를 대조한다.
6. 전체 trace 원본 바이트, 호출/분기, 메모리 변화, stack/callee, 잠금/queue/count,
   다른 root와 기존 버퍼 보존을 독립 Python audit와 음성 대조로 검산한다.
   코드 후 교차검토, 재실행 결정성, 입력/산출물 해시 검증 후에만 결과를 확정한다.

## 범위와 중단 기준

준비하지 않은 pager/PT expansion/PV node allocation/wait/panic 진입이나 추가 fault는
진단을 남기고 실패로 처리한다. 합성 준비를 원본 생성/전체 소유권의 증거로 쓰지 않는다.
검증되지 않은 부분을 누락시키거나 반환값 성공만으로 매핑 완료를 판정하지 않는다.
모든 계산은 Python. 정본 binary/DB/exports, references, 이전 보고서, 07_kernel은
변경하지 않는다. 검증 코드는 복원 커널 소스가 아니며 GCC 2.7 구현은 아직 시작하지 않는다.
