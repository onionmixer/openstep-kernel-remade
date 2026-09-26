# 227차 정적 검토 — `_choose_thread`의 공통 queue-field 감소 경로

원본 OPENSTEP x86 `mach_kernel`의 `_choose_thread` 본문을 원시 명령으로 대조했다. 재부팅·QEMU·외부
소스·구현은 사용하지 않았다.

초기 경로는 첫 stack 입력을 ESI에 놓고 `ESI+0x100`에서 read/test, `XCHG`, 역방향 분기 반복을
실행한다. 이어 `ESI+0x108 > 0`일 때 `ESI+0x104`를 읽어 `ESI + 8 * value` 주소를 만들고,
그 주소와 그 주소가 가리키는 값을 비교한다. 한 분기에서는 대상의 `+0`, `+4`, `+8` 및 계산된
주소의 `+0`을 갱신하고, `ESI+0x108`을 감소시키며 `ESI+0x104=EBX`를 쓴 뒤 `ESI+0x100`에 0과
`XCHG`한다. EDX를 EAX로 옮긴 뒤 epilogue로 간다.

첫 비교가 자기 참조이면 ECX를 8만큼 감소시키고 EBX를 감소시킨 뒤 signed-nonnegative일 때 다시
비교한다. `ESI+0x108 <= 0` 또는 이 반복이 끝난 다른 경로는 먼저 `ESI+0x100`을 0으로 교환한다.
그 뒤에는 첫 stack 입력의 `+0x12c`가 가리키는 값의 `+0x100`에서도 동일한 read/test/XCHG 반복을
수행하고, 두 값을 stack에 push하여 `0x0016448c`을 직접 호출한다.

이는 선택한 명령의 국소 흐름이다. `_choose_thread`라는 export 이름, 포인터·필드의 자료형과
소유권, dequeue/queue/lock의 추상 의미, `0x0016448c` 효과, 반환값, 실제 thread 선택·진행성·
동시성은 확정하지 않는다.

원시 명령과 Python 검산값은 [choose-thread-queue-static-evidence.json](choose-thread-queue-static-evidence.json)에,
재검증 해시는 [checkpoint.json](checkpoint.json)에 보존했다.
