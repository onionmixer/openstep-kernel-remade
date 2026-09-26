# 228차 정적 검토 — `_thread_select`의 helper 분기와 local fallback

원본 OPENSTEP x86 `mach_kernel`의 `_thread_select` export body와 `_choose_thread` 직접 call을
원시 명령으로 대조했다. 재부팅·QEMU·외부 소스·구현은 사용하지 않았다.

`EDI+0x108`을 0과 비교하여 positive가 아닌 경우 `0x001634c8`으로 분기하며, 다른 경로는 EDI를
push한 뒤 `_choose_thread` (`0x001643c0`)를 직접 call한다. 원본 `__text` 전체의 E8 rel32 target을
Python으로 계산했을 때 이 helper entry의 direct caller는 이 한 site뿐이다. 간접·계산된 call은 이
결과에 포함되지 않는다.

fallback은 `0x001e9710`에서 read/test/XCHG와 역방향 분기를 실행한다. `ESI+0x108 != 0` 경로는
`ESI+0x104`로부터 `ESI+8*value` 주소를 만들고, 이 주소와 그 대상의 `+0`, `+4`, `+8`을 갱신하며,
`ESI+0x108` 및 조건부 `ESI+0x104`도 바꾼 뒤 `ESI+0x100`과 EAX를 XCHG한다. 다른 fallback 분기는
`0x001e8b54`가 가리키는 `+0x20`에도 별도 read/test/XCHG 반복을 보이고, 일부 경로에서는
`0x00163dc8` 또는 `_choose_pset_thread`를 직접 call한다. 마지막은 EBX의 `+0x60`에 따라 EDI의
`+0x120`에 두 서로 다른 값을 쓴다.

이는 정적 instruction/data-flow 관찰이다. export label이나 필드 오프셋은 자료형·소유권·queue
의미를 확정하지 않으며, helper/callee 효과, 호출 성공, 선택 정책·진행성·동시성·runtime 실행을
주장하지 않는다.

원시 명령과 Python 검산값은 [thread-select-static-evidence.json](thread-select-static-evidence.json)에,
재검증 해시는 [checkpoint.json](checkpoint.json)에 보존했다.
