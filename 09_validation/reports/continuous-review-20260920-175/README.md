# pmap-name export 표본의 간접 transfer 전수와 해석 경계

Open item 1의 pmap 간접 호출을 label 기반 표본 안에서 재집계했다. full-pass5 export 중
name에 대소문자 무관하게 `pmap`을 포함한 40개 function body(8,280 bytes)를 원본에서
Capstone으로 decode했으며 총 instruction 수는 2,803개다. register 또는 memory operand를
목적으로 하는 `CALL`/`JMP`는 4개뿐이다.

세 `CALL EDX` site (`0x00135ebe`, `0x00135ef5`, `0x00135efe`)는 171차의 allocation field와
file-backed `__DATA` initial cells를 따라 각각 `0x00135bd8`, `0x001351c0`, `0x00135c84`로
축약된다. helper가 zero를 반환하면 prefix가 callbacks를 건너뛰므로, 이는 nonzero return과
initial table contents 조건의 static target이다.

남은 한 site `0x0018ef29 JMP [EBX*4+0x0018ef30]`는 174차의 8-cell `__text` jump table이다.
EBX=0부터 7까지의 loop에서 target sequence는 `18ef50, 18ef64, 18ef78, 18ef78, 18ef64,
18ef64, 18ef78, 18ef78`로 raw cell 값에서 계산된다. 따라서 이 label-selected 표본에는
새로운 미해석 indirect `CALL`/`JMP` operand가 남지 않는다.

이 결과는 **pmap label을 갖는 exported bodies**라는 선택 기준에만 적용된다. export label은
구조체 type 또는 subsystem membership의 증명이 아니며, pmap alias를 쓰는 이름 없는/다른
이름의 function, non-export code, call과 jmp 이외의 callback mechanism, computed table
overwrite와 runtime lifetime은 조사 완료로 바꾸지 않는다.

집계·site 목록·기존 원시 근거 연결은 [pmap-named-indirect-transfer-inventory.json](pmap-named-indirect-transfer-inventory.json)에 있다.
