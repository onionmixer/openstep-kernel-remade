# Callout backend와 clock 연결의 정적 검토

70차에서 남긴 callout 등록·제거·만료 전달·worker callback 및 clock backend 연결을 원본 본문으로 검토한다. 초기화, entry dispatch/delayed/remove, wake helper, worker/creator continuation, timer expire 등록과 system timer dispatch, clock_value/보간 helper, timer attributes/set_timer, ns_hardclock_init/hardclock_init을 포함한다.

Ghidra 스킬을 보존 export 읽기 전용 대조에 적용한다. 원본 Mach-O 매핑·명령어·직접 제어 이전·데이터·주소와 정수 계산은 Python으로 검증한다. inline Python은 원본 읽기·디코딩·유한 산술·JSON 증거 생성에 한정하며 CPU/커널 실행이나 새로운 emulator/verifier 파일을 만들지 않는다. 모든 파일 추가는 apply_patch로 한다.

신규 독립 계획 교차검토는 확보되지 않았다. 이전 실패 검토를 재요청·우회하지 않고 구현·동적 실행으로 전환하지 않는다. 원본·참고 소스·DB·export·기존 확정 보고서·07_kernel을 보존한다.

native interrupt/SMP 경합·진행성, callback와 element 전체 수명, 실제 continuation 비복귀/stack 전환, worker 생성 실패 처리, unsigned division runtime helper 내부, hardware clock 초기화와 전역 값의 전체 writer, 나머지 callout API·scheduler 전수 의미, 실제 GCC 2.7 빌드/boot는 이번 검증만으로 완료 처리하지 않는다. 전체 목표는 계속 미완료다.
