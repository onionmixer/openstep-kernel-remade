# 보고서33 계획 — 실제 쓰기 이후 dirty 매핑 제거

상태: 코딩 전 원본 검토 및 독립 Codex 검토를 거쳐 실행·감사를 진행한다.
보고서32, 원본 바이너리/공개 소스, Ghidra/IDA 보존본, `07_kernel`은 변경하지 않는다.
Ghidra 스킬은 보존된 ASM/원본 명령 대조에 사용하며 live DB를 수정하지 않는다.
계산·주소/필드 산술·해시·집계는 Python만 사용한다.

## 연결할 경로

보고서32와 같은 입력 행렬에서 `setup`만 재사용하고 실제 fault → 명시적 CPU
frame 입력 → 원본 신규 data/PT 할당 → IRETD → byte write를 새로 실행한다.
확정된 32의 실행 trace, CPU/메모리 상태, write 기록과 정확 비교한다.
이전 `case`, `save`, `main`은 호출하지 않으며 파일 생산은 이번 디렉터리에서만 한다.
이는 동일 backend의 기존 감사 범위 계승이지 독립 hardware 실행 증명이 아니다.

이후 caller 경계에서 물리 segment 표와 호출 stack/register만 명시적으로 준비하고
`pmap_remove(PMAP, VA, VA + VM)` 원본을 실행한다. 이후 memory API 보정, 함수 mock,
명령 patch, 추가 CR3 reload는 하지 않는다.

## 사전조건과 원본 근거

- `00178894.asm`: segment stride `0x1c`, `+0` vm_page 배열 base, `+4` 첫 page index,
  `+0x14/+0x18` 물리 주소의 반개구간. page descriptor stride `0x30`.
- 합성 segment는 DATA→PAGE, PT→PG 각각 한 VM page 범위다. PAGE/PG는 연속
  descriptor 배열이 아니므로 segment를 분리한다. 미사용 필드는 합성 0으로 명시한다.
- 두 segment 끝 다음에 count가 위치하므로 중첩을 Python으로 검사한다.
- `18f8e4`에서 첫 PTE의 대표 물리 주소를 저장한다. 두 번째 HW PTE가 dirty여도
  `18f951/18f955`의 lookup 인자는 대표 DATA다. lookup 결과 NULL 확인은 없으므로
  유효 segment는 필수 선행조건이다.
- DATA 끝 경계는 다음 PT segment의 시작이다. 이번 remove가 실제 조회하는 것은
  DATA이며 PT segment 생성/조회나 실제 부팅의 memory discovery를 완료로 주장하지 않는다.
- `18faac` 선행 FS INVLPG, `18f95a` clean 해제, `18f95e/18f96a` modified/reference,
  `18f96e` PTE clear, `18f9bc` PV owner만 clear, `190f90` 계수 감소,
  `191040` PDE present 해제, `19104d` 이후 active→free PT queue를 검증한다.
- DATA는 active/tabled/resident를 유지하며 payload도 보존한다. PG/kernel wired PTE,
  kernel object/map/zone 및 kernel pmap 소유 계수도 유지된다. backing 해제는 후속 경로다.

## 감사와 종료 gate

원본 Mach-O decoder와 독립 상태 모델을 사용하며 실행 모듈을 감사기에 import하지 않는다.
확정32의 입력/결과 provenance, prefix 정확 비교, 명시적 입력 경계의 허용 변경 목록,
모든 신규 write의 원본 opcode/폭·trace index 및 전체 캡처 영역 replay를 검사한다.
각 checkpoint를 raw stack/CPU와 연결하고 대표 phys lookup 인자/반환값, 선행 invalidation,
HW PTE 수와 VM 계수의 차이, dirty/reference 순서, PV stale VA, PT queue/소유권을 확인한다.
hardware A/D 허용은 필요한 기존 공유 kernel alias에만 한정하고 사용자 PTE/PDE의
삭제를 hardware 변화로 허용하지 않는다. 누락 trace/write, 잘못된 lookup, premature free,
틀린 계수·alias·입력 경계·stale 값 등 음성 대조를 통과시킨 뒤 처음부터 재실행한다.
원본/이전 산출물 보존과 새 manifest를 최종 확인한 뒤에만 이번 보고서를 확정한다.

native CPU frame/IDT/RF/CPL, 실제 TLB/cache, 동시성, 전체 ownership/startup,
자원 부족·pager/COW/대기, GCC 2.7 구현/빌드/부팅 및 후속 아키텍처는 여전히 미완료다.
