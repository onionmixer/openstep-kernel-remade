# 코딩 전 계획 — 분리된 사용자 매핑의 copyout 및 보호 경계

사용자 요구에 따라 독립 Codex `/root/copyout_plan_review`의 읽기 전용 교차검토를
코딩 전에 수행했다. 주 에이전트가 원본 assembly와 선행 fixture 코드를 읽어
다시 확인한 조건만 채택한다. 모든 계산은 Python으로 수행한다.

## 근거와 교차검토 반영

- `_copyout` `00189cec.asm`, `_copyoutmsg` `00189e8c.asm`은 DS source를 읽어
  FS destination에 쓴다. copyin의 REP를 역방향으로 바꾼 함수로 가정하지 않는다.
- 원본 `189e47→189e51→189e5a` 및 `189fef→189ff9→18a002`의 tail 순서는
  offset 2→1→0이다. 단조 증가 prefix 모델로 fault 상태를 계산하지 않는다.
- `_copyout`은 caller destination 슬롯을 바꾸지만 msg는 local 슬롯을 바꾼다.
  caller 인자 전체 불변을 일반적으로 요구하지 않는다.
- report02의 short recover 유지 및 정상 진입에서 실행되지 않는 정렬 dword store
  `189da9`/`189f51`을 원본 경로와 Python 산술로 다시 대조한다.
- report22의 private root 및 low table, 페이지별 구별 패턴, 혼합 CS fixture 한계를 유지한다.

## 순서

1. 이전 manifest와 프로젝트 해시를 읽기 전용으로 검사한다.
2. report22 fixture로 root A/B/B/A 선택과 source/destination 매핑을 확인한다.
3. 전체 copyout/copyoutmsg 정상 호출을 source와 destination의 독립 정렬 및 페이지
   경계 조합으로 실행한다. 목적지 전체 내용, source/inactive context 불변,
   반환주소/ESP/보존 레지스터/recover와 실제 FS store 순서를 검사한다.
4. fresh fixture마다 낮은 destination PTE를 root 선택 전에 변경한다. writable,
   read-only, not-present 조건을 구분하고 WP=0 대조는 원본 MOV CR0에 합성 입력을
   제공하여 설정한다. 변경 전후 CR0를 기록하며 실제 boot 상태로 부르지 않는다.
5. fault 시험은 dword-aligned source로 제한한다. 길이32/destination PAGE-16과
   길이19/destination PAGE-18은 페이지를 가로지르는 단일 store를 피한다.
   후자는 tail offset2의 첫 접근이 다음 페이지이므로 낮은 tail 바이트가 먼저
   기록됐다고 기대하지 않는다. byte length1 read-only와 length0 대조도 구분한다.
6. vector14, EIP, CR2 및 원본 FS store를 함께 확인한 경우에만 페이지 fault 모델
   관찰로 기록한다. 다른 예외·API 오류·fixture 실패는 보존하고 원인을 조사한다.
7. 실제 IDT/trap/IRETD 및 recovery helper는 이번 단계에서 실행하지 않는다.
   이전 synthetic recovery 시험을 이번 paging fault 전달의 증거로 대체하지 않는다.

## 보존과 판정

원본 바이너리, 기존 Ghidra/IDA DB·export·보고서 및 `07_kernel`은 변경하지 않는다.
새 코드는 분석 시험용 Python이며 복원 커널 구현이 아니다. 정상 결과, 잘못된
주소 해석의 Python 반사실, CPU 모델 fault 관찰, 미검증 의무를 분리한다.
Codex의 조건부 승인 자체를 정확성 증거로 사용하지 않는다. 사후 검토도 원본과
계산 결과로 재확인한다. 전체 분석 완료는 이 유한 시험 통과로 선언하지 않는다.
