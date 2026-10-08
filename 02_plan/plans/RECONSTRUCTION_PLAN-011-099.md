# 커널 소스 복원 작업계획 — 보관 §11–99

`02_plan/RECONSTRUCTION_PLAN.md` 의 §11–99 를 절 번호·내용 그대로 옮긴 보관본(2026-10-03, D026). 인용 "RECONSTRUCTION_PLAN.md N" 은 이 파일의 같은 번호 절을 가리킨다. 아래는 원문 그대로다.

---

## 11. S1-A 세부 계획 — 빌드 왕복과 툴체인 probe (코딩 전, 2026-10-01)

확인한 실기 조건(읽기 전용 명령): 해시 도구는 `/usr/bin/sum`(16 비트 BSD 체크섬)뿐이고 `cksum`·`md5`·`shasum`·`env`·`mktemp` 가 없다. `/bin/cmp`·`/bin/od`·`/usr/bin/find`·`/usr/bin/sort` 는 있다. `gcds` 명령은 `sh` 로 실행된다(로그인 셸은 csh, umask 0022). 실기 시계는 호스트보다 5 일 7:34:01 느리다(Python). 호스트에는 독립 교차 확인용 `llvm-objdump`(11, 14)가 있다.

A1. 실기용 SHA-256 도구
- `10_tools/reconstruction/target/krsha256.c`: FIPS 180-4 를 따라 새로 쓴 C89 구현(외부 코드 복사 없음). 사용법 `krsha256 FILE...` → `hex  size  path`.
- 실기에서 `/bin/cc -O` 로 빌드해 `08_build/runs/tools/`(git 무시)에 둔다. 표준 시험 벡터(빈 입력, "abc", 448 비트 메시지, 'a' 1,000,000 개)와 임의 파일 몇 개(0 B, 55·56·63·64·65 B 경계, 1 MiB 이상)의 결과가 호스트 Python `hashlib` 과 모두 같아야 쓴다. 16 비트 `sum` 은 쓰지 않는다.

A2. 빌드 실행 규약 도구(호스트 Python + 실기 sh)
- `10_tools/reconstruction/kr_run.py prepare ID SRC_DIR CMDFILE`: `08_build/runs/ID/` 가 이미 있으면 거부. `src/` 에 복사, 파일마다 SHA-256·크기·모드·종류를 담은 `input.manifest`, 대소문자만 다른 경로·심볼릭 링크·비정규 파일은 거부. 실기용 `run.sh` 를 생성한다.
- `run.sh`(실기, sh): ① `mkdir 08_build/runs/lock` 으로 단일 실행 잠금(실패하면 중단) ② `krsha256` 로 `src/` 를 다시 계산해 `input.manifest` 와 비교, 하나라도 다르면 중단 ③ `PATH=/bin:/usr/bin`, `TZ=GMT` 만 남긴 환경, 도구는 절대 경로 ④ 빈 `stage/` 에서 명령 파일의 줄을 차례로 실행하며 줄마다 종료 코드를 `stage.log` 에 기록 ⑤ `stage/` 전체를 `krsha256` 로 `output.manifest` 작성 ⑥ 마지막에 `DONE <종료코드>` 파일을 쓰고 잠금 해제. 오래 걸리면 `nohup` 으로 분리.
- `kr_run.py collect ID`: `DONE` 이 있고 0 인지, `output.manifest` 의 모든 파일을 호스트 Python 으로 다시 계산해 같은지, 빈 파일이 없는지 확인한 뒤에만 `stage/` → `out/` 으로 이름을 바꾸고 `run.json`(입력·출력 해시, 명령, 도구 해시 `08_build/toolchains/real-i386-20261001/sha256-vs-vm.json` 참조, 실기·호스트 시각) 을 쓴다.
- 시험: 입력 파일 1 바이트 변조, 출력 파일 삭제·절단, 잠금 중복, 실패하는 명령이 모두 거부·실패로 나오는지.

A3. probe 소스(`10_tools/reconstruction/probes/`, 새로 작성)
- `c_layout.c`: 여러 구조체(정렬·비트필드·중첩·배열)의 `sizeof`·`offsetof` 를 초기화된 전역 배열에 넣는다(실행 없이 `.o` 의 `__data` 에서 읽음).
- `c_codegen.c`: 잎 함수, 정적 함수 호출, 외부 함수 호출, 전역 읽기·쓰기, 문자열 리터럴, `switch` 점프 표 — L1 도구 시험용 재료.
- `objc_probe.m`: `Object` 하위 클래스(인스턴스 변수, 인스턴스·클래스 메서드, 카테고리 하나).
- `asm_probe.s`: 함수 하나와 데이터 하나.
- `mig_probe.defs`: 루틴 하나 → `/usr/bin/mig` 로 생성한 `.c`·`.h` 를 컴파일.
- 명령 두 벌: 기본(`/bin/cc -arch i386 -c`)과 커널 후보(`-static -fno-common` 에 `-O`/`-O2`). 옵션 효과는 S1-4 에서 본다. 같은 입력을 두 번 빌드해 출력 해시가 같은지(결정성) 확인한다.

A4. 호스트 Mach-O 목적 파일 판독기
- `10_tools/reconstruction/macho_obj.py`: MH_OBJECT(i386) 의 header, `LC_SEGMENT` 섹션, `LC_SYMTAB` 심볼, 섹션별 재배치(일반·scattered) 판독. 판독 결과(섹션 이름·크기·오프셋, 심볼 이름·섹션·값, 재배치 개수·주소·형식)를 `llvm-objdump`(`-h`, `-t`, `-r`) 출력과 대조해 모두 같아야 한다. 대조가 안 되는 항목은 명시적으로 "미대조" 로 둔다.
- `c_layout.o` 의 `__data` 에서 읽은 값을 표로 기록(`09_validation/reconstruction/toolchain/`).

완료 조건: A1 벡터 전부 일치, A2 이상 시험 전부 기대대로, probe 전부 컴파일(종료 0)·수집(해시 일치)·결정성 확인, A4 판독이 `llvm-objdump` 와 일치. 실기 시계는 바꾸지 않는다(시각에 의존하지 않는 설계).

### 11.1 codex 교차검토 반영 (QS1: A2 규약, QS2: A1 시험 범위)

인용 줄(`RECONSTRUCTION_PLAN.md:64,72,159,161,166,167,168`)은 모두 열어 해당 내용임을 확인했다. 각 지적은 설계 논리라 사실 검증 대상은 "현재 계획에 그 대책이 없는가"이며, 계획 본문으로 확인했다.

| 지적 | 판정 | A1·A2 에 더하는 대책 |
|---|---|---|
| QS1 목록 밖 파일이 `out/` 로 들어감 | ✅ | collect 는 `stage/` 전체 목록이 `output.manifest` 와 **정확히 같아야** 통과 |
| QS1 출력 심볼릭·하드 링크 | ✅ | 실기(`find -type`)·호스트(`os.lstat`, `st_nlink==1`)에서 정규 파일·디렉터리만 허용 |
| QS1 목록 밖 의존(시스템 헤더 등) 읽기 | ⚖️ | 격리는 OPENSTEP 에서 비현실적. 대신 번역 단위마다 `/bin/cc … -M` 로 실제 읽은 헤더 목록을 얻어 그 파일들의 SHA-256 을 기록한다. 결과를 저장소 밖 경로(실기 로컬 헤더)와 안(`src/`)으로 나눠 남기고, `src/` 밖 저장소 경로를 읽으면 실패 |
| QS1 빌드 중 입력 변경 | ✅ | 빌드 뒤 `DONE` 전에 입력 manifest 를 다시 검사 |
| QS1 명령·`run.sh`·도구 미결속 | ✅ | 명령 파일·`run.sh` 를 입력 manifest 에 포함, 실기에서 매 실행마다 사용하는 도구(`/bin/cc`, `/lib/i386/*` 등)를 `krsha256` 로 재계산해 `08_build/toolchains/real-i386-20261001/sha256-vs-vm.json` 과 비교 |
| QS1 검증 뒤 다른 쓰기 | ✅ | 명령은 전경 실행만(배경 `&` 금지, 명령 형식 검사), collect 는 이름 바꾼 뒤 `out/` 를 다시 해시 |
| QS1 NFS 반영·내구성 | ✅ | 순서: 출력 완료 → `sync` → `output.manifest` → `sync` → `DONE` → `sync`. 호스트(NFS 서버) 디스크에서 재해시가 실기 해시와 같아야 통과 — 서버에 도달한 바이트를 직접 확인하는 셈 |
| QS1 잠금이 충돌 뒤 남음 | ✅ | 잠금 디렉터리에 실행 ID·실기 PID 기록. 남은 잠금은 자동 제거하지 않고, 실기에서 그 PID 가 없음을 확인한 뒤 수동 제거(기록 남김) |
| QS1 ID 재사용 | ✅ | `08_build/runs/REGISTRY`(추가 전용)에 ID 를 먼저 등록, 등록된 ID 는 삭제 뒤에도 재사용 거부. 모든 표시 파일에 ID 기록 |
| QS1 아무것도 안 만든 성공 | ✅ | 명령 파일에 `EXPECT <경로>` 로 필수 산출물을 선언, 없거나 빈 파일이거나 Mach-O 매직이 아니면 실패 |
| QS1 셸 상태·환경 | ✅ | 명령은 파이프·`;`·`&&`·`&` 없는 단일 명령만 허용(prepare 에서 검사), 각 줄을 실행 직후 `$?` 기록. 환경은 `run.sh` 가 `PATH`·`TZ` 만 설정하고 나머지를 `unset`. 이 동작을 실기 `/bin/sh` 로 먼저 시험 |
| QS1 `run.json` 게시 전 부재 | ✅ | `run.json` 을 `stage/` 안에 먼저 쓰고 검증한 뒤 한 번의 이름 바꾸기로 게시 |
| QS2 2^29 바이트 이상 길이 | ⚖️ | 길이를 64 비트(32 비트 두 워드 + 올림)로 구현하되, 빌드 산출물 크기에 맞춰 **256 MiB 초과 파일은 거부**(오류 종료). 상한 거부를 시험 |
| QS2 버퍼 경계 비정렬 | ✅ | 읽기 버퍼 크기를 컴파일 옵션으로 바꿀 수 있게 하고 1009 B 버퍼 판으로 같은 결과인지 시험 |
| QS2 짧은 읽기 | ✅ | `fread` 반복을 EOF·오류까지. 1009 B 버퍼 시험과 NFS 위 큰 파일 시험으로 확인 |
| QS2 부호 있는 `char` | ✅ | 모든 바이트 값(0x00–0xff)을 여러 블록 경계에 걸쳐 담은 파일 시험, 내부는 `unsigned char` |
| QS2 여러 파일 사이 상태 | ✅ | 비어 있지 않은·빈·비어 있지 않은 파일을 한 번에 넘겨 해시와 **크기**를 모두 비교 |
| QS2 열기·읽기 오류를 성공으로 보고 | ✅ | 없는 파일·읽기 불가 파일 → 0 이 아닌 종료, 그 파일의 해시 줄 없음 |
| QS2 stdin | ⏭️ | stdin 은 지원하지 않는다(인자 없으면 사용법 오류) |

### 11.2 S1-A 결과 (2026-10-01)

- **A1 `krsha256`**: 호스트(gcc C89, 64 비트 long)와 실기(`/bin/cc -O`, 기본판·1009 B 버퍼판) 모두 해시 22 개(공개 벡터 4 개 포함)·크기 일치, 없는 파일·256 MiB 초과 거부(종료 1). 실기 바이너리 `08_build/runs/tools/target/krsha256-default`.
- **A2 `10_tools/reconstruction/kr_run.py`**: 정상 실행 2 회 게시. 거부 시험: ID 재사용, 준비 뒤 입력 변조(`input mismatch`), 실패 명령(종료 1 기록·게시 거부), 필수 산출물 누락, 수집 전 출력 변조(해시 불일치), `stage` 에 목록 밖 파일, 잠금 보유 중 실행, 금지 명령 형식(`;`, 허용 목록 밖 도구) — 모두 기대대로. 발견·수정: ① 표시 파일(DONE/FAILED)이 잠금 해제보다 먼저 써져 연속 실행이 `LOCKED` → launch 는 잠금이 있으면 거부, `wait` 는 잠금 해제까지 대기 ② NFS silly-rename(`.nfsNNNN`)으로 잠금 디렉터리 안 파일을 지운 뒤 `rmdir` 실패 → 소유자 정보를 `LOCK.owner`(디렉터리 밖)로 옮김.
- 실기 셸 확인: 함수·`unset`·`find -links/-exec`·`cmp`·`mkdir` 원자성 가능, `printf`·`sort -k` 없음(`sort +2`). `gcds` 로 `ps` 를 부르면 멈추고, 백그라운드 실행은 한 줄 + `< /dev/null > … 2>&1 &` 이어야 한다.
- **A3 probe**: 기본 옵션 실행 2 회의 목적 파일 4 개 해시가 서로 같다(결정적). 커널 후보 옵션(Darwin 0.1 `conf/Makefile.i386`+`MASTER.i386`: `-static -traditional-cpp -fwritable-strings -fno-common -O3`)으로 C·ObjC·asm·MIG 생성·생성 코드 컴파일 모두 종료 0. `-fpascal-strings` 는 `cc-744.13` 의 `cc1obj` 가 거부한다(Darwin 0.1 설정은 더 새 컴파일러 전제). `cc -M`(cpp-precomp) 은 의존 목록이 불완전 → 의존 기록은 `-traditional-cpp -E` 의 줄 표시로 한다(`objc_probe.m` → 30 파일).
- 구조체 배치(`09_validation/reconstruction/toolchain/c-layout-probe-20261001.json`): char 1, short 2, int 4, long 4, 포인터 4, float 4, double 8; `{char;double}` = 12(double 오프셋 4); 비트필드 3+5+9 뒤 char 오프셋 3, 전체 4. 두 옵션 세트에서 같다.
- **A4 `macho_obj.py`**: 목적 파일 10 개에서 섹션·심볼·재배치(scattered·SECTDIFF·PAIR 포함)가 `llvm-objdump-14` 와 전부 일치(`check_macho_obj.py`). 대조 과정의 수정은 llvm 출력 형식 해석(공백 있는 ObjC 메서드 이름, `*COM*` 열, 주소 없는 PAIR 줄, 7 자로 잘린 재배치 종류 이름)과 판독기의 common 심볼 분류다.
- 참고 코드 사실(후보): Darwin 0.1 `MASTER.i386` 의 `RELOC 00100000`·`SYMADDR 00780000` 이 원본 커널의 `__TEXT` 0x100000·`__LINKEDIT` 0x780000 과 같다.
- 관찰: `-O3` 에서 `switch` 점프 표가 `__text` 안에 있고 항목마다 재배치가 붙는다. 정적 함수가 인라인되어 사라진다. L1 도구 설계(재배치 해석·표 포함)에 반영한다.

다음: S1-4 컴파일 옵션 표본 시험과 L1·L1d 비교 도구(S1-5). 착수 전 세부 계획과 codex 검토.

## 12. S1-B 세부 계획 — L1·L1d 비교 도구 (코딩 전, 2026-10-01)

순서 결정: 옵션 표본 시험(S1-4)은 비교 도구가 있어야 점수를 낼 수 있으므로 비교 도구(S1-5)를 먼저 만든다(S1-B), 옵션 시험은 S1-C.

입력:
- 원본: 링크된 Mach-O(`03_original/x86/binaries/mach_kernel`, MH_EXECUTE). 원본 심볼(외부 3,651, 로컬 없음)과 Ghidra `04_ghidra/exports/x86/full-pass5/functions.json`(함수별 `body` 범위 목록, 떨어진 범위 가능, `status`).
- 후보: 실기에서 만든 재배치 가능 목적 파일(MH_OBJECT), `macho_obj.py` 로 판독(`llvm-objdump` 와 대조 완료).
- **배치(placement)**: 후보 목적 파일의 각 섹션이 원본의 어느 주소에 놓이는지. `__text` 배치는 사용자가 준다(예: 첫 함수 심볼을 원본 심볼 주소에 맞춤). 데이터 섹션 배치는 참조에서 **추론**하고, 추론한 배치에서 섹션 바이트 전체를 L1d 로 대조해 확인한다(추론만으로 판정하지 않음).

비교 단위와 절차(`10_tools/reconstruction/l1_compare.py`):
1. 함수 범위: 목적 파일 `__text` 의 심볼(외부·정적)을 주소순으로 정렬해 함수 범위를 만든다(다음 심볼 또는 섹션 끝까지). 범위 끝의 정렬 채움(`0x90` 등)은 분리해 따로 비교한다. 원본 쪽 범위는 배치로 얻은 주소이며, Ghidra `body` 와 다르면 "경계 불일치"로 기록한다(판정 보류 사유).
2. 바이트: 재배치 필드를 뺀 모든 바이트가 원본과 같아야 한다.
3. 참조(재배치 필드): 종류별로 원본 쪽 값을 해석해 대상 비교.
   - 외부 심볼 + 절대: 원본 필드값 − 목적 파일의 가산값 = 원본 심볼표에서 그 이름의 주소.
   - 외부 심볼 + PC 상대(`call`): 원본 필드 주소 + 길이 + 변위 = 그 이름의 원본 주소.
   - 섹션 상대(비외부): 목적 파일 필드값(섹션 주소 공간)을 그 섹션의 배치로 옮긴 값 = 원본 필드값. 배치가 없는 섹션이면 "참조 미확인".
   - scattered `SECTDIFF`+`PAIR`: 두 값을 각각 배치로 옮겨 (A−B+상수) 가 원본 필드값과 같은지. 배치 없으면 미확인. 그 밖의 재배치 형식은 거부(오류).
   - 이름이 원본 심볼표에 없는 외부 참조(원본에서 정적이었을 함수 등)는 "참조 미확인".
4. 재배치 없는 PC 상대 분기·호출: capstone(x86-32)으로 디스어셈블해 목적지를 구하고, 목적지가 비교 대상 범위 안(배치된 `__text`)이면 원본에서도 같은 상대 위치이므로 바이트 동일로 충분하다. 목적지가 비교 범위 밖이면 "참조 미확인".
5. 점프 표·리터럴: 목적 파일 `__text` 안의 재배치가 걸린 데이터(표)는 함수 범위에 포함되므로 3 에서 대상까지 비교된다.
6. L1d: 데이터 섹션(배치가 있거나 추론된 것)의 바이트를 재배치 필드 밖에서 비교하고, 섹션 안 재배치(포인터)는 3 의 규칙으로 비교한다.
7. 결과 분류(함수마다): **일치**(바이트·모든 참조 확인), **일치·참조 일부 미확인**(바이트 동일, 미확인 참조 목록), **다름**(첫 차이 위치·종류), **경계 불일치**. 분모는 목적 파일 함수 수와 원본 바이트 수 둘 다. 모든 계산은 Python.

자기 시험(도구를 믿기 전):
- T1 실기 링크 상(像): probe 목적 파일(`c_codegen.o`·`c_layout.o`·`asm_probe.o` + 외부 정의를 담은 작은 `.o`)을 실기 `ld` 로 `__TEXT` 0x100000 에 정적 링크한 실행 파일을 만들고(`kr_run.py` 경로), 그 이미지를 "원본" 으로 두고 목적 파일을 비교 → 모든 함수 **일치**여야 한다. 배치는 링크된 이미지의 심볼에서 얻는다.
- T2 변조(호스트에서 링크 상의 사본을 고침): ① 외부 `call` 변위를 다른 함수로 ② 절대 참조 가산값 +4 ③ 점프 표 한 항목을 다른 case 로 ④ 재배치 없는 바이트 1 개 ⑤ 함수 끝 절단(범위를 짧게 준 경우) — 각각 해당 함수만 **다름**(또는 경계 불일치)으로 나와야 하고 나머지는 일치.
- T3 데이터 배치 추론: `__data` 배치를 주지 않고 추론하게 했을 때 T1 과 같은 배치를 찾고 L1d 일치, 데이터 1 바이트 변조 시 L1d 다름.
- T4 원본 커널에 대한 무해 시험: 원본에서 잘라낸 바이트로 만든 가짜 목적 파일은 쓰지 않는다(재배치 정보가 없어 의미 없음). 원본 대상 실사용은 S1-C 에서.

산출: 도구, 시험 스크립트(`10_tools/reconstruction/test_l1_compare.py`), 시험 결과 `09_validation/reconstruction/l1-selftest-<date>.json`.

### 12.1 codex 교차검토 반영 (QB1, 인용 줄 `:231,234,235,238,239,242,245,248`, `macho_obj.py:93` 확인)

| 지적 | 판정 | 수정된 설계 |
|---|---|---|
| PC 상대 가산값·`symbol+offset` 무시 | ✅ | 3 을 **링커 재배치 계산의 재현**으로 바꾼다. 필드 위치 P, 목적 파일 필드값 F, 섹션 배치 차 Δ(sec)=원본주소−목적주소. 외부 절대: F+S; 외부 PC 상대: F+S−Δ(P 의 섹션); 섹션 상대 절대: F+Δ(대상 섹션); 섹션 상대 PC 상대: F+Δ(대상)−Δ(P 의 섹션); `SECTDIFF`(A−B+c): F+Δ(A 의 섹션)−Δ(B 의 섹션). S 는 원본 심볼표의 그 이름 주소. 원본 필드가 이 값과 같아야 확인. |
| 필드 폭·부호·마스크 | ✅ | length 0/1/2 → 1/2/4 바이트, 2^(8w) 나머지 산술, 필드가 섹션 안인지 검사, 마스크는 그 바이트들만. 폭 1·2 재배치를 시험 재료에 넣는다 |
| 섹션 상대 PC 상대 재배치, 섹션 서수 | ✅ | 위 공식. 섹션은 그 목적 파일의 서수로만 찾는다 |
| 별칭(같은 주소 여러 이름) | ✅ | 주소별로 이름을 묶고 모두 보존, 범위는 묶음 단위 |
| 데이터 배치 추론의 우연 일치 | ✅ | 추론 배치는 (a) 그 섹션을 가리키는 모든 참조가 같은 Δ 를 주고 (b) 섹션 바이트 전체가 L1d 로 일치할 때만 채택하고 "추론" 표시. zero-fill(`__bss`·common)은 바이트 대조가 불가하므로 그쪽 참조는 이름이 원본 심볼표에 있을 때만 확인. 함수 판정은 참조한 데이터 섹션의 L1d 결과를 물려받는다(미확인·실패면 "일치" 불가) |
| 심볼 구간은 함수 범위 증명이 아님 | ⚖️ | 판정의 기본 단위를 **배치된 섹션 전체**로 한다(모든 바이트 비교). 함수별 결과는 그 분해일 뿐이다. Ghidra `body` 가 목적 파일 함수 끝이나 섹션 끝을 넘으면 "경계 불일치" |
| 디스어셈블 경계 미검증 | ⚖️ | 재배치 없는 분기의 올바름을 디스어셈블로 판정하지 않는다. 섹션 전체 바이트가 같으면 섹션 안 상대 목적지는 같은 상대 위치다. 재배치 없이 섹션 밖을 가리키는 PC 상대 참조는 생길 수 없다(어셈블러가 재배치를 만든다)는 전제를 시험 재료로 확인한다 |
| 자기 시험의 순환성·누락 | ✅ | T1 은 실기 `ld` 가 재배치를 계산하므로 독립적이다. 기본(`-fPIC`, SECTDIFF 28 개)·커널 후보 목적 파일을 **모두** 링크해 공식 전체를 시험한다. 추가 재료: asm 으로 `call _ext+4`(가산값), `.word`/`.byte` 참조(폭 1·2), 두 `__TEXT` 섹션 사이 `call`(섹션 상대 PC 상대). 추가 변조: 동일한 데이터 블록 두 개(배치 추론이 모호하면 거부해야 함), Ghidra 식 범위를 일부러 길게 준 경우(경계 불일치) |

### 12.2 S1-B 결과 (2026-10-01)

- 도구: `10_tools/reconstruction/l1_compare.py`(링커 재배치 계산 재현, 섹션 전체 바이트 비교, 데이터 배치 추론 + L1d 확인, 별칭 묶음, 외부 범위와의 경계 비교), 시험 `test_l1_compare.py`, 결과 `09_validation/reconstruction/l1-selftest-20261001.json`.
- T1 재료: 실기 `ld -static -e _kr_leaf -segaddr __TEXT 0x100000` 로 링크한 `t1img`(실행 `s1b-t1-kernel-4`). 재배치 종류: 외부 절대(가산값 +8 포함), 외부 PC 상대(`call _kr_ext+4`), 섹션 상대 절대(점프 표 8 항목 포함), 섹션 상대 PC 상대(`__text`→`__kr_text2`), scattered VANILLA, `SECTDIFF`+`PAIR` 2 쌍. **모든 재배치에서 도구 계산값 = 실기 `ld` 결과**.
- 결과 14/14 통과: T1 다섯 목적 파일 전부 MATCH; M1 호출 대상 교체·M2 가산값 +4·M3 점프 표 항목 교체(항목 값이 서로 다름 확인)·M4 재배치 밖 바이트·M5 경계 연장이 각각 해당 함수만 DIFF/BOUNDARY; T3a `asm_reloc` `__data` 배치를 참조에서 추론·L1d 확인; M6 데이터 1 바이트 → 참조 함수 DIFF; M7 참조 하나를 어긋나게 하면 "ambiguous 2 candidates"·일치 판정 없음; M8 사용자 지정 zero-fill 배치는 MATCH_UNVERIFIED(심볼 이름으로 얻은 배치만 확인으로 인정).
- 확인한 도구 사실: `cc -static` 으로 어셈블하면 `as` 가 섹션 간 차이(`SECTDIFF`)를 만들지 못한다("Can't emit reloc"), `-static` 없이 어셈블하면 만든다. 기본(`-fPIC`) 목적 파일은 `__picsymbol_stub` 때문에 `ld -static` 이 거부한다. `-fno-common` 의 미초기화 전역은 `__DATA,__common` zero-fill **섹션**에 들어간다. `llvm-objdump` 는 링크된 이미지(원본 커널 포함)의 `LC_UNIXTHREAD` 를 읽지 못한다 — 이미지 판독은 `macho_obj.py` 만 쓴다(목적 파일 판독은 llvm 과 대조 완료).
- 한계(기록): 폭 1·2 바이트 재배치는 0x100000 배치에서 만들 수 없어 시험하지 못했다(도구는 지원, 실제로 나오면 별도 시험). ObjC 목적 파일은 런타임 심볼 없이 링크할 수 없어 T1 에 넣지 않았다 — ObjC 메타데이터 섹션(`__OBJC`) 비교는 S1-C 이후 별도 시험.

다음: S1-C 컴파일 옵션 표본 시험(원본 커널 함수 대상). 착수 전 세부 계획과 codex 검토.

## 13. S1-C 세부 계획 — 컴파일 옵션 표본 시험 (코딩 전, 2026-10-01)

목적: 원본 커널을 만든 컴파일 옵션 후보를 원본 바이트로 가린다. 결과는 "이 표본에서 이 옵션 세트가 원본과 바이트·참조가 일치했다"는 관찰이며, 커널 전체 옵션의 증명이 아니다.

표본 선택(Python, `04_ghidra/exports/x86/full-pass5/functions.json`): 분석 조각이 아니고, 몸체가 범위 하나, `status` decompiled, 메시지 없음, 이름 있음(1,509 개) 중 16–160 바이트이고 참고 `.c` 에 같은 이름의 정의가 있는 409 개에서, **원본 밖 타입·전역에 기대지 않는** 함수 12 개:
- A 순수 계산(Darwin 0.1): `yeartoday`, `hexdectodec`, `dectohexdec`(`bsd/dev/i386/rtc.c`), `locc`(`bsd/libkern/locc.c`), `skpc`(`bsd/libkern/skpc.c`), `strcpy`(`machdep/i386/libc/strcpy.c`), `strcmp`(`machdep/i386/libc/strcmp.c`).
- B 작은 구조체·매크로: `timevaladd`, `timevalsub`, `timevalfix`(`bsd/kern/kern_time.c`, `struct timeval{long;long}`), `byte_swap_shorts`, `byte_swap_ints`(`bsd/ufs/ufs/ufs_byte_order.c`, NeXT 헤더 `<architecture/byte_order.h>` 의 `NXSwapShort`/`NXSwapLong`).
- 알려진 위험: 원본 `strcpy` 는 117 바이트인데 참고 소스는 짧은 루프다 → 소스가 다를 가능성이 크다(대조군 역할).

표본 소스: 함수마다 `10_tools/reconstruction/s1c/src/<name>.c` 하나. 함수 본문은 참고 파일에서 **글자 그대로** 옮기고, 필요한 선언(`u_char`·`u_int` typedef, `struct timeval`, 반환형 선언, 헤더 include)만 덧붙인다. 파일 머리에 출처(트리·경로·revision/SHA-256)·라이선스(APSL)·덧붙인 줄 목록을 적고 `s1c/provenance.json` 에 기록. (D013: NeXTMach 는 쓰지 않음. 이 파일들의 공개 커밋 여부는 사용자 결정 전까지 보류.)

옵션 세트(7): 공통 `-arch i386 -static -fno-common -fwritable-strings -traditional-cpp`(Darwin 0.1 `conf/Makefile.i386` 에서 `cc-744.13` 이 받는 것), 최적화 {없음, `-O`, `-O2`, `-O3`} × 프레임 포인터 {기본, `-fomit-frame-pointer`} 중 {없음}+{`-O`,`-O2`,`-O3`}×{기본, omit} = 7. 순수 계산 표본은 `-nostdinc`, 바이트 스왑 표본은 시스템 헤더 허용. 의존 헤더는 `-E` 출력으로 기록.

실행: `kr_run.py` 한 번(7 세트 × 12 표본 = 84 컴파일 + 12 개 `-E`). 결정성은 S1-A 에서 확인됨.

비교: 표본 목적 파일마다 `l1_compare.py` 를 원본 커널에 대해 `--place-from-image`(함수 이름이 원본 심볼표에 있음), `--ranges` = Ghidra `body`(시작, 끝+1)로 실행. 추가 분류(Python): 차이 바이트가 Ghidra 몸체 안인지 밖(정렬 채움)인지, 목적 파일 함수 길이와 Ghidra 몸체 길이가 같은지.

판정·기록:
- 세트별 MATCH 수, 몸체 안 차이 바이트 합, 길이 일치 수를 표로(`09_validation/reconstruction/s1c-options-<date>.json`).
- 채택 규칙: 여러 표본에서 일치를 낸 세트를 **후보 1 순위**로 기록하고, 일치가 하나도 없으면 컴파일러 차이를 의심해 기록만 하고 채택하지 않는다. 세트 사이에 일치 수가 같으면 모두 남긴다.
- 원본 커널 이미지에서 `l1_compare` 가 쓰는 것: 섹션 바이트(파일 오프셋)와 외부 심볼표뿐. 원본 판독 결과(섹션 주소·크기)를 `03_original/x86/inventory/macho.json` 과 대조한 뒤 쓴다(이미지 판독은 llvm 과 대조할 수 없으므로).

### 13.1 codex 교차검토 반영 (QC1)

인용을 모두 열어 확인했다. codex 가 든 `bsd/ufs/ufs_byte_order.c` 경로는 없고 실제는 `bsd/ufs/ufs/ufs_byte_order.c`(머리에 "Copyright (c) 1998, Apple", "16 Feb 1998" 이력, 25–32 행) — 경로는 틀렸지만 내용 지적은 맞다. `rtc.c:120–124`(K&R `yeartoday`), `locc.c:62–66`(`int` 반환, K&R, `register`), `Makefile.i386:78–91`(libc `-O4`, 문자열 함수 `-O4 -funroll-all-loops`), `kern_time.c:511–529`(`timevaladd/sub` 가 `timevalfix` 호출), `l1_compare.py:193–196,225–228,250–273,276–278` 확인.

| 지적 | 판정 | 반영 |
|---|---|---|
| 참고 소스가 원본과 다른 판일 수 있어 순위를 흐림 | ✅ | **자격 게이트**: 어떤 세트에서도 몸체 안 일치가 없는 표본은 "소스 불확실"로 따로 보고하고 순위 계산에서 뺀다. 바이트 스왑 두 함수는 1998 Apple 구현이라 보조 표본으로만 둔다 |
| 덧붙인 선언이 실험을 바꿈 | ✅ | 함수 정의 전체(반환형 생략=암묵 `int`, K&R 매개변수 선언, `register`)를 그대로 옮기고, 덧붙이는 것은 typedef·구조체·include 만. 원본 파일의 include 목록을 주석으로 남긴다 |
| 구현 선택 미증명 | ✅ | 위 자격 게이트로 처리(일치가 나와야 구현이 맞다는 근거) |
| 옵션 축 누락 | ⚖️ | 근거가 있는 축을 더한다: 최적화 {`-O`,`-O2`,`-O3`,`-O4`} × 프레임 포인터 {기본, `-fomit-frame-pointer`} × {기본, `-m486`}(먼저 `cc-744.13` 이 받는지 확인), libc 계열에는 `-O4 -funroll-all-loops`(Darwin 규칙). `-fno-builtin`·strength reduction·inline 축은 이 표본에 영향이 없어 이번에는 넣지 않고 "미시험 축"으로 기록 |
| `-traditional-cpp`·`-fwritable-strings` 고정 | ⏭️ | 표본에 문자열 리터럴·`const` 가 없어 이번 결과에 영향이 없다. "미시험 축"으로 기록 |
| 단일 승자가 파일별 옵션을 숨김 | ✅ | 결과를 계열별(rtc, libkern, libc, kern_time, ufs)로 따로 보고 |
| 단독 함수로 문맥 상실 | ✅ | `kern_time.c` 의 세 함수는 원래 순서대로 한 파일로도 컴파일해 비교(단독판과 둘 다) |
| 정렬 채움이 점수를 왜곡 | ✅ | 판정을 Ghidra 몸체 범위 안 차이로 계산하고 채움 차이는 따로 센다 |
| 차이 출력 부족 | ✅ | `l1_compare.py` 가 모든 일반 바이트 차이 오프셋과 참조 차이 위치를 내보내게 고친다 |
| 12 표본은 대표성 약함 | ✅ | 결과를 "제한된 증거"로 표기, 구분되지 않는 세트는 묶어서 보고. 넓은 표본 검증은 S5 진행 중 계속 |
| 원본 이미지 판독의 독립 확인 | ✅ | `macho_obj.py` 의 원본 섹션 주소·크기·파일 오프셋, 외부 심볼 3,651 개 주소를 `03_original/x86/inventory/macho.json`·`symbols.tsv`(별도 구현 `10_tools/prepare.py` 산출)와 전수 대조. 함수 바이트는 파일 오프셋으로 직접 읽어 대조 |
| zero-fill "확인"의 의미 | ✅ | 결과에 "배치 확인(심볼)"과 "내용 확인"을 나눠 표시 |

### 13.2 S1-C 결과 (2026-10-01) — 제한된 표본의 관찰

실행 `s1c-matrix-2`(19 세트 × 13 표본 파일 = 247 컴파일 + `-E` 13, 전부 종료 0, 781 파일 게시), 채점 `10_tools/reconstruction/s1c/score.py` → `09_validation/reconstruction/s1c-options-20261001.json`. 원본 판독 확인: `macho_obj.py` 의 원본 섹션 26 개(주소·크기·파일 오프셋)와 심볼 3,751 개가 `03_original/x86/inventory/` 와 전부 같음. 일치 3 건(`_yeartoday` -O2, `_strcpy` -O4 -funroll-all-loops, `_byte_swap_ints` -O2)은 원시 바이트를 파일 오프셋으로 직접 읽어 다시 확인.

| 관찰 | 근거(몸체 안 BODY_MATCH) |
|---|---|
| **`cc-744.13`(GCC 2.7.2.1) 가 원본과 바이트가 같은 코드를 만든다** | 13 함수 중 11 개가 어떤 세트에서 몸체 전체 일치(117 바이트 `_strcpy` 포함) |
| **프레임 포인터 유지**(`-fomit-frame-pointer` 아님) | omit 세트 9 개 모두 0 일치 |
| **최적화 `-O2` 이상** | `-O` 은 9/13(바이트 스왑 2 개 불일치), `-O2`·`-O3`·`-O4` 는 11/13 — 이 표본으로는 셋을 구분할 수 없음 |
| **libc 문자열 함수는 `-O4 -funroll-all-loops`** | `_strcpy`·`_strcmp` 는 그 세트(s17)에서만 일치 — Darwin 0.1 `conf/Makefile.i386:78–91` 의 libc 규칙과 같다. 계열별(파일별) 옵션이 실제로 있다 |
| `-m486`/`-mno-486` 구분 불가 | 모든 쌍에서 같은 결과(S1-C 옵션 수용 시험에서도 같은 목적 파일) |
| `timevaladd`·`timevalsub`·`timevalfix` 는 원본에서 이 순서로 붙어 있다 | 세 함수를 한 파일로 컴파일한 목적 파일이 하나의 배치로 세 이름에 모두 맞고 일치 |
| 1998 Apple 판 `ufs_byte_order.c` 의 두 함수가 원본과 같다 | `-O2` 이상에서 일치 |
| 소스 불확실 | `_locc`·`_skpc`: 어떤 세트에서도 몸체 차이 6–7 바이트 이상 → 참고 소스가 원본과 다르거나 다른 옵션. 순위 계산에서 제외 |

미시험 축(기록): `-fno-builtin`, strength reduction, inline 계열, `-traditional-cpp`, `-fwritable-strings`. `-O2`/`-O3`/`-O4` 를 구분할 표본(인라인 가능한 정적 함수가 앞에 정의된 것 등)이 필요하다.

판정: 커널 C 파일의 **후보 1 순위 옵션** = `-arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O2`(또는 -O3/-O4, 미구분), 프레임 포인터 유지. libc 계열은 `-O4 -funroll-all-loops`. 표본 12 개의 제한된 증거이며, S5 진행 중 함수 대조로 계속 검증한다.

### 13.3 S1-C2 결정 (2026-10-01): `-O2`/`-O3`/`-O4` 구분을 S5 로 미룸

Darwin 0.1 에서 "작은 static 함수가 먼저 정의되고 원본에 깨끗한 경계로 있는 함수가 그것을 부르는" 쌍을 Python 으로 찾은 결과 8 쌍뿐이고, 판별 재료가 되지 못했다: `page_copy`·`suibyte` 의 도우미는 `__inline__`/`inline` 이 명시돼 `-O2` 에서도 인라인되고, `nb_alloc` 은 `nb_alloc_free` 를 함수 포인터로 넘길 뿐 호출하지 않으며, `ttywflush` 는 원본에 이름이 있는 외부 함수다. 표본을 억지로 만들지 않고, S5 에서 실제 파일을 `-O2` 와 `-O3` 로 함께 컴파일해 파일별로 판정한다(파일별 옵션이 있음은 13.2 에서 확인).

## 14. S1-D 세부 계획 — Objective-C 목적 파일 대조 (코딩 전, 2026-10-01)

확인한 사실: probe `objc_probe.o`(`s1a-probes-kernel-2`)와 원본 커널 모두 `__OBJC` 의 `__class_names`·`__meth_var_types`·`__meth_var_names` 가 섹션 종류 `cstring_literals`(2), `__message_refs`·`__cls_refs` 가 `literal_pointers`(5), 나머지는 regular(0). 리터럴 섹션은 링커가 모듈 사이에서 같은 내용을 합칠 수 있으므로, 한 목적 파일의 해당 섹션이 원본에서 한 덩어리로 있다는 가정(현재 배치 방식)이 성립하지 않는다.

도구 확장(`l1_compare.py`):
1. 리터럴 섹션은 섹션 배치를 하지 않는다(배치·L1d 대상에서 뺀다).
2. 리터럴 섹션을 가리키는 참조는 **내용으로** 확인한다:
   - `cstring_literals`: 목적 파일에서 가리키는 위치의 NUL 종결 문자열(가산값이 문자열 중간이면 그 오프셋부터)과, 원본 필드값이 가리키는 위치의 문자열이 같고, 그 위치가 원본의 **같은 이름 섹션** 안이어야 확인.
   - `literal_pointers`: 목적 파일 항목(4 바이트)이 가리키는 문자열과, 원본 필드가 가리키는 원본 같은 이름 섹션 항목이 가리키는 문자열이 같아야 확인(한 단계 역참조).
   - PC 상대·`SECTDIFF` 가 리터럴 섹션을 가리키면 지원하지 않음(오류)으로 둔다 — 실제로 나오는지 시험에서 본다.
3. 리터럴 섹션 안의 재배치(리터럴 포인터 항목의 문자열 참조)는 2 의 역참조 규칙으로만 쓴다.
4. 메서드 함수: ObjC 메서드는 목적 파일에서 로컬 심볼(`-[Class sel]`)이고 원본에는 이름이 없다. `__text` 배치는 원본 ObjC 메타데이터(`03_original/x86/inventory/objc.json` 의 메서드 IMP 주소)와 목적 파일 메서드 심볼을 같은 (클래스, 셀렉터) 로 짝지어 Δ 를 구하고, 모든 짝이 같은 Δ 를 줄 때만 쓴다.
5. regular `__OBJC` 섹션(`__class`, `__meta_class`, `__inst_meth`, `__cls_meth`, `__category`, `__instance_vars`, `__module_info`, `__symbols` …)은 기존 방식(참조에서 배치 추론 + 바이트 전체 L1d)으로 대조한다.

자기 시험(T-ObjC, 실기 `ld` 링크):
- 재료: 같은 셀렉터·클래스 이름 문자열을 공유하는 ObjC 파일 두 개(합쳐짐을 강제) + 런타임 대용 정의(`_objc_msgSend`, `.objc_class_name_Object` 등, 어셈블리)를 `ld -static -segaddr __TEXT 0x100000` 로 링크.
- 확인: 두 목적 파일 모두 메서드·regular `__OBJC` 섹션이 MATCH, 리터럴 참조가 내용으로 확인됨. 실제로 합쳐졌는지(두 번째 파일의 문자열이 첫 번째 파일 쪽 주소를 가리키는지)를 이미지에서 확인해 시험이 의미 있음을 보인다.
- 변조: 원본 사본에서 ① 셀렉터 참조 하나를 다른 셀렉터 문자열로 ② `__class` 의 인스턴스 크기 필드 ③ 메서드 목록의 IMP 하나를 다른 메서드로 — 각각 해당 항목 DIFF.
- 원본 대상 시범은 S5 에서(작은 ObjC 모듈 하나).

### 14.1 codex 교차검토 반영 (QD1)

인용 확인: 계획 349–357 행, `l1_compare.py:199,254`, `objc.json:2`(바이너리 해시), `:704`(`isa` 0x1fa71c), `:1999`(categories), `:2205`(selector), `:12436`(missing_ghidra_method_entries). Python 으로 `objc.json` 구조 확인: 메서드 키 `owner, kind, selector, types, imp, metadata_address, list_address`; 첫 클래스 `KernLock` 의 `isa` 0x1fa71c(= `__meta_class` 시작), `superclass` 0x1fdfdf(`__class_names` 안 = 문자열 포인터). 파일 상태에서 isa 는 포인터, superclass 는 이름 문자열이다.

| 지적 | 판정 | 반영 |
|---|---|---|
| 리터럴 포인터의 두 단계 모두 섹션 확인 필요 | ✅ | 슬롯이 원본의 같은 이름 `literal_pointers` 섹션 안, 슬롯이 가리키는 문자열이 같은 이름 `cstring_literals` 섹션 안, 문자열은 섹션 끝 안에서 NUL 로 끝나야 함 |
| 합쳐짐 시험이 슬롯 공유·`__cls_refs` 를 안 다룸 | ✅ | 재료에 두 파일이 같은 셀렉터를 보내는 코드(슬롯 공유 확인), 다른 클래스를 이름으로 참조하는 코드(`__cls_refs`)를 넣고, 이미지에서 실제 공유 관계를 확인 |
| 함수 MATCH 가 메타데이터를 보증하지 않음 | ✅ | **목적 파일 판정**을 추가: regular `__OBJC` 섹션 전부 L1d 일치 + 그 안 모든 참조 확인(리터럴은 내용) + 메서드 대응 완전 → OBJECT_MATCH |
| 메서드 식별 불충분 | ✅ | 대응 키 = (소유 클래스, 카테고리 이름 또는 없음, 인스턴스/클래스, 셀렉터). 목적 파일 메서드 전부가 원본에 하나씩 대응해야 함(빠짐·중복이면 배치 거부) |
| IMP 목록 정확성 가정 | ✅ | `objc.json` 의 메서드 1,137 개를 원본 바이트로 재확인: 각 `metadata_address` 의 세 워드가 (셀렉터 문자열 포인터, 형식 문자열 포인터, IMP) 이고 문자열이 일치하는지, 메서드 목록 개수와 항목 수 합이 맞는지 — 불일치하면 해당 메서드는 배치 근거로 쓰지 않음 |
| `ld` 의 regular 섹션 변형 가정 | ✅ | T-ObjC 에서 실제 링크 결과로 변형(정렬 등) 유무를 먼저 확인하고, 변형이 있으면 도구에 반영하기 전에 기록·재계획 |
| 클래스 필드 표현 미시험 | ✅ | 재료에 지역 클래스의 하위 클래스를 넣어 isa(포인터)·superclass(이름 문자열) 표현을 이미지 바이트로 확인하고 각각의 규칙(포인터는 배치, 문자열은 내용)으로 대조 |
| 자기 시험 범위 부족 | ✅ | 확장별 양성·음성 시험 표: 리터럴 문자열 참조, 리터럴 포인터 참조, 슬롯 공유, cls_refs, isa, superclass 문자열, 메서드 목록 IMP, 인스턴스 크기, 카테고리, 모듈 정보. 리터럴을 가리키는 PC 상대·SECTDIFF 는 만들 수 있는지 시도하고, 못 만들면 "생성 불가"로 기록 |

### 14.2 S1-D 결과 (2026-10-01)

- **원본 ObjC 목록 재확인**: `objc.json` 메서드 1,137 개 전부가 원본 바이트와 일치(메타데이터 주소의 세 워드 = 셀렉터·형식 문자열 포인터·IMP, 문자열은 올바른 섹션 안에서 NUL 종결, IMP 는 `__text` 안, 목록 120 개의 개수·순번 일치) → `09_validation/reconstruction/objc-inventory-recheck-20261001.json`. 독립 판독기 `10_tools/reconstruction/objc_meta.py`(모듈→symtab→클래스·카테고리→메서드 목록)도 원본에서 메서드 1,137 개(목록 주소까지)·클래스 59(= 인벤토리 118 의 클래스+메타클래스)·카테고리 40 으로 인벤토리와 동일. 원본의 모듈 이름 76 개·클래스 이름은 모두 유일.
- **T-ObjC 링크 관찰**(`s1d-tobjc-1`, 실기 `ld`): 리터럴이 실제로 합쳐진다(`__message_refs` 24→20 B: 두 파일의 셀렉터 `x` 슬롯 공유, `__class_names` 75→61, `__meth_var_types` 40→32, `__meth_var_names` 62→55). regular `__OBJC` 섹션은 크기가 두 목적 파일의 합이고 입력 순서대로 이어 붙는다(정렬·재배열 없음). `__text` 는 목적 파일 사이 정렬 채움으로 164→168 B. 클래스 레코드: isa = 메타클래스 레코드 포인터, superclass·name = `__class_names` 문자열; 메타클래스 isa = 루트 클래스 이름 문자열.
- **도구 확장**: 리터럴 섹션(`cstring_literals`·`literal_pointers`)은 배치하지 않고 참조를 내용으로 확인(리터럴 포인터는 두 단계 모두 같은 이름 섹션 확인), 리터럴을 가리키는 PC 상대·좁은 폭·SECTDIFF 는 "미지원"으로 미확인 처리. 메서드 심볼(`-[Class(Cat) sel]`)과 이미지 메타데이터의 (소유, 카테고리, 종류, 셀렉터) 완전 대응으로 `__text` 배치. `objc_place.py` 가 모듈·symtab·클래스·메타클래스·인스턴스 변수·메서드 목록·카테고리 레코드 대응으로 regular 섹션 배치(섹션마다 Δ 하나일 때만) → L1d 로 전 바이트·참조 확인. 목적 파일 판정 `OBJECT_MATCH`.
- **시험 13/13** (`test_objc_compare.py` → `09_validation/reconstruction/objc-selftest-20261001.json`): 두 목적 파일 OBJECT_MATCH(메서드 6 개 MATCH), 합쳐짐 3 종 확인; 변조 8 종(셀렉터 슬롯, 인스턴스 크기, IMP, superclass 문자열, `cls_refs` 슬롯, 형식 문자열 1 바이트, 카테고리 이름, 모듈 크기) 모두 NOT_MATCH 이고 사유가 해당 섹션·참조(예: N3 `__inst_meth` 참조 차이 + 메서드 대응 불완전). 기존 L1 시험 14/14 유지.
- 한계: 리터럴을 가리키는 PC 상대·SECTDIFF 는 만들지 못해 시험하지 않음. 프로토콜(`__protocol`)·클래스 변수(`__class_vars`)·`__sel_fixup` 이 있는 목적 파일은 아직 대응 규칙이 없다(나오면 "미배치"로 남아 OBJECT_MATCH 불가). big-endian(SPARC·m68k) 재배치 판독은 미구현(`macho_obj.py` 가 오류).

S1 종료 상태: 툴체인·빌드 왕복·L1/L1d/ObjC 비교 도구·옵션 후보 확보. `-O2`/`-O3` 구분은 S5 로 이월(13.3). 다음은 S2(계보·구성 지도).

## 15. S2-A 세부 계획 — 목적 파일 경계와 링크 순서 (코딩 전, 2026-10-01)

전제(관찰, S1-D 14.2): `ld` 는 목적 파일의 regular 섹션(`__text`, `__data`, `__OBJC` regular)을 입력 순서대로 이어 붙이고 목적 파일 사이에 정렬 채움을 넣는다. 커널 C 는 `-fwritable-strings` 로 빌드되는 것이 후보 1 순위(13.2)라 문자열 리터럴이 목적 파일마다 `__data` 에 들어간다(합쳐지지 않음) — 이것은 S2-A 에서 확인할 가설이다.

실현성 추정(Python, 2026-10-01): 분석 조각이 아닌 Ghidra 함수 4,761 개 중 원본 외부 심볼 이름이 있는 것 2,907, 없는 것 1,854(ObjC 메서드 1,137 포함). 이름 있는 함수 중 Darwin 0.1(ppc 경로 제외)의 `.c`/`.m`/`.s` 에 정의가 정확히 한 파일인 것 1,217, 여러 파일 6, 없음 1,684. 정의 파일이 하나인 함수만으로 주소 순 연속 구간 204 개, 파일 189 개, 둘 이상 구간으로 쪼개진 파일 14 개.

증거와 단계(`10_tools/reconstruction/s2a_objects.py`, 모두 Python):
1. **이름 표지**: 원본 외부 심볼 함수마다 정의 파일 후보를 Darwin 0.1 → NeXTMach → Mach4 순으로 찾는다(정의 줄 정규식, 어셈블리는 `ENTRY(x)`/`_x:`). 파일이 여럿이면 "모호". 이름 일치는 후보다.
2. **ObjC 표지**: `objc_meta.py` 로 메서드 IMP → 소유 클래스 → 모듈 이름(원본 76 개, 유일). 메서드 IMP 의 주소 범위로 모듈별 `__text` 구간을 얻는다. 모듈 이름은 원본 바이트에서 온 사실이다.
3. **구간 만들기**: 주소 순으로 같은 표지가 이어지는 구간을 만들고, 이름 없는 함수(정적 함수)는 양쪽 표지가 같을 때만 그 구간에 넣는다. 양쪽이 다르면 경계는 그 사이 어딘가로 "범위"(최소·최대)만 기록한다.
4. **데이터 단조성 교차 확인**: Ghidra `references.tsv` 의 `__text`→`__data` 참조(READ·WRITE·READ_WRITE·DATA)로 구간마다 참조하는 `__data` 주소의 최소·최대를 구한다. 구간을 `__text` 순서로 늘어놓았을 때 `__data` 범위도 같은 순서여야 한다(겹침·역전은 잘못 붙인 표지나 쪼개진 파일의 신호로 보고). 참조 자료는 Ghidra 해석이므로, 무작위 표본 200 개를 capstone 디코딩(명령의 절대 주소 피연산자)으로 재확인한 뒤 쓴다.
5. **문자열 가설 확인**: `__data` 안에서 함수가 문자열로 참조하는 위치가 같은 구간의 다른 데이터와 붙어 있는지(목적 파일별 데이터 덩어리) 표본으로 확인 — 맞으면 4 의 근거가 강해지고, 아니면 4 는 참고로만 쓴다.
6. **Darwin 빌드 목록과 대조**(진단): `conf/files`·`files.i386` 의 파일 순서와 복원한 순서를 비교해 일치 구간을 보고한다(참고 코드 사실이므로 판정에 쓰지 않음).

산출: `06_reconstruction/objects.tsv`(목적 파일 후보: 순번, 소스 후보, `__text` 시작·끝의 확정값 또는 범위, 함수 수·바이트 수, 근거 종류, 신뢰도, 데이터 범위, 모순), 보고서 `09_validation/reconstruction/s2a-objects-<date>.json`(분모: `__text` 851,436 B 중 구간에 배정된 바이트, 배정 못 한 바이트 목록). 이 단계는 원본 분석이며 코드 복원이 아니다.

### 15.1 codex 교차검토 반영 (QS2A, 인용 380·389·394–398·401 행 확인)

| 지적 | 판정 | 반영 |
|---|---|---|
| 이름이 소유 파일을 정하지 못함 | ✅ | 후보 파일을 모두(트리·경로) 보존, 하나로 좁히지 않는다. 소유 확정은 S5 의 L1 대조로만 |
| 같은 표지 사이 정적 함수의 배정 | ✅ | "추정 소속"으로만 표시. 표지가 전혀 없는 목적 파일 가능성을 열어 둔다(구간 사이 미배정 바이트로 보고) |
| 어셈블리 객체의 진입점 | ✅ | `.s` 후보는 모든 진입점·별칭을 묶은 후보로만 두고, 확정은 조립된 기여 전체의 대조(S5)로 |
| ObjC 메서드 범위 ≠ 객체 범위 | ✅ | 같은 `.m` 의 C 함수 표지(파일 기본 이름)와 메서드 표지를 한 후보로 합친 뒤 범위를 낸다 |
| 참조한 데이터 ≠ 소유 데이터 | ✅ | 단조성 확인에는 원본 외부 심볼 주소가 아닌 `__data` 대상(익명 데이터: 문자열·정적 변수)만 쓰고, 데이터가 없는 후보를 허용 |
| 섹션 간 순서 동일 가정 | ✅ | `__text` 순서와 `__data` 순서를 따로 내고, 둘의 일치는 "관찰"로만 보고 |
| 표본 검증으로는 부족 | ✅ | 결과에 쓰는 참조는 **전부** capstone 으로 원본 명령을 디코딩해 절대 주소 피연산자(즉시값·변위)가 대상과 같은지 확인, 안 맞으면 버린다 |
| 문자열 인접성은 진단 | ✅ | 진단으로만 |
| "확정" 규칙 없음 | ✅ | S2-A 는 확정 경계를 내지 않는다. 신뢰도: **B** 표지 있는 이웃으로 범위가 좁혀지고 데이터 단조성과 모순 없음, **C** 이름 표지만, **U** 미배정. **A**(바이트 확정)는 S5 의 L1 일치로만 부여 |

### 15.2 S2-A 결과 (2026-10-01) — 후보 지도(확정 아님)

도구 `10_tools/reconstruction/s2a_objects.py` → `06_reconstruction/objects.tsv`, `09_validation/reconstruction/s2a-objects-20261001.json`.
- 함수 4,761 개 분류: 이름 표지(참고 트리에 정의 있음) 1,783, 이름 있으나 참고 정의 없음 1,124, ObjC 메서드 1,137(모듈 이름은 원본 바이트), 표지 없음 717.
- 후보 구간 339 개: 신뢰도 B 235(69.3 %, Python), C 104. 둘 이상 구간으로 나뉜 파일 이름 16(`machdep.c`·`pcb.c` 처럼 트리 사이 같은 이름, 또는 쪼개진 파일 — 미해결로 남김).
- 바이트(`__text` 851,436 B 기준): 함수 몸체 822,140 B(96.6 %) 중 표지 있음 508,158(59.7 %), 구간 안 추정 소속 61,574(7.2 %), 미배정 252,408(29.6 %).
- 참조 검증: `__text`→`__data` 후보 4,785 중 외부 심볼 주소 1,323 제외, capstone 디코딩으로 피연산자(즉시값·변위)가 대상과 같은 것 2,525 채택, 937 거부(880 은 명령 피연산자에 그 주소가 없음 — Ghidra 의 자료흐름 추론, 57 은 배열 인덱스처럼 다른 주소). 구간에 쓰인 것 1,295.
- 데이터 순서 진단: 범위(최소·최대) 기준 모순 16 건(28 구간; 대부분 `__data` 끝쪽의 다른 파일 표 원소 참조, 예: `tty.c`), 중앙값 기준 인접 역전 9/162(일치 94.4 %) → `__text` 와 `__data` 기여 순서가 대체로 같다는 관찰.
- Darwin 0.1 `conf/files`+`files.i386` 순서와의 진단: 위치를 찾은 구간 212 중 최장 증가 부분열 152(71.7 %) — 링크 순서가 비슷하지만 같지 않다.
- 해석 경계: 이 지도는 후보다. 경계 확정(A)은 S5 에서 목적 파일 L1 일치로만 준다. "이름 있으나 참고 정의 없음" 1,124 와 "표지 없음" 717 이 S2-B(함수 대응)와 S5 의 주요 미지수다.

## 16. S2-B 세부 계획 — 함수 단위 후보 대응 (코딩 전, 2026-10-01)

산출 위치: 자동 생성물은 `06_reconstruction/function_candidates.tsv`(새 파일). `06_reconstruction/functions.tsv` 는 README 의 취지(원시 심볼을 일괄 등록하지 않음)대로 대조·구현을 거친 항목만 둔다. 어휘는 README 를 따른다: 상태 `unmapped`/`candidate`(이 단계의 최대), 신뢰도 `low`/`medium`/`high`, 상충은 `conflicting`. 후보 출처에는 트리·고정 revision(Mach4 `69fa778`, NeXTMach `f6bdb9c`, Darwin `kernel-1.tar.gz` SHA-256 `0c19349b…`, `driverkit-139.1-1.tar.gz` `25523562…`)·경로·함수 이름을 적는다.

원본 쪽 특징(모두 원본 바이트로 검증, `10_tools/reconstruction/s2b_candidates.py`):
- F1 이름: 원본 외부 심볼 이름(없으면 없음).
- F2 직접 호출: Ghidra `references.tsv` 의 `UNCONDITIONAL_CALL` 중 출발점이 함수 몸체 안이고, capstone 디코딩한 명령이 `call` 이며 목적지가 대상과 같은 것만. 목적지가 원본 외부 텍스트 심볼이면 그 이름.
- F3 문자열: 몸체 안에서 `__data`·`__cstring`·`__const` 를 가리키는 참조 중 디코딩으로 피연산자(즉시값·변위)가 대상과 같은 것만, 대상에서 NUL 까지 읽어 3 자 이상·인쇄 가능 문자 비율 0.9 이상인 문자열.

후보 쪽 특징(참고 소스 텍스트, ppc 경로 제외):
- 함수 정의(정의 줄~첫 `}` 줄), 본문에서 호출한 식별자(`이름(`, C 키워드 제외), 문자열 리터럴(C 이스케이프 해석).

후보 생성과 점수:
- 이름 있는 원본 함수: 같은 이름의 정의 전부가 후보. 호출 일치도 Jc = |원본 호출 이름 ∩ 후보 호출 식별자| / |합집합| (둘 다 원본 외부 텍스트 이름으로 한정), 문자열 일치 수 Ks / 원본 문자열 수.
- 이름 없는 원본 함수: S2-A 구간에 속하면 그 구간 후보 파일의 정적 함수(이름 일치로 이미 쓰인 것 제외)를 후보로, 같은 점수. 구간 밖이면 후보 없음.
- 신뢰도: **high** = 최고 후보가 Jc ≥ 0.5(양쪽 호출 집합이 비어 있지 않을 때) 또는 원본 문자열 전부 일치, 그리고 2 위 후보보다 점수가 높음(같은 본문의 다른 트리 사본은 묶어서 하나로 봄). **medium** = 이름 일치 + 부분 증거(Jc > 0 또는 문자열 ≥ 1), 또는 이름 없는 함수의 유일한 최고 점수 후보. **low** = 이름만(증거를 낼 특징이 없거나 겹침 0). 최고 점수가 서로 다른 본문 둘 이상이면 **conflicting**.
- 같은 함수의 여러 트리 사본은 본문 텍스트를 정규화(공백·주석 제거)해 같으면 "같은 본문"으로 묶는다.

점수기 검증(쓰기 전):
- 정답이 있는 표본: S1-C 에서 바이트 일치한 함수 11 개(Darwin 파일이 정답) — 후보 1 순위가 그 파일이어야 함.
- ObjC 메서드: 원본 바이트로 아는 모듈 이름(파일)이 정답 — Darwin `.m` 의 `@implementation Class` 안 메서드 정의를 (클래스, 셀렉터)로 찾아 후보 파일 기본 이름과 모듈 이름이 같은 비율을 Python 으로 보고(점수기의 문자열·호출 특징이 ObjC 메서드에도 작동하는지 확인용, 메서드 행은 이 방식으로 후보를 만든다).
- 무작위 50 개 함수의 F2·F3 를 사람이 읽을 수 있는 표로 뽑아 디코딩 결과와 함께 남긴다.

결과는 후보이며, `compared` 이상은 S5 에서 L1 대조로만 올린다.

### 16.1 codex 교차검토 반영 (QS2B) — 설계 변경

인용 확인: 계획 282–284·310·421·430·434–449 행, `06_reconstruction/README.md:10–12`. 작은 집합 예 `{panic}` 대 `{panic}` 의 Jc = 1.0 을 Python 으로 확인. 지적 10 건 모두 ✅.

변경된 설계:
- **S2-B 의 신뢰도 최대값은 `medium`**. 전처리 전 텍스트 특징은 매크로·인라인·조건부 정의 때문에 원본과 직접 비교할 수 없다. `high` 는 S5 에서 컴파일한 번역 단위의 L1 대조 뒤에만 준다(그때 상태도 `compared`).
- **출처 대안 보존**: 같은 본문의 다른 트리 사본도 하나로 합치지 않고 모두 나열(정규화 본문 해시로 "같은 본문 묶음" 표시만).
- **판별력 가중치**: 원본 함수 집합에서 특징(호출 이름·문자열)의 문서 빈도 df 로 가중치 w = ln(N/df), N = 원본 함수 수. 점수 = 원본과 후보가 공유한 특징의 w 합. 문턱 τ = ln(N/5)(5 개 이하 함수에만 나오는 특징 하나와 같은 무게). 원본 특징의 w 합이 τ 미만이면 판별 불가로 `low`.
- **결정 규칙**: `medium` = (이름 일치 또는 이름 없는 경우) 최고 후보 점수 ≥ τ 이고 다른 본문 묶음의 차점보다 τ/2 이상 높음. 그 밖은 `low`. 최고 점수가 τ 이상이고 차점과의 차가 τ/2 미만인 서로 다른 본문 둘 이상 → 처분 `conflicting`. 후보가 없으면 신뢰도 `unknown`.
- **필드 분리**: 상태(`unmapped`/`candidate`), 신뢰도(`unknown`/`low`/`medium`), 처분(`single`/`identical-bodies`/`conflicting`)을 별도 열로.
- **미해결 간선 기록**: 함수 몸체의 꼬리 `jmp`(다른 함수 시작으로), 간접 호출, 이름 없는 대상 호출 수를 기록하고, 이것이 있으면 호출 특징만으로는 `medium` 을 주지 않는다(문자열 증거 필요).
- **이름 없는 함수 후보**: S2-A 구간과 앞뒤 이웃 구간 후보 파일의 정적 함수를 모두 후보로(이미 이름으로 쓰인 것도 제외하지 않음).
- **문자열**: 원본 문자열은 3 자 이상·인쇄 가능, 가중치로 흔한 형식 문자열의 무게를 낮춘다. `__FILE__` 등 전처리로 생기는 문자열은 텍스트 후보에 없으므로 일치하지 않아도 감점하지 않는다.
- **검증**: ① S1-C 일치 11 함수는 정답 Darwin 파일이 최고 후보 묶음에 있어야 함(증거가 없으면 `low` 여야 함) ② **음성 시험**: 이름 있는 함수마다 후보를 무작위의 다른 함수 정의로 바꿔 점수를 내면 `medium` 비율이 2 % 이하여야 함 ③ "항상 medium" 변형을 넣으면 ② 가 실패해야 함(시험이 작동함을 보임) ④ 무작위 50 함수의 F2·F3 를 디코딩 결과와 함께 표로 남김. ObjC 파일 이름 대조는 검증에서 뺀다(파일 이름은 힌트일 뿐).

### 16.2 S2-B 결과와 S2-A 재실행 (2026-10-01)

- **파서 결함 발견·수정**: S2-B 표본 검토에서 `_vm_map_protect` 의 후보가 없었다. 원인은 정의 줄 정규식이 `kern_return_t vm_map_protect(` 처럼 반환형이 같은 줄에 있는 정의와 K&R 선언 사이 주석(`struct vop_lookup_args /* { … } */ *ap;`)을 놓친 것. 공용 정의 탐지기 `10_tools/reconstruction/srcdefs.py`(괄호 균형 → `;` 이면 프로토타입, 주석을 걷은 K&R 선언 뒤 `{` 이면 정의, 본문은 0 열 `}` 까지)로 바꿔 S2-A·S2-B 를 다시 돌렸다. Darwin 커널(ppc 제외)에서 정의 3,947 → 5,102; 옛 정규식에만 잡힌 이름 153(상당수 `LIST_HEAD`·`int` 같은 오검출, 나머지는 닫는 `}` 가 0 열이 아닌 HFS 등 — 한계로 기록).
- **S2-A 갱신**(15.2 대체, `06_reconstruction/objects.tsv`): 함수 분류 이름 표지 2,359 / 참고 정의 없음 548 / ObjC 1,137 / 표지 없음 717. 구간 362(B 265 = 73.2 %). 바이트 표지 612,938(72.0 %), 구간 안 추정 45,074(5.3 %), 미배정 164,128(19.3 %). 데이터 범위 모순 20 건, 중앙값 인접 역전 10/186(일치 94.6 %). `conf/files` 최장 증가 부분열 174/226(77.0 %).
- **S2-B**(`06_reconstruction/function_candidates.tsv`, 13 열·4,761 행, 형식 검사 통과; `09_validation/reconstruction/s2b-candidates-20261001.json`): 신뢰도 medium 1,136(23.9 %), low 2,721(57.2 %), unknown 904(19.0 %), 처분 conflicting 445. 종류별: 이름 있음 medium 818 / low 1,516 / unknown 573, ObjC medium 158 / low 648 / unknown 331, 이름 없음 medium 160 / low 557.
- **검증**(`09_validation/reconstruction/s2b-validation-20261001.json`): ① S1-C 바이트 일치 10 함수 모두 정답 Darwin 파일이 최고 후보 묶음(특징 없는 잎 함수는 low, 호출 특징이 있는 `timevaladd/sub` 는 medium) ② 무작위 다른 정의로 바꾼 음성 시험 medium 2/2,334 = 0.09 %(기준 2 % 이하) ③ "항상 medium" 변형은 100 % 로 ② 가 이를 잡음 ④ 무작위 50 함수 표 `s2b-sample50-20261001.tsv`.
- TSV 출력에서 문자열의 줄바꿈이 행을 깨뜨리는 결함을 발견해 탭·줄바꿈·역슬래시를 이스케이프하도록 고쳤다(재생성 후 형식 오류 0).

다음: S5 착수 준비 — 서브시스템 우선순위(S2 결과 기반)와 첫 시범 파일 선정. 착수 전 세부 계획·codex 검토.

## 17. S5-P1 세부 계획 — 첫 시범 파일 `memcmp.c` (코딩 전, 2026-10-01)

선정 근거(Python, S2-A·S2-B 산출): 신뢰도 B 단일 파일 구간이면서 그 파일의 정의가 다른 구간에 없고, 전이적 헤더 집합이 가장 작은 파일. `darwin01/kernel/machdep/i386/libc/memcmp.c`(SHA-256 `90baa677…`, APSL 1.0 머리말 포함)는 헤더 0, 정의 4(외부 `bcmp`·`memcmp`, `static inline` 도우미 2), 원본 구간 seq 1 = `_bcmp` 0x1012fc(40 B)·`_memcmp` 0x101324(164 B, 몸체 두 범위). 앞 구간(seq 0 `memchr.c`) 끝 0x1012f9, 뒤 구간(seq 2) 시작 0x1013cc.

절차:
1. 소스: 파일을 **바이트 그대로** `07_kernel/src/arch/x86/libc/memcmp.c` 에 둔다(APSL 머리말 유지). `07_kernel/PROVENANCE.tsv` 에 출처(`darwin01`, `kernel-1.tar.gz` SHA-256, 원 경로, 파일 SHA-256), 라이선스 `APSL 1.0 (01_resources/upstream/darwin01/architecture/APPLE_LICENSE)`, 변경 `none` 기록. 라이선스 원문 사본을 `07_kernel/LICENSES/APSL-1.0.txt` 로 둔다(원문 해시 기록).
2. 옵션: Darwin `conf/Makefile.i386` 의 libc 규칙(`LIBC_SRC` 에 memcmp.c, `-O4`)과 13.2 의 후보 1 순위 공통 옵션: `-arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4`. 대조군으로 `-O2`(13.2 에서 `-O2`~`-O4` 미구분)와 `-O4 -funroll-all-loops` 도 함께 빌드. 실제로 쓰인 전처리 정의는 `-E` 로 기록(`NX_CURRENT_COMPILER_RELEASE` 가 410 이면 `SIREG "S"`).
3. 빌드: `kr_run.py`(빌드 절차 규약 11.1) — 입력은 `07_kernel/src/arch/x86/libc/` 의 스냅샷.
4. 대조: `l1_compare.py --place-from-image`(이름 `_bcmp`·`_memcmp` 로 배치) + `--ranges`(Ghidra 몸체). 판정 기준: 목적 파일의 `__text` 전체 바이트·참조가 원본과 같고(`object_verdict` OBJECT_MATCH), 두 함수 MATCH.
5. **경계 증명서**(15.1 의 A 등급 규칙): (a) 배치 시작 = 원본 `_bcmp` 주소, 목적 파일 `__text` 전체 바이트 일치 (b) 목적 파일 `__text` 크기만큼 끝 주소를 계산하고, 그 뒤 원본 바이트가 다음 구간 시작 0x1013cc 까지 정렬 채움(목적 파일의 정렬 지수에서 계산한 개수 미만)인지 (c) 앞 구간 끝 0x1012f9 와 0x1012fc 사이도 정렬 채움 크기 범위인지. 셋 다 맞으면 이 목적 파일 경계를 **A**(바이트 확정)로, `bcmp`·`memcmp` 를 `06_reconstruction/functions.tsv` 에 상태 `compared`·신뢰도 `high` 로 올린다(근거 파일 `06_reconstruction/evidence/x86-memcmp.md`).
6. 실패 시: 옵션 대조군 결과와 차이 위치를 기록하고, 원인(소스 판·옵션·인라인)을 가린 뒤 다시 계획한다. 소스를 원본에 맞게 고치는 일은 이 시범에서 하지 않는다.

이후 S5-P2: `machdep/i386/kern_machdep.c`(헤더 25 개, 미해결 `i386/ansi.h`) 로 헤더 환경 구성 — 별도 세부 계획.

### 17.1 codex 교차검토 반영 (QP1)

인용 확인: 계획 484·487·488 행, `objects.tsv` 2·4 행(seq 0 `memchr.c`, seq 2 bcopy 무리), README 12 행(신뢰도와 검증 상태 독립), `memcmp.c` 68·85 행(`static inline` 도우미 두 개), `PROVENANCE.tsv` 1 행(열: destination, source_id, revision_or_sha256, original_path, license_reference, changes, evidence). 6 건 모두 ✅.

- **채움 바이트**: 앞뒤 틈의 원본 바이트 값과 길이를 기록하고, 길이가 "다음 기여의 입력 정렬(목적 파일 섹션 정렬 지수)에 맞추는 데 필요한 최소 바이트 수"와 같은지 Python 으로 확인. 채움 값은 관찰값으로 기록(링커 동작은 T1 이미지 `s1b-t1-kernel-4` 의 목적 파일 사이 틈과 비교).
- **등급 범위**: A 는 **이 목적 파일의 기여 범위**에만 준다. 이웃 구간(seq 0, seq 2)의 등급은 바꾸지 않는다.
- **`compared`/`high` 의 뜻**: "이 후보 소스를 이 옵션으로 빌드한 결과가 원본 바이트·참조를 재현한다"는 강한 증거. 역사적 원 소스의 동일성과 실행 검증은 미결로 남긴다고 근거 파일과 README 에 적는다.
- **인라인 도우미**: 근거 파일에 `simple_fwd_char_cmp`·`simple_fwd_int_cmp` 가 독립 기호 없이 `memcmp` 안으로 인라인됐음(목적 파일 심볼 목록으로 확인)을 적고, 원본 함수 행을 새로 만들지 않는다.
- **PROVENANCE 열 매핑**: destination `07_kernel/src/arch/x86/libc/memcmp.c`, source_id `darwin01`, revision_or_sha256 `kernel-1.tar.gz` SHA-256, original_path `darwin01/kernel/machdep/i386/libc/memcmp.c`, license_reference `07_kernel/LICENSES/APSL-1.0.txt`, changes `none (verbatim)`, evidence `06_reconstruction/evidence/x86-memcmp.md`(파일·라이선스 사본 SHA-256 은 여기).
- **대조군 판정 규칙**: 세 옵션 결과를 모두 기록. 둘 이상 일치하면 이 파일의 옵션은 "미구분"으로 남기고 기준 옵션(`-O4`)이 일치하면 승격. 대조군만 일치하면 승격하지 않고 기준 옵션을 다시 정한다.

### 17.2 S5-P1 결과 (2026-10-01) — 첫 바이트 확정 목적 파일

- `memcmp.c` 를 바이트 그대로 `07_kernel/src/arch/x86/libc/memcmp.c` 에 두고(APSL 원문 `07_kernel/LICENSES/APSL-1.0.txt`), 실기에서 `-O4`·`-O2`·`-O4 -funroll-all-loops` 로 빌드(`s5p1-memcmp-1`). 세 옵션 모두 `_bcmp`·`_memcmp` MATCH, OBJECT_MATCH → 옵션 미구분, 기준 옵션 일치로 승격.
- 경계 증명서: 목적 파일 `__text` 207 B 가 원본 0x1012fc–0x1013cb 에 맞고, 앞 틈 3 B·뒤 틈 1 B 가 모두 0x00 이며 2^2 정렬 최소 길이와 같음. 채움 값 0x00 은 T1 링크 관찰과 같다.
- 기록: `06_reconstruction/objects_confirmed.tsv`(x86-memcmp, 등급 A), `06_reconstruction/functions.tsv` 2 행(`compared`/`high`), `07_kernel/PROVENANCE.tsv` 1 행, 근거 `06_reconstruction/evidence/x86-memcmp.md`, README 에 `compared`/`high` 의 뜻.
- 정정 1 건: `functions.tsv` 의 `_bcmp` 출처 줄을 확인 전에 `:63` 으로 적었다가 `:106`(정의 줄)으로 고쳤다.

다음: S5-P2 `kern_machdep.c` 로 헤더 환경 구성(세부 계획·codex 검토 후).

## 18. S5-P2 세부 계획 — `kern_machdep.c` 와 첫 헤더 환경 (코딩 전, 2026-10-01)

확인한 사실:
- 대상: `darwin01/kernel/machdep/i386/kern_machdep.c`(정의 `check_cpu_subtype`, `grade_cpu_subtype`, 둘 다 원본 구간 seq 258 안), `#import <sys/types.h>`, `<mach/machine.h>`, `<bsd/i386/cpu.h>`. 전이적 헤더 25 개, Darwin 커널 트리 밖 `i386/ansi.h`(`bsd/machine/ansi.h:39` 의 `#include "i386/ansi.h"`) 는 `darwin01/architecture/i386/ansi.h` 에만 있다.
- Darwin 의 실제 include 순서(`conf/Makefile.template:86–92`): `-I.`(생성 헤더) `-I$(SOURCE_DIR)` `-I…/bsd` `-I…/bsd/include` `-I…/machdep` `-I…/bsd/netat…` 그리고 Rhapsody `System.framework` 의 PrivateHeaders·Headers·Headers/bsd. DEFINES(`:103–105`) `-DARCH_PRIVATE -D_KERNEL -DKERNEL -DKERNEL_PRIVATE -DDRIVER_PRIVATE -DKERNEL_BUILD -D__APPLE__ -DNeXT -D_NEXT_SOURCE`, CPP_FLAGS 에 `-imacros meta_features.h`(생성 헤더).
- 실기 OPENSTEP 4.2 `System.framework` 는 PrivateHeaders 가 없고, `architecture/i386/ansi.h` 도 없으며 `bsd/machine` 구성이 다르다(`machparam.h` 등) → Darwin 의 헤더 전제와 다르다. 원본 커널을 만든 NeXT 내부 헤더는 우리에게 없다.

설계(가설 환경 — 옳은지는 L1 결과로만 판단):
1. **소스 배치**: `07_kernel/src/` 를 Darwin `kernel/` 트리와 같은 상대 경로로 둔다(include 가 경로에 의존하므로; `07_kernel/README` 가 원 경로 유지를 허용). Darwin `architecture/` 구성 요소는 `07_kernel/components/architecture/` 에 둔다. S5-P1 의 `memcmp.c` 를 `07_kernel/src/machdep/i386/libc/memcmp.c` 로 옮기고 P1 기록(PROVENANCE·functions.tsv·objects_confirmed·근거 파일)을 같은 내용으로 고친다(파일 해시 불변 확인).
2. **채택 헤더**: `kern_machdep.c` 의 전이적 헤더(Python 으로 다시 계산)만 바이트 그대로 복사하고 파일마다 PROVENANCE 행. 시스템 헤더는 쓰지 않는다(`-nostdinc`).
3. **include 루트**(Makefile 순서를 따름): `07_kernel/src`, `…/src/bsd`, `…/src/bsd/include`, `…/src/machdep`, `07_kernel/components`(→ `architecture/…`), `07_kernel/components/architecture`(→ `i386/ansi.h`; Rhapsody 의 설치 위치를 흉내낸 가정 — 기록). netat 경로는 이 파일과 무관하므로 넣지 않는다.
4. **정의**: Darwin DEFINES 를 그대로 쓰되 `-D__APPLE__` 유무 두 판으로 빌드(1999 OPENSTEP 빌드에 있었는지 모름). `-imacros meta_features.h` 는 생성 헤더가 없어 이번에는 빼고, 전처리 결과(`-E`)에 그 매크로 의존이 있는지 확인한다.
5. **빌드·대조**: 옵션은 13.2 후보(`-O2`, 대조 `-O3`·`-O4`). `kr_run.py` 의 입력은 `07_kernel` 의 필요한 부분만 복사한 스냅샷(경로 유지). 대조는 `l1_compare.py --place-from-image --ranges`, 경계 증명서는 17.1 규칙. 외부 참조(`_machine_slot`·`_cpu_number` 등)가 원본 심볼과 맞는지가 핵심 확인 항목.
6. 실패하면 차이 위치를 기록하고 원인(헤더 판·정의·옵션·소스 판)을 가린다. 원본에 맞추려 소스를 고치는 일은 별도 결정.

### 18.1 codex 교차검토 반영 (QP2) — 내 오류 1 건 포함

인용 확인: 계획 515·521–524 행, `conf/Makefile.template:86`(`-I.` 가 맨 앞), `:103–105`(`$(IDENT)`·`$(MACHINE_DEFINES)`), `bsd/machine/ansi.h:36,39`, `mach/machine.h:104–106`(`#ifdef KERNEL` 안 `machine_slot[]` 선언), `bsd/i386/cpu.h:50`(`#define cpu_number() (0)`), `07_kernel/README.md:10`, P1 경로가 든 `PROVENANCE.tsv:2`·`functions.tsv:2`·`objects_confirmed.tsv:2`, `08_build/runs/s5p1-memcmp-1/prepare.json:4`(옛 입력 경로). `$(IDENT)` 는 설정 도구가 `MASTER:107 ident NeXT` 와 options 에서 만들고, `MACHINE_DEFINES` 는 정의가 없다(빈 값).
**내 오류**: 계획 524 행에서 `_cpu_number` 를 외부 참조 확인 항목으로 적었으나 `cpu_number()` 는 매크로 `(0)` 이다. 기대 참조는 전처리 결과에서 뽑는다.

수정된 절차(7 건 모두 ✅):
1. include 해석을 고정: 작업 디렉터리 = 실행 디렉터리, 루트 순서 = `-I07_kernel/generated`(Darwin `-I.` 자리, 이번엔 비어 있음 — 명시) 다음 Makefile 순서. 실제 해석은 `cc-744.13 -traditional-cpp -E` 의 줄 표시로 기록(Python 목록은 후보일 뿐).
2. 채택 헤더 목록은 **실제 전처리 기록**(정의 세트별)에서 만든다. 해석 안 된 include 는 오류로 거부(이름으로 다른 곳을 찾지 않음).
3. 매크로: 정의 세트별 `-E -dM` 으로 실효 매크로 전체를 기록하고, `__APPLE__` 없는 판에 실제로 정의가 없음을 확인. 읽힌 헤더·소스의 모든 `#if/#ifdef/#ifndef/#elif` 조건식과 그 식의 매크로가 정의됐는지 표로 감사(설정 옵션성 매크로가 걸리면 기록하고 IDENT 재현은 S4 로).
4. `-nostdinc` 시험: 같은 옵션으로 `<stdarg.h>` 를 부르는 probe 와 빈 파일의 `-dM`(미리 정의된 매크로)을 기록.
5. 채택 헤더마다 PROVENANCE 행(목적지, 원 경로, 아카이브 SHA-256, 파일 SHA-256 은 근거 파일, 라이선스).
6. 기대 외부 참조는 전처리 결과와 목적 파일 재배치에서 뽑아 원본 심볼과 대조.
7. P1 이동: 현재 위치 열만 새 경로로 바꾸고, 근거 파일에 옛→새 경로 대응을 덧붙이며, 옛 실행·검증 산출물은 그대로 둔다. 새 경로에서 **다시 빌드·대조**해 같은 결과(OBJECT_MATCH)를 얻은 뒤에만 P1 결론을 새 위치에 잇는다.

### 18.2 S5-P2 결과 (2026-10-01)

- P1 이동: `memcmp.c` 를 `07_kernel/src/machdep/i386/libc/memcmp.c` 로 옮기고 새 위치에서 다시 빌드(`s5p1-memcmp-reloc-1`) → 목적 파일이 P1 것과 바이트 동일, OBJECT_MATCH. 현재 위치 열만 갱신, 옛 실행·검증 산출물 보존, 근거 파일에 대응 기록.
- 헤더 환경: 실제 전처리로 읽힌 21 파일만 채택(스테이징한 ppc 헤더 7 개는 읽히지 않아 제외), 파일별 PROVENANCE(라이선스 표기 확인; BSD 표기만 있는 `architecture/i386/ansi.h` 는 그에 맞게 기록). `07_kernel/generated/` 를 Darwin `-I.` 자리로 비워 둠. `__APPLE__` 는 이 파일에 영향 없음, 설정 옵션 매크로 의존 없음, `-nostdinc` 에서는 컴파일러 내장 헤더 경로가 없음.
- `kern_machdep.c`: 네 옵션 판이 같은 목적 파일. **L1 불일치** — 후보 `check_cpu_subtype` 144 B 대 원본 92 B. 원본 역어셈블로 보면 원본에는 Darwin 판의 `default:` Intel family/model 분기가 없다 → 후보 소스가 나중 판(가설). `functions.tsv` 에 두 함수를 `candidate`(check: medium, grade: low)로 기록, 근거 `06_reconstruction/evidence/x86-kern_machdep.md`. 소스 수정은 하지 않음.
- 다음 결정 필요: 근거가 분명한 차이(예: 원본에 없는 분기)를 소스에서 고치는 "복원 수정"을 시작할지. 하게 되면 수정마다 원본 역어셈블 근거·L1 결과를 남기는 규칙을 먼저 세운다.

## 19. S5-P3 세부 계획 — "복원 수정" 규칙과 첫 적용 `kern_machdep.c` (코딩 전, 2026-10-01, **사용자 결정 대기**)

확인한 사실(원본 바이트, capstone; 계산은 Python):
- 목적 파일 구간 후보 `0x18cac8`–`0x18cbca`(끝 제외, 258 B). 앞은 `_loutw` 의 `ret`(0x18cac4) 뒤 `00` 3 바이트, 뒤는 `00` 2 바이트 후 `_ldt_init`(0x18cbcc) — 두 틈 길이가 4 바이트 정렬 최소 채움(앞 3, 뒤 2; Python)과 같고 값 `00` 은 17.2 의 목적 파일 사이 채움 관찰과 같다. S2-A seq 258 의 경계 범위(0x18cac5–0x18cbcc)와 일치. 구간 안 두 함수 사이(0x18cb23)는 `90`(함수 사이 채움으로 보이나 이 파일 빌드로 확인할 항목).
- `_check_cpu_subtype`: `machine_slot[0].cpu_subtype` 가 3 → 요청 3 만 참; 4·0x84 → 요청 4·0x84·3; 5 → 요청 4·5·0x84·3; **그 밖 → 0**. Darwin 판의 네 `case` 와 같은 의미이고 `default:` Intel family/model 분기만 원본에 없다.
- `_grade_cpu_subtype`(`x86-kern_machdep.grade_cpu_subtype.disasm.txt` 로 보존 예정): 3 → {3:1}; 4 → {3:1, 0x84:2, 4:3}; 0x84 → {3:1, 4:2, 0x84:3}; 5 → {3:1, 0x84:2, 4:3, 5:4}; 나머지 0; **그 밖 → 0**. 역시 네 `case` 는 Darwin 과 같은 의미, `default:` 의 family/model 계산만 없다. 꼬리 코드 공유(교차 점프)는 GCC 최적화 결과로 보이며 소스 차이의 근거로 쓰지 않는다.
- 따라서 차이는 "소스 판" 이 원인일 가능성이 가장 크다(가설). Darwin `mach/machine.h:208–218` 의 `CPU_SUBTYPE_INTEL*` 매크로도 나중 판일 수 있으나, 쓰이지 않으면 목적 파일에 영향이 없으므로 이번에는 헤더를 고치지 않는다.
- APSL 1.0 2.1(c)(`07_kernel/LICENSES/APSL-1.0.txt:94–98`): 수정 내용과 날짜를 빠짐없이 기록, 사용한 원판 명시, 그 정보를 담은 파일을 수정본과 함께 두고, 각 수정 파일에 Exhibit A 표기를 유지.

제안 규칙(사용자 승인 후에만 적용):
- R1 **근거 있는 수정만**: 원본 역어셈블에서 관찰한 구체적 의미 차이(주소 범위 명시)가 있을 때만 고친다. "그럴 것 같다" 수준의 문체·순서 조정은 하지 않는다.
- R2 **최소 수정**: 근거가 요구하는 부분만 지우거나 바꾸고 Darwin 의 문체·주석·머리말은 그대로 둔다. 같은 바이트를 내는 소스는 여럿일 수 있으므로 "역사적 원문" 이라고 주장하지 않는다(`compared/high` 의 뜻 그대로).
- R3 **기록**: (a) `07_kernel/MODIFICATIONS.md` — 파일, 날짜, 원판(아카이브 SHA-256), 바뀐 줄, 근거 파일; (b) 수정 파일의 APSL 머리말은 그대로 두고 머리말 뒤에 한 줄 주석 "Modified <날짜>: see 07_kernel/MODIFICATIONS.md" (주석은 목적 파일 바이트에 영향 없음 — 빌드로 확인); (c) 원판 대비 diff 를 `06_reconstruction/evidence/<id>.diff` 로 보존; (d) `PROVENANCE.tsv` 의 `changes` 칸에 "restoration edit" 와 diff 경로; (e) `functions.tsv` 의 `source_revision` 에 "+ restoration edit (MODIFICATIONS.md)".
- R4 **판정**: 수정 후 빌드가 L1 MATCH·OBJECT_MATCH 면 해당 함수 `compared/high`, 목적 파일 A 등급(17 절과 같은 기준). 일치하지 않으면 시도한 변형마다 결과를 남기고, **함수당 3 회 변형까지**만 시도한 뒤 멈추고 보고한다(맞을 때까지 소스를 맞춰 끼우는 일 방지).
- R5 **예측 먼저**: 빌드 전에 예상(목적 파일 `__text` 크기, 함수 오프셋, 외부 참조)을 계획에 적고, 결과와 대조한다.

첫 적용(H1, `07_kernel/src/machdep/i386/kern_machdep.c`):
- `check_cpu_subtype`: `default:` 아래의 Intel family/model `if/else` 를 지우고 `default: break;` 만 남기거나 `default:` 자체를 지운다 — 두 변형은 의미가 같으니 둘 다 빌드해 결과를 기록하고, 원본과 맞는 것 중 원판과의 diff 가 작은 쪽을 택한다.
- `grade_cpu_subtype`: `default:` 아래 계산을 지우고 `return 0;` 만 남긴다.
- 예측: `__text` 258 B(0x18cac8–0x18cbca 와 같은 길이, 함수 사이 `90` 포함), `_grade_cpu_subtype` 오프셋 92, 외부 참조 `_machine_slot` 만, 재배치는 `machine_slot` 참조 2 개. 옵션 `-O2`·`-O3`·`-O4` 로 빌드(S5-P2 와 같은 환경, `-D__APPLE__` 판은 생략 — 영향 없음 확인됨).
- 결과는 19.2 에, 대조 결과 JSON 은 `09_validation/reconstruction/s5p3-*`.

### 19.1 codex 교차검토 반영 (QP3) 과 독립 확인

독립 확인(codex 전에 실행): 원본 두 함수를 unicorn 으로 실행해 (ms, 요청) 144 쌍(값 0,1,2,3,4,5,6,0x84,0x85,0x13,0x16,−1)의 반환값을 H1 모델과 비교 → 차이 0(`09_validation/reconstruction/s5p3-semantics-emu-20261001.json`).

| codex 주장 | 내 검증 방법 | 판정 |
|---|---|---|
| 두 함수의 (ms, 요청)→반환 표가 H1 수정 소스와 모든 칸에서 같다 | 위 에뮬레이션 144 쌍 차이 0 | ✅ |
| check 586 경로 `lea eax,[edx-4]`/`cmp eax,1`/`jbe`(0x18cb08–0x18cb0e)는 정확히 요청 4·5 | 역어셈블 파일 해당 줄 확인, Python 으로 −5..299 범위에서 조건 성립 값 = [4, 5] | ✅ |
| 386 경로는 0x18cb18 로 바로 들어가 요청 3 만 허용 | `0x18cadd je 0x18cb18` 확인 | ✅ |
| grade 0 반환 블록이 0x18cb60 과 0x18cbc4 두 곳 | 두 줄 모두 `xor eax, eax` 확인 | ✅ |
| `0x18cb3b` 는 near(`e9`), `0x18cb4c` 는 short(`eb`) 점프; 0x18cb89–0x18cb8b `nop` | 역어셈블 바이트 확인 | ✅ (사실; 바이트 일치는 빌드로만 판단) |
| grade 본체 배치 386→486→486SX→586 이 소스 case 순서와 같고 원본 case 순서가 달랐다는 근거 없음 | 블록 시작 0x18cb50·0x18cb68·0x18cb98·0x18cbac 가 증가 순, 각 블록 첫 비교 확인 | ⚖️ 배치 사실은 ✅, "순서 같음" 은 가설로만 둔다 |
| 의미가 같아도 바이트 일치는 보장되지 않는다(블록 병합·배치·점프 길이) | 설계 확인: 19 절 R4(변형 3 회 제한)·R5(예측 먼저)가 이미 이를 전제 | ⚖️ 사실, 설계 변경 없음 |
| codex 가 "함수별 100 쌍을 Python 해석으로 대조" 했다는 진술 | 재현하지 않음 — 근거로 쓰지 않는다(내 에뮬레이션만 근거) | ⏭️ |

결론: H1 은 동작 면에서 원본과 같다(확인). 바이트 일치 여부는 빌드해야 알 수 있다. 수정 적용은 사용자 결정 대기.

### 19.2 S5-P3 결과 (2026-10-01) — 첫 복원 수정, 목적 파일 A

- 사용자 결정 D014: 19 절 R1–R5 허용.
- H1 변형 A 적용(diff `06_reconstruction/evidence/x86-kern_machdep.diff`, 기록 `07_kernel/MODIFICATIONS.md`). 변형 B 는 A 가 일치해 빌드하지 않음(계획의 "diff 가 작은 쪽" 기준과 같은 결론, 변형 시도 1 회).
- `s5p3-build-1`: `-O2`/`-O3`/`-O4` 동일 목적 파일. 예측 4 항목 모두 적중. L1 두 함수 MATCH, OBJECT_MATCH, 경계 증명서 통과(앞 00×3, 뒤 00×2) → `x86-kern_machdep` A 등급, `_check_cpu_subtype`·`_grade_cpu_subtype` `compared/high`. 근거 `06_reconstruction/evidence/x86-kern_machdep.md`.
- 의미: 이 목적 파일을 재현하는 소스를 얻었다(역사적 원문이라는 주장은 아님). `mach/machine.h` 등 헤더의 판 차이는 이 목적 파일에 드러나지 않아 판단 보류.

## 20. S5-P4 세부 계획 — `pagesize.c` 와 Mach 커널 헤더 확장 (코딩 전, 2026-10-01)

고른 이유(Python 으로 `objects.tsv` 를 정렬): B 등급·Darwin 후보 파일 1 개인 구간 중 작고(78 B), 외부 참조가 없고, 헤더가 `<mach/mach_types.h>` 하나지만 `#if _KERNEL && !MACH_USER_API`(`mach/mach_types.h:102`) 아래 `kern/task.h`·`kern/thread.h`·`kern/processor.h`·`vm/vm_user.h`·`vm/vm_object.h` 를 끌어와(`:103–109`; 그 위 `:85–100` 은 `mach/*` 16 개) Mach 커널 헤더 환경을 넓히는 첫 시험이 된다. 인라인 어셈블리와 `NX_CURRENT_COMPILER_RELEASE` 조건도 함께 시험된다.

확인한 사실(원본 바이트·capstone, 계산 Python):
- S2-A seq 6: `_page_set` 0x1019c0–0x1019f0, `_page_copy` 0x1019f0–0x101a0e, 합 78 B, `_page_copy` 오프셋 48. 앞 틈 0x1019be–0x1019c0 `00`×2(앞 구간 `bzero.S,memset.c` 의 `ret` 0x1019bd 뒤), 뒤 틈 0x101a0e–0x101a10 `00`×2 — 둘 다 4 바이트 정렬 최소 채움.
- `_page_set`: 인자 3 개를 `edx`·`ecx`·`eax` 로 읽고 32 바이트 단위 `movl` 8 개 반복(`jne 0x1019cc`) — 소스의 `mem_set_a4_l32` 인라인 어셈블리와 같은 모양. 반복 시작 0x1019cc 는 이미 4 바이트 정렬이라 `.align 2, 0x90` 이 채움을 넣지 않은 것과 맞는다.
- `_page_copy`: `edi`·`esi` 저장, `len>>2` → `ecx`, `rep movsd`. 외부 참조 없음.
- 이 툴체인의 `NX_CURRENT_COMPILER_RELEASE` = 410(`s5p2-pre-2` 의 `-dM` 출력) → 소스는 `SIREG "S"` 쪽.

설계:
1. **스테이징**: `pagesize.c` 에서 `#include`/`#import` 를 텍스트로 따라가 Darwin 트리에서 닫힘을 구한다(P2 와 같은 include 루트 순서; 조건부 include 도 일단 포함 — 실제 사용은 전처리로 가림). 결과를 `08_build/runs/tools/s5p4-stage-1/` 에 경로 유지로 복사하고 manifest(대상, 원 경로, SHA-256). `07_kernel` 에 이미 있는 21 파일은 Darwin 원본과 SHA-256 이 같은지 확인한다. 스테이징 도구는 `10_tools/reconstruction/stage_headers.py` 로 만든다(P2 때 손으로 한 일을 재사용 가능하게; 같은 입력으로 P2 의 스테이징 목록을 다시 만들어 기존 manifest 와 같은지 자체 시험).
2. **전처리** `s5p4-pre-1`: P2 와 같은 정의·include 루트로 `-E`(줄 표시로 읽힌 파일 목록), `-E -dM`. 확인 항목: 읽힌 파일 집합, 미해결 include 오류 유무, `SIREG` 값, `__APPLE__` 은 P2 결과대로 넣지 않는다.
3. **채택**: 읽힌 파일만 `07_kernel` 에 바이트 그대로 복사, 파일마다 PROVENANCE 행과 라이선스 표기 확인(`@APPLE_LICENSE_HEADER_START@` 표지 + 그 밖 표기). Mach4/CMU 표기가 있는 헤더는 표기 그대로 기록. NeXTMach 원본은 쓰지 않는다(D013).
4. **빌드** `s5p4-build-1`(입력 `07_kernel`): `-O4`, `-O2`, `-O4 -funroll-all-loops`(P1 의 libc 판 집합) 과 `-O3`.
5. **예측**: `__text` 78 B, `_page_copy` 오프셋 48, 재배치 0, 정의 안 된 심볼 0, `static __inline__` 도우미 함수는 목적 파일에 남지 않음(남으면 크기가 달라진다), `__data` 등 다른 섹션 크기 0.
6. **대조**: `l1_compare.py --place-from-image --ranges`(Ghidra 몸체) + 17.1 경계 증명서. 일치하지 않으면 원인을 가리고 D014 규칙(R1–R5)으로만 수정.
7. **실패 시 헤더 문제의 구분**: 헤더가 많아 전처리·컴파일 오류가 날 수 있다(예: 생성 헤더 `meta_features.h`·MIG 산출물 요구). 오류가 나면 수정하지 않고 어떤 파일·매크로가 무엇을 요구했는지 기록하고 멈춘다 — 생성 헤더는 S4(빌드 골격) 몫이다.

### 20.1 codex 교차검토(QP4-a: 인라인 asm 재현성) 판정과 독립 확인

| codex 주장 | 내 검증 방법 | 판정 |
|---|---|---|
| 원본 첫 저장이 `89 42 00`(0 변위 명시), `jne .-30` 은 고정 거리라 짧은 인코딩(`89 02`)이면 목적지가 0x1019cb 로 어긋난다 | 역어셈블 0x1019cc `894200`; Python: 3 바이트면 `jne` 0x1019ea→0x1019cc, 2 바이트면 0x1019e9→0x1019cb | ✅ — 이 소스는 NeXT `as` 가 `0x00(%reg)` 를 disp8 로 남긴다는 전제를 가진다. 빌드로 확인할 항목에 추가 |
| `.align` 무채움·레지스터 배정(`_page_set` EDX, `_page_copy` EAX 경유)·인라인 성공은 원본 관찰일 뿐 새 빌드의 보장이 아니다 | 원본 역어셈블 0x1019c3–0x1019c9, 0x1019f5–0x1019fb 확인; 소스 `pagesize.c:68`(`"=r"`), `:89` | ⚖️ 사실. 예측 항목으로 두고 빌드로 판정(설계 변경 없음) |
| `pagesize.c` 줄 40–44(SIREG), 56·84(도우미), 59–67(asm), 89, 99·107 | 각 줄 열어 확인 | ✅ |
| cc-744.13 은 입력 피연산자와 같은 레지스터 clobber(`"c"`/`"ecx"` 등)를 받아들인다 — `memcmp.c:72` asm, 실기 빌드 종료 코드 0·stderr 빈 파일 | `memcmp.c:72–81` 열어 `"c","D",SIREG` + `"ecx","edi","esi"` 확인; `s5p1-memcmp-reloc-1/out/_log/status` 전부 0, `*.err` 0 바이트; `run.cmd:2` 옵션 확인 | ✅ (단 `"a"`/`"eax"` 조합은 미확인 — 빌드 로그로 확인) |
| `-traditional-cpp` 에서 줄바꿈이 든 문자열이 허용된다 — `memcmp.i:73` | `s5p1-memcmp-reloc-1/out/memcmp.i:70–76` 확인 | ✅ |
| GCC 2.7.2 가 겹치는 clobber 를 검출하지 않았다는 gcc-patches 메일 | 열지 않음 | ⏭️ 근거로 쓰지 않음 |

독립 확인(내 Python 텍스트 닫힘 계산, 스크래치): `pagesize.c` 닫힘 122 파일, 해석 안 되는 include 20 건. 그중 `-DKERNEL_BUILD` 아래 생성 헤더 요구 — `mach/features.h:50` `<meta_features.h>`(`#ifdef KERNEL`/`#ifdef KERNEL_BUILD`), `kern/sched.h:63` `<cpus.h>`, `kern/assert.h:39` `<mach_assert.h>` — 와 Darwin 트리에 없는 `machdep/i386/features.h`(`machdep/machine/features.h:32`, `__i386__` 분기). **따라서 설계 7 에 해당할 가능성이 높다**: 전처리 `s5p4-pre-1` 은 진단으로 실행해(07_kernel 변경 없음) 실제로 어떤 include 가 실패하는지 기록하고, 생성 헤더가 필요하면 P4 를 멈추고 S4(설정·생성 헤더) 계획으로 넘긴다. 정의를 빼거나(`-DKERNEL_BUILD` 제거) 빈 헤더를 만들어 통과시키는 우회는 하지 않는다.

### 20.2 codex 교차검토(QP4-b: 스테이징 닫힘) 판정 — P4 를 S4 뒤로 미룸

| codex 주장 | 내 검증 방법 | 판정 |
|---|---|---|
| `pagesize.c:38` → `mach/mach_types.h:102` → `kern/task.h:61` `<mach/features.h>` → `mach/features.h:47`(`#ifdef KERNEL`)·`:50` `<meta_features.h>`; Darwin 트리에 없음 | 각 줄을 Python 으로 열어 내용 확인; 내 닫힘 계산의 미해결 목록에 `meta_features.h` | ✅ |
| `kern/timer.h:87`·`kern/sched.h:62` 의 `#ifdef KERNEL_BUILD` 아래 `cpus.h`·`stat_time.h`·`mach_fixpri.h`·`simple_clock.h` 요구 | `timer.h:84–92`, `sched.h:60–70` 열어 확인 | ✅ |
| 모든 조건 분기를 따르면 비활성 분기에서도 미해결이 생긴다 — `kern/processor.h:75`(`NCPUS > 1`) → `machdep/machine/ast_types.h:32` → 없는 `machdep/i386/ast_types.h` | 줄 확인, 파일 부재 `os.path.exists` = False | ✅ → 스테이징 도구는 미해결 include 를 오류가 아니라 목록으로 기록하고, 성공 판정은 실기 전처리로만 한다 |
| 따옴표 include 는 "포함한 파일의 디렉터리 → 루트" 순서; 이번 범위에 디렉터리 우선으로 달라지는 사례·여러 루트 충돌·매크로 include 없음 | 내 닫힘 계산: macro includes [], multi-root [], 따옴표 대상 모두 루트에서 해석(`vm_types.h:32`, `bsd/machine/ansi.h:39` 확인) | ✅ |
| `#import`/`#include` 혼용(`mach_types.h:96` vs `task.h:65`, 가드 `time_value.h:51`)·서로 다른 파일의 같은 가드(`kern/macro_help.h:57`, `kernserv/macro_help.h:39`) | 줄 확인 | ✅ 사실. 가드 충돌은 어느 파일이 먼저 읽히느냐로 본문이 달라질 수 있어 전처리 결과로 확인할 항목 |
| `-E` 줄 표시는 "모든 파일 읽기" 의 증명이 아니다 → 채택 파일만 있는 격리 입력으로 같은 전처리를 다시 해 성공·결과 동일을 확인하라 | 설계 확인: P2 는 채택 뒤 `07_kernel` 스냅샷으로 빌드했지만 `-E` 결과 동일 비교는 명시하지 않았다 | ✅ 채택 — 채택 절차에 "격리 입력 재전처리, `.i` 동일" 조건 추가(이후 모든 파일) |
| GNU CPP 문서 링크 2 개 | 열지 않음 | ⏭️ 근거로 쓰지 않음 |

결정(계획 20 설계 7 적용): `-DKERNEL_BUILD` 에서 `pagesize.c` 는 config 생성 헤더(`meta_features.h`, `cpus.h`, `stat_time.h`, `mach_fixpri.h`, `simple_clock.h`, `mach_assert.h` 등)를 필요로 한다. 이것들은 Darwin `config` 가 `conf/MASTER*` 의 `options` 로 만드는 파일이고, 값은 원본 커널의 설정을 따라야 한다. 따라서 **P4 는 코딩(스테이징 도구·전처리) 전에 멈추고 S4-A(설정 옵션·생성 헤더 계획) 를 먼저 세운다.** 정의 제거·빈 헤더 같은 우회는 하지 않는다.

## 21. S4-A 사전 조사 — 설정 옵션과 생성 헤더 (조사만, 2026-10-01)

P4 가 멈춘 원인(20.2)을 풀기 위한 사실 수집. 설계·코딩은 이 절의 계획과 codex 교차검토 뒤에 한다.

확인한 사실(파일을 열어 확인, 줄은 Python 으로 대조):
- 생성 헤더 출처 두 갈래: (1) `conf/files` 의 `OPTIONS/<name>` 76 행 — `config` 가 `<name>.h` 를 만들고 선택 여부에 따라 `#define <MACRO> 0/1`(NeXTMach `mk-108.1/src/config/mkheaders.c:232–233` 의 `fprintf(outf, "#define %s %d\n", …)`; D013 — 참고만, 옮기지 않음). 예: `mach_assert`(`files:40`), `mach_fixpri`(`:45`), `simple_clock`(`:65`), `stat_time`(`:66`). (2) `meta_features.h` — `Makefile.template:107` 의 `-imacros meta_features.h`, `:266` `FEATURES_H= meta_features.h`, `:831–833` 이 이것을 `cc -traditional-cpp -E -dD -P` 로 펼쳐 `features.h` 를 만든다. **`meta_features.h` 를 만드는 규칙·도구는 참고 자료 어디에도 없다**(전체 grep: `Makefile.template`, `mach/features.h` 두 곳만 언급). `cpus.h`(`NCPUS`)도 `OPTIONS` 목록이 아닌 `config` 의 장치/CPU 수 처리에서 나온다(가설 — 생성 규칙 확인 필요).
- i386 설정(`conf/MASTER.i386`): `:83` `RELOC = "00100000"`, `:84` `SYMADDR = "00780000"` — 원본의 `__TEXT` 0x100000, `__LINKEDIT` 0x780000 과 같다(원본 판과 가까운 설정이라는 정황). `:81–82` `CCONFIGFLAGS` 는 `<gdb>` 이면 `-g -O3 -fno-omit-frame-pointer`, 아니면 `-O3` — 13.3 의 "-O2/-O3 구별 불가" 와 모순 없음. `:93` `config mach_kernel swap generic`.
- 표준 구성 `RELEASE = [intel pc mach medium event vol pst gdb kernobjc libdriver fixpri simple_clock mdebug kernserv driverkit uxpr kernstack ipc_compat ipc_debug nfsclient nfsserver quota fifo fdesc union portal ffs cd9660 compat_43 revfs nbc]`(`MASTER.i386` 머리 주석). 이것은 Darwin(1999) 의 목록이며 OPENSTEP 4.2 원본의 구성과 같다는 근거는 아직 없다.

S4-A 계획 방향(제안, 다음 단계에서 상세화·codex 검토):
1. 원본 바이너리에서 옵션 값을 판정할 근거를 옵션마다 찾는다(예: `MACH_ASSERT` → assert 문자열·`_Assert` 호출 유무, `NCPUS` → `cpu_number()` 사용 형태, `STAT_TIME`/`SIMPLE_CLOCK` → 타이머 코드 모양, `MACH_FIXPRI` → 정책 코드 유무). 근거가 없는 옵션은 "미정" 으로 두고 그 옵션에 의존하는 파일은 확정하지 않는다.
2. 생성 헤더는 `07_kernel/generated/` 에 우리 도구(Python, `10_tools/reconstruction/`)로 만든다 — 옵션 표(근거 열 포함)를 입력으로. NeXTMach `config` 코드는 옮기지 않고 출력 형식만 관찰 사실로 기록.
3. `meta_features.h` 는 내용이 알려지지 않았으므로, 그것을 읽는 헤더(`mach/features.h`)가 실제로 요구하는 매크로를 전처리로 모아 최소 내용을 정하고, 그 내용이 목적 파일 바이트에 영향을 주는지 L1 로 확인한다.
4. RELEASE 태그 목록은 1 차 가설로만 쓴다.

## 22. S4-A1 세부 계획 — 공통 Mach 헤더가 요구하는 설정 옵션 6 개와 생성 헤더 (코딩 전, 2026-10-01)

새로 확인한 사실:
- 원본 문자열(파일 오프셋 0xe5659): `NeXT Mach 4.2: Tue Jan 26 11:21:50 PST 1999; root(rcbuilder):Objects/mk-183.34.4.obj~2/RELEASE_I386` → 원본은 **RELEASE_I386 구성**으로 빌드됐다.
- 원본에 박힌 소스 경로 19 개(`/BinarySourceCache_Mario1A/mk/mk-183.34.4/...`, `driverkit/KernBus.m`, `machdep/i386/swapgeneric.m` 등)가 모두 Darwin 0.1 `kernel/` 트리의 같은 상대 경로에 있다 → 원본 소스 트리 배치가 Darwin 과 같다는 근거(07_kernel 의 경로 유지 방침과 맞음).
- 실기 OPENSTEP 4.2 의 `/NextLibrary /NextDeveloper /System /usr/include /usr/local /LocalDeveloper /LocalLibrary` 에 `features.h`·`meta_features.h`·`cpus.h`·`mach_assert.h`·`stat_time.h` 없음(양성 대조: 같은 방법으로 `/NextDeveloper/Headers/mach/mach_types.h` 등은 찾음). 원본 시대의 생성 헤더 실물은 없다.
- `mach/mach_types.h` 의 텍스트 닫힘(121 파일, 모든 분기)에서 생성 헤더 요구: `meta_features.h`(`mach/features.h:50`), `cpus.h`(`kern/sched.h:63`, `kern/timer.h:88`), `mach_assert.h`(`kern/assert.h:39`), `mach_fixpri.h`(`kern/sched.h:64`), `simple_clock.h`(`:65`), `stat_time.h`(`:66`, `kern/timer.h:89`). 그 밖 미해결은 다른 아키텍처(ppc) 분기, `NCPUS > 1`·`!STAT_TIME`·`MACH_ASSERT`·`MACH_PAGEMAP` 분기 아래의 파일이다(`machine/cpu_number.h`, `machine/sched_param.h`, `kernserv/printf.h`, `vm/vm_external.h`, `machdep/i386/ast_types.h`).
- Darwin `MASTER` 의 해당 옵션 태그: `MACH_ASSERT <test>`(`:119`), `MACH_FIXPRI <fixpri>`(`:124`), `SIMPLE_CLOCK <simple_clock>`(`:140`), `STAT_TIME <!timing>`(`:141`), `cpus` 1 이 기본(`:204–208`). Darwin RELEASE 태그 목록으로 계산한 1 차 가설: `MACH_ASSERT 0`, `MACH_FIXPRI 1`, `SIMPLE_CLOCK 1`, `STAT_TIME 1`, `NCPUS 1`. (`MACH_DEBUG` 는 ppc 분기에서만 요구되어 이번 범위 밖.)
- 각 옵션의 조건부 사이트 수(Python, Darwin kernel 트리): NCPUS 58(27 파일), MACH_FIXPRI 30(8), SIMPLE_CLOCK 11(5), MACH_ASSERT 10(9), STAT_TIME 6(4).

설계:
1. **옵션 근거 수집 도구** `10_tools/reconstruction/option_evidence.py`(분석 도구, 커널 소스 아님): Darwin 소스에서 조건이 정확히 `OPT`, `!OPT`, `NCPUS > 1`, `NCPUS == 1` 류인 `#if` 블록을 중첩 추적으로 찾아, 블록 안에서만 정의되는 **외부 함수 정의**(srcdefs)와 **문자열 리터럴**을 뽑는다. 원본 심볼표(외부 3,651)와 원본 문자열에서 존재 여부를 본다. 출력 TSV: 옵션, 분기, 근거 종류, 이름/문자열, 소스 위치, 원본 존재 여부·주소.
2. **판정 규칙**: 한 분기의 고유 근거가 원본에 1 개 이상 있고 다른 분기의 고유 근거가 하나도 없으면 그 값으로 판정. 양쪽 다 있거나 둘 다 없으면 "미정". 부재만으로 판정하지 않는다(나중 판에서 추가된 함수일 수 있음) — 부재는 보조 근거로만 기록. 미정 옵션은 원본 역어셈블 한 곳을 골라 수작업 확인하고 근거를 남긴다.
3. **생성 헤더**: 판정된 값으로 `07_kernel/generated/<opt>.h`(`#define MACRO <값>`, 관찰된 NeXTMach `config` 출력 형식을 따르되 코드는 옮기지 않음)와 `cpus.h`(`#define NCPUS <값>`)를 Python 생성기 `10_tools/reconstruction/gen_config_headers.py` 로 만든다. 입력은 근거 열이 있는 `06_reconstruction/config_options.tsv`. 생성물마다 PROVENANCE 행(source_id `generated`, 근거 경로).
4. **`meta_features.h`**: 만드는 규칙이 참고 자료에 없다. `Makefile.template:831–833` 이 이 파일을 `-E -dD` 로 펼쳐 정의 목록 `features.h` 를 만든다는 점에서 "생성 옵션 헤더들을 모으는 파일" 이라는 가설(H-meta)을 세우고, 최소판(이번에 만든 옵션 헤더를 `#import` 로 모음)으로 시작한다. 가설로 표시하고, 이후 파일마다 "조건에 쓰였는데 정의 안 된 매크로" 를 전처리로 점검(18 절 방식)해 빠진 옵션을 찾는다. `-imacros meta_features.h` 는 Darwin 명령 그대로 쓴다.
5. **검증**: (a) S5-P1·P3 의 두 확정 목적 파일을 새 생성 헤더 + `-imacros` 로 다시 빌드해 바이트가 그대로인지(회귀), (b) 그 다음 P4 `pagesize.c` 를 20 절대로 재개.
6. 이번 범위 밖: 나머지 27 개 OPTIONS 헤더, 장치 수 헤더(`bpfilter.h`·`pty.h` 등), `cputypes.h`·`confdep.h`, MIG 산출물, `assym.h`. 필요해질 때 같은 방법으로 넓힌다.

### 22.1 codex 교차검토 반영 (QA1-a: 옵션 판정 규칙, QA1-b: meta_features.h) — 설계 변경

QA1-a(내 검증: 인용 17 곳을 Python 으로 열어 내용 확인, 원본 `symbols.tsv`·바이트 검색):

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| 조건부 문자열이 다른 파일에서 무조건 쓰임: `machdep/ppc/trap.c:533`(`#if MACH_ASSERT`)·`:558` `"%08x "` vs `machdep/i386/miniMonMachdep.c:133`; 원본에 `"%08x "` 두 곳 | 줄 확인; 원본 `\0%08x \0` 위치 0xd96bf·0xe174b(문자열 시작 +1 = 0xd96c0·0xe174c) | ✅ → 고유성은 **트리 전체(무조건 사용·다른 아키텍처 포함)** 에서 검사, 문자열은 앞뒤 NUL 경계로만 비교 |
| 양 분기에 같은 이름: `processor_assign`(`kern/machine.c:286/373/723`), assert 문자열(`ipc_right.c:2587`, `mach_port.c:1598`) — 원본에 있음 | 줄 확인; `_processor_assign` 0x15dfd8, 문자열 0xdea42·0xdeafd | ✅ → 양 분기·조건 밖 출현이 있으면 근거에서 제외 |
| 함수 본문만 조건부인 경우: `thread_policy`(`kern/thread.c:2200`), `processor_set_policy_enable`(`kern/processor.c:806`) — 원본 심볼 있음 | 줄 확인; 0x1688f4·0x161a98 | ✅ → 정의 전체(시작~끝)가 조건 블록 안일 때만 근거 |
| 매크로·인라인·`notdef` 중첩으로 심볼이 안 생김(`parallel.h:65`, `lock.c:75`, `simple_lock.h:50`, `timer.h:160`) | 줄 확인; `_unix_master`·`__unix_master`·`_start_timer`·`_timer_switch`·`_time_trap_uentry`·`_time_int_entry` 원본에 없음 | ✅ → 부재는 판정에 쓰지 않음(기존 규칙 유지) |
| 복합식(`bsd/kern/init_main.c:642` `NeXT && NCPUS > 1`)의 `#else` 는 옵션의 반대값 근거가 아니다 | 줄 확인 | ✅ → 단일 조건 블록만 쓰고 복합식은 참 분기의 conjunct 근거로만 |
| 소스 판 차이: Darwin 에서 조건부인 정의가 원본 판에서는 무조건이었을 수 있다(`mach_clock.c:176` `sched_usec_elapsed`, 원본 0x160714) — 가설 | 줄·심볼 확인; 판 차이 자체는 증거 없음 | ⚖️ 채택 → 심볼·문자열 근거만으로는 **"가설"** 단계까지만 |
| `#if OPT` 참은 "0 아님", `NCPUS > 1` 은 범위 — 정확한 값은 별도 근거 | 논리 확인 | ✅ → 값(특히 `NCPUS`)은 배열 크기 등 별도 근거 필요 |

QA1-b(내 검증: `doconf.csh:103–123`, `Makefile.i386:78–82`, NeXTMach `mkheaders.c:14–18`, NeXTMach `conf/Makefile.template:458–467`, `conf/files:34–35` 를 열어 확인):

| codex 주장 | 판정 |
|---|---|
| `doconf.csh` 에 `FEATURES_H=(cs_*.h mach_*.h net_*.h … cputypes.h cpus.h …)` 가 있으나 이후 쓰이지 않음 | ✅ (`:120–123`; `FEATURES` 는 `:120` 에서 설정만) |
| NeXTMach `config` 는 features 생성을 버리고 Makefile 이 한다(`mkheaders.c:14–18`), NeXTMach Makefile 은 `mach_*.h cpus.h simple_clock.h stat_time.h …` 를 `sort` 로 합친다(`:458–467`) | ✅ — H-meta(옵션 헤더 집계) 를 지지하는 선례. 원본 내용의 증거는 아님 |
| `memcmp.c` 도 `$(COPTS)`(따라서 `-imacros`)를 받는다: `Makefile.i386:78–82` | ✅ 추가 사실: libc 6 파일(`memchr memcmp memcpy memmove memset pagesize`)은 `-O4` 로 컴파일 — P1 결과와 일치, P4 옵션 집합 근거 |
| 현재 `memcmp.c`·`kern_machdep.c` 의 헤더 경로에 5 옵션의 코드상 사용이 없다 → 바이트 불변 예상, 단 회귀 빌드로 확정 | ⚖️ 예상으로만 둠(설계 5 유지) |
| `meta_features.h` 생성 주체는 미상(config 추정은 추측) | ✅ 가설 유지 |

설계 변경:
1. `option_evidence.py`: 근거 후보 = (a) **정의 전체가 단일 조건 블록 안**인 외부 함수, (b) 그 블록 안 문자열 리터럴(앞뒤 NUL 경계 정확 일치), 그리고 (c) 같은 이름·문자열이 **트리 전체에서 그 분기 밖에 한 번도 나오지 않을 것**(다른 아키텍처·무조건 코드 포함). 복합 조건 블록은 참 분기만, 반대값 근거로는 쓰지 않음.
2. 옵션 상태 3 단계: **미정** → **가설**(위 근거 + 원본의 해당 함수를 IDA(`05_ida/databases/x86-full.i64`, 입력 SHA-256 원본과 동일 확인)로 열어 그 분기의 코드 모양과 대응함을 확인, 근거 기록) → **확정**(그 옵션에 따라 바이트가 달라지는 목적 파일이 L1 MATCH). 생성 헤더는 가설 단계 값으로 만들되 표에 상태를 적는다.
3. `NCPUS` 의 정확한 값은 `[NCPUS]` 크기 배열(예: `machine_slot`)의 원본 크기 등 별도 근거로 정한다.
4. `meta_features.h` = H-meta 최소판(생성 옵션 헤더 `#import` 모음), 가설 표시. 회귀(설계 5a) 필수.

### 22.2 S4-A1 결과 (2026-10-01) — 옵션 5 개 가설 판정, 생성 헤더, 회귀 통과

- `option_evidence.py`(22.1 규칙) 실행: `09_validation/reconstruction/s4a1-option-evidence-20261001.{tsv,json}`. Darwin 트리 1,569 파일, 블록 안 함수 30·문자열 26 후보. 대조 사례(codex 지적)는 의도대로 제외됨: `processor_assign`(분기 밖 정의), `"%08x "`(분기 밖 사용), `unix_master`(`#define`), `thread_policy`(정의 전체가 블록 안이 아님 → 후보 아님). 쓸 수 있는 양성 근거는 `SIMPLE_CLOCK=1` 의 `sched_usec_elapsed`(원본 0x160714) 1 건뿐, 나머지는 부재만 → 설계 2 대로 IDA 로 원본 함수 본문 확인.
- IDA(`05_ida/databases/x86-full.i64`, 입력 SHA-256 = 원본 `33469393…` 확인, 읽기만·저장 안 함) 와 capstone 확인:
  - `MACH_ASSERT=0`: `ipc_right_copyin_compat`(`ipc/ipc_right.c:2587`)·`convert_port_type` 등(`ipc/mach_port.c:1598`)의 `#else` 처럼 문자열을 바로 `_panic` 에 넘김(0x15032c→0x150331, 0x155cd8→0x155cdd).
  - `MACH_FIXPRI=1`: `_thread_policy` 0x1688f4 가 `kern/thread.c:2214–2259` 분기 모양(잠금, `policy == 2` 일 때 `1000*data % tick` 양자, `compute_priority`)이고 `#else`(`:2260–2264`, 즉시 반환)가 아님.
  - `SIMPLE_CLOCK=1`: `_sched_usec_elapsed` 존재. 본문은 Darwin 과 다름(`clock_value(1)`, 1000 으로 나눔) — 소스 판 차이 사례.
  - `STAT_TIME=1`: `_clock_interrupt` 0x15bc30 이 사용자/시스템 타이머에 `usec` 를 더하고 부호 비트면 `_timer_normalize` 호출(`kern/mach_clock.c:112–123` 의 `timer_bump`, `kern/timer.h:176`).
  - `NCPUS=1`: `_machine_slot`(`kern/machine.c:86` `machine_slot[NCPUS]`) 이 `__common` 에서 다음 심볼까지 32 B = 구조체 32 B(4×4 + 4×`CPU_STATE_MAX`(3) + 4, Python) 한 개.
  - 다섯 값 모두 Darwin RELEASE 태그로 계산한 1 차 가설과 같다. 상태는 **가설**(확정은 이 옵션에 의존하는 목적 파일의 L1 일치 때).
- `06_reconstruction/config_options.tsv`(근거 열 포함) → `gen_config_headers.py` → `07_kernel/generated/{cpus,mach_assert,mach_fixpri,simple_clock,stat_time,meta_features}.h`(`--check` 통과), PROVENANCE 6 행. `generated/EMPTY_ON_PURPOSE` 는 `README` 로 바꿈.
- 회귀 `s4a1-regress-1`(전체 Darwin 정의 + `-nostdinc` + `-imacros src/generated/meta_features.h`): 오류 출력 없음, `-dM` 에 5 매크로 정의 확인, `kern_machdep.o`(`-O2`)·`memcmp.o`(`-O4`) 가 기존 확정 목적 파일과 SHA-256 동일(`09_validation/reconstruction/s4a1-regress-20261001.json`). 이후 빌드는 이 공통 명령을 기준으로 한다.
- 다음: P4 `pagesize.c` 재개(20 절; 스테이징 도구 + 진단 전처리). 미해결로 남는 생성 헤더가 더 나오면 같은 방법(근거 → 가설 → 생성)으로 넓힌다.

### 20.3 S5-P4 결과 (2026-10-01) — `pagesize.c` 원문 그대로 A, 미정의 옵션 9 개 발견

- 스테이징 도구 `stage_headers.py`(자체 시험: P2 스테이징 28 파일 집합·SHA 동일), `s5p4-stage-1` 128 파일·미해결 11(모두 비활성 분기).
- 진단 전처리 `s5p4-pre-1`(S4-A1 공통 명령): 오류 없음, 읽힌 파일 105. **읽힌 헤더의 조건식에 정의되지 않은 설정 옵션 9 개**(`MACH_HOST`, `MACH_IPC_COMPAT`, `MACH_IPC_DEBUG`, `MACH_PAGEMAP`, `MACH_VM_DEBUG`, `NEW_VM_CODE`, `OLD_VM_CODE`(20 곳), `NORMA_TASK`, `NORMA_VM`) — cpp 가 0 으로 평가해 구조체 배치를 바꿀 수 있다. 비-OPTIONS 미정의(`MACHINE_AST`, `PAGE_SIZE_FIXED` 등)는 ppc 에서만 정의되거나 어디에도 정의되지 않음(전수 grep).
- **새 규칙**: 확정 대상 파일의 전처리에서 OPTIONS 매크로가 미정의로 남으면, 그 파일의 목적 코드가 그 매크로에 의존하지 않음을 보이기 전에는 확정하지 않는다(이번 파일은 타입·인라인 asm 만 쓰고 L1 일치). 다음 단계 S4-A2 에서 9 옵션을 22.1 방법으로 판정한다.
- **내 오류(바로잡음)**: 채택 스크립트가 실행 경로 접두어 `src/` 를 두 번 벗겨 92 파일을 `07_kernel/{bsd,ipc,kern,kernserv,mach,machdep,vm}/` 에 복사했다. 첫 빌드 `s5p4-build-1` 은 입력 파일이 없어 모든 명령이 실패했고 collect 가 게시를 거부해 드러났다. 디스크의 92 파일이 복사 목록과 정확히 같음을 확인한 뒤 76 개를 `07_kernel/src/…` 로 옮기고, 이미 올바른 위치에 같은 SHA 로 있던 16 개의 중복 사본을 지우고 빈 디렉터리를 정리했다. PROVENANCE(76 행 경로 수정·16 행 삭제, 중복 0·없는 파일 0)와 근거 목록을 고치고, 읽힌 105 파일 전부가 올바른 위치에 같은 SHA·PROVENANCE 행으로 있음을 다시 확인했다. `s5p4-build-1` 은 실패 기록으로 남긴다.
- `s5p4-build-2`: 격리 재전처리 `.i` 동일, 네 옵션 판 동일 목적 파일, 예측 5 항목 적중, L1 두 함수 MATCH·OBJECT_MATCH, 경계 증명서 통과 → `x86-pagesize` A, `_page_set`·`_page_copy` `compared/high`(복원 수정 없음). 근거 `06_reconstruction/evidence/x86-pagesize.md`.

## 23. S4-A2 세부 계획 — 미정의로 남은 설정 옵션 9 개 (코딩 전, 2026-10-01)

대상(20.3 에서 발견, Darwin `conf/files` OPTIONS 항목): `MACH_HOST`(files:46), `MACH_IPC_COMPAT`(:47), `MACH_IPC_DEBUG`(:48), `MACH_PAGEMAP`(:59), `MACH_VM_DEBUG`(:61), `NORMA_VM`(:79), `NORMA_TASK`(:80), `NEW_VM_CODE`(:82), `OLD_VM_CODE`(:83).

확인한 사실(Python, Darwin 트리):
- `MASTER` 태그와 RELEASE 태그(`MASTER.i386` 머리 주석, 31 개)로 계산한 1 차 가설: `MACH_IPC_COMPAT 1`(`<ipc_compat>`, MASTER:126), `MACH_IPC_DEBUG 1`(`<ipc_debug>`, :127), `OLD_VM_CODE 1`(`<!newvm>`, :115), `NEW_VM_CODE 0`(`<newvm>`, :114), `MACH_HOST 0`(`<host>`, :125), `NORMA_VM 0`(:137), `NORMA_TASK 0`(:138); `MACH_PAGEMAP`·`MACH_VM_DEBUG` 는 MASTER 에 없음 → config 기본 0(관찰한 NeXTMach config 형식: 선택 안 된 OPTIONS 는 0).
- 조건부 사이트: MACH_IPC_COMPAT 79(21 파일), MACH_HOST 37(12), OLD_VM_CODE 25(7), MACH_VM_DEBUG 18(4), MACH_PAGEMAP 6(2), NORMA_VM 6(3), MACH_IPC_DEBUG 5(4), NORMA_TASK 4(2), NEW_VM_CODE 1(1).
- 여러 옵션이 **구조체 배치**를 바꾼다: 예 `OLD_VM_CODE` 는 `vm/vm_page.h:120–122`(`clean:1`), `:142–147`(`copy_on_write`·`nfspagereq`·`asyncrw` 비트) 와 `vm_page_queue_free` 의 형(`:183–188`), 함수 집합(`:238–244`, `:412–416`)을 바꾼다.

설계(22.1 의 규칙을 그대로 적용):
1. `option_evidence.py` 를 옵션 목록 인자를 받도록 넓힌다(기본값은 S4-A1 5 개 그대로 — 이전 출력 재현을 자체 시험으로 확인). 9 옵션 근거 TSV 를 만든다.
2. 옵션마다 IDA(`x86-full.i64`, 읽기만) 로 원본 함수 본문 1 곳 이상을 해당 분기와 대조. 근거 함수가 없거나 Darwin 과 판이 다르면 다음 방법 3 을 쓴다.
3. **구조체 오프셋 탐침**(새 방법): 옵션 값 두 경우로 실기 `cc` 가 계산한 필드 오프셋을 얻는다 — 탐침 C 파일이 `int off_X = (int)&((struct T *)0)->field;` 같은 상수를 `__data` 에 두게 하고 목적 파일에서 읽는다(실행 없음, 실제 컴파일러 계산). 원본 IDA 디컴파일에서 그 필드를 쓰는 함수(이름과 본문 대응이 확인된 것)의 오프셋과 비교. 값마다 오프셋이 달라지는 필드만 근거로 쓴다.
4. 판정 상태는 22.1 과 같다(가설/확정). `06_reconstruction/config_options.tsv` 에 행 추가, `gen_config_headers.py` 로 생성(헤더 이름은 `conf/files` 의 `OPTIONS/<name>` 그대로). `meta_features.h` 에 자동 포함.
5. 회귀: 확정 목적 파일 3 개(`memcmp`, `kern_machdep`, `pagesize`)를 새 생성 헤더로 다시 빌드해 SHA-256 동일 확인. `pagesize.c` 는 전처리 결과에서 미정의 OPTIONS 가 사라졌는지도 확인.
6. 근거가 모이지 않는 옵션은 "미정" 으로 두고 생성하지 않는다 — 그 경우 그 옵션을 조건에 쓰는 헤더를 읽는 파일은 확정하지 않는다(20.3 규칙).

### 23.1 codex 교차검토(QA2: 오프셋 탐침) 판정 — 설계 변경, 헤더 판 차이 발견

내 검증: 인용 줄 30 여 곳을 Python 으로 열어 내용 확인, 원본 함수 2 개를 capstone 으로 역어셈블, 비트필드 폭을 Python 으로 합산, 기존 탐침 `08_build/runs/s1a-probes-kernel-2/src/c_layout.c:8–18` 확인.

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| `vm_page.h` 의 `OLD_VM_CODE` 비트는 비트필드라 `&` 로 못 잰다; 묶음 합 21/22, 10/13 비트, 각 묶음 끝 `:0` → 뒤 일반 필드 오프셋 불변 추정 | Python 합산 결과 `[21, 10]`(0) / `[22, 13]`(1) | ✅ → 비트필드만 바뀌는 경우는 오프셋 근거로 쓰지 않음(필요하면 마스크·시프트 비교) |
| 같은 구조체를 다른 옵션이 함께 바꾼다: `thread` 의 `MACH_FIXPRI`(`thread.h:152–153`), `MACH_IPC_COMPAT`(`:193`), `MACH_HOST`(`:239–240`), `NCPUS>1`(`:244`); `allocInProgress`(`:247`) 하나로는 교란 | 줄 확인 | ✅ → 같은 구조체에 영향을 주는 조건을 모두 나열하고, 이미 가설로 정한 값(S4-A1)을 고정한 상태에서만 비교, 여러 필드로 교차 확인 |
| **Darwin 구조체가 원본과 다르다**: 원본 `_vm_object_reference` 의 `inc word ptr [ecx+0x18]`(0x178c54, `66 ff 41 18`) vs Darwin `vm_object.h:115` `int ref_count`, `vm_object.c:270–278` `ref_count++` | capstone 역어셈블로 확인(함수 0x178c30, 잠금 `[ecx+0x10]`); `_vm_map_reference` 는 `inc dword ptr [ecx+0x30]`, 잠금 `+0x34`(0x1747a8) | ✅ **중요**: 원본 `vm_object.ref_count` 는 16 비트 — Darwin `vm/vm_object.h` 는 나중 판이다. VM 파일을 확정하려면 헤더도 D014 복원 수정이 필요해질 것 |
| `KR_OFF(t,f) ((unsigned long)&((t *)0)->f)` 상수 초기화는 S1-A 에서 이미 cc-744.13 이 받아들였다 | `c_layout.c:8–18`, 성공 기록 | ✅ → 탐침은 이 형태를 그대로 쓴다(`int` 캐스트 형태는 미검증이라 쓰지 않음) |
| 함수 대응·기준 포인터(`vm_map_to_entry`, `vm_map.h:208`)·접근 폭을 각각 확인해야 한다 | 줄 확인 | ✅ |
| 옵션별 일반 필드 신호: 있음(추정) `MACH_HOST`, `MACH_IPC_COMPAT`, `OLD_VM_CODE`; 없음 `MACH_IPC_DEBUG`, `MACH_PAGEMAP`(끝에 추가), `MACH_VM_DEBUG`, `NEW_VM_CODE`, `NORMA_TASK`(끝에 추가), `NORMA_VM`(형만) | 내 독립 전수 조사(구조체 안 조건부 선언)와 대조: 같은 필드 목록, 내 조사는 여러 줄 비트필드를 놓침(`vm_map.h:131–138`, `vm_object.h:201–205` 는 codex 쪽이 완전) | ✅ |
| `MACH_PAGEMAP=1` 탐침은 `vm/vm_external.h` 부재로 불가 | `ls` 로 부재 확인 | ✅ → 이 옵션은 함수 근거로만 |

설계 변경:
1. 오프셋 근거는 (a) 두 설정에 공통인 비트필드 아닌 필드, (b) 그 구조체에 영향을 주는 다른 조건을 모두 고정, (c) 원본 함수 대응·기준 포인터·접근 폭 확인, 세 조건을 모두 만족할 때만. **일치는 "그 소스·설정 조합을 지지" 로만 기록**하고, 구조체 판 차이(위 `ref_count`)가 있는 구조체에서는 그 차이가 설명된 뒤에만 쓴다.
2. 구조체 신호가 없는 6 옵션은 함수 본문 근거(IDA)로만 판정, 근거가 없으면 "미정".
3. 새 사실 기록: Darwin `vm/vm_object.h` 는 원본보다 나중 판(16 비트 `ref_count`). VM 계열 확정 전에 헤더 판 차이를 별도 조사한다(S5 의 VM 단계).

### 23.2 S4-A2 결과 (2026-10-01) — 옵션 6 개 가설, 5 개 미정, 헤더 판 차이 2 건

- 근거 도구 확장(`--options`, 기본값 출력 재현 자체 시험 통과): `09_validation/reconstruction/s4a2-option-evidence-20261001.*`, `s4a2b-option-evidence-20261001.*`.
- **내 검사 결함 발견·수정**: 20.3 의 미정의 검사는 `#if` 줄에 직접 쓰인 식별자만 봐서 매크로 안의 미정의(`kern/lock.h:66` `MACH_SLOCKS = (NCPUS > 1) || MACH_LDEBUG || DRIVERKIT`, `:81` `#if MACH_SLOCKS`)를 놓쳤다. 매크로 정의를 따라가는 `undef_conditionals.py` 를 만들어 다시 검사(`s5p4-undef-transitive-20261001.json`): `DRIVERKIT`·`MACH_LDEBUG` 가 추가로 드러남. `kern_machdep.c` 환경에는 표준·다른 아키텍처 매크로 외 미정의 없음.
- 오프셋 탐침 `s4a2-probe-3`(`DRIVERKIT=1`; `-1` 은 탐침이 포함한 `mach/mach_types.h` 를 스테이징 시작점에 넣지 않은 내 실수로, `-2` 는 `DRIVERKIT` 미정의로 잠금 필드가 사라져 실패 — 둘 다 기록으로 남김). 결과 `09_validation/reconstruction/s4a2-offset-probe-20261001.json`:
  - `OLD_VM_CODE=1` 일 때만 `vm_object` Lock 0x10·ref_count 0x18, `vm_map` ref_count 0x30·ref_lock 0x34 → 원본 `_vm_object_reference`(0x178c30)·`_vm_map_reference`(0x1747a8) 와 일치.
  - `thread.ith_mig_reply` 는 탐침 0xc0(COMPAT 0)/0xc4(COMPAT 1), 원본 `_mig_get_reply_port`(0x158f88) 는 `+0xbc` → **둘 다 아님: `thread` 구조체도 Darwin 과 판이 다름**(헤더 판 차이 2 건째, `vm_object.ref_count` 16 비트에 이어). `thread` 오프셋은 옵션 판정에 쓰지 않음.
- 판정(`06_reconstruction/config_options.tsv`, 근거 열 참조):
  - 가설: `MACH_IPC_COMPAT=1`(고유 함수·문자열 60), `MACH_IPC_DEBUG=1`(`_ipc_hash_info`, `_ipc_marequest_info`), `OLD_VM_CODE=1`(오프셋 2 구조체), `MACH_HOST=0`(`_pset_deallocate` 0x1616f0 이 `kern/processor.c:376–378` `#if !MACH_HOST` 분기 모양), `DRIVERKIT=1`(`conf/files:513–525` 의 `optional driverkit` 소스 11 개 경로가 원본에 있음, 함수 2), `NORMA_TASK=0`(`_task_create` 0x165a20 이 task.c 구간 안, `_task_create_local` 없음; `kern/task.c:76–78`).
  - 미정(생성 안 함): `NEW_VM_CODE`, `MACH_PAGEMAP`, `MACH_VM_DEBUG`, `NORMA_VM`, `MACH_LDEBUG` — 근거가 부재뿐이거나 없다. `gen_config_headers.py` 는 `undetermined` 행을 건너뛰도록 고침.
- 생성 헤더 6 개 추가(PROVENANCE 6 행). 옵션 값이 바뀌어 읽는 파일이 달라짐: `s4a2-regress-1` 은 `vm/vm_object.h:75` 가 요구한 `vm/vm_pager.h` 미채택으로 `pagesize.c` 컴파일 실패(+ 실패한 컴파일이 남긴 NFS `.nfs*` 파일로 manifest 가 깨져 collect 가 게시 거부). `s5p4-stage-2`·`s5p4-pre-2` 로 다시 스테이징·전처리 → 새로 읽힌 `vm/vm_pager.h` 1 개 채택(APSL+CMU). 남은 미정의는 미정 옵션 5 개와 비옵션 `MACH_USER_API`·`VM_OBJECT_DEBUG` 뿐.
- 회귀 `s4a2-regress-2`: `kern_machdep.o`·`memcmp.o`·`pagesize.o` 모두 확정본과 SHA-256 동일, `pagesize.i` 도 동일(`09_validation/reconstruction/s4a2-regress-20261001.json`).
- 규칙 보강: (1) 옵션 값을 바꾸면 확정 파일마다 스테이징→전처리→채택을 다시 한다(읽기 집합이 바뀐다). (2) 미정의 검사는 `undef_conditionals.py`(매크로 추적)로 한다.
- 다음 과제: (a) 헤더 판 차이(`vm_object`, `thread`) 조사 — VM·스레드 계열 파일 확정 전 필수, D014 복원 수정 대상이 헤더까지 넓어짐. (b) 미정 옵션 5 개는 그 옵션이 바이트에 영향을 주는 파일을 다룰 때 다시 판정.

## 24. S4-B 세부 계획 — 헤더 판 차이: 구조체 배치 복원, 시범 `struct vm_object` (코딩 전, 2026-10-01)

배경: 23.2 에서 Darwin `vm/vm_object.h` 와 `kern/thread.h` 의 구조체가 원본과 다름을 확인했다. VM·스레드 계열 파일을 확정하려면 원본 배치를 먼저 복원해야 한다(D014 를 헤더에 적용).

확인한 사실(원본 바이트, capstone; 계산 Python):
- `_vm_object_template`(0x1f7360, `__common`) 다음 심볼 `_vm_object_zone`(0x1f73b8)까지 88 B. Darwin 탐침(`OLD_VM_CODE=1`, `DRIVERKIT=1`) `sizeof(struct vm_object)` = 0x5c(92 B).
- `_vm_object_init`(Darwin `vm/vm_object.c:160` `vm_object_init`)이 템플릿을 Darwin `:196–213` 과 같은 순서로 초기화한다(`__text` 선형 스캔: 템플릿 범위 메모리 변위 참조 18 곳 모두 이 함수, 그 밖에 `__vm_object_allocate` 0x178bb6 의 즉시값 참조 1 곳 — 디코딩 불가 구간을 건너뛴 스캔이라 완전성 증명은 아님, 24.1). 짝지은 결과(원본 오프셋·폭): `ref_count` 0x18·16 비트, `resident_page_count` 0x1a·16, `size` 0x14·32, `paging_in_progress` 0x44·16(비트필드 0–15), `copy` 0x1c, `pager` 0x28, `pager_request` 0x30, `pager_name` 0x34, `paging_offset` 0x2c, `shadow` 0x20, `shadow_offset` 0x24, `last_alloc` 0x54, `policy` 0x48·16; 비트: `can_persist` 0x46 bit3(전체 bit19), `pager_ready` bit18, `internal` bit20, `pager_creating` 0x4a bit0 — Darwin 비트 순서와 같다. `last_alloc`+4 = 0x58 = 템플릿 크기.
- Darwin 과의 차이는 `ref_count`·`resident_page_count` 가 `int` → 16 비트(그 뒤 필드가 모두 −4)로 모두 설명된다(가설). 부호: `_vm_object_deallocate` 0x178cd3 `cmp word [esi+0x1a], 0` / `jle`(부호 있음) → `short`. `ref_count` 는 부호를 가리는 비교가 아직 없음.
- 참고(근거 아님, D013): NeXTMach `mk-108.1/vm/vm_object.h:83–84` 도 `short ref_count; short resident_page_count;` — 다른 필드 순서는 Darwin 과 다르다(`copy` 다음 `pager`).

설계:
1. **구조체 배치 표** `06_reconstruction/struct_layouts/<struct>.tsv`: 필드, Darwin 오프셋·폭(탐침), 원본 오프셋·폭, 근거(함수·주소·명령), 상태. 근거는 이름이 대응되는 원본 함수(외부 심볼)의 명령에서만 — 초기화 함수(템플릿)를 우선, 다른 접근 함수로 교차 확인(필드마다 2 곳 이상 목표).
2. **최소 수정 가설**: 차이를 설명하는 가장 작은 헤더 수정(여기서는 두 필드 `int`→`short`)을 세우고, **스테이징 사본**(07_kernel 아님)에 적용해 오프셋 탐침으로 모든 관측 필드의 오프셋·크기와 `sizeof`(0x58)가 원본과 같은지 확인한다. 탐침은 비트필드 대신 일반 필드만 재고, 비트 위치는 원본 마스크로 기록한다.
3. 통과하면 D014 복원 수정으로 `07_kernel/src/vm/vm_object.h` 를 고친다: 머리말 뒤 수정 주석, `07_kernel/MODIFICATIONS.md`, diff `06_reconstruction/evidence/x86-vm_object_h.diff`, PROVENANCE `changes` 갱신. `short` 의 근거(부호 비교)가 없는 필드는 그 사실을 기록.
4. 회귀: 확정 목적 파일 3 개 재빌드(바이트 불변 예상 — `pagesize.c` 는 `vm_object.h` 를 읽지만 코드가 의존하지 않음), 그리고 `undef_conditionals.py`.
5. 같은 방법을 `struct thread`(원본 `ith_mig_reply` +0xbc vs 탐침 0xc0) 에 다음으로 적용. 그 밖 구조체는 해당 파일을 다룰 때.
6. 한계: 이 방법은 원본이 실제로 접근하는 필드만 확인한다. 접근이 없는 필드의 존재·형은 "미확인" 으로 표시하고, 목적 파일 L1 일치가 최종 판정이다.

### 24.1 codex 교차검토(QB1: vm_object 배치) 판정

내 검증: 원본 명령 15 곳을 capstone 으로 다시 역어셈블해 내용·소속 함수 확인, Darwin `vm/vm_object.c` 인용 12 줄을 Python 으로 열어 확인.

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| init 대응표 재현(17 문장), `AL` 이 최초 바이트를 보존해 `0xf3` 은 `can_persist`+`pager_ready` 누적 마스크 | 0x178abc–0x178b0f 명령 확인(내 24 절 해석과 같은 비트) | ✅ (해석 보완: 마스크는 누적) |
| 크기 근거: `_vm_object_init` 0x1789ed `push 0x58` → `_zinit`(O:164 `sizeof(struct vm_object)`), `__vm_object_allocate` 0x178bbe `mov ecx, 0x16` + `rep movsd`(O:255 템플릿 복사), 심볼 거리는 패딩을 포함할 수 있음 | 명령·심볼(`0x16a490` = `_zinit`)·소스 줄 확인 | ✅ → 크기 근거 우선순위: zinit 인자·복사 길이 > 심볼 거리 |
| `ref_count` 부호: `_vm_object_coalesce` 0x179c6d `cmp word [esi+0x18], 1` / `jg`(O:1495 `ref_count > 1`) | 확인 | ✅ → `ref_count` 도 signed 16 비트 |
| 합쳐진 검사: `_vm_object_collapse` 0x179970 dword 읽기 `and 0x10ffff`/`cmp 0x100000`(O:1193–1194 `!internal || paging_in_progress != 0`) | 확인 | ✅ → dword 접근을 32 비트 필드로 해석하지 않는다 |
| 다른 함수 접근이 가설과 일치: `_vm_fault` 0x1720bb/0x1720bf, `_vm_object_terminate` 0x178d69/0x178d88/0x178dba, `_vm_object_deallocate` 0x178cf3(`cached_list` +0x4c/+0x50), `_vm_object_copy` 0x1793f0, `_vm_object_setpager` 0x17961b, `_vm_set_policy` 0x17a7ec, `_vm_page_alloc_sequential` 0x17b467/0x17b47b(`policy`, `last_alloc`), `_vm_pageout_scan` 0x179f4a | 각 명령 확인(표본 전부), 소속 함수 확인 | ✅ |
| 템플릿 참조 개수: 메모리 변위 18(모두 init) + 즉시값 1 | 내 스캔 출력과 같음 — 내 문구("19 곳 — 18 곳") 가 부정확 | ✅ 문구 수정(24 절) |
| 미확인: `copy_strategy`(+0x38)·`absent_count`(+0x3c)·`all_wanted`(+0x40) 와 초기화되지 않는 비트(`pager_created` 등)의 이름·순서, `pager_request`/`pager_name` 구별 | 내 표에도 근거 없음 | ✅ → 배치 표에 "미확인" 으로 표시 |

결론: 관찰한 원본 접근은 "Darwin 배치에서 두 count 를 signed `short` 로 바꾼 것" 과 모두 일치, 반례 없음. 접근이 없는 필드는 미확인으로 둔다.

### 24.2 S4-B 결과 (2026-10-01) — `struct vm_object` 헤더 복원 수정

- 탐침 `s4b-vmo-1`: 스테이징 사본(`08_build/runs/tools/s4b-vmo-stage-1`)의 `vm/vm_object.h` 에서만 두 필드를 `short` 로 바꾸고 일반 필드 19 개 오프셋과 `sizeof` 를 잼(`09_validation/reconstruction/s4b-vmo-probe-20261001.json`).
- 배치 표 `06_reconstruction/struct_layouts/vm_object.tsv`: 원본 접근이 있는 15 항목(`sizeof` 0x58, `Lock`, `size`, 두 count(16 비트), `copy`, `shadow`, `shadow_offset`, `pager`, `paging_offset`, `pager_request`, `pager_name`, `cached_list`, `last_alloc`) **모두 일치, 불일치 0**. `memq`, `object_list`, `copy_strategy`, `absent_count`, `all_wanted` 는 원본 접근을 찾지 못해 **미확인**. 비트 위치(`can_persist` bit19, `pager_ready` bit18, `internal` bit20, `pager_creating` +0x4a bit0)는 원본 마스크로 기록(24·24.1).
- D014 복원 수정: `07_kernel/src/vm/vm_object.h` 의 두 줄 `int` → `short` + 머리말 뒤 수정 주석(APSL·CMU 표기 유지). `07_kernel/MODIFICATIONS.md` 행, diff `06_reconstruction/evidence/x86-vm_object_h.diff`, PROVENANCE `changes` 갱신. 수정 후 SHA-256 `a43eb11ca6b73ba73269eec4776601e4d7a06070a6de74626c811376cb51e24d`.
- 회귀 `s4b-regress-1`: 확정 목적 파일 3 개 SHA-256 동일, `pagesize.i` 에 수정 반영 확인(`09_validation/reconstruction/s4b-regress-20261001.json`).
- 다음: `struct thread`(원본 `ith_mig_reply` +0xbc, Darwin 탐침 0xc4 — `MACH_IPC_COMPAT=1` 가설 기준 −8) 에 같은 방법.

## 25. S4-B2 세부 계획 — `struct thread` 배치 복원 (코딩 전, 2026-10-01)

확인한 사실(원본 바이트·capstone, Darwin 탐침 `s4b-thr-1` = 현재 생성 옵션 + Darwin `kern/thread.h` 그대로, 62 필드; 계산 Python):
- 크기: `_thread_template`(0x1f6c00)~`_thread_zone` 396 B(0x18c), Darwin 탐침 `sizeof` 0x194 → −8.
- `_thread_init`(0x166a8c) 의 템플릿 쓰기 35 곳(메모리 변위 33 + `timer_init` 인자 즉시값 2)을 Darwin `kern/thread.c:355–424` 문장 순서와 짝지음:
  - 같음(Darwin 오프셋 그대로): `runq` 0x08, `ref_count` 0x24, `pcb` 0x28, `kernel_stack` 0x2c, `stack_privilege` 0x30, `swap_func` 0x34, `exc_func` 0x38, `wait_event` 0x3c, `wait_result` 0x44, `wake_active` 0x48, `state` 0x4c(=0x102), `unix_lock` 0x88(=−1), `user_stop_count` 0x8c(=1).
  - −4: `max_priority` 0x54(D 0x58), `sched_data` 0x5c, `policy` 0x60, `depress_priority` 0x64, `cpu_usage` 0x68, `sched_usage` 0x6c(D 0x70). 0x74–0x80 의 0 쓰기 4 개는 Darwin 문장 순서와 맞지 않음(원본 소스 순서가 다를 수 있음) → 개별 판정 보류.
  - −8: `user_timer` 0xe0(D 0xe8), `system_timer` 0xf0, timer_save 4 워드 0x100–0x10c, `cpu_delta` 0x110, `sched_delta` 0x114, `active` 0x178, `ast` 0x17c, `bound_processor` 0x184, `allocInProgress` 0x188.
- `_ipc_thread_init`(0x15961c, Darwin `kern/ipc_tt.c:239–`): `ith_next` 0x90·`ith_prev` 0x94(같음), `ith_messages` 0xa4, `ith_lock_data` 0xa8, `ith_self` 0xac, `ith_sself` 0xb0, `ith_exception` 0xb4, `ith_reply` 0xb8(COMPAT 분기 있음), `ith_mig_reply` 0xbc, `ith_rpc_reply` 0xc0 — 모두 −8. 따라서 −8 은 0x98–0xa4 구간: Darwin 은 `ith_state`, `ith_rcv_option`, `ith_list`, `data`, `ith_seqno`(20 B), 원본은 12 B.
- 정황(근거 아님): Mach4 `kernel/kern/thread.h:144–150` 은 그 구간이 `ith_state`, `data`, `ith_seqno` 3 개(12 B). NeXTMach `mk-108.1/kern/thread.h:225–228` 은 `_uthread` 대신 `struct u_address { struct uthread *uthread; struct utask *utask; } u_address;`(8 B).
- Darwin 에서 문제의 필드를 쓰는 곳: `wait_mesg` 는 `bsd/kern/kern_synch.c` 의 `_sleep`(79–185, 원본 심볼 `__sleep` 없음), `ith_rcv_option`·`ith_list` 는 `ipc/ipc_mqueue.c`(원본 `_ipc_mqueue_receive` 0x14acd4 등), `_uthread` 는 13 파일.

가설 H-thr(최소 수정 후보):
1. `char *wait_mesg;` 없음(−4).
2. `_uthread` 자리가 8 B(+4) — 형·이름 미정. 후보: (a) `_uthread` 뒤에 4 B 필드 1 개, (b) NeXTMach 식 `u_address` 구조체. Darwin 코드가 `->_uthread` 를 쓰므로 (a) 가 Darwin 소스와의 차이를 최소화하나, 이름 없는 필드를 만들어 넣는 것은 근거가 필요.
3. `ith_rcv_option`, `ith_list` 없음(−8).

설계(24 와 같은 절차 + 추가 조건):
1. 근거 수집(IDA·capstone, 이름 있는 원본 함수만): (a) `priority` 0x50·`sched_pri` 0x58 류의 −4 영역 필드를 쓰는 함수(예 `_compute_priority`, `_thread_priority`), (b) 0x80/0x84 를 쓰는 함수(→ `_uthread` 와 두 번째 4 B 의 정체; BSD 쪽 `current_thread()->_uthread` 사용 함수), (c) `ith_state` 0x98·`ith_kmsg`/`ith_msize` 0x9c·`ith_seqno` 0xa0 를 쓰는 `_ipc_mqueue_receive`/`_mach_msg_trap` 계열, (d) `sleep_time`·`recover`·`vm_privilege` 의 실제 오프셋.
2. 가설을 스테이징 사본에 적용해 탐침, 배치 표 `06_reconstruction/struct_layouts/thread.tsv`(필드마다 원본 근거 2 곳 이상 목표, 없으면 미확인).
3. 필드 **삭제**는 "그 필드를 쓰는 Darwin 함수가 원본에 없거나 다른 판" 이라는 근거와 함께만 한다. 2 번의 이름 없는 필드는 원본 접근이 그 필드의 쓰임을 보여줄 때만 넣고, 근거가 없으면 이 절의 수정을 보류한다(빈 자리 채우기용 가짜 필드 금지).
4. 헤더 수정은 그 필드를 쓰는 Darwin 소스(`kern_synch.c`, `ipc_mqueue.c` 등)의 컴파일을 깨뜨린다 — 이 파일들은 아직 채택하지 않았고, 다룰 때 원본 판에 맞춰 복원한다(D014). 확정 목적 파일 3 개는 회귀로 확인.

### 25.1 codex 교차검토(QB2: struct thread) 판정 — 내 가설 H-thr 일부 기각, H-thr2

내 검증: codex 가 인용한 원본 명령 16 곳을 capstone 으로 다시 역어셈블(소속 함수·호출 대상 확인), Darwin `kern/thread.c` 495·783·740–744·390–391·1640–1643, `kern/sched_prim.c` 1192, NeXTMach `kern/thread.c` 588–591·923–926 을 열어 확인. 독립 확인으로 `_thread_priority`·`_compute_my_priority` IDA 디컴파일, IPC 함수 3 개의 `+0x98/+0x9c/+0xa0` 접근 전수 목록.

| 주장 | 내 검증 | 판정 |
|---|---|---|
| **내 H-thr (2) 오류**: `0x84` 는 `_uthread`(단일 포인터), `0x80` 은 VM 객체 포인터, `0x7c` 는 커널 매핑 주소 | `_thread_create` 0x166cd0 `zalloc` 결과 → `+0x84`(Darwin thread.c:495), `_thread_deallocate` 0x16715f `+0x84` → `_uthread_free`(:783), 0x1670d2 `+0x80` → `_vm_object_deallocate`, 0x1670b4 `+0x7c` → `_kmem_free`; `_uthread_from_thread` 0x107a6c `+0x84` | ✅ 내 가설(NeXTMach `u_address` 8 B) 기각. 내 `_getpid` 해석("utask")도 틀림 — `+0x84` 는 `_uthread` |
| `sleep_time` 없음: `_thread_info` 0x1682e4 와 `_update_priority` 0x163dd4 가 `sched_tick − sched_stamp(+0x70)` 를 계산(Darwin thread.c:1640–1643 은 `thread->sleep_time` 을 읽음) | 명령·`_sched_tick`(0x1f653c) 확인 | ✅ |
| `recover` 0x74(`_copyin` 0x189a6a/0x189b1d, `_copyout` 0x189d03), `vm_privilege` 0x78(`_vm_pageout` 0x17a0b3, `_vm_page_alloc_sequential` 0x17b25e) | 확인 | ✅ |
| 크기: `_thread_init` 0x166aa0 `push 0x18c` → `_zinit` | 확인 | ✅ |
| IPC 구간 `ith_state` 0x98·`data` 0x9c·`ith_seqno` 0xa0·`ith_messages` 0xa4 → `ith_rcv_option`·`ith_list` 없음 | 내 전수 목록과 같음 | ✅ |
| 0x7c/0x80 의 원래 이름 후보 `tmp_address`/`tmp_object` 는 NeXTMach `thread.c:588–591, 923–926` 에만 있음 | 확인 — 역할은 원본 바이트로, **이름은 NeXTMach 에서만** | ⚖️ 이름은 미확정(D013 문제) |
| `_sendsig` 0x193508 `lea ebx,[eax+0x84]` 는 pcb 경유라 근거에서 제외 | — | ⏭️ 근거로 쓰지 않음 |

H-thr2(스테이징 사본에만 적용, `s4b-thr-2`): Darwin 에서 `wait_mesg`·`sleep_time`·`ith_rcv_option`·`ith_list` 제거, `vm_privilege` 뒤에 4 B 필드 2 개(`vm_offset_t`, `struct vm_object *`; 탐침에서는 중립 이름 `probe_7c`/`probe_80`). 결과(`09_validation/reconstruction/s4b-thr2-probe-20261001.json`, 표 `06_reconstruction/struct_layouts/thread.tsv`): 원본 근거가 있는 52 항목(`sizeof` 0x18c 포함) **모두 일치, 불일치 0**; 미확인 9(`links`, `task`, `thread_list`, `pset_threads`, `suspend_count`, `saved`, `timer`, `depress_timer`, `processor_set`).

남은 결정(사용자): 0x7c/0x80 두 필드의 이름. 역할은 원본으로 확인되지만 이름은 NeXTMach 에서만 알 수 있어 D013(NeXTMach 유래 텍스트 비공개)과 충돌한다. 결정 전에는 `07_kernel/src/kern/thread.h` 를 고치지 않는다.

관련 발견(전략): 원본 `_getpid`(0x107ac8)는 4.3BSD 식(`_uthread` 의 반환값 칸 +0x60/+0x64 에 16 비트 pid 를 씀)이고 Darwin `bsd/kern/kern_prot.c:100` 의 4.4BSD 식(`*retval = p->p_pid`)과 다르다. 원본 BSD 계층은 Darwin 보다 NeXT 이전 판에 가까울 가능성이 크다 — 참고 소스 선택(D013)에 영향.

### 25.2 S4-B2 결과 (2026-10-01) — `struct thread` 헤더 복원 수정, D013 변경

- 사용자 결정: D015(0x7c·0x80 필드 이름은 NeXTMach `tmp_address`·`tmp_object`), **D013 변경**(NeXTMach 유래 코드도 출처 기록과 함께 공개 커밋 가능, 라이선스 판단은 사용자). `02_plan/DECISIONS.md`, `AGENTS.md` 반영.
- D014 복원 수정 `07_kernel/src/kern/thread.h`: `wait_mesg`·`sleep_time`·`ith_rcv_option`·`ith_list` 삭제, `vm_privilege` 뒤에 NeXTMach `mk-108.1/kern/thread.h:218–221`(커밋 `f6bdb9c3268f0eadc545d41bcc0564453b17001e`) 네 줄을 그대로 삽입, 머리말 뒤 수정 주석. diff `06_reconstruction/evidence/x86-thread_h.diff`, `07_kernel/MODIFICATIONS.md`, PROVENANCE(출처 두 개 기록). 수정 후 SHA-256 `3cfd6a91509328ecb1b2f5d204c70c40ef380a8909b3f5f7538dfd57b510976a`.
- 확인 `s4b-thr-3`(07_kernel 사본 + 탐침): 61 필드 오프셋·크기가 H-thr2 탐침과 모두 같음, `sizeof` 0x18c(`vm_object_t` 형은 `kern/task.h` → `vm/vm_map.h` → `vm/vm_object.h` 경로로 보임 — 컴파일 성공). 배치 표 `06_reconstruction/struct_layouts/thread.tsv`: 원본 근거 52 일치·불일치 0·미확인 9. 회귀: 확정 목적 파일 3 개 SHA-256 동일, 미정의 집합 변화 없음(`09_validation/reconstruction/s4b-thr3-20261001.json`).
- 이 수정으로 Darwin 의 `bsd/kern/kern_synch.c`(`wait_mesg`), `ipc/ipc_mqueue.c`(`ith_rcv_option`·`ith_list`), `kern/thread.c`·`kern/sched_prim.c`(`sleep_time`) 는 그대로는 컴파일되지 않는다 — 원본도 해당 코드가 다르다(25·25.1 근거). 해당 파일을 다룰 때 원본 판에 맞춰 복원한다.
- 전략 메모: 원본 BSD 계층(`_getpid` 4.3BSD 식 등)과 `thread` 의 `tmp_*` 필드는 NeXTMach 쪽 판에 가깝다. D013 변경으로 NeXTMach 를 후보 소스로 쓸 수 있으므로, 이후 파일마다 Darwin·NeXTMach 두 후보를 원본과 대조해 가까운 쪽을 고른다(새 계획에서 상세화).

## 26. S2-C 세부 계획 — 후보 소스 선택: Darwin 0.1 대 NeXTMach (코딩 전, 2026-10-01)

배경: D013 변경으로 NeXTMach(mk-108.1)도 커밋 가능한 후보가 됐다. 25.1·25.2 에서 원본 BSD 계층(`_getpid`)과 `struct thread` 일부가 NeXTMach 쪽에 가깝고, IPC(`ith_*`, `ipc_mqueue`)·`vm_object` 초기화 순서는 Darwin 쪽에 가깝다. 파일마다 어느 후보에서 시작할지 근거로 정해야 한다.

확인한 사실(Python): `06_reconstruction/function_candidates.tsv`(S2-B, 4,761 행) 의 1 위 후보 트리 — `darwin01` 1,882, `nextmach` 1,024, `darwin01-dk` 917, `mach4` 34; 신뢰도 medium 행만 보면 `nextmach` 477, `darwin01` 453, `darwin01-dk` 186, `mach4` 20. 그러나 표에는 **1 위 후보와 2 위 점수만** 있고 트리별 점수가 없어, 같은 함수에서 Darwin·NeXTMach 를 직접 비교할 수 없다.

설계:
1. `s2b_candidates.py` 에 `--detail OUT.tsv` 를 더한다: 모든 후보 행(원본 함수, 트리, 경로:줄, 이름, 호출 일치 Jc, 문자열 일치 Ks, 본문 해시). **기본 출력은 바뀌지 않아야 한다**(같은 입력으로 `function_candidates.tsv` 를 다시 만들어 바이트 비교 — 자체 시험).
2. 집계 `06_reconstruction/source_choice.tsv`: S2-A 구간(목적 파일 후보)마다 함수별로 Darwin 최고 점수와 NeXTMach 최고 점수를 비교해 (Darwin 우세, NeXTMach 우세, 동률, 한쪽만 후보) 개수와 판정을 낸다. 판정은 "우세 쪽이 다른 쪽의 2 배 이상이고 우세 함수 3 개 이상" 일 때만, 아니면 "혼합/미정". 점수 특징이 없는 함수(호출·문자열 0)는 세지 않는다.
3. 점수기 검증(쓰기 전 기준, 결과와 함께 기록): 이미 원본으로 확인한 사실과 맞아야 한다 — (a) `kern_machdep.c`·`memcmp.c`·`pagesize.c` 구간은 Darwin(NeXTMach 에 i386 판 없음), (b) `ipc/*` 구간은 Darwin(NeXTMach mk-108.1 에 `ipc/` 디렉터리가 없고 `ipc_mqueue_receive` 문자열도 트리 전체에 없음 — 확인함), (c) `_getpid` 가 속한 구간은 NeXTMach 우세 또는 혼합. 맞지 않으면 점수기를 고치기 전에 원인부터 기록한다.
4. 결과는 시작 후보의 우선순위일 뿐이다. 어떤 후보에서 시작하든 확정은 L1 일치로만, 차이는 D014 복원 수정으로.
5. 다음 시범(이 절 이후 별도 계획): NeXTMach 우세로 나온 작은 구간 하나를 골라, NeXTMach 헤더 환경(4.3BSD `user.h` 등)을 Darwin 커널 헤더와 어떻게 섞을지부터 계획한다.

### 26.1 codex 교차검토(QC1: 후보 소스 선택) 판정 — 설계 변경

내 검증: `s2b_candidates.py` 175–288 행을 읽음(점수식·정렬·출력), `corpus()` 56–64 행, NeXTMach 정의 5 개를 `srcdefs.find` 로 다시 찾음, `function_candidates.tsv` 10 행을 Python 으로 조회, 원본 `_gettimeofday`(0x10abb0) 역어셈블과 NeXTMach `bsd/kern_time.c:59–` 대조.

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| **내 계획 오류**: 점수기에는 Jc·Ks 가 없고 점수는 공유 특징의 idf 가중합(243 행) | 코드 확인 — 26 절의 "Jc, Ks" 는 16 절 초안 용어를 잘못 옮긴 것 | ✅ 수정: 상세 출력은 현재 가중 점수와 공유 특징을 그대로 낸다 |
| 기본 출력 보존: `rows` 에 열을 더하면 276 행 `rows[0].keys()` 때문에 기본 TSV 가 바뀐다; 상세는 240 행 묶기 전에 별도 목록으로 | 코드 확인 | ✅ |
| 비결정성: `os.walk` 미정렬(60 행), 이름 없는 함수 후보는 집합 순회(233–237 행), 동점은 입력 순서 유지 | 코드 확인 | ✅ → 바이트 비교 자체 시험은 같은 환경에서 변경 전후로; 결정성 수정은 별도 변경 |
| 동점은 트리 순서(Darwin 먼저)로 1 위가 정해짐 → "1 위 트리" 분포는 Darwin 쪽으로 기움 | 코드 확인(내 독립 판단과 같음) | ✅ 동점은 "판별 불가" 로 따로 센다 |
| 파서 누락: 함수 머리와 `{` 사이 `#ifdef NeXT/#else` 가 있는 NeXTMach 정의를 놓침 — `netinet/if_ether.c` 의 `arpwhohas`(212)·`arpresolve`(356)·`arpinput`(513)·`in_arpinput`(609), `bsd/vfs_bio.c` 의 `bflush`(799) | `srcdefs.find` 로 5 개 모두 MISSED 확인, `if_ether.c:212–218` 에 `#else NeXT` 확인 | ✅ → "후보 없음 ≠ 소스 없음". 파서 수정은 별도 단계(S2-A/S2-B 재실행과 변경 보고 포함) |
| 아키텍처·빌드 포함 필터 없음: NeXTMach `next/`(m68k), `stand/` 도 후보 | `corpus()` 는 `/ppc` 만 제외 | ✅ → 상세 행에 "i386 부적합/커널 밖" 표시 |
| **내 검증 기준 (a) 모순**: `memcmp`·`pagesize`·`kern_machdep` 함수는 원본 특징 가중치 0 → 투표로는 Darwin 판정이 나올 수 없음 | 6 함수 모두 `original_feature_weight` 0 확인 | ✅ → 소스 가용성·아키텍처 근거는 투표와 별도 열로 기록 |
| `_gettimeofday` 원본은 NeXTMach 식(`u.u_ap`·`u.u_error`, timezone 없음); 표에서는 9.532 동점 `conflicting`, Darwin 먼저 | 원본 0x10abb8–0x10abe0 (`[0x1e875c]`+0x24 인자, +0x68 바이트 오류 저장) 과 NeXTMach `kern_time.c:59–` 확인 | ✅ 투표가 ABI 차이를 놓치는 실례 |
| `kern_time.c` 구간: Darwin 우세 1, NeXTMach 1, 동점 8, 특징 0 4 | 상세 출력 구현 후 재현해 확인(아직 미확인) | ⚠️ 미확인 |
| "2 배·3 개" 규칙의 안전성 근거 없음 | 맞음 | ✅ 탐색 순서용 휴리스틱으로만 |

변경된 설계:
1. `--detail`: 후보마다(묶기 전) 원본 VA, 트리, 경로:줄, 이름, 본문 해시, **현재 가중 점수**, 공유 호출·문자열, 경로 분류(`next/`·`stand/` 등 i386 부적합/커널 밖). 기본 출력 바이트 동일 시험.
2. 집계는 함수마다 (Darwin 우세 / NeXTMach 우세 / 동점 / 한쪽만 후보 / 특징 0 / 부적합) 를 따로 세고, 구간 표에는 이 개수와 **ABI 반증 메모**(예: u 영역 사용 여부)를 함께 둔다. 판정 열은 "탐색 우선순위" 로 이름 짓고 안전성 주장을 하지 않는다.
3. 파서 수정(조건부 함수 머리)과 결정성 수정은 별도 단계로, 각각 변경 전후 S2-A·S2-B 차이를 보고한다.
4. **전략 결론(현재까지의 근거)**: BSD 계층(`_getpid`, `_gettimeofday`)은 NeXTMach 의 4.3BSD u 영역 방식, IPC 는 Darwin(NeXTMach 에 `ipc/` 없음), `struct thread`·`vm_object` 는 두 판의 혼합. 파일 단위로 후보를 정하되, u 영역 사용 여부 같은 구조적 반증을 우선한다.

### 26.2 S2-C 결과 (2026-10-01) — 탐색 우선순위 표(근거 아님)

- `s2b_candidates.py --detail`(후보 40,353 행, `09_validation/reconstruction/s2c-candidate-detail-20261001.tsv`; 상세 출력에 `\r` 이스케이프 누락을 한 번 고침). **자체 시험**: 같은 `PYTHONHASHSEED=0` 에서 수정 전 스크립트 출력과 수정 후 기본 출력(`--detail` 유무 둘 다)이 TSV·JSON 바이트 동일. 
- **비결정성 확인**: 저장된 `function_candidates.tsv` 는 시드 0 재실행과 4,764 행 중 106 행의 `top` 열만 다름(점수·신뢰도는 같음) — 이름 없는 함수 후보 순서가 문자열 집합 순회에 달림(233–237 행). 결정성 수정은 별도 단계(26.1 설계 3).
- 집계 `s2c_source_choice.py` → `06_reconstruction/source_choice.tsv`, `09_validation/reconstruction/s2c-source-choice-20261001.json`: 후보가 있는 원본 함수 3,857 — 특징 0 1,088, Darwin 만 1,387, NeXTMach 만 358, 동점 478, Darwin 우세 180, NeXTMach 우세 345, 양쪽 없음 21. 362 구간의 탐색 우선순위: NeXTMach 29, Darwin 16, 혼합/미정 317.
- 검증(26 절 기준, 26.1 에서 고친 기대치): IPC 계열 26 구간은 Darwin 우세 58·NeXTMach 우세 0 — NeXTMach 에 `ipc/` 없음과 일치. `kern_prot.c`(seq 24) 는 NeXTMach 우선 — `_getpid` 의 u 영역 ABI 근거와 일치. 확정 세 구간은 모두 특징 0 이라 "혼합/미정"(투표로는 판정 불가, 소스 가용성은 따로). `kern_time.c`(seq 31): 동점 8·NeXTMach 우세 1 은 codex 와 같고, 나머지 분류는 codex 수치(Darwin 우세 1·특징 0 4)와 함수 하나 차이 — 정의·경계 차이로 보이며 판정에 영향 없음(혼합/미정).
- 한계(26.1): 파서가 조건부 함수 머리를 놓쳐 "Darwin 만" 에 NeXTMach 누락분이 섞여 있다(예 `if_ether.c` 의 `arpresolve`). 파서 수정 뒤 다시 낸다.
- 다음: (1) 파서(조건부 함수 머리)·결정성 수정 → S2-A·S2-B·S2-C 재실행과 변경 보고, (2) NeXTMach 우선 구간 중 작은 것 하나로 NeXTMach 헤더 환경(4.3BSD u 영역) 시범 계획.

## 27. S2-D 세부 계획 — 정의 파서(조건부 함수 머리)·결정성 수정과 재실행 (코딩 전, 2026-10-01)

확인한 사실:
- 누락 형태(NeXTMach `netinet/if_ether.c:211–222`, `bsd/vfs_bio.c:798–806`): `#if NeXT` / 머리(ANSI 또는 K&R 선언 포함) / `#else NeXT` / 다른 머리 / `#endif NeXT` / `{`. 현재 `srcdefs.find`(53–90 행) 는 닫는 괄호 뒤~`{` 사이를 전처리 없이 보므로 두 번째 머리의 `(` 때문에 정의가 아니라고 판단한다.
- `srcdefs` 사용처: `s2a_objects.py`, `s2b_candidates.py`, `option_evidence.py`. 따라서 파서를 바꾸면 S2-A(구간), S2-B(후보), S2-C(우선순위), S4 옵션 근거가 모두 바뀔 수 있다.
- 비결정성: `s2b_candidates.py` 의 `corpus()` 는 `os.walk` 순서 그대로(60 행), 이름 없는 함수 후보는 문자열 집합 순회(233–237 행). 시드 0 재실행과 저장 표가 106 행의 `top` 에서 다름(26.2).
- S2-B 검증 값(`s2b-validation-20261001.json`: 양성 10/10, 음성 0.09 %, 변이 100 %)은 저장된 스크립트 없이 만든 것이라 같은 절차로 다시 낼 수 없다. 양성 표본의 정답은 `10_tools/reconstruction/s1c/samples-1/provenance.json` 의 `samples[].reference`(Darwin 파일)·`functions`, 대상 함수 10 개는 `09_validation/reconstruction/s1c-options-20261001.json` 의 `qualified`.

설계:
1. **파서 수정**(`srcdefs.find`): 닫는 괄호 뒤 `{` 를 찾는 구간에서 전처리 지시문 줄은 코드로 보지 않고, `#else`/`#elif` 를 만나면 같은 깊이의 `#endif` 까지(그 사이의 다른 머리·K&R 선언 포함) 건너뛴다. 정의 시작은 첫 머리, 끝은 지금처럼 첫 0 열 `}`. 다른 규칙은 바꾸지 않는다.
2. **파서 회귀 시험**(`10_tools/reconstruction/test_srcdefs.py`): (a) 위 5 개 NeXTMach 정의가 찾아짐, (b) 세 참고 트리 전체에서 **수정 전 결과가 수정 후 결과의 부분집합**(이름·시작·끝 동일) — 빠지거나 범위가 바뀐 정의 0, (c) 새로 찾은 정의 수와 무작위 20 개 목록(사람이 검토할 수 있게 머리 줄 포함), (d) 프로토타입(`;` 로 끝남)이 새로 정의로 잡히지 않음.
3. **결정성 수정**: `corpus()` 의 디렉터리·파일 순회를 정렬, 이름 없는 함수의 `bases` 를 정렬해 순회. 동점 순서는 그대로(트리 순서) 두되 S2-C 는 동점을 따로 센다. 수정 후 서로 다른 `PYTHONHASHSEED` 두 개로 실행해 바이트 동일 확인.
4. **검증 스크립트** `s2b_validate.py`: 양성(10 함수의 최고 후보 묶음에 정답 Darwin 파일 포함), 음성(`--shuffle-negative` 의 이름 있는 medium 비율, 기준 2 % 이하), 변이(`--mutate-always-medium` 100 %). 수정 전 코드(사본)로 먼저 돌려 기존 JSON 값과 같은지 확인한 뒤 수정 후 값을 낸다.
5. **재실행과 변경 보고**: 순서 결정성 수정 → (보고) → 파서 수정 → (보고). 각 단계에서 S2-A(`objects.tsv`: 구간 수·경계·seq 변화), S2-B(행별 top·신뢰도 변화 수), S2-C(우선순위 변화), S4 근거(`option_evidence` 두 실행의 usable 행 변화 — 22·23 절 판정이 바뀌는지) 를 Python 으로 비교해 `09_validation/reconstruction/s2d-*` 에 남긴다. 계획 문서에 인용한 S2-A seq 번호(24·31·193·258 등)가 바뀌면 대응표를 남긴다.
6. 확정 항목(`objects_confirmed.tsv`, `functions.tsv` 의 `compared/high`)은 주소·소스 줄로 기록돼 있어 영향이 없어야 한다 — 소스 줄 인용을 다시 대조한다.

### 27.1 codex 교차검토(QD1: 파서 수정) 판정 — 설계 1 기각, 보수적 변형 A+B 채택

codex 는 내 설계 1(조건부 머리에서 `#else`~`#endif` 건너뛰기)을 메모리 안에서 모사해 반례를 냈다. 나는 `srcdefs.py` 사본으로 같은 실험과 대안 두 개를 직접 돌렸다(세 참고 트리 + driverkit, `.c/.m`, 비교 단위 (파일, 이름, 시작, 끝)).

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| 설계 1 은 기존 정의 17 개를 잃거나 이름·시작을 바꾼다(`rindex.c:65`, `ip_output.c:687`, NeXTMach `vm_resident.c:230`, Mach4 `ds_routines.c:91` …) — 원인은 앞 머리가 성공하면 `i = e + 1`(95 행) 로 뒤 머리를 다시 보지 않음 | 기존 총 16,030 개는 내 집계와 같음. 원인 코드 확인 | ✅ 설계 1 기각 |
| S2-B 는 `head` 가 아니라 원문 `lines[i:j+1]` 를 본문으로 써서 건너뛴 분기의 다른 머리(`rindex`, `ds_device_open`)가 호출 특징에 섞인다(72–78 행) | 코드 확인 | ✅ |
| 기존 종료 규칙(첫 0 열 `}`)의 결함: Darwin `vm_fault.c` 의 `vm_fault` 를 76–122 로 잘못 끝냄(122 는 `FREE_PAGE` 매크로) | `vm_fault.c:118–122` 가 `\` 연속 `#define` 의 `}` 임을 확인, 실제 끝 1169 | ✅ → 변형 B 로 고침 |
| `msdos-11/lowlevel.c:44` 의 `pc_cl2sector` 가 44–1144 로 과잉 포함 | 내 변형 A·A+B 에서도 48–1144 로 나옴 | ✅ 남은 한계로 기록(아래) |
| Mach4 `if_de6c.c:1729` `print_arp` 가 다른 분기의 `{`/`}` 를 이음 | 내 변형 A 에서 1729–1748 로 나옴 | ✅ 남은 한계(Mach4 i386at 드라이버, OPENSTEP 원본과 무관한 후보) |
| 현재 파서도 조건부 K&R 선언(`vm_map.c:2340`)은 통과, `kern_exit.c:397` `wait1` 은 놓침 | 변형 A 추가 목록에 `wait1` 397–526 이 있음 | ✅ |

내 대안 측정(Python):
- **변형 A**(머리 뒤~`{` 사이의 전처리 지시문 줄만 무시, `#else` 건너뛰기 없음): 16,030 → 16,064, **기존 손실 0**, 추가 34(목표 5 개 `arpwhohas` 219–337, `arpresolve` 366–504, `arpinput` 520–592, `in_arpinput` 616–875, `bflush` 803–830 포함 — 첫 머리가 아니라 `#else` 쪽 머리부터 잡힘). 앞 머리는 뒤 머리의 `(` 때문에 지금처럼 거부되므로 "첫 성공 머리" 의미가 유지된다.
- **변형 A+B**(B: 끝 `}` 탐색에서 전처리 지시문 줄과 그 `\` 연속 줄을 무시): A 와 같은 추가 + 기존 4 개 범위 교정 — Darwin `vm_fault_wire_fast` 1378–1399→1538, Mach4 같은 함수 1657–1678→1797, NeXTMach `vm_fault` 85–124→1186, `vm_fault_wire_fast` 1394–1415→1547; 모두 옛 끝이 매크로 `}` 였음(Darwin 1395–1399 가 `\` 연속 `#define` 확인). 새 `vm_fault` 83–1169.
- 남은 한계(이번에 고치지 않음, 기록): (1) 함수 닫는 `}` 가 0 열이 아니면 뒤 함수까지 이어진다 — 현재 결과에도 본문 안에 0 열 `{` 가 있는 정의가 511 개(예 `SCSIDiskKern.m` `sdopen` 169–1044). "0 열 `{` 거부" 보호 규칙은 기존 결과를 크게 바꿔 이번 범위에서 제외. (2) 줄 나누기 불일치: `s2a/s2b` 는 `splitlines()`, `option_evidence` 는 `split('\n')` — 참고 트리 51 파일에서 줄 수가 다르다(`\r`·`\f` 등). 줄 번호 인용 시 그 도구 기준임을 기록.

변경된 설계 1: 변형 A+B 를 `srcdefs.find` 에 적용. 회귀 시험(`test_srcdefs.py`): (a) 목표 5 개, (b) 기존 튜플 ⊆ 새 튜플 + 위 4 개 교정(사유 포함 허용 목록) 외 손실 0, (c) 추가 목록을 시험 출력에 저장, (d) 추가 정의의 머리가 `;` 로 끝나지 않음. 나머지 설계(결정성·검증·재실행·변경 보고)는 27 절 그대로.

### 27.2 S2-D 결과 (2026-10-01) — 파서·결정성 수정과 재실행

- 결정성(`s2b_candidates.py`: `os.walk` 디렉터리·파일 정렬, 이름 없는 함수 `bases` 정렬): `PYTHONHASHSEED` 1·987 실행 결과 TSV·JSON·상세 모두 바이트 동일. S2-A(`s2a_objects.py`)는 원래부터 결정적이며 재실행이 저장본과 바이트 동일.
- 검증 스크립트 `s2b_validate.py`: 수정 전 점수기 사본으로 저장 값 5 항목 모두 재현(양성 10/10, 음성 2/2,334, 변이 2,334/2,334, real_named 818/2,334, 전체 분포).
- 파서(`srcdefs.find`, 27.1 변형 A+B): `test_srcdefs.py` 4 시험 통과(`09_validation/reconstruction/s2d-srcdefs-test-20261001.json`) — 목표 5 개 찾음, 기준선 16,030 개 보존(매크로 끝 교정 4 개 제외), 추가 34 개(목록 저장), 프로토타입 추가 0. 기준선 `s2d-srcdefs-baseline-20261001.tsv`.
- 재실행과 변경 보고(`09_validation/reconstruction/s2d-change-report-20261001.json`; 이전 판은 `s2d-before-20261001/` 에 보존):
  - S2-A: 구간 362 그대로, 바뀐 구간 2 개(`ufs_subr.c` 시작 0x1429dc→0x142884, `ddm.c` 구간 표지에 `debugging.m` 추가). **seq 번호 변화 0** — 계획에 인용한 seq(6, 24, 31, 38, 76, 193, 258)는 그대로 유효. 신뢰도·후보 열 변화 0.
  - S2-B: 4,761 행 그대로. 신뢰도 변화 8 행(unknown→medium 3, low→medium 2, unknown→low 1, medium→low 2), `top` 변화 202 행(결정성 191 + 파서 11). 검증(`s2b-validation-20261001b.json`): 양성 10/10, 음성 1/2,338(0.04 %), 변이 100 %.
  - S2-C: 함수 3,857→3,861, 구간 우선순위 분포 그대로(NeXTMach 29, Darwin 16, 혼합/미정 317).
  - S4 옵션 근거(세 실행): usable 행 변화 0 → 22·23 절 판정에 영향 없음(기존 근거 파일 유지).
  - 확정 함수 6 개의 소스 줄 인용이 새 파서 결과와 모두 같음.
- 새 표: `06_reconstruction/objects.tsv`, `function_candidates.tsv`, `source_choice.tsv` 교체, 보고서 `s2a-objects-20261001b.json`, `s2b-candidates-20261001b.json`, `s2c-*-20261001b.*`.
- 남은 한계(27.1): 0 열이 아닌 닫는 괄호로 인한 과잉 범위(본문 안 0 열 `{` 가 있는 정의 511 개), 도구 간 줄 나누기 차이(51 파일).

## 28. S5-P5 세부 계획 — `vm_pager.c`: Darwin 바탕 + NeXTMach 구조 복원 (코딩 전, 2026-10-01)

고른 이유: S2-C NeXTMach 우선 구간 중 가장 작다(seq 211, 0x17a240–0x17a336, 246 B, 함수 6). 원본이 두 판의 **중간판**이라 D013 변경 후 첫 혼합 복원 시험이 된다. 헤더는 Darwin 환경 그대로 쓸 수 있다.

확인한 사실(원본 capstone, 계산 Python):
- 원본 함수: `_vm_pager_init` 0x17a240(빈 함수), `_vm_pager_get` 0x17a248, `_vm_pager_put` 0x17a284, `_vm_pager_deallocate` 0x17a2c0, `_vm_pager_allocate` 0x17a2f8, `_vm_pager_has_page` 0x17a308. 뒤 틈 0x17a336–0x17a338 `00`×2, **앞 틈 0x17a23e–0x17a240 은 `90 90`**(앞 구간 마지막 `jmp` 뒤) — 지금까지의 "목적 파일 사이 00" 관찰과 다름 → 경계 증명서 앞쪽은 성립하지 않을 수 있다(앞 목적 파일 끝의 채움일 가능성; 판정은 빌드 결과로).
- `_vm_pager_get`: `pager == 0` → `vm_page_zero_fill(m)`, `return 0`; `*pager`(is_device) ≠ 0 → `device_pagein(m)` 반환; 아니면 `vnode_pagein(m, error)`(`vm_pager_get(pager, m, error)` 가 인자 3 개, `vnode_pagein` 은 2 개 — **Darwin 시그니처**, `vm_pager.c:61–72`; `device_pagein` 에는 `m` 하나).
- `_vm_pager_put`: null → `panic("vm_pager_put: null pager")`(0x1e0cbc), device → `device_pageout(m)`, 아니면 `vnode_pageout(m)` — **NeXTMach 구조**(`mk-108.1/vm/vm_pager.c`, Darwin 은 `panic("vm_pager_put device")`).
- `_vm_pager_deallocate`: null → panic(0x1e0cd5), device → `device_dealloc(pager)`, 아니면 `vnode_dealloc(pager)` — NeXTMach 구조.
- `_vm_pager_allocate`, `_vm_pager_has_page`(panic 0x1e0cf5 `"vm_pager_has_page"`): 두 판 같음.
- 원본에 `"vm_pager_get device"`·`"vm_pager_put device"`·`"vm_pager_deallocate device"` 없음, NeXTMach `!MACH_XP` 분기의 `DUMMY(pager_data_provided …)` 심볼 없음, `_pager_cache` 없음 → NeXTMach 파일 그대로도 아니다.

설계:
1. 시작 후보: **Darwin `vm/vm_pager.c`**(헤더가 현재 환경과 맞고, 차이가 국소적). D014 복원 수정 4 곳: (a) `vm_pager_get` 앞에 `void vm_pager_init() {}`(NeXTMach `vm_pager.c` 의 정의를 그대로; D013), (b) get 의 device 분기 `panic(...)` → `return(device_pagein(m));`, (c) put 의 device 분기 → `return(device_pageout(m));`, (d) deallocate 의 device 분기 → `device_dealloc(pager); else` 형태(반환형은 바이트로 구별되지 않아 Darwin 의 `void` 유지 — 28.1). 각 수정에 원본 주소 근거를 MODIFICATIONS 에 기록.
2. 절차는 P4 와 같다: `stage_headers.py` 스테이징 → 진단 전처리(`undef_conditionals.py` 로 미정의 확인; 미정 옵션이 이 파일 코드에 영향을 주는지 판단) → 읽힌 헤더 채택 → 격리 재전처리 `.i` 동일 → 빌드(`-O2`, `-O3`, `-O4`) → L1(`--place-from-image`, Ghidra 몸체) → 경계 증명서.
3. **예측**(빌드 전 기록): `__text` 246 B, 함수 오프셋 0/8/0x44/0x80/0xb8/0xc8(Python 으로 원본 주소 − 0x17a240), 외부 참조 `_vm_page_zero_fill`·`_device_pagein`·`_vnode_pagein`·`_panic`·`_device_pageout`·`_vnode_pageout`·`_device_dealloc`·`_vnode_dealloc`·`_vnode_alloc`·`_vnode_has_page`, 문자열 3 개(`-fwritable-strings` 로 `__data`). 
4. 일치하지 않으면 R4(변형 3 회)·R5 를 따른다. 반환형(`void` 대 `boolean_t`)처럼 바이트로 구별되지 않는 선택은 Darwin 쪽을 유지하고 그 사실을 기록한다.
5. 앞 틈 `90 90` 의 해석은 결과와 함께 기록하고, 경계 증명서가 성립하지 않으면 목적 파일 등급은 A 가 아니라 "L1 일치, 경계 미증명" 으로 둔다.

### 28.1 codex 교차검토(QP5) 판정

내 검증: 원본 0x17a240–0x17a338 전체를 capstone 으로 직접 역어셈블(이번 세션), panic 뒤 세 곳(0x17a29d, 0x17a2d5, 0x17a322) 확인, Darwin `bsd/sys/systm.h:136–144`, `vm/vm_pager.h:46–50` 확인, `stage_headers.py --list vm/vm_pager.c`(로컬) 로 닫힘 72 파일 확인.

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| 네 수정으로 제어 흐름·호출 인자가 설명된다; `device_pagein` 인자는 `m` 하나, `vnode_pagein` 은 `error, m` 순 push | 0x17a269 `push eax`(m) → `_device_pagein`, 0x17a274–0x17a279 확인 | ✅ (계획 문구 보완) |
| `deallocate` 합류는 반환형을 구별하지 못한다(`put` 도 `return(x)` 인데 합류) | 확인 | ✅ 문구 수정 — Darwin `void` 는 후보 선택일 뿐 |
| panic 뒤에도 코드가 이어진다 → 컴파일 시 `panic` 이 비복귀로 선언되지 않았다; Darwin `bsd/sys/systm.h:140` 은 GNU 에서 `volatile void panic` | 세 곳 확인, `systm.h:140` 확인 | ✅ → **예측 추가**: `vm_pager.c` 닫힘에 `bsd/sys/systm.h` 가 없으므로(로컬 닫힘 목록) `panic` 은 암묵 선언 → 호출 뒤 코드 유지. 진단 전처리 `.i` 에서 `panic` 선언 유무를 확인 |
| 채움: 함수 사이·함수 안 모두 4 바이트 정렬 `90` | 역어셈블과 같음 | ✅ |
| 앞 틈 `90 90` 은 `_vm_pageout`(0x17a0a4) 끝 `jmp 0x17a1c4` 뒤; S2-A 경계는 함수 범위에서 계산한 것이라 목적 파일 경계의 증거가 아님 | 0x17a23c `eb 86` 확인, S2-A 코드 105 행 계산 방식 확인 | ✅ → 앞 경계는 미증명으로 둘 수 있음(설계 5) |
| Ghidra 가 panic 뒤 `add esp,4` 를 분석 조각으로 떼어 냄 → 몸체 범위만 보면 빠진다 | L1 범위는 함수의 몸체 블록 중 최대 끝까지라 조각을 포함함(내 범위 계산 방식) — 전체 `__text` 비교도 함께 함 | ⚖️ 사실, 이미 대응됨 |
| `is_device` 오프셋 0, `boolean_t` = `unsigned int`(i386) | `vm_pager.h:46–50` 확인 | ✅ |

진행 제약(2026-10-01): 사용자가 OPENSTEP 실기를 다른 세션에서 쓰는 동안 실기(gcds) 작업을 하지 않는다 — 스테이징·명령 파일까지 로컬에서 준비하고 전처리·빌드는 실기가 비면 한다.

### 28.2 S5-P5 결과 (2026-10-01) — 첫 혼합(Darwin+NeXTMach) 복원, `-O3` 증거

- 진단 전처리 `s5p5-pre-1`: 읽힌 48 파일, 채택 2(`vm/vm_pager.c`, `vm/vnode_pager.h`), `panic` 선언 없음(예측 적중), 남은 미정의는 미정 옵션·`VM_OBJECT_DEBUG` 뿐(이 파일 코드는 해당 구조체 필드를 쓰지 않음).
- 복원 수정(28 설계 1, 초안 그대로) → `07_kernel/src/vm/vm_pager.c`, diff `06_reconstruction/evidence/x86-vm_pager.diff`, MODIFICATIONS·PROVENANCE(NeXTMach `vm_pager.c:84` 출처 포함). 07_kernel 스냅샷 `.i` 는 진단 `.i` 와 의도한 두 수정(`vm_object.h` S4-B, 이 파일)만 다름.
- `s5p5-build-1`: `-O3`=`-O4` 동일, `-O2` 다름. `-O3` 예측 4 항목 적중. L1: `-O3`/`-O4` 6 함수 MATCH·OBJECT_MATCH(`__data` 0x1e0cbc L1d 검증), `-O2` 는 `get`·`put` DIFF → **원본 컴파일 옵션이 `-O3` 이상이라는 첫 증거**(13.3 의 보류 사항; Darwin `MASTER.i386:82` `-O3` 와 일치). 이후 공통 빌드 옵션은 `-O3`(libc 6 파일은 `Makefile.i386:82` 의 `-O4`).
- 경계: 뒤 `00`×2 통과, 앞 `90 90`(길이는 최소 채움, 값이 00 아님) → 목적 파일 등급 **A\***(README 에 정의 추가). 함수 6 개 `compared/high`(`vm_pager_init` 은 source_id `nextmach`).
- 남은 질문: 앞 목적 파일(`vm_pageout.c`)이 끝에 `90` 채움을 갖는 이유 — 그 파일을 다룰 때 확인.

## 29. S5-P6 세부 계획 — `ipc/ipc_thread.c`(Darwin 단일 후보) 와 스테이징 개선 (코딩 전, 2026-10-01)

고른 이유: Mach IPC 쪽 작은 구간(S2-A seq 150, 0x151be8–0x151cb9, 209 B, 함수 3). NeXTMach 에 `ipc/` 가 없어 후보는 Darwin 하나, 헤더는 현재 환경. `struct thread` 의 `ith_next`/`ith_prev` 를 써서 S4-B2 수정 헤더(`kern/thread.h`)를 처음 거치는 파일.

확인한 사실(원본 capstone, 계산 Python):
- 함수: `_ipc_thread_enqueue` 0x151be8, `_ipc_thread_dequeue` 0x151c24, `_ipc_thread_rmqueue` 0x151c70(오프셋 0, 0x3c, 0x88). 외부 호출·데이터 참조 없음. `ith_next` +0x90, `ith_prev` +0x94(배치 표와 같음).
- 동작이 Darwin `ipc/ipc_thread.c:90–148` 과 같고 `assert` 코드 없음(`MACH_ASSERT=0` 가설과 맞음).
- 앞 틈 0x151be6–0x151be8 `00`×2, 뒤 틈 0x151cb9–0x151cbc `00`×3 — 둘 다 4 바이트 정렬 최소 채움.

설계:
1. **스테이징 개선**: `stage_headers.py` 에 `--prefer-07` 을 더한다 — 닫힘의 파일이 `07_kernel` 에 같은 상대 경로로 있으면 그 파일(복원 수정본 포함)을 복사하고, manifest 에 출처를 `07_kernel/...` 로 적는다. 닫힘 계산은 지금처럼 Darwin 트리 기준(07_kernel 판에서 include 가 달라지지 않았음을 같이 확인: 두 판의 include 줄 집합 비교). 자체 시험: `--prefer-07` 없이 만든 스테이징과 파일 집합이 같고, 내용이 다른 파일은 07_kernel 에서 수정한 파일(`MODIFICATIONS.md` 목록)뿐.
2. 절차: 스테이징(`--prefer-07`) → 진단 전처리(`undef_conditionals.py`) → 채택 → 07_kernel 스냅샷 빌드(`-O3`, 대조 `-O2`·`-O4`) → `.i` 동일 확인(이제 수정 헤더 차이 없이 바이트 동일이어야 함) → L1 → 경계 증명서.
3. **예측**: `__text` 209 B, 함수 오프셋 0/0x3c/0x88, 재배치 0, 외부 심볼 0, `__data` 없음.
4. 일치하지 않으면 D014 R4·R5.

### 29.1 codex 교차검토(QP6: `--prefer-07`) 판정 — 설계 1 수정

내 검증: 07_kernel 전체를 Darwin 원본과 비교(Python: 내용이 다른 파일 4 개 = `MODIFICATIONS.md` 목록, include 줄이 다른 파일 0, 07 에만 있는 파일은 `.gitkeep` 4 개), `stage_headers.py` 20–45 행(`ROOTS` 첫 항목이 이미 `07_kernel/generated`, `staged_name()` 은 07 의 `src`·`components` 경로를 모름), `vm_external.h` include 가 Darwin `vm_object.h:79` / 07 판 `:81` 임을 grep 으로 확인.

| codex 주장 | 판정 |
|---|---|
| 현재 스냅샷·`ipc_thread.c` 에 한해 "Darwin 으로 탐색, 07 을 복사" 는 같은 닫힘을 낸다 | ✅(include 줄 차이 0 직접 확인) |
| 일반 기능으로는 부족: 07 판에서 include 가 바뀌거나 07 에만 새 헤더가 생기면 Darwin 기준 탐색이 놓친다; 따옴표 include 의 기준 디렉터리도 논리 경로여야 한다 | ✅ 설계 변경 |
| `staged_name()` 이 07 의 물리 경로를 지원하지 않아 "읽는 경로만 바꾸기" 로는 안 된다 | ✅(코드 확인) |
| 미해결 위치(`at`)가 Darwin 줄이면 복사본과 어긋난다(79 대 81) | ✅ → 실제로 읽은 파일 기준으로 기록 |
| manifest 최소 정보(조건·파일별 실제 원본과 해시·의존 관계·생성 입력) | ⚖️ 파일별 실제 원본·해시, Darwin 대응 해시(다르면), 미해결의 실제 위치, 옵션·루트 목록을 기록(의존 관계 전체 목록은 이번 범위 밖) |

변경된 설계 1: 닫힘을 **논리 경로**(`generated/…`, `src/…`, `components/…`)로 계산한다. 논리 경로마다 `--prefer-07` 이면 `07_kernel/<논리 경로>` 를 먼저, 없으면 Darwin 대응 경로를 고르고, **고른 파일의 내용으로** 재귀한다. 따옴표 include 는 포함한 파일의 논리 디렉터리를 먼저 본다. 루트 순서는 지금과 같다. 자체 시험: (a) 옵션 없이 기존 manifest(`s5p2-stage-1`, `s5p4-stage-2`, `s5p5-stage-1`)의 파일·출처·해시를 그대로 재현, (b) `--prefer-07` 로 `pagesize.c`·`vm_pager.c`·`ipc_thread.c` 닫힘이 옵션 없을 때와 논리 파일 집합이 같고, 내용이 다른 파일은 `MODIFICATIONS.md` 의 수정 파일뿐.

### 29.2 S5-P6 결과 (2026-10-01) — `ipc_thread.c` A, 스테이징 개선

- `stage_headers.py` 를 논리 경로 기준으로 다시 씀(29.1): 자체 시험 통과 — 옵션 없이 기존 manifest 3 개(`s5p2-stage-1` 28, `s5p4-stage-2` 134, `s5p5-stage-1` 72 파일, 미해결 목록 포함)를 그대로 재현, `--prefer-07` 은 `pagesize.c`·`vm_pager.c`·`ipc_thread.c` 닫힘에서 논리 파일 집합이 같고 내용 차이는 수정 파일(`thread.h`, `vm_object.h`, `vm_pager.c`)뿐.
- `s5p6-pre-1`: 읽힌 90 파일 중 89 가 07_kernel 과 동일, 채택 1. **07_kernel 스냅샷 `.i` 가 진단 `.i` 와 바이트 동일**(스테이징 개선 효과).
- `s5p6-build-1`: `-O2`=`-O3`=`-O4`, 예측 적중, L1 3 함수 MATCH·OBJECT_MATCH, 경계 증명서 통과(앞 00×2, 뒤 00×3) → `x86-ipc_thread` **A**, 3 함수 `compared/high`. 수정한 `struct thread` 를 거친 첫 확정 파일.

## 30. S5-P7 세부 계획 — libc `memcpy.c`·`memmove.c` 의 `bcopy` 위치 복원 (코딩 전, 2026-10-01)

확인한 사실(원본 capstone·Ghidra 함수표, 계산 Python):
- 원본 순서: `_memcmp`(끝 0x1013cb) → `00`×1 → `_bcopy` 0x1013cc → `_memcpy` 0x1013e4 → (0x101487 `90`) → `_bcopy16` 0x101488 → (틈 0) → `_ovbcopy` 0x1014ec → `_memmove` 0x101504 → 끝 0x1015fe → `00`×2 → `_bzero` 0x101600.
- 원본 `_bcopy` 는 `[ebp+0x10]`, `[ebp+8]`, `[ebp+0xc]` 순으로 push 해 **`_memcpy(dst, src, len)`** 을 호출(0x1013db). `_ovbcopy` 는 같은 모양으로 `_memmove` 호출(0x1014fb).
- Darwin `machdep/i386/libc/memmove.c` 는 `bcopy`(115–118)·`ovbcopy`(120–123)·`memmove` 를 정의하고 `bcopy` 도 `memmove` 를 부른다; `memcpy.c` 는 `memcpy`(101–134)·`bcopy16`(141–171)만, `memcpy` 프로토타입은 99 행.
- 해석(가설): 원본 판에서 `bcopy` 는 `memcpy.c` 에 있고 `memcpy` 를 부른다 → 목적 파일 두 개: **memcpy**(0x1013cc–0x1014ec, 288 B: `bcopy` 0, `memcpy` 0x18, `bcopy16` 0xbc; 내부 `90` 채움은 같은 목적 파일 안이라는 관찰과 맞음), **memmove**(0x1014ec–0x1015fe, 274 B: `ovbcopy` 0, `memmove` 0x18). S2-A seq 2·3 의 경계(0x101487)는 함수 범위 기반이라 목적 파일 경계라는 증거가 아님(30.1).
- 경계: memcpy 앞 `00`×1(최소 채움 1), memcpy 뒤·memmove 앞 0 바이트(이미 정렬), memmove 뒤 `00`×2(최소 채움 2).

설계:
1. D014 복원 수정 두 파일: (a) `memmove.c` 에서 `bcopy` 정의(115–118 행과 뒤 빈 줄) 삭제. (b) `memcpy.c` 의 `memcpy` 프로토타입(99 행) 뒤, `memcpy` 정의 앞에 `void bcopy(const void *src, void *dst, unsigned long ulen) { (void) memcpy(dst, src, ulen); }` 를 Darwin `memmove.c:115–118` 의 문체 그대로(호출 대상만 `memcpy`) 넣는다. 각 수정 근거: 원본 0x1013db·0x1014fb.
2. 절차: `stage_headers.py --prefer-07`(두 소스) → 진단 전처리 → 채택 → 07_kernel 스냅샷 빌드(libc 규칙 `-O4`, 대조 `-O3`·`-O4 -funroll-all-loops`) → `.i` 동일 → L1 → 경계 증명서(두 목적 파일 연속, 사이 틈 0).
3. **예측**: memcpy `__text` 288 B·함수 오프셋 0/0x18/0xbc·같은 목적 파일 안 호출이라 외부 재배치 없음(있다면 `_memcpy` 로컬 재배치 0 개 예상); memmove `__text` 274 B·오프셋 0/0x18·외부 참조 없음. 둘 다 `__data` 없음.
4. 일치하지 않으면 R4·R5.

### 30.1 codex 교차검토(QP7) 판정

내 검증: 원본 0x1013c8–0x1013f0, 0x1014e8–0x101508 역어셈블(이번 세션), 경계 바이트 4 곳, Darwin `memcpy.c:99`·`memmove.c:113–123` 확인.

| codex 주장 | 판정 |
|---|---|
| `_bcopy` → `_memcpy(dst, src, len)`(0x1013db), `_ovbcopy` → `_memmove`(0x1014fb) | ✅ 확인 |
| `_bcopy` 는 EAX, `_ovbcopy` 는 EDX 로 인자를 옮긴다 — 빌드에서 확인할 차이 | ✅ 사실(원인은 미확인) → 예측 항목에 추가 |
| 경계 바이트는 "목적 파일 2 개" 를 지지하지만 "3 개(`bcopy16` 별도)" 를 배제하지 못한다(0x101487 `90` 은 앞 목적 파일 끝 채움일 수도) | ✅ → **빌드로 판정**: `memcpy.c` 한 목적 파일이 0x101487 의 `90` 을 포함해 288 B 로 L1 일치하면 2 개 가설이 바이트로 확인된다 |
| 본문(`memcpy`, `bcopy16`, `memmove`)은 Darwin 과 대응, `bcopy` 이동 외 수정 근거 없음 | ⚖️ 소스–명령 대응은 합리적, 최종 판정은 L1 |
| `bcopy` 는 프로토타입(99 행) 뒤·`memcpy` 정의 앞에 — 가장 작은 변경 | ✅ 설계 그대로 |

### 30.2 S5-P7 결과 (2026-10-01) — `memcpy`·`memmove` A

- 두 소스는 include 가 없어 스테이징 2 파일, 채택 2(APSL). 복원 수정(`bcopy` 이동) diff `06_reconstruction/evidence/x86-memcpy_memmove.diff`.
- `s5p7-build-1`: 파일마다 `-O4`=`-O3`=`-O4 -funroll-all-loops`, 예측(크기·오프셋) 적중. L1 5 함수 MATCH, 두 목적 파일 OBJECT_MATCH, 경계 증명서 통과 → `x86-memcpy`·`x86-memmove` **A**, 5 함수 `compared/high`.
- 30.1 의 열린 질문 해결: 0x101487 의 `90` 은 memcpy 목적 파일 안 채움 → 목적 파일 2 개가 바이트로 확인. `_bcopy`(EAX)/`_ovbcopy`(EDX) 의 레지스터 차이도 추가 수정 없이 재현.

### 30.3 사고 기록 (2026-10-01) — `06_reconstruction/functions.tsv` 행 손실과 복구

- 원인(내 오류): 행 추가에 `open(f,'w').write(open(f).read() + …)` 를 썼다. 쓰기용 `open` 이 먼저 평가돼 파일을 비운 뒤 읽으므로 기존 내용이 사라진다. S5-P5(`vm_pager`), S5-P6(`ipc_thread`), S5-P7(`memcpy/memmove`) 세 번 실행돼 헤더와 앞선 15 행이 사라졌다(세션 기록 전수 검색: 이 패턴은 이 세 곳뿐, 모두 `functions.tsv`). `objects_confirmed.tsv`(추가 모드), PROVENANCE·MODIFICATIONS·계획 문서는 읽은 뒤 쓰거나 추가 모드라 영향 없음.
- 복구: 헤더는 `git show HEAD:06_reconstruction/functions.tsv`, 사라진 행은 파일 변경 때 세션에 남은 diff(삭제된 줄 원문)에서 그대로 복원 — memcmp·kern_machdep·pagesize 6 행, vm_pager 6 행(다음 diff 의 삭제 줄과 같음을 확인), ipc_thread 3 행 — 에 현재 memcpy·memmove 5 행을 더해 20 행. 검증: ID 중복 0, 열 수 모두 15, 20 행 모두 소스 줄 인용이 원본·수정본 줄과 일치(자동 대조), kern_machdep 의 `:88` 교정 유지. 손상된 판은 스크래치에 보존.
- 재발 방지: 표 갱신은 항상 "읽기 → 메모리에서 변경 → 쓰기" 또는 추가 모드로 하고, 갱신 뒤 행 수를 Python 으로 확인한다.

## 31. S5-P8 세부 계획 — libc `memchr.c`(그대로)·`memset.c`(뒷부분 삭제) (코딩 전, 2026-10-01)

확인한 사실(원본 심볼표·Ghidra·바이트, 계산 Python):
- `memchr`: `_memchr` 0x1012d0 = `__text` 시작, 몸체 끝 0x1012f9(41 B), 뒤 틈 `00`×3(최소 채움 3) 다음 `_bcmp`(memcmp 목적 파일, A). Darwin `machdep/i386/libc/memchr.c` 는 `memchr`(38–54) 하나, include 없음.
- `memset`: 0x101600–0x1019be(958 B), `_bzero` 0x101600·`_blkclr` 0x101618·`_memset` 0x101630(오프셋 0/0x18/0x30), 앞 틈 `00`×2(memmove 끝 0x1015fe, A 에서 확인), 뒤 틈 `00`×2(최소 채움 2) 다음 `_page_set`(pagesize, A). `_memset` 안에 Ghidra 분석 조각 다수(0x10183c–0x1018bd) — 전체 `__text` 비교로 확인.
- Darwin `memset.c`(338 줄)는 `bzero`(186)·`blkclr`(191)·`memset`(198–248) 뒤에 `#import <mach/mach_types.h>`·`<sys/errno.h>`(250–251), `set_recover`·`clear_recover`·`safe_bzero`·`safe_memset`(257–338)을 둔다. 원본에는 `_safe_bzero`·`_safe_memset`·`_set_recover`·`_clear_recover` 심볼이 없고(`set_recover`·`clear_recover` 는 `static inline`), memset 구간도 `_memset` 끝에서 끝난다 → 원본 판에는 249–338 행이 없다(가설; `safe_*` 는 나중 판에서 추가된 것으로 보임).

설계:
1. `memchr.c`: Darwin 원문 그대로 채택. `memset.c`: D014 복원 수정으로 249–338 행 삭제(머리말 뒤 수정 주석 추가) — 근거: 원본 심볼·구간.
2. 두 소스 모두 include 가 없게 되므로 스테이징·헤더 채택 없음. 07_kernel 스냅샷 빌드(`-O4`, 대조 `-O3`·`-O4 -funroll-all-loops`) + `-E`.
3. **예측**: memchr `__text` 41 B·외부 참조 0·재배치 0; memset `__text` 958 B, 함수 오프셋 0/0x18/0x30, `bzero`·`blkclr` 는 `_memset` 호출(재배치는 같은 목적 파일 안), `switch` 가 있으면 점프 표 재배치. 둘 다 `__data` 없음(문자열 없음).
4. L1(`--place-from-image`, Ghidra 몸체) + 경계 증명서. 일치하지 않으면 R4·R5.

### 31.1 codex 교차검토(QP8) 판정

내 검증: 0x1017b9 `jmp [eax*4+0x1017c0]`, 점프 표 3 개(0x101670 31 항목, 0x1017c0 31, 0x101900 29)의 모든 항목이 memset 구간 안을 가리킴(Python), 원본 `_mfs_trunc` 0x15e79f `call _bzero`, Darwin `kern/mapfs.c:43–45`(1997 년 mfs→mapfs 이름 변경 기록), 248 행까지 `mach_types.h` 형·`EFAULT`·`current_thread` 사용 없음(grep).

| codex 주장 | 판정 |
|---|---|
| `_memchr`·`_bzero`·`_blkclr`·`_memset` 이 Darwin 소스와 대응(인라인된 `simple_char_set` 두 사본, `MODULO_LOOP_UNROLL`, fall-through switch) | ⚖️ 대응은 합리적, 최종 판정은 L1 |
| 0x10183c–0x1018bd 는 두 번째 `simple_char_set` 의 switch 코드, 점프 표는 `__text` 안(세 개) | ✅ 점프 표 확인 → 예측: 목적 파일에 점프 표 항목 재배치(로컬)가 있다 |
| 248 행까지는 `#import <mach/mach_types.h>` 에 의존하지 않음 | ✅ |
| `nfs.h:795` 는 주석·상수일 뿐, 실제 호출은 `mapfs.c:696`; 원본에는 `mapfs_*` 대신 `_mfs_trunc` 가 있고 그 자리에서 **일반 `_bzero`** 를 호출(0x15e79f) | ✅ 내 근거("mapfs 심볼 없음")보다 강한 직접 근거 — `safe_*` 부재 판단 유지 |

### 31.2 S5-P8 결과 (2026-10-01) — `memchr`·`memset` A

- 채택 2(APSL), `memset.c` 249–338 행 삭제(MODIFICATIONS, diff `06_reconstruction/evidence/x86-memset.diff`). 두 소스 모두 include 없음.
- `s5p8-build-1`: 파일마다 세 옵션 동일, 예측(41 B; 958 B·오프셋 0/0x18/0x30) 적중, memset 재배치 96 = 점프 표 91 + 표 기준 3 + 호출 2.
- L1 4 함수 MATCH, OBJECT_MATCH 2, 경계 증명서 통과 → `x86-memchr`·`x86-memset` **A**, 4 함수 `compared/high`. 표 갱신 후 행 수 확인(functions 20→24 행, 30.3 의 재발 방지 규칙대로).
- 이로써 Darwin `Makefile.i386:78` 의 libc 6 파일(`memchr memcmp memcpy memmove memset pagesize`)이 모두 원본 바이트로 확정됐다(0x1012d0–0x101a0e 연속, 목적 파일 6 개 모두 A).

## 32. S5-P9 세부 계획 — libc 두 번째 묶음 11 파일(`-O4 -funroll-all-loops`) (코딩 전, 2026-10-01)

확인한 사실(원본 함수표·바이트, Darwin `conf/Makefile.i386:84–91`, 계산 Python):
- Darwin 규칙 `LIBC_UNROLL_SRC = strchr strrchr strlen strcpy strncpy strcat strncat strcmp strncmp index ffs`, `${KCC} $(COPTS) $(MACHINE_CFLAGS) -c -O4 -funroll-all-loops`. 링크 순서 `LDOBJS_PREFIX= $(LIBC_OBJ) $(LIBC_UNROLL_OBJ)`(:68) — 원본도 libc 6 파일(0x1012d0–0x101a0e, 모두 A) 바로 뒤에 같은 순서로 놓임.
- 원본 함수(시작, 크기 B): `_strchr` 0x101a10 41, `_strrchr` 0x101a3c 187, `_strlen` 0x101af8 77, `_strcpy` 0x101b48 117, `_strncpy` 0x101bc0 248, `_strcat` 0x101cb8 181, `_strncat` 0x101d70 265, `_strcmp` 0x101e7c 127, `_strncmp` 0x101efc 197, `_index` 0x101fc4 41, `_ffs` 0x101ff0 188. 함수 사이 틈은 모두 `00` 이고 길이가 4 바이트 정렬 최소 채움과 같음(`strncpy`→`strcat`, `ffs`→`_rpause` 는 0). 외부 호출·구간 밖 절대 참조 없음(capstone 전수).
- Darwin `machdep/i386/libc/<name>.c` 는 각각 함수 하나, include 없음(`srcdefs`). S1-C 에서 `strcpy`·`strcmp` 는 이미 몸체 일치 관찰.
- S2-A 는 이 구간을 seq 7–11 로 나눴고(seq 9·11 은 NeXTMach `next/libc.s` 표지로 묶임) — 함수 범위 기반 표지라 목적 파일 경계의 증거가 아님.

설계:
1. 11 파일 모두 Darwin 원문 그대로 채택(PROVENANCE 행), 수정 없음.
2. 07_kernel 스냅샷 빌드: 파일마다 `-O4 -funroll-all-loops`(Makefile 규칙), 대조 `-O4`·`-O3`, `-E` 1 개씩.
3. **예측**: 파일마다 목적 파일 `__text` 크기 = 위 원본 크기, 기호 1 개, 외부 심볼 0, `__data` 없음. 재배치는 점프 표가 있으면 그 수만큼(외부 0).
4. L1(`--place-from-image`, Ghidra 몸체) + 경계 증명서(앞뒤 틈이 연속 구간이라 이웃 목적 파일의 증명서와 공유). 일치하지 않는 파일은 원인을 기록하고(R4·R5), 일치한 파일만 확정한다.

### 32.1 codex 교차검토(QP9) 판정

내 검증: S1-C 산출물 `08_build/runs/s1c-matrix-2/out/s13__strcpy.o`·`s17__strcpy.o`·`s13__strcmp.o`·`s17__strcmp.o` 의 `__text` 를 원본과 직접 비교(s13 = `-O4`, s17 = `-O4 -funroll-all-loops`, `10_tools/reconstruction/s1c/samples-1/provenance.json:19,23`), 원본 `_index` 41 B 와 `_strchr` 41 B 바이트 비교.

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| 함수별 의미가 Darwin 소스와 맞고, 루프 본문이 8 번 반복(펼침), `strchr`·`index` 는 펼침 없음 | 개별 대조는 L1 로 판정 | ⚖️ 예측 근거로만 |
| `strcpy`·`strcmp`: `-O4` 는 43 B 로 불일치, `-O4 -funroll-all-loops` 는 117·127 B 로 원본 `__text` 일치 | 직접 비교: s13 43 B False, s17 117/127 B True | ✅ → 이 묶음의 옵션이 Makefile 규칙과 같다는 바이트 근거 |
| `index` 는 `strchr` 와 함수 전체가 같은 바이트 | 확인 | ✅ |
| 틈 `00`·최소 채움은 파일마다 목적 파일 하나와 양립; S1-C 의 여러 함수 목적 파일은 함수 사이를 `90` 으로 채움; 그러나 다른 분할을 완전히 배제하지는 못함 | 기존 관찰(함수 사이 90, 목적 파일 사이 00)과 같음 | ✅ 판정은 빌드 결과로(각 목적 파일 크기가 원본 함수 크기와 같은지) |

### 32.2 S5-P9 결과 (2026-10-01) — libc 두 번째 묶음 11 파일 A

- 11 파일 원문 채택(PROVENANCE 11 행), `s5p9-build-1` 44 명령 모두 종료 코드 0(`ffs.c:40` 내장 함수 형 충돌 경고만).
- 크기 예측 11/11 적중, 재배치·외부 심볼 0. L1: `-O4 -funroll-all-loops` 에서 11 목적 파일 OBJECT_MATCH, `-O4`·`-O3` 에서는 9 개 불일치(`strchr`·`index` 만 옵션 무관) → Makefile 규칙의 옵션이 바이트로 확인.
- 경계 증명서 11/11 통과 → 11 목적 파일 **A**, 11 함수 `compared/high`(표 행 수 확인: functions 24→35 행, objects 9→20).
- 누적: libc 17 파일(0x1012d0–0x1020ac 연속)이 모두 원본 바이트로 확정.

## 33. S5-P10 세부 계획 — `kern/timer.c`(옵션 `STAT_TIME`·`NCPUS` 확정 시험) (코딩 전, 2026-10-01)

고른 이유: Mach 쪽 작은 구간(S2-A seq 197), 코드가 `STAT_TIME` 분기와 `NCPUS` 크기 배열에 직접 의존 → 일치하면 S4-A1 가설 두 개를 **확정**으로 올릴 수 있다(22.1 의 확정 조건).

확인한 사실(원본, 계산 Python):
- 목적 파일 0x16a198–0x16a35e(454 B): `_init_timers` 0, `_timer_init` 0x34, `_timer_normalize` 0x5c, `_timer_read` 0x94, `_thread_read_times` 0xe8, `_timer_delta` 0x174. 앞 틈 `00`×2·뒤 틈 `00`×2(최소 채움). 뒤의 `FUN_0016a360` 은 `00 00` 뒤에 있고 끝에서 `_zinit` 까지 `90 90 90`, 호출자 0x16ae29(zalloc 구간) → zalloc.c 의 정적 함수(이 목적 파일 아님).
- Darwin·NeXTMach `kern/timer.c` 는 같은 함수 목록; 원본에 없는 `start_timer`·`time_trap_*`·`time_int_*`·`timer_switch` 는 소스에서 `!STAT_TIME` 분기 → `STAT_TIME=1` 과 맞음.
- 외부 참조: 호출은 `_timer_init`(같은 파일), 절대 참조는 `_current_timer` 0x1f6d9c(4 B)·`_kernel_timer` 0x1f6da0(16 B) — 둘 다 이 파일이 정의(`timer.c:49–50`, `timer_t current_timer[NCPUS]`, `timer_data_t kernel_timer[NCPUS]`), 원본 `__common` 에서 연속, 크기가 `NCPUS=1` 과 맞음(`struct timer` 16 B). `-fno-common` 의 미초기화 전역은 목적 파일의 `__DATA,__common` zero-fill 섹션(11.2 도구 사실).
- 헤더: `sys/param.h`, `sys/kernel.h`, `bsd/machine/cpu.h`(Darwin 4.4BSD 판) 를 읽는다 — 이 파일 코드가 BSD 구조체를 쓰는지 전처리 결과로 확인.

설계:
1. 시작 후보 Darwin(헤더 환경 준비됨; NeXTMach 판은 `sys/` 헤더 경로가 달라 이번에는 대조용). 원문 그대로 채택.
2. 절차: `stage_headers.py --prefer-07` → 진단 전처리(`undef_conditionals.py`) → 채택 → 07_kernel 빌드(`-O3`, 대조 `-O2`·`-O4`) → `.i` 동일 → L1(`__common` 배치 포함) → 경계 증명서.
3. **예측**: `__text` 454 B, 함수 오프셋 위와 같음, 목적 파일 `__common` 20 B(`current_timer` 4 + `kernel_timer` 16), 외부 심볼 없음(전부 정의), 재배치는 `__common` 참조와 `timer_init` 호출.
4. 일치하면 `06_reconstruction/config_options.tsv` 의 `STAT_TIME`·`NCPUS` 상태를 `confirmed` 로(근거: 이 목적 파일 L1), 생성 헤더 내용은 그대로(`--check`). 일치하지 않으면 R4·R5.

### 33.1 codex 교차검토(QP10) 판정

내 검증: Darwin `timer.c:49` 와 NeXTMach `timer.c:92` 부터 파일 끝까지 줄 단위 동일(Python), 원본 0x16a1b8–0x16a1be(`inc ebx; add esi,0x10; test ebx,ebx; jle`) 확인.

| codex 주장 | 판정 |
|---|---|
| 6 함수가 Darwin `STAT_TIME` 분기 소스와 대응(`timer_normalize` 제수 1,000,000, `thread_read_times` 의 `+0xe0`/`+0xf0` 은 복원한 `thread.h` 와 맞음, `TIMER_ADJUST` 는 `STAT_TIME` 분기에서 `#undef`) | ⚖️ 대응은 합리적, 최종은 L1 |
| `init_timers` 는 펼쳐지지 않은 1 회 루프(`jle` 로 i≤0 재시도) | ✅ 확인 |
| Darwin·NeXTMach 본문은 전역 정의부터 끝까지 동일 → 이 파일로는 판을 가를 수 없음 | ✅ 확인 → 후보 선택은 헤더 환경으로만 의미 |
| `#if STAT_TIME` 은 0/비영만 구별 → 확정은 "비영" 이며 값 1 은 불리언 옵션 전제 | ✅ → 표에 "confirmed (nonzero; boolean option)" 로 적는다 |
| `__common` 은 zero-fill 이라 파일 바이트로 크기 검증 불가 — 목적 파일의 zero-fill 섹션 크기·심볼 오프셋과 원본 심볼 간격으로 비교해야 | ✅ 예측 3 을 그렇게 판정 |
| `STAT_TIME=0` 대조 빌드는 Darwin i386 헤더에 `TIMER_HIGH_UNIT` 정의가 없어 성립하지 않을 수 있음 | ⏭️ 대조 빌드는 하지 않음(확정 근거는 일치 쪽만 사용) |

### 33.2 S5-P10 중단 (2026-10-01) — BSD 헤더 환경 공백

- `s5p10-stage-1`(`--prefer-07`, 136 파일, 미해결 13) → 진단 전처리 `s5p10-pre-1` 실패: `src/src/bsd/sys/param.h:106: machine/limits.h: No such file or directory`(두 명령 모두 종료 코드 1; collect 는 NFS 임시 파일로 manifest 가 깨져 게시 거부 — 메모리의 증상 그대로).
- Darwin `kernel/bsd/machine/` 에는 `limits.h` 가 없다(`architecture/i386/limits.h`, `bsd/include/limits.h` 만 있음). Darwin 빌드는 이것을 시스템(Rhapsody `System.framework`) 헤더로 풀었을 것으로 보인다(추정).
- 실기 OPENSTEP 4.2 의 `/NextDeveloper/Headers` 에는 `limits.h` 가 `ansi/{,i386,m68k,sparc,hppa,machine}/limits.h` 에만 있고 `bsd/machine/` 에는 없다(읽기 전용 조회). Darwin 4.4BSD 판 `sys/param.h` 의 `<machine/limits.h>` 요구는 원본 시대의 NeXT BSD 헤더 배치와 맞지 않는다.
- `timer.c` 는 `sys/param.h`·`sys/kernel.h`·`bsd/machine/cpu.h` 를 읽기 때문에 처음으로 BSD 헤더 환경에 걸렸다. 빈 헤더·경로 끼워 넣기 같은 우회는 하지 않고 P10 을 멈춘다(채택한 파일 없음, 07_kernel 변경 없음).
- 다음: S4-C 계획 — BSD 헤더 환경(Darwin 4.4BSD 판 대 NeXTMach 4.3BSD 판, i386 기계 의존 헤더의 출처)을 원본 근거로 정한다. 그 전까지 BSD 헤더를 읽는 파일은 진행하지 않는다.

## 34. S4-C 조사와 S5-P11 세부 계획 — BSD 헤더 공백의 범위, `kern/mach_factor.c` (코딩 전, 2026-10-01)

S4-C 조사(Python, `stage_headers.py --prefer-07` 닫힘, Darwin 단일 후보 구간 중 아직 안 한 170 개): 기존 비활성 미해결 11 종 외에 새 미해결 이름 — `machine/limits.h` 90 구간, `mach_nbc.h`·`kdebug.h` 각 11, `mach_kdb.h` 10, `cputypes.h` 7, … . 새 미해결이 없는 구간 61 개(대부분 BSD `sys/` 헤더를 읽지만 `machine/limits.h` 경로에 닿지 않음). → `machine/limits.h`(Darwin 4.4BSD `sys/param.h:106`) 한 가지가 가장 큰 장애. BSD 헤더 판 결정(S4-C)은 따로 계획하고, 그동안 새 미해결이 없는 Mach 쪽 파일을 진행한다.

S5-P11 대상: `kern/mach_factor.c` — 닫힘 45 파일, BSD `sys/` 헤더 없음.

확인한 사실(원본, 계산 Python):
- 목적 파일 0x15c100–0x15c2fc(508 B), `_compute_mach_factor` 하나. 앞 `FUN_0015c0ac` 는 `_mach_clock_bootstrap` 과 사이가 `90`(같은 목적 파일, mach_clock.c 정적 함수)이고 끝 뒤 `00`×1(최소 채움 1) → 앞 경계 0x15c100. 뒤는 `mach_header.c` 가 0x15c2fc 에서 바로 시작(틈 0).
- 호출 없음. 데이터 참조: `_avenrun` 0x1dee68(12 B, 0x1dee70 = `avenrun[2]`), `_mach_factor` 0x1dee74(12 B), 0x1dee80(이름 없음 — 소스의 `static long fract[3]` 로 보임), `_all_psets` 0x1e9600, `_all_psets_lock` 0x1e9608, `_default_pset` 0x1e9610. `processor_set` 필드 접근 오프셋 264–376.
- 세 후보(Darwin, Mach4, NeXTMach)에 같은 함수 하나; Darwin 은 Mach 헤더만 include.

설계: Darwin 원문 그대로 채택 → `--prefer-07` 스테이징 → 진단 전처리(`undef_conditionals.py`) → 채택 → 07_kernel 빌드(`-O3`, 대조 `-O2`·`-O4`) → `.i` 동일 → L1(`__data` 포함) → 경계 증명서.
예측: `__text` 508 B, `__data` 36 B(`avenrun`·`mach_factor`·`fract` 각 12 B, 원본 0x1dee68–0x1dee8c 연속), 외부 심볼 `_all_psets`·`_all_psets_lock`·`_default_pset`. `processor_set` 오프셋이 다르면 구조체 판 차이(`kern/processor.h`) → 24·25 절 방법으로 조사.

### 34.1 codex 교차검토(QP11) 판정

내 검증: 0x1dee68–0x1dee8c 원본 값(`avenrun` 0×3, `mach_factor` 0×3, 0x1dee80 = 800, 966, 983) 직접 읽음.

| codex 주장 | 판정 |
|---|---|
| 제어 흐름·상수(LOAD_SCALE 1000, SCHED_SHIFT 7, `(old<<2)+now)/5`, fract 가중 평균)·잠금 순서가 Darwin 소스와 대응 | ⚖️ 최종은 L1 |
| 현재 옵션의 `struct processor_set` 계산 배치가 관찰 오프셋(264, 276, 284, 292, 332, 344, 368, 372, 376)과 모두 맞음 | ⚖️ 빌드 결과로 판정 |
| **내 계획 정정**: 오프셋 308 은 `pset` 이 아니라 내부 루프의 `processor`(`edi`) 의 `processors.next`(0x15c189) | ✅ 수용 — 34 절의 "processor_set 필드 접근 오프셋 264–376" 은 308 을 포함해 잘못 묶었음 |
| 세 배열이 소스 정의 순서대로 `__data` 에 연속, 0x1dee80 은 `fract` 초기값 | ✅ 직접 확인 |

### 34.2 S5-P11 결과 (2026-10-01) — `mach_factor.c` A

- 채택 1, `.i` 동일, 세 옵션 동일 목적 파일, 예측(508 B, `__data` 36 B, 외부 3) 적중. L1 OBJECT_MATCH(`__data` 포함) → `x86-mach_factor` **A**, `_compute_mach_factor` `compared/high`. Darwin `struct processor_set` 배치가 현재 옵션에서 원본과 같음이 바이트로 확인됨(구조체 판 차이 없음).

## 35. S5-P12 세부 계획 — `ipc/ipc_table.c`(데이터 값 복원) (코딩 전, 2026-10-01)

확인한 사실(원본, 계산 Python):
- 목적 파일 0x151934–0x151be6(690 B): `_ipc_table_fill` 0, `_ipc_table_init` 0x94, `_ipc_table_alloc` 0x210, `_ipc_table_realloc` 0x250, `_ipc_table_free` 0x284; 함수 사이 `90`, 앞 `00`×2·뒤 `00`×2(최소 채움). 호출: `_kalloc`, `_kfree`, `_kmem_alloc`, `_kmem_free`, `_kmem_realloc`; 데이터: `_page_size`, `_kalloc_map`, 자기 정의 `_ipc_table_entries_size` 0x1dea94·`_ipc_table_dnrequests_size` 0x1dea98(`__data`), `_ipc_table_dnrequests` 0x1f6328·`_ipc_table_entries` 0x1f632c(`__common`).
- **원본 `__data` 값: `ipc_table_entries_size` = 128, `ipc_table_dnrequests_size` = 64.** Darwin `ipc/ipc_table.c:106` 은 `= 512`(dnrequests 는 64 로 같음) → 데이터 값 차이.
- 원본 `__common` 에서 `ipc_table_dnrequests` 가 `ipc_table_entries` 앞(소스 정의 순서와 반대, 알파벳 순서와 같음). 원본 `__common` 417 심볼 중 인접 쌍 336/416 이 알파벳 오름차순, 역전 80 곳 → 목적 파일별 `__common` 묶음이 이어지고 묶음 안은 알파벳 순서일 가능성(가설; 이 빌드로 확인).

설계:
1. D014 복원 수정: `ipc_table.c:106` `= 512` → `= 128`(근거: 원본 0x1dea94 의 값). 그 밖은 그대로.
2. 절차: `--prefer-07` 스테이징 → 진단 전처리 → 채택 → 07_kernel 빌드(`-O3`, 대조 `-O2`·`-O4`) → `.i` 동일 → L1(`__data`·`__common` 배치 포함) → 경계 증명서.
3. **예측**: `__text` 690 B·오프셋 위와 같음, `__data` 8 B(128, 64), 목적 파일 `__common` 8 B 이고 그 안 순서가 원본(dnrequests → entries)과 같은지 기록. `ipc_table_init` 안에 `ipc_table_entries_size` 에 따른 상수가 있으면 512/128 차이가 코드에도 드러남 — 그 경우 수정이 코드까지 맞춰야 일치.
4. 불일치 시 R4·R5.

### 35.1 codex 교차검토(QP12) 판정 — 내 주장 기각, 수정 두 곳

내 검증: 원본 0x151970–0x1519c8 역어셈블, 0x151a6b·0x151b1f, Darwin `ipc/ipc_table.c:112–150`, 0x1519d1·0x1519ec·0x151a72·0x151a85·0x151aa0·0x151b26 의 메모리 읽기 확인.

| codex 주장 | 판정 |
|---|---|
| **내 주장("512→128 만") 기각**: 원본 `_ipc_table_fill` 은 0x1519b5 `add edi, edi` 로 증가 폭을 **상한 없이** 두 배로 하고, `ipc_table_init` 의 인라인 사본 두 곳(0x151a6b, 0x151b1f)도 같다; Darwin `:147–148` 은 `if (incrsize < (PAGE_SIZE << 3))` 상한을 둔다 | ✅ 확인 — 수정이 하나 더 필요 |
| 두 size 전역은 메모리에서 읽고 상수로 접히지 않음 → 512/128 차이는 데이터에만 | ✅ 확인 |
| 128 은 이미지 `__data` 초기값; 로컬 참고 판(Darwin, Mach4)은 512, NeXTMach 에 해당 파일 없음 | ✅(Mach4 `ipc_table.c:61` 확인) |
| `__common` 역순 배치를 설명할 cc-744.13 근거는 저장소 산출물에 없음(여러 미초기화 전역을 가진 목적 파일 없음) | ✅ → 이번 빌드가 첫 표본 |
| `alloc`·`realloc`·`free` 는 Darwin 과 일치, `assert` 코드 없음(MACH_ASSERT=0) | ⚖️ 최종은 L1 |

설계 변경: D014 복원 수정 두 곳 — (a) `:106` `= 512` → `= 128`(근거: 원본 0x1dea94), (b) `:147–148` 의 상한 조건 삭제, `incrsize <<= 1;` 만 남김(근거: 원본 0x1519b5, 0x151a6b, 0x151b1f).

### 35.2 S5-P12 결과 (2026-10-01) — `__text`·`__data` 일치, `__common` 순서 문제로 판정 보류

- 채택 4(`ipc/ipc_entry.h`, `ipc/ipc_table.c`, `ipc/port.h`, `vm/vm_kern.h`), 복원 수정 두 곳 적용(diff `06_reconstruction/evidence/x86-ipc_table.diff`; MODIFICATIONS 행은 판정 뒤 작성). `.i` 는 진단 판과 의도한 두 수정만 다름.
- `s5p12-build-1`: `-O3`=`-O4`, `-O2` 다름. `-O3`: `__text` 690 B **바이트 차이 0**(5 함수 중 4 개 MATCH, `_ipc_table_init` 은 바이트 0 차이·참조 4 개 미검증), `__data` 8 B 를 0x1dea94 에 배치해 일치(128, 64). 
- **보류 사유**: 목적 파일 `__common`(`-fno-common`)은 정의 순서대로 `_ipc_table_entries` 0x2bc → `_ipc_table_dnrequests` 0x2c0 인데, 원본은 `_ipc_table_dnrequests` 0x1f6328 → `_ipc_table_entries` 0x1f632c 로 반대. 한 섹션을 한 Δ 로 둘 수 없어 `l1_compare` 가 `__DATA,__common` 배치를 거부했고, 그 두 심볼을 가리키는 참조 4 개가 미검증.
- 해석 후보(미확정): (a) 원본은 `-fno-common` 이 아니라 진짜 common 기호로 컴파일되어 링커가 배치했다(순서 규칙 미상), (b) 원본 판 소스에서 두 전역의 정의 순서가 반대, (c) 컴파일러가 zero-fill 섹션 안 순서를 다른 규칙으로 정함. 원본 `__common` 의 다른 관찰: `machine_slot`(kern/machine.c, `__text` 0x15d…)이 0x1e8e00 으로 `ipc_table` 쌍(0x1f6328)보다 앞 — 링크 순서(텍스트 순서)대로 목적 파일별 `__common` 이 이어진다는 단순 모델과도 맞지 않는다.
- 다음: (1) 원본 `__common` 417 심볼의 배치 규칙을 조사(정의 파일의 텍스트 순서·알파벳·크기와의 관계, Python), (2) `-fno-common` 없는 변형 빌드로 목적 파일 기호 형태 비교, (3) 필요하면 `l1_compare` 에 zero-fill 섹션의 심볼별 검증(이름이 원본 외부 심볼과 같고 참조 값이 그 주소와 같음)을 추가 — 모두 계획·codex 검토 후.

## 36. S1-E 세부 계획 — `__common`(zero-fill) 의 심볼별 검증 (코딩 전, 2026-10-01)

조사(Python, 원본 심볼표): `__common` 417 심볼을 이름 오름차순이 끊기는 곳에서 나누면 81 묶음(크기 1–34). 묶음의 순서는 정의 파일의 텍스트(링크) 순서와 맞지 않는다(예: `ipc_*` 묶음(텍스트 0x146908 근처)이 0x1f62xx 에, `processor.c` 의 `all_psets` 묶음(텍스트 0x161134)이 0x1e9600 에). → 이미지의 `__common` 배치 규칙은 링커 내부 순서일 가능성이 크고(미확인), 목적 파일 하나의 대조로는 판정할 수 없다. `-fno-common` 여부도 이미지의 심볼 형태로는 구별되지 않는다(둘 다 `__common` 의 외부 심볼). → 배치 규칙·`-fno-common` 여부는 최종 링크 재현(S6) 단계의 과제로 넘긴다.

목적 파일 대조(L1)에서 필요한 것: zero-fill 섹션은 바이트가 없으므로, **참조가 원본의 같은 이름 심볼(같은 오프셋)을 가리키는지**만 확인하면 된다.

설계(`10_tools/reconstruction/l1_compare.py`):
1. `evaluate()`: 로컬 재배치의 대상 섹션 T 가 zero-fill 이고 Δ 가 없으면, 목적 파일에서 T 에 정의된 심볼 중 값이 F 이하인 가장 큰 것(이름 N, 값 v)을 찾고, N 이 원본 외부 심볼이면 기대값 = `img.symbol(N) + (F − v) − (pcrel 이면 ΔP)`, 사유 `zerofill symbol N`. 해당 심볼이 없거나 원본에 없으면(정적 심볼 등) 지금처럼 미검증.
2. 섹션 판정: zero-fill 섹션 T 를 Δ 하나로 둘 수 없을 때, T 에 정의된 **모든** 외부 심볼이 원본 `__common`(같은 이름)에 있고 T 안에 정적 심볼이 없으면 `placement = 'per symbol (zero-fill)'`, 섹션 검증으로 인정. 하나라도 없으면 미검증. 추가로 목적 파일의 심볼 간격(크기)과 원본의 다음 심볼까지 간격을 기록만 한다(크기 하한 확인용, 판정에는 쓰지 않음).
3. 기존 동작 보존: Δ 하나로 배치되는 zero-fill 섹션, 다른 섹션은 지금과 똑같이 처리.
4. 시험(`test_l1_compare.py` 에 추가): (a) 기존 14 시험 그대로 통과, (b) 확정된 목적 파일들(`09_validation/reconstruction/*-l1-*` 의 OBJECT_MATCH 대상)을 다시 돌려 판정 변화 0, (c) `s5p12` `ipc_table` `-O3` 이 OBJECT_MATCH 가 되고 사유가 `zerofill symbol` 로 기록, (d) 음성: 원본 사본에서 `_ipc_table_init` 의 `ipc_table_entries` 참조 한 곳을 `ipc_table_dnrequests` 주소로 바꾸면 DIFF.
5. 결과로 `ipc_table` 을 판정하고(경계 증명서 포함), 확정되면 등급 문구에 "zero-fill per symbol" 를 남긴다.

### 36.1 codex 교차검토(QE1) 판정 — 36 절 설계 기각, 대안

내 검증: `l1_compare.py` 219–227 행(zero-fill **대상**도 Δ 추론 대상 — 207 행은 출발 섹션만 제외), 276–281 행(zero-fill 은 `given by symbol` 일 때만 `placement-only`), `ipc_table.o` 의 참조 4 개 필드값(0x1519e5·0x151a79 → 0x1f632c, 0x151a99·0x151b2d → 0x1f6328)은 codex 표와 같음(35.2 결과 JSON 으로도 확인 가능).

| codex 주장 | 판정 |
|---|---|
| 로컬 재배치는 섹션 번호만 보존 → "F 이하 가장 큰 심볼" 로 대상 심볼을 증명할 수 없다(예: `dnrequests` 시작 = `entries` 끝 0x2c0) | ✅ 설계 1 기각 |
| `infer()` 가 zero-fill 대상도 추론 → 원본 참조를 바꿔도 단일 Δ 가 나와 심볼별 검증을 우회할 수 있음 | ✅ 코드 확인 |
| pcrel·scattered·SECTDIFF·정적 심볼·별칭·패딩에서 오판 가능 | ✅ |
| 심볼 간격은 크기의 상한 후보일 뿐, 크기 증명 아님 | ✅ |

대안 설계(도구 수정 없음): zero-fill 전역을 참조하는 목적 파일은 **`-fno-common` 을 뺀 변형**을 함께 빌드한다. 그 변형에서 미초기화 전역은 이름 있는 common 심볼(정의되지 않은 외부 심볼, `n_value` = 크기)이 되어 참조가 **외부 재배치(심볼 번호 = 그 이름)** 로 남는다 → 기존 L1 의 외부 경로가 이름으로 정확히 검증. 판정 조건: (a) `-fno-common` 판의 `__text`·`__data` 바이트 차이 0(재배치 필드 제외), (b) common 변형이 OBJECT_MATCH(모든 참조 검증), (c) common 심볼 크기 ≤ 원본에서 다음 심볼까지 간격(상한 일관성만 기록). 원본이 `-fno-common` 이었는지는 목적 파일로 판정하지 않는다(S6).

### 36.2 codex 교차검토(QE2) 판정과 S5-P12 확정 (2026-10-01)

QE2(대안 설계): 핵심은 타당, 결론 범위를 좁힘 — 증명되는 것은 "common 변형에서 복원 측 이름·addend 로 다시 계산한 값이 원본 필드와 같다" 이고, `-fno-common` 판에 옮기려면 두 판의 참조 대응(같은 전처리 입력, 같은 재배치 위치·폭·pcrel·유형, 재배치 밖 바이트 동일)을 확인해야 한다(✅ 수용). 원본의 비-STAB 섹션 심볼 3,651 개가 모두 외부라 이름 해석의 local 혼동은 이 원본에서 생기지 않음(codex 수치, 35.2 이전 집계 3,651 과 같음). 정적 미초기화 변수는 이 방법의 대상이 아님(✅ 범위 밖으로 기록).

결과: `s5p12-common-1` — 전처리 입력 바이트 동일, 재배치 28 개 위치 동일·재배치 밖 바이트 동일, 달라진 4 개는 폭·pcrel·유형 같고 local→extern(이름 `_ipc_table_entries`·`_ipc_table_dnrequests`)만 다름, common 크기 4 ≤ 원본 간격 4, L1 OBJECT_MATCH(모든 참조 검증). 경계 증명서 통과 → `x86-ipc_table` **A**, 5 함수 `compared/high`(표 행 수 확인: functions +5, objects +1, MODIFICATIONS +1). 앞으로 `__common` 정의를 가진 파일은 이 두 판 방식으로 판정한다.

## 37. S5-P13 세부 계획 — `kern/host.c`(`MACH_HOST` 확정 시험) (코딩 전, 2026-10-01)

확인한 사실(원본, 계산 Python):
- 목적 파일 0x157958–0x157c3e(742 B): `_host_processors` 0, `_host_info` 0xd0, `_host_kernel_version` 0x224, `_host_processor_sets` 0x254, `_host_processor_set_priv` 0x2b4; 함수 사이 `90`, 앞 `00`×2, **뒤 0x157c3e–0x157c40 은 `90 90`**(37.1: 내가 처음에 `00` 으로 잘못 적음). 호출 `_bcopy`·`_convert_processor_to_port`·`_convert_pset_name_to_port`·`_kalloc`·`_panic`·`_pset_reference`·`_strncpy`; 데이터 `_processor_ptr`(0x1e9050, 색인 주소 — 내 첫 조사에서 누락), `_tick`, `_avenrun`, `_mach_factor`, `_version`, `_machine_slot`, `_default_pset`, `_master_processor`, `_machine_info`+8/+12/+16(0x1f6348–0x1f6350), 문자열 `"host_processors"`(0x1deb90, `__data`, Darwin `host.c:99` 의 panic).
- `host_processor_sets` 는 세 후보 모두 `#if MACH_HOST`/`#else` 로 두 번 정의 → 원본이 `!MACH_HOST` 판과 일치하면 `MACH_HOST=0` 확정 근거(값은 0/비영 구분).
- 세 후보(Darwin, NeXTMach, Mach4)의 5 함수 본문(주석·공백 정규화 후)은 서로 모두 다르다 → 어느 판이 원본과 맞는지 함수별 대조가 필요(codex 질문).

설계: 시작 후보 Darwin(헤더 환경). `--prefer-07` 스테이징 → 진단 전처리 → 채택 → 07_kernel 빌드(`-O3`, 대조 `-O2`·`-O4`) → `.i` 동일 → L1(`__data` 의 panic 문자열 포함) → 경계 증명서. 예측: `__text` 742 B·오프셋 위와 같음, `__data` 에 `"host_processors"` 문자열(16 B 이상), 외부 심볼 위 목록. 불일치 시 차이 위치를 원본·세 후보와 대조해 D014(R4·R5).

### 37.1 codex 교차검토(QP13) 판정

내 검증: 0x157c3a–0x157c42 바이트(`ret` 뒤 `90 90`), 첫 조사 출력의 `gap 9090` 재확인.

| codex 주장 | 판정 |
|---|---|
| Darwin 5 함수가 원본 흐름과 모두 대응(`host_info` flavor 1–4, count 검사, `machine_info` +8/+12/+16, `host_load_info` 두 `bcopy`, `strncpy(…, 512)`, `!MACH_HOST` 의 `kalloc`+`pset_reference`+`convert_pset_name_to_port`); NeXTMach 는 여러 곳에서 다르고(LOAD 분기 없음, `copystr`, `vm_allocate`), Mach4 는 SCHED 의 `min_quantum` 이 다름 | ⚖️ 대응은 합리적 — 최종은 L1 |
| **내 기록 오류 2 건**: 뒤 틈은 `90 90`(00 아님), 참조 목록에 `_processor_ptr` 누락 | ✅ 수정 |
| `host_info.h` 구조체 배치가 원본 저장 오프셋과 맞음 | ⚖️ 빌드로 판정 |

### 37.2 S5-P13 결과 (2026-10-01) — `kern/host.c` 확정(등급 A)

- 채택 1(`kern/host.c`, Darwin 그대로). `s5p13-build-1`: `-O3` = `-O4`, `-O2` 다름(734 B). `-O3` L1 OBJECT_MATCH, 5 함수 MATCH, `__text` 744 B 차이 0·참조 27 일치, `__data` 16 B(0x1deb90) 일치, `__common` `_realhost` 심볼로 배치.
- `-fno-common` 없는 변형(`s5p13-common-1`)도 OBJECT_MATCH, `_realhost` 크기 8 = 원본 다음 심볼까지 간격.
- 경계: 앞 `00 00`(최소 채움), 뒤 0 — 뒤 `90 90`(37.1)은 host.o `__text` 안의 컴파일러 채움으로 바이트 비교에 포함됨 → **A**.
- `MACH_HOST`=0 을 confirmed 로 올림(`config_options.tsv`, 생성 헤더 변화 없음: `gen_config_headers.py --check` 통과). 헤더 변경이 없으므로 회귀 재빌드 불필요.
- 증거: `06_reconstruction/evidence/x86-host.md`.

## 38. S5-P14 세부 계획 — `kern/priority.c` `_thread_quantum_update` (코딩 전, 2026-10-01)

원본 사실(capstone 4.0.2, 원본 이미지 직접 디스어셈블; IDA 작업 프로세스가 응답하지 않아 사용하지 않음):
- 객체 `__text` 0x160e84–0x161134(688 B, Python), 함수 하나. 앞 틈 0x160e81–0x160e84 `00 00 00`(앞 함수 `_kern_PMRestoreDefaults` 끝 0x160e81, Ghidra 본문), 0x161132–0x161134 `00 00`, 다음 `_pset_sys_bootstrap` 0x161134.
- 호출: `_splsched`×2, `_update_priority`×2(0x160ef7, 0x161037), `_timer_delta`×4, `_compute_my_priority`×2, `_splx`×2, `_ast_check`. 데이터: `_processor_ptr`(색인), `_min_quantum`, `_sched_tick`, 0x1e977c(= `_default_pset` 0x1e9610 + 364, Python).
- 0x160ea3: `min_quantum` 을 0x1e977c 에 저장 → `NCPUS > 1` 이 아닌 분기(`default_pset.set_quantum = quantum`). pset 읽기·`quantum_adj_lock` 없음.
- 0x160f04: `cmp [esi+0x60], 2; je` → `thread->policy != POLICY_FIXEDPRI`(policy.h:64 = 2) — Darwin 식. Mach4 는 `== POLICY_TIMESHARE`(1).
- `_update_priority` 를 `sched_stamp != sched_tick` 일 때 호출 — Darwin 은 이 호출을 `#if NCPUS > 1`(priority.c:173–175, :218–220)로 감싸 NCPUS=1 이면 사라진다. Mach4 는 감싸지 않음.
- NeXTMach 트리에는 `thread_quantum_update` 가 없다(grep 0 건).

후보 판정: Darwin 그대로도, Mach4 그대로도 원본과 다르다(앞은 `update_priority` 없음, 뒤는 policy 비교 상수 다름).

설계:
1. 채택 기준 소스: Darwin `kern/priority.c`. **복원 수정(D014)**: `update_priority(thread);` 를 감싼 `#if NCPUS > 1` / `#endif` 두 쌍(4 줄)을 제거 — Mach4 구조와 같고, 원본 바이트의 두 호출이 근거. 그 밖은 바꾸지 않는다.
2. 대조군: 수정 없는 Darwin 판(진단 빌드)도 함께 빌드해 두 `_update_priority` 호출만큼만 다른지 본다(수정의 효과를 분리).
3. 환경: `stage_headers.py --prefer-07`, 진단 전처리로 정의 안 된 식별자 확인. 빌드 `-O3`(대조 `-O2`, `-O4`), L1, 경계 증명서.
4. 일치하면: 함수·객체 기록, diff 를 `06_reconstruction/evidence/x86-priority.diff`, MODIFICATIONS 행. `NCPUS`=1 을 confirmed 로 올릴 근거가 되는지 판단(NCPUS>1 분기는 pset 경로를 컴파일하므로 바이트로 배제됨). `MACH_FIXPRI`=1 도 같은 방식으로 판단(0 이면 policy 비교가 사라짐).
5. 불일치하면: 차이 위치를 기록하고 채택하지 않는다.

### 38.1 codex 교차검토(QP14) 판정

내가 직접 확인한 것: capstone 디스어셈블(`scratchpad/prio.dis`), Darwin `priority.c`·Mach4 `priority.c`·07_kernel `sched.h`·`timer.h`·`lock.h` 해당 줄, Python.

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| 원본은 Darwin(NCPUS=1, MACH_FIXPRI=1) + `update_priority` 무조건 호출과 의미상 같고 다른 차이는 없다 | 호출·데이터 목록(38절), 0x160f04·0x160fe6·0x161044 `cmp [esi+0x60],2` 세 곳, 0x160fd9 `processor+0x124 = 0`(`first_quantum = FALSE`, priority.c:195), 0x160ffc `thread+0x5c`(`sched_data`) | ✅ 의미 대응 — 최종은 L1 |
| 임계값 0x1610f5 `cmp eax,0x7ffffff; jbe` = `1 << (18+2+7)` | Python `(1<<27)-1 = 0x7ffffff`; sched.h:81 `PRI_SHIFT 18`(STAT_TIME 분기), :154 `SCHED_SHIFT 7` | ✅ |
| `thread_timer_delta` 는 sched.h:160, system 먼저·user 다음, `sched_load` 를 `thread+0x180`→`+0x178` 로 곱함 | sched.h:160–168 열람(system_timer 먼저), 0x160f9a/0x1610da `[esi+0x180]`, 0x160fa0/0x1610e0 `imul [eax+0x178]` | ✅ |
| 잠금은 남아 있다(MACH_SLOCKS via DRIVERKIT, lock.h:66); 획득·해제 xchg | lock.h:66 열람, 0x160fcd·0x161114 `xchg [esi+0x20]` | ✅ (기존 가설과 같음) |
| Mach4 는 정책 비교 세 곳이 다르고 그 밖에 더 나은 곳 없음 | Mach4 priority.c:155 등 `== POLICY_TIMESHARE`, policy.h:63–64 | ✅ |
| 대조군 차이는 레지스터 배치까지 다를 수 있으니 의미 비교로 볼 것 | 대조 빌드 662 B, L1 459 B 차이 — 호출 두 개만의 차이로 보지 않는다 | ✅ 설계 2 문구 완화 |
| 이 함수 하나로 전역 옵션 값을 확정할 수 없다 | 설계 4 는 "판단" 으로만 적음. NCPUS·MACH_FIXPRI 승격은 일치 뒤 따로 근거를 적는다 | ⚖️ |
| 인용 줄 priority.c:172, :217 | 172·217 은 `if (thread->sched_stamp != sched_tick)` 줄(가드는 173–175, 218–220) | ⚖️ 위치는 가드 바로 위 줄 |

### 38.2 S5-P14 결과 (2026-10-01) — `kern/priority.c` 확정(등급 A, 복원 수정)

- 채택 5(`kern/priority.c`, `kern/mach_param.h`, `kern/time_stamp.h`, `machdep/i386/time_stamp.h`, `machdep/machine/time_stamp.h`), 복원 수정 1 곳(가드 두 쌍 제거) + 수정 주석. `.i` 는 진단 판과 두 호출만 다름.
- `-O2` = `-O3` = `-O4`(같은 SHA, 주석 넣은 최종 파일 `s5p14-build-2` 도 같은 SHA). L1 OBJECT_MATCH, 차이 0, 참조 18 일치. 경계 앞 `00`×3·뒤 `00`×2(최소 채움) → **A**.
- 옵션: `NCPUS`=1, `MACH_FIXPRI`=1 confirmed. `STAT_TIME` 은 근거 추가(임계 상수)만, hypothesis 유지. 생성 헤더 변화 없음.
- 증거: `06_reconstruction/evidence/x86-priority.md`, `x86-priority.diff`.

## 39. S5-P15 세부 계획 — `vm/vm_init.c` `_vm_mem_init` (코딩 전, 2026-10-01)

후보 선정(Python, `objects.tsv` 중 미확정·Mach 쪽 작은 묶음): seq 164/166(7·12 B, 단편), 192 `syscall_sw.c`(대부분 데이터), 165, 214, **196 `time_stamp.c` 보류**, **205 `vm_init.c` 선택**.
- 196 보류 사유: 원본 `_kern_timestamp`(0x16a158–0x16a196)는 `ns_time_to_tsval(clock_value(1), &ts)` 후 `copyout` — Darwin(clock_get_counter + usec 계산), Mach4(`time`), NeXTMach(`event_set_ts`) 모두 다르고, `clock_value`·`ns_time_to_tsval` 정의·사용 모두 어떤 참조 트리에도 없음(`grep -rnw` 0 건; 처음 적은 "NeXTMach `tags`·`nextdev/sc.c` 사용처" 는 `s5r_clock_values` 부분 문자열 일치였음 — 39.1). 맞추려면 분기 전체를 새로 써야 하므로 19 절 R1/R2(최소 수정) 범위를 넘는다 → 새 코드 작성 규칙이 정해질 때까지 보류.

원본 사실(capstone):
- `_vm_mem_init` 0x173a68–0x173ad3(107 B, Python), 앞 틈 0(앞 함수 `_vm_fault_wire_fast` Ghidra 끝 0x173a68), 뒤 0x173ad3 `00` 1 B, 다음 `_kmem_alloc` 0x173ad4(vm_kern.c).
- 호출 순서: `vm_page_startup(mem_region, num_regions, virtual_avail)` → `virtual_avail` 저장 → `zone_bootstrap` → `vm_object_init` → `vm_map_init` → `kmem_init(virtual_avail, virtual_end)` → `pmap_init(mem_region, num_regions)` → `zone_init` → `kalloc_init` → **`vm_pager_init`** → `vm_user_init`.
- Darwin `vm/vm_init.c` 은 `vm_pager_init` 만 없고 나머지 순서·인자가 같다. NeXTMach mk-108.1 `vm/vm_init.c:91` 에 `vm_pager_init();` 가 같은 자리(`kallocinit()` 뒤, `vm_user_init` 앞)에 있다(NeXTMach 은 `kallocinit` 이름이 달라 기준으로 못 씀). Mach4 는 구조가 다름.

설계:
1. 기준 Darwin `vm/vm_init.c`, 복원 수정(D014): `kalloc_init();`(:85) 뒤에 `vm_pager_init();` 한 줄 추가 + 머리말 뒤 수정 주석. 추가 줄의 출처는 NeXTMach(`https://github.com/johnsonjh/NeXTMach.git` f6bdb9c3268f0eadc545d41bcc0564453b17001e, `mk-108.1/vm/vm_init.c:91`) — D013 에 따라 MODIFICATIONS·PROVENANCE 에 기록.
2. **새 옵션 `MACH_XP`**: Darwin `vm_init.c` 가 `#import <mach_xp.h>` 하므로 생성 헤더가 필요. 값 0, 상태 hypothesis(근거: Darwin `conf/MASTER.i386:72` RELEASE 태그에 `xp` 없음, `MASTER:134` `options MACH_XP # <xp>`). 일치하면 confirmed(원본이 `#else MACH_XP` 의 `vm_user_init` 을 호출 — `MACH_XP` 분기는 비어 있음).
3. 생성 헤더 추가는 `meta_features.h` 를 바꾸므로 **회귀**: 확정 객체 24 개 가운데 `meta_features.h` 를 쓰는 커널 C 빌드를 원래 명령 그대로 다시 빌드해 SHA-256 동일 확인. 저장소 전체에 `#ifdef MACH_XP`/`defined(MACH_XP)` 는 없다(grep 0 건) — 정의 추가가 `#if` 결과를 바꾸지 않는다는 예측.
4. 예측(R5): `__text` 108 B(뒤 `00` 포함 여부는 빌드로), 재배치: 외부 호출 11 + `virtual_avail` 3·`num_regions` 2·`mem_region` 2·`virtual_end` 1, `__data` 없음.
5. 진단 빌드(수정 없는 Darwin)도 함께 — 호출 하나 차이인지 확인. 빌드 `-O3`(대조 `-O2`, `-O4`), L1, 경계 증명서.

### 39.1 codex 교차검토(QP15) 판정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| `_vm_mem_init` = Darwin + `vm_pager_init` 한 줄(0x173ac5, `_kalloc_init` 0x173ac0 와 `_vm_user_init` 0x173aca 사이); `#ifdef ppc` 는 i386 에서 비활성 | 39 절 디스어셈블 다시 확인(같은 호출 순서·인자) | ✅ — ppc 블록은 x86 바이트로 검증 불가(그대로 둠) |
| MACH_XP=0 에서만 생기는 원본 심볼: `_vm_user_init` 0x17c4e0, `_vm_alloc_lock` 0x1f64c0, `_vm_map_lookup_done` 0x1783d8; XP 전용 `vm_map_verify(_done)` 없음 | `symbols.tsv` grep(앞 셋 있음, verify 둘 없음), vm_user.c:61–63 `#if MACH_XP / #else`, vm_map.c:60 `USE_VERSIONS MACH_XP`·:2588 `#if USE_VERSIONS` 안의 `vm_map_verify`(:2596) | ✅ MACH_XP=0 근거 추가 |
| vm_fault 의 non-XP `FREE_PAGE`(PAGE_WAKEUP 먼저) | 주소만 받음, 이번 판정에 쓰지 않음 | ⏭️ (근거로 기록하지 않음) |
| `#ifdef MACH_XP`/`defined(MACH_XP)` 0 건, 07_kernel 에 `MACH_XP` 토큰 없음 | grep 두 트리 0 건, `grep -rn MACH_XP 07_kernel` 0 건 | ✅ — 회귀 빌드는 그대로 수행 |
| 경계: 앞 0, 끝 0x173ad3(107 B), 0x173ad3 `00`, 다음 0x173ad4 | 39 절 Python 출력과 같음 | ✅ |
| **내 기록 오류**: `clock_value`/`ns_time_to_tsval` 의 NeXTMach "사용처" 는 `s5r_clock_values` 부분 일치 | `grep -rnw` 0 건, sc.c:226·237 은 `s5r_clock_values` | ✅ 39 절 문구 수정 |

### 39.2 S5-P15 결과 (2026-10-01) — `vm/vm_init.c` 확정(등급 A, 복원 수정) · `MACH_XP`=0

- `MACH_XP` 옵션 행 추가·생성 헤더 `mach_xp.h` 생성(`meta_features.h` 에 `#import <mach_xp.h>` 한 줄). 회귀 `s5p15-regress-2`: 확정 24 개 SHA 모두 동일(`-1` 은 S5-P1 memcmp 명령의 옛 경로 `src/memcmp.c` 때문에 memcmp 만 실패 → memcmp·kern_machdep 은 S4-A2 회귀의 공통 명령으로 바꿔 재실행).
- 채택 1(`vm/vm_init.c`), 복원 수정 1 줄(`vm_pager_init();`, NeXTMach 출처) + 수정 주석. `.i` 는 진단 판과 주석·한 줄만 다름.
- `-O2` = `-O3` = `-O4`, `__text` 107 B, 재배치 18. L1 OBJECT_MATCH(차이 0, 참조 18 일치). 경계 앞 0·뒤 `00`×1(최소 채움) → **A**. 대조군(수정 전) 102 B.
- **예측 오류**: 설계 4 의 "외부 호출 11 / 재배치 19" 는 잘못 셈 — 호출 10, 재배치 18(Python).
- `MACH_XP`=0 confirmed. 증거 `06_reconstruction/evidence/x86-vm_init.md`, `x86-vm_init.diff`.

## 40. S4-C 사실 조사(2026-10-01) — 결정 없음, 기록만

- 계기: 다음 후보 `vm/vm_synchronize.c`(seq 214; 원본 0x17b9e0–0x17bd28, 함수 4 개가 Darwin 정의 순서와 같고 `vm_pageout_page` 의 `assert_wait`/`thread_block` 재시도 경로까지 Darwin 판과 대응)가 `#import <sys/param.h>` → `bsd/sys/param.h:106` `<machine/limits.h>` 로 막힘.
- 조사 결과 보존: `09_validation/reconstruction/s4c-survey-20261001.json`(미확정 199 구간, 첫 Darwin 후보의 `--prefer-07` 닫힘; 미해결은 모든 분기 기준). 집계(Python): BSD 쪽 86 개 중 77 개, Mach 쪽 113 개 중 31 개(Mach 소계 40619 B; BSD 소계 158669 B, 41.1)가 `machine/limits.h` 에 닿음(경로: `bsd/include/time.h:103` 107 건, `bsd/sys/param.h:106` 105 건, `bsd/include/limits.h:65` 1 건). Mach 쪽 82 개는 닿지 않고, 그중 **59 개는 이미 성공한 빌드의 미해결 11 종 밖의 새 미해결이 없음**.
- 참조: Darwin 빌드는 `conf/Makefile.template:86–92` 에서 `$(NEXT_ROOT)/System/Library/Frameworks/System.framework/{PrivateHeaders,Headers,Headers/bsd}` 를 include 경로에 넣는다 — `machine/limits.h` 는 소스 트리가 아니라 빌드 머신의 시스템 헤더에서 왔을 가능성(미확인). Darwin 트리의 후보: `architecture/i386/limits.h`(CHAR_BIT 8, MB_LEN_MAX 6, CLK_TCK 100, …, SSIZE_MAX/SIZE_T_MAX/QUAD_*).
- 실기 OPENSTEP 4.2(읽기 전용 조회, gcds): `/NextDeveloper/Headers/bsd/machine/` 에 `param.h`·`limits.h` 없음, 대신 4.3BSD 식 `machparam.h`; `limits.h` 는 `ansi/machine/limits.h`(→ `ARCH_INCLUDE(ansi/, limits.h)`)와 `ansi/i386/limits.h`(1992 NeXT; MB_LEN_MAX 1, UCHAR_MAX 255U, CLK_TCK 없음, LONG_LONG_*)에만 있다. `architecture/i386/` 에도 `limits.h` 없음. → 원본 시대 NeXT 헤더는 Darwin 4.4BSD 판과 배치·값이 다르다(그 판이 커널 빌드에 쓰였는지는 미확인).
- 결정하지 않는 이유: 어느 판을 쓸지는 BSD 쪽 재구성 전체에 영향을 주고, 지금은 새 헤더 없이 진행할 Mach 쪽 59 구간이 남아 있다. S4-C 결정은 BSD 쪽에 들어갈 때 계획·codex 검토·사용자 판단으로 다룬다. 그때까지 `machine/limits.h` 에 닿는 파일은 진행하지 않는다(30.x 규칙 유지). `vm_synchronize.c` 는 보류.

## 41. S5-P16 세부 계획 — machdep/i386 작은 세 파일 `bios.c`, `checksum_16.c`, `ldt.c` (코딩 전, 2026-10-01)

선정: 40 절의 "새 미해결 없음" 59 구간 중 작은 순. seq 192 `syscall_sw.c`(대부분 데이터 표), seq 165 `_send_notification`(앞뒤 틈이 `90` — seq 162 `ipc_xxx.c` 객체의 일부로 보여 그쪽과 함께)는 뒤로.

원본 사실(capstone, 계산 Python):
- `bios.c`: `_bios32` 0x1871d4–0x1871e6(18 B) — `__bios32(bb)` 호출 뒤 `return 0`. Darwin `machdep/i386/bios.c` 에서 `NOTYET` 이 거짓인 경우와 대응(정적 지역 변수 4 개와 `static inline` 두 함수는 쓰이지 않음 — 목적 파일에 데이터가 남는지는 빌드로). 앞 틈 `00`×3(앞 `__bios32` 끝 0x1871d1), 뒤 `00 00`, 다음 `FUN_001871e8`.
- `checksum_16.c`: `_checksum_16` 0x1877f8–0x187842(74 B) — 16 비트 바이트 교환(`ror ax,8`) 합, 접기, `> 0xffff` 이면 −0xffff. Darwin `machdep/i386/checksum_16.c` 와 대응(`NXSwapShort` 인라인). 앞 `00`×3(앞 `_PMUpdateClock` 끝 0x1877f5), 뒤 `00 00`, 다음 `_system_timer_dispatch` 0x187844.
- `ldt.c`: `_ldt_init` 0x18cbcc–0x18cc25(89 B) — `ldt[1]`(UCS) 코드, `ldt[2]`(UDS) 데이터 서술자 기록, DPL 3. 데이터: `_ldt` 0x1e2278 = 0x1e2260 을 가리킴, 정적 `ldt_store[LDTSZ=3]` 24 B 가 그 앞(0x1e2260–0x1e2278) — Darwin 정의 순서와 같음. 앞 `00 00`(확정 객체 kern_machdep 끝 0x18cbca 와 일치), 뒤 `00`×3, 다음 `_halt_thread` 0x18cc28.

설계:
1. 세 파일 모두 Darwin 그대로, 수정 없음. `stage_headers.py --prefer-07` 으로 각각 스테이징, 진단 전처리로 정의 안 된 식별자 확인(`NOTYET` 포함).
2. 빌드 `-O3`(대조 `-O2`, `-O4`), L1(`ldt.c` 는 `__data` 28 B 포함), 경계 증명서. 일치하면 등급 A 기록.
3. 예측(R5): `bios.o` `__text` 18 B 와 재배치 1(`__bios32`); `checksum_16.o` 74 B, 재배치 0; `ldt.o` `__text` 89 B, 재배치 2(`ldt` ×2), `__data` 28 B 와 재배치 1(`ldt` → `ldt_store`).
4. 불일치면 채택하지 않고 차이를 기록.

### 41.1 codex 교차검토(QP16) 판정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| `_bios32` = bios.c `NOTYET` 거짓 경로; 정적 지역 4 개(bios.c:56–59)는 쓰이지 않아도 16 B zero-fill 로 남을 것(GCC 소스 근거, NeXT cc 미검증) | bios.c:56–59 열람; 빌드 `s5p16-pre-2` 실측: `__bss` 16 B, 참조 0 | ✅ 실측으로 확인(GCC 소스 인용은 근거로 쓰지 않음) |
| 원본에서 그 16 B 의 위치는 증명 불가(지역 심볼 없음, zero-fill) | 원본 심볼표는 외부 심볼만, `__bss` 바이트 비교 불가 | ✅ → `bios` 객체는 확정하지 않음 |
| `NXSwapShort` 는 architecture/i386/byte_order.h:38–53 의 인라인 `rorw $8` | 해당 줄 열람 | ✅ |
| `ldt_init` 서술자 저장 전부 일치; VM_MIN/MAX 0/0xc0000000(mach/i386/vm_param.h:65–66), USER_PRIV 3(architecture/i386/sel.h:42); 원본 0x1e2260 24 B 0, `_ldt` = `60 22 1e 00` | 세 줄 열람, 원본 28 B 덤프 | ✅ (최종은 L1 일치) |
| 경계 세 쌍 모두 최소 채움 | 41 절 Python 값과 같음 | ✅ |
| 40 절 수치 재계산 일치; "합 40619 B" 는 Mach 소계 | Python 합계 BSD 158669, Mach 40619 | ✅ 문구 수정 |

### 41.2 S5-P16 결과 (2026-10-01)

- 세 파일 Darwin 그대로 채택(읽힌 115 파일 중 새 10 개 채택: 세 `.c` 와 `bios.h`, `desc_inline.h`, `gdt.h`, `idt.h`, `ldt.h`, `table_inline.h`, `architecture/i386/table.h`). 07_kernel 빌드 `s5p16-build-1` 이 진단 빌드와 `.i`·목적 파일 모두 같음. 세 파일 모두 `-O2` = `-O3` = `-O4`.
- `checksum_16.c`, `ldt.c`: OBJECT_MATCH, 경계 최소 채움 → **A** 2 개(`ldt` 는 `__data` 28 B 포함).
- `bios.c`: `_bios32` 함수는 MATCH(compared/high). 객체는 쓰이지 않는 정적 지역 변수 4 개가 `__bss` 16 B 로 남는데(실측), 원본에서 위치를 보일 수 없으므로 **확정하지 않고** S6 로 넘김. 예측(41 설계 3)은 `__bss` 를 빼먹었음.
- 증거 `06_reconstruction/evidence/x86-machdep_small.md`.

## 42. S5-P17 세부 계획 — `machdep/i386/gdt.c`, `idt.c` (코딩 전, 2026-10-01)

선정: 40 절 59 구간 중 앞뒤 틈이 모두 `00` 최소 채움인 것. 같이 본 `dbl_fault.c`(seq 247), `intr.c`(254), `dma_buf.c`(246)는 뒤 틈이 `90` 이라 객체가 이어지는 것으로 보여 뒤로.

원본 사실(capstone, Python):
- `gdt.c`(seq 250): `_locate_gdt` 0x18a904, `_gdt_init` 0x18a924, 끝 0x18aafa(502 B). 앞 `00 00`(`_fp_synch` 끝 0x18a902), 뒤 `00 00`, 다음 `_i386_init` 0x18aafc. 호출 없음, 데이터 `_gdt_base`·`_gdt_limit`(0x1e17b2/0x1e17b0, 다른 파일), `_gdt`(×11), `_unix_syscall_`·`_mach_kernel_trap_`·`_machdep_call_`. `_gdt` 0x1e19b0 = 0x1e18b0 → 정적 `gdt_store` 256 B(= GDTSZ 32 × 8, gdt.h:38)가 바로 앞 — Darwin 정의 순서와 같음.
- `idt.c`(seq 252): `_locate_idt` 0x18b184, `_idt_init` 0x18b1a4, 끝 0x18b2ab(295 B). 앞 `00`×3(`_getval` 끝 0x18b181), 뒤 `00`×1, 다음 `_in_cksum` 0x18b2ac. 데이터 `_idt_pseudo` 0x1e1a04(2048 B = IDTSZ 256 × 8, idt.h:38), 바로 뒤 `_idt` 0x1e2204 = 0x1e1a04.
- **Darwin `idt.c` 의 세 번째 함수 `idt_copy`(idt.c:438–451)의 흔적이 원본에 없고 그 호출 자리도 없다**(42.1: "없다" 는 과장 — 정적 함수·다른 곳 인라인 가능성은 기호 부재로 배제되지 않음): 심볼 `_idt_copy` 없음(원본 심볼표는 외부 심볼을 보존), 문자열 `"idt_copy"` 없음(strings.tsv 0 건), 원본 `_i386_init`(0x18aafc–0x18abcd) 호출 목록에 `alloc_cnvmem`/`idt_copy` 없이 `_pmap_bootstrap` → `_locate_gdt` → `_locate_idt` — Darwin `i386_init.c:159–163` 의 'f00f' 우회(`idt_copy(alloc_cnvmem(...))`)가 없는 판.

설계:
1. `gdt.c`: Darwin 그대로.
2. `idt.c`: 복원 수정(D014) — idt.c:437–451(빈 줄과 `idt_copy` 정의) 삭제 + 머리말 뒤 수정 주석. 근거는 위 세 가지.
3. 진단(수정 없는 Darwin)과 07_kernel 판을 함께 빌드: 진단 `idt.o` 는 `_idt_copy`·`panic`·`memcpy` 참조와 문자열을 더 가질 것.
4. 예측(R5): `gdt.o` `__text` 502 B, `__data` 260 B(gdt_store 256 + gdt 4), 재배치 `__data` 1. `idt.o` `__text` 295 B(`idt_copy` 제거 후), `__data` 2052 B(idt_pseudo 2048 + idt 4), `__data` 재배치 257(IPE 256 + idt 1). 둘 다 `-O3`(대조 `-O2`, `-O4`), L1, 경계 증명서.

### 42.1 codex 교차검토(QP17) 판정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| `_gdt_init` 의 7 서술자·3 호출 게이트 모두 gdt.c·seg.h·desc_inline.h 와 일치; `KERNEL_LINEAR_BASE` = `VM_MAX_ADDRESS`(pmap.h:84), 커널 min/max 0/0x40000000(mach/i386/vm_param.h:68–69) | pmap.h:84, vm_param.h:65–69 열람 | ✅ 헤더 값 — 서술자 전부는 L1 로 판정 |
| IDT 표 256 항목 0 불일치, `_idt` = 0x1e1a04 | 진단 빌드 `__data` 2061 B 중 표 부분은 L1 로 판정 | ⚖️ L1 로 확인 예정 |
| task gate: idt.c:159–162 는 인자 4 개, desc_inline.h:409–417 은 3 개 → `tmp.offset` 이 DPL 로 들어감, 원본도 그렇다 | 두 곳 열람(4 인자 대 3 매개변수 확인) | ✅ 소스 그대로 둔다(고치지 않음) |
| `idt_copy` "없다" 는 과장 — 정적·인라인 가능성; `_alloc_cnvmem`(0x18ad9c)은 존재 | 심볼표에서 `_alloc_cnvmem` 확인, 원본 파일 전체 `b"idt_copy"` 0 건 | ✅ 42 절 문구 수정 |
| 설계 4 예측 타당; "_idt_copy 참조" 가 아니라 정의 | 설계 3 의 "참조" 는 정의가 맞음 | ✅ |
| 경계(배타 끝) 확인; 502·295 B 는 객체, 함수는 470·263 B | Python 41/42 절 값과 같음 | ✅ |

### 42.2 S5-P17 결과 (2026-10-01) — `gdt.c`, `idt.c` 확정(A 2 개)

- `gdt.c` Darwin 그대로, `idt.c` 복원 수정(`idt_copy` 삭제) + 수정 주석. `.i` 차이는 의도한 것만(`gdt.i` 동일).
- 둘 다 `-O3` = `-O4` OBJECT_MATCH, `-O2` 다름(gdt 486 B, idt 279 B). `gdt` `__data` 260 B(0x1e18b0), `idt` `__data` 2052 B(0x1e1a04, 재배치 257 일치 — IDT 표 전체 확인). 경계 최소 채움 → **A**. 예측(설계 4) 크기·재배치 수 모두 맞음.
- 증거 `06_reconstruction/evidence/x86-gdt_idt.md`, `x86-idt.diff`.

## 43. S5-P18 세부 계획 — `machdep/i386/dma_buf.c`, `dbl_fault.c` (코딩 전, 2026-10-01)

원본 사실(capstone, Python):
- `dma_buf.c`(seq 246 확장): 0x189748–0x18991c(468 B) = `_dma_buf_initialize` 0x189748, `_dma_buf_alloc` 0x18980c, `_dma_buf_free` 0x18987c, 이름 없는 `FUN_001898bc`(`alloc_cnvmem(page_size, page_size)` + `bzero` = Darwin 정적 `dma_buf_sm_create`, `DMA_BUF_SM_LEN = PAGE_SIZE` dma_exported.h:41), `FUN_001898ec`(`alloc_cnvmem(0x10000, 0x10000)` + `bzero` = 정적 `dma_buf_lg_create`, `DMA_BUF_LG_LEN = 64*1024` :42). 함수 사이 `90`. 앞 `00`×3(`_get_dma_count` 끝 0x189745), 뒤 틈 0(다음 0x18991c).
- `dbl_fault.c`(seq 247): `_dbf_init` 0x18991c, `_dbf_handler` 0x1899d0, 본문 끝 0x189a5a, 그 뒤 `90 90`, 다음 `_copyin` 0x189a5c. 호출 `_pmap_kernel`, `_kernel_trap`.
- 전역(원본 `__common`, 섹션 6, 이름순 배치): `_dma_buf_lg` 0x1f7510, `_dma_buf_sm` 0x1f7520(각 다음까지 16 B = `dma_buf_type_t` 4 필드), `_dbf_stack` 0x1f7530(1024 B = DBF_STACK_SIZE), `_dbf_state` 0x1f7930(96 B), `_dbf_tss` 0x1f7990(다음 `_cpu_config` 까지 104 B).

설계:
1. 두 파일 Darwin 그대로(수정 없음).
2. 36.1 방식: `-fno-common` 빌드(바이트 차이 0)와 `-fno-common` 없는 변형(OBJECT_MATCH, 공통 기호 크기 ≤ 원본 다음 심볼까지 간격)을 모두 확인.
3. `dbl_fault.o` 의 끝: `__text` 가 318 B 면 뒤 `90 90` 은 원본에서 객체 사이 채움(00 아님) → 경계 증명 불완전(A*); 320 B 로 `90 90` 을 포함하면 뒤 틈 0 → A. 빌드 전에는 판정하지 않는다.
4. 예측(R5): `dma_buf.o` `__text` 468 B, `__common`(또는 변형의 공통 기호) 2 × 16 B; `dbl_fault.o` `__common` 3 기호 1024/96/104 B. 옵션 `-O3`(대조 `-O2`, `-O4`). 진단 전처리로 미정의 식별자 확인.

### 43.1 codex 교차검토(QP18) 판정과 실측

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| DMA 세 함수·정적 두 함수 흐름 일치; 0x18976e/0x189778 에서 `create_fcn` 에 0x1898bc/0x1898ec 저장 → 이름 없는 두 함수 = `dma_buf_sm_create`/`dma_buf_lg_create` | 빌드 L1(변형) 5 함수 MATCH(정적 두 함수 포함) | ✅ |
| dbl_fault TSS·saved state 필드 오프셋 전부 일치(tss.h:41, machdep/i386/thread.h:88, seg.h:140 …) | 세 줄 열람; L1(변형) 2 함수 MATCH | ✅ |
| **`thread_saved_state_t` 는 92 B**(계획의 96 B 는 틀림 — 원본 간격 96 은 다음 심볼까지 거리일 뿐) | 변형 빌드 공통 기호 `_dbf_state` 크기 92 실측 | ✅ **내 예측 오류**, 설계 4 정정 |
| 07_kernel 에 `dma_buf_internal.h`·`dma_exported.h`·`trap.h` 없음 | `ls` 0 건 — 이번 채택에서 들어감 | ✅ |
| `PAGE_SIZE → page_size` 유지, NCPUS=1·잠금 저장소 유지(pcb +0x28), `make_task_gate` 4 인자 형태 유지 | 기존 설정 그대로 빌드해 MATCH | ✅ 변경 없음 |

실측(`s5p18-pre-1`, Darwin 그대로): 두 파일 모두 `-O2` = `-O3` = `-O4`.
- `dma_buf.o`: `__text` 468 B, `-fno-common` 판 바이트 차이 0(공통 영역 참조 4 개는 배치 모호로 미검증), 변형(`-fno-common` 없음) OBJECT_MATCH, 공통 기호 16/16 B = 원본 간격 16/16. 두 판의 재배치 위치 24 개 같고 필드 밖 바이트 같음.
- `dbl_fault.o`: `__text` **320 B**(뒤 `90 90` 포함 → 원본 뒤 틈 0), `-fno-common` 판 바이트 차이 0, 변형 OBJECT_MATCH, 공통 기호 1024/92/104 B ≤ 원본 간격 1024/96/104. 재배치 위치 23 개 같고 필드 밖 바이트 같음. `-fno-common` 판에서 `_dbf_init` 판정이 `DIFF` 로 나온 것은 크기 0 인 `__data` 가 `__common` 시작과 같은 주소라 scattered 재배치 대상이 `__data` 로 잘못 분류된 도구 한계(바이트 차이 0, 참조 차이 0).

### 43.2 S5-P18 결과 (2026-10-01) — `dma_buf.c`, `dbl_fault.c` 확정(A 2 개)

- 두 파일 Darwin 그대로 채택(새 5 개). 07_kernel 빌드 `s5p18-build-1` 이 진단 빌드와 모두 같음.
- 36.1 기준 충족(`-fno-common` 바이트 차이 0 + 변형 OBJECT_MATCH + 크기 ≤ 간격). `dbl_fault.o` `__text` 320 B 가 뒤 `90 90` 을 포함 → 뒤 틈 0, **A**. `dma_buf` 도 **A**(앞 `00`×3, 뒤 0).
- 정적 함수 두 개(`dma_buf_sm_create`, `dma_buf_lg_create`)도 함수 표에 기록.
- 증거 `06_reconstruction/evidence/x86-dma_buf_dbl_fault.md`.

## 44. S5-P19 세부 계획 — `vm/vm_mem_region.c` (코딩 전, 2026-10-01)

후보 조사(Python, capstone): seq 138 `ipc_init.c`, 208 `vm_mem_region.c`, 254 `intr.c`, 195 `thread_swap.c`.
- **`ipc_init.c` 보류**: 원본 `_ipc_init`(0x146ed8–0x146f38)은 `MACH_OLD_VM_COPY` 분기의 `task_create(0,0,&ipc_soft_task)` → 실패 시 `panic` → `ipc_soft_map = ipc_soft_task->map` 은 있으나, Darwin 의 `vm_allocate(ipc_soft_map, &x, PAGE_SIZE, FALSE)`(ipc_init.c:201–213 블록; 44.1 에서 줄 범위 정정)와 두 번째 `kmem_suballoc`(`ipc_kernel_copy_map`, :219–220)가 없고 `_ipc_kernel_copy_map` 심볼도 없다. `MACH_OLD_VM_COPY`(MASTER:145 `<!newvm>`)는 07_kernel 에 아직 정의가 없고, `ipc_kernel_copy_map` 은 `ipc_kmsg.c` 에도 쓰인다 → 옵션 결정과 ipc_kmsg 와 함께 따로 계획.
- `intr.c`(뒤 `90` → `_spl0` 와 이어짐), `thread_swap.c` 는 다음 차례.

원본 사실(`vm_mem_region.c`, seq 208): 0x1787c4–0x1789cf(523 B), 함수 `_vm_mem_ppi`, `_vm_valid_page`, `_vm_phys_to_vm_page`, `_vm_region_to_vm_page`, `_vm_alloc_from_regions`(Darwin 정의 순서와 같음). 호출 `_panic` 2(문자열 0x1e0b14 `"mem_ppi"`, 0x1e0b1c `"vm_mem_alloc_from_regions"` — Darwin 의 두 `panic` 문자열과 같음). 데이터 `_mem_region` 0x1f6e60, `_num_regions` 0x1f6e98, `_page_shift`(`atop`). `ASSERT` 는 `MACH_ASSERT`=0 이면 사라질 것(kern/assert.h). 앞 `00`×3(`_vm_map_pmap_EXTERNAL` 끝 0x1787c1), 뒤 `00`, 다음 `_vm_object_init` 0x1789d0.

설계:
1. Darwin 그대로(수정 없음). `--prefer-07` 스테이징, 진단 전처리, `-O3`(대조 `-O2`, `-O4`), L1, 경계 증명서.
2. 예측(R5): `__text` 523 B, `__data` 에 문자열 두 개(`-fwritable-strings` 이므로 `__data`, 8 + 26 = 34 B), 함수 5 개.
3. 불일치면 채택하지 않고 차이 기록.

### 44.1 codex 교차검토(QP19) 판정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| 5 함수 의미 일치, `struct mem_region` 28 B(오프셋 0x00/0x04/0x0c/0x14/0x18, vm/pmap.h:167–178), `vm_page` 원소 48 B | pmap.h:167–178 열람; 빌드 L1 5 함수 MATCH(차이 0) | ✅ |
| `vm_region_to_vm_page` 는 `vm_phys_to_vm_page` 를 인라인(두 구간 104 B 같음) | L1 MATCH 로 같은 결과 | ✅ |
| `ASSERT` 는 kern/assert.h 와 `MACH_ASSERT`=0 으로 사라짐 | 빌드 결과 호출 2 개(`panic`)뿐, L1 일치 | ✅ |
| ipc_init 보류 타당; 빠진 블록은 **201–213**(내가 198–213 으로 잘못 씀), 두 번째 suballoc 219–220; `mach/features.h:49–50` 은 `meta_features.h` 를 import 할 뿐 | ipc_init.c:196–222 열람(201–213 확인), features.h:49–50 열람 | ✅ 44 절 정정 |
| 예측 523 B·34 B 맞음; 범위는 반열림으로 | 빌드 실측 같음 | ✅ |

### 44.2 S5-P19 결과 (2026-10-01) — `vm_mem_region.c` 확정(A)

- Darwin 그대로. 진단 `s5p19-pre-1`: `-O3` = `-O4` OBJECT_MATCH(5 함수, 차이 0, 참조 27, `__data` 34 B 0x1e0b14 L1d 확인), `-O2` 다름(435 B). 07_kernel 빌드로 같은 SHA 확인 후 기록. 경계 앞 `00`×3·뒤 `00`×1(최소 채움) → **A**.
- 증거 `06_reconstruction/evidence/x86-vm_mem_region.md`.

## 45. S5-P20 세부 계획 — `kern/thread_swap.c` (코딩 전, 2026-10-01)

원본 사실(capstone, Python): seq 195, [0x168ed4, 0x169124) 592 B — `_swapper_init` 0x168ed4, `_thread_swapin` 0x168efc, `_thread_doswapin` 0x168f90, `_swapin_thread_continue` 0x168ff4, `_swapin_thread` 0x16910c(Darwin 정의 순서). 앞 틈 0(`_current_thread_EXTERNAL` 끝 0x168ed4), 뒤 틈 0(다음 `_calloutInitialize` 0x169124).
- 호출: `thread_wakeup_prim` 1, `panic` 1(문자열 0x1dfcac `"thread_swapin"`), `stack_alloc` 2(`thread_doswapin` 본체 + `swapin_thread_continue` 안 인라인으로 보임), `splsched`/`splx` 각 4, `thread_setrun` 2, `assert_wait` 1, **`thread_block_with_continuation`** 1, `stack_privilege` 1, `swapin_thread_continue` 1.
- 데이터: `_swapin_queue` 0x1f6d90(8 B), `_swapper_lock_data` 0x1f6d98(4 B), 둘 다 `__common`(원본 이름순 배치).
- 후보 비교: Mach4 판은 `thread_block(swapin_thread_continue)` 이고 `current_thread()->vm_privilege = TRUE;` 가 없다; NeXTMach 판은 `swap_state`·`make_unswappable` 등 구조가 다르다 → Darwin 판이 원본 호출 목록과 맞음.

설계:
1. Darwin 그대로(수정 없음). `kern/counters.h` 등 07_kernel 에 없는 헤더는 읽힌 것만 채택.
2. 36.1 방식(`__common` 기호 2 개): `-fno-common` 빌드 바이트 차이 0 + 변형 OBJECT_MATCH + 크기(8, 4) ≤ 원본 간격(8, 4).
3. 예측(R5): `__text` 592 B, 함수 5 개, `__data` 에 문자열 `"thread_swapin"` 14 B. 옵션 `-O3`(대조 `-O2`, `-O4`).

### 45.1 진단 빌드 결과·codex 교차검토(QP20) 판정 → 설계 변경(복원 수정 1 줄)

진단 `s5p20-pre-1`(Darwin 그대로): `-O3` = `-O4` `__text` **604 B**(원본 592 B, 차이 12 B — Python). 앞 네 함수 MATCH(차이 0), `_swapin_thread` 만 DIFF: 빌드는 `stack_privilege` 호출 뒤 `mov eax,[current_thread]; mov dword [eax+0x78],1`(12 B)을 하는데 원본(0x16910c–0x169124)은 `stack_privilege` 다음 바로 `swapin_thread_continue` 호출. `-O2` 516 B.

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| 앞 네 함수 Darwin 흐름 일치(상태 `thread+0x4c`, 마스크 0x300, TH_RUN 4 …) | 진단 빌드 L1 네 함수 MATCH, 차이 0 | ✅ |
| **`swapin_thread` 에 `vm_privilege` 저장이 없다** — Darwin thread_swap.c:211 이 더함; 07 thread.h:164 `vm_privilege` +0x78(32 비트) | thread_swap.c:211 열람, 원본·빌드 디스어셈블 비교(위), thread.tsv `vm_privilege 0x78 match` | ✅ 설계 변경 |
| `thread_doswapin` 이 continuation 안에 인라인(stack_alloc 0x168f9e, 0x169064) | 진단 빌드에서 그 함수 MATCH | ✅ |
| `counter()` 는 counters.h:66 `#if MACH_COUNTERS` — 미정의라 비어 있고 원본에도 증가 없음 | counters.h:66 열람, 진단 미정의 목록에 `MACH_COUNTERS`, continuation MATCH | ✅ (옵션은 정의하지 않고 둠: `#if` 미정의 = 0) |
| `__common` 8/4 B, 잠금은 MACH_SLOCKS(DRIVERKIT) 로 4 B | 변형 빌드 공통 기호 8/4 실측 | ✅ |

설계 변경: Darwin `kern/thread_swap.c` 에서 :211 `current_thread()->vm_privilege = TRUE;` 한 줄 삭제(D014 복원 수정, 근거 원본 0x16910c–0x169124) + 머리말 뒤 수정 주석. 이 한 줄은 Mach4 판(mach4 thread_swap.c `swapin_thread`)에도 없다. 예측: `__text` 592 B, 다섯 함수 MATCH.

### 45.2 S5-P20 결과 (2026-10-01) — `kern/thread_swap.c` 확정(A, 복원 수정)

- 복원 수정 1 줄(`vm_privilege` 저장 삭제) + 수정 주석. `.i` 차이는 의도한 것만. `-O3` = `-O4` 592 B(예측대로), OBJECT_MATCH(5 함수). `-fno-common` 판과 변형 모두 OBJECT_MATCH, 공통 크기 8/4 = 원본 간격. 경계 앞 0·뒤 0 → **A**.
- 증거 `06_reconstruction/evidence/x86-thread_swap.md`, `x86-thread_swap.diff`.

## 46. S1-F 세부 계획 — 정적 zero-fill 의 참조 기반 배치 판정, 참조 없는 영역의 등급 처리; S5-P21 `intr.c` (코딩 전, 2026-10-01)

계기(진단 `s5p21-pre-1`, Darwin `machdep/i386/intr.c` 그대로, 계획 전 사실 수집용 빌드): 원본 객체 [0x18b514, 0x18c9da) 5318 B(33 함수, Darwin 정의 순서, `send_eoi`·`set_*`·`lower_ipl` 등 static inline 은 인라인), 앞 `00 00`(`_in_cksum` 끝 0x18b512), 뒤 `00 00`. 빌드 `-O3` = `-O4` `__text` 5318 B, **33 함수 모두 바이트 차이 0**, `-O2` 2930 B. 섹션: `__data` 86 B(0x1e2208, L1d 확인), `__common` 12 B(`_intr_cnt`, 심볼로 배치), **`__bss` 266 B(정적 표 `dispatch_table`·`ipl_mask`·`defer_table`·`current_ipl` 등, 심볼 없음)는 참조로 0x1e7618 에 추정되지만 도구가 설계상 미검증**(l1_compare.py: zero-fill 은 심볼로 배치될 때만 placement-only), **`__TEXT,__const` 4 B(`18 00 20 00`, 컴파일러 생성, 참조 0 — .i 에 `const` 없음)는 배치 불가**(원본 `__TEXT,__const` 에 같은 4 B 가 9 곳). 함수 판정은 `__bss` 의존 때문에 30 개가 MATCH_UNVERIFIED.

`__bss` 추정의 근거(Python): 참조 341 개, 서로 다른 오프셋 9 곳(0, 12, 204, 220, 252, 256, 260, 262, 264)이 모두 같은 Δ; 추정 구간 [0x1e7618, 0x1e7722) 은 원본 `__bss` [0x1e56c0, 0x1e8750) 안; 그 구간 ±64 B 안에 원본 이름 심볼 없음.

설계(코드 변경은 codex 검토·내 검증 뒤):
1. `l1_compare.py`: zero-fill 섹션이 참조로 추정(Δ 하나)되고 (a) 서로 다른 참조 오프셋 ≥ 2, (b) 추정 구간이 원본의 같은 이름 섹션 안, (c) 추정 구간 안에 원본 이름 심볼 없음 — 셋을 모두 만족하면 `placement = 'inferred from N references at K offsets (zero-fill)'`, `sec_ok = 'placement-only'`(심볼 배치와 같은 취급). 하나라도 어기면 지금처럼 미검증. 기존 동작(다른 섹션, 심볼 배치 zero-fill)은 그대로.
2. 시험: 기존 시험 전부 통과; 확정 객체 33 개의 L1 판정 변화 없음(재실행 비교); `intr` 의 `__bss` 가 새 판정으로; 음성 시험 — 원본 사본에서 참조 하나의 값을 4 바이트 어긋나게 바꾸면 Δ 가 둘 → ambiguous.
3. 참조가 전혀 없는 섹션(`intr` `__const` 4 B, `bios` `__bss` 16 B): 위치를 보일 방법이 없으므로 **등급 A 를 주지 않고 A\* 로 두며 사유 칸에 "unreferenced <섹션> <크기> not placeable" 를 적는다**(A\* 의 뜻을 넓힘 — 17.1 의 등급 정의 문구 수정) **[46.1 에서 기각: A\* 는 그대로, 새 등급 P; 정의 위치는 17.1 이 아니라 `06_reconstruction/README.md:22`(도입 28.2)]**. 그 섹션 말고 모든 것이 일치해야 한다(함수 바이트·참조·다른 섹션).
4. 적용: `intr.c`(Darwin 그대로 — 수정 없음) 재판정, `bios.c`(41.2 에서 보류) 재판정.

### 46.1 codex 교차검토(QP21) 판정 → 설계 수정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| 참조 341, Δ 하나; "9 오프셋" 은 재배치 기준 수이고 실제 대상 오프셋은 25 | 목적 파일 직접 계산: refs 341, 기준 9, 대상 25 | ✅ 문구 정정 |
| 제안 조건은 **일관되게 4 B 밀린 배치도 통과**(반례) — 내부 상대 배치 일관성만 보일 뿐 소유·절대 위치 증명은 아니다; 상태를 "reference-inferred" 로 따로 둘 것 | 반례의 논리 확인(조건 a–c 는 Δ 하나·구간 안·심볼 없음뿐) | ✅ → **도구 판정 규칙을 바꾸지 않음** |
| `__const` 4 B 는 참조 0(349 재배치 전수, SECTDIFF 없음); 출처는 쓰이지 않는 `ltr()`/`lldt()`(cpu_inline.h:126–140)의 선택자 `TSS_SEL` 0x18·`LDT_SEL` 0x20 | cpu_inline.h:120–140, seg.h:63/70 열람; 진단 목적 파일 재배치 전수(내 계산: `__const` 대상 0) | ✅ ("`.i` 에 const 없음" 은 근거로 부적절 — 철회) |
| 원본 0x1d14e4 가 링크 순서상 그럴듯한 후보(0x1d14dc/e0/e4/e8 연속) 이나 유일하지 않음 | 원본 `__TEXT,__const` 9 곳 실측(41 절 계산) | ⚖️ 기록만, 판정에 쓰지 않음 |
| A\* 를 넓히지 말고 별도 등급(P); 정의는 README:22(도입 28.2); README:20 도 손볼 것 | README:20·22, 계획 28.2 열람 | ✅ |
| 확정 33 객체는 추정 zero-fill 에 의존하지 않음 | 09_validation 의 L1 JSON 전수: 추정 zero-fill 은 `s5p21` 2 건뿐 | ✅ |

**내 기존 기록의 불일치(정정 대상)**: README:20 은 `compared/high` 에 "목적 파일 OBJECT_MATCH" 를 요구하는데, 41.2 에서 `_bios32` 를 객체 미확정인 채 `compared/high` 로 올렸다.

수정 설계(46 의 1–4 대체):
1. `l1_compare.py` 는 바꾸지 않는다. 참조로만 배치되는 zero-fill 은 **별도 검사 기록**(`09_validation/reconstruction/s5p21-zerofill-check-20261001.json`: 참조 수, 기준·대상 오프셋, Δ, 정렬, 원본 섹션 범위 안 여부, 이름 심볼 없음, 확정 객체의 zero-fill 배치와 겹침 없음)으로 남기고 상태를 **reference-inferred** 로 부른다. 증명이 아니라 정황이다.
2. 새 등급 **P**(부분 검증): 파일 기반 섹션은 모두 바이트·참조 일치, 다른 zero-fill 은 심볼 배치이거나 reference-inferred(목록 명시), 참조가 전혀 없는 섹션은 "unplaced, unverified" 로 목록 명시. P 는 OBJECT_MATCH 가 아니다. README:22 에 정의 추가.
3. 함수 상태(README:20 에 조건 추가): `compared`+`high` = 함수 L1 MATCH(모든 바이트·참조 검증) 이고 객체가 A/A\*/P; 함수 바이트가 같고 미검증 참조가 reference-inferred zero-fill 로만 가는 경우 `compared`+`medium`.
4. 적용: `bios.c` → P(`__bss` 16 B unreferenced), `_bios32` 는 함수 MATCH 이므로 `high` 유지(조건 3 으로 정당화). `intr.c` → Darwin 그대로 채택, P(`__bss` 266 B reference-inferred, `__const` 4 B unreferenced); 함수 MATCH 3 개 `high`, MATCH_UNVERIFIED 30 개 `medium`.

### 46.2 codex 재검토(QP21b) 판정과 최종 설계

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| intr: MATCH 3(`_intr_disbl`, `_intr_enbl`, `_ipltospl`), MATCH_UNVERIFIED 30, 미검증 원인은 `__bss`(섹션 2) 하나뿐, 함수별 미검증 참조·차이 0 | 내 계산(L1 JSON 집계)과 같음 | ✅ |
| P 정의 문구: "파일 기반 섹션 모두" 는 `__const` 예외와 모순 → "목록에 적은 참조 없는 미배치 섹션을 뺀 모든 파일 기반 섹션"; 바이트 차이 0 만으로는 부족(재배치 필드 제외) → 참조 차이·미지원·모호 배치 없음까지 | 46.1 문구 재검토 | ✅ 문구 강화 |
| `medium` 은 MATCH_UNVERIFIED 이면서 미검증 의존이 **검사 기록이 있는** reference-inferred zero-fill 뿐일 때만 | — | ✅ |
| 검사 기록 항목(입력 SHA, 섹션 정보, 재배치 전수와 식, Δ 일치, 정렬·포함·심볼 검사, 겹침 검사, 음성 검사) | — | ✅ 도구에 반영 |
| 확정 객체의 zero-fill 배치는 모두 원본 `__common` 에 있어 intr `__bss` 와 겹칠 수 없다(→ 겹침 검사는 소유의 적극적 증거가 못 됨) | 10 심볼 모두 섹션 6(`__common`, 0x1e8750~) 확인 | ✅ 기록 |
| P 는 별도 표 `objects_partial.tsv`; `objects_confirmed.tsv` 를 읽는 스크립트 없음 | `grep -rn objects_confirmed 10_tools` 0 건 | ✅ |

최종 설계:
1. 새 도구 `10_tools/reconstruction/zerofill_check.py`(L1 은 그대로): 목적 파일의 지정 zero-fill 섹션을 가리키는 모든 재배치(일반·scattered; PAIR/SECTDIFF 가 있으면 실패)를 원본 값과 대조해 Δ 를 각각 계산, 전부 같을 때만 후보 배치; 정렬·원본 같은 이름 zero-fill 섹션 포함·이름 심볼 없음·주어진 기존 배치와 겹침 없음 검사; 음성 검사(원본 값 하나를 4 B 바꾼 사본 → Δ 불일치로 실패해야 함). 출력 JSON 에 입력 SHA-256, 명령, 재배치별 기록, 결론 `reference-inferred` 또는 `fail`.
2. README:20/22 수정 — `high` 는 함수 L1 MATCH 이고 객체가 A/A\*/P(`objects_partial.tsv`); `medium` 은 위 조건; P 정의(46.2 문구) 추가; `objects_partial.tsv` 설명.
3. `objects_partial.tsv` 새 표(열: object, arch, binary_sha256, text_start, text_end_exclusive, source, build, grade, unverified_sections, gap_before, gap_after, evidence): `bios`(P, `__bss` 16 B unreferenced), `intr`(P, `__bss` 266 B reference-inferred, `__const` 4 B unreferenced).
4. `intr.c` Darwin 그대로 07_kernel 채택, 07_kernel 빌드로 같은 SHA 확인, 함수 33 행(high 3, medium 30), 증거 `x86-intr.md`.

### 46.3 결과 (2026-10-01) — 새 등급 P, `intr.c`·`bios.c` 를 P 로 기록

- 도구 `10_tools/reconstruction/zerofill_check.py`(L1 은 그대로). `intr` `__bss`: reference-inferred(참조 341, 대상 오프셋 25, Δ 0x1e60f4, 음성 검사 감지) — `09_validation/reconstruction/s5p21-zerofill-check-20261001.json`. `bios` `__bss`: 참조 0 → `fail`(= unreferenced 로 분류).
- README:20–22 정의 수정(`high`/`medium` 조건, 등급 P). 새 표 `06_reconstruction/objects_partial.tsv`(bios, intr). `objects_confirmed.tsv` 는 A/A\* 만 유지.
- `intr.c` Darwin 그대로 채택(새 9 파일), 07_kernel 빌드가 진단과 같은 SHA. 함수 33 행: high 3, medium 30. `_bios32` 행 비고를 "object grade P" 로 갱신(41.2 의 README 불일치 해소).
- 증거 `06_reconstruction/evidence/x86-intr.md`.

## 47. S5-P22 세부 계획 — IPC 네 파일 `ipc_space.c`, `ipc_hash.c`, `ipc_pset.c` (+ `ipc_object.h`), `ipc_sched.c` 보류 (코딩 전, 2026-10-01)

사실(계획 전 진단 `s5p22-pre-1` Darwin 그대로, 탐침 `s5p22-probe-1` 스테이징 사본만 수정; 계산 Python):
- `ipc_space.c` [0x1506b0, 0x150a05) 853 B, 5 함수, 앞 `00`(0x1506af), 뒤 `00`×3. 진단: `-O3` = `-O4` 853 B, 바이트 차이 0; `-fno-common` 판은 `__common` 12 B 배치 추정·미검증, 변형(`-fno-common` 없음) OBJECT_MATCH.
- `ipc_hash.c` [0x146908, 0x146dbe) 1206 B, 11 함수, 앞·뒤 `00 00`. 진단 1190 B(16 B 짧음): `_ipc_hash_lookup` 만 원본 80 B 대 64 B. 원본은 결과를 0/1 로 정규화(`xor esi,esi` … `mov esi,1`) — **Mach4 판의 `return (local || (is_tree_hash > 0 && global));`**(mach4 ipc_hash.c:73–76)와 같은 모양, Darwin 판(ipc_hash.c:133–141)은 `rv` 를 그대로 반환. 탐침에서 이 본문만 바꾸면 1206 B, 변형 OBJECT_MATCH(11 함수).
- `ipc_pset.c` [0x14d61c, 0x14db06) 1258 B, 6 함수, 앞·뒤 `00 00`. 진단 1280 B(22 B 김): `_ipc_pset_move`·`_ipc_pset_destroy` 에서 빌드만 값을 스택에 내렸다 다시 읽음. 원인: Darwin `ipc/ipc_object.h:142` `io_check_unlock` 의 `volatile ipc_object_refs_t _refs` — Mach4(ipc_object.h:94)는 `volatile` 없음. 탐침에서 `volatile` 만 지우면 1258 B, `-fno-common` 판·변형 모두 OBJECT_MATCH.
- `ipc_sched.c` [0x159000, 0x1593e1) 993 B: `_thread_handoff` 만 다름(원본 309 B 대 301 B) — 원본은 `stack_handoff` 앞에 `switch_unix_context(new)`(원본 0x106e0c, BSD 쪽) 호출이 있고 이 함수는 어떤 참조 트리에도 없다(grep 0 건) → 참조에 없는 코드를 써야 하므로 **보류**(time_stamp.c 와 같은 사유, 사용자 결정 대기).

설계:
1. `ipc_space.c`: Darwin 그대로, 36.1 방식(`-fno-common` 바이트 0 + 변형 OBJECT_MATCH + 공통 크기 ≤ 간격).
2. `ipc_hash.c`: 복원 수정 — `ipc_hash_lookup` 본문(Darwin :133–141)을 Mach4 ipc_hash.c:73–76 의 return 식으로 교체(출처 https://github.com/openmach/mach4.git 69fa77870f20d854c875135e116ebc80b118e7ff `kernel/ipc/ipc_hash.c:73–76`; 같은 CMU 고지(1991,1990,1989)가 Darwin 파일에 이미 있음 — 파일 머리말 유지). 36.1 방식.
3. `ipc/ipc_object.h`: 복원 수정(헤더) — :142 의 `volatile` 삭제(Mach4 :94 와 같은 형태). **헤더 변경이므로 회귀**: 확정 33 + 부분 2 객체를 원래 명령으로 다시 빌드해 SHA 동일 확인(`io_check_unlock` 을 쓰는 객체가 있으면 바뀔 수 있고, 그러면 원본과 다시 대조).
4. `ipc_pset.c`: Darwin 그대로(헤더 수정 반영), 36.1 방식 확인.
5. 예측(R5): `ipc_space` 853 B, `ipc_hash` 1206 B, `ipc_pset` 1258 B; `-O2` 는 셋 모두 `-O3` 와 다른 목적 파일(실측: ipc_space 854 B, ipc_hash 1206 B 이나 SHA 다름, ipc_pset 882 B — 판정에 쓰지 않음).

### 47.1 codex 교차검토(QP22) 판정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| `ipc_hash_lookup` 의 Mach4 식은 바이트를 설명하는 "최소로 보인 교체 범위" 이지 유일한 원문은 아님; 나머지 10 함수는 이미 같음 | 진단 함수별 길이 비교(10 함수 같은 길이), 탐침 변형 OBJECT_MATCH | ✅ 문구: "minimal demonstrated replacement" |
| `volatile` 이 ipc_pset 차이의 원인; 탐침에서 move/destroy 일치 | 탐침 L1(두 판 모두 OBJECT_MATCH) | ✅ |
| 확정·부분 객체 중 이 매크로를 전개하는 것 없음 | 확정 빌드 `.i` 전수: `volatile ipc_object_refs_t _refs` 전개 0 곳 | ✅ (회귀는 그대로 수행) |
| 원본 방증: `_ipc_object_release` 0x14b888–0x14b896, `_ipc_port_release_send` 0x14d070– 이 참조 수를 레지스터에 둔 채 unlock | 0x14b888–0x14b898 디스어셈블 열람(`dec eax; xor edx,edx; xchg [ecx],edx; test eax,eax`) | ✅ (선언의 철자까지는 증명 아님) |
| `thread_handoff` 차이는 `switch_unix_context(new)` 호출 하나(바이트로는 변위 등 연쇄 변경); 참조 트리에 이름 없음 | 47 절 diff, grep 0 건 | ✅ 보류 유지 |
| `ipc_space` 공통 기호 `_ipc_space_kernel`/`_reply`/`_zone` 각 4 B = 원본 간격 4 | 변형 목적 파일 공통 기호와 원본 간격 Python 확인 | ✅ |
| CMU 고지는 "supporting documentation" 에도 요구 → `07_kernel/LICENSES` 에 CMU 고지 파일 추가; Mach4 출처는 PROVENANCE·MODIFICATIONS 에 함수 단위로 | mach4 ipc_hash.c:1–25 열람, AGENTS.md 규칙 | ✅ `LICENSES/CMU-MACH.txt` 추가 |

### 47.2 S5-P22 결과 (2026-10-01) — `ipc_space`, `ipc_hash`, `ipc_pset` 확정(A 3 개)

- 복원 수정 2: `ipc/ipc_object.h`(`io_check_unlock` 의 `volatile` 삭제), `ipc/ipc_hash.c`(`ipc_hash_lookup` 본문을 Mach4 :73–76 식으로). 새 `07_kernel/LICENSES/CMU-MACH.txt`.
- 07_kernel 빌드가 탐침과 같은 목적 파일. 세 객체 OBJECT_MATCH(ipc_space·ipc_hash 는 36.1 변형, ipc_pset 은 두 판 모두). 경계 최소 채움 → **A** 3 개. 회귀 35 객체 동일.
- `ipc_sched.c` 보류(사용자 결정 대기 목록에 추가: `time_stamp.c` 의 `kern_timestamp`, `ipc_sched.c` 의 `switch_unix_context` 호출).
- 증거 `06_reconstruction/evidence/x86-ipc_s5p22.md`.

## 48. 새 코드 작성 규칙(D016)과 첫 적용 — `kern/time_stamp.c`, `kern/ipc_sched.c` (코딩 전, 2026-10-01)

사용자 결정 D016: 참조 소스에 없는 코드를 원본 바이트에 맞춰 새로 써도 된다. 규칙:
- W1 **마지막 수단**: 참조 텍스트(Darwin/NeXTMach/Mach4)와 D014 복원 수정으로 원본 바이트를 낼 수 없을 때만. 그 사실(어느 참조와 어떻게 다른지)을 계획에 적는다.
- W2 **최소·근거 한정**: 원본 역어셈블에서 관찰한 동작(호출·인자·순서·상수, 주소 명시)만 쓴다. 이름은 원본 심볼표에 있는 것(함수·전역)과 참조 헤더의 타입·상수만 쓰고, 근거 없는 새 식별자를 만들지 않는다(지역 선언은 허용). 둘레 코드의 문체를 따른다.
- W3 **표시·기록**: 작성한 줄 바로 앞에 `/* Reconstructed from the original binary (no reference source), 2026-10-01: see 07_kernel/MODIFICATIONS.md */`; 머리말 뒤 수정 주석(D014 와 같음); MODIFICATIONS 행에 "authored" 와 근거 주소; PROVENANCE `changes` 에 "authored lines"; functions.tsv `source_id` 에 `+authored`. 작성분은 "역사적 원문" 이라 주장하지 않는다.
- W4 **판정**: 수정 후 L1 MATCH·객체 OBJECT_MATCH(또는 정의된 등급) 필수. 함수당 변형 3 회까지, 불일치면 기록하고 멈춘다.
- W5 **예측 먼저**: 빌드 전 크기·재배치·호출을 적는다.

적용 1 — `kern/time_stamp.c`(seq 196): 원본 `_kern_timestamp` [0x16a158, 0x16a196) 62 B(Python): `push 1; call _clock_value`(0x187b98) → 64 비트 반환(`edx:eax`) → `lea ebx,[ebp-8]; push ebx; push edx; push eax; call _ns_time_to_tsval`(0x160674) → `copyout(&ts, tsp, 8)` → 0 이 아니면 1(`KERN_INVALID_ADDRESS`), 아니면 0. 앞 틈 0(앞 `FUN_0016a140` 끝 0x16a158), 뒤 `00 00`, 다음 `_init_timers` 0x16a198.
- W1: Darwin(`clock_get_counter` + usec 계산, time_stamp.c:65–72), Mach4(`time` 복사), NeXTMach(`event_set_ts`) 모두 다름; `clock_value`·`ns_time_to_tsval` 은 어느 트리에도 없음(`grep -rnw` 0 건).
- 작성: Darwin 파일의 `#else m68k` 분기 본문(:65–72 — `usec_now`·`now` 선언 :65–66, 빈 줄 :67, 계산 4 문장 :68–72; 처음에 `:68–74` 로 잘못 적어 정정)을 `ns_time_to_tsval(clock_value(System), &ts);` 한 줄로 바꾸고, 파일 앞쪽에 선언 두 줄 `extern unsigned long long clock_value(clock_type_t which_clock);`, `extern void ns_time_to_tsval(unsigned long long value, struct tsval *tsp);` 를 둔다(`System` = 1 은 kern/clock.h:77–80 의 열거; `unsigned long long` 은 kernserv/clock_timer.h:40 의 `ns_time_t` 정의 — 그 헤더는 `bsd/sys/time.h` 를 끌어와 BSD 헤더 문제에 닿을 수 있어 쓰지 않음).
- 예측: `__text` 62 B, 외부 호출 3(`_clock_value`, `_ns_time_to_tsval`, `_copyout`), 데이터 없음.

적용 2 — `kern/ipc_sched.c`(seq 160): `_thread_handoff` 만 다름 — 원본 0x159342 `push ebx`(new), 0x159343 `call _switch_unix_context`(0x106e0c), 그다음 `stack_handoff`(0x15934a). Darwin ipc_sched.c:348 `stack_handoff(old, new);` 바로 앞.
- W1: 이 호출은 Darwin·Mach4·NeXTMach 어디에도 없음(`switch_unix_context` grep 0 건).
- 작성: :348 앞에 `switch_unix_context(new);` 한 줄. 선언은 넣지 않는다(K&R 암시 선언, 반환값 안 씀) — 바이트가 다르면 변형 2 로 `extern void switch_unix_context();` 추가.
- 예측: `__text` 993 B(원본과 같음), 함수 5 개 MATCH, 다른 네 함수는 진단에서 이미 MATCH.

### 48.1 codex 교차검토(QP23) 판정과 규칙 보강

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| 교체 범위는 :65–72(`#else` :64, `#endif` :73 유지) — 계획의 :68–74 는 틀림 | time_stamp.c 52–79 줄번호 출력 | ✅ (codex 회신 전에 내가 이미 정정) |
| 원본 `_kern_timestamp` 순서: `sub esp,8`(ts), `esi`=tsp, `push 1; call clock_value`, `ebx`=&ts, `push ebx/edx/eax; call ns_time_to_tsval`, `copyout(ebx, esi, 8)`, 0/1 반환, 인자 28 B 는 에필로그에서 한 번에 정리 | 0x16a158–0x16a196 디스어셈블(196 절 조사 출력) | ✅ — 정확한 레지스터·순서는 빌드로 판정 |
| `System`=1, `kern/clock.h` 는 time_stamp.c:47 에서 import; 07_kernel 에 아직 없음 → 스테이징·채택 필요 | clock.h:77–80, time_stamp.c:45–47 열람, `ls 07_kernel/src/kern/clock.h` 없음 | ✅ |
| 핵심 선언은 `clock_value` 의 64 비트 반환(암시 `int` 면 틀림); `ns_time_to_tsval` 의 `void` 는 역사적 선언의 증명 아님 | — | ✅ 기록 |
| ipc_sched: 삽입 위치 :348 앞, 원본 0x1592b5 에서 `new` 는 `ebx`, 0x159342 `push ebx`; 985 + 6 + 정렬 2 = 993 | 47 절 diff 와 일치, Python `985+6+2` = 993 | ✅ |
| 선언 바꾸기를 바이트 맞추기 수단으로 쓰지 말 것(`extern void f();` 는 C89 비원형 선언) | — | ✅ 설계 변형 2 삭제 |
| W 규칙 보강: 작성 줄의 라이선스, 기록 방식, 과적합 방지(모든 시도·예측·이유·.i·옵션 보존, 환경 고정, 이유 없는 꼼수 금지), W1 문구는 "검토한 후보로는 안 됨" | 저장소에 LICENSE 파일 없음(`ls`), AGENTS.md D013 은 라이선스 판단을 사용자에게 둠 | ✅ W6 추가 |
| `ns_time_to_tsval`(0x160674) 은 `kern/ns_timer.c`, `clock_value`(0x187b98) 는 `machdep/i386/machine_clock.c` 쪽일 가능성 | — | ⏭️ 이후 작업용 기록(판정에 안 씀) |

규칙 보강:
- W1 문구: "검토한 참조 후보(이름 명시)와 복원 수정으로는 원본 바이트가 나오지 않았다" 를 적는다(참조 기반 해법이 없다는 증명이 아님).
- W6 **라이선스·과적합**: Darwin 파일 안에 작성한 줄은 APSL 1.0 의 Modifications 로 그 파일의 고지 아래 두고 MODIFICATIONS 에 "authored" 로 적는다. 독립 새 파일의 라이선스는 사용자 판단(D013 원칙). 시도마다 예측·이유·`.i`·명령·결과를 보존하고, 빌드 환경·옵션은 고정한다. 이유 없는 군더더기·선언 바꾸기·레지스터 유도 같은 꼼수로 바이트를 맞추지 않는다.
- functions.tsv: `source_id` = `darwin01+authored`, 비고에 작성 줄 범위(선언 포함)·근거 주소·diff 경로.

설계 수정: ipc_sched 변형 2(선언 추가) 삭제 — 한 줄 삽입이 맞지 않으면 기록하고 멈춘다.

### 48.2 실행 기록 — 도구 수정, 변형 1 결과, 변형 2 근거 (2026-10-01)

- 도구 결함 수정: `stage_headers.py` 의 닫힘이 `-imacros src/generated/meta_features.h` 를 따라가지 않아 작은 닫힘(`time_stamp.c`)에서 생성 헤더가 빠져 진단 `s5p23-pre-1` 이 실패. `closure()` 가 처음부터 `generated/meta_features.h` 를 넣도록 고침 — 기존 닫힘과 비교해 빠진 파일 0, 추가만(`kern/priority.c` 는 `generated/mach_xp.h` 1 개 추가). 진단 `s5p23-pre-2`: 수정 없는 Darwin `time_stamp.o` 143 B.
- `ipc_sched.c`(한 줄 삽입): `s5p23-build-1` `-O2`=`-O3`=`-O4` 993 B, OBJECT_MATCH(5 함수, `__data` 15 B L1d) — 예측대로.
- `time_stamp.c` 변형 1(`ns_time_to_tsval(clock_value(System), &ts);`): 66 B, DIFF. 차이는 평가 순서뿐: 빌드는 `lea ebx,[ebp-8]; push ebx; push 1; call clock_value; add esp,4; push edx; push eax; call ns_time_to_tsval`, 원본은 `push 1; call clock_value; lea ebx,[ebp-8]; push ebx; push edx; push eax; call ns_time_to_tsval`(인자 정리를 미룸). 원본은 `clock_value` 결과를 먼저 얻은 뒤 두 번째 호출을 만든 모양 → 시도 파일·`.i` 보존(`09_validation/reconstruction/s5p23-attempts/time_stamp-v1.*`).
- 변형 2(근거: 위 호출 순서): 지역 변수에 먼저 받고 다음 문장에서 호출 — `unsigned long long now;` / `now = clock_value(System);` / `ns_time_to_tsval(now, &ts);`(지역 이름은 Darwin 판의 `now` 를 재사용, W2). 예측: 62 B, 호출 3, 원본과 같은 순서.

### 48.3 결과 (2026-10-01) — 새 코드 작성 첫 적용, A 2 개

- `time_stamp.c` 변형 2: 62 B, `-O2`=`-O3`=`-O4`, OBJECT_MATCH, 경계 앞 0·뒤 `00 00` → **A**. `ipc_sched.c`: 993 B OBJECT_MATCH, 경계 앞 `00`·뒤 `00`×3 → **A**.
- 함수 표: 두 함수(`kern_timestamp`, `thread_handoff`) `source_id` `darwin01+authored`, 나머지 4 함수 `darwin01`. MODIFICATIONS 에 "authored" 행 2 개. 시도 기록 `09_validation/reconstruction/s5p23-attempts/`.
- 증거 `06_reconstruction/evidence/x86-time_stamp.md`, `x86-ipc_sched.md`.

## 49. S5-P24 세부 계획 — 일괄 진단 결과, `kern/lock.c`·`ipc/ipc_splay.c` 확정 (코딩 전, 2026-10-01)

일괄 진단(계획 전 사실 수집, Darwin 그대로; `s5p24-pre-1` 은 두 파일 컴파일 실패로 게시 거부 → 두 파일을 빼고 `s5p24-pre-2`): 남은 "새 미해결 없음" Mach 쪽 41 구간 중 12 개.
- 컴파일 실패(보류): `ipc/ipc_mqueue.c` — 복원한 thread.h 에서 뺀 `ith_rcv_option`·`ith_list` 를 씀(원본은 다른 판, D015·24.x 의 thread 배치와 연결해 따로 계획); `kern/kernel_stack.c` — `mach_debug.h`(옵션 헤더 미정) 필요.
- **Darwin 그대로 OBJECT_MATCH**: `kern/lock.c`(seq 169, [0x15b504, 0x15bc2d) 1833 B, 16 함수, `-O2`=`-O3`, `__data` 81 B 심볼 배치, 앞 틈 0(`_stack_statistics` 끝 0x15b504), 뒤 `00`×3, 다음 `_clock_interrupt` 0x15bc30), `ipc/ipc_splay.c`(seq 148, [0x150a08, 0x151932) 3882 B, 11 함수, `-O3` 만(`-O2` 2150 B 다름), 앞 `00`×3(확정 `ipc_space` 의 뒤 틈과 같음), 뒤 `00 00`(확정 `ipc_table` 앞 틈과 같음)).
- 함수 일부만 다름(이후 조사): `kern/ipc_host.c`(`_mach_host_self`, `_host_self`), `kern/syscall_subr.c`(`_thread_switch`, 빌드 1028 B 대 S2-A 구간 1481 B — 구간 경계도 확인 필요), `kernserv/kern_notify.c`(`_notify_server_loop`), `ipc/ipc_marequest.c`(3 함수).
- 크기부터 다름(이후 조사): `ipc/ipc_notify.c`(2680 대 2302), `ipc/ipc_entry.c`(2826 대 2754), `ipc/ipc_object.c`(3098 대 3088), `kern/power.c`(949 대 933).

설계: `lock.c`, `ipc_splay.c` 를 Darwin 그대로 채택(읽힌 파일 중 07_kernel 에 없는 것만), 07_kernel 빌드로 진단과 같은 SHA 확인, 경계 증명서, 등급 A 기록. 예측: 진단과 같은 SHA(lock `-O3`, ipc_splay `-O3`).

### 49.1 codex 교차검토(QP24) 판정과 추가 사실

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| lock·ipc_splay OBJECT_MATCH 진짜, zero-fill·공통 없음; lock `__data` 81 B = `lock_wait_time` 0 + 두 panic 문자열 | 원본 0x1deddc 81 B 덤프(`00×4`, 두 문자열) | ✅ |
| 경계 바이트 맞음; 단 lock 앞 틈 0 은 별개 객체의 독립 증명이 아님(`_stack_statistics` 는 kernel_stack.c 로 강하게 귀속) | 41–49 절 Python 값과 같음 | ✅ 증거 문서에 한계 명시 |
| `kernel_stack.c` 는 원본에 `_stack_statistics`·`_stack_finalize`·`_stack_init` 이 있어 `MACH_DEBUG=1` 후보 | — | ⏭️ 이후 계획에서 검증 |
| syscall_subr S2-A 구간 1481 − 1028 = 453 B 는 `_map_fd` [0x165784, 0x165949)(NeXTMach syscall_subr.c:637 에도 있음); 공유 구간의 차이는 0x165516 변위 0x80 대 0x88 하나 | Python 453 = 0x165949 − 0x165784, `_map_fd` 심볼 0x165784, NeXTMach :637 열람, 0x165514 `mov eax,[eax+0x88]` | ✅ |
| kern_notify `__bss` 20 B 추정·미검증, ipc_marequest 는 데이터 불일치 포함 | — | ✅ 조사 메모 |

추가 사실(내 조사): `kern/ipc_host.c` 의 `_mach_host_self`·`_host_self` 차이와 syscall_subr 의 한 바이트는 같은 원인 — `current_space()` 가 읽는 `task->itk_space` 가 원본 +0x88, 07_kernel `kern/task.h:123` 판은 +0x80(8 B 차이). → `struct task` 배치 복원(24 절 thread·vm_object 와 같은 방법)을 다음 계획(50)으로.

### 49.2 S5-P24 결과 (2026-10-01) — `lock.c`, `ipc_splay.c` 확정(A 2 개)

- Darwin 그대로 채택(새 2 파일). 07_kernel 빌드가 진단과 같음. lock(16 함수, `__data` 81 B), ipc_splay(11 함수) OBJECT_MATCH, 경계 최소 채움 → **A**. lock 앞 틈 0 의 한계는 증거·objects 표에 적음.
- 증거 `06_reconstruction/evidence/x86-lock_ipc_splay.md`.

## 50. S4-B3 세부 계획 — `struct task` 배치 복원(24 절 방법) (코딩 전, 2026-10-01)

계기: 49.1 — `ipc_host.c` `_mach_host_self`/`_host_self` 와 `syscall_subr.c`(0x165514) 가 `task->itk_space` 를 +0x88 에서 읽는데 07_kernel `kern/task.h` 판은 +0x80.

원본 근거(capstone; 계산 Python):
- `sizeof(struct task)` = **0x8c**(140): `_task_init` 0x165978 `push 0x8c` → `_zinit`.
- `_task_create` 0x165a20–0x165beb 의 저장: `ref_count` +4(=2), `map` +0xc, `lock` +0, `thread_list` +0x1c/+0x20(자기 연결), `thread_list_lock` +0x28, `suspend_count` +0x18, `active` +8(=1), `user_stop_count` **+0x44**, `thread_count` +0x24, `pcb_common` **+0x40**(=0), `kernel_vm_space` **+0x50**(=0), 시간 4 워드 **+0x54/+0x58/+0x5c/+0x60**, `kernel_privilege` **+0x4c**, `processor_set` +0x2c, `priority` **+0x48**(=10 BASEPRI_USER), `may_assign` +0x30(=1), `assign_active` +0x34(=0); 그리고 Darwin 에 없는 **`zalloc(u_task_zone)` 결과를 +0x38 에 저장**하고 `_utask_zero(task)` 호출. `_task_init` 0x16599a/0x1659a1: kernel_task 의 +0x4c(`kernel_privilege`)·+0x50(`kernel_vm_space`) = 1.
- `_mach_ports_register` 0x15a030: `cmp esi,4`(portsCnt > 4), 루프 `cmp ebx,3`(i < 4), 지역 배열 16 B, `itk_registered` 접근 `[ecx+ebx*4+0x78]`; `_mach_ports_lookup` 0x15a104: `kalloc(0x10)`, `*portsCnt = 4`, `[edi+ebx*4+0x78]` → **TASK_PORT_REGISTER_MAX = 4**, `itk_registered` +0x78.
- Darwin 판(07_kernel task.h, `TASK_PORT_REGISTER_MAX` 3 — mach/mach_param.h:86): `proc` +0x38 … `itk_registered` +0x74, `itk_space` +0x80, sizeof 0x84(탐침으로 확인 예정).

가설 H-task(최소 수정, D014):
1. `kern/task.h`: `struct proc *proc;`(:94) 앞에 `struct utask *u_address;` 한 필드 — 이름은 NeXTMach `mk-108.1/kern/task.h:178` 의 것(D015 와 같은 원칙: 역할은 원본 바이트, 이름은 NeXTMach 유래로 기록). 이로써 0x38 이후가 +4.
2. `mach/mach_param.h:86`: `TASK_PORT_REGISTER_MAX` 3 → 4(NeXTMach `mk-108.1/kern/mach_param.h:44` 도 4). 이로써 `itk_space` 가 추가 +4 → 0x88, sizeof 0x8c.
- 예측(Python): `u_address` 0x38, `proc` 0x3c, `pcb_common` 0x40, `user_stop_count` 0x44, `priority` 0x48, `kernel_privilege` 0x4c, `kernel_vm_space` 0x50, 시간 0x54–0x63, `itk_lock_data` 0x64, `itk_self` 0x68 … `itk_registered` 0x78(4 개), `itk_space` 0x88, sizeof 0x8c.

설계:
1. 스테이징 사본에 두 수정만 넣고 오프셋 탐침(24 절 `thr_probe.c` 방식: 상수 배열, 실행하지 않음)으로 모든 필드의 오프셋·크기와 sizeof 를 원본 근거와 대조 → 배치 표 `06_reconstruction/struct_layouts/task.tsv`.
2. 모두 맞으면 07_kernel 두 헤더에 복원 수정(수정 주석, MODIFICATIONS, diff, PROVENANCE). `mach_param.h` 는 공개 헤더이므로 이 상수를 쓰는 곳(Darwin 은 kern/ipc_tt.c 만, grep)을 기록.
3. 회귀: 확정 40 + 부분 2 객체 재빌드, SHA 동일 확인(이 필드들을 쓰는 확정 객체는 원본과 이미 일치했으므로 변화가 없어야 함 — 바뀌면 원인 분석).
4. 그다음 `ipc_host.c`(Darwin 그대로)·`syscall_subr.c` 를 다시 진단(syscall_subr 은 원본 구간에 NeXTMach 의 `map_fd` 가 함께 있으므로 별도 계획).
5. 한계: `task_create` 의 `proc = 0` 은 원본에서 `_utask_zero`(0x106dfd `mov [ebx+0x3c],0`) 안으로 옮겨져 있고(50.1 정정), `u_task_zone`·`utask_zero` 는 task.c 의 차이 — 이번 범위 밖(task.c 계획에서).

### 50.1 codex 교차검토(QP25) 판정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| 계획의 원본 오프셋 주장 모두 맞음; 추가 근거 — `_ipc_task_init` `itk_self` +0x68(0x159440), `itk_sself` +0x6c(0x159449), `itk_space` +0x88(0x15944f), `itk_exception` +0x70, `itk_bootstrap` +0x74, `itk_registered[i]` +0x78, `itk_lock` +0x64(0x1594cd xchg); `_task_info` `user_stop_count` +0x44(0x166766), 시간 +0x54/58/5c/60(0x16676b–0x16677d) | 해당 주소 디스어셈블 열람(모두 확인) | ✅ |
| `proc` 는 빠진 게 아니라 `_utask_zero` 가 +0x3c 를 0 으로(0x106dfd); `_utask_zero` 는 +0x38(`u_address`)을 `bzero(…, 0x298)` | 0x106de8–0x106e0b 열람 | ✅ 50 절 5 번 정정 |
| `pcb_common` +0x40·`user_stop_count` +0x44 식별은 다른 소비처(`_pcb_common_init` 0x18d603, `_task_suspend`/`_task_resume`)로 확정 | `_task_info` 의 +0x44 읽기 확인(나머지는 주소만 받음) | ⚖️ |
| 두 수정이 최소 설명(다른 위치 필드로는 +0x38 할당/해제·+0x3c·색인 접근을 함께 설명 못 함) | 50 절 예측과 원본 접근 일치 | ✅ |
| 상수 사용처: Darwin `mach/mach_param.h`·`kern/task.h`·`kern/ipc_tt.c`, 07_kernel 은 정의와 task.h 뿐; 확정 40 객체 소스는 직접 안 씀 | 50 절 grep 결과와 같음 | ✅ 회귀는 수행 |
| NeXTMach 의 4 는 NeXT 조건부 커널 헤더 값 — 공개 SDK 정의의 증명은 아님 | — | ✅ 기록(근거는 원본 바이트) |
| 탐침은 원본 설정(잠금 저장소 있음, `NORMA_TASK`=0)으로 | 생성 헤더 `norma_task.h` = 0, DRIVERKIT=1 | ✅ |

### 50.2 결과 (2026-10-01) — `struct task` 복원, `ipc_host.c` 확정(A)

- 탐침 `s4b-task-1`: 가설판의 원본 근거 있는 27 필드와 sizeof 0x8c 모두 일치(불일치 0, `pset_tasks` 미확인) → 배치 표 `06_reconstruction/struct_layouts/task.tsv`.
- 07_kernel 복원 수정: `kern/task.h`(`u_address`, NeXTMach 이름), `mach/mach_param.h`(`TASK_PORT_REGISTER_MAX` 4). 회귀 42 객체 동일.
- 설계 4 의 재진단: `ipc_host.c` 가 Darwin 그대로 OBJECT_MATCH(19 함수, `-O2`=`-O3`) → 채택(새 2 파일)·07_kernel 빌드 동일 → **A**. `syscall_subr.c` 는 `map_fd` 문제로 따로 계획.
- 증거 `06_reconstruction/evidence/x86-task_layout_ipc_host.md`.

## 51. S5-P25 세부 계획 — `kernserv/kern_notify.c` 를 P 로 (코딩 전, 2026-10-01)

- `kern/syscall_subr.c` 보류: 원본 구간 끝의 `_map_fd`(453 B) 는 NeXTMach `kern/syscall_subr.c:637` 에 있고, 그 코드는 `sys/file.h`·`sys/vnode.h`·u-area 등 BSD 헤더가 필요 → S4-C(BSD 헤더 판) 결정 뒤.
- 재진단 `s5p25-pre-1`(복원 task.h, Darwin 그대로): `kern_notify.c` 의 `_notify_server_loop` 차이는 모두 `struct task` 오프셋(`kernel_privilege` +0x50, `itk_space` +0x88)이었고 이제 7 함수 바이트·참조 차이 0. 나머지(`ipc_marequest`·`ipc_notify`·`ipc_entry`·`ipc_object`·`power`)는 여전히 다름 — 다음 조사.

`kern_notify.c` 사실(seq 200): `__text` [0x16d20c, 0x16d64d) 1089 B(`-O3`; `-O2` 는 `_port_request_notification` 다름), 7 함수(정적 `pn_panic`·`pn_register`·`pn_notify` 와 외부 `get_kern_port` 포함 — 처음에 `get_kern_port` 를 정적으로 잘못 적음, 51.1), 앞 `00 00`(`_kern_serv_kernel_task_port` 끝 0x16d20a), 뒤 `00`×3(다음 `_kern_serv_handler` 0x16d650). `__data` 485 B(0x1dff0c, `_pn_register_port` 심볼로 배치), `__common` 4 B(`_pn_register_port_k` 0x1f6e30, 심볼). **`__bss` 20 B**(정적 `pn_notify_port`·`pn_notify_port_k`·`pnotify_port_set`·`pn_reg_q`, 원본 심볼표에 없음): `zerofill_check.py` → reference-inferred, 참조 27, Δ 하나, 후보 [0x1e726c, 0x1e7280), 정렬·원본 `__bss` 안·이름 심볼 없음·기존 배치(확정 zero-fill + intr `__bss`)와 겹침 없음, 음성 검사 감지. 함수 판정: MATCH 4, MATCH_UNVERIFIED 3(의존은 `__bss` 뿐 — 확인 예정).

설계: Darwin 그대로 채택, 07_kernel 빌드 동일 확인, 등급 **P**(`objects_partial.tsv`, `__bss` 20 B reference-inferred), 함수 high 4·medium 3(README 규칙), 증거 문서.

### 51.1 codex 교차검토(QP26) 판정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| 7 함수 바이트·참조 91 일치, MATCH_UNVERIFIED 3 의 미검증 의존은 `__bss` 뿐 | L1 JSON 집계(내 계산과 같음) | ✅ |
| `__data` 485 B 차이 0, `__common` `_pn_register_port_k` 4 B 심볼 배치 | L1 JSON 섹션 값 | ✅ |
| zero-fill: 참조 27 모두 VANILLA 4 B, Δ 0x1e6c3c, 대상 오프셋 0–16 이 네 정적 변수 전부를 덮음, intr 추정 블록과 920 B 떨어짐 | zerofill_check 출력(참조 27, Δ 하나, 후보·음성 검사) | ✅ |
| **`get_kern_port` 는 외부 심볼**(계획의 "정적" 은 틀림) | 원본 심볼표에 `_get_kern_port` 있음 | ✅ 51 절 정정 |
| 경계 앞 `00 00`·뒤 `00`×3, README P 조건 정확히 적용 | 51 절 Python 출력 | ✅ |

### 51.2 결과 (2026-10-01) — `kern_notify.c` 를 P 로

- Darwin 그대로 채택(새 5 파일), 07_kernel 빌드 동일. 최종 목적 파일로 zero-fill 검사 다시 실행: reference-inferred. `objects_partial.tsv` 에 P, 함수 high 4·medium 3. 증거 `06_reconstruction/evidence/x86-kern_notify.md`.
- 기록 도구 한계: `srcdefs.find` 가 한 줄 `static void f(...)` 정의를 놓쳐(`pn_panic`) 기록 스크립트에 보조 규칙(0 열 시작, `;` 로 끝나지 않는 `name(` 줄, 후보 1 개만 허용)을 썼다.

## 52. S5-P26 세부 계획 — `ipc/ipc_marequest.c` (코딩 전, 2026-10-01)

사실(재진단 `s5p25-pre-1`, Darwin 그대로; L1 `-O3c`): 원본 [0x14a0d8, 0x14a631) 1369 B, 6 함수. 빌드 1369 B, 3 함수 MATCH, `_ipc_marequest_destroy` 만 바이트 1·참조 2 차이(나머지 두 DIFF 는 `__data` 실패 의존뿐). 원본 0x14a5a8–0x14a5ad: `push esi; mov ecx,[ebp-4]; push ecx; call _ipc_notify_msg_accepted`(0x14b464; 처음 `push [ebp-4]` 로 잘못 적음, 52.1), 빌드: `push "ipc_marequest_destroy"; call panic`. `__data`: 빌드 52 B = 원본 30 B(`ipc_marequest_max` 0x400 + `"ipc msg-accepted requests"`) + panic 문자열 22 B(Python); 원본은 30 B 뒤에 다른 객체의 문자열(`"ipc_mqueue_receive: …"`)이 바로 이어짐.
- Darwin ipc_marequest.c:459 `panic("ipc_marequest_destroy");` 자리에 Mach4 ipc_marequest.c:437 은 `ipc_notify_msg_accepted(soright, name);`.

설계: 복원 수정(D014) — Darwin :459 를 Mach4 :437 의 줄로 교체(출처 https://github.com/openmach/mach4.git 69fa77870f20d854c875135e116ebc80b118e7ff `kernel/ipc/ipc_marequest.c:437`, CMU 고지는 파일에 있음) + 머리말 뒤 수정 주석. 예측: `__text` 1369 B, `__data` 30 B, 6 함수 MATCH. `__common`(`ipc_marequest_table` 등)이 있으면 36.1 방식. 경계 증명서.

### 52.1 codex 교차검토(QP27) 판정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| 한 줄 교체로 모든 차이 설명(필드 밖 차이 1 바이트 `68→56`, panic 재배치, 문자열 22 B); 원본 명령은 `mov ecx,[ebp-4]; push ecx` | 52 절 원본 디스어셈블 출력(`push esi; mov ecx,[ebp-4]; push ecx; call 0x14b464`) | ✅ 문구 정정 |
| Darwin 의 `zinit(…, FALSE, …)` + `zchange` 는 유지(원본 0x14a1a0 `_zchange` 호출) — Mach4 의 `IPC_ZONE_TYPE` 판을 가져오면 안 됨 | 진단 L1 에서 `_ipc_marequest_init` 바이트 차이 0(데이터 의존만 실패) | ✅ |
| 원본 `__data` [0x1de710, 0x1de72e) 30 B, 그 뒤 `"ipc_mqueue_receive: strange ith_state"` 는 `_ipc_mqueue_receive` 0x14aea4 가 참조 | 52 절 데이터 덤프 | ✅ |
| 36.1 필수 — 공통 기호 mask/size/table/zone 각 4 B ≤ 간격 4/4/4/8 | — | ✅ 재빌드 뒤 확인 |
| 경계: 앞 `00 00`(0x14a0d6), 뒤 `00`×3, 다음 `_ipc_mqueue_init` 0x14a634 | — | ✅ 재빌드 뒤 확인 |

### 52.2 결과 (2026-10-01) — `ipc_marequest.c` 확정(A, 복원 수정) · `power.c` 보류 사유

- 한 줄 교체 후 `__data` 30 B, 변형 OBJECT_MATCH(6 함수), 36.1 대응 조건 충족, 경계 최소 채움 → **A**. 증거 `06_reconstruction/evidence/x86-ipc_marequest.md`.
- `kern/power.c` 보류: 원본 `_power_callout`·`_power_init` 은 `_calloutEntryAllocate`/`_calloutDeadlineFromInterval`/`_calloutEntryDispatchDelayed` 를 부르는데 Darwin 판은 `thread_call_allocate`/`deadline_from_interval`/`thread_call_enter_delayed`(함수마다 8 B 차이). `callout*` API 는 어떤 참조 트리에도 없고 원본에는 0x169124 부터 `callout` 모듈(`_calloutInitialize` …)이 있다 → `callout` 모듈(Darwin `thread_call.c` 의 이전 판으로 보임)과 함께 계획.

## 53. S5-P27 세부 계획 — `ipc/ipc_object.c` + `ipc_entry.h`·`ipc_port.h` 원형 (코딩 전, 2026-10-01)

사실(재진단 `s5p25-pre-1` Darwin 그대로 3098 B 대 원본 [0x14b844, 0x14c454) 3088 B; 탐침은 스테이징 사본만, 계산 Python):
- **원본의 `_ipc_entry_grow_table`·`_ipc_port_dngrow` 호출은 모두 인자 1 개**(Ghidra 함수 단위 전수 스캔 9 곳: `_ipc_entry_alloc` 0x145fd1, `_ipc_entry_alloc_name` 0x146144, `_ipc_kmsg_copyout_header` 0x14894e/0x148a05, `_ipc_object_copyout` 0x14be30, `_ipc_object_copyout_compat` 0x14c210/0x14c299, `_ipc_object_copyout_name_compat` 0x14c438, `_ipc_right_dnrequest` 0x14dcea — 모두 `push` 1 개 뒤 `add esp,4` 또는 곧바로 결과 사용). Darwin 은 `(space, ITS_SIZE_NONE)`·`(port, ITS_SIZE_NONE)` 두 인자(ipc_object.c:657, 1077, 1101, 1206; 원형 ipc_entry.h:206–208, ipc_port.h:279–281), Mach4 는 한 인자(mach4 ipc_entry.h:156, ipc_port.h:258).
- `_ipc_object_destroy`(0x14bd68): `default` 에서 아무 호출 없이 반환 — Darwin(:601)·Mach4 모두 `panic` 이 있음.
- `_ipc_object_copyin_type`: `panic` 뒤 `xor eax,eax` — Mach4 :384 `return 0; /* in case assert/panic returns */`.
- `_ipc_object_copyout_dest`: `mscount` 초기화(`mov [ebp-4],0`, Mach4 :854 `= 0`)와 함수 시작의 `xor esi,esi`(`name` = 0), send-once 이상 분기에서 다시 0 을 넣지 않음.
- 탐침: `s5p27-probe-1`(원형·호출 4 곳·mscount·destroy) 3088 B, 18 MATCH; `s5p27-probe-2` 변형 A(+`return 0`) 19 MATCH, 변형 B(mscount 초기화 없음) 배치 실패; `s5p27-probe-3` 변형 C(`mach_port_t name = MACH_PORT_NULL;`) **OBJECT_MATCH 20/20**, 변형 D(C + 분기 대입 삭제)도 OBJECT_MATCH → 더 작은 C 를 택함. copyout_dest 변형 3 회(R4 한도).

설계(복원 수정, D014):
1. `ipc/ipc_entry.h`·`ipc/ipc_port.h`: `ipc_entry_grow_table(ipc_space_t space)`·`ipc_port_dngrow(ipc_port_t port)` 한 인자 원형(Darwin 문체, Mach4 의 인자 수).
2. `ipc/ipc_object.c`: (a) 호출 4 곳에서 `, ITS_SIZE_NONE` 삭제(Mach4 형태), (b) `ipc_object_destroy` 의 `default:` 를 `break;` 로(panic 삭제), (c) `ipc_object_copyin_type` 의 panic 뒤에 Mach4 :384 줄, (d) `copyout_dest` 의 `mscount` 에 Mach4 :854 초기화, (e) `copyout_dest` 의 `name` 선언에 `= MACH_PORT_NULL`(참조 소스에 없는 최소 수정 — 근거 0x14bfb3 `xor esi,esi`; 처음 0x14bfb2 로 잘못 적음, 53.1).
3. 원형 변경은 헤더 → 회귀(확정 42 + 부분 3). 아직 채택하지 않은 Darwin `ipc_entry.c`·`ipc_port.c`·`ipc_kmsg.c`·`ipc_right.c` 는 이 원형과 맞지 않게 되므로 그 파일을 다룰 때 함께 고친다(원본과 같은 방향).
4. `__common`(`ipc_object_zones`) 은 36.1 방식, 경계 증명서. 예측: 3088 B, 20 함수 MATCH, `__data` 172 B(0x1de8ae).

### 53.1 codex 교차검토(QP28) 판정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| 한 인자 호출 9 곳 정확, 두 피호출 함수 본체가 `[ebp+0xc]` 를 읽지 않음 | 내 Ghidra 함수 단위 스캔(호출 9 곳), 두 본체 `[ebp+0xc]` 0 건 | ✅ |
| 변형 C 의 차이는 설계 2(a–e) 뿐; Mach4 인용 줄 맞음(Mach4 헤더의 인자는 주석 안 — 인자 수의 근거일 뿐 강제 원형 아님) | 53 절 근거 줄 열람 | ✅ |
| **`xor esi,esi` 는 0x14bfb3**(내 0x14bfb2 는 틀림); C 는 시험한 것 중 가장 작은 일치 수정, 원문 철자의 증명은 아님 | 0x14bfa4 디스어셈블(0x14bfb3) | ✅ 53 절 정정 |
| 42+3 확정·부분 객체는 두 함수를 쓰지 않음 | — | ✅ 회귀는 수행 |
| **36.1 미완**: C 는 `-fno-common` 으로만 빌드됨 → 최종 소스로 변형(`-fno-common` 없음) 빌드·대응 검사 필요; `_ipc_object_zones` 8 B = 간격 8 | s5p27-probe3.cmd 두 명령 모두 `-fno-common` 확인 | ✅ 최종 빌드에 포함 |
| 경계: 앞 `00 00`, 뒤 0(`_ipc_port_timestamp` 0x14c454) | 내 Python 확인과 같음 | ✅ |

### 53.2 결과 (2026-10-01) — `ipc_object.c` 확정(A) · 헤더 원형 두 개

- 07_kernel 수정: `ipc/ipc_entry.h`, `ipc/ipc_port.h`(한 인자 원형), `ipc/ipc_object.c`(설계 2 의 a–e). 07_kernel 빌드의 `-O3` 목적 파일이 탐침 C 와 같은 SHA.
- `-O3`·`-O2`·변형 모두 OBJECT_MATCH(20 함수), 36.1 대응 조건 충족, 경계 앞 `00 00`·뒤 0 → **A**. 회귀 45/45 동일(`09_validation/reconstruction/s5p27-regress-20261001.json`).
- 실수 기록: 회귀 참조 목록 저장 줄에서 `open(…, 'w')` 를 빠뜨려 그 JSON 만 쓰이지 않음(명령 파일·회귀 실행은 정상) — 다시 만들어 비교.
- 증거 `06_reconstruction/evidence/x86-ipc_object.md`.

## 54. S5-P28 세부 계획 — `ipc/ipc_entry.c` (코딩 전, 2026-10-01)

사실: 원본 [0x145e44, 0x146906) 2754 B, 7 함수. 재진단(`s5p25-pre-1`) 2826 B — `ipc_entry_alloc`·`alloc_name` 은 `ipc_entry_grow_table(space, ITS_SIZE_NONE)` 의 둘째 인자만큼 4 B 씩 길고, `grow_table` 은 Darwin 이 더한 `target_size` 처리(:636–653 블록, :704–705 assert 조건, `psize` 변수)가 있음. 원본 `_ipc_entry_grow_table` 1114 B 의 호출은 Darwin 식(`thread_block_with_continuation`, `bcopy`, `bzero` — Mach4 의 `thread_block`/`memcpy`/`memset` 아님), 두 번째 인자를 읽지 않음(53.1).
- 탐침 `s5p28-probe-1`(스테이징 사본만; 07_kernel 의 한 인자 원형 사용): 호출 2 곳 `, ITS_SIZE_NONE` 삭제, 정의를 `ipc_entry_grow_table(ipc_space_t space)` 로, `psize` 선언·`target_size` 블록(주석 포함) 삭제, assert 를 `assert(space->is_table_next == its);` 로 → `-O3`·변형 **OBJECT_MATCH 7/7, 2754 B**; `-O2` 다름.

설계(복원 수정, D014): 위 탐침 수정을 07_kernel `ipc/ipc_entry.c` 에 그대로 적용(+ 머리말 뒤 수정 주석); 07_kernel 빌드가 탐침과 같은 SHA 인지, 36.1(공통 기호 있으면), 경계 증명서. 헤더 변화 없음 → 회귀 불필요(이 파일은 다른 확정 객체가 쓰지 않음).

### 54.1 codex 교차검토(QP29) 판정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| 스테이징 diff 는 54 절 수정뿐; 원본 호출 0x145fd1·0x146144 한 인자, grow_table 은 `[ebp+8]` 만 | 53.1 의 스캔, 54 절 탐침 수정 목록 | ✅ |
| 주석·안 쓰는 선언·꺼진 assert 는 바이트로 증명 불가(MACH_ASSERT=0) — Mach4 와 일치하는 재구성 선택 | — | ✅ 증거에 명시 |
| L1 재현: O3·O3c OBJECT_MATCH 2754 B, O2 2554 B NOT_MATCH; 36.1 통과 — `_ipc_tree_entry_zone` 4 B = 간격 4, 재배치 56 대응, 필드 밖 차이 0 | 내 36.1 계산(재배치 56, 필드 밖 같음, 4/4) | ✅ |
| 경계: `_ufs_nlinks`(UFS) 끝 0x145e44 틈 0, 뒤 `00 00` 은 확정 ipc_hash 앞 틈과 같음 | 54 절 Python 출력 | ✅ |

### 54.2 결과 (2026-10-01) — `ipc_entry.c` 확정(A)

- 탐침 본문을 07_kernel 에 적용(+수정 주석), 07_kernel 빌드가 탐침과 같은 SHA(O3·O3c·O2). OBJECT_MATCH 7/7, 36.1 충족, 경계 앞 0·뒤 `00 00` → **A**. 증거 `06_reconstruction/evidence/x86-ipc_entry.md`.
- 실수 기록: 첫 기록 스크립트가 따옴표 문법 오류로 실행되지 않음(표 변경 없음) → 다시 실행.

## 55. S5-P29 세부 계획 — `ipc/ipc_port.c` + `ipc_port.h`·`ipc_kmsg.h` (코딩 전, 2026-10-01)

사실(원본 [0x14c454, 0x14d61a) 4550 B, 29 함수; 탐침은 스테이징 사본만; 계산 Python):
- `s5p29-probe-1`(한 인자 `ipc_port_dngrow`, Darwin :185 매개변수·:198–211 `target_size` 블록 삭제): 4366 B — 원본에 있는 `_ipc_port_lock_mqueue`(0x14c748, 164 B)가 Darwin 에 없고, `dngrow` 가 20 B 짧음(원본 `mov [ebp-0x10],0`).
- Mach4 `ipc_port.c:372–423` 에 `ipc_port_lock_mqueue`(주석 포함)와 이를 쓰는 `ipc_port_set_seqno` 가 있음(Darwin 은 `set_seqno` 안에 펼친 판). Mach4 `dngrow` 의 `oits = 0` 초기화.
- `s5p29-probe-2`(+ Mach4 블록으로 Darwin `set_seqno` 교체, + `oits = 0`, + `ipc_port.h` 에 `ipc_port_lock_mqueue` 원형): 4550 B, 26 MATCH; 남은 차이 — `release_send`(원본 시작의 `xor ebx,ebx` = `mscount` 0; Darwin·Mach4 모두 초기화 없음), `copyout_send_compat`(같은 함수 인라인), `destroy`(`kmsg->ikm_header.msgh_remote_port` 를 원본 +0x1c, 빌드 +0x24).
- `struct ipc_kmsg`: Darwin 에 `security_id_t ikm_sender`(8 B, mach/message.h:384)와 `integer_t ikm_delta` 가 있음. 원본 `_ipc_kmsg_get`(0x1475f0/0x147623 `lea [..+0x14]` = `ikm_header` +0x14; 0x147616/0x14766f `[ebx+0x10]` 에 0 다음 세 번째 인자 저장 = `ikm_delta`).
- `s5p29-probe-3`(+ `mscount = 0`, 두 필드 모두 삭제): `destroy` 가 +0x18 로 지나침. `s5p29-probe-4`(+ `mscount = 0`, **`ikm_sender` 만 삭제**): 변형 **OBJECT_MATCH 29/29**, `-fno-common` 판 바이트·참조 차이 0(`__common` 순서만 미검증).

설계(복원 수정, D014):
1. `ipc/ipc_kmsg.h`: `security_id_t ikm_sender;` 삭제(원본 배치; `ikm_delta` 유지). Darwin `ipc_notify.c` 등의 `ikm_sender` 사용은 그 파일을 다룰 때 처리.
2. `ipc/ipc_port.h`: `ipc_port_lock_mqueue(ipc_port_t)` 원형 추가(Mach4 ipc_port.h:303–304 에 있음; Darwin 문체).
3. `ipc/ipc_port.c`: (a) `dngrow` 한 인자·`target_size` 블록 삭제, (b) `oits = 0`(Mach4 줄), (c) Darwin `set_seqno` 주석+본문을 Mach4 :372–423 블록으로 교체, (d) `release_send` 의 `mscount = 0`(참조 없는 최소 수정, 근거 원본 함수 시작 `xor ebx,ebx`).
4. 헤더 변경 → 회귀(확정 44 + 부분 3). 36.1 대응 조건, 경계 증명서(앞 0: ipc_object 끝 0x14c454, 뒤 `00 00`: ipc_pset 앞 틈).

### 55.0 설계 보강(codex 회신 전, 내 발견) — `ipc_kmsg.h` 매크로

- `ikm_sender` 필드를 지우면 Darwin `ipc_kmsg.h` 의 `ikm_init_special`(:174)·`ikm_check_initialized`(:182)에 있는 `(kmsg)->ikm_sender = ANONYMOUS_SECURITY_ID_VALUE;` 두 줄이 컴파일되지 않는다(4 회차 탐침 `s5p30-probe-2` 에서 확인; 탐침 4 의 `ipc_port.c` 는 이 매크로를 쓰지 않아 드러나지 않음). 원본 `_ipc_kmsg_get` 0x14760f/0x147616 은 `ikm_marequest`(+0xc)·`ikm_delta`(+0x10)에만 0 을 쓰고 sender 저장이 없다 → **설계 1 에 두 줄 삭제를 추가**.

### 55.1 codex 교차검토(QP30) 판정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| stage-4 의 수정은 설계 1–3 그대로, Mach4 인용(:179, :372–423, ipc_port.h:303–304) 맞음 | 55 절 근거 줄 열람(grep 출력) | ✅ |
| `ikm_delta` 유지·`ikm_sender` 삭제 강하게 지지(`_ipc_kmsg_get` +0x10 지우고 셋째 인자 저장, `_ipc_kmsg_put` 0x1476fa 가 +0x10 지움, mach_msg 경로가 `msgh_size + delta` 사용); `security_id_t` 8 B(message.h:381) | 0x1476fa `mov [ebx+0x10],0` 확인, 탐침 3·4 결과 | ✅ |
| **헤더 결함: `ikm_init_special`·`ikm_check_initialized` 의 `ikm_sender` 대입 2 줄** | 내가 55.0 에서 먼저 발견(4 회차 탐침 컴파일 오류) | ✅ 55.0 보강 유지 |
| `mscount = 0` 의 근거 `xor ebx,ebx` 는 **0x14d05a**(함수 시작 0x14d050 이 아님); 재구성일 뿐 원문 철자 증명 아님 | 0x14d050 디스어셈블(0x14d05a `xor ebx,ebx`) | ✅ 주소 명시 |
| 36.1: O3c OBJECT_MATCH 29/29, 재배치 101 대응, 공통 3 개 4 B = 간격; O3 의 14 참조는 미검증(차이 0 ≠ 검증) | 내 36.1 계산과 같음 | ✅ |
| `-fno-common` 유무로 전처리는 같다는 쌍 기록이 없음 | `-fno-common` 은 전처리 옵션이 아님(같은 명령·입력) — 최종 빌드에서 O3c 용 `-E` 도 받아 비교 | ⚖️ 최종 빌드에 추가 |
| 확정 44 + 부분 3 객체는 kmsg 멤버·크기를 쓰지 않음 | — | ✅ 회귀는 수행 |

### 55.2 결과 (2026-10-01) — `ipc_port.c` 확정(A) · `ipc_kmsg.h`·`ipc_port.h` 복원

- 07_kernel: `ipc_kmsg.h`(필드 + 매크로 2 줄), `ipc_port.h`(원형), `ipc_port.c`(stage-4 본문 + 수정 주석). 07_kernel 빌드가 탐침 4 와 같은 SHA, `.i` 두 판 동일. 변형 OBJECT_MATCH 29/29, 36.1 충족, 경계 앞 0·뒤 `00 00` → **A**. 회귀 47/47 동일. 증거 `06_reconstruction/evidence/x86-ipc_port.md`.

## 56. S5-P30 세부 계획 — `ipc/ipc_notify.c`·`mach/notify.h` 를 Mach4 판으로 (코딩 전, 2026-10-01)

사실(원본 [0x14af44, 0x14b842) 2302 B, 16 함수; 탐침은 스테이징 사본만):
- Darwin 판(재진단 `s5p25-pre-1`) 2680 B: 함수 구성이 다름 — 원본의 `ipc_notify_init_msg_accepted`·`ipc_notify_msg_accepted` 가 없고 원본에 없는 `*_compat` 초기화 3 개가 있음. **Mach4 `kernel/ipc/ipc_notify.c` 의 16 함수가 이름·순서까지 원본과 같다**(srcdefs 목록).
- 원본 `_ipc_notify_init_port_deleted`(0x14af44): `msgh_size` 0x20, +0x18 의 `mach_msg_type_t` 비트필드(name 0x0f, size 0x20, number 1, inline …), +0x1c `not_port` = 0, `msgh_seqno` 자리(+0x10)에 1 = Mach4 의 `NOTIFY_MSGH_SEQNO`(`MACH_IPC_COMPAT` 일 때 `MSG_TYPE_EMERGENCY`) — **이전 메시지 형식**(타입 기술자). Darwin `mach/notify.h` 는 이후 형식(NDR·트레일러·디스크립터)이고 Mach4 `include/mach/notify.h` 는 이전 형식. Darwin `mach/message.h` 에도 `mach_msg_type_t`·`msgh_seqno` 는 있음.
- 탐침: `s5p30-probe-1`(Mach4 ipc_notify.c + Darwin notify.h) 컴파일 실패(`mach_msg_accepted_notification_t`·`not_type` 없음); `s5p30-probe-2`(+ Mach4 notify.h) 실패 — `ipc_kmsg.h` 매크로의 `ikm_sender`(→ 55.0 으로 해결, 지금 07_kernel 에 반영됨); `s5p30-probe-3`(+ 매크로 수정) **변형 OBJECT_MATCH 16/16**, `-fno-common` 판 미검증 80 참조(공통 템플릿 6 개).
- 공통 기호(변형): 템플릿 5 개 32 B·`send_once` 24 B = 원본 간격과 같음. `__data` 346 B.
- 영향: `mach/notify.h` 를 쓰는 확정 객체는 `kern_notify`(P) 뿐 — Mach4 notify.h 로 빌드해도 SHA 동일(`s5p30-probe-kn-1`). 아직 채택 안 한 사용처: Darwin `mach_port.c`, `ipc_kobject.c`, `server_loop.c`, `kern_server.c`, `ipc_xxx.c`, `bsd/dev/vol.c`(그 파일을 다룰 때 이 형식에 맞춘다).
- 경계: 앞 `00 00`(`_ipc_mqueue_receive` 끝 0x14af42), 뒤 `00 00`(확정 ipc_object 앞 틈과 같음).

설계:
1. `07_kernel/src/mach/notify.h` 를 Mach4 `include/mach/notify.h`(https://github.com/openmach/mach4.git 69fa77870f20d854c875135e116ebc80b118e7ff, CMU 고지) 로 교체 — 파일 출처가 mach4 로 바뀐다(PROVENANCE `source_id` mach4). 수정 없이 그대로.
2. `07_kernel/src/ipc/ipc_notify.c` = Mach4 `kernel/ipc/ipc_notify.c` 그대로(D013/AGENTS: Mach4 텍스트는 CMU 고지·출처 기록과 함께).
3. 07_kernel 빌드(`-E` 두 판, `-O3`/`-O2`/변형), 36.1, 경계 증명서. `mach/notify.h` 는 공개 헤더 → 회귀 48(확정 45 + 부분 3).

### 56.1 codex 교차검토(QP31) 판정 → 설계 변경(최소 수정)

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| 원본은 형식 있는 알림(템플릿 32 B×5, send-once 24 B), `__data` 346 B 는 문자열 9 개로 일치 | 탐침 3 L1(`__data` 일치), 56 절 디스어셈블 | ✅ |
| Mach4 헤더 통째 교체는 현재 설정에선 되지만 최소가 아님 — Darwin 헤더에서 구조체 정의만 바꾸고 `mach_msg_accepted_notification_t` 추가로 충분할 것(빌드로 확인 필요) | **탐침 4**: Darwin `notify.h` 106–143 행을 Mach4 62–94 행으로 바꾼 혼합판 → `ipc_notify` O3·O3c 가 탐침 3 과 같은 SHA, `kern_notify` 확정 SHA 그대로(`s5p30-probe-kn-2`) | ✅ **혼합판 채택** |
| L1·36.1 재현: O3c 16/16, 127 참조; O3/O3c 필드 밖 바이트 같음, 재배치 127 곳 대응(80 개 공통 참조 변환, scattered 포함) | 내 계산: 위치 127 같음, 형태 차이 65 개는 모두 `-fno-common` 판의 `__common` 대상 scattered VANILLA ↔ 변형의 외부 재배치(타입 같음) | ✅ 36.1 형태 조건에 이 예외 명시 |
| 공통 템플릿 시작 주소들과 간격 32/32/32/32/32/24 | 탐침 3 공통 기호 크기 = 간격 | ✅ |
| 경계 `00 00`/`00 00` | 56 절 Python 출력 | ✅ |
| 출처: 파일·함수 단위 기록, 헤더의 CMU 고지(1991,1990,1989,1988,1987)도 `CMU-MACH.txt` 에 | mach4 notify.h 머리말 확인, `CMU-MACH.txt` 는 ipc_hash.c 판(1991,1990,1989)만 | ✅ 추가 |

설계 변경: 56 절 설계 1 을 "Darwin `mach/notify.h` 의 구조체 정의 블록(:106–143)을 Mach4 `include/mach/notify.h:62–94` 로 교체(복원 수정)" 로 바꾼다. 설계 2(Mach4 `ipc_notify.c` 그대로)는 유지.

### 56.2 결과 (2026-10-01) — `ipc_notify.c` 확정(A, Mach4) · `mach/notify.h` 최소 복원

- 07_kernel: `mach/notify.h` 혼합판(+수정 주석), `ipc/ipc_notify.c` = Mach4 원문, `LICENSES/CMU-MACH.txt` 에 헤더 판 CMU 고지 추가. 07_kernel 빌드가 탐침 4 와 같은 SHA, `.i` 두 판 같음. 변형 OBJECT_MATCH 16/16, 36.1 충족(형태 예외: `__common` 대상 scattered↔외부), 경계 `00 00`/`00 00` → **A**. 회귀 48/48. 증거 `06_reconstruction/evidence/x86-ipc_notify.md`.

## 57. S5-P31 세부 계획 — `ipc/ipc_right.c` = Mach4 판 + Darwin 의 `ipc_hash_delete` (코딩 전, 2026-10-01)

사실(원본 [0x14db08, 0x1506af) 11175 B, 19 함수; 탐침은 스테이징 사본만):
- Darwin 판(dngrow 호출만 한 인자로 고친 탐침 1): 11147 B — `ipc_right_clean`·`destroy`·`dealloc`·`delta` 가 4–8 B 짧음. 차이는 Mach4 와의 차이와 같은 곳: 세 함수의 `mscount = 0` 초기화(Mach4 판에 있음), `delta` 의 범위 검사 두 곳의 위치(Darwin 은 포트 잠금 뒤로 옮김).
- **탐침 2(Mach4 `kernel/ipc/ipc_right.c` 그대로)**: 앞 17 함수 크기가 모두 원본과 같고 `ipc_right_copyin_compat` 만 12 B 짧음 — Darwin 판은 이 함수에 `ipc_hash_delete(space, (ipc_object_t) port, name, entry);`(4 줄, darwin ipc_right.c 해당 함수 :50–53)가 더 있고, 탐침 1(Darwin)의 이 함수는 원본과 같은 1176 B.
- **탐침 3(Mach4 판 + 그 4 줄을 Darwin 과 같은 자리에)**: `-O3`·변형 **OBJECT_MATCH 19/19**(`__common` 없음), `-O2` 다름. 이 함수 본문은 Darwin 판과 글자까지 같아짐.
- 경계: 앞 `00 00`(확정 ipc_pset 뒤 틈), 뒤 `00`(확정 ipc_space 앞 틈).

설계: `07_kernel/src/ipc/ipc_right.c` = Mach4 `kernel/ipc/ipc_right.c`(69fa778…) + Darwin `ipc_right_copyin_compat` 의 `ipc_hash_delete` 4 줄(복원 수정; MODIFICATIONS 에 Mach4 기준·Darwin 줄 출처, CMU·APSL 고지 — 파일 머리말은 Mach4(CMU)이고 추가 4 줄은 Darwin(APSL) 유래임을 기록). 07_kernel 빌드 동일 SHA 확인, 경계 증명서. 헤더 변경 없음 → 회귀 불필요.

### 57.1 codex 교차검토(QP32) 판정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| 스테이징 diff 는 삽입 1 곳(+4/−0), Darwin 해당 줄은 **2422–2425**, 위치 동일(`ipc_marequest_cancel` 뒤, `ie_object = IO_NULL` 앞) | Darwin ipc_right.c:2420–2426 열람, 탐침 3 함수 = Darwin 함수(diff 0) | ✅ 줄 번호 기록 |
| 탐침 3 O3·O3c OBJECT_MATCH 19/19, `__text` 11175 B·재배치 228·`__data` 312 B([0x1de95a, 0x1dea92)) 차이 0 | 탐침 3 L1 결과 | ✅ |
| Mach4 기준이 더 작다(+4/−0 대 Darwin 기준 8 의미 수정·10 블록) — Darwin 초기화 차이는 4 함수 5 곳(dealloc 두 곳) | — | ✅ 57 절 서술 보강 |
| **MODIFICATIONS 만으로 부족 — Darwin(APSL) 줄을 넣은 파일엔 APSL 고지(Exhibit A)를 파일에 둬야 함**(APSL 1.0 §2.1(c)), CMU 고지 유지, 혼합 출처 명시 | `LICENSES/APSL-1.0.txt` §2.1 확인 | ✅ 파일 머리에 Darwin APSL 머리말(:1–23) + 수정 주석 추가 |
| 경계 [0x14db08, 0x1506af), 앞 `00 00`·뒤 `00` | 57 절 Python 출력 | ✅ |

### 57.2 결과 (2026-10-01) — `ipc_right.c` 확정(A, Mach4 + Darwin 4 줄)

- 07_kernel `ipc/ipc_right.c` = Darwin APSL 머리말 + 수정 주석 + 탐침 3 본문. 07_kernel 빌드가 탐침 3 과 같은 SHA(O3·O3c·O2). OBJECT_MATCH 19/19, 경계 `00 00`/`00` → **A**. 헤더 변경 없음.
- 증거 `06_reconstruction/evidence/x86-ipc_right.md`.

## 58. S5-P32 세부 계획 — `ipc/mach_port.c` + `mach/port.h` + 옵션 `MACH_OLD_VM_COPY` (코딩 전, 2026-10-01)

사실(원본 [0x154b28, 0x156693) 7019 B, Ghidra 범위 40 개, `__data` 72 B; 탐침은 스테이징 사본만, `08_build/runs/tools/s5p33-probe-stage-N`):
- 탐침 1(Mach4 `kernel/ipc/mach_port.c` 그대로): 컴파일 실패 — `old_mach_port_status_t` 가 Darwin `mach/port.h` 에 없음.
- 탐침 2(Mach4 + Mach4 `include/mach/port.h:146–156` typedef): `mach_port_names` −12, `port_names` −128, `port_set_backlog` +4 B.
- 탐침 3(Darwin 판 + `MACH_OLD_VM_COPY 1`, 스테이징 generated 헤더): `port_names` 일치(436). 남은 차이 `mach_port_names` +16, `old_mach_port_get_receive_status` 없음, `mach_port_get_set_status` +24, `port_set_backlog` +4.
- 탐침 4(+ Darwin `mach_port.c:380`·`:386`·`:1151` 의 `vm_move` 크기 인자 `size_used` → `vm_size_used`): 정규화 diff 에서 원본은 `round_page` 결과(`esi`)를 넘김. `mach_port_names` 1208·`get_set_status` 716 일치.
- `port_set_backlog`: 두 판 소스 동일. 원본은 `lea eax,[edi-1]; cmp eax,0xf; jbe` (int 범위 검사 1–16 을 하나로 접음), 빌드는 `test/jle` + 부호 없는 `cmp 0x10; jbe` — Darwin `mach/port.h:229` `PORT_BACKLOG_MAX` = `MACH_PORT_QLIMIT_MAX` = `((mach_port_msgcount_t) 16)`(부호 없음). NeXTMach `sys/port.h:143`·Mach4 `include/mach/mach_param.h:49` 은 int `16`. 커널(드라이버 `/dev/` 제외)에서 `PORT_BACKLOG_MAX` 사용처는 `ipc/mach_port.c:1892` 하나(전수 grep).
- **탐침 5**(탐침 4 + Mach4 `mach_port.c:738–777`(`old_mach_port_get_receive_status` 주석·본문)을 Darwin `mach_port_set_qlimit` 주석 앞에 삽입 + port.h 에 Mach4 typedef(146–156)를 `MACH_PORT_QLIMIT_MAX` 뒤에, `PORT_BACKLOG_MAX` 를 `16`): `-O3`·O3c(같은 SHA, `__common` 없음) **OBJECT_MATCH 40/40**, `__text` 7019 B·재배치 164, `__data` 72 B 0x1deada(L1d) 차이 0. 미정의 심볼 `_vm_move`·`_vm_map_pageable`·`_ipc_soft_map`(=`MACH_OLD_VM_COPY` 분기; `#else` 는 `vm_map_wire`/`unwire`/`vm_map_copyin`) — L1 은 참조까지 같아야 MATCH.
- 경계: 앞 간격 0(`_msg_receive_continue` 끝 = 0x154b28, 4 정렬), 뒤 `00` 1 B(0x156694 `_ast_init`, 4 정렬) — 최소 채움.
- `MACH_OLD_VM_COPY` 사용처(Darwin 커널, `/dev/` 제외): `conf/MASTER`, `bsd/kern/init_main.c`, `ipc/mach_debug.c`, `ipc/mach_port.c`, `ipc/ipc_kmsg.c`, `ipc/ipc_init.c`, `kern/zalloc.c`. 이 중 확정(A/A*/P) 객체 없음.

설계:
1. `06_reconstruction/config_options.tsv` 에 `mach_old_vm_copy	MACH_OLD_VM_COPY	mach_old_vm_copy.h	1	confirmed` 행 추가(근거: MASTER:145 `<!newvm>`, RELEASE 에 newvm 없음, mach_port.c OBJECT_MATCH 의 `_vm_move`·`_vm_map_pageable`·`_ipc_soft_map` 참조). `gen_config_headers.py` 로 `generated/mach_old_vm_copy.h`·`meta_features.h` 생성(`--check` 통과 확인). 손으로 쓰지 않는다.
2. `07_kernel/src/ipc/mach_port.c` = Darwin 판 + 복원 수정 (a) `vm_move` 크기 3 곳 `vm_size_used`, (b) Mach4 `old_mach_port_get_receive_status`(CMU) 삽입. 파일 머리 수정 주석, MODIFICATIONS·PROVENANCE 행.
3. `07_kernel/src/mach/port.h` = Darwin 판 + Mach4 typedef + `PORT_BACKLOG_MAX 16`(근거 NeXTMach·Mach4). 수정 주석, MODIFICATIONS·PROVENANCE 행.
4. 회귀: port.h·meta_features.h 가 바뀌므로 확정 47 + 부분 3 객체를 직전 회귀(s5p30-regress-1 이후 확정분 포함)와 같은 명령으로 다시 빌드하여 **출력 SHA 가 직전과 모두 같아야** 한다. 하나라도 다르면 중단하고 원인 조사.
5. 07_kernel 빌드(O3·O3c·O2) — 탐침 5 와 같은 SHA, L1 OBJECT_MATCH, 경계 증명서 → 등급 A. 기록: objects_confirmed, functions.tsv 40 행(high), 증거 md·diff, 58.2 결과.

### 58.1 codex 교차검토(QP33) 판정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| 탐침 5 diff 는 Darwin :380·:386·:1151 교체 + Mach4 :738–777 삽입뿐, port.h 는 typedef(Mach4 :146–156) + `PORT_BACKLOG_MAX 16` 뿐 | `diff` 출력: `380c380`·`386c386`·`836a837,876`·`1151c1191`, 변경 46 줄(=3×2+40); port.h diff `181a182,192`·`229c240` | ✅ |
| 탐침 5 O3·O3c OBJECT_MATCH 40/40, 7019 B·재배치 164·`__data` 72 B 0x1deada | l1batch 출력(58 절) | ✅ |
| `PORT_BACKLOG_MAX` 실행 사용처는 Darwin `ipc/mach_port.c:1892` 하나(:1866 은 주석), 07 에는 정의(port.h:229)만; Darwin·07 `mach_param.h` 에 정의 없음, Mach4 `mach_param.h:46–51` 의 `MACH_IPC_COMPAT` 블록 16 은 일치 | grep(07_kernel/src·darwin, `/dev/` 제외) 출력; Mach4 mach_param.h 40–60 열람 | ✅ |
| typedef 중복 정의 없음 | `old_mach_port_status` grep: darwin·07 0 건 | ✅ |
| `vm_move` 4 번째 인자는 바이트 수이고 함수가 스스로 `round_page` — 올린 크기를 넘겨도 범위 동일 | `vm/vm_map.c:2933–2956` 열람(`src_size = round_page(src_addr + num_bytes) - src_start`), 0 이면 둘 다 0 | ✅ (동작 동일, 증거는 바이트 일치) |
| **삽입 함수의 출처 고지가 "CMU" 만으로는 부족 — Mach4 `mach_port.c` 머리말은 CMU + University of Utah/CSL(1993,1994) 공동 고지**, Darwin 판 머리말·`LICENSES/CMU-MACH.txt` 에는 Utah 없음 | Mach4 `mach_port.c:1–28` 열람(:4–5 Utah/CSL), Darwin :1–75 Copyright 줄에 Utah 없음, `grep Utah 07_kernel/LICENSES/*` 0 건 | ✅ 설계 2 수정: Mach4 고지 :1–28 을 파일 머리(Darwin 고지 뒤)에 그대로 두고 적용 범위를 주석으로 밝힘, `LICENSES/CMU-UTAH-MACH4.txt` 추가. port.h typedef 의 Mach4 `port.h` 고지는 CMU 만(:3) — 기존 CMU-MACH.txt 로 충분 |
| 회귀 기준에 ipc_notify·ipc_right 가 없음(s5p30 회귀 마지막이 ipc_port) | s5p30-regress-1 `-o` 마지막 3 개 `ipc_object`·`ipc_entry`·`ipc_port` | ✅ 기준은 s5p30-build-1(ipc_notify)·s5p32-build-1(ipc_right) 출력 SHA |
| 확정 객체 불변이 미채택 파일(ipc_kmsg·ipc_init·zalloc 등)의 새 분기를 검증하지는 않음 | 사용처 목록(58 절) | ✅ 기록(그 파일들은 각 차례에서 검증) |
| port.h 포함 객체 28 확정 + 3 부분 | — | ⏭️ 전 객체 회귀를 하므로 수를 쓰지 않음 |
| **O2 기준 없음** — 탐침 5 는 O3·O3c 만 | `s5p33-probe5.cmd` RUN 3 줄(O3·O3c·.i), EXPECT 에 O2 없음 | ✅ 설계 5 수정: O3·O3c 는 탐침 5 와 같은 SHA, O2 는 기록만 |
| 절 표기 S5-P32 와 실행 ID s5p33 불일치 | 이전 관례: 57 절 S5-P31 의 빌드 `s5p32-build-1` 머리 `# S5-P31 …`, 탐침 `s5p32-probe-*` 머리 `# S5-P32 PROBE` — 실행 ID 와 절 번호는 원래 1:1 이 아님 | ⚖️ 절 번호 유지, 58 절 실행 ID 가 `s5p33-*` 임을 명기 |
| config 행에 evidence 열도 넣을 것 | `config_options.tsv:1` 머리 6 열 | ✅ (원래 의도; 근거 문구를 evidence 열에) |

설계 수정 요약: (2') `mach_port.c` 머리 = Darwin APSL·CMU 고지 + 수정 주석 + Mach4 고지(:1–28, "old_mach_port_get_receive_status 에 적용") ; `07_kernel/LICENSES/CMU-UTAH-MACH4.txt` 신설. (5') O3·O3c SHA = 탐침 5, O2 는 기록. 고지·주석 줄 추가로 줄 번호가 바뀌므로 `__LINE__` 영향 여부는 SHA 동일로 확인한다. 58 절의 실행 ID 는 `s5p33-*`.

### 58.2 결과 (2026-10-01) — `mach_port.c` 확정(A) · `mach/port.h` 복원 · `MACH_OLD_VM_COPY` confirmed

- `config_options.tsv` 에 `mach_old_vm_copy` 행(confirmed) 추가(18→19 행), `gen_config_headers.py` 로 `mach_old_vm_copy.h`·`meta_features.h` 생성, `--check` 통과.
- 07_kernel `ipc/mach_port.c`(신규) = Darwin + (a) `vm_size_used` 3 곳 + (b) Mach4 함수, 머리에 수정 주석과 Mach4 고지(:1–28); `mach/port.h` = typedef + `PORT_BACKLOG_MAX 16` + 수정 주석; `LICENSES/CMU-UTAH-MACH4.txt` 신설.
- 빌드 `s5p33-build-1`: O3 = O3c = 탐침 5 SHA(`5e1ff613…`), O2 다름(6059 B, 기록만). L1 OBJECT_MATCH 40/40, 경계 앞 0 B(`ret` 0x154b27)·뒤 `00` 1 B → **A**.
- 회귀 `s5p33-regress-1`: 50/50 SHA 동일.
- 기록: objects_confirmed 49 행(A 47, A* 1 + 머리), functions.tsv 323 함수(+40, high), PROVENANCE port.h 행 갱신·mach_port.c·mach_old_vm_copy.h 추가, **이전 누락이던 `generated/mach_xp.h` 행도 추가**(209→212), MODIFICATIONS 2 행, 증거 `x86-mach_port.md`·`.diff`·`x86-port_h.diff`.

## 59. S5-P33 세부 계획 — `ipc/mach_debug.c` = Darwin 판 + 크기 변수 0 초기화 4 곳(작성, D016) (코딩 전, 2026-10-01)

사실(원본 [0x151cbc, 0x1525a7) 2283 B, Ghidra 범위 6 개, 객체 소유 데이터 섹션 없음(외부 `_page_mask`·`_ipc_kernel_map`·`_ipc_soft_map` 참조); 실행 ID `s5p34-*`, 탐침은 스테이징 사본만):
- 일괄 진단 `s5p34-pre-1`(Darwin 그대로, 현재 07 헤더; ast·exception·ipc_kobject·ipc_mig·ipc_tt·ipc_xxx·kalloc·mach_debug): ast 는 BSD 헤더(`machine/limits.h`), exception 은 `norma_ipc.h`·`mach_kdb.h` 없음, ipc_kobject 는 `ikm_sender` 로 컴파일 실패; ipc_mig·ipc_xxx·kalloc 은 크기 차이 여럿, ipc_tt 는 원본에 없는 함수 2 개(`retrieve_task_self`·`retrieve_thread_self`). **mach_debug 는 6 함수 중 `mach_port_space_info` 만 12 B 짧음**(빌드 2271 B).
- 원본 `_mach_port_space_info`(0x151f60) 머리에 `mov [ebp-0x1c],0`(0x151f69)·`mov [ebp-0x28],0`(0x151f70). `[ebp-0x1c]` 는 `round_page` 결과를 받아 `kmem_alloc`(0x173ad4) 에 넘기고 `kmem_free`(0x173e90) 에 쓰는 `table_size`(0x15207e 저장), `[ebp-0x28]` 은 같은 방식의 `tree_size`(0x152112 저장).
- 탐침 1(+ Darwin :347 `table_size = 0`, :351 `tree_size = 0` 선언 초기화): `mach_port_space_info` MATCH. `_host_ipc_hash_info`(0x151d04)·`_host_ipc_marequest_info`(0x151e30) 가 17 B씩 다름 — 원본 머리 `xor edi,edi` 가 빌드에 없음.
- 탐침 2(+ Darwin :158·:250 `vm_size_t size = 0;`): O3·O3c(같은 SHA `7c7da496…`, `__common`·`__data` 없음) **OBJECT_MATCH 6/6**, `__text` 2283 B·재배치 71. 미정의 심볼에 `_vm_move`·`_ipc_soft_map`(= `MACH_OLD_VM_COPY` 분기, 58 절 옵션과 일치).
- W1: 검토한 참조 후보 — Darwin `ipc/mach_debug.c`(초기화 없음), Mach4 `kernel/ipc/mach_debug.c`(초기화 없음, `MACH_OLD_VM_COPY` 분기 자체가 없음 — 함수 diff), NeXTMach(이 파일 없음) — 와 복원 수정으로는 원본 바이트가 나오지 않음. `grep 'table_size = 0\|tree_size = 0'` 참조 트리 0 건.
- 경계: 앞 `00 00 00`(확정 ipc_thread 끝 0x151cb9, 정렬 4), 뒤 `00` 1 B(0x1525a8 `mach_msg.c` 시작) — 최소 채움.

설계(W2–W6):
1. `07_kernel/src/ipc/mach_debug.c` = Darwin 판 + 선언 4 줄의 초기화(`= 0`) — 지역 변수 이름은 참조 그대로, 새 식별자 없음. 각 줄 바로 앞에 W3 표시 주석, 머리말 뒤 수정 주석. MODIFICATIONS("authored", 근거 주소 — 59.1 에서 0x151d0d·0x151f69·0x151f70 로 정정, 0x151e39 는 Mach4 줄), PROVENANCE("authored lines"), functions.tsv `source_id` = `darwin01+authored`(변경한 3 함수) / `darwin01`(그대로인 3 함수).
2. 헤더·옵션 변경 없음 → 회귀 불필요(58 절 회귀 이후 07 헤더·generated 불변을 SHA 로 확인).
3. W5 예측: `__text` 2283 B, 재배치 71, O3 = O3c = 탐침 2 SHA(주석 줄 추가로 줄 번호만 바뀜), O2 는 기록만. L1 OBJECT_MATCH 6/6, 경계 증명서 → 등급 A.

### 59.1 codex 교차검토(QP34) 판정 → 설계 변경(참조 1 줄 + 작성 3 줄)

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| **W1 일부 거짓: Mach4 `kernel/ipc/mach_debug.c:195` 에 `vm_size_t size = 0; /* '=0' to shut up lint */`(`host_ipc_marequest_info`)** — 내 grep 은 `table_size`/`tree_size` 만 찾아 놓침 | Mach4 mach_debug.c:188(함수 시작)·190–200 열람, :195 에 그 줄 | ✅ **내 오류.** `host_ipc_marequest_info` 의 초기화는 참조(Mach4) 줄을 그대로 쓰는 복원 수정(D014)이고 작성이 아님 |
| `xor edi,edi` 실제 주소는 0x151d0d·0x151e39(머리 push 뒤), `edi` = `size`(`addr` 는 `[ebp-4]`) | capstone: 0x151d0d·0x151e39 `xor edi, edi`; 0x151d04·0x151e30 은 `push ebp` | ✅ 근거 주소를 명령 주소로 |
| `[ebp-0x1c]`=table_size(0x15207e), `[ebp-0x28]`=tree_size(0x152112), Darwin :390·:411 흐름과 일치 | 59 절 디스어셈블 출력(0x15207e·0x152112 저장 직후 `kmem_alloc`) | ✅ |
| 스테이징 diff 는 :158·:250·:347·:351 의 ` = 0` 뿐(715 줄) | 탐침 스크립트의 assert(정확한 원래 줄 내용) + `diff` | ✅ |
| 탐침 2 O3·O3c OBJECT_MATCH 6/6, 2283 B, 71 재배치, SHA `7c7da496a90c089c…` | l1batch 출력 | ✅ |
| 경계 `00 00 00` / `00`, 다음 심볼 `_mach_msg_send` 0x1525a8 | 59 절 Python 출력 | ✅ |
| 회귀 생략은 조건부로 타당 — 비교 증거를 남길 것 | 탐침 2 스테이징 137 파일 중 mach_debug.c 를 뺀 136 개가 현재 원천과 SHA 동일(Python) | ✅ 58.2 이후 헤더 불변의 증거로 기록 |
| W3 표시는 작성 줄에만, Mach4 유래 줄은 참조 출처로 | — | ✅ |
| W6: 탐침마다 사전 예측 기록이 없음 | 탐침 1·2 는 예측을 문서로 남기지 않고 실행(사실 수집 관례) | ✅ **규칙 위반 인정.** 이유는 당시 근거(탐침 1: 0x151f69·0x151f70 의 0 저장; 탐침 2: 0x151d0d·0x151e39 의 `xor edi,edi`) — 이후 탐침은 cmd 머리에 예측을 적는다 |
| "데이터 참조 없음" → "객체 소유 데이터 섹션 없음"(`_page_mask`·`_ipc_kernel_map`·`_ipc_soft_map` 참조) | 탐침 2 미정의 심볼 목록에 셋 다 있음 | ✅ 문구 정정 |

설계 수정:
1. `host_ipc_marequest_info`(Darwin :250): Mach4 :195 의 줄 `vm_size_t size = 0; /* '=0' to shut up lint */` 을 그대로(주석 포함) — 복원 수정, Mach4(CMU) 출처. functions.tsv `source_id` = `darwin01`(+ restoration edit).
2. 작성 3 줄(W3 표시 주석 각각 앞): `host_ipc_hash_info`(Darwin :158) `size`, `mach_port_space_info`(:347·:351) `table_size`·`tree_size` — 근거 0x151d0d·0x151f69·0x151f70. 이 두 함수만 `darwin01+authored`. 문체는 Darwin 의 다른 선언과 같게(`= 0` 만, 주석 없음).
3. Mach4 줄이 들어가므로 파일에 Mach4 고지 필요 여부: Mach4 `mach_debug.c` 머리말 확인 후 해당 고지(CMU / Utah) 추가.
4. 예측(W5): 주석은 바이트에 영향 없음 → O3 = O3c = 탐침 2 SHA `7c7da496…`, 2283 B, 재배치 71, OBJECT_MATCH 6/6.

### 59.2 결과 (2026-10-01) — `mach_debug.c` 확정(A, Mach4 1 줄 + 작성 3 줄)

- 07_kernel `ipc/mach_debug.c`(신규) = Darwin + Mach4 :195 줄(`host_ipc_marequest_info`) + 작성 3 줄(W3 표시) + 수정 주석. 고지: Darwin 판이 같은 CMU 고지(1991,1990)를 이미 가짐.
- 빌드 `s5p34-build-1`: 예측대로 O3 = O3c = 탐침 2 SHA(`7c7da496…`). **O2 도 같은 SHA**(명령에 `-O2` 확인) — 이 객체는 최적화 수준의 증거가 아님. OBJECT_MATCH 6/6, 경계 `00 00 00`/`00` → **A**.
- 회귀 없음(헤더·generated 불변, 59.1). 기록: objects_confirmed 50 행(머리 포함), functions.tsv +6(329 함수; `darwin01+authored` 2), MODIFICATIONS·PROVENANCE 각 1 행, 증거 `x86-mach_debug.md`·`.diff`.

## 60. S5-P34 세부 계획 — `kern/ipc_tt.c` = Darwin 판에서 `retrieve_task_self`·`retrieve_thread_self` 삭제 (코딩 전, 2026-10-01)

사실(원본 [0x1593e4, 0x15a39c) 4024 B, Ghidra 범위 32 개, `__data` 60 B; 실행 ID `s5p35-*`, 탐침은 스테이징 사본만):
- 진단 `s5p34-pre-1`(Darwin 그대로): 원본 32 함수의 길이는 모두 같고, 빌드에만 `_retrieve_task_self`·`_retrieve_thread_self` 가 있음(빌드 4176 B). 원본 심볼표(`03_original/x86/inventory/symbols.tsv`)에는 `_retrieve_task_self_fast`(0x1598a0)·`_retrieve_thread_self_fast`(0x159900)만 있고 두 함수는 없음.
- 탐침 1(예측을 cmd 머리에 기록: 4024 B, 32 함수): Darwin `kern/ipc_tt.c:418–471`(두 함수의 주석·본문·빈 줄; :472 부터 `retrieve_task_self_fast` 주석) 삭제 → O3·O3c(같은 SHA `d2731dfd…`) **OBJECT_MATCH 32/32**, `__text` 4024 B·재배치 83, `__data` 60 B 0x1decc4(L1d) 차이 0.
- 다른 사용처: `machdep/ppc/PseudoKernel.c:105`(ppc, x86 빌드 밖), 선언 `kern/ipc_tt.h:68`·`:74`(정의 없는 선언은 무해 — 그대로 둠). Mach4 `kernel/kern/ipc_tt.c:401`·`:428` 에도 두 함수가 있어 참조 대안 없음.
- 경계: 앞 `00 00 00`(확정 ipc_sched 끝 0x1593e1, 정렬 4), 뒤 0 B(마지막 `_space_deallocate` 가 `ret` 0x15a39b 로 끝나고 0x15a39c 에서 다음 함수 `55 89 e5` 시작).

설계: `07_kernel/src/kern/ipc_tt.c` = Darwin 판에서 :418–471 삭제(복원 수정 D014, 작성 없음) + 수정 주석. MODIFICATIONS·PROVENANCE 행, objects_confirmed(A)·functions.tsv 32 행. 헤더 변경 없음 → 회귀 불필요. 예측: O3 = O3c = 탐침 1 SHA, O2 는 기록만.

### 60.1 codex 교차검토(QP35) 판정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| 스테이징 = Darwin[:417] + Darwin[471:] (418–471 만 삭제) | 탐침 스크립트 assert(:418 `/*`+`Routine:\tretrieve_task_self`, :472 `/*`+`…_fast`, :470 `}`) 와 `grep -n` 출력(:419·:473) | ✅ |
| O3·O3c OBJECT_MATCH 32/32, 4024 B, 83 재배치, `__data` 60 B 0x1decc4, SHA `d2731dfd…` | l1batch 출력(60 절) | ✅ |
| 원본 inventory 에 비-fast 이름 없음(symbols.tsv:2605·2607, strings.tsv:5548·5550 은 `_fast`) — 이름 없는/인라인 코드 부재의 증명은 아님 | 60 절 grep 출력(같은 4 줄) | ✅ 문구 그대로 받음 |
| 사용처: `ipc_tt.h:68·74` 선언, ppc `PseudoKernel.c:105` 뿐, `.defs` 0 | 60 절 `grep -rnw` 출력 | ✅ (`.defs` 0 건은 grep 범위에 포함됨) |
| 경계 `00 00 00`, `ret` 0x15a39b, 0x15a39c `push ebp` | 60 절 Python/capstone 출력 | ✅ |
| D014 R2(최소 삭제) 에 부합, 선언 유지 무해 | 19 절 R1–R5 열람 | ✅ |
| R3: diff·PROVENANCE `changes`·functions `source_revision` 접미 명시 | — | ✅ 설계에 명시 |
| R5: 탐침 예측에 외부 참조·오프셋 없음 | `s5p35-probe1.cmd:1` 예측 = 크기·함수 수·span | ✅ 절차 미흡 인정. 최종 빌드 예측에 넣음(아래) |
| 표제 S5-P34 와 ID s5p35 불일치 | 58.1 과 같은 관례(실행 ID ≠ 절 번호) | ⚖️ 유지 |
| "참조 대안 없음" 은 과함: Mach4 에도 두 함수가 있고(:401·:428), NeXTMach 는 구조가 다름 | Mach4 grep 출력(:401·:428) | ✅ 문구: "검토한 참조(Darwin·Mach4)는 모두 두 함수를 가짐, NeXTMach 는 다른 IPC 구조" |
| **`ipc_tt.h`(·`ipc_tt.c`) 가 07_kernel 에 없음 — 채택·출처 기록 필요** | `.i` 의 `# N "file"` 표지를 07 과 대조(Python): s5p32·s5p33 빌드는 07 에 없는 파일 0, s5p35 탐침은 `kern/ipc_tt.c`·`kern/ipc_tt.h`, **s5p34-build-1(7 회차)은 `mach_debug/ipc_info.h`** | ✅ **7 회차 누락(내 오류) 발견.** `ipc_tt.h`·`mach_debug/ipc_info.h` 를 그대로 07 에 채택, PROVENANCE "none (verbatim)" 행 |

설계 보강: (1) `07_kernel/src/kern/ipc_tt.c` = Darwin − :418–471 + 수정 주석; `kern/ipc_tt.h`·`mach_debug/ipc_info.h` 그대로 채택(내용 동일 → 이미 확정된 mach_debug 빌드 입력과 같은 바이트, 07 빌드 SHA 로 재확인). (2) R3 기록: `evidence/x86-ipc_tt.diff`, PROVENANCE `changes` "restoration edit: retrieve_task_self/retrieve_thread_self removed (…diff)", functions `source_revision` "+ restoration edit". (3) R5 예측(최종 빌드): `__text` 4024 B, 재배치 83, `__data` 60 B, 외부 미정의 심볼 = 탐침 1 과 같은 집합(비-fast `retrieve_*` 없음), 함수 오프셋 = 탐침 1(32 범위와 같음), O3 = O3c = `d2731dfd…`. (4) 채택 검사: 최종 `.i` 의 모든 `src/` 표지가 07 에 있는지 Python 으로 확인(앞으로 매 회차 수행).

### 60.2 결과 (2026-10-01) — `ipc_tt.c` 확정(A) · `ipc_tt.h`·`mach_debug/ipc_info.h` 채택

- 07_kernel `kern/ipc_tt.c` = Darwin − :418–471 + 수정 주석; `kern/ipc_tt.h`·`mach_debug/ipc_info.h` 그대로.
- 빌드 `s5p35-build-1`: 예측대로 O3 = O3c = `d2731dfd…`(O2 `8e28b8c3…` 다름), 4024 B·재배치 83·`__data` 60 B, 미정의 심볼 = 탐침 1. OBJECT_MATCH 32/32, 경계 `00 00 00`/0 B → **A**. 같은 실행에서 mach_debug 재빌드 = `7c7da496…`(3 변형) — `ipc_info.h` 채택이 바이트를 바꾸지 않음.
- 채택 검사: 두 `.i` 의 `src/` 표지 109 개가 모두 07 에 있음.
- 기록: objects_confirmed 51 행(머리 포함), functions.tsv +32(361 함수), MODIFICATIONS +1, PROVENANCE +3(216 행), 증거 `x86-ipc_tt.md`·`.diff`, `x86-mach_debug.md` 정정 추가.

## 61. S5-P35 세부 계획 — `kern/kalloc.c` = Darwin 판 + NeXTMach malloc 계열 + 작성 3 곳(D016) (코딩 전, 2026-10-01)

사실(원본 [0x15a67c, 0x15ab9b) 1311 B; 실행 ID `s5p36-*`, 탐침은 스테이징 사본만; 탐침 cmd 머리에 예측 기록):
- 원본 심볼(symbols.tsv): `_kalloc_init` 0x15a67c, `_kalloc_noblock`, `_kalloc`, `_kget`, `_kfree`, `_malloc` 0x15a880, `_calloc` 0x15a910, `_realloc` 0x15a9a8, `_free` 0x15ab30, `_malloc_good_size` 0x15ab94(Ghidra 범위 밖, capstone: `push ebp; mov ebp,esp; mov esp,ebp; pop ebp; ret` → 끝 0x15ab9b).
- 진단(Darwin 그대로): 앞 5 함수 길이 일치, malloc 계열 없음, 원본에 없는 `kalloc_zone`(Darwin :261–281) 있음. Darwin·Mach4 에는 malloc 계열이 없고 NeXTMach mk-108.1 `kern/kalloc.c:332–376` 에 `malloc`·`calloc`·`realloc`·`free`·`malloc_good_size` 가 있음.
- 탐침 1(Darwin :261–281 을 NeXTMach :332–376 으로 교체): malloc 144·calloc 152 일치(-O3 인라인), realloc 256(원본 392)·free 96(100).
- 원본 realloc(0x15a9a8): ① `addr == 0` 이면 malloc 과 같은 경로(인라인 kalloc → `bzero` → `*new = size+8` → `new+2`; 0x15a9b7–0x15aa37), ② `bcopy` 길이는 `size < *sizep` 이면 `size`, 아니면 `*sizep`(0x15aab8–0x15aac8; 두 `push` 가 공통 `call _bcopy` 로 합류). 원본 free(0x15ab30): ③ `data == 0` 이면 반환(0x15ab38 `test/je`), `sizep` 계산(0x15ab3c `lea ebx,[eax-8]`)은 검사 뒤.
- 탐침 2(①·② 를 `?:`·③ 을 선언 초기화 뒤 검사로): realloc 388(−4), free 길이 일치. 탐침 3(② 를 if/else 두 `bcopy` 호출로 — realloc 변형 2): realloc MATCH, free 7 B 다름(`lea` 가 검사 앞). 탐침 4(③ 의 `sizep` 대입을 검사 뒤로 — free 변형 2): **`__text` 1311 B 바이트·참조 차이 0**. common 변형(O3c): 9 MATCH + `_kalloc_init` MATCH_UNVERIFIED(`__bss`). `-fno-common`(O3): `__common` 72 B 후보 3 개로 모호 → 36.1 절차 대상.
- 데이터: `__data` 79 B 0x1ded18(`_k_zone_elemsize` 심볼, L1d 일치). common: `_k_zone` 0x40(원본 0x1f6360, 다음 심볼까지 64), `_k_zone_maxsize` 4(0x1f63a0, 간격 16), `_kalloc_map` 4(0x1f6330, 간격 16) — 크기 ≤ 간격. `__bss` 256 B = `static char k_zone_name[16][16]`(원본 심볼 없음): `zerofill_check.py` → 참조 1 개, Δ 하나, 후보 [0x1e5a98, 0x1e5b98) 정렬·zero-fill 섹션 안·심볼 없음·겹침 없음이지만 **음성 검사 미검출(참조 1 개라 구조상 불가) → `fail`**(`09_validation/reconstruction/s5p36-zerofill-check-kalloc-pre-20261001.json`).
- 경계: 앞 0 B(`_task_secure` 끝 `ret` 0x15a67b), 뒤 `00` 1 B(kernel_stack 0x15ab9c).
- W1: 검토한 참조 — Darwin(malloc 계열 없음), Mach4(없음), NeXTMach(①②③ 없음) — 와 복원 수정으로 원본 바이트가 나오지 않음.

설계:
1. `07_kernel/src/kern/kalloc.c` = Darwin 판, `kalloc_zone`(:261–281, 원본에 없음 — 복원 수정) 자리에 NeXTMach :332–376(복원 수정, 출처 NeXTMach; D013 커밋 허용) + 작성 ①②③(W3 표시 주석 각각). 작성분: realloc `if (addr == 0) return malloc(size);` 와 `if (size < *sizep) bcopy(…, size); else bcopy(…, *sizep);`, free 의 `if (data == 0) return;` 와 `sizep` 대입을 검사 뒤로(선언과 대입 분리). 변형 수: realloc 2, free 2(W4 한도 3 이내).
2. 등급: `__bss` 가 zerofill `fail` 이므로 규칙상 A/A*/P 를 줄 수 없다. objects 표에 넣지 않고 증거·계획에만 "바이트·참조 일치, `__bss` 단일 참조로 배치 미검증" 으로 기록. functions.tsv 10 행은 `compared` + **`low`**(README:12 의 일반 등급 — high/medium 정의를 충족하지 못함)로 두고 비고에 사유. 규칙 완화는 하지 않는다.
3. 36.1: O3(`-fno-common`)·O3c 의 재배치 위치·형태 대응, 재배치 밖 바이트 동일, common 크기 ≤ 간격을 Python 으로 확인해 기록.
4. 헤더 변경 없음 → 회귀 불필요. `.i` 표지 채택 검사. 최종 빌드 예측: O3·O3c 가 탐침 4 와 같은 SHA(`d87a52ac…`·`126e1a24…`), 1311 B, 재배치 95, 미정의 심볼 = 탐침 4.

### 61.1 codex 교차검토(QP36) 판정 → 설계 변경: **채택 보류**

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| 스테이징 = Darwin[:260] + NeXTMach[331:376] + Darwin[281:] + 작성 3 곳, 다른 차이 없음 | 탐침 스크립트 assert(:261 `struct zone *kalloc_zone(`, :281 `}`, 블록 처음 `/*`·끝 `malloc_good_size`), 교체 문자열 각 1 회 | ✅ |
| 원본 realloc NULL 경로·min 길이(`*sizep` 는 머리 8 B 포함)·free 검사 뒤 `lea`·`malloc_good_size` 끝 0x15ab9b·경계 | 61 절 capstone 출력(0x15a9b7, 0x15aab8–0x15aac8, 0x15ab38–0x15ab3c, 0x15ab9a `ret`, 0x15ab9b `00`) | ✅ ("min(size, 헤더 포함 이전 크기)" 로 기록) |
| O3 는 참조 42 개 미검증(`__common` 모호), O3c 는 9 MATCH + `_kalloc_init` 만 미검증 — "차이 0" 이 "전부 검증" 은 아님 | l1batch 출력(탐침 4) | ✅ 문구 정정 |
| zerofill `fail` 은 음성 검사만의 이유, `__data` 재배치 0 → 두 번째 참조 없음 | 탐침 4 O3c 섹션 목록 `('__data', 79, 0)`, zerofill JSON `problems` 빈 목록 | ✅ |
| common 크기 ≤ 간격(64/64, 4/16, 4/16) — 상한 일관성일 뿐 | symbols.tsv 1781·1783·1786·2061·2870 줄 출력 | ✅ |
| **`low` 는 README:12 에 이름만 있고 대체 등급으로 정의되지 않음; W4 는 OBJECT_MATCH 또는 정의된 등급을 요구** | README:12, 계획 :1642 W4 원문 열람 | ✅ **설계 2 철회: 작성 줄이 있는 파일은 W4 를 충족하지 못하므로 07_kernel 채택·표 추가를 하지 않는다** |
| 작성 3 곳은 W2/W6 에 부합(관찰된 실행 순서·두 인자 경로 + 합류 호출), 다만 역사적 문법의 증명은 아님 | 탐침 2–4 diff 와 원본 명령 | ✅ 기록 |
| NeXTMach `kalloc.c:1–11` 고지(1987 CMU, CMU 라이선스 합의 언급, 1985 Avadis Tevanian) 보존·D013 기록 | NeXTMach kalloc.c 1–24 열람, `acquisition.json:16–19` 커밋 `f6bdb9c…` | ✅ 채택 시 필요(보류로 이번엔 미적용) |
| 36.1 의 재배치 대응은 성립하나 O3c 가 NOT_MATCH 라 전체 조건 불성립; O3c 의 `.i` 미보존 | `s5p36-probe4.cmd` 의 `-E` 1 개 | ✅ |
| R5 예측에 함수 오프셋 누락, R3/W3 기록 명시 | — | ✅ 채택 시 적용 |

### 61.2 결과 (2026-10-01) — `kalloc.c` 보류(바이트·참조 차이 0, `__bss` 배치 미검증)

- 07_kernel 변경 없음. 탐침 4 원문 diff 를 `06_reconstruction/evidence/x86-kalloc-probe4.diff` 로, 사실과 판정을 `x86-kalloc.md` 로 보존.
- 재개 조건(하나라도): (a) `k_zone_name`(`__bss` 256 B)의 위치를 독립적으로 고정하는 근거(예: 이웃 zero-fill 의 확정으로 [0x1e5a98, 0x1e5b98) 의 앞뒤가 모두 다른 객체 소유로 증명), (b) 단일 참조 zero-fill 에 대한 규칙을 계획에 새로 세우고 codex 검토·사용자 판단을 거친 경우. 그때 O3c `.i` 도 함께 보존하고 R3/W3·D013(NeXTMach 고지) 기록을 한다.

## 62. S5-P36 세부 계획 — `kern/ipc_xxx.c` = Darwin 판에서 나중 추가분 제거 + `suser()` (코딩 전, 2026-10-01)

사실(원본 [0x15a39c, 0x15a628) 652 B, 함수 8: `_host_priv_self`·`_device_master_self`·`__lookupd_port`·`__event_port_by_tag`·`_object_copyin`·`_object_copyout`·`_port_reference`·`_port_release`; `__data` 23 B 0x1ded00(`_ev_port_list`), common `_lookupd_port` 0x1f6358; 실행 ID `s5p37-*`, 탐침은 스테이징 사본만, cmd 머리에 예측):
- 진단(Darwin 그대로): `host_priv_self`·`device_master_self` +4, `__lookupd_port` +32, `__event_port_by_tag` +8, 빌드에만 `__lookupd_port1`·`_send_notification`.
- 원본 `_host_priv_self`(capstone 0x15a39c–0x15a3f4): 인라인 `do_object_copyout` 에 `IP_DEAD` 검사가 없음 — `push &name; push 1; push 0x11; push port; call _ipc_port_copy_send; add esp,4; push eax; push itk_space; call _ipc_object_copyout`. 특권 검사는 인자 없는 `call _suser`(0x108310); 원본 심볼표에 `_is_suser`·`_lookupd_port_priv`·`__lookupd_port1` 없음, `_send_notification` 은 0x15a63c(이 객체 밖, 사이에 `_ds_notify` 0x15a628 등).
- 탐침 1(Darwin 에서: `do_object_copyout` 의 `IP_DEAD` 분기 제거 → `ipc_object_copyout(task->itk_space, ipc_port_copy_send(port), …)`; `lookupd_port_priv` 선언·`_lookupd_port_choose`·`_lookupd_port1`·`send_notification` 삭제; `_lookupd_port` 의 else 를 `port = lookupd_port;`): 8 함수 길이·바이트 일치, 참조만 `_is_suser`(원본 `_suser`) 4 곳 미검증.
- 탐침 2(+ `is_suser()` → `suser()` 4 곳; NeXTMach mk-108.1 의 인자 없는 `suser()` 와 같은 형태, 예: `bsd/kern_time.c:116`): O3·O3c **OBJECT_MATCH 8/8**, `__text` 652 B·재배치 32, `__data` 23 B(L1d), O3 의 `__common` 4 B 는 심볼 배치(placement-only), common 크기 4 ≤ 원본 간격 8(다음 `_k_zone`).
- 경계: 앞 0 B(확정 ipc_tt 끝 0x15a39c), 뒤 0 B(`ret` 0x15a627, `_ds_notify` 0x15a628). `.i` 표지 중 07 에 없는 것은 대상 파일 자신뿐.

설계: `07_kernel/src/kern/ipc_xxx.c` = 탐침 2 본문(복원 수정 D014: 삭제와 단순화, 작성 없음 — `suser()` 는 원본 호출 대상의 이름) + 수정 주석. MODIFICATIONS·PROVENANCE·diff, objects_confirmed(A)·functions.tsv 8 행(`+ restoration edit`). 헤더 변경 없음 → 회귀 불필요. 예측(R5): O3 = `2c9bccd5…`, O3c = `369dcdf9…`(탐침 2), 652 B, 재배치 32, 함수 오프셋 = 탐침 2(spans 표와 같음), 미정의 심볼에 `_suser`, `_is_suser` 없음.

### 62.1 codex 교차검토(QP37) 판정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| 스테이징 diff 는 계획한 편집뿐(`IP_DEAD` 분기, priv 선언·chooser·`_lookupd_port1`·`send_notification` 삭제, `port = lookupd_port`, `is_suser()`→`suser()` 4 곳) | 탐침 스크립트의 문자열 교체(각 1 회 assert)·`is_suser count 4` 출력 | ✅ |
| 원본: 0x15a3ab 인자 없는 `call _suser`, `copy_send` 결과가 바로 `copyout` 으로, `_send_notification` 0x15a63c 는 다른 곳에 존재 | 62 절 capstone 출력, symbols.tsv | ✅ "전역적으로 없음" 이 아니라 "이 객체 밖" 으로 기록 |
| L1 O3·O3c OBJECT_MATCH 8/8, 652 B, 32 재배치, `__data` 23 B(포트 배열 + `"object_copyout"`), O3 `__common` 4 B placement-only | l1batch 출력 | ✅ |
| R1/R2 최소 복원 수정. 단 **동작 차이**: Darwin 은 `IP_DEAD` 면 `PORT_NULL` 반환, 복원본은 그 값을 `ipc_object_copyout` 에 넘김(전제 `assert(IO_VALID(object))`, 07 `ipc/ipc_object.c:637`) | ipc_object.c:630–640, ipc_port.c:1055–1062 열람 | ✅ 기록: 바이트로 입증된 원본 동작이며 Darwin 과 동작이 같다고 주장하지 않음 |
| 원본 `_suser`(0x108310–0x10835c)는 인자를 읽지 않고 0/1 반환; Darwin `suser(cred, acflag)`(kern_prot.c:532)는 0/오류 — 나중 BSD 복원 때 Darwin 정의를 그대로 쓸 수 없음 | capstone(`[ebp+8]`·`[ebp+0xc]` 읽기 없음), kern_prot.c:528–536 열람 | ✅ 후속 의무로 기록 |
| 스테이징 헤더에 `suser` 선언 없음 | probe 2 cmd 실행 전 `grep -rn suser …/src --include=*.h` 출력 0 줄 | ✅ |
| 경계 0 B / 0 B | 62 절 출력 | ✅ |
| 36.1: 재배치 위치·폭·pcrel·유형 동일, 재배치 밖 바이트 동일, 4 곳(0xfb·0x10e·0x116·0x11f)이 local→extern `_lookupd_port`; **O3c `.i` 미보존** | `s5p37-probe2.cmd` 에 `-E` 1 개 | ✅ 최종 빌드에 O3c `.i` 추가하고 두 `.i` 동일 확인 |
| 통합 의무: `send_notification`(kern_server.c:1149 호출)은 원본 0x15a63c 의 다른 객체로; `_lookupd_port1` 은 `syscall_sw.c:156`·`mach_traps.h:70`·`mach/syscall_sw.h:79` 에서 참조 | 내 grep 출력(같은 4 곳) | ✅ 기록(그 객체·syscall_sw 차례에서 처리) |
| R3·R5 기록 완비, 표제 S5-P36 vs `s5p37-*` | 58.1 과 같은 관례 | ✅ R3/R5 / ⚖️ 표제 유지 |

설계 보강: 최종 빌드에 O3c 전처리(`-E` 를 `-fno-common` 없이)를 추가해 두 `.i` 의 바이트 동일을 Python 으로 확인. R5 외부 참조 예측: 미정의 심볼 = 탐침 2 집합(`_suser` 포함, `_is_suser` 없음).

### 62.2 결과 (2026-10-01) — `ipc_xxx.c` 확정(A)

- 07_kernel `kern/ipc_xxx.c` = 탐침 2 본문 + 수정 주석(APSL 고지만 있는 파일). 빌드 `s5p37-build-1`: 예측대로 O3 = `2c9bccd5…`(O2 도 같음), O3c = `369dcdf9…`, 두 `.i` 동일, 미정의 심볼 = 탐침 2. OBJECT_MATCH 8/8(두 변형), 경계 0/0 → **A**.
- 기록: objects_confirmed 52 행(머리 포함), functions.tsv +8(369 함수), MODIFICATIONS·PROVENANCE 각 +1, 증거 `x86-ipc_xxx.md`·`.diff`. 후속 의무(send_notification·`_lookupd_port1`·`suser` 정의)는 증거에 기록.

## 63. S5-P37 세부 계획 — `vm/vm_user.c` = Darwin 판에서 `vm_reallocate`·`vm_wire` 삭제 (코딩 전, 2026-10-02)

이번 회차에서 먼저 조사하고 보류한 것(실행 ID `s5p38-*`, 스테이징만):
- `kern/ipc_mig.c`: 원본에 `_mach_msg`(0x158534, 416 B)가 `_mach_msg_abort_rpc` 뒤에 있음(Darwin 판에 없음, Mach4 `kern/ipc_mig.c:255` 에 있음). 탐침 1(Mach4 :240–336 삽입)은 `ipc_kmsg_get_from_kernel`·`ipc_mqueue_send`·`ipc_mqueue_receive`·`ipc_kmsg_copyout` 인자 수 불일치로 컴파일 실패 — 아직 미복원인 ipc_kmsg·ipc_mqueue 의 API 결정이 먼저. 보류.
- [0x15a628, 0x15a67c): `_ds_notify`(`xor eax,eax; ret`), `_vm_object_pager_wakeup`(빈 함수), `_send_notification`, `_task_secure`(`return 1`) — 함수 사이 채움이 `90` 이라 한 목적 파일로 보이나 Darwin 에는 `send_notification` 만 있음 → 참조에 없는 독립 새 파일이 필요(W6: 라이선스는 사용자 판단). 보류. [2026-10-08: D056 으로 해제 — 07 kern/ipc_xxx.c 끝에 둠, plan 392]
- 일괄 진단 `s5p38-pre-1`(14 파일): machine·ns_timer·timer·mapfs·ux_exception·vm_machdep·miniMonMachdep·catch·mach_header 는 BSD 헤더(`machine/limits.h`)·옵션 헤더(`norma_ether.h`·`mach_nbc.h`·`mach_kdb.h`)·`pc_support.h`·`mach-o/loader.h` 없음으로 실패. PCtimers·mach_clock·vm_pageout 은 차이 큼, syscall_sw 는 `__data` 6 B 차이·참조 3 미검증(`_lookupd_port1` 등, 62.1 의무와 연결), **vm_user 는 원본 11 함수 길이 모두 같고 빌드에만 `_vm_reallocate`·`_vm_wire`**.

사실(vm_user, 원본 [0x17c4e0, 0x17c942) 1122 B, 함수 11; 원본 심볼표에 `_vm_reallocate`·`_vm_wire` 없음):
- 탐침 2(Darwin `vm/vm_user.c` 에서 `vm_reallocate`(:189–203, 정의와 뒤 빈 줄)·`vm_wire`(:327–363, 앞 빈 줄 3 개·주석 포함) 삭제; diff `189,203d188`·`327,363d311`): O3c(common 변형) **OBJECT_MATCH 11/11**, `__text` 1122 B·재배치 52, `__data` 26 B 0x1e0e3d(L1d). O3(`-fno-common`)는 바이트·참조 차이 0, `__common` 64 B 후보 2 개로 모호.
- 36.1: common `_vm_alloc_lock` 12 B(원본 0x1f64c0, 다음 심볼까지 12), `_vm_stat` 52 B(0x1f64f0, 52) — 크기 ≤ 간격. `__text`·`__data` 재배치 위치 동일, 재배치 밖 바이트 차이 0, 모양 차이는 scattered VANILLA(`__common` 대상) → extern 6 곳과 local → extern 5 곳(63.1 에서 정정 — 처음 4 곳만 적음).
- 다른 사용처: `mach_host.defs:427` `routine vm_wire`, `mach_debug.defs:217` `routine vm_reallocate`(MIG 정의 — 서버 스텁 복원 때 의무), 선언 `vm/vm_user.h:47`(07 에 있음, 그대로).
- 경계: 앞 0 B(`ret` 0x17c4df), 뒤 `00 00`(vnode_pager 0x17c944, 4 정렬 최소).

설계: `07_kernel/src/vm/vm_user.c` = 탐침 2 본문(복원 수정 D014, 작성 없음) + 수정 주석. MODIFICATIONS·PROVENANCE·diff·functions.tsv 11 행·objects_confirmed(A, 36.1 근거). 헤더 변경 없음. 최종 빌드에 O3c `.i` 도 남겨 두 `.i` 동일 확인. 예측(R5): O3 = `a56055a3…`, O3c = `7b9ce4fe…`, 1122 B, 재배치 52, 함수 오프셋·미정의 심볼 = 탐침 2.

### 63.1 codex 교차검토(QP38) 판정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| 스테이징 = Darwin − :189–203 − :327–363 정확(뒤 삭제는 앞 빈 줄 2 개 포함, :326 남음) | `diff` 출력 `189,203d188`·`327,363d311`, `sed -n 326,327p` 둘 다 빈 줄 | ✅ |
| 원본에 `_vm_reallocate`·`_vm_wire` 없음, 11 함수 1122 B, `ret` 0x17c4df, 끝 `ret` 0x17c941 뒤 `00 00`, 다음 `_vnode_pager_vput` 0x17c944 | 63 절 Python 출력(앞 `…5d c3`, 뒤 `0000`) | ✅ |
| O3c OBJECT_MATCH 11/11; O3 는 차이 0 이나 참조 11 미검증·NOT_MATCH | l1batch 출력 | ✅ |
| **재배치 변환은 scattered→extern 6(0x5e·0x92·0x227·0x233·0x23f·0x24b) + local→extern 5(0x6·0x4b·0x97·0x21b·0x253)** — 계획의 "4 곳" 은 틀림 | Python 재계산 출력(같은 11 곳, 그 밖 0) | ✅ **내 오류**(첫 4 개만 출력하고 extern 비교를 안 함) — 63 절 정정 |
| 36.2(ipc_table)에는 scattered 가 없어 "같은 예외" 가 아님 | `s5p12-build-1` O3 ipc_table 의 scattered 0 | ⚖️ 사실. 다만 scattered→extern 은 이미 56.1(ipc_notify, 계획 1912 행: "형태 차이 65 개는 모두 `__common` 대상 scattered")에서 인정된 선례 — 근거를 56.1 로 바로잡음 |
| common 12/12·52/52 는 상한 일관성일 뿐 | — | ✅ |
| 최종 빌드에 O3c `.i` 추가·두 `.i` 동일·대응 재확인 | — | ✅ (계획에 있음) |
| 다른 C 사용처 없음, MIG `.defs` 는 서버 생성 때 의무 | 63 절 grep 출력 | ✅ |
| ipc_mig 실패 4 건 확인; `_mach_msg` 416 B 중 명령은 413 B(뒤 nop 3) | 탐침 1 `01.err` | ✅ 기록 |
| 일괄 진단 14 중 실패 9·성공 5, 빠진 헤더에 `mach/mach_user_internal.h`(ux_exception) 추가; syscall_sw 미검증 참조 이름 `__lookupd_port1`·`_mach_msg_overwrite_trap`·`_mach_msg_simple_trap` | `04.err` 열람(:3) | ✅ 기록 |
| 작은 객체를 한 파일로 묶는 것은 추론 | — | ✅ (보류 상태 유지) |

### 63.2 결과 (2026-10-02) — `vm_user.c` 확정(A)

- 07_kernel `vm/vm_user.c` = 탐침 2 본문 + 수정 주석. 빌드 `s5p38-build-1`: 예측대로 O3 = `a56055a3…`, O3c = `7b9ce4fe…`(O2 `2240c57e…` 다름), 두 `.i` 동일, 미정의·common 심볼 = 탐침 2. O3c OBJECT_MATCH 11/11, 36.1 충족, 경계 0/`00 00` → **A**.
- 기록: objects_confirmed 53 행(머리 포함), functions.tsv +11(380 함수), MODIFICATIONS·PROVENANCE 각 +1, 증거 `x86-vm_user.md`·`.diff`.

## 64. S5-P38 세부 계획 — `machdep/i386/pc_support/PCinit.c`·`machdep/i386/fault_copy.c` 를 Darwin 판 그대로 채택 (코딩 전, 2026-10-02)

사실(실행 ID `s5p39-*`; 일괄 진단 `s5p39-pre-1`, Darwin 15 파일 그대로, 현재 07 헤더):
- 실패 8(vm_resident·vm_policy·vm_unix·kernel_stack·kern_server·machine_clock·APM_i386·kdp_machdep), 성공 7. 차이 큼: task(3 함수)·vm_kern(7 함수, 원본에 없는 `_kmem_alloc_pages`·`_kmem_remap_pages`)·zalloc. processor 는 함수 27 개 바이트 일치·`__common` 732 B 후보 7 개로 모호(36.1 대상, 다음 회차 후보). PCresume 는 5 함수 MATCH, `__TEXT,__const` 4 B 배치 불가(참조 없음).
- **PCinit**: `-O3`(`-fno-common`) L1 **OBJECT_MATCH 7/7**, `__text` 1365 B·재배치 59, 데이터 섹션 없음. 원본 [0x1a0e48, 0x1a139d): 앞 `00 00`(이전 객체 `ret` 0x1a0e45), 뒤 `00 00 00`(`_PCexception` 0x1a13a0) — 최소 채움.
- **fault_copy**: `-O3` L1 **OBJECT_MATCH 14/14**, `__text` 2225 B·재배치 56, 데이터 섹션 없음. 원본 [0x189a5c, 0x18a30d): 앞 0 B(확정 dbl_fault 끝 0x189a5c, 그 `90 90` 은 dbl_fault 소유), 뒤 `00 00 00`(`_fp_configure` 0x18a310). Ghidra 범위는 0x18a2f6 에서 끝나지만 그 뒤 이름 없는 코드(…`c3` 0x18a30c)까지 `__text` 2225 B 전체가 바이트 비교됨(objects.tsv 의 0x18a2f6 은 하한일 뿐).
- 두 객체 모두 common·zero-fill·`__data` 없음 → 36.1 불필요.

설계: 두 파일을 Darwin 원문 그대로 07 에 복사(수정 없음 → 수정 주석·MODIFICATIONS 없음, PROVENANCE "none (verbatim)"). 최종 `.i` 의 `src/` 표지 중 07 에 없는 헤더도 그대로 채택(PROVENANCE 행). 07 에서 다시 빌드해 진단과 같은 SHA 를 확인하고(예측: PCinit·fault_copy O3 SHA = `s5p39-pre-1` 의 것), objects_confirmed 2 행(A)·functions.tsv 21 행(`darwin01`, 수정 없음)·증거 1 개. O2·O3c 는 기록만. 헤더 변경 없음(새 헤더 추가만) → 다른 객체 회귀 불필요 — 단 추가 헤더가 기존 확정 빌드의 `.i` 에 이미 Darwin 원문으로 들어가던 것과 같은 바이트임을 SHA 로 확인.

### 64.1 codex 교차검토(QP39) 판정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| 진단 입력은 Darwin 원문(SHA 동일) | 스테이징은 `stage_headers.py --prefer-07` 로 만들었고 07 에 두 파일이 없음 → Darwin 원문 | ✅ (07 빌드 후 `.i`·SHA 로 재확인) |
| L1 은 `--ranges` 와 무관하게 `__text` 전체를 비교(l1_compare.py:282·315), 두 객체 OBJECT_MATCH 7/7·14/14, 데이터·common 없음 | 64 절 L1 출력(섹션 크기 1365·2225, 바이트 차이 0) | ✅ |
| 경계 바이트(PCinit `c3 00 00`/`c3 00 00 00`, fault_copy `90 90`/`c3 00 00 00`) | 64 절 Python 출력 | ✅ |
| 0x18a2f8–0x18a30c 는 `_suibyte` 의 `do_fault` 복구 경로(0x18a2da 가 복구 주소 0x18a2f8 저장) — fault_copy.c `suibyte` | capstone 0x18a2cc–0x18a30c, fault_copy.c:570–584 열람 | ✅ |
| 07 에 없는 실제 의존 헤더: PCinit → `PCprivate.h`·`PCpublic.h`·`PCmiscInline.h`·`bsd/i386/signal.h`, fault_copy → `bsd/sys/errno.h` | (07 빌드 `.i` 로 확정 예정) | ⚖️ 목록은 최종 `.i` 표지로 확정한 것만 채택 |
| "그대로" 는 채택 소스에 한함 — 헤더 환경에는 이미 복원 수정된 07 헤더가 쓰임 | — | ✅ 증거에 명시 |
| O3 일치는 재현성이지 역사적 최적화 수준의 유일성 아님; PCinit 경고 4 개 기록 | `13.err` 의 warning 4 줄 | ✅ |
| 표제 S5-P38 vs ID s5p39 | 관례 | ⚖️ 유지 |
| 다른 객체 회귀 생략은 "추가 헤더가 Darwin 원문과 같은 바이트" 확인 조건부 | — | ✅ 설계대로 SHA 확인 |

### 64.2 결과 (2026-10-02) — `PCinit.c`·`fault_copy.c` 확정(A, 원문 그대로)

- 07_kernel: 두 소스 + `.i` 표지로 확정한 헤더 5 개(`bsd/i386/signal.h`·`bsd/sys/errno.h`·`pc_support/PCmiscInline.h`·`PCprivate.h`·`PCpublic.h`)를 Darwin 원문 그대로 채택(빌드에 쓰인 스테이징 사본과 SHA 동일).
- 빌드 `s5p39-build-1`: 예측대로 O3 = 진단 SHA(`667a6de1…`·`024a7889…`), O3c 같음, O2 다름. OBJECT_MATCH 7/7·14/14, 경계 증명서 성립 → 둘 다 **A**.
- 기록: objects_confirmed 55 행(머리 포함), functions.tsv +21(401 함수), PROVENANCE +7(225 행; errno.h 는 UC 고지 병기), 증거 `x86-pc_support_fault_copy.md`. 수정 없음 → MODIFICATIONS 행 없음.

## 65. S5-P39 세부 계획 — `kern/processor.c` 를 Darwin 판 그대로 채택(36.1 common 절차) (코딩 전, 2026-10-02)

사실(원본 [0x161134, 0x161e5a) 3366 B, Ghidra 범위 27 개; 실행 ID `s5p40-*`, 탐침 cmd 머리에 예측):
- 탐침 1(Darwin `kern/processor.c` 그대로, 현재 07 헤더): `-fno-common` O3 = 진단 `s5p39-pre-1` 과 같은 SHA(`7e6688b3…`) — 27 함수 바이트·참조 차이 0, `__common` 732 B 후보 7 개로 모호(NOT_MATCH, 참조 24 미검증). common 변형 O3c(`8a5034b8…`) **OBJECT_MATCH 27/27**, `__data` 74 B 0x1df228(L1d). 두 `.i` 동일.
- 36.1: common 7 개 — `_all_psets` 8/간격 8, `_all_psets_count` 4/16, `_all_psets_lock` 4/8, `_default_pset` 380/380, `_master_processor` 4/4, `_processor_array` 328/336, `_processor_ptr` 4/4 (모두 크기 ≤ 원본 다음 심볼까지 간격, 상한 일관성). `__text` 재배치 55 곳 위치 동일, 폭·pcrel·유형 동일, 모양 차이는 scattered→extern 8·local→extern 16(56.1·63.1 과 같은 종류), 재배치 밖 바이트 차이 0; `__data` 재배치 없음, 바이트 동일.
- 경계: 앞 `00 00`(확정 priority 끝 0x161132), 뒤 `00 00`(`_enqueue_head` 0x161e5c) — 최소 채움.
- `.i` 표지 중 07 에 없는 것은 대상 파일뿐.

설계: `07_kernel/src/kern/processor.c` = Darwin 원문 그대로(수정 없음). PROVENANCE "none (verbatim)". 07 빌드(O3·O3c·O2·두 `.i`)로 탐침 1 과 같은 SHA 확인, objects_confirmed(A, 36.1)·functions.tsv 27 행·증거. 헤더 변경 없음 → 회귀 불필요. 예측: O3 `7e6688b3…`, O3c `8a5034b8…`, 미정의·common 심볼 = 탐침 1.

### 65.1 codex 교차검토(QP40) 판정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| 원문·스테이징 SHA 동일, 두 `.i` 동일, O3 = 진단 SHA | 탐침 1 출력(`cmp` 동일, SHA 접두 `7e6688b3` 두 곳) | ✅ |
| O3c OBJECT_MATCH 27/27·참조 55 검증·`__data` 74 B L1d; O3 는 참조 24 미검증 | l1batch 출력 | ✅ |
| 재배치 55 곳 위치·폭·pcrel·유형 동일, scattered→extern 8 + local→extern 16, 그 밖 15 곳은 외부 심볼 번호만 바뀜(이름·가산값 동일), 16 곳 완전 동일, 재배치 밖 바이트 동일 | 내 Python(55·55, 8·16, 밖 차이 0) — 번호만 바뀐 15 곳은 내 검사의 "변환 없음" 범주에 포함 | ✅ 증거에 명시 |
| common 7 개 크기 ≤ 간격(상한 일관성) | 65 절 Python 출력 | ✅ |
| 경계 `…5d c3 | 00 00` / `…5d c3 | 00 00 | 55 89 e5` | 65 절 Python 출력 | ✅ |
| 설정 `MACH_HOST=0`·`NCPUS=1`·`MACH_FIXPRI=1`(config_options.tsv 3·6·10 행)과 일치 | 그 세 행 열람 | ✅ |

### 65.2 결과 (2026-10-02) — `processor.c` 확정(A, 원문 그대로)

- 07_kernel `kern/processor.c` = Darwin 원문. 빌드 `s5p40-build-1`: 예측대로 O3 `7e6688b3…`·O3c `8a5034b8…`(O2 `1b836934…` 다름), 두 `.i` 동일. O3c OBJECT_MATCH 27/27, 36.1 충족, 경계 `00 00`/`00 00` → **A**.
- 기록: objects_confirmed +1, functions.tsv +27, PROVENANCE +1, 증거 `x86-processor.md`. 수정 없음.

## 66. S5-P40 세부 계획 — `machdep/i386/pc_support/PCresume.c` 를 Darwin 판 그대로 채택(등급 P) (코딩 전, 2026-10-02)

사실(원본 `__text` [0x1a15c4, 0x1a19c7) 1027 B, 함수 5: `_PCresume`·`_PCcallMonitor`·`_PCbopFA`·`_PCbopFC`·`_PCbopFD`; 실행 ID `s5p41-*`):
- 진단 `s5p39-pre-1`(Darwin 원문, 현재 07 헤더): `__text` 1027 B·재배치 9, **5/5 MATCH**, 객체 판정 NOT_MATCH 의 유일한 이유는 `__TEXT,__const` 4 B(`18 00 20 00`) 미배치.
- `__TEXT,__const`: 심볼 없음, 이 섹션을 가리키는 재배치 0 개(Python, 일반·scattered 모두) — intr(계획 46.x, `objects_partial.tsv` x86-intr 행)과 같은 ltr/lldt 선택자 상수로 보임(같은 바이트). 규칙상 "참조 없음(unreferenced)" → 등급 P 조건(README:24).
- 경계: 앞 `00` 1 B(이전 코드 `ret` 0x1a15c2, objects.tsv 의 PCexception 하한 0x1a1511 뒤에도 이름 없는 코드가 0x1a15c2 까지 있음), 뒤 `00` 1 B, 0x1a19c8 부터 이름 없는 함수 둘(56 B, `90 90` 로 구분) 뒤 `_PCscheduleTimers` 0x1a1a00 — 진단에서 Darwin `PCtimers.c` 빌드는 정적 `PCpendTimeout`·`PCpendTick` 가 앞 56 B 를 차지하므로 0x1a19c8 은 PCtimers 객체의 시작으로 보임(이번 판정에는 쓰지 않음). 앞뒤 모두 4 정렬 최소 채움.

설계: `07_kernel/src/machdep/i386/pc_support/PCresume.c` = Darwin 원문(수정 없음). `.i` 표지 중 07 에 없는 헤더도 원문 채택. 07 빌드(O3·O3c·O2·두 `.i`)로 진단과 같은 SHA 확인(예측: O3 = 진단 O3, `__const` 4 B 그대로). `objects_partial.tsv` 에 P 행(`unverified_sections`: `__TEXT,__const 4 B unreferenced`), functions.tsv 5 행(`high` — README:20 은 P 객체의 L1 MATCH 함수를 high 로 정의), PROVENANCE, 증거.

### 66.1 codex 교차검토(QP41) 판정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| 원문 SHA `8bdafe08…`, 진단 O3 `0c48d41a…`, L1 5/5 MATCH·1027 B·참조 9·차이 0, 유일한 미검증은 `__TEXT,__const` 4 B | 66 절 Python·진단 출력(O3 SHA 접두 `0c48d41a`) | ✅ |
| `__const` `18 00 20 00` 은 `cpu_inline.h` 의 `ltr()`·`lldt()` 메모리 피연산자(`TSS_SEL`·`LDT_SEL`, seg.h) — 재배치 0, 심볼 0; intr 과 같은 기제. 인용은 :126–142(`LDT_SEL` 은 :141) | `grep -n 'TSS_SEL\|LDT_SEL' cpu_inline.h` 출력 | ✅ 인용 정정 |
| 경계 `ret` 0x1a15c2·`00`·0x1a15c4 / `ret` 0x1a19c6·`00`·0x1a19c8, 최소 채움 1/1 | 66 절 Python 출력 | ✅ |
| 0x1a19c8–0x1a19ff 56 B 는 Darwin PCtimers 빌드의 첫 56 B(`_PCpendTimeout`·`_PCpendTick`)와 바이트 동일 — P 판정에는 불필요 | — | ⏭️ 기록만(PCtimers 차례에서 재확인) |
| P + 함수 `high` 는 README:20·24 와 일치, `__const` 는 미검증으로 남김 | README:20·24 | ✅ |

### 66.2 결과 (2026-10-02) — `PCresume.c` 등급 P(원문 그대로)

- 07_kernel: `PCresume.c` + `.i` 표지로 확인한 `machdep/i386/sel_inline.h` 원문 채택. 빌드 `s5p41-build-1`: 예측대로 세 변형 모두 `0c48d41a…`, 두 `.i` 동일, 5/5 MATCH, `__const` 4 B 미배치 → **P**.
- 기록: objects_partial +1(4 객체), functions.tsv +5(433 함수, high), PROVENANCE +2, 증거 `x86-PCresume.md`.

## 67. S5-P41 세부 계획 — 옵션 `MACH_KDB`·`NORMA_ETHER` 추가와 `kern/machine.c` 원문 채택 (코딩 전, 2026-10-02)

먼저 조사하고 보류한 것(실행 ID `s5p42-*`): `PCtimers.c` — 원본 `_PCscheduleTimers` 는 타이머 호출의 인자 형태·시간 변환이 Darwin 판과 다름(power.c 보류와 같은 callout API 문제). `mapfs.c` 는 BSD 헤더(`machine/limits.h`), `exception.c` 는 `ikm_sender` 로 막힘.

사실:
- 일괄 진단에서 machine·miniMonMachdep·exception 은 `mach_kdb.h`, machine 은 `norma_ether.h` 가 없어 실패. 둘 다 `06_reconstruction/config_options.tsv` 에 행이 없고 `07_kernel/generated` 에 헤더 없음.
- `MACH_KDB`: Darwin `conf/MASTER*` 에 옵션 자체가 없음(grep 0). 사용처는 `kern/exception.c:87–92`(`thread_kdb_return`·`db_printf` 선언, `boolean_t debug_user_with_kdb`) 과 `:300–311` 뿐, `bsd/sys/reboot.h:65` 는 include 만. 원본 심볼표에 `_debug_user_with_kdb`·`_thread_kdb_return`·`_db_printf` 없음(grep 0 — 1 이었다면 전역 `_debug_user_with_kdb` 가 있어야 함). → 값 0, **hypothesis**(바이트 확인은 exception.c 차례).
- `NORMA_ETHER`: `conf/MASTER:139` `<norma_ether>`, RELEASE 태그(`MASTER.i386:72`)에 없음. 사용처는 `kern/machine.c:58` include 뿐(값을 쓰는 곳 없음). → 값 0, **hypothesis**(바이트에 영향 없음).
- 탐침 3(스테이징만: 두 헤더를 generated 에 두고 meta_features 에 import): Darwin `kern/machine.c` 원문 — O3(`-fno-common`) = O2 = 탐침 1 SHA `39a4e686…`, 바이트·참조 차이 0, `__common` 64 B 모호(+ 크기 0 `__data` 추정 배치로 `cpu_up`·`cpu_down` 이 DIFF 표시, 바이트 차이 0); common 변형 O3c `67e04b32…` **OBJECT_MATCH 6/6**(`__text` 380 B, 재배치 17), 두 `.i` 동일.
- 36.1: common `_action_lock` 4/4, `_action_queue` 8/8, `_machine_info` 20/20, `_machine_slot` 32/32(크기/간격); 재배치 17 곳 위치·폭·pcrel·유형 동일, scattered→extern 4·local→extern 2, 재배치 밖 바이트 차이 0.
- 경계: 앞 0 B(`ret` 0x15de67), 뒤 0 B(`_mfs_init` 0x15dfe4) — 원본 [0x15de68, 0x15dfe4) 380 B.

설계:
1. `config_options.tsv` 에 `mach_kdb`·`norma_ether` 두 행(값 0, hypothesis, evidence 열에 위 근거), `gen_config_headers.py` 로 생성·`--check`.
2. 회귀: `meta_features.h` 가 바뀌므로 확정 55 + 부분 4 = 59 객체를 마지막 확정 빌드 명령으로 다시 빌드해 SHA 전부 동일 확인(기준: `s5p33-regress-1` 50 개 + 이후 확정 9 개의 최종 빌드 출력).
3. `07_kernel/src/kern/machine.c` = Darwin 원문. 07 빌드(O3·O3c·O2·두 `.i`) — 예측: 탐침 3 과 같은 SHA. objects_confirmed(A, 36.1)·functions.tsv 6 행·PROVENANCE·증거.

### 67.1 codex 교차검토(QP42) 판정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| `MACH_KDB` 0 은 가설로 타당: MASTER 에 없음, 원본 심볼 3 개·문자열 `"No exception server, calling kdb"` 없음; 옵션 등록은 `conf/files:50` | 67 절 grep(심볼 0·0·0), strings.tsv grep 0 줄 | ✅ (문자열 부재도 근거에 추가) |
| `NORMA_ETHER` 0 은 설정 가설일 뿐, 쓰이지 않는 값이라 이 객체로 확정 불가 | 67 절 grep(include 1 줄) | ✅ hypothesis 유지 |
| O3 의 `_cpu_up`·`_cpu_down` DIFF 는 도구 인공물: 크기 0 `__data` 를 `sect_of` 가 1 바이트로 취급(`l1_compare.py:68` `max(s['size'], 1)`) → scattered `_machine_info` 참조를 잘못 분류; O3 는 여전히 참조 4 미검증 | l1_compare.py:66–70 열람 | ✅ 기록(도구 수정은 이번 범위 밖, 판정은 O3c + 36.1) |
| 36.1: 재배치 17 = extern→extern 11 + scattered→extern 4 + local→extern 2, 이름·가산값 대응, 밖 바이트 동일, common 4/4·8/8·20/20·32/32 | 67 절 Python 출력 | ✅ |
| 경계 0/0, 380 B | 67 절 출력 | ✅ |
| 회귀: `s5p33-regress.cmd` 가 이전 50 개를 정확히 포함, 이후 9 개 기준 출력(표) | 기준 파일 존재·SHA 접두가 각 회차 기록과 같음 | ✅ 기준으로 사용 |
| **누락 채택: `bsd/sys/reboot.h`·`bsd/machine/reboot.h`·`bsd/i386/reboot.h`(machine.i 에서 사용)** | 탐침 3 `machine.i` 표지 대조(Python): 07 에 없는 것 = 두 generated + 이 세 헤더 + machine.c | ✅ 설계 3 에 추가 |
| 탐침의 import 는 끝에 덧붙였고 생성기는 정렬 — 최종 생성 헤더로 재현 필요 | gen_config_headers.py:35 `sorted(files)` | ✅ 07 빌드로 확인 |

### 67.2 결과 (2026-10-02) — 옵션 2 개 추가, `machine.c` 확정(A, 원문 그대로)

- `config_options.tsv` 19→21 행(`mach_kdb`·`norma_ether`, hypothesis 0), 생성 헤더·`--check` 통과. 회귀 `s5p42-regress-1` 59/59 동일.
- 07_kernel `kern/machine.c` + `bsd/{sys,machine,i386}/reboot.h` 원문. 빌드 `s5p42-build-1`: 예측대로 O3 = O2 = `39a4e686…`, O3c `67e04b32…`, 두 `.i` 동일, `.i` 표지 모두 07 에 있음. O3c OBJECT_MATCH 6/6, 36.1 충족, 경계 0/0 → **A**.
- 기록 처리 중 `processor_assign` 정의가 세 개(MACH_HOST·#else·#else NCPUS>1)라 스크립트가 쓰기 전에 멈춤 → 활성 정의 :723 명시 후 기록. objects_confirmed +1, functions.tsv +6, PROVENANCE +6(생성 헤더 2 포함), 증거 `x86-machine.md`.
- 도구 메모: `l1_compare.py:68` 의 크기 0 섹션 처리(`max(size,1)`)가 빈 `__data` 를 1 바이트로 취급 — 판정에 영향 없으나 나중에 도구 수정 후보.

## 68. S5-P42 세부 계획 — `machdep/i386/miniMonMachdep.c` 를 Darwin 판 그대로 채택(등급 P) (코딩 전, 2026-10-02)

사실(실행 ID `s5p43-*`; 일괄 진단 `s5p43-pre-1`, Darwin 7 파일 그대로):
- miniMon·kdp_udp·kdp_machdep·unix_signal·unix_startup·pcb 는 BSD 헤더(`machine/limits.h`, unix_startup 은 `kernserv/ns_timer.h` 경유)로 실패 — S4-C 결정 대기. **miniMonMachdep 성공**(이제 `mach_kdb.h` 가 있으므로).
- miniMonMachdep: `__text` 728 B·재배치 24 **바이트·참조 차이 0**. objects.tsv 범위(0x185fb0, 154 B)는 하한일 뿐 — Darwin 에서 `static` 인 `miniMonDump`(:100)가 앞 [0x185e04, 0x185fb0) 428 B, `miniMonBacktrace`(:43)가 끝 [0x18604c, 0x1860dc) 144 B 를 차지하고(68.1 정정) 원본 이미지 [0x185e04, 0x1860dc) 와 바이트 일치(정적 심볼은 원본 심볼표에 없음 — 일관). `__data` 129 B(`_miniMonMDCommands`, 재배치 6) 심볼 배치·L1d 일치. 객체 판정 NOT_MATCH 의 유일한 이유는 `__DATA,__bss` 4 B(함수 정적 `ptr`, `miniMonDump` 안 :103) — `zerofill_check.py`: 참조 5, Δ 하나, 후보 [0x1e75a0, 0x1e75a4) 정렬·zero-fill 섹션 안·심볼 없음·겹침 없음, 음성 검사 검출 → **reference-inferred**(`09_validation/reconstruction/s5p43-zerofill-check-miniMonMachdep-pre-20261002.json`). common 없음.
- 경계: 앞 `00` 1 B(`ret` 0x185e02, 앞은 kdp 계열 함수), 뒤 0 B(`_start` 0x1860dc).

설계: `07_kernel/src/machdep/i386/miniMonMachdep.c` = Darwin 원문. `.i` 표지로 07 에 없는 헤더 원문 채택. 07 빌드(O3·O3c·O2·두 `.i`) — 예측: O3 = 진단 SHA, common 없음 → O3c 도 같은 바이트. 등급 **P**(`unverified_sections`: `__DATA,__bss 4 B reference-inferred at 0x1e75a0`, README:24), functions.tsv: `miniMonDump` 은 `__bss` 의존으로 MATCH_UNVERIFIED → **medium**(README:21), 나머지 7 은 **high**. 최종 빌드 객체로 zerofill_check 를 다시 돌려 기록.

### 68.1 codex 교차검토(QP43) 판정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| 원문·진단 입력 SHA 동일, 진단 O3 `51b24681…` | 진단 출력 SHA 접두 | ✅ |
| L1: 7 MATCH + `miniMonDump` MATCH_UNVERIFIED(`__bss` 만), `__text` 728 B·참조 24, `__data` 129 B·참조 6(0x1e1728) 차이 0 | 68 절 L1 출력 | ✅ |
| 배치는 공개 심볼 6 개가 같은 Δ 를 주는 "심볼 배치" — 0x185e04 에 원본 심볼은 없음 | `_miniMonReboot` 0x185fb0 − 0x1ac = 0x185e04(Python) | ✅ |
| **`miniMonBacktrace` 는 앞이 아니라 끝 [0x18604c, 0x1860dc) 144 B** | 빌드 심볼 `_miniMonBacktrace` 0x248 → 0x185e04+0x248 = 0x18604c, 728−584 = 144(Python) | ✅ **내 오류** — 68 절 정정 |
| 경계 `ret` 0x185e02·`00`·…·`ret` 0x1860db·`_start` 0x1860dc | 68 절 Python 출력 | ✅ |
| zero-fill: 참조 5, Δ 0x1e7244, 후보 [0x1e75a0, 0x1e75a4), 음성 검사 검출, 대상은 `static ptr`(:103) | zerofill JSON 출력, 빌드 심볼 `_ptr.102` | ✅ |
| **`--known` 이 낡음**(kern_notify [0x1e726c, 0x1e7280) 등 누락) — 겹침은 없음 | s5p25 known 11 구간에 kern_notify 없음(Python) | ✅ `zerofill-known-s5p43-20261002.json`(12 구간)으로 최종 재실행 |
| P·`miniMonDump` medium·나머지 high | README:20–24 | ✅ |

### 68.2 결과 (2026-10-02) — `miniMonMachdep.c` 등급 P(원문 그대로)

- 07_kernel: `miniMonMachdep.c` + `kern/miniMonPrivate.h` 원문. 빌드 `s5p43-build-1`: 예측대로 O3 = O3c = `51b24681…`(O2 다름), 두 `.i` 동일. 7 MATCH + `miniMonDump` MATCH_UNVERIFIED(`__bss`), 갱신한 known 으로 zerofill reference-inferred → **P**.
- 기록: objects_partial +1(5 객체), functions.tsv +8(high 7, medium 1), PROVENANCE +2, known-range 파일 `zerofill-known-s5p43-20261002.json`, 증거 `x86-miniMonMachdep.md`.

## 69. S5-P43 세부 계획 — `pc_support/PCemulateREAL.c`·`PCemulatePROT.c` 를 Darwin 판 그대로 채택 (코딩 전, 2026-10-02)

선정: 40 절 규칙(`machine/limits.h` 에 닿는 파일은 S4-C 결정 전까지 진행 안 함) 아래에서 조사 자료 `s4c-survey-20261001.json` 의 Mach 쪽 미확정·미시도 후보를 다시 뽑아 일괄 진단 `s5p44-pre-1`(Darwin 원문 7 개, 실행 ID `s5p44-*`).
- 결과: 7 개 모두 컴파일. PCexception(바이트 358 차이·참조 17 차이, 보류), vm_fault·vm_map·pmap(배치 실패 — 크기 다름), **dma**(`__text` 5889 B 바이트 차이 0, `__bss` 12 B·`__common` 28 B 미검증 — 다음 회차 후보), **PCemulateREAL·PCemulatePROT OBJECT_MATCH**.
- PCemulateREAL: `__text` [0x1a1b60, 0x1a2b3e) 4062 B, 함수 12(정적 포함, Ghidra 범위 10), `__data` 1024 B 0x1e4b80(추정 배치, L1d 일치). 앞 `00`×3(`ret` 0x1a1b5c, PCtimers 쪽), 뒤 `00 00`.
- PCemulatePROT: `__text` [0x1a2b40, 0x1a3d0a) 4554 B, 함수 5(정적 `handle_bop`·`push_frame16_err_code`·`emulate_exception`·`emulate_instruction` 이 앞, 공개 `_PCemulatePROT` 0x1a3ac4), 데이터 없음. 앞 = REAL 의 뒤 `00 00`, 뒤 `00 00`(`_IOGetObjectForDeviceName` 0x1a3d0c). 네 틈 모두 4 정렬 최소 채움.
- 두 파일에 같은 이름의 정적 `handle_bop` 이 있음(파일마다 static — 충돌 없음).

설계: 두 파일을 Darwin 원문 그대로 07 에 복사, `.i` 표지로 07 에 없는 헤더 원문 채택. 07 빌드(각 O3·O3c·O2·두 `.i`) — 예측: O3 = 진단 SHA(`s5p44-pre-1`). common 없음 → 36.1 불필요. objects_confirmed 2 행(A), functions.tsv 17 행(high; 정적 함수는 원본 심볼 없음 명기), PROVENANCE, 증거.

### 69.1 codex 교차검토(QP44) 판정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| 두 소스는 Darwin 원문(SHA 동일) | 진단 스테이징은 `--prefer-07` 이고 07 에 두 파일 없음 | ✅ (07 빌드 SHA 로 재확인) |
| REAL 12/12·4062 B·참조 31, PROT 5/5·4554 B·참조 33 OBJECT_MATCH | 69 절 L1 출력 | ✅ |
| **REAL `__data` 1024 B(정적 `inst_table`, :771) 배치는 들어오는 참조 1 개(0xaf3)로 추정**, 나가는 함수 포인터 6 개 포함 1024 B 전체 L1d 일치 | Python: incoming 1(`__text` 0xaf3), `__data` 재배치 6 | ✅ 기존 L1 추정 배치 규칙(263 행: 모든 참조 같은 Δ + 섹션 전체 L1d 일치) 충족. 단일 참조임을 증거에 기록 |
| 경계 바이트, PROT 시작 0x1a2b40 = 0x1a3ac4 − 0xf84, 정적 함수 4 개는 원본 심볼 없음 | 69 절 Python 출력 | ✅ |
| `machine/limits.h` 의존 없음; 예상 미채택 헤더 `machdep/i386/err_inline.h`·`pc_support/PCtaskInline.h` | (07 빌드 `.i` 로 확정) | ⚖️ `.i` 로 확정한 것만 채택 |
| 표제 S5-P43 → P44 | 관례(실행 ID 와 절 번호 별개) | ⚖️ 유지 |

### 69.2 결과 (2026-10-02) — `PCemulateREAL.c`·`PCemulatePROT.c` 확정(A, 원문 그대로)

- 07_kernel: 두 소스 + `.i` 로 확정한 `machdep/i386/err_inline.h`·`pc_support/PCtaskInline.h` 원문. 빌드 `s5p44-build-1`: 예측대로 O3 = O3c = 진단 SHA, 두 `.i` 동일, OBJECT_MATCH 12/12·5/5, 경계 최소 채움 → 둘 다 **A**.
- 기록 처리: 함수 정의 찾기가 여러 줄 원형 선언(:348)을 정의로 잘못 잡아 표 기록 전에 멈춤 → 괄호 뒤 `;` 여부로 원형을 거르도록 고쳐 기록(PROVENANCE 4 행은 그 전에 기록됨). objects_confirmed +2, functions.tsv +17(정적 15 은 원본 심볼 없음 명기), PROVENANCE +4, 증거 `x86-PCemulate.md`.

## 70. S5-P44 세부 계획 — `machdep/i386/dma.c` 를 Darwin 판 그대로 채택(등급 P) (코딩 전, 2026-10-02)

사실(원본 `__text` [0x188044, 0x189745) 5889 B, 함수 22; 실행 ID `s5p45-*`, 탐침은 스테이징만, cmd 머리에 예측):
- 탐침 1(Darwin 원문): `-fno-common` O3 = 진단 `s5p44-pre-1` SHA `2e601aad…` — 바이트·참조 차이 0, 참조 129 미검증(`__common` 28 B 후보 4·`__bss`). common 변형 O3c `412a0bde…`: 7 MATCH + 15 MATCH_UNVERIFIED, **유일한 미검증은 `__DATA,__bss` 12 B**(함수 정적 `xxx` 3 개, 오프셋 0x1770·0x1774·0x1778). `__data` 108 B 0x1e1842 심볼 배치·L1d 일치. 두 `.i` 동일.
- `__bss`: `zerofill_check.py`(known 범위 파일 `zerofill-known-s5p45-20261002.json` = s5p43 + miniMonMachdep [0x1e75a0, 0x1e75a4)) — 참조 67, Δ 0x1e5e7c 하나, 후보 [0x1e75ec, 0x1e75f8) 정렬·zero-fill 안·심볼 없음·겹침 없음, 음성 검사 검출 → **reference-inferred**(`09_validation/reconstruction/s5p45-zerofill-check-dma-pre-20261002.json`).
- 36.1: common 5 개 `_dma_assigned_bits` 4/4, `_dma_cmd_regs` 4/16, `_dma_write_regs` 16/16, `_prev_tcstatus0` 4/4, `_prev_tcstatus1` 4/12(크기/간격); `__text` 재배치 425 곳 위치 동일, 폭·pcrel·유형 동일(같은 종류 296, local→extern 123, scattered→extern 6), 재배치 밖 바이트 차이 0; `__data` 재배치 없음·바이트 동일.
- 경계: 앞 0 B(`_isbad` 쪽 `ret` 0x188043), 뒤 `00`×3(`_dma_buf_initialize` 0x189748 — 확정 dma_buf 객체 시작).

설계: `07_kernel/src/machdep/i386/dma.c` = Darwin 원문(수정 없음), `.i` 표지로 07 에 없는 헤더 원문 채택. 07 빌드(O3·O3c·O2·두 `.i`) 예측: 탐침 1 과 같은 SHA. 최종 객체로 zerofill_check 재실행. 등급 **P**(`unverified_sections`: `__DATA,__bss 12 B reference-inferred at 0x1e75ec`), common 은 36.1 로 검증. functions.tsv 22 행: O3c 에서 MATCH 인 7 개 high, `__bss` 의존 MATCH_UNVERIFIED 15 개 medium(README:20–21).

### 70.1 codex 교차검토(QP45) 판정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| 원문·`.i` 동일, O3 = 진단, O3c `412a0bde…` | 70 절 탐침 출력 | ✅ |
| O3c 7 MATCH + 15 MATCH_UNVERIFIED(`__bss` 만), `__data` 108 B 0x1e1842 | l1batch 출력 | ✅ |
| zero-fill: 참조 67·Δ 하나·음성 검사 검출. **참조는 모두 오프셋 0** — 셋 중 첫 `xxx` 만 직접 배치되고 나머지 8 B 는 섹션 연속성으로 추정 | 기록의 `field_target_offsets` = [0] | ✅ 증거에 한계 명시 |
| `xxx` 는 dma.c 가 아니라 `io_inline.h:108·128·148` 의 `outb`·`outw`·`outl` 안 정적 변수(`lock; incl` 더미 피연산자) | dma.i 14435 행 등, io_inline.h grep | ✅ |
| known 범위는 이 후보 주변에 충분(원본 `__common` 은 0x1e8750 부터라 무관) | known 13 구간 | ✅ |
| 36.1 수치(4/4·4/16·16/16·4/4·4/12, 425 = 296 + 123 + 6, 밖 차이 0)·경계 | 70 절 Python 출력 | ✅ |
| **문구: 36.1 의 OBJECT_MATCH 조건은 이 객체에서 문자 그대로 성립하지 않음**(O3c 에 `__bss` 남음) — common 참조 검증이 옮겨지고 남은 `__bss` 는 46 절 P 규칙으로 | 36.1(:1269) 열람 | ✅ 기록 문구를 "common 참조는 변형에서 검증, `__bss` 는 reference-inferred" 로 |
| P + high 7 / medium 15 | README:20–24 | ✅ |

### 70.2 결과 (2026-10-02) — `dma.c` 등급 P(원문 그대로)

- 07_kernel: `dma.c` + `.i` 로 확정한 `bsd/i386/param.h`·`machdep/i386/dma.h`·`dma_inline.h`·`dma_internal.h` 원문. 빌드 `s5p45-build-1`: 예측대로 O3 `2e601aad…`, O3c `412a0bde…`, 두 `.i` 동일. 최종 객체 zerofill reference-inferred → **P**.
- 기록: objects_partial +1(6 객체), functions.tsv +22(high 7, medium 15), PROVENANCE +5, 증거 `x86-dma.md`.

## 71. S5-P45 세부 계획 — `l1_compare.py` 의 크기 0 섹션 처리 수정 (코딩 전, 2026-10-02)

먼저 조사하고 보류한 것(실행 없음, 원본 역어셈블만): `pc_support/PCexception.c` — 원본 `_PCexception`(369 B, 빌드 348 B)은 `vm_fault` 호출 앞뒤로 이름 없는 전역 0x1e875c 가 가리키는 구조체의 바이트 필드 +0x68 을 저장·0 으로·복원([0x1a1400, 0x1a144e)). 같은 전역·필드를 원본 `_suser`([0x10833c, 0x108345))도 씀 → BSD 쪽 구조체(S4-C) 결정 없이는 이름을 정할 수 없음. 보류.

문제(67.1 에서 기록): `l1_compare.py:66–70` `sect_of` 가 `s['addr'] <= addr < s['addr'] + max(s['size'], 1)` 로 크기 0 섹션을 1 바이트로 취급 → 크기 0 섹션이 다음 섹션과 같은 주소를 가지면(machine.o: 크기 0 `__data` 와 `__common` 이 둘 다 0x17c 에서 시작) scattered 참조가 빈 섹션으로 잘못 분류되어 그 섹션이 추정 배치되고 파일 기반 검사가 `fail` → 함수가 DIFF 로 표시됨(판정에 쓴 O3c 에는 영향 없었음). `zerofill_check.py:40–45` 의 `sect_of` 는 이미 `s['size'] and …` 로 크기 0 섹션을 건너뜀.

설계:
1. `l1_compare.py` `sect_of` 를 `if s['size'] and s['addr'] <= addr < s['addr'] + s['size']` 로(크기 > 0 섹션의 동작은 같음). 주석에 이유.
2. 시험: (a) 기존 자체 시험 `test_l1_compare.py 08_build/runs/s1b-t1-kernel-4/out` 14/14 그대로(수정 전 기준 14/14 확인함); (b) **차등 회귀** — `09_validation/reconstruction/*-l1-*.json` 의 `object` 경로로 아직 존재하는 모든 목적 파일에 대해, 같은 입력(`placements_from_image`, ranges 없음)으로 수정 전·후 `compare()` 결과 전체를 비교. 예측: 차이는 크기 0 섹션이 다른 섹션과 주소를 공유하는 객체에서만, machine O3(`s5p42-build-1`)은 `_cpu_up`·`_cpu_down` 이 DIFF → MATCH_UNVERIFIED 로 바뀌고 객체 판정은 NOT_MATCH 유지(`__common` 모호); 확정·부분 객체의 판정 근거(O3c 등)는 바뀌지 않음. 하나라도 예측 밖이면 되돌리고 조사.
3. 기록: 도구 수정 이력(계획·증거), 자체 시험 결과 `09_validation/reconstruction/l1-selftest-20261002.json`, 차등 결과 `09_validation/reconstruction/l1-sectof-diff-20261002.json`.

### 71.1 codex 교차검토(QP46) 판정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| 크기 > 0 섹션의 소속 조건은 같지만, 앞의 빈 섹션에 가려졌던 조회 결과는 바뀌고, 맨 끝 빈 섹션은 index → `None`; 호출부(:130 literal → `differs`, :182·:193 → 미검증, :222 → 건너뜀)는 `None` 을 처리 | l1_compare.py 120–135·178–200·216–230 열람(`if A is None …` 분기 존재) | ✅ "차이는 주소를 공유할 때만" 문구를 "빈 섹션이 조회에 걸리는 경우에만(공유 주소 또는 맨 끝)" 으로 고침 |
| 전체 자료(301 객체)에 빈 섹션 심볼·빈 섹션 대상 local 재배치·`None` 이 되는 scattered 대상 0 | 내 드라이런 차등: 301 중 차이 5, 오류 0 | ✅ |
| `max(size,1)` 도입 이유 기록 없음(파일 미추적) | — | ⏭️ 기록만 |
| machine.o: 빈 것은 `__data` 뿐(0x17c, 크기 0), `__common` 은 0x17c·0x40 | 67 절 섹션 목록 출력(`('__data', 0, 0)`, `('__common', 64, 0)`) | ✅ 문구 정정 |
| 차등 301/5 재현(dbl_fault 진단 O2·O3·O4, machine O3 두 개), 모두 NOT_MATCH 유지; machine 미검증 참조 4 → 6 | 내 드라이런 출력 | ✅ |
| `by_symbol=set(placements)` 를 넘길 것 | 내 스크립트 `bs=set(pl)` | ✅ 이미 그렇게 함 |
| 빈 섹션 앞·끝 경우의 집중 시험 추가 | — | ✅ 합성 시험 `test_sect_of.py`(sect_of 단위: 빈 섹션 앞 공유 주소, 맨 끝 빈 섹션, 일반 경계) — 재배치 종류별 종단 시험은 이번 범위 밖으로 기록 |
| PCexception 범위는 반열림 끝 0x1a144e, `_suser` 는 0x108345 | capstone 출력(0x1a144b 3 B 명령, 0x108341 4 B 명령) | ✅ 정정 |

### 71.2 결과 (2026-10-02) — `sect_of` 수정 완료

- `10_tools/reconstruction/l1_compare.py` `sect_of`: 크기 0 섹션은 어떤 주소도 소유하지 않음(`if s['size'] and …`, 주석에 이유). 
- 시험: 단위 `test_sect_of.py` 7/7(빈 섹션 앞 공유 주소·맨 끝 빈 섹션·일반 경계), 자체 시험 `test_l1_compare.py` 14/14(`09_validation/reconstruction/l1-selftest-20261002.json`).
- 차등 회귀 `check_sectof_diff.py`(옛 조건식 대 수정 도구, 같은 입력): 301 객체 중 차이 5 — `s5p18-pre-1` dbl_fault O2·O3·O4 의 `_dbf_init`, `s5p42-build-1`·`s5p42-probe-3` machine O3 의 `_cpu_up`·`_cpu_down` 이 DIFF → MATCH_UNVERIFIED, 객체 판정은 모두 NOT_MATCH 유지(`09_validation/reconstruction/l1-sectof-diff-20261002.json`). 예측과 같음. 확정·부분 객체의 판정 근거(dbl_fault·machine 은 common 변형의 OBJECT_MATCH)는 바뀌지 않음 → 표 수정 없음.
- 남은 한계: 재배치 종류별(VANILLA·SECTDIFF/PAIR·literal) 종단 합성 시험은 만들지 않았음(자료 전체에 해당 사례 0 — 71.1).

## 72. S5-P46 세부 계획 — 기록 정합성 점검, `07_kernel/README.md` 정정, 64 객체 최종 회귀 (코딩 전, 2026-10-02)

점검(Python, 읽기만):
- 07_kernel 파일 257 개 중 PROVENANCE 행이 없는 것은 `07_kernel/README.md` 뿐(프로젝트 문서; LICENSES·PROVENANCE·MODIFICATIONS 제외). PROVENANCE 244 행에 중복 대상·없는 파일 없음, "verbatim" 행의 SHA 가 실제 파일·Darwin 원문과 모두 같음.
- "수정" PROVENANCE 행 중 MODIFICATIONS 에 없는 것으로 보인 `memmove.c` 는 MODIFICATIONS:18 의 memcpy.c·memmove.c 공동 행 — 점검 정규식이 첫 경로만 읽은 오탐.
- 표 열 수: objects_confirmed 59 행·objects_partial 7 행·functions.tsv 487 행·config_options 21 행·PROVENANCE 245 행 모두 일정. 확정·부분 객체의 증거 파일 모두 존재, functions.tsv 의 VA 중복·없는 구현 경로 없음.
- **`07_kernel/README.md:3` "아직 채택된 커널 구현은 없다" 는 사실과 다름**(확정 58·부분 6 객체가 채택됨).

설계:
1. `07_kernel/README.md:3` 을 현재 상태로 고침: 채택 기준(06_reconstruction 의 등급표)과 기록 위치(PROVENANCE·MODIFICATIONS)를 가리키는 문장. 숫자는 쓰지 않음(표가 기준).
2. 최종 회귀: 현재 07_kernel 트리로 확정 58 + 부분 6 = 64 객체의 기준 명령(`s5p42-regress.cmd` 59 개 + machine `s5p42-build-1`·miniMonMachdep `s5p43-build-1`·PCemulateREAL/PROT `s5p44-build-1`·dma `s5p45-build-1` 의 O3)을 다시 빌드, 모든 SHA 가 기준과 같아야 함. 예측: 64/64 동일.
3. 결과를 72.2 와 회귀 기준 파일에 기록.
4. (보강) README 6–8 행의 예약 디렉터리(`src/common` 등)는 `.gitkeep` 만 있는 빈 구조로 실제로 존재함. 실제 채택 파일은 Darwin 경로를 유지한 `src/<Darwin kernel 경로>`·`components/architecture/…`·`generated/`(생성 헤더) 에 있다는 한 문장을 추가(8 행 "원래 파일 경로를 최대한 유지" 의 실제 적용).

### 72.1 codex 교차검토(QP47) 판정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| **`07_kernel/generated/README` 에 PROVENANCE 행 없음** — 내 점검은 이름이 `README` 로 끝나는 파일을 제외해 놓침 | 점검 스크립트의 제외 조건 `f.endswith('README')` 확인 | ✅ **내 점검 오류.** 두 README 는 프로젝트 문서(제3자 코드 아님)이므로 PROVENANCE 대상에서 제외하는 규칙을 `07_kernel/README.md` 에 명시 |
| verbatim SHA 27 건·verbatim 파일 195(Darwin 194, Mach4 1)·수정/작성 33 행 모두 MODIFICATIONS 와 대응, 라이선스 파일·구현 경로·증거 경로 모두 존재 | 내 점검 출력(불일치 0, memmove 는 18 행 공동 행) | ✅ |
| 열 수 59×11·7×12·487×15·21×6·245×7 | 내 점검 출력 | ✅ |
| README:3 낡음, 예약 디렉터리 6 개는 `.gitkeep` 만 | 72 절 `ls -a` 출력 | ✅ |
| 64 객체 ↔ 기준 64 출력 정확히 대응, 명령은 O3 46·O2 1·O4 6·O4+unroll 11 그대로 유지 | 내 대응표 Python(누락·중복·여분 0, 비 O3 기준 18 = O2 1 + O4 6 + U 11) | ✅ |

### 72.2 결과 (2026-10-02) — 정합성 점검 완료, README 정정, 64 객체 최종 회귀 64/64

- `07_kernel/README.md`: 낡은 "채택된 구현 없음" 문장을 등급표·함수표를 가리키는 문장으로 바꾸고, 실제 배치(`src/`·`components/architecture/`·`generated/`, 예약 디렉터리는 비어 있음)와 PROVENANCE 대상 제외 규칙(프로젝트 문서 `README.md`·`generated/README`, `PROVENANCE.tsv`·`MODIFICATIONS.md`·`LICENSES/`)을 적음(15 → 19 줄).
- 최종 회귀 `s5p46-regress-1`: 현재 07_kernel 트리로 확정 58 + 부분 6 = 64 객체를 각자의 확정 명령(O3 46·O2 1·O4 6·O4+unroll 11)으로 다시 빌드 — 빌드 입력 소스 64 개 모두 07_kernel 에서, **64/64 SHA 가 기준과 동일**(`08_build/runs/tools/s5p46-regress-baseline.json`).
- 점검 결과 그 밖의 불일치 없음(72 절·72.1).

## 73. S5-P47 세부 계획 — D018(S4-C 안 B) 1 단계: 실기 헤더 확인·기록과 스테이징 루트 추가(선택 플래그) (코딩 전, 2026-10-02)

사실(실기는 읽기만, gcds; 계산 Python):
- 실기 `/NextDeveloper/Headers` 일반 파일 704 개의 SHA-256(실기 krsha256, `08_build/runs/tools/s4c-target-headers-sha.txt`) 대 로컬 사본 `01_resources/local_mirrors/headers/NextDeveloper/Headers`(→ `../ref/openstep/headers`): 699 동일, 5 다름(전부 미리 컴파일된 `.p`: `bsd/libc.p`·`ansi/ansi.p`·`mach/mach.p`·`mach/cthreads.p`·`objc/Object.p`), 실기에만 0, 사본에만 3(AppKit). 심볼릭 링크 2 개(`X11`, `objc/hashtable.h`) 동일. 커널 관련 bsd 335 중 334·ansi 53 중 52·architecture 37/37·mach 98 중 96·kernserv 33/33 동일(다른 것은 `.p` 뿐).
- 실기 `cc`(cc-744.13, gcc 2.7.2.1) 기본 `<…>` 검색: `System.framework/PrivateHeaders`(없음), `System.framework/Headers`, `…/Headers/ansi`, `…/Headers/bsd`, `/NextDeveloper/Headers`, `/NextDeveloper/Headers/ansi`, `/NextDeveloper/Headers/bsd`, `/LocalDeveloper/Headers`, `/usr/include`. `System.framework/Versions/A/Headers` 는 `/NextDeveloper/Headers` 의 ansi·architecture·bsd·mach·mach-o·machkit·objc·remote·streams 를 가리키는 링크 모음. `<machine/limits.h>` → `ansi/machine/limits.h` → `architecture/ARCH_INCLUDE.h` → `ansi/i386/limits.h`.
- Darwin `conf/Makefile.template:86–92`: 소스 루트 뒤에 `System.framework/{PrivateHeaders,Headers,Headers/bsd}` — `-nostdinc` 없이 쓰므로 cc 기본 목록(위)이 뒤에 붙음 → 실효 순서 소스 루트 → `Headers` → `Headers/bsd` → `Headers/ansi`.
- Darwin `architecture/`(architecture-1 tar, 지금 `components/architecture` 루트)와 NeXT `Headers/architecture` 는 공통 20 개가 모두 바이트가 다름; Darwin 에만 `i386/ansi.h`·`i386/limits.h` 등, NeXT 에만 `ARCH_INCLUDE.h` 등. 확정 객체 빌드는 Darwin 판(`byte_order.h`·`i386/{ansi,byte_order,cpu,desc,fpu,frame,io,sel,table,tss}.h`)을 쓰며 바이트로 검증됨.

설계:
1. 기록: `09_validation/reconstruction/s4c-nextdev-headers-20261002.json` — 실기 704 파일 SHA·사본 대조 결과·검색 경로 사실(위). 사본은 "불변 스냅샷 아님"(SOURCES.md:39–41)이므로 이 JSON 이 이후 채택의 고정 기준.
2. `stage_headers.py` 에 선택 플래그 `--nextdev`: 기존 루트 **뒤에** `<사본>/Headers`, `Headers/bsd`, `Headers/ansi` 를 이 순서로 추가(논리 경로 `nextdev/…`, `--prefer-07` 이면 `07_kernel/nextdev/…` 먼저). Darwin 루트가 앞이므로 Darwin 에 있는 이름은 그대로 Darwin 판 — D018 의 "Darwin 소스 트리에 없는 시스템 헤더" 와 일치. 플래그 없으면 동작 그대로. 빌드 명령에는 `-Isrc/nextdev -Isrc/nextdev/bsd -Isrc/nextdev/ansi` 를 기존 `-I` 목록 끝에 추가(이번 회차는 스테이징 탐침에서만).
3. 검증: (a) 플래그 없는 스테이징 결과가 수정 전과 manifest 동일(확정 소스 하나 이상으로); (b) `--nextdev` 로 40 절에서 막힌 `vm/vm_synchronize.c` 를 스테이징·진단 빌드(탐침, 07 변경 없음) — 컴파일 여부와 `.i` 에서 nextdev 쪽에서 온 헤더 목록 기록. 예측: `machine/limits.h` 는 `nextdev/ansi/machine/limits.h` → `nextdev/architecture/ARCH_INCLUDE.h`·`nextdev/ansi/i386/limits.h` 로 해결; 다른 새 미해결이 나올 수 있음.

### 73.1 codex 교차검토(QR1) 판정 → 설계 수정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| 사본 대조 699/5/0/3(SHA·크기), 디렉터리별 표, 다른 5 개는 `.p` | 73 절 Python 출력과 같음 | ✅ |
| 실기 쪽 심볼릭 링크 동일성은 일반 파일 목록으로는 입증 안 됨 | 실기 `find … -type l | xargs ls -l` 출력(2 개, 대상 같음)을 따로 받음 | ⚖️ 이미 확인 — JSON 에 함께 기록 |
| NeXT 루트를 기존 루트 뒤에 두는 것은 D018 과 일치(이름이 아니라 "요청 경로로 앞 루트에서 해석 안 되는 것") | — | ✅ |
| `components/architecture` 루트의 `i386/ansi.h`·`i386/limits.h` 는 Darwin 설치 시 `Headers/bsd/i386/` 로 감(architecture/Makefile:4–8·50–56) | Makefile 1–10·48–58 열람(`ANSI_DSTDIR=…/Headers/bsd`, `ANSI_HDRS = ansi.h limits.h`) | ✅ 기록 |
| **차단: 스캐너는 문자 그대로의 include 만 따라감 — NeXT `ansi/machine/limits.h:11` `#include ARCH_INCLUDE(ansi/, limits.h)` 의 대상(`ansi/i386/limits.h`)이 스테이징되지 않음** | limits.h 1–15 열람, `ARCH_INCLUDE.h`: `#define ARCH_INCLUDE(prefix, suffix) #prefix __TARGET_ARCHITECTURE__ "/" #suffix`; NeXT 헤더 41 개가 이 형식 사용 | ✅ **설계 추가** |
| 기본 동작은 선택 플래그면 바이트 동일 유지 가능(현재 회귀 manifest 64 소스·268 파일·미해결 12 재현) | — | ✅ 수정 후 실제로 비교 |
| 매핑은 `Headers` 기준 하나로(`Headers/bsd`+`sys/x` 와 `Headers`+`bsd/sys/x` → `nextdev/bsd/sys/x`) 중복 제거 | — | ✅ |
| 아키텍처 20 개: 13 개는 주석만 다름, `byte_order.h`·`alignment.h` 는 선택 방식이 다름(Darwin `#if __i386__`, NeXT `ARCH_INCLUDE`) | 내 Python(주석 제거 후 13 동일)·`byte_order.h` diff | ✅ Darwin 우선 유지 |
| **해시 강제**: 사본은 불변이 아니므로 JSON 기준과 다른·목록에 없는 파일은 거부, manifest 에 실기 경로·SHA·D017 상태 | SOURCES.md:39–41 | ✅ 설계 추가 |

**내가 추가로 찾은 위험**: 우리 빌드는 `-traditional-cpp`. 전통 모드 전처리기는 `#prefix` 문자열화를 하지 않으므로 `ARCH_INCLUDE` 가 실기에서도 이 플래그로는 동작하지 않을 수 있음 → 탐침에서 먼저 확인.

수정 설계:
1. 기록 JSON(실기 704 파일 SHA·크기, 링크 2 개, 사본 대조, 검색 경로 사실).
2. `stage_headers.py --nextdev`: (a) 루트를 기존 뒤에 `Headers`·`Headers/bsd`·`Headers/ansi` 순으로 추가, 논리 경로는 모두 `Headers` 기준 `nextdev/…`(`--prefer-07` 이면 `07_kernel/nextdev/…` 먼저); (b) 스캐너가 `#include/#import ARCH_INCLUDE(p, s)` 를 i386 대상으로 `p` + `i386/` + `s` 로 해석(우리 빌드는 `-arch i386` 고정 — 명시); (c) nextdev 파일은 JSON 의 SHA 와 같아야 스테이징(다르거나 없으면 오류), manifest 행에 실기 경로 `/NextDeveloper/Headers/…`·SHA·"license TBD (D017)". 플래그 없으면 동작·출력 그대로.
3. 검증: 플래그 없는 스테이징이 수정 전과 manifest 바이트 동일(s5p46 회귀 소스 64 개로); `--nextdev` 로 `vm/vm_synchronize.c` 스테이징 → 실기 진단 빌드(07 변경 없음), `-traditional-cpp` 에서 `ARCH_INCLUDE` 동작 여부와 `.i` 의 nextdev 출처 헤더 목록 기록.
- 탐침(실기 `/tmp` 에 시험 파일만): `-traditional-cpp -nostdinc -I/NextDeveloper/Headers{,/bsd,/ansi}` 로 `<machine/limits.h>` 전처리 → `ansi/machine/limits.h` → `architecture/ARCH_INCLUDE.h` → `ansi/i386/limits.h` 까지 정상 — NeXT cpp 는 전통 모드에서도 `ARCH_INCLUDE` 를 처리(내가 걱정한 위험 없음).

### 73.2 결과 (2026-10-02) — 실기 헤더 기준 고정, `stage_headers.py --nextdev`, 첫 시험 OBJECT_MATCH

- 기록: `09_validation/reconstruction/s4c-nextdev-headers-20261002.json`(실기 704 파일 SHA·크기, 링크 2, 사본 대조 699/5(`.p`)/3(AppKit), cc 기본 검색 경로, `System.framework/Headers` 링크 구성, license TBD(D017)).
- `10_tools/reconstruction/stage_headers.py`: `--nextdev` 추가 — 루트 `Headers`·`Headers/bsd`·`Headers/ansi` 를 기존 루트 뒤에, 논리 경로 `nextdev/…`(07 우선은 `07_kernel/nextdev/…`), `ARCH_INCLUDE(p, s)` → `p` + `i386/` + `s`(플래그 있을 때만), nextdev 파일은 JSON 의 실기 SHA 와 다르면 오류, manifest 행에 실기 경로·SHA·"license TBD (D017)". **플래그 없는 동작은 그대로**: 회귀 소스 64 개 스테이징이 수정 전 `s5p46-regress-stage-1` 과 manifest·파일 트리 모두 바이트 동일.
- 탐침 `s5p47-probe-1`(07 변경 없음): Darwin `vm/vm_synchronize.c` 원문 + `--nextdev` 스테이징(nextdev 8 파일 모두 실기 SHA 일치), 빌드 명령 `-I` 끝에 `-Isrc/nextdev -Isrc/nextdev/bsd -Isrc/nextdev/ansi`. 컴파일 성공, `.i` 의 nextdev 출처 = `ansi/machine/limits.h`·`architecture/ARCH_INCLUDE.h`·`ansi/i386/limits.h`, 두 `.i` 동일, O3 = O3c = O2 `a97565b4…`, **L1 OBJECT_MATCH 4/4**(원본 [0x17b9e0, 0x17bd28) 840 B). 채택(07_kernel/nextdev 사본·경계·기록)은 다음 회차.

## 74. S5-P48 세부 계획 — `vm/vm_synchronize.c` 채택과 첫 NeXT 헤더 채택(D018) (코딩 전, 2026-10-02)

사실(실행 ID `s5p47-*`; 73.2 탐침):
- 원본 [0x17b9e0, 0x17bd28) 840 B, 함수 4(공개 `_vm_synchronize` 0x17b9e0, 정적 3 — 원본 심볼 없음, Ghidra `FUN_0017ba1c`·`FUN_0017bacc`·`FUN_0017bc50`), 데이터 섹션 없음. 앞 `00`×3(`ret` 0x17b9dc, vm_resident 쪽), 뒤 0 B(`ret` 0x17bd27, `_useracc` 0x17bd28). objects.tsv 의 끝 0x17ba1b 는 이름 있는 함수만의 하한.
- 탐침: Darwin 원문 + `--nextdev`, O3 = O3c = O2 `a97565b4…`, OBJECT_MATCH 4/4, 두 `.i` 동일.
- `.i` 표지 중 07 에 없는 것: 대상 소스, NeXT 헤더 3(`ansi/machine/limits.h`, `architecture/ARCH_INCLUDE.h`, `ansi/i386/limits.h` — 고지는 `ansi/i386/limits.h:1` "Copyright (c) 1992 NeXT Computer, Inc." 뿐), Darwin BSD 헤더 9(`bsd/machine/{param,signal}.h`, `bsd/sys/{param,resource,signal,syslimits,time,ucred,uio}.h`).

설계:
1. `07_kernel/src/vm/vm_synchronize.c`·Darwin BSD 헤더 9 개 = Darwin 원문(PROVENANCE "none (verbatim)", 고지 기록).
2. `07_kernel/nextdev/{ansi/machine/limits.h, architecture/ARCH_INCLUDE.h, ansi/i386/limits.h}` = 사본 그대로이되 **실기 SHA 와 같음을 다시 확인**. PROVENANCE: source_id `nextdev-os42`, revision "OPENSTEP 4.2 real machine /NextDeveloper/Headers (09_validation/reconstruction/s4c-nextdev-headers-20261002.json)", 원 경로 `/NextDeveloper/Headers/…`, 라이선스 칸 "license TBD (D017); NeXT notice in file"(있는 경우), changes "none (verbatim; file SHA-256 …)".
3. 07 빌드: `stage_headers.py --prefer-07 --nextdev`(nextdev 3 파일이 `07_kernel/nextdev` 에서 오는지 manifest 로 확인), 명령은 기존 `-I` 끝에 `-Isrc/nextdev -Isrc/nextdev/bsd -Isrc/nextdev/ansi`. 예측: 탐침과 같은 SHA `a97565b4…`. objects_confirmed(A)·functions.tsv 4 행(정적 3 명기)·증거.
4. 다른 객체 회귀 불필요(기존 헤더 변경 없음, 새 파일은 `--nextdev` 에서만 쓰임) — 단 BSD 헤더 9 개를 07 로 들이면 플래그 없는 스테이징에서도 07 판이 우선되므로, 내용이 Darwin 원문과 같음(SHA)으로 영향 없음을 확인.

### 74.1 codex 교차검토(QR2) 판정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| 탐침: 원문 SHA `e360165a…`, nextdev 8 파일 실기 SHA 일치, L1 OBJECT_MATCH 4/4(정적 이름 `_map_push_range`·`_vm_pageout_page`·`_object_push`), 840 B, O2=O3=O3c | 73.2 출력 | ✅ |
| **범위 JSON 키가 Ghidra `FUN_*` 라 정적 함수의 경계 검사가 조용히 건너뜀**(`l1_compare.py:363` `if nm in ranges`); 객체 심볼 이름으로 바꾸면 4/4 그대로 | l1_compare.py 355–372 열람 | ✅ 채택 증거는 객체 심볼 이름으로 바꾼 범위로. **앞선 확정 중 정적 함수가 있는 객체(mach_debug·miniMonMachdep·PCemulateREAL/PROT·vm_synchronize 탐침 등)도 정적 함수 경계 검사는 하지 않았음** — `__text` 전체 바이트·참조 비교는 했으므로 판정은 유지, 한계로 기록 |
| 경계 `c3 00 00 00`/`c3`·`_useracc` | 74 절 출력 | ✅ |
| `.i` 의 07 미채택 = 소스 + nextdev 3 + BSD 9, 고지(Darwin 전부 APSL, `sys/*` 7 개 UC, 일부 NeXT; nextdev 는 `ansi/i386/limits.h` 만 1992 NeXT) | 74 절 Python 출력 | ✅ 고지 없음도 명기 |
| 회귀 64 소스는 새 BSD 헤더를 읽지 않음 | 내 Python(교집합 []) | ✅ |
| "새 파일은 `--nextdev` 에서만" 은 nextdev 에만 해당 — BSD 헤더는 `--prefer-07` 로 늘 우선(내용 동일하므로 무해) | stage_headers.py:76 `select` | ✅ 문구 정정 |
| **07_kernel 사본에는 실기 SHA 검사가 적용 안 됨**(:183 조건) | stage_headers.py 178–190 열람 | ✅ 수정: 07 사본이 실기 SHA 와 다르면 manifest 에 "differs from real machine" 표시(사본에서 온 파일은 지금처럼 오류), 이번 채택은 3 파일 SHA 를 별도로 확인 |
| README 디렉터리 목록에 `nextdev/` 추가 | README:10 | ✅ |

### 74.2 결과 (2026-10-02) — `vm_synchronize.c` 확정(A), 첫 NeXT 헤더 채택

- `stage_headers.py`: 07_kernel 쪽 nextdev 사본이 실기 SHA 와 다르면 manifest 에 "differs from the real machine" 표시(사본에서 온 파일은 오류 유지).
- 07_kernel: `src/vm/vm_synchronize.c`·Darwin BSD 헤더 9 개(원문), `nextdev/ansi/machine/limits.h`·`nextdev/architecture/ARCH_INCLUDE.h`·`nextdev/ansi/i386/limits.h`(실기 SHA 와 같음 확인, license TBD D017). README 에 `nextdev/` 추가.
- 빌드 `s5p47-build-1`(`--prefer-07 --nextdev`, nextdev 3 파일이 07_kernel 에서): 예측대로 세 변형 `a97565b4…`, 두 `.i` 동일, 객체 심볼 이름 범위로 L1 OBJECT_MATCH 4/4(정적 경계 포함), 경계 `00`×3/0 → **A**.
- 기록: objects_confirmed +1(59 객체), functions.tsv +4, PROVENANCE +13(258 행; `nextdev-os42` 3 행), 증거 `x86-vm_synchronize.md`. 처리 중 실수: PROVENANCE 고지 검출이 "NeXT, Inc." 형식을 놓쳐 vm_synchronize.c 행을 고침.

## 75. S5-P49 세부 계획 — `kern/timer.c`(A)·`machdep/i386/vm_machdep.c`(P) 를 Darwin 판 그대로 채택(`--nextdev`) (코딩 전, 2026-10-02)

사실(실행 ID `s5p48-*`; 일괄 진단 `s5p48-pre-1` = `machine/limits.h` 로 막혔던 Darwin 13 파일, `--nextdev`):
- 컴파일 10, 실패 3(unix_signal·pcb: `pc_support.h`/`fp_emul.h` 없음; mapfs: `mach_nbc.h` 없음). L1: **timer OBJECT_MATCH 6/6**, **syscall_subr OBJECT_MATCH 9/9**(1028 B), **vm_machdep 2/2 MATCH + `__TEXT,__const` 4 B 미배치**; ns_timer·miniMon·kdp_udp·kdp_machdep·unix_startup 은 크기 다름(배치 실패), ux_exception·ast 는 바이트 차이.
- syscall_subr 보류: 원본 구간에 NeXTMach `kern/syscall_subr.c` 의 `map_fd`(원본 [0x165784, 0x165949), 49.1)가 이어지고, 이 함수는 `struct file`·`vnode`·`getf` 등 BSD 구조체에 의존 — BSD 쪽 정리 후.
- timer: `__text` [0x16a198, 0x16a35e) 454 B, 함수 6(`_init_timers`·`_timer_init`·`_timer_normalize`·`_timer_read`·`_thread_read_times`·`_timer_delta`, 모두 원본 심볼), `-fno-common` 판 `__common` 20 B 는 원본 심볼로 배치(placement-only), `__data` 크기 0. 앞 `00 00`(확정 time_stamp 끝 0x16a196), 뒤 `00 00`(0x16a360 부터 이름 없는 코드, 다음 심볼 `_zinit` 0x16a490).
- vm_machdep: `__text` [0x193e58, 0x193f31) 217 B, 함수 2(`_pagemove`·`_kernacc`), `__data` 9 B 0x1e294a(추정·L1d 일치), `__TEXT,__const` 4 B `18 00 20 00` — 재배치 0(ltr/lldt 선택자, PCresume·intr 과 같은 기제). 앞 `00 00`(`ret` 0x193e55, `_startup` 쪽; 0x193e56→0x193e58 최소 채움 2), 뒤 `00`×3(`_probeNativeDevices` 0x193f34).

설계: 두 소스 Darwin 원문 그대로 07 에 복사, `.i` 표지로 07 에 없는 헤더 원문 채택(nextdev 쪽은 실기 SHA 확인 후 `07_kernel/nextdev`). 07 빌드(`--prefer-07 --nextdev`, O3·O3c·O2·두 `.i`) 예측: O3 = 진단 SHA(`s5p48-pre-1`). timer 는 common 변형으로 36.1 확인(common 1 개 이상이면), 등급 A. vm_machdep 는 등급 **P**(`__TEXT,__const 4 B unreferenced`). 함수 L1 은 객체 심볼 이름 키 범위로.

### 75.1 codex 교차검토(QR3) 판정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| 입력 원문 SHA·nextdev 9 파일 실기 SHA 일치, 객체 SHA = output.manifest | 진단 스테이징 `--nextdev`(사본 파일은 불일치 시 오류) | ✅ |
| timer OBJECT_MATCH 6/6·454 B; vm_machdep 2/2, `__data` 9 B(`"pagemove"`)는 참조 1 개(0x193e6d)로 추정·L1d 일치, `__const` 는 들어오는 재배치 0 | 75 절 출력(`refs to const 0`, 섹션 표) | ✅ `__data` 단일 참조 배치를 증거에 명기 |
| 경계 두 객체 모두 성립; 0x16a360 의 이름 없는 함수는 zalloc 의 정적 `zone_free_space_lookup` 으로 보임(원본 0x16ae29 의 호출) | 75 절 바이트 출력 | ✅ 귀속은 "추정" 으로 기록 |
| **timer 의 common 2 개(`_current_timer` 4 B, `_kernel_timer` 16 B)는 심볼 배치라도 36.1 절차(변형 OBJECT_MATCH·전처리 동일·재배치 대응·크기 상한)를 생략하지 않음**(계획 1273–1275, host 선례) | 1273–1275 열람 | ✅ 07 빌드에서 수행 |
| vm_machdep P 는 선례·README:24 와 일치 | — | ✅ |

### 75.2 결과 (2026-10-02) — `timer.c` 확정(A), `vm_machdep.c` 등급 P

- 07_kernel: `kern/timer.c`·`machdep/i386/vm_machdep.c` 원문 + `.i` 로 확정한 Darwin BSD 헤더 6(`bsd/machine/cpu.h`·`bsd/sys/{kernel,buf,queue,vm,vmmeter}.h`). nextdev 쪽은 74 에서 채택한 3 파일 그대로.
- 빌드 `s5p48-build-1`(`--prefer-07 --nextdev`): 예측대로 timer O3 = O2 = `ae4e93ed…`, O3c `2561c773…`, vm_machdep 세 변형 `760ab32f…`, 두 `.i` 각각 동일. timer O3·O3c OBJECT_MATCH 6/6, 36.1(common 2, 재배치 3 대응, 밖 바이트 동일) → **A**; vm_machdep 2/2 MATCH + `__const` 4 B 참조 없음 → **P**.
- 기록: objects_confirmed +1(60 객체), objects_partial +1(7), functions.tsv +8(high), PROVENANCE +8, 증거 2.

## 76. S5-P50 세부 계획 — 옵션 `PC_SUPPORT`·`FP_EMUL`·`MACH_NBC` 추가, 67 객체 회귀, `machdep/i386/catch.c` 채택 (코딩 전, 2026-10-02)

사실(실행 ID `s5p49-*`; 탐침은 스테이징에만 옵션 헤더):
- `pc_support.h`·`fp_emul.h`·`mach_nbc.h` 는 파일이 아니라 config 옵션 헤더(`conf/files.i386:5–6` `OPTIONS/fp_emul`·`OPTIONS/pc_support`, `conf/MASTER:131` `MACH_NBC <nbc>`). `MASTER.i386:90–91`: `FP_EMUL <fp>`, `PC_SUPPORT <pc>`; RELEASE 태그(`MASTER.i386:72`)에 `pc`·`nbc` 있고 `fp` 없음. 원본 심볼표에 `fp_emul/*.s` 의 전역(`_e80387` 등 20 개 검사) 없음, PC 지원 심볼(`_PCcreate` 0x1a0e48·`_PCexception`·`_PCresume` 등) 있음 — 76.1 에서 정정(`_PCinit` 은 없음).
- 탐침 `s5p49-pre-1`(PC_SUPPORT 1·FP_EMUL 0·MACH_NBC 1, `--nextdev`): unix_signal·pcb·mapfs·catch·fp_support 모두 컴파일. **catch OBJECT_MATCH 2/2**(300 B); fp_support 3 MATCH + 7 MATCH_UNVERIFIED(`__TEXT,__const`·`__DATA,__bss` 미검증 — 다음 회차 후보); unix_signal(1416 대 1452)·pcb(6753 대 6760)·mapfs 는 크기 다름.
- catch.c: `#if PC_SUPPORT` 분기(:40–42, :52–54, :65–67)가 `threadPCInterrupt`/`threadPCException` 인라인을 넣어 미정의 참조 `_PCcallMonitor`·`_PCexception` 이 생기고, 이것이 원본 참조와 일치(L1 참조 차이 0) → **PC_SUPPORT=1 의 바이트 근거**. 원본 [0x186fdc, 0x187108): 앞 `00` 1 B(`ret` 0x186fda), 뒤 0 B(`__bios32` 0x187108). 데이터 섹션 없음.

설계:
1. `config_options.tsv` 3 행: `pc_support` PC_SUPPORT 1 **confirmed**(catch.c), `fp_emul` FP_EMUL 0 hypothesis(fp_emul 전역 부재, RELEASE 에 fp 없음; fp_support 판정 때 바이트 확인), `mach_nbc` MACH_NBC 1 hypothesis(RELEASE nbc). `gen_config_headers.py` 로 생성·`--check`.
2. 회귀: `meta_features.h` 변경 → 확정 60 + 부분 7 = 67 객체를 각 확정 명령으로 다시 빌드(기준 `s5p46-regress-baseline.json` 64 + vm_synchronize `s5p47-build-1`·timer·vm_machdep `s5p48-build-1` O3), 스테이징은 `--nextdev` 하나로(기존 64 명령에는 nextdev `-I` 가 없으므로 영향 없음), 예측 67/67.
3. `07_kernel/src/machdep/i386/catch.c` = Darwin 원문, `.i` 로 07 에 없는 헤더 원문 채택. 07 빌드 예측: O3 = 탐침 `23bd2de7…`. objects_confirmed(A), functions.tsv 2, PROVENANCE, 증거.

### 76.1 codex 교차검토(QR4) 판정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| **`_PCinit` 은 원본에 없음** — PCinit.c 의 함수는 `_PCcreate` | `grep -cP '\t_PCinit\t'` = 0, `_PCcreate` 0x1a0e48 | ✅ **내 오류** — 76 절 정정 |
| 옵션 근거(MASTER.i386:72·90–91, MASTER:131, files.i386:5–6, 추가로 `conf/files:54` `OPTIONS/mach_nbc`), fp_emul 전역 140 개 중 원본 일치 0 | files:54 열람, 내 검사(20 개 검사, 0) | ✅ |
| catch.c OBJECT_MATCH 2/2(300 B, 참조 8, 차이 0, 데이터 없음); `PC_SUPPORT=0` 이면 `PCexception`/`PCcallMonitor` 참조가 사라져 이 바이트를 낼 수 없음 → confirmed 타당(0 판 빌드는 안 함) | catch.c 36–80 열람, 탐침 미정의 심볼에 두 이름 | ✅ |
| 67 등록 소스와 그 닫힘(304 파일)에 세 매크로·헤더 이름 없음 → 기존 객체 코드 불변 예상; fp_support.c 는 등록 밖 | — | ✅ 회귀로 확인 |
| catch 경계(앞 1·뒤 0) | 76 절 출력 | ✅ |
| 회귀 기준 67 개 완비(목록), 기존 64 명령에 nextdev `-I` 없음, `--prefer-07 --nextdev` 스테이징 | 내 기준 구성과 같음 | ✅ |

### 76.2 결과 (2026-10-02) — 옵션 3 개 추가, 회귀 67/67, `catch.c` 확정(A)

- `config_options.tsv` 21→24 행(`pc_support` 1 confirmed, `fp_emul` 0·`mach_nbc` 1 hypothesis), 생성·`--check` 통과.
- 회귀 `s5p49-regress-1`(`--prefer-07 --nextdev` 스테이징, 각 확정 명령): **67/67 동일**.
- 07_kernel `machdep/i386/catch.c` 원문(07 에 없는 `.i` 헤더 없음). 빌드 `s5p49-build-1`: 예측대로 세 변형 `23bd2de7…`, 두 `.i` 동일, OBJECT_MATCH 2/2, 경계 1/0 → **A**.
- 기록: objects_confirmed +1(61 객체), functions.tsv +2, PROVENANCE +4(생성 헤더 3 포함), 증거 `x86-catch.md`.

## 77. S5-P51 세부 계획 — `machdep/i386/fp_support.c` 채택(등급 P)과 `FP_EMUL=0` 확정 (코딩 전, 2026-10-02)

사실(실행 ID `s5p50-*`; 탐침은 Darwin 원문을 07 의 생성 헤더·`--nextdev` 로 스테이징):
- 탐침 1: O3 = O3c = O2 `d90a0d6c…`(= 76 절 진단 `s5p49-pre-1` 의 O3), 두 `.i` 동일. 섹션: `__text` 1522 B·재배치 43, `__TEXT,__const` 4 B `18 00 20 00`(들어오는 재배치 0 — ltr/lldt 선택자), `__DATA,__bss` 4 B(정적 `fp_thread`, :57).
- 원본 `__text` [0x18a310, 0x18a902) — 공개 심볼로 Δ 하나(0x18a310), 함수 10(원본 심볼 7 + 원본에 이름 없는 정적 3 `fp_save`·`fp_switch`·`fp_unowned` — 77.1 정정; 범위는 객체 심볼 이름 키 10/10). L1(O3·O3c): 3 MATCH(`_fp_configure`·`_fp_noextension`·`_fp_ast`) + 7 MATCH_UNVERIFIED(모두 `__bss` 에만 의존), 객체 NOT_MATCH 사유는 `__const`·`__bss` 미검증뿐. 바이트·참조 차이 0.
- `__bss`: `zerofill_check.py`(known `zerofill-known-s5p50-20261002.json` = s5p45 + dma [0x1e75ec, 0x1e75f8)) — 참조 9(모두 오프셋 0), Δ 0x1e7000 하나, 후보 [0x1e75f8, 0x1e75fc) 정렬·zero-fill 안·심볼 없음·겹침 없음, 음성 검사 검출 → **reference-inferred**.
- 경계: 앞 `00`×3(확정 fault_copy 끝 0x18a30d), 뒤 `00 00`(`_locate_gdt` 0x18a904).
- `FP_EMUL`: `#if FP_EMUL` 분기(:47, :120–122, :158–167, :354–360, :386–392, :438–444, :470–477)는 `FPU_EMUL` 대입·`e80387(state)` 호출·`map_data(...)` 를 넣음. 원본에 `_e80387` 없고 함수 바이트가 0 판과 일치 → **FP_EMUL=0 바이트 확정** 가능(1 판 빌드는 안 함).

설계:
1. `07_kernel/src/machdep/i386/fp_support.c` = Darwin 원문, `.i` 로 07 에 없는 헤더 원문 채택. 07 빌드 예측: 세 변형 `d90a0d6c…`. 최종 객체로 zerofill_check 재실행.
2. 등급 **P**(`unverified_sections`: `__TEXT,__const 4 B unreferenced` + `__DATA,__bss 4 B reference-inferred at 0x1e75f8`), functions.tsv 10 행(3 high, 7 medium).
3. `config_options.tsv` `fp_emul` 행 상태 hypothesis → **confirmed**(값 0 그대로 → 생성 헤더 내용 불변, `--check`; 회귀 불필요 — 생성 결과 바이트 동일 확인).

### 77.1 codex 교차검토(QR5) 판정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| 탐침 원문·`.i` 동일·O2=O3=O3c | 77 절 출력 | ✅ |
| L1 3 MATCH + 7 MATCH_UNVERIFIED(`__bss` 만), `__const` 들어오는 재배치 0, 범위 키 10/10 | 77 절 출력 | ✅ |
| zero-fill 9 참조·Δ 하나·후보·음성 검사; known 은 겹침 검사용으로 적절(소유 증명 아님); dma 끝 = 후보 시작, text 에서도 dma 가 앞 — 일관 | 77 절 출력 | ✅ |
| 경계 `00 00 00`/`00 00` | 77 절 출력 | ✅ |
| **FP_EMUL=0 확정 타당**: :120(`FPU_EMUL` 대입)·:158(`e80387` 호출)이 들어가는 두 함수(`_fp_configure`·`_fp_ast` 쪽)가 **완전 MATCH** — BSS 의존 7 개와 무관; 심볼 부재만으로는 부족 | L1 함수 판정(`_fp_configure`·`_fp_ast` MATCH) | ✅ |
| **"전부 원본 심볼" 은 틀림 — 원본 심볼 7, 원본에 없는 정적 3(`_fp_save`·`_fp_switch`·`_fp_unowned`)** | symbols.tsv grep(그 3 개 0 건) | ✅ **내 오류** — 77 절 정정 |

### 77.2 결과 (2026-10-02) — `fp_support.c` 등급 P, `FP_EMUL=0` confirmed

- 07_kernel: `machdep/i386/fp_support.c` 원문 + `.i` 로 확정한 헤더 6(`mach/{,i386/,machine/}exception.h`, `machdep/i386/{configure,fp_exported,fp_inline}.h`) 원문.
- 빌드 `s5p50-build-1`: 예측대로 세 변형 `d90a0d6c…`, 두 `.i` 동일, 3 MATCH + 7 MATCH_UNVERIFIED(`__bss`), 최종 객체 zerofill reference-inferred → **P**.
- `config_options.tsv` `fp_emul` hypothesis → confirmed(값 그대로, `--check` 통과 — 생성 헤더 불변, 회귀 불필요).
- 기록: objects_partial +1(8 객체), functions.tsv +10(high 3·medium 7, 정적 3 명기), PROVENANCE +7, 증거 `x86-fp_support.md`.

## 78. S5-P52 세부 계획 — 첫 BSD 쪽 일괄 진단과 `bsd/libkern/strtol.c` 채택 (코딩 전, 2026-10-02)

사실(실행 ID `s5p51-*`; 일괄 진단 `s5p51-pre-1` = BSD 쪽 미확정 B 후보 49 중 작은 30 구간의 Darwin 원문 29 파일, `--nextdev`):
- 컴파일 17, 실패 12 — 대부분 옵션 헤더 없음(`quota.h`·`cputypes.h`·`uxpr.h`·`bpfilter.h`·`rev_endian_fs.h`, `kern/kdebug.h` 가 찾는 `kdebug.h`), tcp_output 은 코드 오류.
- L1: **strtol OBJECT_MATCH 2/2**; in_bootp·ip_mroute 는 빌드 `__text` 0 B(in_bootp 는 `#if NEXT`(:25)로 비고, ip_mroute 는 `#ifndef MROUTING`(:76) 판에 `__common` 4 B `_ip_mrtproto` 만 — 78.1 정정; 원본 seq 78 은 실행 코드, seq 92 는 스텁 3 개); 나머지는 크기 다름 또는 바이트·참조 차이(cmu_syscalls·kern_acct) — 후보 빌드가 원본과 다르다는 뜻이며, 판 차이 외에 설정·헤더 차이도 원인일 수 있음(78.1 정정).
- strtol: 원본 [0x1beb58, 0x1bee8b) 819 B, `_strtol`·`_strtoul`(원본 심볼), 재배치·데이터 없음, O3 SHA(진단) `4392f8a9da471e71…`. 앞 `00 00`(`ret` 0x1beb55, `_audio_byteToMulaw` 쪽), 뒤 `00`(`_Event_server` 0x1bee8c). 고지: APSL, 1995 NeXT, UC Regents(1990, 1993).

설계: `07_kernel/src/bsd/libkern/strtol.c` = Darwin 원문, `.i` 로 07 에 없는 헤더 원문 채택. 07 빌드(`--prefer-07 --nextdev`, 세 변형·두 `.i`) 예측: 진단 SHA. objects_confirmed(A)·functions.tsv 2·PROVENANCE·증거. 다른 실패 원인(옵션 헤더 `quota`·`cputypes`·`uxpr`·`bpfilter`·`rev_endian_fs`·`kdebug`)은 다음 회차 이후 옵션 근거 조사 대상으로 기록.

### 78.1 codex 교차검토(QR6) 판정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| 17/12 맞음; 실패 원인에 `kernobjc.h`·`loop.h`·`xpr_debug.h`·`driverkit/{ddmPrivate,Device_ddm}.h` 추가, tcp_output 은 `DBG_*` 미정의 | 78 절 요약은 첫 오류만 출력 | ✅ 기록 보강 |
| strtol OBJECT_MATCH 2/2, 819 B, 재배치 0, `__text` 만, SHA `4392f8a9…`, 원문 SHA 일치 | 78 절 출력 | ✅ |
| **seq 344 상한 [0x1bee8c, 0x1c0918) 에는 `_Event_server`·`_audio_server` 등 다른 코드 — strtol 에 귀속하지 말 것** | 78 절 출력(다음 심볼 `_Event_server` 0x1bee8c) | ✅ 객체 범위는 [0x1beb58, 0x1bee8b) 만 |
| strtol 의 헤더 사슬은 nextdev `objc/objc.h`·`objc/objc-api.h`·limits 3 개 | (07 빌드 `.i` 로 확정) | ⚖️ `.i` 로 확정한 것만 채택 |
| UC 4 조항 고지 등 원 고지 보존이면 D017 상 별도 BSD 라이선스 파일 불필요 | DECISIONS:21 | ✅ |
| **in_bootp 은 `#if NEXT`(:25, `NeXT` 아님) — 빌드는 `-DNeXT` 만** | in_bootp.c:25, run.sh 의 `-DNeXT` 29 회·`-DNEXT` 0; Darwin BSD 13 파일이 `#if NEXT`/`#ifdef NEXT` 사용, conf Makefile 에 정의 없음 | ✅ **열린 질문으로 기록**(BSD 쪽 `NEXT` 매크로 근거 조사 필요) |
| ip_mroute 빈 판은 MROUTING 을 켰다는 증거가 아님(원본 seq 92 는 스텁) | — | ✅ |
| "판이 다름" 은 과한 결론 | — | ✅ 문구 정정 |

### 78.2 결과 (2026-10-02) — `strtol.c` 확정(A), 첫 BSD 쪽 객체

- 07_kernel: `bsd/libkern/strtol.c` 원문 + `.i` 로 확정한 Darwin `bsd/include/{limits,stdlib,string}.h` 와 실기 `nextdev/objc/{objc,objc-api}.h`(실기 SHA 같음, license TBD).
- 빌드 `s5p51-build-1`: 예측대로 세 변형 `4392f8a9…`, 두 `.i` 동일, OBJECT_MATCH 2/2, 경계 2/1 → **A**.
- 기록: objects_confirmed +1(62 객체), functions.tsv +2, PROVENANCE +6(283 행), 증거 `x86-strtol.md`. 열린 질문: BSD 파일의 `#if NEXT`(빌드에는 `NeXT` 만 정의).

## 79. S5-P53 세부 계획 — BSD 쪽 기준 판 조사: 구조체 비교 도구(NeXT SDK·NeXTMach·Darwin) (코딩 전, 2026-10-02)

사실(실행 ID `s5p52-*`, 탐침은 스테이징만):
- `#if NEXT`(대문자)를 쓰는 Darwin 파일 13 개(PCRE 전수: `bsd/kern/uipc_{socket,syscalls}.c`, `bsd/netat/*` 4, `bsd/netinet/{in_bootp,in_cksum,ip_input,ip_output,tcp_output,udp_usrreq}.c`, `machdep/i386/fp_emul/fp_e80387.h`) — 확정 객체 소스·07 헤더에는 없음. `NEXT` 를 정의하는 곳은 `driverkit-1/libDriver/Kernel/IOEthernet.m:51` 뿐, Darwin `conf/Makefile.template:104` 는 `-D__APPLE__ -DNeXT`. 원본에는 bootp 심볼 2 개와 in_bootp 객체(seq 78)가 있음 → 원본 빌드에서 그 블록이 켜져 있었을 것.
- 탐침 `s5p52-probe-1`(in_bootp.c + `-DNEXT`): `struct ifnet` 에 `if_eflags` 없음 오류 — Darwin `bsd/net/if.h:163–168` 은 `#if __APPLE__` 에서만 `if_eflags`(우리 빌드는 `__APPLE__` 를 정의하지 않고 지금까지의 확정 객체도 그 없이 일치).
- **실기 SDK `bsd/net/if.h` 의 `struct ifnet`(주석 제거 후 본문의 비어 있지 않은 줄 43 — 필드 수가 아님, 79.1 정정)은 NeXTMach `mk-108.1/net/if.h` 와 완전히 같고, Darwin 판(40 줄)과 다름** — `char *if_name`, `short if_unit`, `netbuf_t (*if_getbuf)()` 등 4.3BSD 식.

설계(이번 회차는 도구와 기록, 07 변경 없음):
1. 새 도구 `10_tools/reconstruction/struct_compare.py`: 헤더 세 판(실기 SDK `NextDeveloper/Headers/bsd/...`, NeXTMach `mk-108.1/...`, Darwin `kernel/bsd/...`)에서 지정 구조체 본문을 뽑아(주석·공백 정규화) 같음/다름과 필드 수를 JSON 으로 냄. 대상: BSD 쪽 핵심 구조체(`ifnet`·`ifaddr`·`mbuf`·`socket`·`sockbuf`·`proc`·`ucred`·`file`·`vnode`·`uio`·`timeval`·`rusage`·`user` 등 — 세 판에 같은 이름의 헤더가 있는 것만).
2. 결과 `09_validation/reconstruction/s4c-bsd-struct-compare-20261002.json` 와 요약을 계획 79.2 에 기록 — 구조체마다 "SDK = NeXTMach" / "SDK = Darwin" / "셋 다 다름". 이는 BSD 각 하위 체계의 기준 판(Darwin 대 NeXTMach) 판단의 근거 자료이며, 판단 자체(사용자 결정 사항일 수 있음)는 하지 않는다.
3. 도구 자체 검증: `ifnet` 결과가 위 수동 비교(SDK = NeXTMach, Darwin 다름)와 같아야 함.

### 79.1 codex 교차검토(QR7) 판정 → 설계 보강

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| `#if/#ifdef NEXT` 파일은 14(백업 `bsd/netat/h/localglue.h.pre0529` 포함), 제외하면 13 | `ls bsd/netat/h` 에 `.pre0529` 존재 | ✅ 문구에 필터 명시 |
| `NEXT` 정의는 `IOEthernet.m:51` 뿐(그 번역 단위 한정), Darwin 은 `-D__APPLE__ -DNeXT` | 79 절 grep | ✅ |
| 원본 bootp 근거는 `symbols.tsv:1229–1230`(`_in_bootp` 0x124154, `_in_bootp_bptombuf` 0x124590); NeXTMach `nextif/in_bootp.c` 는 바깥 `NEXT` 가드 없음 | — | ✅ 기록 |
| **`__APPLE__` 미정의는 전역 검증이 아님** — 07 의 `bsd/i386/param.h:102–111` 이 `#ifdef __APPLE__` 로 `btodb/dbtob` 형태를 고름; vm_synchronize·timer 는 이 헤더를 포함하지만 매크로를 쓰지 않아 바이트로 가려지지 않음. 실기 SDK `bsd/sys/param.h:219–228` 은 `NeXT` 에서 두 인자 판(= Darwin `__APPLE__` 분기와 같은 꼴) | param.h 100–112, SDK param.h 219–228 열람 | ✅ **열린 질문 추가**: BSD 쪽에서 `__APPLE__` 분기 판정 필요(지금까지 확정 객체는 이 매크로를 쓰지 않음) |
| `ifnet` 비교 맞음, 다만 "필드 43" 이 아니라 "본문 비어 있지 않은 줄 43"(지시문·대안 분기 포함) | — | ✅ 문구 정정 |
| 도구: 중괄호 균형 추출, 중첩·typedef·여러 정의·조건부 멤버 처리, 원문 비교와 전처리 비교 구분, 입력 해시·정의 범위·정규화 방식 기록, 결과 분류(모두 같음 / S=N≠D / S=D≠N / N=D≠S / 모두 다름 / 없음·모호), 픽스처 시험 | — | ✅ 이번 판은 "원문(조건부 텍스트 포함) 비교" 모드만 구현하고 그 한계를 명시 |
| 경로 대응표(13 구조체, 세 판의 경로:줄) | Python: 표의 모든 경로:줄에 `struct` 와 이름이 있음(불일치 0) | ✅ 도구 입력으로 사용 |
| 원문 동일 ≠ ABI 동일 — 배치 판단에는 원본 바이트·컴파일러 ABI 필요 | — | ✅ 결과 해석에 명시 |

### 79.2 결과 (2026-10-02) — BSD 구조체 13 개 비교: 실기 SDK 는 NeXTMach 계열

- 도구 `10_tools/reconstruction/struct_compare.py`(원문·조건부 텍스트 비교: 주석·문자열 가림 후 중괄호 균형 추출, 주석 제거·공백 정규화, 전처리 줄 유지; 입력 SHA·정의 줄 범위 기록; 결과 6 분류 + 없음/모호), 픽스처 시험 `test_struct_compare.py` 9/9(일반·주석 안 중괄호·문자열 안 중괄호·중첩·typedef·전방 선언만·조건부 멤버·정의 둘·이름 접두).
- 결과 `09_validation/reconstruction/s4c-bsd-struct-compare-20261002.json`: **S=N≠D 10**(`ifnet`·`ifaddr`·`mbuf`·`socket`·`sockbuf`·`ucred`·`file`·`vnode`·`uio`·`timeval`), all-equal 1(`rusage`), 모두 다름 2(`proc`·`user` — 단 SDK 대 NeXTMach 줄 유사도 0.960·0.967, SDK 가 6 줄씩 더 있음; Darwin `user` 는 본문 0 줄). 자체 검증: `ifnet` 이 수동 비교(SDK = NeXTMach, Darwin 다름)와 같음.
- 해석(원문 비교일 뿐 ABI 증명 아님): 원본 시대의 BSD 헤더(SDK)는 **NeXTMach mk-108.1(4.3BSD 계열) 쪽**이고 Darwin(4.4BSD 계열)과 다르다. BSD 쪽 소스 기준 판을 Darwin 에서 NeXTMach 로 바꿀지(하위 체계별로) 는 **사용자 판단 사항**으로 올린다 — 근거: 이 표, 78 절 BSD 일괄 진단(Darwin 판 17 컴파일 중 1 일치), 79 절 `in_bootp`·`ifnet`. 열린 질문 둘(`NEXT` 매크로, `__APPLE__` 분기)도 같은 판단과 묶임.

## 80. S5-P54 세부 계획 — `machdep/i386/kdp_machdep.c` = Darwin 판 + 래퍼 2 개 작성(D016) (코딩 전, 2026-10-02)

먼저 조사하고 보류한 것(실행 ID `s5p53-*`): `machdep/i386/pcb.c` — 원본과 다른 곳은 `_thread_dup`(324 대 320 B) 한 곳, 원본은 `child->task->proc->p_pid` 를 `movsx word [proc+0x30]` 로 읽고 Darwin 판은 `[proc+0x24]` 32 비트 — 실기 SDK `bsd/sys/proc.h:328`·NeXTMach `sys/proc.h:272` 는 `short p_pid`, Darwin 은 `pid_t p_pid`(:123). D018 상 Darwin 에 있는 `sys/proc.h` 는 Darwin 판이 우선이므로 **BSD 기준 판 결정(79.2, 사용자) 대기**. ns_timer·unix_startup·miniMon·kdp_udp·unix_signal 은 함수 크기 차이가 커서 보류.

사실(kdp_machdep):
- 진단(Darwin 원문, `--nextdev`): 원본에 있고 빌드에 없는 것은 `_kdp_en_send_pkt`(0x185dc0, 20 B)·`_kdp_en_recv_pkt`(0x185dd4, 24 B) 뿐, 그 밖 함수 크기 일치(끝의 `_kdp_flush_cache` 8 대 7 은 정렬 끝).
- 원본(capstone): `_kdp_en_send_pkt` = `push [ebp+0xc]; push [ebp+8]; call _en_send_pkt; ret`, `_kdp_en_recv_pkt` = 세 인자를 그대로 `call _en_recv_pkt`. 원본 순서 `_kdp_intr_enbl` 0x185db0 → 두 래퍼 → `_kdp_us_spin` 0x185dec.
- W1: Darwin `kdp_machdep.c` 에 없음(Darwin 은 `kern/kdp_udp.c:113–121` 에서 정적 함수 포인터 `kdp_en_send_pkt` 를 등록식으로 씀), NeXTMach·Mach4 에 kdp 없음. `en_send_pkt(void *pkt, unsigned int pkt_len)`·`en_recv_pkt(void *pkt, unsigned int *pkt_len, unsigned int timeout)` 꼴은 Darwin `driverkit-1/libDriver/Kernel/IOEthernetDebugger.m:175–195`(거기선 static) — 원본에는 전역 `_en_send_pkt`·`_en_recv_pkt` 심볼 있음.
- 탐침 2(스테이징; 예측을 cmd 머리에 기록: 887 B, 모든 함수 일치): `kdp_us_spin` 앞에 `void kdp_en_send_pkt(void *pkt, unsigned int pkt_len) { en_send_pkt(pkt, pkt_len); }` 와 `void kdp_en_recv_pkt(void *pkt, unsigned int *pkt_len, unsigned int timeout) { en_recv_pkt(pkt, pkt_len, timeout); }`(선언 없이 — 반환값 미사용, 48 절 ipc_sched 선례) → O3 = O3c(O2 는 다름 — 80.1 정정), **OBJECT_MATCH**(함수 15 + `__const` 섹션 시작 1 = 16 항목), `__text` 887 B(= 원본 [0x185a8c, 0x185e03))·재배치 21, `__TEXT,__const` 172 B 0x1d13f4·`__DATA,__data` 15 B 0x1e1716 추정·L1d 일치. 변형 1 회.
- 경계: 앞 0 B 이나 그 앞 0x185a8b 가 `90`(`_vol_check_set_poll` 은 0x1859d8 에서 `ret`, 0x1859dc 부터 이름 없는 함수가 `jmp` 0x185a86 + `90` 으로 끝남 — 소유 미증명, 80.1 정정), 뒤 `00` 1 B(확정 miniMonMachdep 0x185e04).

설계(W2–W6): `07_kernel/src/machdep/i386/kdp_machdep.c` = Darwin 원문 + 작성 2 함수(각 앞에 W3 표시 주석) + 머리말 뒤 수정 주석. MODIFICATIONS("authored", 근거 주소 0x185dc0·0x185dd4), PROVENANCE("authored lines"), functions.tsv 해당 2 함수 `darwin01+authored`. 07 빌드 예측: 탐침 2 SHA. 등급 **A\***(앞 틈 값이 `00` 이 아닌 `90`, vm_pager 선례).

### 80.1 codex 교차검토(QR8) 판정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| pcb 보류 타당: 원본 0x18ebb5 `movsx eax, word [eax+0x30]`; D018 은 Darwin 에 없는 헤더만 공급, BSD 기준 판 교체는 아님 | 80 절 ndiff·proc.h 세 판 줄 | ✅ |
| 스테이징 diff 는 래퍼 2 개 추가뿐; L1 OBJECT_MATCH, 887 B·재배치 21, `__const` 172 B 는 참조 3, `__data` 15 B 는 참조 1 로 배치·L1d 일치 | 탐침 2 출력 | ✅ |
| **"16/16" 은 함수 15 + `__const` 섹션 시작 항목** | — | ✅ 정정 |
| **O2 는 다름**(695 B, NOT_MATCH) — O3 = O3c 만 | 탐침 2 SHA(`O2 7d671d0a…` ≠ `0df7708d…`) | ✅ **내 오류** — 정정 |
| 래퍼·W1 통과(원본 호출 0x185dcb→0x1aad8c, 0x185de3→0x1aad58; 세 참조 트리에 정의 없음) | 80 절 capstone·grep | ✅ |
| **앞 경계 과장**: `_vol_check_set_poll` 은 0x1859d8 `ret`, 0x1859dc 부터 다른 함수가 0x185a86 `jmp` + `90` — `90` 의 소유 미증명 → A\* | capstone(0x1859d8 `ret`, 0x1859dc `push ebp`, 0x185a86 `jmp`, 0x185a8b `nop`) | ✅ **내 오류** — 등급 A\* |
| 뒤 경계 통과, 다만 miniMonMachdep 은 P | objects_partial.tsv:6 | ✅ 문구 정정 |
| 암시 선언은 선례대로 허용, 인자 형은 IOEthernetDebugger.m 에서 — 바이트가 형을 증명하지 않음; W3 표시·기록 | — | ✅ |
| **W5 미흡**: 탐침 예측에 재배치 수 없음, "`__const` 4 B possible" 은 틀린 예측(실제 172 B) | `s5p53-probe2.cmd:1` | ✅ 예측 불일치 기록, 채택 빌드 예측: 887 B·재배치 21·`__const` 172 B·`__data` 15 B·O3 = O3c `0df7708d…` |

### 80.2 결과 (2026-10-02) — `kdp_machdep.c` 확정(A\*, 래퍼 2 개 작성)

- 07_kernel `machdep/i386/kdp_machdep.c` = Darwin + 작성 2 함수(W3 표시) + 수정 주석; `.i` 로 확정한 Darwin 헤더 24 개 원문(BSD 네트워크 헤더 포함 — 79.2 결정 후 바뀔 수 있음을 증거에 명기).
- 빌드 `s5p53-build-1`: 예측대로 O3 = O3c `0df7708d…`, O2 `7d671d0a…`, 887 B·재배치 21·`__const` 172 B·`__data` 15 B, 두 `.i` 동일, OBJECT_MATCH → **A\***(앞 틈의 `90` 소유 미증명).
- 기록: objects_confirmed +1(63 객체), functions.tsv +15(작성 2 는 `darwin01+authored`), MODIFICATIONS +1, PROVENANCE +25(308 행), 증거·diff.

## 81. S5-P55 세부 계획 — 옵션 `UXPR`·`XPR_DEBUG` 추가, Darwin `driverkit-1` 헤더 루트 추가, 70 객체 회귀 (코딩 전, 2026-10-02)

사실(실행 ID `s5p54-*`):
- `kern/xpr.h:112–114` 가 `KERNEL_BUILD` 에서 `<uxpr.h>`·`<xpr_debug.h>`(config 옵션 헤더, `conf/files:67`·`:75`)를 import — vm_resident·vm_object·kern_clock·ddm 등이 여기서 막힘. `MASTER.i386:92` `UXPR <uxpr>`, `MASTER:142` `XPR_DEBUG <xpr_debug>`; RELEASE 태그(`MASTER.i386:72`)에 `uxpr` 있고 `xpr_debug` 없음(DEBUG 태그 :74 에만). `conf/files:529` `driverkit/ddm.c optional uxpr` 가 정의하는 `_uxprGlobal`(0x1f74c0)·`_xpr_lock`(0x1f74d0)·`_xprLocked`(0x1e13a0)가 원본에 있음.
- 탐침 `s5p54-pre-1`(스테이징에 UXPR 1·XPR_DEBUG 0): 옵션 헤더는 해결되나 다음이 `driverkit/ddmPrivate.h`·`driverkit/Device_ddm.h`(vm_resident·kern_clock·ddm, `machdep/i386/xpr.h:57–58` 경유)와 `norma_vm.h`·`mach_pagemap.h`(vm_object) 에서 막힘. 앞의 둘은 Darwin `driverkit-1/driverkit/` 에 있음(Darwin 빌드에서는 driverkit 프로젝트가 설치한 시스템 헤더 — 지금 스테이징 루트 밖). 현재 회귀 70 객체의 스테이징에는 미해결 `driverkit/…` 이름 없음.

설계:
1. `config_options.tsv`: `uxpr` UXPR 1 hypothesis(RELEASE `uxpr`, ddm.c 의 전역 3 개 원본 존재), `xpr_debug` XPR_DEBUG 0 hypothesis(RELEASE 에 없음). 생성·`--check`.
2. `stage_headers.py`: 루트에 Darwin `driverkit-1`(그 아래 `driverkit/…`) 을 기존 Darwin 루트 뒤·`--nextdev` 루트 앞에 추가(논리 경로 `components/driverkit-1/…` 대신 별도 접두 `driverkit/…` 매핑은 기존 `components` 루트(= darwin01)로 이미 가능한지 먼저 확인 — `-Isrc/components` 가 darwin01 이므로 `driverkit/x.h` 는 `components/driverkit/x.h` 를 찾음 → 없음; 따라서 새 루트 `components/driverkit-1` 와 빌드 `-Isrc/components/driverkit-1` 를 추가). 기본 동작 변화는 회귀 manifest 로 확인.
3. 회귀: 확정 63 + 부분 8 = 71 객체… (정확한 수는 표 기준)를 각 확정 명령으로 다시 빌드, 전부 동일 예측.
4. 그다음 vm_resident·kern_clock·ddm·vm_object 를 다시 진단(결과 기록; 채택은 다음 회차).

### 81.1 codex 교차검토(QR9) 판정 → 설계 확정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| 옵션 근거 맞음(files:67 = xpr_debug, :75 = uxpr). **`XPR_DEBUG=0` 의 원본 바이트 근거: 0x184964 `call _IOMalloc`** = `driverkit/ddm.c:100–111` 의 `#else XPR_DEBUG` 분기; `_IOAddDDMEntry` 는 있으나 직접 호출·점프·절대 주소 0 | capstone(0x184964 → `_IOMalloc` 0x1a5448), ddm.c 100–112 열람 | ✅ 근거 추가(객체 일치 전이므로 hypothesis 유지) |
| 기존 확정·부분 객체의 닫힘에 `uxpr.h`·`xpr_debug.h`·두 매크로 없음; 다만 `meta_features.h` 가 모든 빌드에 정의를 들임 | — | ✅ 회귀로 확인 |
| **회귀는 71 객체**(63 + 8) — `s5p49-regress.cmd` 67 에 strtol·catch·fp_support·kdp_machdep 추가 | 표 행 수 Python(71) | ✅ 정정 |
| driverkit 헤더는 `driverkit-1/driverkit/Makefile:14–15` 의 PrivateHeaders 로 설치, 커널은 `Makefile.template:90` 에서 검색 → Darwin 루트로 추가하고 NeXT 루트 앞이 맞음; 겹치는 이름 46 개는 Darwin 우선 | Makefile:14–15 열람 | ✅ |
| **정확한 매핑**: `ROOTS` 에 `os.path.join(D01, 'driverkit-1')` 추가(NeXT 루트 앞), 기존 `D01 ↔ components` 대응으로 논리 경로 `components/driverkit-1/driverkit/…`, 빌드 `-Isrc/components/driverkit-1` 를 Darwin `-I` 뒤·nextdev 앞 | stage_headers.py 45–72 | ✅ 설계 2 를 이것으로 교체 |
| 메모리 안 시험: 루트 추가로 67·71 소스 모두 파일 선택·미해결 목록 변화 없음 | — | ✅ 실제 회귀로 재확인 |

### 81.2 결과 (2026-10-02) — 옵션 `UXPR`·`XPR_DEBUG` 추가, driverkit-1 루트, 회귀 71/71

- `config_options.tsv` 24→26 행(`uxpr` 1, `xpr_debug` 0, 둘 다 hypothesis), 생성·`--check` 통과.
- `stage_headers.py`: `ROOTS` 끝(nextdev 앞)에 `darwin01/driverkit-1`(논리 `components/driverkit-1/…`, 빌드 `-Isrc/components/driverkit-1`).
- 회귀 `s5p54-regress-1`(확정 63 + 부분 8, 각 확정 명령): **71/71 동일**.
- 재진단 `s5p54-pre-2`: vm_resident·kern_clock·ddm 컴파일, vm_object 는 `norma_vm.h`·`mach_pagemap.h`(옵션 미정) 로 실패. vm_resident(4345 대 ≤4140)·kern_clock(1146 대 ≤820) 크기 다름. **ddm.c**: `__text` 618 B 바이트 차이 0, 원본 [0x18494c, 0x184bb6) 함수 7 중 4 MATCH + 3 MATCH_UNVERIFIED(`__bss` 20 B 의존), `__TEXT,__const` 12 B 미배치, `__data` 74 B 심볼 배치 일치 — 다음 회차 후보(P 판정 절차, `XPR_DEBUG=0` 의 객체 단위 근거).

## 82. S5-P56 세부 계획 — `driverkit/ddm.c` 채택(등급 P) (코딩 전, 2026-10-02)

사실(실행 ID `s5p55-*`; 탐침은 Darwin 원문, UXPR 1·XPR_DEBUG 0, `-Isrc/components/driverkit-1`):
- 탐침 1: O3 `fc557038…`(= 81.2 진단), O3c `af1e2c09…`, O2 다름; 두 `.i` 동일. 섹션: `__text` 618 B·재배치 41, `__bss` 20 B(정적 `xxx` 3 개 — `io_inline.h` 의 `outb/outw/outl` 더미 — 와 `xprEnd`·`xprInitialized`), `__TEXT,__const` 12 B `40 00 00 00 41 00 00 00 42 00 00 00`(정적 `_timer_cnt_port_`, 들어오는 재배치 0), `__data` 74 B(`_xprLocked` 심볼 배치·L1d 일치), `-fno-common` 판 `__common` 36 B.
- 원본 [0x18494c, 0x184bb6) 618 B, 함수 7(모두 원본 심볼). L1(O3·O3c): 4 MATCH + 3 MATCH_UNVERIFIED(`_IOInitDDM`·`_IOAddDDMEntry`·`_IOClearDDM` — `__bss` 에만 의존), 바이트·참조 차이 0; 객체 NOT_MATCH 사유는 `__bss`·`__const` 미검증뿐.
- `__bss`: `zerofill_check.py`(known `zerofill-known-s5p55-20261002.json` = s5p50 + fp_support [0x1e75f8, 0x1e75fc)) — 참조 5(대상 오프셋 12·16), Δ 0x1e72b0 하나, 후보 [0x1e7574, 0x1e7588) 정렬·zero-fill 안·심볼 없음·겹침 없음, 음성 검사 검출 → **reference-inferred**(오프셋 0–12 의 `xxx` 는 참조 없음, 섹션 연속성으로만).
- 36.1: common `_IODDMMasks` 16/16, `_uxprGlobal` 16/16, `_xpr_lock` 4/4(크기/간격); `__text` 재배치 41 곳 위치·폭·pcrel·유형 동일(같은 종류 19, local→extern 8, scattered→extern 14), 재배치 밖 바이트 차이 0; `__data` 재배치 없음·동일.
- 경계: 앞 0 B(`ret` 0x18494b, `_sgioctl` 쪽), 뒤 `00 00`(`_volopen` 0x184bb8).

설계: `07_kernel/src/driverkit/ddm.c` = Darwin 원문; `.i` 로 07 에 없는 헤더 원문 채택(Darwin `driverkit-1` 헤더는 `07_kernel/components/driverkit-1/…` — `--prefer-07` 의 논리 경로 대응). 07 빌드 예측: O3 `fc557038…`, O3c `af1e2c09…`. 최종 객체로 zerofill_check 재실행. 등급 **P**(`__TEXT,__const 12 B unreferenced` + `__DATA,__bss 20 B reference-inferred`), functions.tsv 7 행(4 high, 3 medium). 옵션 UXPR·XPR_DEBUG 는 hypothesis 유지(`_IOInitDDM` 은 바이트 일치이나 MATCH_UNVERIFIED).

### 82.1 codex 교차검토(QR10) 판정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| 원문·`.i`·O3/O3c SHA 일치; `__const` 는 `timer_inline.h:83` 의 정적 `_timer_cnt_port_`(객체 심볼 `__timer_cnt_port_`), 들어오는 재배치 0 | 82 절 출력, grep(timer_inline.h:82–83) | ✅ |
| L1 4 MATCH + 3 MATCH_UNVERIFIED(`__bss` 만), 범위 키 7/7 | 82 절 출력 | ✅ |
| zero-fill 5 참조(오프셋 12·16)·Δ 하나·검사 통과; [0,12) 는 연속성으로만; 가장 가까운 기록 구간(miniMonMachdep)과 24 B 떨어짐 | 82 절 출력 | ✅ |
| 36.1 대응(41 = 19 + 8 + 14, 이름·가산값 대응, 밖 차이 0); **문자 그대로의 36.1(b) OBJECT_MATCH 는 미충족** — dma 선례로 common 참조 검증만 옮김 | 36.1(:1269), dma 증거 | ✅ 증거에 명시 |
| 경계 성립; objects.tsv 하한 0x18447c 는 앞 구간 끝일 뿐, `debugging.m` 은 다른 후보 소스이지 앞 객체 증거 아님; `_IOInitDDM` 이 객체 오프셋 0 | 82 절 출력 | ✅ |
| P + high 4 / medium 3 | README:20–24 | ✅ |

### 82.2 결과 (2026-10-02) — `ddm.c` 등급 P

- 07_kernel: `driverkit/ddm.c` 원문 + `.i` 로 확정한 헤더 20(`components/architecture/arch_types.h`, `components/driverkit-1/driverkit/` 7, Darwin kernel 12) 원문.
- 빌드 `s5p55-build-1`: 예측대로 O3 `fc557038…`, O3c `af1e2c09…`, 두 `.i` 동일, 4 MATCH + 3 MATCH_UNVERIFIED, 최종 객체 zerofill reference-inferred → **P**.
- 기록: objects_partial +1(9 객체), functions.tsv +7(high 4·medium 3), PROVENANCE +21(329 행), 증거 `x86-ddm.md`.

## 83. S5-P57 세부 계획 — D020(BSD 기준 = NeXTMach) 적용 1 단계: `stage_headers.py --bsd-next` (코딩 전, 2026-10-02)

사실(실행 ID `s5p56-*`; Python):
- NeXTMach mk-108.1 은 68k 판: `machine -> next`(심볼릭 링크). 실기 SDK `NextDeveloper/Headers/bsd/` 는 같은 계열(79.2: 구조체 13 중 10 이 NeXTMach 와 같음)의 OPENSTEP 4.2 **i386** 판(`bsd/i386/`, `bsd/machine/` 은 ARCH_INCLUDE)이며 .h 319 개.
- SDK `bsd/` 의 이름 중 Darwin `kernel/` 최상위(kern·mach·vm 등) 와 겹치는 것 0, Darwin `machdep/machine` 과 겹치는 것 0; Darwin `bsd/machine` 과 겹치는 것 14(`machine/{cons,cpu,endian,label_t,psl,reboot,reg,signal,spl,table,types,unix_traps,user,vmparam}.h`).
- NeXTMach `sys/` 94 개 중 SDK `sys/` 73 개에 없는 것 25(`sys/{boolean,exception,features,host_info,kern_return,linedisc,loader,mach_extra,machine,message,mig_errors,msg_type,notify,policy,port,processor_info,table,task_info,task_special_ports,thread_info,thread_special_ports,thread_status,thread_switch,time_stamp,time_value}.h`) — 대부분 Mach 호환·커널 내부.
- 탐침 `s5p56-probe-1`(pcb.c 스테이징의 Darwin `bsd/sys/proc.h` 를 SDK 판으로 바꿔치기): SDK `proc.h:222–223` 의 `sys/user.h`·`kernserv/lock.h` 를 찾지 못해 실패 — 스테이징 닫힘을 SDK 판 기준으로 다시 계산해야 함(도구 지원 필요).

해석(D020 적용 방식, codex 검토 대상): 헤더는 **SDK(OPENSTEP 4.2 i386, NeXTMach 계열)** 를 우선하고, SDK 에 없는 BSD 이름은 **NeXTMach** 에서, 둘 다 없으면 지금처럼 Darwin. 소스(.c)의 NeXTMach 판 채택은 객체별 계획에서.

설계:
1. `stage_headers.py --bsd-next`(`--nextdev` 와 함께만): 루트 순서를 `GEN, KERNEL, [SDK bsd], [NeXTMach(이름의 첫 구성요소가 sys·net·netinet·nfs·ufs·specfs·rpc·rpcsvc·nextif·netns·netimp·krpc 일 때만)], Darwin bsd, bsd/include, machdep, darwin01, architecture, driverkit-1, nextdev 루트` 로. 논리 경로: SDK 는 기존 `nextdev/bsd/…`, NeXTMach 는 새 접두 `nextmach/…`(07 우선은 `07_kernel/nextmach/…`). SDK 파일은 기존 실기 SHA 검사, NeXTMach 파일은 저장소 커밋(`f6bdb9c…`)·경로로 manifest 기록. 빌드 `-I`: `-Isrc/src` 다음에 `-Isrc/nextdev/bsd -Isrc/nextmach` 를 넣고 나머지는 그대로. 플래그 없으면 동작 그대로(기존 회귀 소스 71 개 스테이징이 바이트 동일한지 확인).
2. 시험: pcb.c 를 `--bsd-next` 로 진단(07 변경 없음) — `.i` 에서 `proc.h` 출처가 SDK 인지, `_thread_dup` 이 원본(`movsx word [proc+0x30]`)과 맞는지.
3. 이번 회차에는 객체 채택 없음(도구·시험·기록).

### 83.1 codex 교차검토(QS1) 판정 → 설계 교체(전역 루트 재배치 폐기)

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| 83 절 사실(68k 링크, 319, 겹침 0/0/14, 25 개 목록, 탐침 실패 줄) 맞음 | 83 절 Python 출력 | ✅ |
| SDK 우선은 D020 의 귀결이 아니라 후보 정책 — D020 은 객체별 바이트 근거를 요구 | DECISIONS D020 | ✅ |
| **SDK 헤더 일부는 커널 부분이 빠짐**: `sys/ux_exception.h`(SDK 52 줄 대 N 64), `sys/callout.h`(SDK `#if NeXT` 에서 구조체·전역 없음, :22), `sys/kernel.h`(SDK 에 `boottime`·`time`·`phz` 없음, N:68–76) | wc·sed·grep 출력 | ✅ "이름이 없을 때만 대체" 규칙 폐기 |
| **2 차 해석 누출**: SDK `machine/user.h:11` `ARCH_INCLUDE(bsd/, user.h)` → `bsd/i386/user.h` 가 `KERNEL` 루트(Darwin `kernel/bsd/i386/user.h`)로 해석 | sed·ls 출력 | ✅ 전역 재배치 폐기 |
| NeXTMach 대체 헤더도 전역 루트를 따라 SDK/Darwin `machine/…` 을 받음(68k 판 아님), 일부는 미해결 | — | ✅ |
| 인용 상대 경로 우선 유지, `ARCH_INCLUDE` 는 실제로 인용 형식 문자열 — 시험 필요 | stage_headers.py:134–138 | ✅ |
| NeXTMach 출처: `https://github.com/johnsonjh/NeXTMach.git` `f6bdb9c…`, 작업 트리 바이트를 그 커밋 객체와 대조할 것 | `git rev-parse HEAD` 출력 | ✅ |
| 플래그 끈 동작 동일성은 구현 후 다시 확인; pcb 는 `.i` 출처·L1 로 판정 | — | ✅ |

교체 설계(코딩 전 재검토 QS1b 대상):
1. 전역 루트는 그대로 둔다. `stage_headers.py --subst MAP.json`: MAP 은 `{논리 경로: "sdk:<Headers 상대>" | "nextmach:<mk-108.1 상대>"}`. 닫힘 계산에서 그 논리 경로를 고를 때 대응 파일을 대신 쓰고(그 파일의 include 는 평소대로 해석 — 필요하면 그 이름도 MAP 에 명시), 스테이징은 같은 논리 경로(예: `src/bsd/sys/proc.h`)에 그 내용을 둔다 → 빌드 `-I` 변경 없음. MAP 키는 Darwin 에 없는 이름도 허용(예: `src/bsd/sys/thread_switch.h`).
2. 검증: SDK 대체 파일은 실기 SHA 목록과 일치, NeXTMach 대체 파일은 `git -C … cat-file -p f6bdb9c:mk-108.1/<경로>` 바이트와 일치해야 스테이징. manifest 행에 출처(실기 경로·SHA 또는 저장소 URL·커밋·경로·SHA), "license TBD (D017)"/NeXTMach 고지 기록.
3. `--prefer-07` 와의 관계: 07 에 같은 논리 경로 파일이 있으면 07 이 우선(채택 후에는 07 이 기준) — MAP 은 아직 채택 안 된 이름에만 의미.
4. 시험: (a) MAP 없으면 71 회귀 소스 스테이징 바이트 동일; (b) 작은 MAP 으로 `--list` 결과가 기대대로 바뀌는지; (c) pcb.c 를 `{src/bsd/sys/proc.h: sdk:bsd/sys/proc.h}` 로 시작해 컴파일 실패 원인을 하나씩 MAP 에 더하는 진단(변형 기록), `.i` 출처·`_thread_dup` L1 로 판정. 객체 채택은 이번 회차 없음.

### 83.2 codex 교차검토(QS1b, 83.1 교체 설계) 판정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| `closure()` 는 실제 파일만 `order` 에 남기고(`stage_headers.py:127`), 스테이징 이름은 `staged_name(f)`(:174)로 실제 경로에서 다시 계산 → MAP 대상 논리 경로가 사라짐 | 파일 열람 :107–146, :173–179 | ✅ `(논리, 실제)` 쌍을 끝까지 유지 |
| `ARCH_INCLUDE` 는 문자열을 만드는데 스캐너는 `q='<'` | `ARCH_INCLUDE.h:29–30`(`#prefix __TARGET_ARCHITECTURE__ "/" #suffix`), 스캐너 :134(codex 는 :132 라 했으나 :132 는 `elif`) | ✅ 인용 형식으로 수정, 기존 회귀 스테이징 동일성으로 확인 |
| 2 차 해석은 MAP 에 명시해야 함(`machine/user.h` 만으로 부족) | 83.1 표 | ✅ |
| 07 우선이 MAP 을 조용히 가릴 수 있음 → 충돌은 거부 | :78–86 `select` | ✅ `--prefer-07` 이고 `07_kernel/<키>` 가 있으면 오류 |
| "differs from" 표시가 `prefer07` 조건에 묶임 | :181 | ✅ 대체 행은 Darwin 대비 차이를 따로 기록 |
| NeXTMach `machine` 은 심볼릭 링크(`next`), `cat-file …:mk-108.1/machine/user.h` 실패 | `git ls-tree`: `120000 … mk-108.1/machine`, 내용 `next`; cat-file `fatal: Not a valid object name` | ✅ 심볼릭 링크 경로 거부 |
| NeXTMach 작업 트리 HEAD 가 `f6bdb9c…`, `proc.h` 는 LF | `git rev-parse HEAD`, `ls-files --eol` → `i/lf w/lf` | ✅ 바이트 비교(정규화 없음) |
| SDK SHA 목록에 `bsd/sys/proc.h` 있음(:1075) | json 로드: `5eda0a5a…`, 크기 20390; grep 1075 행 | ✅ 원 SDK 경로로 검사, 없으면 거부 |
| `--list` 가 검증을 건너뜀 | :158–164 | ✅ MAP 검증은 `--list` 전에도 수행 |
| 키 범위 제한·경로 탈출·디렉터리 대상 거부, 같은 원본 두 번 허용 | — (설계 요구) | ✅ 시험 항목으로 반영 |
| `.i` 의 경로는 논리 경로만 보여 줌 → manifest·MAP 해시와 묶어야 | — | ✅ manifest 에 MAP 경로·SHA 기록 |

구현 결정: `--subst` 는 `--nextdev` 와 함께만(SDK 파일이 `ARCH_INCLUDE` 를 씀). NeXTMach 허용 첫 구성요소: sys·net·netinet·nfs·ufs·specfs·rpc·rpcsvc·nextif·netns·netimp·krpc. 키는 `src/bsd/…` 만.

### 83.3 결과 (S5-P57, 2026-10-02)

- 도구: `stage_headers.py --subst MAP.json`(sha256 `d346dfce2633b06b…`). `closure()` 는 `(논리 경로, 실제 파일)` 쌍을 돌려주고, 스테이징·manifest 는 논리 경로를 그대로 쓴다. `ARCH_INCLUDE` 는 인용 형식으로 해석한다. MAP 검증은 `--list` 전에도 한다. 대체 행은 `substituted: …` 와 `replaces <Darwin 출처> sha256 …`(또는 `no Darwin file`)을 기록하고, manifest 에 `subst`(MAP 경로·SHA·항목)를 둔다.
- 기본 동작 동일성: 회귀 71 개 + ddm 을 합친 72 개 소스를 `--prefer-07 --nextdev` 로 옛 도구와 새 도구에서 각각 스테이징해 비교했다. 파일 368 개 트리 바이트, manifest JSON, `--list` 출력이 모두 같다.
- 시험 `test_stage_headers_subst.py`(sha256 `7d4b59c6cb3de70b…`): 19/19 통과. 기존 `test_sect_of` 7/7, `test_struct_compare` 9/9 도 통과.
  - 거부 시험: `--nextdev` 없음, 키가 `src/bsd` 밖, 키·원본 경로 탈출, 절대 경로, Darwin 디렉터리 키, 키 충돌, 중복 키, 알 수 없는 스킴, 실기 목록에 없는 SDK 이름, NeXTMach 허용 밖 디렉터리(`machine`), 없는 NeXTMach 파일, 07 가림(`sys/callout.h`), 심볼릭 링크 경로.
  - 정상 시험: 스테이징 바이트, manifest 행, 쓰이지 않는 키는 스테이징 안 됨.
  - ARCH 2 차 해석: SDK `machine/user.h` 만 대체하면 `src/bsd/i386/user.h` 는 Darwin 판이고, 그 이름까지 대체하면 SDK 판이다.
- pcb.c 진단(객체 채택 없음, 실행 ID `s5p57-probe-1…3`).
  1. MAP `{proc.h: sdk}`(`s5p57-subst-sdk.json`): 스테이징 195, 컴파일 실패. SDK `proc.h:222` → Darwin `sys/user.h:75` → Darwin `sys/sysctl.h:215·219` 에서 `kp_proc`·`e_pcred` 가 불완전 형이다.
  2. MAP `{proc.h, sys/boolean.h: nextmach}`(`s5p57-subst-nextmach.json`): 실패. NeXTMach `sys/boolean.h:26` 의 `machine/boolean.h` 가 없다. NeXTMach `machine` 은 68k `next` 를 가리키는 심볼릭 링크라 허용하지 않는다.
  3. MAP `{proc.h, sys/user.h: sdk}`(`s5p57-subst-p3.json`): 실패. SDK `sys/user.h:72·230` 의 `label_t` 는 SDK `sys/types.h:94` 의 `bsd/machine/label_t.h` 에서 오지만, Darwin `sys/types.h` 에는 `label_t` 가 없다.
  4. `sys/types.h` 를 추가한 MAP(`s5p57-subst-p4.json`)은 도구가 거부했다: `07_kernel/src/bsd/sys/types.h` 는 이미 채택된 Darwin 판이다(PROVENANCE 행 있음). 확정 객체들이 이 헤더로 일치를 냈으므로 바꾸면 그 객체들과 충돌할 수 있다.
  - 결론: 이름 단위 대체는 BSD 헤더 연쇄(proc → user → types)로 번지고, 채택된 07 헤더에서 멈춘다. pcb 는 다음 회차에 계획을 새로 세운다. 후보는 (a) 객체별 최소 수정(D014)으로 Darwin `proc.h` 의 `p_pid` 앞쪽 배치를 원본에 맞추는 방안, 이때 다른 필드 오프셋 근거가 필요하다. (b) BSD 헤더 집합을 객체별로 통째로 바꾸고 별도 스테이징 접두를 쓰는 방안. 어느 쪽이든 원본 오프셋 전수 근거가 먼저다.
- 알려진 도구 한계(기존 기록과 같음): 실패한 실행은 `stage/.nfsNNNN` 때문에 `kr_run.py collect` 가 `krsha256: read error` 행에서 `ValueError` 를 낸다(probe-2). 게시는 원래도 거부되므로 결과에는 영향이 없다.

## 84. S5-P58 세부 계획 — D019 를 `zerofill_check.py` 에 반영하고 `kern/kalloc.c`(61 절 보류분) 채택 (코딩 전, 2026-10-02)

사실(61·61.2 절, `06_reconstruction/evidence/x86-kalloc.md`):
- 원본 [0x15a67c, 0x15ab9b) 1311 B, 10 함수. 앞 0 B, 뒤 `00` 1 B 이고, 다음 `_initKernelStacks` 는 0x15ab9c 이다.
- 탐침 4(`s5p36-probe-4`): O3c 는 9 MATCH 에 `_kalloc_init` MATCH_UNVERIFIED 1 개. 남은 것은 `__bss` 256 B 하나다.
- zerofill 결과(`s5p36-zerofill-check-kalloc-pre-20261001.json`): 참조 1, Δ 1 개(`0x1e5529`), 후보 [0x1e5a98, 0x1e5b98), 다른 검사는 모두 참, `negative_check.detected = false` 라서 `fail`.
- D019(사용자 확정): 이 경우는 `reference-inferred-single` 이다. 등급은 P 까지, 그 섹션에 의존하는 함수는 medium.

설계:
1. `zerofill_check.py`: 결론이 `fail` 이 되는 원인이 "참조 1 개 + 음성 검사 미검출" 뿐일 때만 `reference-inferred-single` 로 바꾼다. 조건은 다음을 모두 만족하는 것이다.
   - `problems` 가 비어 있다.
   - Δ 가 1 개다.
   - `references == 1` 이다.
   - 다섯 검사(aligned, inside_zero_fill_image_section, image_symbols_inside 없음, overlaps 없음, field_targets_in_range)를 모두 통과한다.
   - `negative_check.detected == false` 다.

   다른 경우의 결론은 그대로 둔다. 확인 방법:
   - 기존 `reference-inferred` 결과 파일들을 같은 명령으로 다시 돌려 결론이 같은지 본다.
   - 탐침 4 O3c 는 `reference-inferred-single` 이 나와야 한다.
   - 참조가 2 개 이상인데 음성 검사가 실패하는 경우는 계속 `fail` 이어야 한다(합성 시험).
2. `07_kernel/src/kern/kalloc.c`: 탐침 4 스테이징 사본(`s5p36-probe-stage-4/src/kern/kalloc.c`)에 다음을 더한다.
   - D014 머리말 뒤에 `/* Modified 2026-10-02: … */` 를 넣는다.
   - 작성 ①②③ 각 줄 앞에 W3 표시 주석을 넣는다.
   - NeXTMach 블록 앞에는 출처 주석을 넣는다(필요하면).

   주석만 더하므로 목적 코드는 바뀌지 않아야 한다. 단 `__LINE__` 사용이 없다는 것을 확인하고, `meta_features.h` 변경(UXPR 등) 영향은 빌드로 확인한다.
3. 빌드 `s5p58-build-1`: O3, O3c, O2, `.i` 두 개(5 명령, 표준 템플릿). **예측**:
   - O3 `d87a52ac…`, O3c `126e1a24…` 로 탐침 4 와 같다.
   - 두 `.i` 는 같다.
   - L1: O3c 는 9 MATCH 와 `_kalloc_init` MATCH_UNVERIFIED(`__bss`), O3 는 36.1 절차 대상(`__common` 72 B).
4. 판정:
   - 36.1 공통 절차. 두 `.i` 가 같아야 하고, 재배치가 대응해야 하며, 재배치 밖 바이트가 같아야 한다. common 크기는 원본 간격 이하여야 한다(`_k_zone` 64≤64, `_k_zone_maxsize` 4≤16, `_kalloc_map` 4≤16, 다시 계산).
   - 경계 증명서: 뒤 1 B 는 4 정렬 최소 채움이고 값이 00 이어야 한다.
   - zerofill: 알려진 범위 `zerofill-known-s5p55-20261002.json` 으로 → `reference-inferred-single`.

   위가 모두 성립하면 등급 P(`unverified_sections` = `__DATA,__bss` 단일 참조, 행에 "단일 참조" 명시)다. 함수는 `_kalloc_init` 가 medium, 나머지 9 개가 high 다. 단 9 개 각각이 `__bss` 에 의존하지 않는지 재배치로 확인한다.
5. 기록:
   - PROVENANCE 행: Darwin 과 NeXTMach 출처, CMU 고지, authored lines.
   - MODIFICATIONS 행: restoration edit 과 authored, 근거 주소.
   - 표: objects_partial, functions 10 행.
   - 증거 파일 갱신, `.i` 채택 검사.
   - 새 알려진 범위 파일 `zerofill-known-s5p58-20261002.json` = s5p55 15 개 + [0x1e5a98, 0x1e5b98) "kalloc k_zone_name (single)" 로 16 개.
   - 다른 객체 재판정은 없다.

### 84.1 codex 교차검토(QS2) 판정 → 계획 보강

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| kalloc 탐침 기록은 다섯 조건 + 음성 미검출에 해당(참조 1, problems 없음, base_offset 없음) | `s5p36-zerofill-check-kalloc-pre…json`: references 1, problems [], base_offsets [], field_target_offsets [0], checks 모두 참, detected false | ✅ |
| `references` 는 받아들인 기록만 셈 — 지원 안 되는 재배치는 `problems` 로만 걸러짐 | `zerofill_check.py` `infer()` :58–96(PAIR/SECTDIFF → problems, 배치 없는 출발 섹션 → problems) | ✅ 조건에 `problems` 비어 있음 포함(이미 있음) |
| `field_targets_in_range` 는 pc-relative 아닌 필드만, scattered `base_offset` 은 범위 검사 안 함 | :125(`field_target_offsets` 는 `not r['pcrel']` 만), base_offset 은 기록만 | ✅ **단일 판정은 그 한 기록이 scattered 아님·pcrel 아님(필드 목표가 범위 검사됨)일 때만** 으로 좁힘 |
| 섹션별 적용, 미검증 섹션 모두가 자격을 갖춰야 P | README:24 P 정의 | ✅ (kalloc O3c 미검증은 `__bss` 하나뿐 — L1 JSON 확인) |
| `meta_features.h` 에 import 8 개 추가됨 → SHA 예측은 잠정, `.i` 는 옛 것과 다를 수 있음 | `diff` 출력: `fp_emul.h`·`mach_kdb.h`·`mach_nbc.h`·`norma_ether.h`·`pc_support.h`·`uxpr.h`·`xpr_debug.h` (7 개; codex 는 개수 미언급) | ✅ SHA 가 다르면 L1 전에 `.i` 차이부터 분석 |
| `_kalloc_init` 만 섹션 3 미검증, 나머지는 섹션 2 만(또는 없음) | L1 JSON `functions[*].data_sections` 출력: 첫 함수 {2 ok, 3 unverified}, 8 개 {2 ok}, 마지막 {} | ✅ 함수별 의존 표를 증거에 남김 |
| README 의 medium·P 정의가 `reference-inferred-single` 을 받아들이지 않음 | README:21 "그 검사가 실패하면 이 분류를 쓰지 않는다" | ✅ README 를 D019 대로 고침 |
| W3 표시는 realloc 두 분기·free 선언/검사/대입 각각 | 스테이징 kalloc.c realloc/free 본문 열람 | ✅ 바뀐 줄 묶음마다 표시 |
| NeXTMach 고지(1987 CMU "software License Agreement", 1985 Avadis Tevanian) 필수 — 스테이징에는 없음 | NeXTMach `kern/kalloc.c:1–11`; 스테이징에서 `License Agreement` grep 0 건, `Avadis` 는 :52 Darwin 머리말의 Author 줄뿐 | ✅ NeXTMach 블록 앞에 고지 원문 주석 |
| W5: 크기·재배치·호출 예측 | 탐침 4 O3 Python 파싱 | ✅ 아래 예측 |

빌드 예측(W5, 탐침 4 Python 파싱): `__text` 1311 B·재배치 95, `__data` 79 B, O3 `__common` 72 B, `__bss` 256 B; 함수 오프셋 `_kalloc_init` 0, `_kalloc_noblock` 112, `_kalloc` 224, `_kget` 336, `_kfree` 424, `_malloc` 516, `_calloc` 660, `_realloc` 812, `_free` 1204, `_malloc_good_size` 1304; 미정의 14: `_bcopy _bzero _kernel_map _kmem_alloc_wired _kmem_alloc_zone _kmem_free _page_size _panic _sprintf _zalloc _zalloc_noblock _zfree _zget _zinit`.

### 84.2 결과 (S5-P58, 2026-10-02) — `kalloc.c` **P**(단일 참조)

- 도구: `zerofill_check.py` 에 `conclude()` 를 두었다. `reference-inferred-single` 은 84.1 조건일 때만 나온다: 음성 검사 전 검사 모두 통과, 기록 1 개, 그 기록이 scattered·pcrel 아님, 음성 미검출. 시험 `test_zerofill_conclude.py` 8/8 통과(참조 2 개·scattered·pcrel·다른 검사 실패는 모두 `fail`). 저장된 zerofill 결과 14 개를 같은 명령으로 다시 돌렸다. kalloc 탐침 결과의 `conclusion` 만 `fail` → `reference-inferred-single` 로 바뀌고, 나머지 13 개는 모든 필드가 같다.
- `07_kernel/src/kern/kalloc.c`: 탐침 4 본문에 주석만 더했다(Modified 1, NeXTMach 고지 1, W3 표시 5). 주석을 빼면 스테이징과 바이트가 같다(Python). 그 스테이징은 Darwin[:260] + NeXTMach[331:376] + Darwin[281:] 에 작성 3 곳을 적용한 것과 같다(다시 확인).
- 빌드 `s5p58-build-1`: 예측이 모두 맞았다. O3 `d87a52ac…` 와 O3c `126e1a24…` 는 탐침 4 와 같고, 두 `.i` 는 같다. 1311 B, 재배치 95, 미정의 14.
- L1(객체 심볼 이름 범위): O3c 는 9 MATCH 와 `_kalloc_init` MATCH_UNVERIFIED(`__bss` 만)이고, 차이는 0, BOUNDARY 는 없다. 36.1: 재배치 95 개가 대응(같은 형태 53, local→extern 42)하고, 재배치 밖 바이트가 같다. common 64/64·4/16·4/16.
- 경계: 앞 0 B(`ret` 0x15a67b, 4 정렬), 뒤 `00` 1 B(최소 채움).
- zerofill(known s5p55): `reference-inferred-single`, [0x1e5a98, 0x1e5b98). 알려진 범위 파일 s5p58 은 16 개다.
- 판정: **P**(단일 참조). functions +10(high 9, medium 1) → 544(high 484, medium 60). objects_partial 10, PROVENANCE 329 행, MODIFICATIONS +1. README 의 medium·P 정의를 D019 에 맞게 고쳤다. `.i` 채택 검사에서 51 개 모두 07 에 있다. 헤더 변경이 없으므로 회귀는 필요 없다.

## 85. S5-P59 세부 계획 — `vm/vm_object.c` 진단(옵션 `NORMA_VM`·`MACH_PAGEMAP` 헤더) (코딩 전, 2026-10-02)

사실(Python·grep):
- 원본 구간(objects.tsv seq 209, 등급 B): [0x1789d0, 0x179d41) 4977 B, 함수 25 개(`_vm_object_init` … `_vm_object_name` 0x179d38). 뒤 3 B 다음에 `_vm_pageout_scan` 0x179d44 가 온다. 앞은 확정 `vm_mem_region` 끝 0x1789cf(경계는 빌드 뒤 다시 계산).
- 후보(`srcdefs.py`):
  - Darwin `vm/vm_object.c` 는 원본 25 개를 원본 순서대로 모두 가진다. 추가로 static `_vm_object_deactivate_pages`, 전역 `vm_object_deactivate_pages_first`(:557)·`adjust_vm_object_cache`(:588)·`vm_object_cache_steal`(:1117), `vm_object_print`(`#if DEBUG` :1545) 가 있다. 앞의 세 전역은 원본 심볼표에 없다(grep 0 건). 뒤의 둘은 Darwin `bsd/vfs/vfs_subr.c` 가 부른다.
  - NeXTMach 는 `vm_object_cache_object` 가 없다. Mach4 는 7 개가 없다.
- 막힌 원인: `vm_object.c:57–58` 이 `<norma_vm.h>`·`<mach_pagemap.h>` 를 include 하는데, 두 옵션은 config_options.tsv 에서 `undetermined`(값 0)라 생성되지 않는다.
- 두 매크로의 쓰임은 Darwin 트리 전체에서 `#if` 뿐이다(`#ifdef`·`defined()` 0 건). 파일은 `vm/memory_object.c`(conf/files 밖), `vm/vm_object.c:60–62`, `vm/vm_object.h:78–90·212–214` 셋이다. 정의 안 된 `#if` 는 0 이므로, 지금까지 확정된 객체들(`vm_object.h` 사용)은 이미 사실상 0 으로 빌드되었다.

설계:
1. 탐침 1(스테이징만): `stage_headers.py --prefer-07 --nextdev vm/vm_object.c` 를 쓰고, 스테이징 사본에만 `src/generated/norma_vm.h`(`#define NORMA_VM 0`)·`src/generated/mach_pagemap.h`(`#define MACH_PAGEMAP 0`)를 둔다. 07 과 config 표는 바꾸지 않는다. 빌드는 O3·O3c·O2·`.i` 두 개다.
   - 예측: 컴파일은 성공한다(실패하면 원인을 기록하고 멈춘다).
   - 예측: `__text` 는 원본보다 크다(전역 3 개 추가분).
   - 함수별 L1(객체 심볼 이름 범위, Ghidra 몸체 끝)으로 25 함수 각각의 크기·바이트 차이를 기록한다.
2. 탐침 2(조건부, 복원 수정 D014): 원본에 없는 전역 3 개(`vm_object_deactivate_pages_first`·`adjust_vm_object_cache`·`vm_object_cache_steal`)를 지운다. 단 원본 바이트에서 그 흔적(호출 등)이 없는지 먼저 확인한다. 함수별 차이가 남으면 원인을 하나씩 기록한다.
3. 판정:
   - OBJECT_MATCH 또는 P 조건(README)이 성립하면 채택한다. 채택 단계는 다음과 같다.
     - 두 옵션을 `hypothesis` 0 으로 config_options.tsv 에 올리고(근거: 객체 바이트와 위 `#if` 사용), `gen_config_headers.py` 로 다시 생성한다.
     - `meta_features.h` 에 import 2 개가 늘어나므로, 회귀(확정·부분 73 객체 = s5p54 71 + ddm + kalloc)로 모두 동일함을 확인한다.
     - 그다음 07 채택, `.i` 채택 검사, 표 갱신을 한다.
   - 성립하지 않으면 함수별 차이를 증거로 남기고 보류한다.

### 85.1 codex 교차검토(QS3) 판정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| 범위·함수 25·뒤 3 B·Darwin 이 25 개를 순서대로 가지고 5 개 추가 | 85 절 Python(symbols.tsv, srcdefs) 출력 | ✅ |
| "Darwin 트리 전체에서 세 파일" 은 과함 — `conf/MASTER`·`.defs` 주석에도 나옴 | grep: `conf/MASTER:137`, `mach/memory_object.defs:89` 등(C 코드 아님); SDK `mach/mach_types.defs:218` 은 `#if` | ⚖️ 문구를 "C/H 소스에서" 로 좁힘, 결론(`#if` 뿐) 유지 |
| `#ifdef`·`defined()` 사용은 Darwin C/H·07 에 없음 → 0 정의는 기존 분기 유지 | 85 절 grep 0 건 + 07·SDK grep(위) | ✅ 회귀로 확인 |
| `kern/mapfs.c:1033` 이 `vm_object_deactivate_pages_first` 를, `vfs_subr.c` 가 나머지 둘을 부름 → 원본 호출자 확인 필요 | grep: mapfs.c:206·1033; vfs_subr.c:177·184·429·445·463 | ✅ 탐침 2 전에 원본 호출 대상 확인(mapfs·vfs_subr 원본 구간의 call 대상) |
| 원본의 cache_trim panic 문자열은 `vm_object_deactivate: I'm sooo confused.`(0xe0bb2), Darwin 은 `vm_object_cache_trim: …`(:575) | strings.tsv:1393, vm_object.c:570–580 | ✅ 세 전역 삭제만으로는 복원되지 않음 — 탐침 1 의 함수별 차이로 확인 |
| "`__text` 가 크다" 는 예측이 아니라 관찰 대상 | — | ✅ 문구 수정 |
| 스테이징 뒤 덧붙인 헤더는 manifest 에 없음 → 덧붙임과 해시 기록 | `stage_headers.py` 는 덧붙임을 모름 | ✅ 실행 cmd 머리와 계획에 두 파일 SHA 기록 |
| `s5p54-regress.cmd` 는 71 RUN → ddm·kalloc 을 명시 추가해야 73 | `grep -c ^RUN` = 71 | ✅ |
| 경계 별도 확인(앞 1 B, 뒤 3 B) | objects_confirmed `x86-vm_mem_region` 끝 0x1789cf, gap_after `1 x 00` | ✅ |

### 85.2 결과 (S5-P59, 2026-10-02) — 탐침 1 컴파일 실패, 보류

- 탐침 `s5p59-probe-1`(스테이징 + 덧붙인 헤더 2 개: `generated/norma_vm.h` sha256 `c278bc14…`, `generated/mach_pagemap.h` `8394f10f…`): 5 명령 모두 실패했다. 원인은 둘이다.
  1. `machdep/i386/xpr.h:56–58`·`driverkit/xpr_mi.h:47–48` 의 `driverkit/…` 가 없다. **내 실수**다: driverkit-1 `-I` 가 없는 s5p47 템플릿을 썼다. ddm 빌드(s5p55-build.cmd)와 같은 플래그를 써야 한다.
  2. `vm_object.c:65–66` 의 `mach/memory_object_default.h`·`mach/memory_object_user.h` 가 없다. 이 둘은 MIG 생성물이다. Darwin `conf/Makefile.template:534–558` 이 `mig -typed -MD $(MIGKUFLAGS) -DSEQNOS -header … -user … -server /dev/null mach/memory_object{,_default}.defs` 로 만들고, `MIGKUFLAGS = -I. -I.. -I$$REL_SOURCE_DIR -DKERNEL -DKERNEL_USER`(:442–444)이다.
- 07·config 표 변경은 없다. NORMA_VM·MACH_PAGEMAP 은 `undetermined` 로 둔다.
- 다음(86 절): 게스트 `/usr/bin/mig`(kr_run 허용 도구, A3 탐침에서 사용)로 두 헤더를 생성하는 절차를 세운다. 같은 실행에서 생성된 `memory_object_user.c`·`memory_object_default_user.c` 도 원본 객체 후보로 진단한다.

## 86. S5-P60 세부 계획 — MIG 생성 헤더 `mach/memory_object_user.h`·`mach/memory_object_default.h` 를 게스트 `mig` 로 만들고 vm_object 재진단 (코딩 전, 2026-10-02)

사실:
- Darwin 규칙은 `conf/Makefile.template:534–558` 이다.
  - 명령: `mig -typed -MD $(MIGKUFLAGS) -DSEQNOS -header X.h -user X_user.c -server /dev/null mach/X.defs`.
  - `MIGKUFLAGS` = `-I. -I.. -I$$REL_SOURCE_DIR -DKERNEL -DKERNEL_USER`(:442–444).
  - 작업 디렉터리는 빌드의 `mach/` 이다. `..` 는 config 생성물이 있는 빌드 디렉터리, `REL_SOURCE_DIR` 은 소스 루트다.
- 두 `.defs` 는 `<mach/std_types.defs>`·`<mach/mach_types.defs>` 만 include 한다(`memory_object.defs:169–170`, `memory_object_default.defs:144–145`). `serverprefix seqnos_` 를 쓴다.
- `kr_run.py` 허용 도구에 `/usr/bin/mig`·`/usr/lib/migcom`·`/lib/cpp` 가 있다(:28). A3 탐침이 `/usr/bin/mig -arch i386 -user stage/… -server stage/… -header stage/… src/mig_probe.defs` 를 실행했다(`probes/probes-kernel.cmd:7`).
- 원본 심볼표에 `_memory_object_*` 사용자 스텁은 하나도 없다(12 개 이름 grep 0). Darwin `vm_object.c` 에서 `memory_object_` 함수는 `:85` 의 `memory_object_release` 원형뿐이다. 따라서 이 헤더들은 vm_object 에서 선언 공급용이다(생성 `.c` 는 원본 객체 후보가 아니다).

설계:
1. 실행 `s5p60-mig-1`(스테이징: `stage_headers.py --prefer-07 --nextdev mach/memory_object.defs mach/memory_object_default.defs` + config 생성물). 명령은 다음과 같다(작업 디렉터리 = 실행 디렉터리, 출력은 `stage/`).
   - `RUN /usr/bin/mig -arch i386 -typed -Isrc/generated -Isrc/src -DKERNEL -DKERNEL_USER -DSEQNOS -header stage/memory_object_user.h -user stage/memory_object_user.c -server stage/memory_object_server_unused.c src/src/mach/memory_object.defs`
   - default 도 같은 방식이다.
   - 결정성을 보려고 각각 두 번 돌린다(출력 이름 `…_2`).
   - `-MD` 는 의존성 파일만 만들므로 뺀다. 내용 영향이 없는지 한 쌍으로 확인한다(`-MD` 판 1 회, `.d` 를 `stage/` 에 두는 방법이 없으면 생략하고 기록).
   - `-server /dev/null` 대신 `stage/` 의 버릴 파일을 쓴다(출력 규약). `-arch i386` 은 A3 탐침과 같게 둔다.
2. 검사: 두 번의 출력 해시가 같은지 보고, 헤더 안에 경로·날짜 같은 비결정 요소가 있는지 Python 으로 본다.
3. vm_object 탐침 2: 탐침 1 스테이징을 다시 만들고 덧붙임은 `generated/norma_vm.h`·`generated/mach_pagemap.h`(0), `generated/mach/memory_object_user.h`·`generated/mach/memory_object_default.h`(1 의 출력)이다. Darwin 의 `-I.`(빌드 디렉터리) 위치에 해당한다. 빌드 플래그는 ddm 템플릿(driverkit-1 포함)이다.
   - 관찰: 컴파일 여부, 함수별 크기, L1(객체 심볼 이름 범위).
   - 이 회차에는 07·config 표를 바꾸지 않는다. 채택 여부는 결과에 따라 다음 회차에 정한다. 생성 헤더를 07 에 둘 때는 `07_kernel/generated/mach/` 에 두고, README·PROVENANCE 에 "mig 생성물(도구 해시·명령·입력 해시)" 로 기록할 예정이다. `gen_config_headers.py --check` 는 자기 파일만 비교한다(:40–53).

### 86.1 실기 `mig` 확인과 codex 교차검토(QS4 시간 초과 → QS4b) 판정 → 설계 수정

내 확인(실기 읽기 전용, gcds):
- `/usr/bin/mig`(셸 스크립트, sha256 `6341c61c…` = 툴체인 기록)의 옵션 처리는 다음과 같다.
  - `-[qQvVtTrRsSiPp]` 와 `-user/-server/-header/-sheader/-handler X` 는 migcom 으로 간다.
  - `-arch X` 는 아키텍처를 정한다.
  - `-newipc` 를 주면 `/usr/lib/migcom3` 을 쓰고 cpp 에 `-DNEW_MACH_IPC` 를 더한다.
  - `-MD` 는 **버린다**(`shift`).
  - 그 밖의 `-*`(`-typed`·`-I`·`-D`)는 **cpp 로** 간다.
  - cpp 는 `/lib/${arch}/cpp` 다.
- 실기 해시(`krsha256`): `/usr/lib/migcom3` `7676a202…` 91144 B. migcom `b9d62a00…`, mig `6341c61c…`, `/lib/i386/cpp` `a21a9f03…` 는 기록(`sha256-vs-vm.json`)과 같다. `migcom3` 은 기록에 없어 VM 대조값이 없다.

| codex 주장(QS4b) | 내 검증 | 판정 |
|---|---|---|
| 어느 migcom 이 이 `.defs` 를 읽는지는 근거 없음 → 두 모드 모두 실행·기록 | 위 스크립트 | ✅ 탐침에 기본/`-newipc` 두 모드 |
| `-typed` 는 이 대상에서 cpp 로 가므로 타입 출력 효과 없음, cpp 오류 가능 | 스크립트 `-* ) cppflags=…` | ✅ 주 명령에서 뺌. 효과는 별도 1 쌍으로 관찰 |
| `migcom3`·`/lib/i386/cpp` 를 해시 목록에 추가 | `kr_run.py:28`(현재 6 개), `:118–120`(VM 일치 필수) | ⚖️ `/lib/i386/cpp` 는 VM 일치 해시가 있어 그대로 추가. `migcom3` 은 VM 값이 없으므로 **실기 전용 해시 목록**(새 json, 출처 = 이 측정)으로 결속하고, `run.json` 에 그 구분을 남긴다 |
| `-MD` 설명 정정(무시됨) | 스크립트 `-MD ) shift;;` | ✅ 86 절의 `.d` 확인 항목 삭제 |
| `-newipc` 는 cpp 입력(`-DNEW_MACH_IPC`)도 바꿈 | 스크립트 | ✅ 기록 |
| Darwin make 규칙은 Darwin 호출의 근거일 뿐, 대상 래퍼 동작이 우선 | — | ✅ |

수정 설계:
1. `kr_run.py`:
   - `ALLOWED_TOOLS` 에 `/lib/i386/cpp`·`/usr/lib/migcom3` 을 더한다.
   - `migcom3` 은 `REAL_ONLY_TOOLS` 로 `08_build/toolchains/real-i386-20261001/real-only-20261002.json`(이번 측정, VM 미대조 명시)과 대조한다.
   - 나머지 도구의 VM 일치 규칙은 그대로 둔다.
   - 바뀌는 것은 `tools.expected` 줄이 늘어나는 것뿐이다(도구 해시 결속 강화). 기존 실행 기록은 다시 만들지 않는다.
2. `s5p60-mig-1` 명령(각각 `memory_object.defs`·`memory_object_default.defs`):
   - (A) 기본: `mig -arch i386 -Isrc/generated -Isrc/src -DKERNEL -DKERNEL_USER -DSEQNOS -header … -user … -server …`
   - (B) (A) + `-newipc`
   - (C) (B) 를 한 번 더 돌린다(결정성).
   - (D) (B) + `-typed`(관찰).

   성공한 모드의 헤더를 Python 으로 비교하고 필요한 선언(`memory_object_release` 원형 쪽과 vm_object 가 쓰는 이름)이 있는지 본다.
3. vm_object 탐침 2 는 86 절 3 그대로다. 생성 헤더는 (B) 를 우선 쓴다. (B) 가 실패하면 (A) 를 쓰고 그 사실을 기록한다.

### 86.2 결과 (S5-P60, 2026-10-02) — 도구 결속 확장, Darwin `.defs` 로는 MIG 실패

- `kr_run.py` 를 다음과 같이 고쳤다.
  - `ALLOWED_TOOLS` 에 `/lib/i386/cpp`(VM 일치 해시)·`/usr/lib/migcom3` 을 더했다.
  - `REAL_ONLY_TOOLS`·`REAL_ONLY_JSON` 을 두고 `tool_hashes()` 로 결속한다. `migcom3` 의 실기 측정값은 `08_build/toolchains/real-i386-20261001/real-only-20261002.json` 이고, VM 대조는 없다고 명시했다.
  - `prepare.json`/`run.json` 에 `tools_real_only`(기록 SHA·주석)·`tool_list` 를 넣는다.

  시험:
  - `test_kr_run_tools.py` 7/7.
  - 실기 거부 시험 `s5p60-krtest-1`: 틀린 real-only 해시로 준비하면 `FAILED` 에 `tool mismatch` 가 남고 `stage/` 는 생기지 않는다(예측대로).
- MIG 실행 `s5p60-mig-1`(B: `-newipc`, Darwin `.defs`): 4 명령 모두 종료 136. `std_types.defs:149–152` 의 `MSG_TYPE_*` 가 정의되지 않았다. Darwin `std_types.defs` 는 `#ifdef MACH_IPC_FLAVOR`(:57) 아래에 새 IPC 형을 두고, `#else`(:147) 에 옛 `MSG_TYPE_*` 를 둔다. 이 래퍼는 `MACH_IPC_FLAVOR` 를 정의하지 않는다.
- `s5p60-mig-2`:
  - A(기본 migcom)는 `memory_object.defs:167…`·`memory_object_default.defs:142…` 에서 구문 오류(`subsystem` 등 새 문법)로 종료 1.
  - D(`-newipc -typed`)는 B 와 같은 오류(136)다. `-typed` 는 cpp 에서 오류를 내지 않았다.
- 결정적 사실: 실기 SDK `mach/std_types.defs:81` 은 `#ifdef NEW_MACH_IPC` 를 쓴다. 이것은 래퍼의 `-newipc` 가 정의하는 매크로다. 주석을 뺀 Python 비교 결과는 다음과 같다.
  - `memory_object.defs`·`memory_object_default.defs` 는 SDK 와 Darwin 이 **같다**(0 줄 차이).
  - `std_types.defs` 는 매크로 이름 한 줄만 다르다.
  - `mach_types.defs` 는 119 줄 다르다(Darwin 이 뒤의 판).
  - `machine/machine_types.defs` 는 SDK 가 `ARCH_INCLUDE`, Darwin 이 `#if defined(ppc)…` 다.

  즉 OPENSTEP 4.2 시대의 MIG 입력은 SDK 판 `.defs` + `-newipc` 조합이다.
- 07·config 변경은 없다. vm_object 탐침 2 는 다음 절(87)로 넘긴다.

## 87. S5-P61 세부 계획 — SDK 판 `.defs` + `mig -newipc` 로 MIG 헤더 생성, vm_object 탐침 2 (코딩 전, 2026-10-02)

사실(86.2, grep):
- SDK 닫힘은 7 개다: `mach/memory_object.defs`·`mach/memory_object_default.defs`(→ `mach/std_types.defs`·`mach/mach_types.defs`), `std_types.defs:94` → `mach/machine/machine_types.defs` → `architecture/ARCH_INCLUDE.h` + `ARCH_INCLUDE(mach/, machine_types.defs)` = `mach/i386/machine_types.defs`. `mach_types.defs:143` 의 `<norma_vm.h>` 는 `#if KERNEL_SERVER` 안에 있어 사용자 쪽 생성에서는 읽지 않는다. 7 개 모두 실기 SHA 목록(`s4c-nextdev-headers-20261002.json`)에 있다.
- `stage_headers.py` 는 Darwin 판 이름을 먼저 해석한다(SDK 루트는 뒤). `--subst` 는 `src/bsd/` 만 허용한다. 그래서 이 7 개는 `--nextdev` 스테이징으로 얻을 수 없다.

설계:
1. 스테이징(새 작은 도구 없이, 이번만 Python 스크립트를 `08_build/runs/tools/s5p61-stage-mig.py` 로 저장):
   - 7 개를 `nextdev/<경로>` 로 바이트 복사한다. 각 파일은 실기 SHA 목록과 같아야 하고, 다르면 중단한다.
   - `generated/` 의 config 생성물을 함께 둔다(Darwin `-I..` 대응, 사용자 쪽에서는 읽히지 않음).
   - manifest(경로·출처·SHA)를 쓴다.
2. 실행 `s5p61-mig-1`: `mig -arch i386 -newipc -Isrc/generated -Isrc/nextdev -DKERNEL -DKERNEL_USER -DSEQNOS -header stage/memory_object_user.h -user stage/memory_object_user.c -server stage/…_unused.c src/nextdev/mach/memory_object.defs`. default 도 같은 방식이고, 둘 다 반복 1 회(결정성)다.
   - 예측: 성공, 반복 출력 동일.
   - 헤더에서 확인할 것: `memory_object_*` 사용자 원형, 경로·시각 같은 비결정 문자열(Python).
3. vm_object 탐침 2(`s5p61-probe-1`): `stage_headers.py --prefer-07 --nextdev vm/vm_object.c` 를 쓰고, 덧붙임은 `generated/norma_vm.h`·`generated/mach_pagemap.h`(0)와 `generated/mach/memory_object_user.h`·`generated/mach/memory_object_default.h`(2 의 출력, SHA 기록)다. 플래그는 ddm 템플릿(driverkit-1 포함)으로 O3·O3c·O2·`.i` 두 개다.
   - 관찰: 컴파일, 25 함수 L1(객체 심볼 이름 범위), 크기.
   - 07 은 바꾸지 않는다. 채택은 결과를 보고 다음 회차에 정한다.

### 87.1 codex 교차검토(QS5) 판정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| SDK `.defs` + `-newipc` 는 유력 후보일 뿐, 원본과 같다는 증명은 아님 | 86.2 | ✅ 86.2 결론을 "가장 근거 있는 후보(생성 헤더·바이너리 확인 전)" 로 읽는다 |
| `std_types.defs` 가 `<mach/std_types.h>` 를 import → 생성 C 헤더는 컴파일 경로의 C 헤더(07/Darwin)에 기댐, vm_object 환경에서 `.i` 로 확인 필요 | SDK `std_types.defs:197` `import <mach/std_types.h>;` | ✅ 탐침 2 의 `.i` 에서 생성 헤더가 끌어오는 경로 확인 |
| mig 에 `-nostdinc` 가 없으면 스테이징에 없는 이름이 실기 `/NextDeveloper/Headers` 로 샐 수 있음 | mig 래퍼는 `-*` 를 cpp 로 넘김(86.1) | ✅ `-nostdinc` 판을 따로 돌려 출력이 같으면 닫힘 증명 |
| `-DSEQNOS` 는 생성 시그니처를 바꿈 | `memory_object.defs:133–136·151–153` — `serverprefix`/`serverdemux` 와 `msgseqno` 인자(서버 쪽) | ⚖️ Darwin 규칙(`Makefile.template:541·556`)이 사용자 쪽에도 `-DSEQNOS` 를 준다. `msgseqno` 는 서버 쪽 인자라 사용자 헤더 영향은 생성물로 확인(SEQNOS 없는 판 1 쌍도 생성해 비교) |

### 87.2 결과 (S5-P61, 2026-10-02) — MIG 헤더 생성 성공, vm_object 컴파일·크기 진단

- 스테이징 `s5p61-mig-stage-1`(`08_build/runs/tools/s5p61-stage-mig.py`): SDK 7 개는 실기 SHA 와 일치했고, `generated/` 는 07 사본이다.
- `s5p61-mig-1`(SDK `.defs`, `-newipc`, `-DSEQNOS`)·`s5p61-mig-2`: 8 명령 모두 성공했다(collect 게시).
  - 헤더 `memory_object_user.h` `440be767…`(6539 B)·`memory_object_default.h` `247dee04…`(1667 B)는 반복, `-nostdinc` 판, SEQNOS 없는 판이 모두 **바이트 같다**. 닫힘과 결정성을 확인했고, 사용자 헤더는 SEQNOS 영향이 없다.
  - 생성 `.c` 의 차이는 첫 줄 `#include "<헤더 이름>"` 뿐이다(diff).
  - 헤더에 경로·날짜 문자열은 없다(Python 정규식).
  - include 는 `mach/kern_return.h`·`port.h`·`message.h`·`std_types.h`·`mach_types.h` 다.
  - 원형은 `memory_object_init` 등 10 개이고 `memory_object_release` 는 없다(Darwin vm_object.c:85 가 스스로 원형을 둔다).
- vm_object 탐침 2(`s5p61-probe-1`, ddm 템플릿 플래그, 덧붙임 4 개 SHA 기록): 5 명령 모두 성공했다. 두 `.i` 는 같다(`a0ac0b05…`). O3/O3c `__text` 5594 B·재배치 297, O2 4446 B.
  - L1 `--place-from-image` 는 크기가 달라 Δ 가 하나로 정해지지 않아 함수 판정이 없다(`__text` unverified).
  - 객체 심볼 간격으로 크기를 비교(Python)했다.
    - 원본 25 함수 중 20 개는 크기가 같다.
    - 원본에 없는 `_vm_object_deactivate_pages_first` 88·`_adjust_vm_object_cache` 164·`_vm_object_cache_steal` 348(합 600)이 있다.
    - `_vm_object_lookup` 192/188, `_vm_object_enter` 124/120, `_vm_object_remove` 104/100, `_vm_object_cache_clear` 336/332 로 각 +4 다.
    - 끝 `_vm_object_name` 10/9 는 끝 정렬 차이다.
  - 계산: 5594 − 600 − 16 = 4978 이고, 원본은 4977 + 끝 채움 1 이다.
- 다음(88 절, 다음 회차): 위 세 전역 제거(복원 수정), 네 함수의 4 B 원인(바이트 비교), cache_trim panic 문자열(`vm_object_deactivate: …`, 86 절 QS3)을 다룬다.

## 88. S5-P62 세부 계획 — vm_object.c 복원 수정(탐침 3) (코딩 전, 2026-10-02)

사실(capstone diff, Python, grep):
- `_vm_object_lookup`(원본 0x179630)·`_vm_object_remove`(0x179764) 의 차이는 해시 계산이다.
  - 원본: `and eax,0x7f` → `lea edx,[eax*8+0x1f6f50]`, 즉 `pager % 128`.
  - Darwin: `shr eax,5; and eax,0x1ff8`, 즉 `(pager >> 8) % 1024`(`vm_object.c:976–978` `VM_OBJECT_HASH_SHIFT 8`, `:121` `VM_OBJECT_HASH_COUNT 1024`).
  - 나머지 명령은 재배치 필드 밖에서 같다(차이 목록에 다른 명령 없음).
  - 원본 `_vm_object_hashtable` 0x1f6f50 에서 다음 심볼 `_vm_object_list` 0x1f7350 까지 1024 B = 128 × 8(`queue_head_t`).
  - NeXTMach `vm_object.c:976–977` 은 `#define vm_object_hash(pager) (((unsigned)pager)%VM_OBJECT_HASH_COUNT)`(시프트 없음)이고 `:109` `VM_OBJECT_HASH_COUNT 521` 이다. 128 은 어느 참조에도 없다.
- 원본 문자열 0xe0bb2 `vm_object_deactivate: I'm sooo confused.`(strings.tsv:1393) = NeXTMach `vm_object.c:564`. Darwin `:576` 은 `vm_object_cache_trim: …` 이다. `vm_object_cache_steal: …` 문자열은 원본 strings 에 없다(:1391–1398 사이에 없음).
- 원본에 없는 전역 3 개: `vm_object_deactivate_pages_first`(Darwin :549–561, 주석 포함), `adjust_vm_object_cache`(:584–593), `vm_object_cache_steal`(:1113–1137). 원본 객체의 25 함수가 이것들 없이 연속으로 크기가 맞는다(87.2).

탐침 3(스테이징 사본에서, 복원 수정 D014 R1–R5 + 작성 W 규칙):
- E1(R1·R2): 위 세 함수 정의와 바로 앞 주석 블록을 지운다(헤더 `vm_object.h:248` 의 원형은 코드에 영향이 없으므로 그대로 둔다).
- E2(R1, NeXTMach :564 문자열): `vm_object_cache_trim` 의 panic 문자열을 바꾼다.
- E3: `vm_object_hash` 를 NeXTMach :976–977 형태(시프트 없음)로 바꾸고 `VM_OBJECT_HASH_SHIFT` 정의를 지운다. `VM_OBJECT_HASH_COUNT` 1024 → **128** 은 참조에 없는 값이라 **작성(D016, W3 표시)** 으로 기록한다(근거: `and 0x7f`, 표 크기 1024 B).
- 예측(R5/W5):
  - `__text` 4977 또는 4978 B(끝 채움). 25 함수 크기가 모두 원본과 같다.
  - `vm_object_hashtable` 은 O3 에서 1024 B `__common`, O3c 에서 common 1024 다.
  - 문자열 `__cstring` 에 `vm_object_cache_steal` 이 없다.
  - L1(O3c, 객체 심볼 이름 범위)은 25 함수 MATCH 거나 bss/common 의존 MATCH_UNVERIFIED 다.
  - 남는 차이가 있으면 함수별로 기록한다(변형 한도 함수당 3).
- 이번 회차에는 07 을 바꾸지 않는다. 일치하면 다음 회차에 채택 절차(옵션 2 개 config 반영·회귀 73·MIG 헤더 07 배치·표)를 계획한다.

### 88.1 codex 교차검토(QS6) 판정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| `vm_object_cache_steal` 은 :1138 에서 끝남(1137 아님) | `sed -n 1137,1139p`: 1137 `return(num_removed);`, 1138 `}` | ✅ 정정(:1113–1138) |
| E1 은 다른 호출처의 인라인·최적화를 바꿀 수 있음 → 수정 뒤 크기·바이트 재확인 | `adjust_vm_object_cache`(:588–594)가 `vm_object_cache_trim()` 호출(164 B, 인라인) | ✅ 수정 뒤 25 함수 바이트를 모두 비교 |
| 원본 문자열과 NeXTMach 의 trim panic 이 같음(codex 는 :563 이라 함) | NeXTMach :563 은 `if (…)`, **:564** 가 `panic("vm_object_deactivate: …")` — 내 표기 :564 가 맞음 | ⚖️ 사실 ✅, 줄 번호는 기각 |
| 그 문자열을 원본의 어느 함수가 참조하는지는 문자열 목록만으로 미확정 | — | ✅ L1 의 `__cstring` 참조 검증으로 확인 |
| 128 이라는 **동작**은 근거 있음, 소스 철자(`% 128`·`& 127`·`& (COUNT-1)`)는 미확정 → "의미 복원, 철자는 추정" | 원본 `vm_object_init` 의 루프 끝 `mov ecx, 0x1f7348`(= 0x1f6f50 + 127×8, Python), 빌드는 `0x1ff8`(1023×8) | ✅ MODIFICATIONS/W3 표시에 "값 128 은 바이너리에서(표 1024 B, `and 0x7f`, init 루프 끝 0x1f7348), 철자는 NeXTMach 형태를 따른 추정" 으로 기록 |
| `VM_OBJECT_HASH_COUNT` 의 모든 사용처 확인 | grep: :121 정의, :126 배열, :179 init 루프, :978 해시 매크로(:992·:1040·:1065 사용) | ✅ 모두 E3 에 포함됨 |

### 88.2 결과 (S5-P62, 2026-10-02) — 탐침 3: 23/25 MATCH

- 탐침 `s5p62-probe-1`(스테이징 소스 sha256 `fe3cecb0…`, diff `06_reconstruction/evidence/x86-vm_object-probe3.diff`): 5 명령 모두 성공했고, 두 `.i` 는 같다(`c30167e5…`).
  - `__text` 4978 B·재배치 258(예측 4977–4978 범위). O3 `__common` 1336 B(해시표 1024 포함).
  - L1 O3c: placement `__text` 0x1789d0, `__data` 0x1e0b38. **23 MATCH**, 2 DIFF(바이트 차이 49, 참조 차이 3).
  - O3 는 15 MATCH_UNVERIFIED(`__common` 미배치) + 8 MATCH + 2 DIFF 다.
- 남은 차이 1: `_vm_object_deactivate_pages`(42 B, 참조 3).
  - 원본은 페이지마다 `vm_page_lock_queues()` 를 잡고 `call 0x17b810` 을 한다(루프 안 잠금).
  - 빌드는 Darwin 의 static `_vm_object_deactivate_pages(object, age)` 가 인라인되어 루프 전체를 잠근다.
  - NeXTMach `vm_object.c:533–548` 의 `vm_object_deactivate_pages` 는 루프 안에서 잠그고 `vm_page_deactivate(p)` 를 부른다. 이것이 원본 구조와 같다.
- 남은 차이 2: `_vm_object_name`. 원본 `55 89 e5 31 c0 89 ec 5d c3` 은 `return 0`. Darwin(`:1539` `return ((port_t)object)`)과 NeXTMach(`:1840` 이름 포트 조회)는 모두 다르다. → 작성(W) 후보다.
- 다음(89 절): `vm_object_deactivate_pages` 를 NeXTMach 판으로 바꾸고 static 도우미를 지운다(복원 수정). `vm_object_name` 은 `return 0` 계열로 작성한다(W1–W5).

## 89. S5-P63 세부 계획 — vm_object 탐침 4: `vm_object_deactivate_pages` NeXTMach 본문, `vm_object_name` 작성 (코딩 전, 2026-10-02)

근거(88.2, 원본 바이트):
- 원본 `_vm_object_deactivate_pages`(0x179084, 88 B)는 루프 안에서 잠근다. `call 0x17b810` = `_vm_page_deactivate`(symbols.tsv:3499). 도우미 함수나 `vm_page_deactivate_first` 호출은 없다.
- 원본 `_vm_object_name`(0x179d38, 9 B)은 `xor eax,eax` 로 0 을 돌려준다.

수정(탐침 3 스테이징 위에서):
- E4(D014 R1·R2, NeXTMach D013): Darwin :506–528(static `_vm_object_deactivate_pages` 와 그 주석)을 지운다. Darwin `vm_object_deactivate_pages`(:538–542)의 머리(`void …(object)`·K&R 선언)는 남긴다(:90 원형 `void` 와 맞추기 위해서다. NeXTMach 의 암시적 `int` 머리는 충돌한다). 본문만 NeXTMach `vm_object.c:536–547`(지역 `p, next`, 루프 안 `vm_page_lock_queues()`·`vm_page_deactivate(p)`·`vm_page_unlock_queues()`)로 바꾼다.
- E5(D016 작성, W1–W5): `vm_object_name` 본문을 `return (PORT_NULL);` 로 바꾼다. W3 표시를 한다. `PORT_NULL` 은 Darwin `mach/port.h:226`(07 `:239`)의 정의(`(port_name_t) 0`)다.
  - W1: Darwin(`object` 반환)·NeXTMach(이름 포트 조회)·Mach4(이 함수 없음, 85 절 srcdefs)로는 원본 바이트가 나오지 않는다.
  - 변형 1/3 이다.
- 예측(W5/R5):
  - `__text` 4978 B → `deactivate_pages` 길이 같음(88), `vm_object_name` 9 B + 채움.
  - 재배치 258 − 3(Darwin 판 잠금 변수 참조 차이분 재계산은 빌드로) 이다.
  - L1 O3c 25/25 MATCH, 차이 0 이다.
  - O3 는 `__common` 때문에 MATCH_UNVERIFIED 다(36.1 절차는 채택 회차에).
- 일치하면 다음 회차(90)에 채택 계획을 세운다. 채택 항목: NORMA_VM·MACH_PAGEMAP config(hypothesis 0)·MIG 헤더 07 배치·`.i` 채택 검사·회귀 73·36.1·경계·`__data` 확인·표.

### 89.0 자체 정정(codex QS7 회신 전, Python 줄 출력으로 확인)

89 절의 줄 번호를 정정한다. 근거는 `vm_object.c` 줄 출력이다(Darwin 505–547, NeXTMach 533–548).
- 지울 Darwin 도우미: 주석 :506–513, 정의 :514–533. 뒤의 빈 줄 :534 까지 지운다(89 절의 ":506–528" 은 틀림).
- 남길 Darwin 머리: 주석 :535–542, `void vm_object_deactivate_pages(object)` :543, 선언 :544, `{` :545. 바꿀 본문은 :546 `_vm_object_deactivate_pages(object, FALSE);` 한 줄이다(89 절의 ":538–542" 는 틀림).
- 들여올 NeXTMach 본문: `vm_object.c:537–548`(지역 선언 `register vm_page_t p, next;` 부터 `while` 블록의 닫는 `}` 까지)이다. 89 절의 ":536–547" 은 한 줄씩 어긋났다(:536 은 `{`).

### 89.1 codex 교차검토(QS7 은 회신 지연으로 중단, QS7b 범위 축소) 판정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| 89.0 의 범위(지울 :506–534, 남길 :535–545, 바꿀 :546 ← NeXTMach :537–548)는 정확하고 결과 함수는 문법상 온전 | 89.0 의 줄 출력(Python) | ✅ |
| 지정 범위 안에는 지운 도우미·`vm_page_deactivate_first` 참조가 남지 않음, 파일 전체는 미확인 | 탐침 3 스테이징 파일 전체 grep(아래 결과) | ✅ 파일 전체 grep 으로 보완 |
- 파일 전체 grep(탐침 3 스테이징): 참조는 :508·:515·:527·:547 네 곳이고, 모두 지우거나 바꿀 범위 안이다(스테이징은 W3 표시 1 줄 때문에 Darwin 보다 +1).

### 89.2 결과 (S5-P63, 2026-10-02) — 탐침 4: O3c **OBJECT_MATCH 25/25**

- 탐침 `s5p63-probe-1`(스테이징 소스 sha256 `98869e38…`, diff `06_reconstruction/evidence/x86-vm_object-probe4.diff`): 5 명령 모두 성공했다.
  - O3 `daa551c6…`, O3c `c8b1bd8b…`, O2 `042b05d9…`(다름). 두 `.i` 는 같다(`80676253…`).
  - `__text` 4977 B(원본 [0x1789d0, 0x179d41) 와 같은 길이)·재배치 258, `__data` 378 B.
- L1(객체 심볼 이름 범위):
  - O3c **OBJECT_MATCH**: 25 MATCH, 바이트·참조 차이 0, `__data` 포함.
  - O3 는 10 MATCH + 15 MATCH_UNVERIFIED(`__common` 1336 B 미배치)다. 36.1 절차 대상이다.
- 변형 수: `vm_object_deactivate_pages` 1, `vm_object_name` 1(작성), 해시 1.
- 다음(90 절): 채택 계획을 세운다(07 반영, NORMA_VM·MACH_PAGEMAP config, MIG 헤더 07 배치·출처, `.i` 채택 검사, 회귀 73, 36.1, 경계, 표).

## 90. S5-P64 세부 계획 — `vm/vm_object.c` 채택 (코딩 전, 2026-10-02)

사실(Python, 탐침 4):
- 경계: 앞 0x1789cf `00` 1 B. 확정 `x86-vm_mem_region` 의 gap_after `1 x 00 (min align 2^2)` 와 같은 바이트다. 뒤 0x179d41–0x179d44 `00 00 00` 3 B = 4 정렬 최소 채움 3 이다.
- O3c common 14 개는 모두 원본 심볼이 있고 크기 ≤ 간격이다(예: `_vm_object_hashtable` 1024/1024, `_kernel_object_store` 88/88, `_vm_object_count` 4/16).
- `.i` 표지 131 개 가운데 07 에 없는 것은 다음과 같다.
  - 대상 `src/vm/vm_object.c` 다.
  - 생성물 4 개: `generated/norma_vm.h`·`generated/mach_pagemap.h`·`generated/mach/memory_object_user.h`·`generated/mach/memory_object_default.h`.
  - Darwin 헤더 9 개: `components/driverkit-1/driverkit/Device_ddm.h`, `src/driverkit/xpr_mi.h`, `src/kern/xpr.h`, `src/mach/vm_policy.h`, `src/machdep/i386/xpr.h`, `src/machdep/machine/xpr.h`, `src/vm/memory_object.h`, `src/vm/vm_fault.h`, `src/vm/vm_pageout.h`.

채택 절차:
1. config: `config_options.tsv` 의 `norma_vm`·`mach_pagemap` 을 `undetermined` 에서 `hypothesis`(값 0)로 바꾼다. 근거:
   - C/H 의 쓰임은 `#if` 뿐이다(85 절). 그래서 0 정의는 정의 안 함과 같다.
   - vm_object 는 0 으로 OBJECT_MATCH 다. 단 `vm_object.c:60–62` 의 `NORMA_VM` 분기는 include 뿐이라 값의 직접 증거는 약하다. 그러므로 `confirmed` 가 아니라 `hypothesis` 다.

   `gen_config_headers.py` 로 다시 생성하고 `--check` 를 돌린다. `meta_features.h` 에 import 가 2 개 늘어난다.
2. 회귀: 확정·부분 73 객체를 새 `meta_features.h` 로 다시 빌드해 기준과 바이트가 같은지 본다. 대상은 s5p54-regress.cmd 71 + ddm(s5p55 명령) + kalloc(s5p58 명령)이다. 기준 해시는 s5p54 기준 json 과 s5p55/s5p58 산출이다.
3. MIG 헤더를 `07_kernel/generated/mach/` 에 둔다(s5p61-mig-1 출력 그대로, sha `440be767…`·`247dee04…`).
   - `07_kernel/generated/README` 에 "mach/ 는 MIG 생성물(입력·명령·도구 해시는 PROVENANCE)" 을 더한다.
   - PROVENANCE 행: 생성 도구(실기 `/usr/bin/mig` `6341c61c…`, `/usr/lib/migcom3` `7676a202…` 실기 전용, `/lib/i386/cpp` `a21a9f03…`), 명령, 입력 SDK `.defs` 7 개 SHA(실기 목록), 실행 ID `s5p61-mig-1`, license TBD(D017).
4. `07_kernel/src/vm/vm_object.c`: 탐침 4 본문 + 머리말 뒤 `Modified` 주석을 넣는다. W3 표시는 이미 2 곳(해시 수, `vm_object_name`) 있다. 주석만 더한 것인지 Python 으로 확인한다.
   Darwin 헤더 9 개는 원문 그대로 채택한다(PROVENANCE 행, Darwin 아카이브 SHA).
5. 최종 빌드 `s5p64-build-1`(07 스테이징, 덧붙임 없음). 예측: O3 `daa551c6…`·O3c `c8b1bd8b…`(탐침 4 와 같음). 근거는 주석만 다르고, 생성 헤더가 같은 바이트이며, `meta_features.h` 의 import 2 개는 `#if` 의미가 같다는 것이다.
   이어서 L1(O3c OBJECT_MATCH)을 확인하고 36.1 을 한다(재배치 258 대응, 밖 바이트 동일, common 크기 ≤ 간격).
6. 판정은 **A** 다(OBJECT_MATCH + 경계 앞 1·뒤 3 최소 채움 00). 표: objects_confirmed +1, functions +25(high). source_id 는 `darwin01`, 일부 `+authored`(`vm_object_name`), NeXTMach 출처(`vm_object_deactivate_pages` 본문, 해시 매크로, panic 문자열)를 기록한다. MODIFICATIONS·증거·diff 를 남긴다.

### 90.1 codex 교차검토(QS8) 판정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| 작성 `vm_object_name` 은 A 를 막지 않음(A 는 객체 일치 기준). 단 A 는 O3 로의 36.1 이전(common·재배치·`__data`·경계)이 성립할 때만 | README:23 A 정의, 89.2 의 O3 결과(15 MATCH_UNVERIFIED) | ✅ 판정은 5–6 단계 결과 뒤 |
| `hypothesis` 는 역사적 값 증명이 아님 → `undetermined` 유지하고 빌드값만 따로 두라 | config 표의 선례: `norma_ether` 0 `hypothesis`("bytes cannot confirm it", plan 67), `mach_kdb` 0 `hypothesis` | ⚖️ 사실은 수용, 결론은 기각 — 표의 `hypothesis` 는 선례상 "빌드에 쓰는 가설 값" 이다(`gen_config_headers.py` 는 `undetermined` 를 생성하지 않음). 근거 칸에 "역사적 값은 미확정, `#if` 전용이라 0 = 미정의" 를 명시 |
| README 의 "모든 파일은 gen_config_headers 가 씀" 문구를 고쳐야 함 | `07_kernel/generated/README` 전문 | ✅ `mach/` 예외를 명시하도록 바꿈 |
| ddm·kalloc 기준 산출물을 정확히 고정, 같은 명령·플래그로 비교. kalloc 이 같다는 것은 등급 유지 근거일 뿐 | s5p54 기준 json 형식(`base`: 이름→산출 경로) | ✅ 기준에 `O3__ddm.o`·`O3c__ddm.o` → `s5p55-build-1/out`, `O3__kalloc.o`·`O3c__kalloc.o` → `s5p58-build-1/out` 을 더한 새 기준 json |
| 최종 O3 이전에서 `__data` 재확인, `vm_object_name` 함수 행에 authored 표시 | — | ✅ |

### 90.2 결과 1 (S5-P64, 2026-10-02) — config·MIG 헤더 배치·회귀

- `config_options.tsv`: `norma_vm`·`mach_pagemap` 을 `hypothesis` 0 으로 바꿨다. 근거 칸에 "빌드 값, 역사적 값 미확정" 을 적었다. 행 수 26 은 그대로다.
- `gen_config_headers.py` 를 다시 돌렸고 `--check` 를 통과했다.
  - 새 파일 `norma_vm.h`(`c278bc14…`)·`mach_pagemap.h`(`8394f10f…`)는 탐침 덧붙임과 바이트가 같다.
  - `meta_features.h` import 는 20 에서 22 가 됐다.
  - 다른 생성 파일은 s5p58 사본과 같다(cmp).
- `07_kernel/generated/mach/memory_object_user.h`(`440be767…`)·`memory_object_default.h`(`247dee04…`)는 s5p61-mig-1 출력 그대로다. `07_kernel/generated/README` 를 고쳐 `mach/` 예외를 명시했다.
- 회귀 `s5p64-regress-1`: 73 객체 / 75 명령(s5p54 71 + ddm O3·O3c + kalloc O3·O3c). 기준 `08_build/runs/tools/s5p64-regress-baseline.json` 은 s5p54 기준 71 의 해시를 다시 확인하고 4 개를 더한 것이다. 스테이징은 `--prefer-07 --nextdev` 소스 73 개다. 결과 **75/75 바이트 동일**이다.

### 90.2 결과 2 (S5-P64, 2026-10-02) — `vm_object.c` **A**

- `07_kernel/src/vm/vm_object.c`: 탐침 4 본문 + `Modified` 주석 1 줄. 주석만 더한 것인지 Python 으로 확인했다.
- Darwin 헤더 9 개는 원문 그대로 채택했다(스테이징 사본과 SHA 같음).
- 최종 빌드 `s5p64-build-1`(덧붙임 없음):
  - 예측 일치: O3 `daa551c6…`·O3c `c8b1bd8b…`. 두 `.i` 는 같다(`ade38440…`, 탐침 4 와는 `Modified` 주석 줄만큼 다름).
  - L1 O3c OBJECT_MATCH 25/25(`__data` 포함).
  - 36.1: 재배치 258 대응(같은 형태 102, local→extern 122, scattered→extern 34), 밖 바이트 동일. common 14 개 크기 ≤ 간격.
  - 경계: 앞 1·뒤 3 B 최소 채움 00.
  - `.i` 표지 131 개가 모두 07 에 있다.
- 판정 **A**. 표 변경: functions +25(high) → 569(high 509, medium 60), objects_confirmed 64(A 62, A* 2). PROVENANCE +16 → 345 행(vm_object.c, Darwin 헤더 9, 생성 config 헤더 4, MIG 헤더 2). MODIFICATIONS +1, 증거 `x86-vm_object.md`·`.diff`.
- **내 누락 정정**: 81 절에서 만든 `generated/uxpr.h`·`generated/xpr_debug.h` 의 PROVENANCE 행이 없었다. 이번에 더했다. 07 의 생성 헤더 23 개 모두에 행이 있는지 셸 루프로 확인했다.

## 91. S5-P65 세부 계획 — vm/ 미채택 7 파일 일괄 진단(채택 없음) (코딩 전, 2026-10-02)

계기: vm_object 채택으로 생긴 기반이 있다. 옵션 `NORMA_VM`·`MACH_PAGEMAP` 헤더, MIG `generated/mach/memory_object_{user,default}.h`, Darwin 헤더 9 개(`vm/vm_fault.h`·`vm/vm_pageout.h`·`vm/memory_object.h`·`mach/vm_policy.h`·xpr 계열)다. 같은 이유로 막혔을 수 있는 vm/ 후보를 다시 본다.

대상(objects.tsv, Python 추출, Darwin 후보 첫째 열 기준, 07 에 없음):
- `vm/vm_fault.c` seq 204 [0x172038, 0x173a68)
- `vm/vm_kern.c` 206 [0x173ad4, 0x174600)
- `vm/vm_map.c` 207 [0x174600, 0x1787c1)
- `vm/vm_pageout.c` 210 [0x179d44, 0x17a23e)(확정 vm_object 바로 뒤)
- `vm/vm_policy.c` 212 [0x17a338, 0x17a9b1)
- `vm/vm_resident.c` 213 [0x17a9b4, 0x17b9dd)
- `vm/vm_unix.c` 215 [0x17bd28, 0x17c409)

설계:
1. 스테이징 `stage_headers.py --prefer-07 --nextdev` 에 7 소스를 넣는다. 07·config 는 바꾸지 않는다.
2. 실행 `s5p65-pre-1`: 소스마다 O3c(공통 변형) 1 명령이다. 플래그는 ddm 템플릿(driverkit-1·nextdev)이고 출력 이름은 `O3c__<이름>.o` 다. 실패가 있으면 collect 가 거부하므로 로그를 직접 읽는다(이전 관행). 성공한 것만 따로 정리한다.
3. 관찰(Python):
   - 컴파일 성공 여부와 첫 오류.
   - 객체 심볼 간격 기준의 함수별 크기 대 원본(원본 심볼 간격, 구간 끝은 objects.tsv `text_end`).
   - 빌드에만 있는 함수 / 원본에만 있는 함수.
   - 크기가 모두 같은 파일만 L1(객체 심볼 이름 범위)을 돌린다.
4. 기록: 92 절 이후의 후보 우선순위표(파일별 "차이 요약·예상 원인"). 판정·채택은 없다.

### 91.1 codex 교차검토(QS9) 판정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| 인용한 seq·범위 7 개 일치 | objects.tsv 출력(위 awk, seq 204–215) | ✅ |
| 원본 심볼 간격에는 심볼 없는 static 함수·채움이 섞일 수 있음 → 크기 차이를 곧바로 "함수 크기 차이" 로 적지 말 것 | vm_object 에서도 끝 채움 1 B 차이가 있었음(87.2) | ✅ 간격 차이는 "간격 차이" 로 적고, 빌드에만 있는 static 은 따로 표시 |
| 마지막 함수 크기는 `text_end` 추정에 기댐(vm_unix 는 상한 215 B 뒤) | awk: seq 215 end 0x17c409, end_upper_bound(열 7) 확인 | ✅ 마지막 함수 비교는 "잠정" 표시 |
| 한 명령 실패가 collect 를 막음 → 파일별 수집 | kr_run collect 는 status 전부 0 요구(:236 부근) | ✅ 파일마다 실행 ID 하나(`s5p65-pre-<이름>`) |
| "크기 모두 같을 때만 L1" 은 부분 일치를 숨김 | — | ✅ 컴파일된 모든 파일에 L1 을 돌리고 함수별 결과·배치 여부를 기록 |

### 91.2 결과 (S5-P65, 2026-10-02) — vm/ 7 파일 진단(채택 없음)

실행 `s5p65-pre-<이름>`(파일마다 하나, O3c 1 명령). 스테이징 `s5p65-pre-stage-1`(07 우선, 덧붙임 없음). 요약은 `09_validation/reconstruction/s5p65-pre-summary-20261002.json`, 파일별 L1 은 `s5p65-pre-l1-<이름>-O3c-20261002.json` 이다. 크기는 심볼 간격 기준이며, 마지막 함수는 `text_end` 추정이라 잠정이다(91.1).

| 파일 | 컴파일 | `__text` 빌드/원본 | 간격 같은 함수 | 차이 요약 | L1 |
|---|---|---|---|---|---|
| vm_policy | ✅ | 1657/1657 | 3/4(+ 빌드 전용 static 3) | `_vm_policy_apply` 간격 차이는 원본에 심볼 없는 static 3 개가 그 간격 안에 있어서다 | **OBJECT_MATCH 7/7**(`__text` 0x17a338) → 다음 채택 후보 |
| vm_fault | ✅ | 6688/6704 | 4/5 | `_vm_fault_unwire` 152/168(−16) | 배치 안 됨 |
| vm_resident | ✅ | 4345/4137 | 16/17 | 빌드 전용 `_vm_page_deactivate_first`(vm_object 와 같은 후대 추가 계열), `_vm_page_startup` 1048/1028 | 배치 안 됨 |
| vm_map | ✅ | 17813/16833 | 25/29 | 빌드 전용 `_vm_map_find_entry`·`_vm_map_reallocate`(그 둘이 원본 간격 안에 들어가는지는 미확인), `_vm_map_insert`·`_find`·`_copy`·`_region` 간격 차이 | 배치 안 됨 |
| vm_kern | ✅ | 3120/2860 | 6/13 | 빌드 전용 `_kmem_alloc_pages`·`_kmem_remap_pages`, 7 함수 간격 차이 | 배치 안 됨 |
| vm_pageout | ✅ | 1408/1274 | 0/2 | `_vm_pageout_scan` 932/864, `_vm_pageout` 476/410 | `__data` 만 배치 |
| vm_unix | ❌ | — | — | `vm_unix.c:34` `cputypes.h` 없음 | — |

우선순위(다음 계획 후보):
1. vm_policy 채택. 36.1(O3), 경계, `.i` 검사가 필요하다.
2. vm_fault(차이 1 함수).
3. vm_resident(후대 함수 제거 + 1 함수).
4. 나머지는 차이가 크다.

## 92. S5-P66 세부 계획 — `vm/vm_policy.c` 채택(Darwin 그대로) (코딩 전, 2026-10-02)

사실(91.2, Python):
- 원본 [0x17a338, 0x17a9b1) 1657 B. 원본 심볼 4 개(`_vm_policy_apply`·`_vm_set_policy`·`_vm_fault_range`·`_vm_deactivate`)가 있고, 빌드에는 static 3 개(`_deactivate_object` 440·`_deactivate_range` 604·`_set_policy` 956)가 더 있다.
- 탐침 `s5p65-pre-vm_policy`(O3c, 07 우선 스테이징): 섹션은 `__text` 1657 B·재배치 50 하나뿐이다(`__data`·common 없음). L1 OBJECT_MATCH 7/7, `__text` 는 심볼로 배치된다.
- 경계:
  - 앞 0x17a336–0x17a337 `00 00` 은 확정 `x86-vm_pager` 의 gap_after `2 x 00` 과 같은 바이트다.
  - 뒤 0x17a9b1–0x17a9b3 `00 00 00` 3 B = 4 정렬 최소 채움 3 이다(다음 0x17a9b4 는 vm_resident 구간 시작).
- 고지: APSL + `Copyright (c) 1992 NeXT, Inc.`(:26) 다.

절차:
1. `07_kernel/src/vm/vm_policy.c` = Darwin 원문 그대로(R 수정 없음, PROVENANCE `none (verbatim)`, NeXT 고지 표기).
2. 빌드 `s5p66-build-1`(07 스테이징, ddm 템플릿 플래그 5 명령: `.i`·O3·O3c·`_c.i`·O2).
   - 예측: O3c 는 탐침과 같은 해시, O3 는 common 이 없으므로 O3c 와 같은 바이트(해시 같음 예상), 두 `.i` 같음.
   - 탐침 해시는 빌드 전에 Python 으로 기록한다.
3. 판정: L1 O3·O3c OBJECT_MATCH, 경계 증명, `.i` 표지 전부 07 존재(없으면 원문 그대로 채택)이면 **A** 다. 7 함수 중 원본 심볼 4 개만 functions.tsv(high)에 올린다. static 3 개는 원본 심볼이 없으므로 행을 만들지 않고 증거에만 적는다(이전 관행 확인 후).
4. 헤더 채택이 있으면 회귀가 필요한지 판단한다(원문 그대로 채택은 07 우선 스테이징 바이트가 같아 회귀 불필요 — 이전 관행).
- 정정(코딩 전, 선례 확인): functions.tsv 는 static 함수도 행으로 둔다. 예: `x86-0x1898bc` 의 symbol 칸 `(static dma_buf_sm_create; Ghidra FUN_001898bc)`. 그래서 7 함수 모두 행으로 올린다(static 3 개는 같은 표기).
- 탐침 O3c sha256 `75be59ca…`(빌드 전 기록).

### 92.1 codex 교차검토(QS10 은 지연으로 중단, QS10b 축약) 판정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| README 정의상 A 가능. 단 OBJECT_MATCH 가 객체 전체와 참조를 덮고 경계 바이트가 독립 확인되어야 | 92 절 Python: 앞 `00 00`, 뒤 `00 00 00`, 최소 채움 3; static 3 개 = Ghidra `FUN_0017a4f0`·`FUN_0017a594`·`FUN_0017a6f4`(주소 일치, Python) | ✅ 최종 빌드에서 다시 확인 |
| 36.1 불필요(`__data`·common·bss 없음) | 탐침 섹션 목록 `[('__text', 1657, 50)]` | ✅ |
| A 는 객체 일치이지 역사적 원문 증명이 아님 | README:22 | ✅ 기존 문구 그대로 |

### 92.2 결과 (S5-P66, 2026-10-02) — `vm_policy.c` **A**

- 07 원문 그대로 채택했다(sha `aca8ff47…`).
- 빌드 `s5p66-build-1`: 예측 일치. O3 = O3c = 탐침 `75be59ca…`, 두 `.i` 같음, O2 다름.
- L1 OBJECT_MATCH 7/7(참조 50 검증). 경계 앞 `00 00`·뒤 `00 00 00` 을 다시 확인했다. `.i` 표지 123 개 모두 07 에 있다.
- 표: functions +7 → 576, objects_confirmed +1 → 65(A 63), PROVENANCE +1 → 346, 증거 `x86-vm_policy.md`. 헤더 채택이 없어 회귀는 필요 없다.

## 93. S5-P67 세부 계획 — `vm/vm_fault.c` 탐침(복원 수정 1 곳) (코딩 전, 2026-10-02)

사실(91.2, capstone diff, Python):
- 원본 [0x172038, 0x173a68) 6704 B, 5 함수(`_vm_fault`·`_vm_fault_wire`·`_vm_fault_unwire` 0x1735f4·`_vm_fault_copy_entry`·`_vm_fault_wire_fast`). Darwin 그대로 빌드는 6688 B 이고 4 함수의 간격이 같다.
- `_vm_fault_unwire` 168/152 B:
  - 원본은 `pmap_extract` 결과가 0 이면 `push 0x1e09c1; call _panic` 한다. 문자열은 "unwire: page not in pmap"(Python 으로 원본 바이트를 읽음).
  - Darwin `vm_fault.c:1234–1235` 는 `if (pa == (vm_offset_t) 0)` / `continue;` 다.
  - NeXTMach `vm_fault.c:1251–1253` 은 `if (pa == (vm_offset_t) 0) {` / `panic("unwire: page not in pmap");` / `}` 다.

탐침(스테이징 사본만, D014 R1·R2, NeXTMach D013):
- E1: Darwin :1235 `continue;` 를 NeXTMach :1252 `panic("unwire: page not in pmap");` 로 바꾼다. 중괄호는 Darwin 문체를 유지해 넣지 않는다(코드 동일). 변형 1/3.
- 예측(R5): `__text` 6704 B, 5 함수 간격이 모두 원본과 같고, `__cstring` 에 그 문자열이 추가된다. L1(O3c, 객체 이름 범위)은 OBJECT_MATCH 또는 bss/common 의존 MATCH_UNVERIFIED 다. O3·O3c·O2·`.i` 두 개를 빌드한다.
- 일치하면 다음 회차에 채택 계획(36.1·경계·`.i` 검사·표)을 세운다.

### 93.1 codex 교차검토(QS11) 판정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| 줄 번호 정확, 수정은 문법상 온전하고 최소 | 93 절 `cat -A` 출력(Darwin :1230–1240), NeXTMach :1251–1253 `sed` | ✅ |
| 다른 차이: Darwin `entry->vme_start` 대 NeXTMach `entry->start` → Darwin 필드 유지 | 두 `sed` 출력 | ✅ (계획도 Darwin 필드 유지) |

### 93.2 결과 (S5-P67, 2026-10-02) — 탐침 1: **OBJECT_MATCH 5/5**

- `s5p67-probe-1`(diff `06_reconstruction/evidence/x86-vm_fault-probe1.diff`): O3 = O3c `9148cba6…`(common 없음), O2 `0ada66f7…` 다름, 두 `.i` 같음(`8b7528d3…`).
- `__text` 6704 B·재배치 275 로 예측과 같다. `__data` 282 B.
- L1(O3, 객체 이름 범위): OBJECT_MATCH 5/5, 차이 0. `__data` 는 L1d 로 추론·검증된다.
- 다음(94): 채택. 경계, `.i` 검사, `__data` 배치 근거, 표.

## 94. S5-P68 세부 계획 — `vm/vm_fault.c` 채택 (코딩 전, 2026-10-02)

사실(Python):
- 경계:
  - 앞 0 B. 0x172037 이 `c3`(ret)이고 0x172038 은 4 정렬이다. 그 `ret` 앞 함수에는 원본 심볼이 없다(0x171f00–0x172038 심볼 0 개). 이는 ddm(`ret` 0x18494b) 선례처럼 "앞 객체 끝 = 직전 ret" 이고 소유는 미확정이다.
  - 뒤 0 B. 다음은 확정 `x86-vm_init` 0x173a68 이고, 그 행의 gap_before 가 `0 (previous function ends at 0x173a68, aligned)` 다.
- `__data` 282 B 는 L1 이 0x1e08e2 에 추론·L1d 로 검증했다(차이 0). 심볼 배치가 아니라 참조 추론이다.

절차:
1. `07_kernel/src/vm/vm_fault.c` = 탐침 본문(Darwin + 93 의 E1) + 머리말 뒤 `Modified` 주석. MODIFICATIONS 행(NeXTMach :1252 출처, 근거 0x1735f4 함수·문자열 0x1e09c1), PROVENANCE 행, diff 를 남긴다.
2. 빌드 `s5p68-build-1`. 예측: O3 = O3c = `9148cba6…`(주석만 다름), 두 `.i` 같음.
3. L1 OBJECT_MATCH 5/5, `.i` 표지 07 존재(없으면 원문 그대로 채택).
4. 판정: 앞 경계는 "0 B, 직전 `ret` 소유 미확정" 이라 ddm 선례와 같은 처리다. ddm 은 P 였지만 그 이유는 bss/const 였고 앞 경계는 문제 삼지 않았다(증거 확인 후 확정). 따라서 **A** 후보다. 단 `__data` 가 추론 배치이므로 A 의 "모든 섹션 검증" 조건을 README 로 다시 확인한다.
5. 표: objects_confirmed +1, functions +5(high), PROVENANCE +1(+채택 헤더), MODIFICATIONS +1, 증거.

### 94.1 codex 교차검토(QS12) 판정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| A 는 `__data` 의 심볼 배치를 요구하지 않음. 선례 `x86-PCemulateREAL`(단일 참조 배치 + L1d) | README:23, objects_confirmed.tsv:58 | ✅ |
| 앞 0 B(`ret` 뒤) A 선례: `x86-vm_user`(ret 0x17c4df)·`x86-machine`(ret 0x15de67). 단 "앞 함수가 심볼 없음" 까지 같다는 근거는 아님 | objects_confirmed.tsv:53·57 출력 | ✅ |
| `ret` 이 앞 함수의 끝점임을 따로 확인해야 함 | Ghidra functions.json: `FUN_00171f6c` 몸체 조각 `[0x172010, 0x172037]` 의 end_inclusive 가 0x172037. 0x172038 앞 마지막 원본 심볼은 `_catch_exception_raise` 0x171eb0(Python) | ✅ 앞 경계 = 심볼 없는 함수 `FUN_00171f6c` 의 끝 |

### 94.2 결과 (S5-P68, 2026-10-02) — `vm_fault.c` **A**

- 07 반영: 탐침 본문 + `Modified` 주석. 주석만 더한 것인지 Python 으로 확인했다.
- 빌드 `s5p68-build-1`: 예측 일치. O3 = O3c `9148cba6…`, 두 `.i` 같음.
- L1 OBJECT_MATCH 5/5(참조 275 검증, `__data` L1d). `.i` 표지 90 개 모두 07 에 있다.
- 표: functions +5, objects_confirmed +1(A), PROVENANCE +1, MODIFICATIONS +1, 증거·diff.

## 95. S5-P69 세부 계획 — `vm/vm_resident.c` 탐침(복원 수정 2 곳) (코딩 전, 2026-10-02)

사실(91.2, capstone 나란히 보기, Python):
- 원본 [0x17a9b4, 0x17b9dd) 4137 B, 17 함수. Darwin 그대로 빌드는 4345 B 다. 함수 16 개 간격이 같고, 빌드 전용 `_vm_page_deactivate_first` 가 있으며, `_vm_page_startup` 은 1048/1028 이다.
- `_vm_page_deactivate_first`(Darwin :897–910, 주석 포함)는 원본 심볼표에 없다. Darwin 안의 유일한 호출처는 vm_object.c:526 이고, 그것은 이미 vm_object 복원에서 지웠다(89.0). 다른 호출처는 Darwin 커널 전체 grep 0 건이다.
- `_vm_page_startup` 차이:
  - 원본 0x17abe9 근처: `mov eax,[_page_size]; lea edx,[eax*8]; mov [_zdata_size],edx; push eax; push edx; call _vm_alloc_from_regions` 다. 반올림이 없다.
  - 빌드는 `page_mask` 를 더하고 `not`·`and` 하는 `round_page` 가 끼어 있다.
  - 출처는 Darwin `PALLOC_PAGES` 의 `(size) = round_page(size);` 다. `#if SHOW_SPACE` 판 :226, `#else` 판 :257 의 두 정의 모두에 있다. `SHOW_SPACE` 는 Darwin 헤더에 정의가 없으므로 `#else` 판이 쓰인다.
  - NeXTMach 은 `zdata_size = 40*sizeof(struct zone)`(:394)로 다르고 `PALLOC_PAGES` 가 없다. Mach4 도 없다.

탐침(스테이징 사본만):
- E1(D014 R1·R2): :897–911(주석·함수·뒤 빈 줄)을 지운다.
- E2(D014 R1·R2, 참조 없는 삭제): `#else` 판 `PALLOC_PAGES`(:255–261)의 `(size) = round_page(size);`(:257) 한 줄을 지운다. 새 텍스트를 쓰지 않으므로 "작성" 이 아니라 삭제형 복원 수정이다(근거: 원본 명령열). `#if SHOW_SPACE` 판은 쓰이지 않으므로 그대로 둔다(R2).
- 예측(R5): `__text` 4137 또는 4140(끝 채움) B, 17 함수 간격이 모두 같다. `_vm_page_deactivate` 인라인 변화는 바이트로 확인한다. L1(O3, 객체 이름 범위)은 OBJECT_MATCH 또는 bss/common 의존 MATCH_UNVERIFIED 다.

### 95.1 codex 교차검토(QS13) 판정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| 줄 번호, `#else` 판 선택, 매크로 연속줄 정상 | 95 절 `grep`·줄 출력, `cat -A`(:252–262) | ✅ |
| `PALLOC_PAGES` 의 다른 사용은 범위 밖이라 미확인 | 파일 전체 grep: 정의 :224·:255, 사용 :370 하나. 커널 다른 파일 0 건 | ✅ 영향은 zdata 하나 |

### 95.2 결과 (S5-P69, 2026-10-02) — 탐침 1: 크기 일치, 15/17 MATCH

- `s5p69-probe-1`(diff `x86-vm_resident-probe1.diff`): `__text` **4137 B**(원본과 같음)·재배치 256. O3 `c76be09b…`, O3c `9ea78a22…`, 두 `.i` 같음.
- L1 O3c: 15 MATCH, 2 DIFF(각 11 B).
  - `_vm_page_startup` 끝: 원본 `mov eax,[ebp+0x10]`(셋째 인자 반환, 3 B), 빌드 `mov eax,[virtual_avail]`(5 B). Darwin :423 `return(virtual_avail);` 인데, 셋째 인자 `vavail`(:264·:267)은 Darwin 안에서 쓰이지 않는다(grep).
  - `_vm_page_deactivate`: 원본은 `queue_enter` 하나뿐인 배치이고, 빌드는 Darwin static `_vm_page_deactivate(m, age)`(:854–880)의 `age` 분기(`queue_enter_first`)가 인라인되어 레이블 정렬 위치가 달라진다. NeXTMach `vm_resident.c:1014–1039` 의 `vm_page_deactivate` 는 `age` 없는 본문이다(`m->laundry` 는 `#if !MACH_XP`, MACH_XP 는 config 값 0).

## 96. S5-P70 세부 계획 — vm_resident 탐침 2 (코딩 전, 2026-10-02)

탐침 1 스테이징 위에서:
- E3(D014 R1·R2, NeXTMach D013): Darwin :843–881(static `_vm_page_deactivate` 의 주석 블록부터 정의, 뒤 빈 줄까지. 주석 시작 줄은 코딩 때 Python 으로 확정)을 지운다. Darwin `vm_page_deactivate`(:891–893 머리)는 남기고 본문 :894 를 NeXTMach :1017–1038 로 바꾼다. vm_object E4 와 같은 방식이다.
- E4(작성 D016, W1–W5): :423 `return(virtual_avail);` → `return(vavail);`. 참조에 이 문장은 없다(Darwin 은 전역 반환, NeXTMach 는 `vaddr` 를 다른 구조로 반환). 근거는 원본 `mov eax,[ebp+0x10]` 이다. W3 표시, 변형 1/3.
- 예측: `__text` 4137 B, L1 O3c 17/17 MATCH(차이 0). O3 는 `__common` 156 B 때문에 MATCH_UNVERIFIED 가 남고 36.1 은 채택 회차에 한다.

### 96.1 codex 교차검토(QS14 는 지연으로 중단, QS14b 사실 제시형) 판정

내 확인(줄 출력, Python): 도우미 주석 시작 **:844**, 정의 :854–880, 빈 줄 :881. 셋째 인자 `vavail` 은 :264·:267 이고, :423 은 `return(virtual_avail);` 다.

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| 도우미 삭제는 유일 호출처가 :894 라면 구조상 문제없음 | 탐침 1 스테이징에서 `_vm_page_deactivate` 참조는 정의와 :894 뿐(`vm_page_deactivate_first` 는 탐침 1 에서 지움) | ✅ |
| NeXTMach 본문 교체의 의미 동등성은 원본 바이트로 확인해야 | — | ✅ L1 바이트 비교가 그 확인이다 |
| `return(vavail)` 로 바꾸지 말 것 — 인자 이름은 `virtual_avail` 의 반환 시점 값과 같다는 근거가 아님 | 근거는 이름이 아니라 원본 명령이다. 원본 `_vm_page_startup` 끝 0x17adfd 는 `mov eax, dword ptr [ebp + 0x10]` 로 셋째 인자 자리를 읽는다. 빌드는 `mov eax,[virtual_avail]` 이다(95.2 capstone 출력) | ❌ 기각. 원본이 반환하는 것은 셋째 인자 자리의 값이다. 함수 안에서 그 자리에 쓰는 명령이 있는지까지 포함해 L1 이 함수 전체 바이트로 확인한다. 의미("가상 주소 진행")에 대한 주장은 하지 않는다 |

### 96.2 결과 (S5-P70, 2026-10-02) — 탐침 2: O3c **OBJECT_MATCH 17/17**

- `s5p70-probe-1`(diff `x86-vm_resident-probe2.diff`): O3 `7a9fcea4…`, O3c `a423bca0…`, 두 `.i` 같음(`ebb73de3…`), O2 다름.
- L1 O3c OBJECT_MATCH 17/17, 차이 0(`__data` 포함). `return(vavail)` 은 원본 바이트로 확인되었다(QS14b 의 반대 의견은 96.1 에서 기각).
- O3 는 3 MATCH + 14 MATCH_UNVERIFIED(`__common` 156 B)다. 다음(97)에 채택한다.

## 97. S5-P71 세부 계획 — `vm/vm_resident.c` 채택 (코딩 전, 2026-10-02)

사실(Python, 탐침 2 산출):
- 경계:
  - 앞 0x17a9b1–0x17a9b3 `00×3` 은 확정 `x86-vm_policy` 의 gap_after `3 x 00` 과 같은 바이트다.
  - 뒤 0x17b9dd–0x17b9df `00×3` 은 확정 `x86-vm_synchronize` 의 gap_before `3 x 00` 과 같고, 4 정렬 최소 3 이다.
- 36.1(O3 대 O3c):
  - `__text` 4137 B·재배치 255 대응(같은 형태 78, local→extern 141, scattered→extern 36), 밖 바이트 차이 0.
  - `__data` 172 B 차이 0.
  - common 25 개는 모두 원본 심볼이 있고 크기 ≤ 간격이다(예 `_vm_page_template` 48/48).
- `.i` 표지 122 개 중 07 에 없는 것은 대상 파일뿐이다.

절차:
1. `07_kernel/src/vm/vm_resident.c` = 탐침 2 본문 + `Modified` 주석(주석만인지 Python 확인).
2. 빌드 `s5p71-build-1`. 예측 O3 `7a9fcea4…`·O3c `a423bca0…`, 두 `.i` 같음. L1 O3c OBJECT_MATCH, O3 는 36.1 로 이전한다.
3. 판정 **A**. 표:
   - functions +17(high). `_vm_page_startup` 은 `+authored`(return) + 복원 수정(round_page 삭제), `_vm_page_deactivate` 는 NeXTMach 본문.
   - objects_confirmed +1, PROVENANCE +1, MODIFICATIONS +1, 증거·diff.

### 97.1 codex 교차검토(QS15) 판정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| O3c 기준으로 A 는 타당 | README:23 | ✅ |
| `-fno-common` 판 자체는 OBJECT_MATCH 가 아님 | 36.2 결정: "앞으로 `__common` 정의를 가진 파일은 이 두 판 방식으로 판정한다". 선례 ipc_table·vm_object | ⚖️ 사실은 맞다. 등급은 36.2 의 두 판 규칙으로 준다(새 결정 아님) |
| 복원 수정·작성 토큰은 PROVENANCE·MODIFICATIONS 에 기록 | — | ✅ 절차 3 |

### 97.2 결과 (S5-P71, 2026-10-02) — `vm_resident.c` **A**

- 빌드 `s5p71-build-1`: 예측 일치. O3 `7a9fcea4…`, O3c `a423bca0…`, 두 `.i` 같음. L1 O3c OBJECT_MATCH 17/17. `.i` 표지 122 개 모두 07 에 있다.
- 표: functions +17, objects_confirmed +1(A), PROVENANCE +1, MODIFICATIONS +1, 증거·diff.

## 98. S5-P72 세부 계획 — `vm/vm_pageout.c` 탐침 1: `vm_pageout()` (코딩 전, 2026-10-02)

사실(91.2, capstone, Python):
- 원본 [0x179d44, 0x17a23e) 1274 B = `_vm_pageout_scan` 864 + `_vm_pageout` 410. 앞은 확정 vm_object(뒤 3 B), 뒤는 확정 vm_pager(앞 2 B `90`)다.
- 원본 `_vm_pageout`(0x17a0a4):
  - `ebx = 1`(`did_work` 지역) 다음 `active_threads[0]->(+0x78) = 1`(`vm_privilege`), `spl0`.
  - 매개변수 초기화. `vm_page_free_reserved` 가 0 이면 **3 만 대입**한다(`/4` 계산 없음).
  - 루프는 Darwin 형태다(`did_work` 가 0 이면 잠, `free_count > free_min` 등). 결과 `ebx = vm_pageout_scan()`.
  - `stack_privilege` 호출과 `sched_pri`·`priority`·`policy`·`sched_data` 대입이 없다.
- Darwin `vm_pageout`:
  - :376 `self = current_thread()`, :379 `stack_privilege(self)`, :380–382 sched 필드 대입, :383 `self->vm_privilege = TRUE`.
  - :404–410 은 `if ((vm_page_free_reserved = vm_page_free_min / 4) < 3) … = 3;`(위 cat 출력으로 범위 확정).
- NeXTMach `vm_pageout`: `current_thread()->vm_privilege = TRUE;`, :724–726 `if (vm_page_free_reserved == 0) {` / `//\t\tif ((… / 4) < 3)` / `\t\t\tvm_page_free_reserved = 3;`.

탐침 1(스테이징 사본만, D014 R1·R2, NeXTMach D013):
- P1: :379–382(`stack_privilege` 와 sched 3 줄)을 지운다. `self` 지역과 :383 은 유지한다.
- P2: `vm_page_free_reserved` 블록의 `if ((… / 4) < 3)` 줄을 NeXTMach :725 처럼 주석 처리하는 대신 지운다(R2: 동작 근거만, 주석 처리도 결과는 같지만 지우는 쪽이 diff 가 작다). `vm_page_free_reserved = 3;` 만 남긴다.
- 예측: `_vm_pageout` 크기 410 B 로 바이트 일치(`self` 지역이 레지스터/스택 배치를 바꾸면 차이가 나므로, 그 경우 `self` 를 없애고 NeXTMach 의 `current_thread()->vm_privilege = TRUE;` 로 바꾸는 변형 2 를 한다). `_vm_pageout_scan` 은 이번에 고치지 않는다(932 그대로).

### 98.1 codex 교차검토(QS16 지연 중단 → QS16b) 판정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| :379–382·:408 삭제 뒤에도 `self`(:383)가 쓰이고 :409 는 유효한 문장 → 온전 | 98 절 줄 출력(Python)·`cat -A`(:404–412) | ✅ |
| 남는 논리는 0 일 때만 3 대입, 원본과 같음 | 원본 0x17a10c–0x17a115 | ✅ |
| :405–407 주석("0.50% …")이 지운 계산을 설명하면 고칠 것 | 주석 내용 확인 | ⚖️ 사실은 맞다. 다만 R2(Darwin 문체·주석 유지, 최소 수정)에 따라 주석은 두고, MODIFICATIONS 에 "주석은 원문 그대로, 계산은 삭제" 를 적는다 |

### 98.2 결과 (S5-P72, 2026-10-02) — `vm_pageout()` 바이트 일치(변형 2)

- 탐침 1 `s5p72-probe-1`(P1·P2): `_vm_pageout` 412 B(원본 410 + 끝 `90 90`, vm_pager 앞 채움과 같음)다. 차이는 오프셋 5·10–13 의 명령 순서다. 빌드는 `self = current_thread()` 를 먼저 읽고, 원본은 `ebx = 1` 이 먼저다.
- 탐침 2 `s5p72-probe-2`(변형 2: `self` 지역을 없애고 :383 을 NeXTMach `vm_pageout.c:706` `current_thread()->vm_privilege = TRUE;` 로): `_vm_pageout` 재배치 밖 바이트 차이 **0**(Python). diff 는 `x86-vm_pageout-probe2.diff` 다.
- `_vm_pageout_scan` 은 그대로 932/864 다(다음 절).

## 99. S5-P73 세부 계획 — `vm_pageout_scan` (코딩 전, 2026-10-02)

사실(98 절 호출 순서 비교, Python):
- 원본 `_vm_pageout_scan` 호출 23 개는 빌드의 앞 23 개와 순서·대상이 같다.
- 빌드에만 끝에 `thread_will_wait`·`thread_set_timeout`·`thread_block` 3 호출이 있다. 이것은 Darwin :353–364 의 "IO 도 해제도 없으면 양보" 블록이다(`if (!pages_cleaned && !pages_freed && did_work) {…}`).
- 크기 차이는 932 − 864 = 68 B 다.

탐침 3(탐침 2 위에서, D014 R1·R2):
- S1: :353–364 블록(주석 포함, `if` 부터 닫는 `}` 까지. 정확한 범위는 코딩 때 Python 으로 확정)을 지운다.
- 예측: `_vm_pageout_scan` 이 864 B 에 가까워진다. `pages_cleaned` 는 :131·:290 에서 아직 쓰이므로 남긴다. 남은 차이는 바이트 비교로 기록한다(함수당 변형 한도 3, 이번이 scan 변형 1).

### 99.1 codex 교차검토(QS17) 판정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| :353–365 삭제는 최소·온전 | 99 절 줄 출력(Python) | ✅ |
| :131·:290 참조만으로는 두 변수가 계속 "쓰인다" 는 근거가 아님 | grep: `pages_cleaned` 는 :131 에서 읽힌다(살아 있음). `pages_freed` 는 :123 대입·:180 증가뿐이다(:334 는 `//` 주석). 삭제 후 `pages_freed` 는 쓰기 전용이 되어 코드 생성이 바뀔 수 있다 | ✅ 바이트로 판정 |
| 호출 목록만으로 제어 흐름 일치를 증명할 수 없음 → 바이트 비교 | — | ✅ |

### 99.2 결과 (S5-P73, 2026-10-02) — scan 932 → 880 B, `__data` 차이 발견

- `s5p73-probe-1`(diff `x86-vm_pageout-probe3.diff`): `__text` 1292 B(scan 880 + pageout 412)다. L1 `__text` unplaced, `__data` fail.
- `__data` 8 B: `_vm_page_free_min_sanity` 는 빌드 `0x40000`(Darwin :54 `256*1024`), 원본 `0x20000` 이다(Python 바이트). NeXTMach `vm_pageout.c:75` 가 `128*1024` 다.
- scan 정규화 diff(capstone, 주소를 N 으로):
  - 원본에는 `pages_cleaned` 가 없다. 지역 초기화가 1 개 적고, 목표 비교가 `cmp [free_target], free_count; jge` 다(Darwin :131 은 `(vm_page_free_count + pages_cleaned) >= …`, NeXTMach :488 은 `vm_page_free_count >= vm_page_free_target`).
  - Darwin :290 `pages_cleaned++` 에 대응하는 `inc [ebp-4]` 가 원본에 없다.
  - 나머지 차이는 스택 오프셋과 정렬 nop 이다.

