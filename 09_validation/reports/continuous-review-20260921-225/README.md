# 225차 정적 검토 — VFS add/remove list·lock 경계

원본 OPENSTEP x86 `mach_kernel`의 `_vfs_add`, `_vfs_remove`, `_vfs_lock`, `_vfs_unlock`을
원시 명령으로 대조했다. 재부팅·QEMU·외부 소스·구현은 사용하지 않았다.

`_vfs_add`는 두 번째 인자로 `_vfs_lock`을 호출한다. 이 call의 EAX가 0이 아니면 그대로
epilogue로 가며, `ESI != 0` 및 `DWORD[ESI+0xc] != 0` 경로는 `_vfs_unlock` 후 EAX=16을
쓴다. 정상 경로는 전역 list head `0x001e97a4` 또는 기존 head의 next를 EBX로 갱신하고,
`EBX+8=ESI`를 쓴다. 세 번째 인자의 1·2·8·0x20 bit에 따라 `EBX+0xc`의 1·8·0x10·0x20 bit를
각각 set/clear하며, 마지막에 0x80 bit를 clear하고 EAX=0으로 반환한다.

`_vfs_remove`는 전역 head 자체가 EDI이면 panic helper call 경로로 간다. 그렇지 않으면
head부터 next pointer를 순회해 EDI의 predecessor를 찾고, predecessor next를 EDI next로
바꾼다. `ESI=[EDI+8]`의 `+0xc` 값에 따라 보조 list unlink 또는 `ESI+0xc=0`을 수행한 뒤
`_vfs_unlock(EDI)`을 호출한다. panic helper가 실제로 return하지 않는지, list 구조의 타입·
소유권·동시성·callee 효과는 이 범위에서 확정하지 않는다.

원본 `__text` 전체의 `E8 rel32` target을 Python으로 계산하면 `_vfs_add`의 direct caller는
4개, `_vfs_remove`의 direct caller는 2개다. 이 결과는 간접·계산된 caller를 제외한다.

원시 명령·caller·계산값은 [vfs-list-lock-static-evidence.json](vfs-list-lock-static-evidence.json)에,
재검증 해시는 [checkpoint.json](checkpoint.json)에 보존했다.
