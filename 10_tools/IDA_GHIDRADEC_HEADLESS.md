# IDA GhidraDec headless 사용

전역 설치 파일·SHA-256·설치 및 재검증 절차는 [IDA_GHIDRADEC_GLOBAL_INSTALL.md](IDA_GHIDRADEC_GLOBAL_INSTALL.md)에 있다.

전역 IDA 설치의 `idat-ghidradec` wrapper는 로컬 Ghidra 12.1 경로를 설정한 뒤 IDA `idat`를 실행한다. m68k와 SPARC는 big-endian canonical DB를 직접 열지 말고 새 `/tmp` 복사본에서만 실행한다.

다음은 명시적으로 검증한 live-callback 경로의 형식이다. `GHIDRADEC_TEST_TARGET_EA`와 output 위치는 대상별로 바꾼다.

```bash
GHIDRADEC_TEST_LIVE_CALLBACKS=1 \
GHIDRADEC_TEST_TARGET_EA=0x40013d6 \
GHIDRADEC_BATCH_OUTPUT=/tmp/m68k-ghidradec.c \
GHIDRADEC_TEST_INPUT_PATH=/tmp/mach_kernel \
/mnt/USERS/onion/DATA_ORIGN/local/ida-pro-9.3/idat-ghidradec \
  -A -S10_tools/ida_ghidradec_headless_smoke.py /tmp/m68k-working.i64
```

기존 `run_ghidradec_function_slices.py`의 non-live batch는 `GHIDRADEC_BATCH_FORCE_MAPPED_SYMBOL_HOLES=1` 경로에서 모든 출력이 `Bad decompile address` native message임이 확인됐다. 따라서 해당 historical corpus와 runner 결과를 C 가설로 사용하지 않는다. 현재 유효성이 확인된 경로는 위와 같이 `GHIDRADEC_TEST_LIVE_CALLBACKS=1`을 명시한 copied DB selective probe뿐이다. 전수 재생성 전에는 작은 live slice에서 native-message 부재와 callback 안정성을 먼저 검증해야 한다.

출력 C는 decompiler 도구의 해석 가설이다. 함수 범위, endian-sensitive operand, code/data 분류, ABI 또는 동작을 확정하는 근거로 사용하지 말고 원본 binary bytes와 별도로 대조한다.
