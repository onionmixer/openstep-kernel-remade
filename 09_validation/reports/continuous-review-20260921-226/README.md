# 226차 정적 검토 — `_thread_setrun`의 큐 삽입·lock-word 국소 흐름

원본 OPENSTEP x86 `mach_kernel`의 `_thread_setrun` 한 본문을 원시 명령으로 대조했다.
재부팅·QEMU·외부 소스·구현은 사용하지 않았다.

이 함수는 `ESI+0x58` 값을 읽고 `0x1f`와 비교한다. unsigned-below-or-equal 분기 밖에서는
`0x0010c0d8`을 호출한 다음 그 값을 `0x1f`로 쓴다. 이후 `EBX+0x100`을 대상으로 read/test,
`XCHG` 및 두 개의 역방향 분기를 포함하는 반복을 실행한다. 획득 이후에는 `EBX+ECX*8`으로
계산한 주소와 그 `+4` 값을 사용하여 ESI의 `+0`, `+4` 및 그 두 대상 주소를 갱신하고,
`ESI+8=EBX`을 쓴 뒤 `EBX+0x100`에 다시 `XCHG`를 실행한다.

같은 경로에서 `EBX+0x104`와 ECX의 비교·조건부 write, `EBX+0x108` 증가가 있다. 앞부분에는
전역 `0x001e9724`, `0x001e971c`, `0x001e90ac`과 `ESI+0x70`·`+0x184`를 읽고 일부 경로에서
쓰기하는 명령도 있다. `EBP+0xc`가 0이 아닌 후반 경로는 `0x001e8b54`가 가리키는 `+0x58`과
비교한 뒤, 조건부로 `[0x001e9050]+0x124=0` 및 `0x001e90ac`의 low-byte OR 4를 쓴다.

이는 명령 수준의 메모리 접근·분기 관찰이다. 필드의 자료형과 소유권, queue/priority/lock의
추상 의미, `0x0010c0d8` 및 `0x00163dc8`의 효과, 호출이 실제로 발생하는지, lock 획득과
scheduler의 진행성·동시성은 확정하지 않는다.

원시 명령과 Python 검산값은 [thread-setrun-queue-static-evidence.json](thread-setrun-queue-static-evidence.json)에,
재검증 해시는 [checkpoint.json](checkpoint.json)에 보존했다.
