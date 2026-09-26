# IDA GhidraDec 전역 headless 설치 절차

이 문서는 2026-09-22에 검증한 Linux x86-64 IDA Pro 9.3 전역 설치 절차만 기록한다. 설치 대상은 headless `idat` 분석이며, GUI 검증은 이 절차의 조건이 아니다.

## 고정 대상

| 항목 | 고정 값 |
|---|---|
| IDA root | `/mnt/USERS/onion/DATA_ORIGN/local/ida-pro-9.3` |
| Ghidra root | `/home/onion/ghidra_12.1_PUBLIC` |
| durable plugin artifact | `10_tools/vendor-cache/ghidradec64-ida93-linux-ea64-42d7343debf731ca749e09f6e7c010eff94230c194928509e56bcc46f3e9fea2.so` |
| plugin 설치 경로 | `$IDA_ROOT/plugins/ghidradec64.so` |
| wrapper 설치 경로 | `$IDA_ROOT/idat-ghidradec` |
| plugin SHA-256 | `42d7343debf731ca749e09f6e7c010eff94230c194928509e56bcc46f3e9fea2` |
| wrapper SHA-256 | `fe0bdbd769594603cd8cdc2ff047be77a0bb6cdab229ba4b24117b3e37c9afba` |
| GhidraDec source commit | `35afec3d588407de8e2aae5330f26dea857c26bd` |
| IDA SDK v9.3 source commit | `d5db59ab4e9d2ae92038e9520082affd0da6fe20` |

지속 보관 source bundle과 검증된 plugin artifact는 `10_tools/vendor-cache/`에 있다. `/tmp` build artifact는 재부팅 뒤 사라지므로 설치 입력으로 사용하지 않는다. candidate build 및 source bundle 근거는 [후속 런타임 검증](../09_validation/reports/multiarch-input-20260921/ghidradec-candidate-followup-20260922/README.md)에 있다.

현재 artifact는 pinned upstream source에 [exact headless patch](patches/ghidradec-headless-slice-output.patch)를 적용해 빌드했다. 이 patch는 `GHIDRADEC_BATCH_OUTPUT`의 저장 대화상자 생략, `GHIDRADEC_BATCH_FUNCTION_MARKERS=1`의 주소 marker, `GHIDRADEC_BATCH_INCLUDE_SKIPPED=1`의 모든 IDA function 후보 포함, `GHIDRADEC_BATCH_FUNCTION_STARTS`의 exact-address 선택을 제공한다. batch corpus runner는 `GHIDRADEC_BATCH_FORCE_MAPPED_SYMBOL_HOLES=1`로 재현된 mapped-symbol callback SIGSEGV를 피한다. 이 안전 모드의 C는 data/function symbol과 type 추론을 보존하지 않으므로 원본 bytes·assembly보다 약한 가설로만 취급한다. GUI 경로와 이 환경변수가 없는 기존 저장 대화상자 경로는 변경하지 않는다.

## 사전 검증

다음 Python 명령으로 artifact와 Ghidra 경로를 확인한다. SHA-256 계산은 Python으로만 한다.

```bash
python3 - <<'PY'
from pathlib import Path
import hashlib
import subprocess

plugin = Path('10_tools/vendor-cache/ghidradec64-ida93-linux-ea64-42d7343debf731ca749e09f6e7c010eff94230c194928509e56bcc46f3e9fea2.so')
ghidra = Path('/home/onion/ghidra_12.1_PUBLIC')
expected = '42d7343debf731ca749e09f6e7c010eff94230c194928509e56bcc46f3e9fea2'

digest = hashlib.sha256()
with plugin.open('rb') as stream:
    for block in iter(lambda: stream.read(1024 * 1024), b''):
        digest.update(block)
if digest.hexdigest() != expected:
    raise SystemExit('plugin SHA-256 mismatch')
dynamic = subprocess.run(['readelf', '-d', str(plugin)], check=True, text=True,
                         stdout=subprocess.PIPE).stdout
if '(RPATH)' in dynamic or '(RUNPATH)' in dynamic:
    raise SystemExit('plugin has RPATH/RUNPATH')
if not (ghidra / 'Ghidra/Processors/68000/data/languages/68040.sla').is_file():
    raise SystemExit('m68k Ghidra language is missing')
if not (ghidra / 'Ghidra/Processors/Sparc/data/languages/SparcV9_32.sla').is_file():
    raise SystemExit('SPARC Ghidra language is missing')
print('pre-install verification passed')
PY
```

