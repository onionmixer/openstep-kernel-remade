# GC 반환 자원 재사용 — 진단 진행 중

**보고서36은 미확정이다. 계획한 실제 fault 재진입 성공은 입증하지 못했다.**
새로 실행한34 전체 기록이 확정34와 동일함을 확인한 뒤 새copy 호출을 실행했다.
원본189d1b에서 예외가 관찰됐지만 기대한 vector14가 아닌vector8이어서 중단했다.
[진단 기록](latest-prefault.json)에 trace/CPU/쓰기/전후메모리를 보존했다.
이를 정상page fault로취급하여handler를진행하지않았다.

[계획](PLAN.md)은 기존DATA lookup과반환된PG/EXT/KE를신규wired PT 생성에서
재사용하는경로다. src101의245와이전src100의228은Python으로구분했고버퍼/물리메모리를
초기화하지않았다. 재사용/최종retry/독립감사·반례·재현·manifest는아직미완료다.

Ghidra스킬로보존ASM을읽기전용대조하고코딩전독립검토를받았다.
[helper검사](helper-check.json)는[GC helper](gc_prefix.py)의허용변환을확인한다.
기존확정producer/main/파일쓰기와원본/DB/07_kernel변경은하지않았다.

## 새로 조사하는 실행기 제약

설치된Unicorn은2.1.4다. 해당release의
[예외변환 코드](https://github.com/unicorn-engine/unicorn/blob/2.1.4/qemu/target/i386/excp_helper.c)는
이전PF 상태와후속PF가겹치면DF로변환한다.
[interrupt hook 경로](https://github.com/unicorn-engine/unicorn/blob/2.1.4/qemu/accel/tcg/cpu-exec.c)는
callback후exception_index를지우며, 별도의
[정상 예외 전달 경로](https://github.com/unicorn-engine/unicorn/blob/2.1.4/qemu/target/i386/seg_helper.c)에서
old_exception을초기화하는것과구별된다. 이자료는원인후보를설명하며, 설치binary의
실제 반복 fault 결과는 별도 최소 실험으로 확인했다.

[최소 실험](exception-probe.json)의 관찰 결과는 다음과 같다.

| 독립 대조 | 관찰 vector 순서 |
|---|---|
| 같은 UC의 연속 NP | 14 → 8 |
| 중간에 NOP 실행 | 14 → NOP 정상 실행 → 8 |
| 새 UC | 14 |
| 첫 예외 전 context 복구 | 14 → 14 |
| 첫 예외 직후 context 복구 | 14 → 8 |

context 대조는 열거한24개 공개 필드와 RAM hash의 복구 직전/직후 동등성을
검사했다. FPU/SIMD/MSR/숨은 segment cache 등 CPU 전체 동등성은 아니다.
독립 검토자가 선언된 PD/PTE/code로 RAM을 재구성해 hash도 확인했다.
context 복구는 여러 내부 상태를 복구하므로 old_exception 하나만 격리한 실험은
아니다. 이 결과를 OPENSTEP의 high-CS/IRETD/native IDT 전달에 대한 완전한
동등 대조로 취급하지 않는다. context 복구를 커널 UC에는 적용하지 않았다.

[진단 감사 코드](audit_diagnostic.py)는 kernel 재진입이 여전히 vector8에서
중단됨을 확인하고, 명시적 caller 입력·prefault 기록·미커밋 store 제외 및 최소
실험 RAM/CPU 기록을 검사한다. [진단 검증 결과](diagnostic-verification.json)는
계획한 자원 재사용 완료 여부와 별도다. 보고서36 최종 manifest는 아직 만들지 않았다.

진단 재실행 결과가 동일했고, [훼손 대조](diagnostic-negative-controls.json)의
13개 기록 변조를 모두 거부했다. 이는 중단 진단과 최소 실험의 검증이지,
미실행된 handler 이후 코드의 검증이 아니다.

현재kernel 진단의vector8을native OPENSTEP double fault 버그라고단정하지않는다.
반대로backend 의심만으로kernel 분석목표를완료하거나예외를무시하지않는다.
[이전전체잔여목록](../continuous-review-20260912-35/OPEN_ITEMS.md)과GCC2.7 빌드/부팅
등의의무를유지하고, 진단을계속한다.

## 별도 보조 경계: 실제 GC 이후 직접 pmap_enter

[코딩 전 계획](DIRECT_PLAN.md)에 따라 fresh34 전체 결과를 비교한 live UC에서
caller stack·callee-saved GPR·EFLAGS만 설정하고 원본 pmap_enter를 호출했다.
컨텍스트 복구·숨은 예외 필드·CR3·자원 상태를 API로 수정하지 않았다.
이 보조 함수 실행에는 새로운 fault가 없으며 원래 fault/IRETD/retry 검증과 별개다.

[독립 감사](direct-audit.json)는 32개 prefix 조건에서 177440 instruction head,
86400 CPU 쓰기, 65536 PT zero DWORD 쓰기를 검사했다. 수치는 Python으로 계산했다.
이 조건들은 이전 copy 함수·destination·flags·root·zone 분기를 구별하는 것이며,
직접 호출 자체의 인자는 동일한 pmap_enter(PMAP, VA, DATA, 3, 0)다.

- GC가 반환한 PG만 실제로 다시 할당·zero·wire된다. DATA payload/vm_page/OBJ는 유지된다.
- KE의 pop→free→pop과 EXT의 pop을 원본 zone 쓰기·반환 지점으로 연결한다.
- 새 kernel PTE와 user PTE 설치, NP PDE residue의 교체, DATA PV 재등록을 검사한다.
  DATA descriptor attr3은 유지되며 새 user PTE의 A/D에는 전파되지 않는다.
- 최종값뿐 아니라 zone 연결·개수, 객체/map/zone/queue 잠금 필드의 모든 겹치는
  쓰기와 중요한 호출 경계의 잠금 조건을 검사한다. 실제 병렬 실행이나 경합 증명은 아니다.
- 새 보조 경계의 모든 메모리 checkpoint는 기록된 쓰기와 byte-exact로 일치해야 한다.
  이전 감사의 넓은 alias A/D 허용을 새 실험에 적용하지 않는다.

[훼손 대조](direct-negative-controls.json)는 40개 변조를 거부했고, 동일한 translation
bytes를 수용하는 양성 대조도 통과했다. 특히 초기 감사가 허용했던 coherent zone
unlink/count·KO lock 변조는 root가 독립 재현한 뒤 회귀시험에 추가했다.
수정 내용과 한계는 [교차검토 기록](CROSS_REVIEW.md)에 남겼다.

새 producer·감사·대조시험을 다시 실행해 [재현 기록](direct-reproducibility.json)의
5개 산출물 해시가 모두 동일함을 확인했다. 보존 검사도 통과했다.
현재 파일 해시는 [진행 중 체크포인트](checkpoint.json)에 별도로 기록한다.
전체 보고서36의 최종 manifest는 여전히 없으며, 남은 작업은 [잔여 목록](OPEN_ITEMS.md)에 있다.
