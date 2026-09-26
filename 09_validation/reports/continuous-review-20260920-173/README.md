# page size/mask/shift initializer의 `_start` 정적 도달 경로

126차는 page size·mask·shift 세 absolute global의 exported-body writer를 전수 셌지만,
runtime initializer의 정적 entry 경계는 별도로 남겨 두었다. 이번에는 원본 `__text` 전체의
`CALL rel32` encoding을 Python으로 산출하고, 발견 site를 원본 function body에서 Capstone으로
재해석했다.

`_start`의 선형 instruction 순서는 다음과 같다.

1. `0x0018610b CALL 0x0018aafc` (`_i386_init` label hypothesis)
2. 해당 call이 복귀한 뒤 `0x00186124 CALL 0x00193a98` (`_startup_early` label hypothesis)
3. 그 call이 복귀한 뒤 `0x00186129 CALL 0x0015c828` (`_setup_main` label hypothesis)
4. `0x0015c83a CALL 0x00173a68` (`_vm_mem_init` label hypothesis)

첫 callee 내부에는 `0x0018ab2b MOV dword ptr [0x001e0d0c],0x2000`가 있고 바로 다음
`0x0018ab35 CALL 0x0017a9b4`가 page-size helper로 간다. 해당 helper는 page-size global을
읽어 mask global을 쓰고 shift global을 zero부터 증가시킨다. 따라서 이 **정적 복귀 경로가
실행되고 각 call이 복귀한다는 조건**에서는 page-size writer가 VM memory initializer보다
앞선다.

`__text`의 모든 byte position에서 target을 재계산해 정확한 `E8 rel32` encoding을 찾은
결과 `_i386_init`, `_vm_set_page_size`, `_startup_early`, `_setup_main` 각각 target당 한 site다.
각 site는 위 raw function body instruction boundary에서 다시 확인했다. 이로써 선택한
직접-call encoding에는 추가 static site가 없음을 보였지만, indirect/computed call은 이
방법의 범위가 아니다.

이는 원본의 정적 부팅 경로와 상대적 순서만 확정한다. 실제 firmware entry, call 이전의
machine state, panic/exception·무한 loop, call의 실제 복귀, 재호출, 동시 writer, boot
완료 뒤 global 값의 보존 및 runtime lifetime은 실행 관측 없이 확정할 수 없다. export label과
C prototype은 의미 판정에 사용하지 않았다.

원시 target 계산과 모든 수치는 [page-size-static-init-path.json](page-size-static-init-path.json)에 기록했다.
