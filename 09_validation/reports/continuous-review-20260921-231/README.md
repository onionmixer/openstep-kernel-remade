# 231차 정적 검토 — `_unmount`의 `_dounmount` 인자 provenance

원본 OPENSTEP x86 `mach_kernel`의 `_unmount`를 원시 명령으로 대조했다. 재부팅·QEMU·외부 소스·
구현은 사용하지 않았다.

이 함수는 `0x001e875c`에서 pointer를 읽어 그 `+0x24`를 한 번 더 역참조한 값을 stack-local
`[EBP-4]`의 주소와 함께 `0x0011c0f8`에 전달한다. 반환 EAX의 low byte는 `0x001e875c`가
가리키는 `+0x68`에 쓰이고, 반환 EAX를 EDX에 둔 상태에서 `EDX+0x68`과 0을 비교한다.

계속되는 경로에서 EAX=`[EBP-4]`이며 `EAX+4`의 bit 1을 검사한다. bit가 set인 경로는
`EBX=[EAX+0x24]`를 읽고, 조건부 helper call 뒤 EBX를 push하여 `_dounmount`에 전달한다.
`_dounmount` 반환 EAX는 다시 EDX를 거쳐 `0x001e875c`가 가리키는 `+0x68` byte에 쓴다.
`0x001e8758`에서 얻은 pointer의 `+0x1c`, EBX의 WORD `+0x124` 비교와 두 직접 call도 이
경로 앞에 있다.

원본 `__text`의 E8 rel32 target을 Python으로 전수 계산했을 때 `_unmount` entry를 target으로
하는 site는 0개다. 이것은 직접-relative caller만의 결과이며 indirect 또는 table dispatch가
없다는 뜻이 아니다.

원시 명령과 Python 검산값은 [unmount-argument-static-evidence.json](unmount-argument-static-evidence.json)에,
재검증 해시는 [checkpoint.json](checkpoint.json)에 보존했다.
