# 230차 정적 검토 — `_dounmount` 직접 caller와 간접 전송 경계

원본 OPENSTEP x86 `mach_kernel`의 `_dounmount`를 원시 명령으로 대조했다. 재부팅·QEMU·외부 소스·
구현은 사용하지 않았다.

`_dounmount`는 첫 stack 입력을 ESI에 놓고 `ESI+8`을 EDI에 보관한 후 `_vfs_lock(ESI)`를 직접
call한다. 그 반환값을 EBX에 보관해 0이 아니면 epilogue로 분기한다. 0 경로에는 `ESI+4`에서
읽은 pointer의 `+0x10`, 이어 별도로 읽은 `+4`를 EAX에 놓아 각각 `CALL EAX`를 수행하는 두
간접 전송이 있다. 이 두 target과 callee 효과는 이 검토에서 확정하지 않는다.

두 번째 간접 call 뒤 EBX가 0이 아니면 `_vfs_unlock(ESI)`을 직접 call한다. EBX가 0인 경로는
EDI가 0인지 검사하고, nonzero일 때 `0x0011df54(EDI)` 및 `_vfs_remove(ESI)`를 직접 call한다.
이어 immediate `0x12c`와 ESI를 push하여 `0x0015a824`를 직접 call하고 EBX를 EAX로 옮겨 반환한다.

원본 `__text`의 E8 rel32 target을 Python으로 전수 계산하면 `_dounmount` 직접 caller는 3개다:
`_unmount_all`의 두 site와 `_unmount`의 한 site. 간접·계산된 caller는 제외한다.

원시 명령과 Python 검산값은 [dounmount-static-evidence.json](dounmount-static-evidence.json)에,
재검증 해시는 [checkpoint.json](checkpoint.json)에 보존했다.
