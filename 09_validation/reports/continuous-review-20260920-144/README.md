# 144차 연속 검토 — deallocate caller pre-call lock-helper window

`_vm_map_deallocate` direct caller 37개의 각 call 직전 128-byte 원시 window를 다시
검사했다. `_lock_write` (`0x0015b5d0`) 및 `_lock_done` (`0x0015b73c`) direct call은
0개다. 같은 window에서 XCHG가 있는 caller는 138차에서 확인한 `_task_deallocate`와
`_task_terminate` 2개뿐이다.

이는 fixed window의 static direct-call inventory다. 128 byte 이전의 lock, indirect
lock call, XCHG 이외의 동기화, helper 내부 lock, runtime dynamic dispatch는 배제하지
않는다.

