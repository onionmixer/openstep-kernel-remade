# 137차 연속 검토 — `_task_deallocate`의 `_vm_map_deallocate` 전 lock 순서

`_task_deallocate`는 nonnull input EBX에서 spin loop와 `XCHG [EBX],1`을 실행한다.
이후 `[EBX+4]`을 하나 감소시키고 `XCHG [EBX],0`으로 이 interlock을 해제한다. 감소 전
EAX가 0이 아니면 epilogue로 간다.

마지막 참조 경로는 ESI=`[EBX+0x2c]`, EDX=`ESI+0x158`을 만들고 두 번째 spin/XCHG
interlock을 얻는다. `0x00165c42` helper call 뒤 `XCHG [ESI+0x158],0`으로 해제하고,
그 다음 helper call `0x00165c53` 및 `_vm_map_deallocate` call `0x00165c5c`를 실행한다.
따라서 이 caller의 관측된 순서에서는 두 번째 interlock 해제가 map deallocate call보다
앞선다.

이는 raw XCHG/call order만 확정한다. field type, lock API 이름, helper 내부 작업,
interlock이 전체 exclusion을 제공하는지, and other deallocate caller의 순서는 이 보고서
범위 밖이다.

