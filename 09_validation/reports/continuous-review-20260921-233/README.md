# 233차 정적 검토 — `_unix_syscall_` wrapper의 `_unix_syscall` 직접 전송

원본 OPENSTEP x86 `mach_kernel`의 `_unix_syscall_` wrapper를 원시 명령으로 대조했다. 재부팅·QEMU·
외부 소스·구현은 사용하지 않았다.

이 96바이트 body는 `PUSHFD`, immediate 0 push, `PUSHAD`, DS/ES/FS/GS push로 시작한다. stack
`+0x34` dword를 `+0x40`에 쓰고 DS·ES·FS·GS에 immediate word를 옮긴 뒤 `CLD`한다. EBP는
`ESP+0x18`에서 계산된다.

`0x001f74d4`가 0이 아닌 경우에는 `CLI`, `ESP=[0x001f74d8]`, `[0x001f74d4]=0`, `STI`의 순서가
있다. 이어 EBX를 push하고 `_unix_syscall`을 직접 call한다. call 뒤 ESP=EBX, GS/FS/ES/DS pop,
`POPAD`, `ADD ESP,8`, `IRETD`가 연속한다.

원본 `__text` E8 rel32 target을 Python으로 전수 계산하면 `_unix_syscall`의 direct caller는 이
한 site다. 이것은 direct relative caller의 inventory일 뿐, vector entry·privilege transition,
stack validity, IRETD 복귀, interrupt/runtime behavior를 확정하지 않는다.

원시 명령과 Python 검산값은 [unix-syscall-wrapper-evidence.json](unix-syscall-wrapper-evidence.json)에,
재검증 해시는 [checkpoint.json](checkpoint.json)에 보존했다.
