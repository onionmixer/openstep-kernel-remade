# 245차 정적 검토 — `FUN_0016a30c`의 반복 read와 정확한 1,000,000 계수 산술

원본 OPENSTEP x86 `mach_kernel`의 `FUN_0016a30c`를 원시 명령으로 대조했다. 재부팅·QEMU·외부
소스·구현은 사용하지 않았다.

함수의 연속 export body는 82바이트다. 원본 `__text` E8 rel32 target을 Python으로 전수 계산하면
direct caller는 6곳이며, 244차의 `0x00163e0b`, `0x00163e48` 두 site가 포함된다.

입력 두 개는 `[EBP+8]`의 EAX와 `[EBP+0xc]`의 ESI다. 함수는 EAX의 `+4`와 `+0`을 local에
보관하고, `[EAX+8]`이 보관한 `+4` 값과 같아질 때까지 `0x0016a31c`로 되돌아가 다시 읽는다.
종료 후 ECX=`EBX-[ESI+4]`이다.

원시 산술 `((ECX<<5)-ECX)`, `((...<<6)-...)`, `ECX+(...<<3)`, `(...<<6)`의 계수는 Python으로
각각 31, 1,953, 15,625, 1,000,000임을 계산했다. 이후 원시 명령은 EDI를 더하고 `[ESI]`을
뺀 EAX를 남기며, EBX를 `[ESI+4]`, 저장한 EDI를 `[ESI]`에 쓴다. 숫자·field의 단위와 함수의
의미는 확정하지 않는다.

원시 명령과 Python 검산값은 [fun-0016a30c-static-evidence.json](fun-0016a30c-static-evidence.json)에,
재검증 해시는 [checkpoint.json](checkpoint.json)에 보존했다.
