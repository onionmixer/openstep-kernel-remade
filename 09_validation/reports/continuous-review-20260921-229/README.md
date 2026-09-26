# 229차 정적 검토 — `_choose_pset_thread`의 제거 후 상태·링크 갱신

원본 OPENSTEP x86 `mach_kernel`의 `_choose_pset_thread`를 원시 명령으로 대조했다. 재부팅·QEMU·외부
소스·구현은 사용하지 않았다.

두 번째 stack 입력을 ESI에 둔 뒤 `ESI+0x108`을 검사한다. 양수 경로는 `ESI+0x104`를 읽어
`ESI+8*value`를 계산하고, 대상의 `+0`, `+4`, `+8` 및 ESI의 `+0x108`, `+0x104`, `+0x100`을
갱신한다. 다른 경로는 `ESI+0x118`을 대상으로 read/test/XCHG와 역방향 분기를 실행한다.

이후 첫 stack 입력의 `+0x114==1`인 분기에서 그 값을 2로 쓰며, `0x001ea9dc`와의 비교 결과에
따라 `ESI`, 첫 stack 입력, 및 ESI에서 얻은 다른 주소의 `+0x10c/+0x110`을 갱신한다. 끝에서
`ESI+0x114`를 증가시키고 `ESI+0x118`과 EAX를 XCHG한 뒤 첫 stack 입력의 `+0x11c`를 읽는다.

원본 `__text` 전체 E8 rel32 target을 Python으로 계산하면 이 entry의 direct caller는
`_thread_select`와 `_choose_thread`의 두 site다. 간접·계산된 caller와 pointer/field의 자료형,
소유권, queue·lock·state의 추상 의미, 실행·진행성·동시성은 이 검토로 확정하지 않는다.

원시 명령과 Python 검산값은 [choose-pset-thread-static-evidence.json](choose-pset-thread-static-evidence.json)에,
재검증 해시는 [checkpoint.json](checkpoint.json)에 보존했다.
