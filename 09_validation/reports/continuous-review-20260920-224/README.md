# 224차 정적 검토 — IRQ mask level-table 초기화와 IPL 변경

원본 OPENSTEP x86 `mach_kernel`에서 `_intr_initialize`와 `_intr_change_ipl`의
mask level-table 변경을 원본 바이트로 대조했다. 재부팅·QEMU·외부 소스·구현은 사용하지 않았다.

`_intr_initialize`는 `0x001e76e4`에서 시작하는 16-bit cell을 2바이트 간격으로
8개 기록한다. Python 계산으로 table 범위는 16바이트이고 마지막 cell은 `0x001e76f2`다.
각 cell에 쓰는 초기값은 `0xfffb`, 별도 WORD `0x001e771e`에는 0이다. 이후
`0x001e7718`과 `0x001e7714`에 각각 7을 쓴다.

`_intr_change_ipl`은 첫 인자가 15 이하이면서 2가 아니고, 두 번째 인자가 7 이하이며,
계산된 IRQ slot의 `+4` DWORD가 nonzero일 때만 진행한다. slot `+8`에 새 level을 쓴 뒤,
level 0–7의 8개 cell을 순회한다. loop index가 새 level보다 작으면 해당 cell에서 bit를
clear하고, 같거나 크면 bit를 set한다. 마지막에는 `table[0x001e7718] | WORD[0x001e771e]`를
계산해 이전 mask WORD와 다를 때만 두 `OUT`과 두 `LOCK INC`를 실행한다.

원본 `__text`의 모든 `E8 rel32` 후보를 Python으로 재계산하면 `_intr_initialize`
entry에 대한 direct caller는 `0x0018ab21` 한 곳이며, 그 owner export label은
`_i386_init`이다. 이는 정적 edge 하나이며 실제 초기화 실행, 장치 상태 또는 interrupt
delivery의 증거는 아니다.

세부 원시 명령·계산·한계는 [irq-mask-level-table-init-change.json](irq-mask-level-table-init-change.json),
재검증 해시는 [checkpoint.json](checkpoint.json)에 있다.
