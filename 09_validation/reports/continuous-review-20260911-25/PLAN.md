# 보고서25 코딩 전 계획 — 실제 entry의 VM protection 거절

계획 작성 당시 상태: 계획 및 읽기 전용 교차검토만 완료. 시험 코드는 아직 작성하지 않았으며,
이 디렉터리를 실행 검증 완료 보고서로 취급하지 않는다.

report24는 원본 trap/VM lookup miss/recover/IRETD를 연결했지만 map miss만
검증했다. 다음에는 주소를 포함하는 VM entry가 실제로 발견된 뒤 쓰기 권한이
거절되는 원본 경로를 확인한다. 이는 전체 잔여 분석 의무 중 추가 경로이며
page-in 성공·재시작이나 native IDT 전달을 대체하지 않는다.

## 코딩 전 독립 검토와 거부한 의견

`/root/trap_plan_review`가 원본 ASM·바이트·canonical C·SDK를 읽기 전용으로
검토했다. root는 관련 원본 ASM/C, Darwin 및 NeXTMach vm_map.c, Darwin
vm_map.h/kern_return.h와 report24 실제 vm_fault 인자를 직접 대조했다.

독립 검토자는 처음에 부분 복사를 위해 “첫 하드웨어 페이지 RW entry, 다음
하드웨어 페이지 READ entry”를 제안했다. **이 제안은 채택하지 않았다.**
root가 VM page와 하드웨어 page의 차이를 지적하고 Python 및 실제 인자를
대조한 후 검토자도 제안을 철회했다. Codex 의견은 정확성의 증거가 아니다.

확인한 Python 계산 및 report24 실행 근거:

- `_page_mask=0x1fff` → VM page size `0x2000`.
- 하드웨어 PTE page size `0x1000`.
- 실제 CR2=`0x601000` 사례의 원본 `_vm_fault` 주소 인자는 `0x600000`.
- `0x601000 & ~0x1fff == 0x600000`; 해당 VM 범위는 `[0x600000,0x602000)`.
- 현재 사용자 buffer span=`0x2000`은 VM page 하나다. 실제 VM 경계에서 부분
  쓰기를 검증하려면 다음 VM page까지 범위·PTE·버퍼 모델을 확장해야 한다.

## 최소 정합 fixture와 게이트

- 원본 page_mask를 읽어 범위·정렬을 Python으로 계산. READ entry 범위의 낮은
  하드웨어 PTE를 모두 RO로 구성하여 첫 PTE RW/VM 전체 READ 모순을 피한다.
- 원본 높은 CS 및 IDT 설정, root 선택, 실제 #PF 관찰과 frame 주입 경계를
  report24처럼 분리한다. native 자동 전달 실패를 성공으로 처리하지 않는다.
- 합성 단일 entry의 양방향 sentinel 연결을 구성. hint=entry의 빠른 경로와
  hint=sentinel의 목록 탐색을 구분한다. hint 변화는 실제 원본 쓰기로 판단하고
  무조건 entry로 갱신된다고 가정하지 않는다.
- entry flags+0x18=0, protection+0x1c=READ. max_protection+0x20, wired+0x28 등
  거절 전 읽히지 않는 필드는 초기화와 실제 검증을 구분한다.
- map+0x24의 pmap pointer는 CR3 물리 주소와 같은 것이 아니다. 미사용 필드를
  임의로 채운 것으로 전체 map 생성 정합성을 주장하지 않는다.
- 가능한 경우 원본 lock_init을 실행하여 owner/read count/can_sleep/interlock
  상태를 만들고, lock_read/lock_done 후 복원 검사. 경합 없는 조건임을 명시한다.

## 필수 원본 경로

`0x178144` submap 검사 → `0x17815c` protection 읽기 → `0x178165` 요청과 AND
→ `0x17816d` lock_done → `0x178172` EAX=2 → vm_fault 조기 반환
→ kernel_trap/recovery/IRETD → 원본 EFAULT 반환.

`KERN_PROTECTION_FAILURE=2`는 SDK와 원본 immediate를 함께 대조한다.
이전 empty-map miss=1과 구분하고, 원본 frame 변경·lock·uthread·counter·recover·
caller 상태 및 지정 버퍼/guard를 검증한다. 공개 소스의 OLD_VM_CODE/USE_VERSIONS
조건부 layout을 원본 ABI와 같다고 전제하지 않는다.

권한 허용 입력으로 `0x17817c`에 도달하는 대조를 추가할 수 있으나, 그 지점에서
중단하면 **권한 검사 분기 대조**일 뿐 VM fault/page-in 성공이 아니다.

## 보존

보고서24 및 이전 manifest·원본·reference sources·Ghidra/IDA DB·07_kernel은
수정하지 않는다. 계산은 Python만 사용한다. 새 실행·독립 검산·재현·보존 증거가
갖춰진 뒤에만 해당 범위의 완료를 판정한다. GCC 2.7 빌드 및 전체 분석은 미완료다.
