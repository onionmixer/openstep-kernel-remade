# 105차 범위·검증 방법

## 자료와 변경 제한

원본 mach_kernel, 그 바이너리의 Ghidra ASM/C/metadata·심볼·section 정보,
현재 정책과 이전 원본 분석 보고서만 사용했다. 01_resources/07_kernel, 다른 커널 코드,
외부 문서·웹·저장소는 참조하지 않았다. 원본·DB·export·확정 보고서를 수정하지 않았다.
생성물은 이 디렉터리뿐이며 구현·복원·빌드·포팅·실행·에뮬레이션을 수행하지 않았다.

Ghidra 스킬은 기존 export와 raw 바이트 대조에 적용했다. live DB 조작은 하지 않았다.
새 독립 계획 교차검토 미수신 제한을 유지하며, 반복 요청/agent 우회는 하지 않았다.
모든 산술/주소/크기/개수/비트/해시는 Python으로 계산했다. inline 검증은 정적 assertion이며
커널 emulator나 실행 가능한 복원 모델을 만들지 않았다.

## 선택한 일반 본문

- lock_init 0x15b54c, lock_sleepable 0x15b594, lock_write 0x15b5d0,
  lock_done 0x15b73c, lock_read 0x15b7d0.
- lock_read_to_write 0x15b890, lock_write_to_read 0x15b9b0,
  lock_try_write 0x15ba2c, lock_try_read 0x15ba98,
  lock_try_read_to_write 0x15bae8, lock_set_recursive 0x15bb9c,
  lock_clear_recursive 0x15bbe0.
- host_stack_usage 0x168bb8, thread_sleep 0x163320,
  splsched 0x18be68, splx 0x18b544.
- bzero 0x101600, memset 0x101630 — 의미 연결의 핵심은 lock_init의 정확한 zero-fill 요청이다.
- 104차 연결부 stack_statistics 0x15b49c, stack_finalize 0x168b50,
  initKernelStacks 0x15ab9c와 wait 연결부 assert_wait 0x162f20, thread_wakeup_prim 0x1631a0.

추가로 위 본문의 bounding range 안에 metadata가 분리한 기존 fragment들을 원본 그대로
대조했다. memset alignment table의 명목상 목적지 중 해당 경로의 국소 guard로 도달할 수
없는 경우와, panic 다음 fallthrough fragment를 구분한다. fragment를 신규 일반 함수나
실행 성공으로 세지 않는다. 모든 fragment 연결은 evidence의 fragment_links에 있다.

## 검증 절차

1. 104차 fresh 검증과 고정 checkpoint SHA를 다시 검사한다. 이전 입력과 보존 파일을
   현재 허용된 원본 분석 범위로 제한해 재해시한다. 제외한 과거 항목은 열지 않는다.
2. 원본 SHA와 Mach-O header/segment/section을 검사하고 명령 주소를 파일 offset으로
   매핑한다. zerofill에는 파일 초기값을 부여하지 않는다.
3. 선택 ASM 각 명령의 원본 바이트를 Capstone 4.0.2 x86-32로 해독하고 길이/head,
   metadata body byte 집합, 직접 분기 목적지, 중복 없음을 검사한다.
4. 필드 폭/가감/mask/분기/호출 대상/잠금 순서/SPL 특권 명령을 별도 assertion으로
   확인한다. WORD 전 범위 identity와 조건부 산술 사례는 Python으로 검증한다.
5. memset의 short/alignment/bulk 및 wakeup table 원본을 읽고 local guard가 허용하는
   index의 목적지를 검사한다. 명목상 table slot 전체와 실제 허용 index를 분리한다.
6. strict 인접 MOV/TEST/JNZ, NOP-tolerant 같은 레지스터 backedge, snapshot countdown을
   분리 기록한다. 이것이 모든 lock/loop 패턴을 망라한 검사라는 주장은 하지 않는다.
7. ASM 모집단 전체를 manifest와 해시 대조한 뒤 지정 직접 CALL와 literal operand만
   조사한다. alias/bulk/indirect/out-of-function 해석을 대체하지 않는다.
8. 생성 JSON을 새 계산 결과와 정확히 비교하고 문서 링크/파일 크기/해시를 checkpoint에
   기록한다. 마지막 fresh 재실행에서 같은 결과가 나오는지 다시 검사한다.

집계: 일반 본문 23, fragment 14, head 1459, body bytes 3947,
direct branches 216, CALL 31, indirect transfers 6, warning lines 8,
critical instructions 160, table entries 106, strict spins 29, NOP-tolerant spins 30,
snapshot countdowns 4, inputs 118, preserved paths 929.
WORD 산술 identity 사례 65536개와 flags/readers 조합 64개를 검사했다.

ASM 모집단은 5253개이며 sorted path/size/SHA JSON의 Python SHA-256은
`742617851f014a94309d47296900fc5e27b5ad5a862f588590559fe5f334471d`이다.
검출된 지정 직접 CALL은 9개, literal 참조는 38개다. 여기의 literal 참조에는
PUSH immediate와 memory read/write가 모두 포함되므로 writer 수와 같지 않다.

## 미입증 범위

모든 lock caller의 소유권/최대 count/재진입, interlock 0/1 runtime 불변식,
캐시 목록과 count 일치, interrupt/pending callback의 도달성·수명, lost wakeup/hang 여부,
VM fault/wire/remove/rollback, reserve 최종 해제, 물리 residency는 미완료다.
memset 전체 일반 인자 의미·SPL의 모든 유효 수준과 table writer·RPC host 변환도 남아 있다.
선택 본문 해독 통과와 전체 kernel semantics/실행 성공은 별도 판정이다.

[결과](README.md) · [증거](object-lifetime-evidence.json) · [남은 분석](OPEN_ITEMS.md)