## Wrapper 작성

`/tmp/idat-ghidradec`에 아래 내용을 정확히 저장하고 executable mode를 설정한다.

```bash
#!/usr/bin/env bash
set -eu
export GHIDRADEC_GHIDRA_DIR=/home/onion/ghidra_12.1_PUBLIC
export GHIDRA_INSTALL_DIR=/home/onion/ghidra_12.1_PUBLIC
exec /mnt/USERS/onion/DATA_ORIGN/local/ida-pro-9.3/idat "$@"
```

```bash
chmod 0755 /tmp/idat-ghidradec
```

wrapper checksum은 다음 Python으로 확인한다.

```bash
python3 - <<'PY'
from pathlib import Path
import hashlib

path = Path('/tmp/idat-ghidradec')
expected = 'fe0bdbd769594603cd8cdc2ff047be77a0bb6cdab229ba4b24117b3e37c9afba'
if hashlib.sha256(path.read_bytes()).hexdigest() != expected:
    raise SystemExit('wrapper SHA-256 mismatch')
print('wrapper verification passed')
PY
```

## 전역 설치

다음 두 명령은 기존 동일 경로 파일을 교체한다. plugin 또는 wrapper가 현재 검증 대상과 다른 경우에는 먼저 사전 검증을 통과시킨다.

```bash
install -m 0755 -T 10_tools/vendor-cache/ghidradec64-ida93-linux-ea64-42d7343debf731ca749e09f6e7c010eff94230c194928509e56bcc46f3e9fea2.so \
  /mnt/USERS/onion/DATA_ORIGN/local/ida-pro-9.3/plugins/ghidradec64.so

install -m 0755 -T /tmp/idat-ghidradec \
  /mnt/USERS/onion/DATA_ORIGN/local/ida-pro-9.3/idat-ghidradec
```

## 설치 후 검증

반드시 canonical DB가 아닌 새 `/tmp` copied DB에서 실행한다. 두 원본은 big-endian이다. m68k는 `68K`와 `68040.sla`, SPARC는 `sparcb`와 `SparcV9_32.sla`가 검증 대상이다.

```bash
GHIDRADEC_TEST_LIVE_CALLBACKS=1 \
GHIDRADEC_TEST_TARGET_EA=0x40013d6 \
GHIDRADEC_BATCH_OUTPUT=/tmp/m68k-ghidradec.c \
GHIDRADEC_TEST_INPUT_PATH=/tmp/mach_kernel \
/mnt/USERS/onion/DATA_ORIGN/local/ida-pro-9.3/idat-ghidradec \
  -A -S10_tools/ida_ghidradec_headless_smoke.py /tmp/m68k-working.i64
```

이 smoke script는 `ghidradec`와 `ghidradec64` plugin identifier를 순서대로 시도한다. 64-bit Linux plugin filename에서는 후자가 필요할 수 있다. `GHIDRADEC_TEST_LIVE_CALLBACKS=1`은 검증된 callback 경로다. 기본 무인 UI-dispatch 경로는 댓글 callback timeout을 낼 수 있으므로 사용하지 않는다.

설치된 파일, 두 아키텍처의 original SHA-256, protocol 및 C output의 최종 검증 결과는 [전역 설치 검증 보고서](../09_validation/reports/multiarch-input-20260921/ghidradec-global-install-20260922/README.md)에 보존되어 있다. 생성 C는 decompiler 해석 가설이며 원본 bytes로 대조하기 전에는 함수 경계, ABI, code/data 분류 또는 동작의 증거가 아니다.
