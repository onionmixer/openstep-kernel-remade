# 138차 연속 검토 — `_task_terminate`의 `_vm_map_deallocate` 전 lock 순서

`_task_terminate`의 direct map-deallocate path는 ESI interlock을 얻어 `[ESI+4]`을
감소시키고 `XCHG [ESI],0`으로 해제한다. 마지막 참조일 때 EBX=`[ESI+0x2c]`,
EDX=`EBX+0x158`에서 두 번째 spin/XCHG interlock을 얻는다. helper `0x00161504` 후
`XCHG [EBX+0x158],0`으로 해제하고, helper `0x001616f0` 뒤 `_vm_map_deallocate`
`0x00165fe2`를 호출한다.

37개 deallocate direct caller의 각 직전 128-byte 원시 창을 Python으로 스캔했을 때 XCHG가
있는 site는 `_task_deallocate`와 이 `_task_terminate` 두 개뿐이었다. 이 창 길이는
caller-wide lifetime proof가 아니며, 그 밖의 caller가 다른 lock 방식을 쓰지 않는다는
결론도 아니다.

