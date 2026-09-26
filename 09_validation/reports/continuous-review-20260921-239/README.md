# 239차 정적 검토 — `_thread_invoke`의 `_switch_context` stack 전달 경계

원본 OPENSTEP x86 `mach_kernel`의 `_thread_invoke` selected path와 `_switch_context` direct caller를
원시 명령으로 대조했다. 재부팅·QEMU·외부 소스·구현은 사용하지 않았다.

원본 `__text` E8 rel32 target을 Python으로 전수 계산하면 `_switch_context` direct caller는
`_thread_invoke`의 `0x001639cd` 한 site다. 이 site 직전에는 ESI `+0x4c`의 bit clear, `ESI+0x20`
XCHG, global `0x001e90ac` read/AND/OR/write, ESI push와 `0x00106e0c` call, global
`0x001deb4c` 증가가 있다.

`_switch_context` call 직전 stack push 순서는 ESI, EDI, EBX다. call 직후에는 EBX=EAX,
EBX push, `_thread_dispatch` direct call, EAX=1 write가 이어진다. 이는 raw stack/register
instruction 순서이며 source signature, argument/field/global 의미, call return, dispatch/context
semantics 및 runtime scheduling은 확정하지 않는다.

원시 명령과 Python 검산값은 [thread-invoke-switch-context-evidence.json](thread-invoke-switch-context-evidence.json)에,
재검증 해시는 [checkpoint.json](checkpoint.json)에 보존했다.
