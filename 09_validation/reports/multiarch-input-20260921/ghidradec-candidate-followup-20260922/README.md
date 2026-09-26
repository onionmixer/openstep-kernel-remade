# GhidraDec 후보 후속 런타임 검증

이 디렉터리는 초기 실패 기록을 덮어쓰지 않는 후속 검증이다. 모든 실행은 canonical IDA DB와 원본 `mach_kernel`의 새 `/tmp` 복사본에서만 실시했으며, m68k와 SPARC 원본 SHA-256, plugin SHA-256, target 주소와 크기는 Python으로 대조했다. canonical DB와 전역 IDA 설치는 변경하지 않았다.

동일한 RPATH/RUNPATH 없는 plugin `194f39a774f7d5a8fc13cfe5f03dc24dff2bc6f675dda28603d86d208f500686`으로 두 명시적 회귀 경로를 확인했다.

| 대상 | byte order | Ghidra 언어 | 대상 함수 | batch C 출력 | live-callback C 출력 |
|---|---|---|---|---:|---:|
| m68k | big-endian | `68040.sla` | `_pflush_super` `0x40013d6`, 30 bytes | 394 bytes | 496 bytes |
| SPARC | big-endian | `SparcV9_32.sla` | `_return_with_state` `0xf0003144`, 44 bytes | 320 bytes | 4,307 bytes |

두 경로 모두 `decompileAt` 요청, `getcomments` 질의 및 응답, decompile 응답을 기록했고 timeout 없이 C 출력을 만들었다. `batch`는 `GHIDRADEC_BATCH_OUTPUT`로 UI-dispatch 교착을 피하는 무인 경로이며, `live`는 `GHIDRADEC_TEST_LIVE_CALLBACKS=1`로 댓글을 생략하지 않고 IDA API callback을 직접 처리한다. 초기 기본 무인 경로의 timeout은 이 두 성공 결과와 별도로 [초기 assessment](../ghidradec-candidate-20260922/README.md)에 그대로 남긴다.

일반 IDA GUI 선택 디컴파일의 자동 시험은 IDA가 프로토콜을 생성하기 전에 종료되어 유효한 결과가 아니었다. 따라서 후보 core runtime은 확인됐지만, 전역 IDA 배포 승인은 아직 보류한다. m68k와 SPARC 각각에서 일반 GUI 선택 디컴파일을 성공시키고 그 결과를 보존한 뒤에만 전역 plugin과 영구 설정을 설치한다.

이 C 출력은 원본 커널의 함수 경계, code/data 분류, ABI 또는 동작을 확정하지 않는다. 후속 분석에서 사용하는 decompiler 해석은 해당 원본 바이트로 독립 대조해야 한다. 재생성 도구는 `10_tools/audit_ida_ghidradec_followup.py`이며 상세 hash와 protocol evidence는 [assessment.json](assessment.json)에 있다.
