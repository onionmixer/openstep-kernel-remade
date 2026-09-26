# 136차 연속 검토 — `vm_fault` common epilogue ingress 전수

원본 export의 `_vm_fault` body fragment 전체(5406 bytes)를 재디코드했다. common epilogue
`0x00173580`을 직접 목표로 하는 jump는 7개다. `0x0017207d`와 `0x00173201`은 saved local
`-0x30`을 EAX로 복원하고 jump한다. `0x001721e3`, `0x00172577`, `0x00172927`은 직전
`MOV EAX,0xa` 뒤 jump한다. `0x00172378`, `0x00172d15`는 `XOR EAX,EAX` 뒤 jump한다.

normal fall-through는 `0x0017357e XOR EAX,EAX`에서 epilogue로 들어간다. 그러므로 body
전수의 direct epilogue ingress 7개와 normal fall-through를 합친 8개가 현재 확인된 callee
EAX 복귀 경로다.

이는 direct branch 형태의 ingress inventory다. indirect control transfer, helper call의
내부 결과, numerical status의 이름, runtime reachability는 별도 증거가 필요하다.

