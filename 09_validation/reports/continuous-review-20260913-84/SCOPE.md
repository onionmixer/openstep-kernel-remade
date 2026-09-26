# 84차 원본 분석 범위와 검토 계획

현재 사용자 범위는 OPENSTEP 원본 x86 커널 분석뿐이다. Mach4·NeXTMach·Darwin,
`01_resources` 및 `07_kernel`의 코드를 열거나 참고하지 않는다. 원본 바이트,
해당 바이너리의 Ghidra export와 nlist, 이전 원본 전용 보고서만 근거로 사용한다.

## 선정 이유와 순서

[83차 미완료 목록](../continuous-review-20260913-83/OPEN_ITEMS.md)의 buffer I/O 계약을 잇는다.
breadDirect, bread, breada, vnReadAhead, incore, getblk, bdwrite, bawrite, brelse에
biowait, geterror, bwrite, biodone 및 원본 vnode 결합/분리 helper를 연결한다.

1. 이전 checkpoint와 보존 대상, 원본 SHA-256 및 선택한 export의 baseline을 재검증한다.
2. 전체 선택 함수의 원본 파일 mapping·명령 경계·직접 분기를 Python/Capstone으로 대조한다.
3. read byte 수·copy 길이·오류 WORD/flag/uerror BYTE, wait/wakeup와 async release를 읽는다.
4. 스택 header의 hash 게시/해제와 vnode 참조, cached buffer 반환 후 필드 접근을 구분한다.
5. 원본 vnodeops의 strategy slot과 이전 filesystem caller의 한정된 명령 구간을 대조한다.
6. 조건부 정수 예시와 명령 근거를 보존하고 하위 strategy/allocator 및 native 미확인을 남긴다.

## 안전 경계

Ghidra 스킬의 함수 본문·디컴파일·참조 대조 방식을 기존 export에 적용한다.
라이브 DB, 원본 파일, 확정된 이전 보고서는 변경하지 않는다. 새로운 verifier 소스,
에뮬레이터, 구현 코드나 동적 실행은 추가하지 않는다. 인라인 Python은 원본 바이트의
해독·주소/폭/비트/해시 계산과 정적 증거 출력에만 사용하고 파일 변경은 apply_patch로 한다.

독립 계획 교차검토는 이번 회차에 수신하지 않았다. 과거 실패를 통과로 바꾸거나
실패한 요청을 재시도·우회하지 않는다. 계산 대조는 독립 에이전트 검토가 아니다.
디컴파일 타입과 관습적 flag 이름은 확정된 구조체 정의로 취급하지 않는다.
간접 호출의 실제 실행, 모든 IRQ/동시성·수명·완료 전달은 정적 지역 증거만으로 확정하지 않는다.

이 회차의 종료는 전체 원본 분석 완료와 다르다. 결과는 [보고서](README.md),
[정적 증거](object-lifetime-evidence.json), [남은 항목](OPEN_ITEMS.md)에 분리한다.
