# 126차 연속 검토 — page size/mask/shift global writer 전수

원본 `i386_init`은 `0x0018ab2b MOV [0x001e0d0c],0x2000` 뒤
`0x0018ab35 CALL 0x0017a9b4`를 실행한다. `_vm_set_page_size`는 이 global에서 1을 뺀
EAX를 `0x001e89ec`에 쓰고, `0x001f6ea4`를 0으로 만든 뒤 loop에서 증가시킨다.

모든 export function body fragment에서 세 absolute global의 write operand를 전수
검사했다. page size writer는 1개, page mask writer는 1개, page shift writer는 2개다.
각각 위 두 함수 외에는 없다. Python 계산으로 page size는 8192, mask는 8191, shift는
13이며 8192는 2의 거듭제곱이다.

이 결론은 export가 포착한 function body의 static absolute writers에 한정한다. 함수 밖
코드, computed address store, runtime 호출 횟수, 초기화 순서의 동시성은 확정하지 않는다.

