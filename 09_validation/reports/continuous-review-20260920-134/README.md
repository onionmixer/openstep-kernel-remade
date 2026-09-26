# 134차 연속 검토 — `_smmap` callback table base의 static writer 경계

모든 export function body에서 displacement `0x001e2f58` memory operand를 검사했다.
reference는 `_smmap`의 `0x00106f65 MOV ESI,[EDX*4+0x001e2f58]` 1개이고, write access는
0개다. 따라서 133차의 indexed callback target load 외에는 이 base를 직접 참조하는
export-body instruction이 없다.

이는 exact displacement에 대한 static 관측이다. row 내부의 computed writer, loader/BSS,
table 범위·row count, function 밖 code, runtime 변경 가능성은 확정하지 않는다.

