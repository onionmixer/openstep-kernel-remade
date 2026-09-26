# 높은 세그먼트의 실제 IDT 전달 — RF 불일치 진단

상태: **진단 기록은 재현됐지만 RF 계약은 실패한다. 원본 커널 분석 완료가 아니다.**

설치된 QEMU 6.2.0 TCG, pc-i440fx-6.2/qemu32 단일 CPU에서 별도 합성 BIOS와 RAM을
실행했다. 네트워크·host disk·실기 커널은 연결하지 않았다. 원본 바이너리/분석 DB 및
07_kernel을 변경하지 않았다. 모든 이미지 생성·주소·분기 fixup·수치·해시는 Python을 썼다.
Ghidra 스킬로 보존 원본 ASM을 대조하고 코딩 전 Codex 교차검토를 받은 후 직접 확인했다.

## 관찰과 미충족 계약

CS8·DS/SS10은 base c0000000, FS50은 base0이며 vector14는 trap gate8f다.
원본 189d1b의 FS byte-store와 동일한 648819를 다른 주소에 배치했다. CPU 모델이
직접 error/EIP/CS/EFLAGS를 쌓고 IDT를 통해 합성 handler로 들어갔다. host API에 의한
frame 주입/context 복구/숨은 예외 필드 수정은 없다.

합성 handler는 원시 frame을 보존하고 PTE를 설치한 다음 error word를 제거해 IRETD한다.
첫 retry에서 e4, PTE NP+FS INVLPG 이후 두 번째 retry에서 f5가 주변 sentinel을 유지하며
저장됐다. IF/DF의4개 조건에서 총8회 PF를 관찰했다. 이는 원본 copyout·OPENSTEP handler
전체 실행이 아니라 **재배치된 동일 명령과 합성 handler의 QEMU CPU 모델 진단**이다.

| 초기 flags | 관찰된 CPU 저장 flags | RF 계약상 요구 flags |
|---|---|---|
| 0x2 | 0x2 | 0x10002 |
| 0x202 | 0x202 | 0x10202 |
| 0x402 | 0x402 | 0x10402 |
| 0x602 | 0x602 | 0x10602 |

요구값은 Python으로 계산했다. RF 조건의 근거는 Intel SDM 3B 253669-060US
(September 2016), §17.3.1.1의 fault-class exception 규칙이다.
[Intel 원문](https://www.intel.com/content/dam/www/public/us/en/documents/manuals/64-ia-32-architectures-software-developer-vol-3b-part-2-manual.pdf)

PUSHFD 결과는 RF를 포함한 raw CPU flags와 동일하지 않으므로 별도 필드로 기록했다.
RF 불일치는 PUSHFD 값이 아니라 **CPU가 만든 원시 stack frame에서 복사한 값**이다.
handler의 PUSHAD/PUSHFD scratch는 frame 밖이며 CLD도 저장 frame을 쓰지 않는다.
이를 root와 독립 검토자가 각각 원시 코드/주소/출력으로 확인했다.

설치된 QEMU 내부 원인의 확정은 남아 있다. 해당 버전 소스의 웹 접근 실패를 다른
버전 소스로 대체해 확정하지 않았다. QEMU 결과를 물리 CPU의 규칙으로 채택하지 않는다.

## 검증 산출물

- [계획](PLAN.md), [교차검토](CROSS_REVIEW.md)
- [실행·raw 출력·해시](native-probe.json): case별 BIOS/tables/code/data/output/qemu.log/run.json
- [독립 진단 감사](diagnostic-audit.json): 고정 ROM/code/padding, descriptor/table,
  command/run metadata/필수 해시, handler frame 복사, QEMU event 로그와 raw record,
  payload/PTE/SP를 검사하며 RF 실패를 유지한다.
- [훼손 대조](negative-controls.json):301개 거부. main/helper의 각 바이트를 하나씩
  변조하는262개 대조를 포함하며 CPU 동작 전수 검증과는 다르다. RF를 가정해 바꾼4개 양성 대조는
  Python 메모리 안의 모델 시험이며 실제 CPU·guest memory·기록 파일에는 적용하지 않았다.
- [재현](reproducibility.json):31개 파일 해시 동일, 엄격한 RF 명령의 실패도 재현.

```sh
python3 -B native_probe.py --collect-diagnostics
python3 -B audit_native.py
python3 -B test_native.py
python3 -B reproduce_native.py
```

`--collect-diagnostics`는 실패를 기록하고 다음 독립 조건을 수집하는 모드이지
RF 계약을 통과시키는 옵션이 아니다. `python3 -B native_probe.py --single`은
현재 RF assertion에서 종료 코드1로 실패하는 것이 확인된 상태다.

추가 교차검토에서 이전 감사의 초기 ESP/record 포인터 및 빈 hash/임의 command
허용 문제가 발견되어 root 재현 후 보강했다. 실제 기록에서 frame 훼손을 발견한 것은
아니다. 고정 기대 이미지와 command 일치는 실행 사실 자체를 독립적으로 증명하지 않는다.

## 다음 분석

다른 독립 CPU 모델에서 RF와 예외 전달을 대조하고, 검증된 조건을 바탕으로 원본
GC 후의 RAM/아키텍처 상태를 옮기는 경계를 검토해야 한다. 현재는 그 상태 이전도,
원본 handler→IRETD→copy retry도 검증하지 않았다. [이전 전체 잔여 의무](../continuous-review-20260912-36/OPEN_ITEMS.md)를
모두 유지한다. 일반 GPR/flags/분기/메모리 EA의 전수 의미 검사와 물리 CPU 검증도 별도다.
