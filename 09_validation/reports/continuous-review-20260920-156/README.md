# `_vm_object_deallocate` 30개 direct caller의 EAX 수명

## 범위

Open item 2의 deallocate caller-wide 검토를 확장했다. 원본 x86 바이트에서
`_vm_object_deallocate`로 해석되는 `0x00178c64`의 직접 `CALL rel32` 30개를 모두
확인하고, 각 CALL의 다음 명령부터 같은 export body 안의 분기와 jump 목적지를 따라
원래 EAX 값이 처음 읽히거나 덮어써지는 지점까지 추적했다. 모든 개수와 주소·해시는
Python으로 계산했다.

## Callee의 공통 반환값은 증명되지 않는다

`0x00178c64`의 export body 세 조각은 `0x00178c64..0x00178ced`,
`0x00178cf0..0x00178d25`, `0x00178d28..0x00178d5f`이고 공통 epilogue는
`0x00178d5f RET`이다. 그 RET 직전에 모든 경로에서 EAX를 같은 값으로 쓰는 명령은
없다. 예를 들어 NULL 입력 분기는 `0x00178c6e JE 0x00178d57`로 바로 epilogue로
가며, 다른 경로에는 lock exchange와 helper call 전후의 EAX write가 있다.

따라서 export 이름이나 디컴파일러 signature로 이 함수를 status-return API라고
해석할 근거는 없다. 이 보고서는 EAX 값 자체의 의미를 추정하지 않는다.

## 30개 direct caller의 결과 사용

CFG를 따라간 결과, 29개 CALL site는 모든 도달 경로에서 원래 EAX를 읽기 전에 EAX를
덮어쓰거나 함수 RET에 도달한다. 남은 `_thread_deallocate` `0x001670dd`는 정상 분기에서
`0x001670fa MOV EAX,[ESI+0x4c]`로 덮어쓰고, 다른 분기에서는 상수만 push한 뒤
`0x001670f2 CALL 0x0010ca6c`에 먼저 도달한다. 어느 쪽에도 이전 EAX를 검사하거나
그 값으로 rollback을 고르는 명령은 없다.

`_mfs_memfree` `0x0015ebf2`는 덮어쓰기 대신 `0x0015ebff RET`에 도달한다. 따라서 이
함수의 상위 caller가 EAX를 볼 가능성은 이 한 함수 바깥의 별도 분석 대상이며, 여기서
이를 무시된 반환값이라고 확대 해석하지 않는다.

VM 관련 결과도 구체적이다. `_vm_fault`의 11 site, `_vm_fault_wire_fast`의 3 site,
`_vm_map_copy`의 2 site, `_vm_map_fork`의 1 site와 map delete/copy entry site는 모두
분기 목적지를 포함해 원래 EAX보다 새 상수·local·전역 또는 entry field를 먼저 EAX에
쓴다. 그러므로 이 30개 direct call edge에는 deallocate EAX로 오류 전파·rollback을
선택한다는 증거가 없다.

## 한계

이는 direct call과 export body 내 정적 EAX dataflow만의 결과다. memory side effect,
callee helper의 의미, indirect caller, C type, runtime lock owner 및 `mfs_memfree`의
상위 caller는 판정하지 않는다. 따라서 deallocate의 전체 lifetime/locking/rollback이
완료됐다는 주장도 아니다.

상세 주소·각 path의 종착 instruction·Python 집계는
[vm-object-deallocate-eax-flow.json](vm-object-deallocate-eax-flow.json)에 있다.
