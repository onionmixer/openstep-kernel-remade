# 실제 쓰기 이후 dirty 매핑 제거 검증

보고서32의 원본 fault/할당/byte-write 경로를 새로 실행한 후, 원본 `pmap_remove`를
연결했다. dirty/reference 메타데이터 반영과 user PTE/PV 제거, free PT queue 이동을
확인했다. **DATA page 해제나 kernel wired PT backing 반환을 검증한 것은 아니다.**

## 입력과 관찰 범위

입력 행렬은 root A/B, `_copyout`/`_copyoutmsg`, destination `0x100/0x1100`,
prefix EFLAGS `2/0x602`, zone sleepable `1/0`이다. Python 집계는 32개 사례다.
삭제 caller EFLAGS는 모든 사례에서 명시적으로 2로 준비한다. prefix flag 행렬을
삭제 함수의 모든 flag 조합 검증으로 확대하지 않는다.

새 prefix의 setup, 시작/실제 fault/CPU frame 입력 직후/최종 상태, 원본 trace와
전체 write 기록을 확정32의 동일 scenario와 정확 비교했다. 32의 중간 points와
zero_chunks는 다시 수집하지 않았다. 따라서 trace/store/boundary 동등성이며
32 전체 중간 CPU 관찰을 이번에 새로 검증했다는 주장이 아니다.
이전 생산 함수 `case/save/main`은 호출하지 않는다.

prefix 이후 명시적 입력은 physical segment 표와 count, 지정된 caller stack,
callee-saved GPR/ESP/EFLAGS뿐이다. CR3/selector/dirty PTE와 VM 메타데이터는
수정하지 않았고, 이 경계 이후 memory API 보정·mock·명령 patch·추가 CR3 reload는 없다.

합성 segment는 DATA `[0xb00000,0xb02000)`→PAGE `0x683000`,
PT `[0xb02000,0xb04000)`→PG `0x683100`이다. 원본 stride `0x1c`, page descriptor
stride `0x30`과 반개구간 산술을 Python으로 검사했다. 실제 remove의 lookup은
대표 DATA 한 번이다. PT segment 경계 예상값은 독립 Python 모델 검사이며
PT segment의 원본 lookup 실행이나 실제 물리 segment 생성 검증이 아니다.

## 원본에서 확인한 상태 전이

`18faac`의 FS INVLPG가 각 HW page에 선행한다. dirty 대상 lookup은 `178894`,
clean 해제는 `18f95a`, descriptor modified/reference는 `18f95e/18f96a`에서 수행된다.
두 번째 HW PTE만 dirty인 경우 **첫 PTE clear → 대표 DATA lookup → 두 번째 clear**다.
첫 번째 HW PTE가 dirty인 경우와 이 순서를 구별한다.

`18f9bc`는 PV owner만 0으로 만들고 stale VA는 유지한다. `190f90`의 감소 계수는
HW PTE 수가 아니라 VM page 하나다. `191040`은 PDE 전체를 지우지 않고 present만
해제하며, `19104d` 이후 extension을 active PT에서 free PT queue로 옮긴다.

| 항목 | 삭제 전 | 삭제 후 |
|---|---|---|
| DATA vm_page queue/clean byte | `0x22` | `0x02` (active 유지) |
| DATA descriptor modified/reference | `0` | `3` |
| DATA object resident / page tabled | `1 / 4` | 동일 |
| user pmap resident / wired | `1 / 0` | `0 / 0` |
| active PT / free PT / total PT | `1 / 0 / 1` | `0 / 1 / 1` |
| kernel pmap resident / wired | `1 / 1` | 동일 |
| PG wire count / global wire count | `1 / 1` | 동일 |

DATA payload, object/hash/active queue, kernel object/map/entry/zone, PG 및 kernel wired
PTE가 보존된다. `_pmap_remove`의 EAX 7은 관찰된 `splx` 잔여값이며 성공 반환 ABI로
해석하지 않는다. 원본 `splx`의 STI와 caller DF-clear 조건도 별도로 확인했다.

## 검증 자료

- [계획](PLAN.md), [코딩 전·후 교차검토](CROSS_REVIEW.md)
- [실행기](dirty_remove_review.py), [독립 감사기](audit_results.py)
- [실행 사례](dirty-remove-cases.json), [실행 집계](dirty-remove-summary.json)
- [독립 감사 결과](independent-audit.json), [음성 대조 결과](negative-controls.json)
- [새 실행 재현 결과](reproducibility.json), [입력 해시](input-hashes.json)
- [최종 보존 검증](verification.json), [산출물 해시](artifact-hashes.json)

Python 집계: 원본 삭제 경로 11,520 instruction heads, dirty lookup 32회,
PTE clear 64회, PDE present 해제 64회. 독립 감사 32개 사례와 증거 훼손 대조 44개를
검사한다. 최종 완료 판정은 위 JSON의 성공 값과 재현/보존 검증을 함께 확인한다.

독립 감사기는 실행 모듈을 import하지 않는다. 원본 Mach-O에서 명령을 읽어 trace의
연결과 write opcode/폭을 검사하고, 모든 캡처 영역을 write 순서대로 재구성한다.
lookup 인자와 raw stack, segment 산술/반환값, 핵심 store의 PC/주소/폭/값/순서,
중간·최종 상태 모델을 연결한다. hardware A/D 예외는 기존 공유 kernel alias로
제한하며 user PTE/PDE 삭제를 임의의 hardware 변화로 허용하지 않는다.

이는 동일 emulator backend의 기록 감사와 재현이다. 모든 명령의 CPU flag나 모든
store 유효주소를 독립 CPU 모델로 재평가한 것은 아니며, native IDT/frame/RF/CPL,
실제 TLB/cache·동시성·전체 부팅/ownership을 증명하지 않는다.
원본/공개 소스/이전 보고서/Ghidra·IDA 보존본/`07_kernel`은 변경하지 않는다.
Ghidra 스킬은 보존된 ASM과 원본 근거를 읽기 전용으로 대조하는 데 사용했다.
전체 분석 및 GCC 2.7 구현·빌드·부팅은 아직 완료하지 않았으며
[잔여 분석](OPEN_ITEMS.md)을 계속 수행한다.
