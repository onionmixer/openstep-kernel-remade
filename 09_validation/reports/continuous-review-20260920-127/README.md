# 127차 연속 검토 — vm page template writer 범위

원본 `0x0017b143 MOV ESI,0x001f7440`, `0x0017b14b MOV ECX,0xc`,
`0x0017b150 REP MOVSD`는 source template의 12 dword를 destination으로 복사한다.
Python 계산상 12 dword는 48 bytes이며 template range는 `0x001f7440`부터
`0x001f7470` 직전까지다.

모든 export function body에서 이 range의 absolute write를 검사한 결과 12개이며 모두
`_vm_page_startup`에 있다. write offset은 `+0x14,+0x18,+0x1c,+0x1e,+0x20,+0x21,+0x24,
+0x28,+0x2c`에 분포한다. 범위의 나머지 byte가 원본 BSS/loader 초기값인지, computed
address writer가 있는지, template copy의 runtime 횟수는 이 정적 절대주소 스캔으로
확정하지 않는다.

