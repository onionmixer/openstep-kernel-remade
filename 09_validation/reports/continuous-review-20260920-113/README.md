# 113차 연속 검토 — vnode pager indirect callback table values

## 판정

원본 명령과 file-backed data로 vnode pager의 두 indirect call을 table slot까지 연결했다.
`_vnode_pagein`은 byte-indexed global record table에서 record를 읽고 `record+8`의 pointer,
그 pointer의 `+0x1c`, 그리고 table `+0x74`를 차례로 load한 뒤 `CALL EAX`를 실행한다.
`_vnode_pageout`은 같은 graph에서 table `+0x78`을 load한 뒤 `CALL EAX`를 실행한다.

원본 `__DATA` bytes에서 symbol-labelled vectors의 slot 값을 Python으로 추출했다. `+0x74`
및 `+0x78`은 각각 dword index 29와 30이다.

| Vector address | `+0x74` | `+0x78` |
| --- | --- | --- |
| `_nfs_vnodeops` `0x001dca20` | `0x001338c0` | `0x00133de4` |
| `_fifo_vnodeops` `0x001dd6d0` | `0x00139b14` | `0x00139b14` |
| `_spec_vnodeops` `0x001dd4b4` | `0x00139444` | `0x00139444` |
| `_ufs_vnodeops` `0x001de480` | `0x00145848` | `0x00145bbc` |

`_vnode_alloc` compares the `record+8`-derived pointer's `+0x1c` with the UFS vector address;
`_vnode_uncache` compares a corresponding `+0x1c` value with both UFS and NFS vector addresses.
This confirms the dispatch-vector address is part of the pager's directly consumed pointer graph.

## 원시 검증

Python Capstone x86/32 decode checked 11 instructions: pagein graph/load/call at
`0x0017d35f`..`0x0017d373`, pageout at `0x0017d49f`..`0x0017d4cd`, and UFS/NFS identity
compares at `0x0017d956`, `0x0017e120`, and `0x0017e13c`. The four table slot values were
unpacked from the original binary through the Mach-O segment mapping in Python.

See [`pager-vnodeops-evidence.json`](pager-vnodeops-evidence.json).

## 미해결

This does not prove every runtime `+0x1c` value is one of these four vectors. The writers that
install a vector into each live pointer, every vector family, and target-function contracts remain
to be traced from original code.
