# VM pager wrapper direct caller의 EAX 경계

Open item 2의 pager 오류 전파를 원본 direct edge로 확장했다. `_vm_pager_get`의 유일한
direct caller는 `_vm_fault` `0x001727c3`이며, stack 정리 뒤
`0x001727cb TEST EAX,EAX; 0x001727cd JNE 0x0017280c`를 실행한다.

그 nonzero destination은 `0x0017280c CMP EAX,2`다. EAX=2 경로는 lock/release와 helper
call을 거친 뒤 `0x00172922 MOV EAX,0xa; 0x00172927 JMP 0x00173580`으로 합류한다.
EAX가 2가 아닌 nonzero 경로는 `0x0017292c`로 가며 곧 EAX를 lock-slot load로 덮어쓴다.
이는 숫자 2가 raw pager result에서 final fault return value `0xa`로 이어지는 한 경로라는
사실만 보이며, 두 숫자의 오류 의미는 추정하지 않는다.

Wrapper 자체에서 `0x0017a251 TEST EDX,EDX`의 null path는
`0x0017a255 PUSH EAX; CALL 0x0017b99c; XOR EAX,EAX; RET`다. nonnull path는
`[EDX]`가 nonzero일 때 `CALL 0x0017c264`, zero일 때 `CALL 0x0017d2d0`로 나뉘며,
두 CALL 직후 wrapper는 EAX를 쓰지 않고 epilogue/RET로 간다. 따라서 `_vm_fault`가
처음 받는 EAX는 null path의 raw zero 또는 두 helper의 raw return register다.

vnode helper `0x0017d2d0`은 table chain의 `0x0017d370 MOV EAX,[EAX+0x74];
0x0017d373 CALL EAX` 직후 `0x0017d375 MOV EDX,EAX`를 실행한다. optional output write
뒤 `0x0017d3af MOV EAX,EDX; RET`로 끝난다. 그러므로 이 vnode indirect callback의 raw
EAX가 wrapper와 `_vm_fault`의 위 분기까지 전달되는 경로가 확인된다.

vnode pageout helper `0x0017d3bc`도 `0x0017d4ca CALL EAX`의 결과를
`0x0017d4cf MOV EBX,EAX`로 보존하고, tail의 `0x0017d523 MOV EAX,EBX; RET`로
반환한다. callback 전 helper result가 5인 비교 경로는 `0x0017d477 MOV EAX,2`로 같은
tail에 간다. 따라서 `_vm_pager_put`의 두 direct caller TEST는 wrapper가 정한 raw EAX
result를 검사한다.

`_vm_pager_put`의 두 direct caller `0x00179f9f`, `0x0017bbd0`도 각 stack 정리 뒤
`TEST EAX,EAX`와 conditional branch를 수행한다. 반면 `_vm_pager_has_page`의 유일한
caller `_vm_fault` `0x00172ed7`는 EAX를 `[EBP-0x38]`에 저장한다. 이 local은 lock/release
sequence 뒤 `0x00172fac CMP [EBP-0x38],0`과 `0x00173007 CMP [EBP-0x38],0`에서 두 번
검사된다. zero는 `0x0017300d` 다음 helper sequence로, nonzero는 `0x00173080`으로
분기한다. `_vm_pager_deallocate`의 유일한 caller `0x00178ebd`는 EAX를 검사하지
않고 다음 word test로 진행한다.

이는 direct wrapper edge의 raw EAX 사용만 기록한다. branch가 의미하는 오류값, wrappers
내부의 device/vnode dispatch, indirect callers, helper side effect와 rollback은 미확정이다.
