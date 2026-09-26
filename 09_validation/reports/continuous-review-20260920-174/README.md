# `_pmap_bootstrap`의 8-cell static indirect-jump table과 초기화 loop

Open item 1의 pmap 간접 dispatch를 원본 `_pmap_bootstrap` label hypothesis에서도
추적했다. `0x0018ef20 XOR EBX,EBX` 뒤 `0x0018ef24 CMP EBX,7`,
`0x0018ef29 JMP dword ptr [EBX*4+0x0018ef30]`가 실행된다. 원본 `__text` bytes를
Python으로 little-endian dword로 읽으면 8-cell table은 세 case target만 담으며, 각각의
선택 횟수는 1, 3, 4다.

각 case는 EDX/EAX가 가리키는 두 연속 buffer cell에 dword를 쓴 뒤 EDX를 4만큼, EAX를
공통 block에서 4만큼 전진한다. `0x0018ef8a INC EBX`와 `CMP EBX,7; JLE 0x0018ef24`가
loop를 닫으므로, EBX=0으로 시작한 이 경로는 정확히 8회 table dispatch한다. Python으로
계산한 결과는 EDX base `0x001f7a80`의 8 dword에 `[0,0,1,1,0,0,1,1]`, EAX base
`0x001f7b00`의 8 dword에 `[0,2,3,3,2,2,3,3]`을 기록한다.

table은 Mach-O `__TEXT,__text` 안에 file-backed bytes로 있고 segment `initprot` raw 값은
5다. 이 fact는 load-time protection interpretation이나 이후 runtime memory permission을
완결하지 않는다. table 값·case branch·buffer store의 원시 주소를 구분했으며, label에서
pmap field나 table 값의 API 의미를 추론하지 않았다.

173차에서 확인한 `_start → _i386_init` 경로 안에는 `0x0018ab7f CALL 0x0018eee8`가 하나
있다. 따라서 그 정적 call이 실제로 도달·복귀한다는 조건에서 이 loop는 page-size helper
call 뒤에 위치한다. 실제 boot 실행, mapping 성공, register 초기값, runtime 재호출, buffer
수명/alias와 concurrent overwrite는 정적 evidence 밖이다.

수치·raw table·case 계산은 [pmap-bootstrap-jump-table.json](pmap-bootstrap-jump-table.json)에 기록했다.
