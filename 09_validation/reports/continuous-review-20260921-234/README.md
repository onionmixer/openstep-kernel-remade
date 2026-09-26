# 234차 정적 검토 — `_unix_syscall_` address의 descriptor-like writer·comparison

원본 OPENSTEP x86 `mach_kernel`에서 `_unix_syscall_` entry `0x00186e9c`를 참조하는 두 code operand를
원시 명령으로 대조했다. 재부팅·QEMU·외부 소스·구현은 사용하지 않았다.

`_gdt_init`은 `[0x001e19b0]`가 가리키는 EDX에 대해 EAX=`0x00186e9c`의 low 16 bits를 `EDX+0x28`에,
`SHR EAX,16` 뒤 remaining 16 bits를 `EDX+0x2e`에 쓴다. 같은 8바이트 영역에서 `EDX+0x2a=8`,
`EDX+0x2c`의 high 3 bits 보존 후 low bit set, `EDX+0x2d=0xec`도 확인했다.

`FUN_00192438`은 첫 stack 입력의 `+0x38` dword를 wrapper address 및 두 다른 entry 주소와 비교한다.
첫 비교군 중 하나와 같을 때는 `[0x001e8b54]+0x28`의 byte `+0xf0`에 bit 1을 set하고, stack 입력
`+0x34`의 dword에서 bit `0x100`을 clear한다. 비교가 일치하지 않는 경우와 `+0x30` 값이 1이 아닌
경우에는 각각 immediate 1 또는 3을 push하는 별도 직접 call 경로가 있다.

이는 raw address split/write와 comparison의 관찰이다. export name·8바이트 영역의 자료형, vector,
descriptor·privilege·exception 의미, 실제 entry·runtime execution은 확정하지 않는다.

원시 명령과 Python 검산값은 [unix-syscall-address-static-evidence.json](unix-syscall-address-static-evidence.json)에,
재검증 해시는 [checkpoint.json](checkpoint.json)에 보존했다.
