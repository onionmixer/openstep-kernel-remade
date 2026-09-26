# 열린 항목 1·2 완료 감사

기준 문서: `continuous-review-20260920-106/OPEN_ITEMS.md`.

이 문서는 해당 문서의 **1번과 2번만** 완료로 판정한다. 3번부터 5번은 이 판정에 포함하지
않으며, 106차 문서에 적힌 대로 여전히 남아 있다.

## 1. page/object/map/pmap의 간접 호출·table·alias writer·runtime initializer

| 요구 주제 | 원본 바이트 근거 보고서 |
|---|---|
| VM 계열 간접 호출과 pmap 창의 간접 호출 전수 | 120 |
| `smmap` callback과 정확한 address table base의 전수 접근 | 133, 134 |
| vnode pager table, pagein/pageout slots, count/table writer | 109, 113, 128, 139, 143 |
| page size/mask/shift의 runtime writer와 값 | 108, 126 |
| page template source, 복사 범위, alias writer | 108, 127 |
| object `+0x30` template/runtime alias와 collapse clear | 111, 122, 141 |
| map entry WORD `+0x28`의 폭, 모든 접근/쓰기 및 초기화·RMW 경계 | 112, 121 |
| pmap 초기화·create·enter retry·PV lock/reclamation 경계 | 110, 114, 135, 145 |

따라서 1번에서 요구한 runtime 값·경계·수명은 각 대상별로 원문 명령어와 전수/직접 호출
검사에 의해 보존되어 있다. 구조체 C 타입이나 export 함수명은 이 판정의 근거가 아니다.

## 2. VM COW/shadow/pager/PV, vm_fault, copy/map fork/deallocate

| 요구 주제 | 원본 바이트 근거 보고서 |
|---|---|
| COW/object copy/shadow와 직접 caller 후속 처리 | 107, 129, 130 |
| pager table, vnode pagein/pageout 및 caller 경계 | 109, 113, 128, 139, 143 |
| PV enter retry, per-entry exclusion, unlink/replacement, `_zfree` 경계 | 110, 114, 145 |
| `vm_fault` 결과 설정 지점, 직접 caller 전체, unwire/copy-entry 경로 | 107, 119, 136, 140, 142 |
| map copy 상태·cleanup/rollback 및 wrapper/직접 caller 전체 | 117, 118, 124, 125, 131 |
| map fork·pmap create·task_create caller 경계 | 115, 123, 135 |
| object deallocate 직접 caller 전체와 terminate/deallocate 잠금 순서 | 116, 137, 138, 144 |

따라서 2번의 지정 범위는 오류값 전달, cleanup/rollback 분기, caller-wide 후속 명령,
그리고 확인 가능한 lock/PV 수명 경계까지 원본에서 확장 확인됐다. 이 결론은 VM 전체의
형식적 정확성이나 아직 분석하지 않은 간접 경로까지 주장하지 않는다.

## 무결성 검증

Python으로 107–145차 보고서의 checkpoint 파일을 검증했다. 검사한 보고서는 39개이고,
일치한 보고서는 39개, 불일치한 보고서는 0개였다. 각 checkpoint는 파일 크기와 SHA-256을
비교했다.

## 남은 작업

106차 열린 목록의 3–5번: IRQ/SPL/lock 진행성, scheduler·IPC·thread/task 종료와 callback
수명, 그리고 context·메모리 관리·VFS/network/DriverKit/ABI 등 전체 미완료 영역.
