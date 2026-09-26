# GhidraDec 전역 headless 설치 검증

GhidraDec EA64 plugin을 로컬 IDA 9.3 전역 경로 `plugins/ghidradec64.so`에 설치했다. SHA-256은 `194f39a774f7d5a8fc13cfe5f03dc24dff2bc6f675dda28603d86d208f500686`이다. `idat-ghidradec` wrapper는 Ghidra 12.1 경로를 설정한 뒤 IDA `idat`를 실행하며 SHA-256은 `fe0bdbd769594603cd8cdc2ff047be77a0bb6cdab229ba4b24117b3e37c9afba`이다.

temporary user plugin 디렉터리를 사용하지 않고, 전역 plugin과 wrapper만 사용해 새 `/tmp` copied DB에서 다음을 확인했다.

| 대상 | IDA processor / byte order | Ghidra 언어 | target | C output |
|---|---|---|---|---:|
| m68k | `68K` / big-endian | `68040.sla` | `0x40013d6` | 394 bytes |
| SPARC | `sparcb` / big-endian | `SparcV9_32.sla` | `0xf0003144` | 322 bytes |

양쪽 probe는 `GHIDRADEC_TEST_LIVE_CALLBACKS=1`과 batch output path를 명시했다. original binary SHA-256, `getcomments` response, decompile response, C output 및 timeout 부재를 Python으로 검증했다. 세부 hash와 protocol logs는 [assessment.json](assessment.json)에 있다.

일반 headless 사용법은 [IDA_GHIDRADEC_HEADLESS.md](../../../../10_tools/IDA_GHIDRADEC_HEADLESS.md)에, 설치 파일·SHA-256·정확한 설치 명령은 [IDA_GHIDRADEC_GLOBAL_INSTALL.md](../../../../10_tools/IDA_GHIDRADEC_GLOBAL_INSTALL.md)에 있다. 이 설치는 decompiler 도구 사용 가능 여부만 확인한다. 생성 C는 함수 범위·code/data 분류·ABI·동작의 증거가 아니며, 원본 커널 분석에 쓰기 전에는 원본 bytes와 별도로 대조해야 한다.
