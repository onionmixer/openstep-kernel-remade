# Callout API 소유권·중복 처리·실제 caller

71차의 후속으로 calloutEntryAllocate/Free, 일반 Dispatch/Unique/Delayed/Remove/RemoveAll, WithArgument 변형과 lightning_bolt·log open/close/wakeup/callback의 전체 본문을 검토한다. 공개 callout 이름의 export 목록을 70~72차 본문 검토 기록에 매핑하되 모든 caller·경합·하위 callee까지 완료한 것으로 표시하지 않는다.

Ghidra 스킬을 보존 ASM/C/metadata의 읽기 전용 대조에 적용한다. 주소·크기·해시·명령어/분기·상태 및 유한 산술 계산은 모두 Python으로 수행한다. 원본·참고 소스·분석 DB·export·이전 확정 보고서·07_kernel을 보존하고 새 문서/정적 증거만 apply_patch로 추가한다.

신규 독립 계획 교차검토는 확보되지 않았다. 이전 실패 검토를 재요청·우회하지 않고 구현·동적 실행·새 emulator/verifier 파일 작성으로 전환하지 않는다. kalloc/kfree 전체 오류·생존 계약, 모든 export 외/간접 caller, log subsystem 전체 serialization, native IRQ/SMP 및 실제 continuation/clock 실행, GCC 2.7 실컴파일·boot는 이 보고서만으로 완료하지 않는다. 전체 목표는 계속 미완료다.
