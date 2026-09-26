# QEMU CPU 모델의 반복 페이지 폴트 — 코딩 전 검토

보고서36 실제 fault 재진입의 실행기 제약을 조사하기 위한 선행 진단이다.
vm_contract_review27의 코딩 전 읽기 전용 검토를 받았다. root는 보존된 원본
copyout(189d1b), trap/IRETD(186d7c), idt_init 계약을 직접 대조했다.

설치된 QEMU 6.2.0의 TCG 단일 CPU를 사용한다. 별도 합성 BIOS/RAM/code만
로드하고 host disk·네트워크·실기 커널을 연결하지 않는다. timeout/reset/빈 기록은 실패다.
프로그램 이미지·주소·descriptor·table·분기 fixup·수치·해시는 Python으로 생성/계산한다.
이는 진단용 기계어이며 GCC 2.7 커널 소스 구현이 아니다.

## 검증 경계

- ROM→PE→PG→high CS8/DS·SS10, FS50 flat 전환을 명시한다.
- selector, segment-relative EIP, linear IDTR/GDTR 및 SS.base+ESP paging을 구별한다.
- vector14는 present 32-bit trap gate(8f)다. 다른 gate는 별도 fatal 경로다.
- 원본과 동일한 FS byte-store opcode로 NP write를 일으킨다. CPU 모델이 직접
  frame을 만들고 IDT를 통해 들어가며 frame 주입·context 복구는 하지 않는다.
- 합성 handler는 CPU frame과 CR2, PUSHFD 관측값을 기록하고 mapping을 설치한다.
  error word를 제거한 뒤 원본과 같은 IRETD opcode로 돌아가 store를 재시도한다.
- PTE를 다시 NP로 만들고 FS override INVLPG 후 같은 store를 재실행한다.
  서로 다른 payload와 주변 sentinel, PTE 및 SP를 기록한다.
- IF/DF 각각의 설정 조건을 시험한다. handler는 PUSHFD 관측을 먼저 보존하고 CLD한다.
  PUSHFD는 RF의 raw 관측 수단이 아니다. RF 판단은 CPU가 저장한 frame과 구별한다.

## 주장하지 않는 것

물리 CPU·OPENSTEP handler 전체·원본 GC 상태 이전·전체 부팅·동시성 검증이 아니다.
동일한 opcode를 재배치해 시험한 것이며 원본 copyout 전체 실행으로 표현하지 않는다.
성공하면 원본 상태를 QEMU로 이전하는 후속 경계 검토에 사용한다. 전체 잔여 의무는
[보고서36](../continuous-review-20260912-36/OPEN_ITEMS.md)을 유지한다.

## 추가 감사 보강 — 코딩 전 검토

독립 검토에서 초기 ESP/record 포인터를 변경하거나 hashes를 비우고 command를
바꾸어도 기존 감사가 통과하는 반례를 받았다. root가 Python 메모리 내 변조로
각 반례를 직접 재현했다. 원본/실행기/실제 guest 기록은 수정하지 않는다.

코딩 전에 검토자에게 전체 ROM·main/handler/fatal·padding·labels/lengths 고정,
필수 해시 집합, case 경로·loader 주소·run metadata/command 연결을 검토받았다.
검토자가 지적한 prefix/명령 길이, ES 로그, frame/record/stack 비중첩을 포함한다.
producer의 images()를 재사용하지 않고 별도의 고정 기대 명령 바이트와 descriptor
계약을 사용한다. 이는 실행 사실의 독립 증명이나 CPU 의미 전수 검증이 아니다.
