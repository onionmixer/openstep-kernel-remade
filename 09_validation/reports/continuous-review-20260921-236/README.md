# 236차 정적 검토 — `_idt_init`의 8-byte stride loop와 최종 `LIDT`

원본 OPENSTEP x86 `mach_kernel`의 `_idt_init`을 원시 명령으로 대조했다. 재부팅·QEMU·외부 소스·
구현은 사용하지 않았다.

`_start`가 `_idt_init`을 직접 call한다. `_idt_init`은 두 stack-local dword를 0으로 초기화하고,
loop마다 두 번째 local을 8만큼 증가시키며 첫 local을 1 증가시킨 뒤 signed `<= 0xff` 조건으로
되돌아간다. 이 명령 순서를 Python으로 계산하면 256회이며, loop body의 local offset은 0부터
2040까지 8씩이고 loop 뒤 값은 2048이다.

각 반복은 `EDI=[EBP-8]`로부터 `EDI+0x001e1a04`, `EDI+0x001e1a08`을 읽고 ESI의 bit field로
세 분기를 고른다. shown 분기들은 `EAX = local + [0x001e2204]`를 계산해 EAX의 `+0`, `+2`,
`+5`, `+6` word/byte에 EBX/ESI에서 유도된 값을 쓴다. 공통 경로는 `EAX+5` byte를 갱신한다.
loop 뒤에는 `[0x001e17ba]=[0x001e2204]`, `[0x001e17b8]=0x7ff`, `LIDT [0x001e17b8]` 명령이 있다.

이는 local arithmetic과 memory operands의 static 관찰이다. `_idt_init` label, 8-byte record의
자료형·vector/descriptor 의미, `LIDT`와 processor state의 효과, 실제 초기화 실행은 확정하지 않는다.

원시 명령과 Python 검산값은 [idt-init-static-evidence.json](idt-init-static-evidence.json)에,
재검증 해시는 [checkpoint.json](checkpoint.json)에 보존했다.
