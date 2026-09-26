# 223차 정적 검토 — SPL 수준 wrapper와 PIC mask 갱신 경로

원본 OPENSTEP x86 `mach_kernel`의 실제 `_spl*` export 22개를 정적으로 대조했다.
재부팅·QEMU·외부 소스·구현은 사용하지 않았다.

14개 고정 수준 함수는 현재 수준 전역 `0x001e7714`에 0–7의 즉시값을 쓴다.
수준별 함수 수는 0:1, 1:1, 2:1, 3:2, 4:1, 5:1, 6:5, 7:2다.
각 고정 함수에는 PIC port `0x21`·`0xa1`에 대한 `OUT`이 두 개씩, 그리고 그 직후의
`LOCK INC [0x001e7618]`이 두 개씩 있다. 이 출력은 level-indexed WORD와 별도 WORD를
OR한 값이 이전 값과 다를 때의 선택 분기 안에 있다.

`_splx`와 `_spln`은 인수를 ESI로 받아 같은 전역에 쓰며, 이전 수준이 더 높을 때
`0x001e76f4 + 4*old_level`부터 목표까지 DWORD slot을 역순으로 검사한다. nonzero slot은
0으로 지운 뒤 일시적으로 current level을 slot `+8` 값으로 바꾸고, `STI` 상태에서
slot `+0`과 `+4`에서 얻은 값을 사용해 간접 `CALL`한다. 호출 뒤에는 `CLI`로 돌아온다.
이는 원시 제어·데이터 흐름일 뿐 callback의 type·완료·진행성·재진입 안전성을 증명하지 않는다.

`_spltty`, `_splnet`, `_splvm`, `_splimp`, `_splbio`는 current level을 EAX로 읽고 반환하는
12바이트 wrapper다. `_ipltospl`은 첫 stack 인수를 EAX로 읽어 반환한다.

원본 instruction record와 Python 집계는 [spl-level-mask-static-evidence.json](spl-level-mask-static-evidence.json)에,
재검증 해시는 [checkpoint.json](checkpoint.json)에 보존했다.
