# `_vm_fault` pager-get non-2 결과의 소거와 다음 전이

Open item 2의 pager 오류 전파에서, `_vm_pager_get` 뒤 nonzero이면서 `EAX != 2`인
`_vm_fault` 분기를 원본 x86 바이트로 확장했다. export label은 위치 탐색용 가설이며,
결론은 `0x0017280c`부터 `0x00172a2d`의 raw control flow에 한정한다.

`0x0017280c CMP EAX,2; 0x0017280f JNE 0x0017292c`가 이 분기를 고른다.
도착 뒤 `0x0017292c MOV EDX,[EBP-0x4c]`와 `0x00172930 MOV EAX,[EDX]`가 실행된다.
따라서 pager가 돌려준 원래 EAX는 caller가 이 분기에서 다시 읽기 전에 lock-slot load로
덮인다. 이후의 `TEST EAX,EAX`와 `XCHG` retry는 이 새 EAX에 대한 것이다.

첫 교환 뒤 raw pointer 비교와 byte 수정·보조 호출을 거쳐, `0x001729a6`은 EDI의 `+0x20`
값을 `[EBP-0x4c]`에 쓴다. 그 local이 0이면 `0x001729dc`에서 다른 local을 0으로 쓰고
`0x001729e4 CALL 0x0017b99c` 뒤 `0x001729f6 JMP 0x00172a30`으로 간다. 0이 아니면
`+0x10`에 대한 두 번째 xchg retry를 거쳐 `0x00172a22 MOV EDI,[EBP-0x4c]`,
`0x00172a25 INC WORD [EDI+0x44]`, `0x00172a29 JMP 0x001720cc`으로
간다. 해당 loop-back은 fault body의 앞선 처리로 돌아가며 common return으로 직접 가지
않는다.

이 raw 경로에는 pager 원래 EAX를 공통 epilogue에 보존하거나, original EAX에 따라
rollback을 고르는 추가 branch가 없다. `EAX=2` 경로의 `0x00172922 MOV EAX,0xa` 반환과
대조되지만, 숫자들의 오류 의미나 보조 호출의 의미를 추정하지 않는다.

원시 바이트와 Python 집계는
[pager-get-non2-fault-flow.json](pager-get-non2-fault-flow.json)에, 제외 범위는
[SCOPE.md](SCOPE.md)에 있다.
