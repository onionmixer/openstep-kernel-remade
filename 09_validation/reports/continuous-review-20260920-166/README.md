# `_vm_map_copy` 재귀 잠금의 flag별 set/clear 경계

Open item 2의 copy/map-fork 잠금 순서를 좁히기 위해, export label상 `_vm_map_copy`
`0x00176888` 내부의 재귀 호출 주변 원시 CFG를 확인했다. helper 명칭과 field 의미는
가설로만 취급하고, 아래는 `0x0017769b`부터 `0x001778cf`까지의 명령 순서다.

두 entry flag 검사 모두 bit 0을 `TEST`한다. 첫 검사에서 zero edge는 `[EBP+0xc]`를
`[EBP-0x44]`에 저장하고 `0x001776c0 CALL 0x0015bb9c`에 같은 값을 push한다. 두 번째
검사의 zero edge는 `[EBP+8]`를 `EBX`에 넣고 `0x00177885 CALL 0x0015bb9c`에 push한다.
두 경로는 `0x001778a2 CALL 0x00176888`의 nested direct call로 합류한다.

nested call 뒤에는 EAX 검사 없이 pointer 동등성만 검사한다. 첫 lane의 zero edge는
`[EBP+0xc]`를 `[EBP-0x44]`에 저장한 뒤, clear guard에서 둘을 비교한다. 두 번째
zero edge는 `[EBP+8]`를 `EBX`에 넣은 뒤 clear guard에서 둘을 비교한다. outer caller
명령에는 각 setup 뒤 guard 전의 해당 local/`EBX` 명시 write가 없지만 nested callee의
메모리·레지스터 효과는 이 범위에서 알 수 없다. 따라서 비교가 참일 때만 각 clear call이
실행되며, 이 raw caller 범위만으로 zero edge의 무조건 clear를 주장하지 않는다.

각 flag-one edge는 해당 set site를 건너뛐다. 첫 lane은 entry `+0x10`을
`[EBP-0x44]`에, 두 번째 lane은 entry `+0x10`을 `EBX`에 넣고 nested-call 합류점으로
갈 수 있다. 그 뒤 clear는 각각 argument와 그 값의 runtime 동등성 비교가 참일 때만
실행된다. 이 보고서 범위는 flag-one clear가 어떤 앞선 재귀 상태와 짝을 이루는지,
동일 포인터가 alias인지, helper 내부 효과나 다른 CFG entry를 증명하지 않는다.

명령어 원시 바이트·Python 집계는
[map-copy-recursive-lock-cfg.json](map-copy-recursive-lock-cfg.json)에, 분석 범위는
[SCOPE.md](SCOPE.md)에 기록했다.
