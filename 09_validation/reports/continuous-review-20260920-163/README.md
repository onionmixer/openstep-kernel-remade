# `_vm_object_copy` output flag의 copy/fork 후속 경로

Open item 2의 COW copy/fork 경계를 원본 명령으로 확장했다. `_vm_object_copy` 뒤
`[EBP-4]` output local을 검사하는 `_vm_map_copy`와 `_vm_map_fork`는 nonzero일 때 각각
source entry byte `+0x18`에 `OR 0x40`을 쓴다. 두 path 모두 destination/source entry에
`OR 0x40`, 양쪽에 `OR 0x08`, prior object deallocate, `CALL 0x0019113c` 후 cleanup target
으로 합류한다.

이 raw output flag는 즉시 EAX error rollback 분기가 아니라 entry-flag와 후속 cleanup
순서를 고르는 branch다. flag의 C 이름·의미, deallocate/helper side effect와 transactional
rollback 완료 여부는 결론 내리지 않는다.

두 common path의 `0x0019113c`는 export label상 `_pmap_copy`이며, 원본 body 7 bytes는
`PUSH EBP; MOV EBP,ESP; MOV ESP,EBP; POP EBP; RET`뿐이다. 따라서 이 binary의 해당
call은 stack frame 이외의 외부 pmap state나 EAX를 명시적으로 바꾸지 않는 no-op이다. 이 사실은 앞의 entry flag,
object deallocate 및 cleanup 효과를 no-op로 만들지는 않는다.
