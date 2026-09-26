# `_pmap_kgetport` 세 간접 call의 동적 root 경계

Open item 1의 pmap-prefix 간접 call 조사에서, export label상 `_pmap_kgetport`
`0x00135df4`의 세 target chain이 시작되는 raw 값을 확인했다. 이 이름은 위치 탐색용
가설이며, 결론은 원본 `0x00135e5a..0x00135f0c` 명령어에 한정한다.

함수는 local 입력 묶음의 주소를 포함한 다섯 인수를 push한 뒤
`0x00135e6c CALL 0x001353b0`을 실행하고, `0x00135e71 MOV EBX,EAX`로 그 raw 반환값을
받는다. `0x00135e76 TEST EBX,EBX; 0x00135e78 JE 0x00135f00` 때문에 EBX가 0인 경로는
세 간접 call 모두 건너뛰어 local return 값을 반환한다.

EBX가 0이 아닌 경로에서 첫 target은 `[EBX+4]`의 첫 dword, 두 번째는
`[EBX] -> +0x20 -> +0x10`, 세 번째는 `[EBX+4] -> +0x10`의 끝 dword다. 첫 call의 EAX는
`TEST`되어 local return 값 `0/1/-1` 선택에만 쓰이고, 그 세 분기는 모두
`0x00135eec`으로 합류한다. 따라서 두 tail 간접 call은 첫 call EAX의 zero/nonzero
분기 이후에도 raw control flow상 실행된다.

이는 callback target들이 이 함수 안의 static table에서 시작하지 않고 direct helper의
raw 반환값 EBX에서 load된다는 범위의 사실이다. helper 반환값의 자료형,
그 필드의 writer/lifetime, target ABI, helper side effect와 runtime target identity는
확정하지 않는다.

상세 raw 바이트·Python 집계는
[pmap-kgetport-dynamic-root.json](pmap-kgetport-dynamic-root.json)에 기록했다.
