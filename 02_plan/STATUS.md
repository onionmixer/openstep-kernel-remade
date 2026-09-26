# 현재 상태 — 2026-09-11

x86 기준 바이너리의 전체 분석 **자료 확보 단계**를 완료했다.
이는 원본 소스 복원이나 디컴파일 결과의 의미적 정확성 검증 완료를 뜻하지 않는다.
자세한 증거·한계·경로는 [전체 분석 보고서](../09_validation/reports/full-analysis/README.md)에 있다.

- Ghidra 최종 기준: `04_ghidra/exports/x86/full-pass5/`, 저장 프로젝트 `04_ghidra/projects/x86-full.gpr`.
  일반 함수로 분류한 항목 4,761개와 별도 분석 조각 492개에 assembly·pseudocode를 저장했다.
  분석 조각은 독립적인 실제 함수로 세지 않는다. export 실패는 없다.
- 원본 `__text` 851,436바이트를 명령·데이터·정렬로 분류했다.
  미표현 바이트, 비정렬 미분류 구간, 함수/분석 조각 밖 명령 구간은 없다.
  원본 코드 심볼과 Objective-C 메서드 진입점의 누락 검사를 통과했다.
- IDA 보조 자료: 주소별 디컴파일 성공 4,519개, 실패 244개 및 원시 응답 보존.
  독립적인 IDA 전체 함수 열거·assembly export와 DB 내부 바이트 검증은 권한 제한으로 미수행이다.
- Ghidra 경고가 있는 함수/분석 조각 884개를 별도 목록으로 보존했다.
  함수 경계, 호출 규약, 타입, 간접 분기 등의 의미 검토는 후속 작업이다.
- 사용자 요구: 모든 계산은 Python으로 수행한다.
- 구현, 커널 빌드/부팅은 아직 수행하지 않았다.
- 사용자 요구 확정: 최종 커널 소스는 GCC 2.7에서 컴파일 가능해야 한다.
  정확한 2.7.x/NeXT 수정판 식별 및 실제 컴파일 검증은 P3에서 수행할 미완료 항목이다.
- x86 로컬 기준: NeXT Mach 4.2, mk-183.34.4, RELEASE_I386 (내장 문자열 기준).
- 두 로컬 커널 보관본 SHA-256:
  `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`.
- 로컬 복사·기초 인벤토리 결과: `03_original/manifest.json`, `03_original/x86/inventory/`.
  원본/스냅샷 해시, 저장 인벤토리 재검증 및 기존 도구와 외부 심볼 전체 3,751개 대조를 통과했다.
- 기존 IDA 스냅샷은 보존하고 작업 복사본을 열어 autoanalysis 완료와 Hex-Rays 사용 가능 상태를 확인했다.
  입력 경로는 확인했으나 DB 내부 바이트 패치 여부는 미검증이다.
- Ghidra MCP 대신 설치된 Ghidra 12.1을 프로젝트 내부 설정 경로를 사용하는 headless 방식으로 실행했다.
- 공개 소스 수집 완료: Git 저장소 2개 + Darwin 아카이브 3개 + 라이선스 1개.
  사용자가 일반 터미널에서 다운로드한 결과를 검증했다.
  kernel/driverkit 파일은 확장자와 달리 plain tar여서 기존 검사기가 거부했다.
  검사기를 수정하고 기존 `.part` 전체를 검증하여 재다운로드 없이 복구했다.
  고정 commit, 파일 SHA-256, 실제 압축 형식은 `01_resources/manifests/acquisition.json`에 기록했다.
- Darwin 아카이브를 `01_resources/upstream/darwin01/`에 추출하고 파일별 해시를
  `01_resources/manifests/darwin-extraction.json`에 기록했다.
- 2026-09-21 사용자 제공 OPENSTEP 4.2J 설치 ISO의 UFS `/mach_kernel`에서 SPARC와
  m68k 원본 슬라이스를 확보했다. 원본 컨테이너와 추출 근거는
  `03_original/installation-media/os42j/provenance.json`에, 별도 정적 분석 규칙은
  `02_plan/MULTIARCH_STATIC_ANALYSIS.md`에 기록한다.
- m68k·SPARC의 big-endian raw Mach-O inventory와 각 IDA Pro 9.3 초기 DB·함수별
  assembly corpus를 전용 경로에 기록했다. SPARC 자동 loader의 little-endian DB는 거부
  기록으로 격리했으며, `-psparcb`로 확인한 big-endian DB만 유효 자료로 사용한다.
  근거와 범위는 `09_validation/reports/multiarch-input-20260921/README.md`를 따른다.
- 원본 nlist와 IDA 함수 후보 시작 주소도 각 Mach-O 범위에 독립 대조했다. absolute nlist는
  주소 범위 밖을 오류로 처리하지 않고 별도 분류했으며, 두 대상에서 non-absolute unmapped
  심볼과 `__text` 밖 함수 후보 시작점은 없다.
- 함수 후보와 독립적으로 두 canonical IDA DB에서 원본 `__text` 전체 item inventory를
  만들고, 각 export 행의 주소·file offset·길이·바이트가 원본과 연속 일치함을 검증했다.
  IDA의 code/data/unknown 표시는 아직 도구 가설로 유지한다.
- canonical DB는 보존한 채 복사 working DB에서 m68k·SPARC의 모든 Mach-O load range도
  별도 item inventory로 export했다. `__PAGEZERO`은 file byte·loader item이 없는 address-zero
  guard range로 명시적으로 제외했고, file-backed range의 `original_bytes`는 원본 file offset에
  전수 대조했다. zero-fill virtual range에는 원본 파일 byte가 없으므로 원본 byte 비교를
  주장하지 않는다. m68k의 file-backed IDA value는 원본과 일치하지만 SPARC에서는 DB value와
  원본 byte가 다를 수 있어 두 값을 분리해 보존한다. 이 차이는 loader·runtime memory·의미의
  근거가 아니다. 근거는
  `09_validation/reports/multiarch-input-20260921/all-load-units-validation.json` 및
  `09_validation/reports/multiarch-input-20260921/sparc-file-backed-ida-value-differences-audit.json`에
  있다.
- 두 canonical IDA DB의 전체 xref를 아키텍처별 TSV로 export했다. 모든 source endpoint는
  원본 mapped 영역 안에 있고, outside destination은 의미 판단 없이 보존한다. m68k의
  unknown 6바이트도 근거 부족으로 DB를 수정하지 않고 unknown으로 유지한다.
- 30회 연속 정적 감사는 25개 원본 구조·바이트·경로 불변식 통과와 5개 비확정 관측을
  분리해 보존했다. 관측값을 함수 경계·의미·code/data 확정으로 사용하지 않는다.
- 2026-09-22의 별도 30회 연속 감사는 원본 hash·big-endian IDA 조건·xref endpoint·unknown
  보류·SPARC raw `__OBJC` NUL-section evidence를 순차 대조했다. 통과 28개와 비확정 관측
  2개를 분리했으며, 집계는
  `09_validation/reports/multiarch-continuous-20260922/aggregate.json`에 보존했다.
- continuation 2에서도 같은 원본 불변식을 새 전용 경로에서 30회 순차 대조해 통과 28개와
  비확정 관측 2개를 분리했다. 집계는
  `09_validation/reports/multiarch-continuous-20260922-continuation2/aggregate.json`에 보존했다.
- steps3에서도 원본 불변식을 새 전용 경로에서 30단계 순차 대조해 통과 28개와 비확정 관측
  2개를 분리했다. 집계는
  `09_validation/reports/multiarch-continuous-20260922-steps3/aggregate.json`에 보존했다.
- canonical big-endian IDA DB에서 Hex-Rays capability를 비변경 probe했다. m68k·SPARC
  모두 모듈 import는 됐지만 plugin 초기화는 실패했으므로 pseudocode를 생성하지 않았다.
  원본 해시 재계산을 포함한 검증은
  `09_validation/reports/multiarch-input-20260921/ida-decompiler-capability-validation.json`에
  보존했다.
- 원본 big-endian segment와 `__text` item을 교차한 xref endpoint audit에서 m68k 241,893개,
  SPARC 311,716개 출발점은 모두 mapped 영역에 있었다. 도착점은 code·data·unknown·mapped
  밖 분포만 기록했고, m68k unknown 6바이트 범위의 도착점 1개는 보류 상태를 유지했다. IDA
  item·xref 분류는 의미 판정에 사용하지 않으며, 원시 분포는
  `09_validation/reports/multiarch-input-20260921/xref-source-kind-audit.json`에 보존했다.
- 원본 `__OBJC` word-layout은 m68k section 0개와 SPARC file-backed·4바이트 정렬 section
  20개를 분리해 big-endian 32비트 값으로 감사했다. 값의 mapped section 일치는 pointer·
  Objective-C metadata·동작 의미로 판정하지 않으며, 근거는
  `09_validation/reports/multiarch-input-20260921/objc-word-layout-audit.json`에 보존했다.
- SPARC `__OBJC`의 flag `0x2` file-backed section 세 개를 7,527개 NUL-delimited raw byte
  record로 export하고, record address·file offset과 TSV 재조합 payload를 원본에 대조했다.
  section layout을 runtime 의미로 해석하지 않으며, 검증은
  `09_validation/reports/multiarch-input-20260921/objc-nul-section-tsv-validation.json`에
  보존했다.
- canonical SPARC xref 중 이 raw record 시작 주소에 닿는 4,293개 행은 주소 경계 교차
  사실로만 기록했다. record text·xref type을 runtime 의미로 해석하지 않으며, 근거는
  `09_validation/reports/multiarch-input-20260921/sparc-objc-nul-xref-endpoint-audit.json`에
  보존했다.
- 이 4,293개 xref 출발점은 모두 원본 SPARC `__OBJC` segment와 `__text` 밖에 분포한다.
  section 배치는 runtime 의미로 해석하지 않으며, 근거는
  `09_validation/reports/multiarch-input-20260921/sparc-objc-nul-xref-source-audit.json`에
  보존했다.
- 원본 bytes·계산 target·type-17 xref를 전수 대조한 direct-call edge corpus는 m68k BSR
  10,521개·JSR 22개와 SPARC CALL 17,607개를 보존한다. 이는 control-transfer edge만
  확정하며 callee behavior·ABI·함수 의미는 후속 검증 대상이다. 근거는
  `09_validation/reports/multiarch-input-20260921/direct-call-edge-tsv-validation.json`에
  보존했다.
- direct-call corpus 전체의 인접 item도 원본 bytes로 대조했다. m68k 10,543개 CALL의 다음
  item은 모두 code이고 직전 data item은 2개다. SPARC 17,607개 CALL의 post-delay item은 모두
  code이고 predecessor·delay-slot data item은 각각 2개다. 여섯 non-code adjacency 예외는 raw
  context와 current candidate ownership으로 따로 보존했다. 이는 argument preparation·delay-slot
  실행·call return·ABI의 증거가 아니다. 근거는
  `09_validation/reports/multiarch-input-20260921/multiarch-direct-call-adjacency-audit.json`과
  `09_validation/reports/multiarch-input-20260921/direct-call-adjacency-noncode-exceptions-audit.json`에
  보존했다.
- raw direct target entry에서 m68k `LINK` 562개와 SPARC IDA `save` 2,465개의 immediate/register
  bit fields를 Python으로 추출했고, lexical-exit endpoint와 구조적으로 교차했다. 이는 stack
  frame·local·argument·calling convention·ABI를 확정하지 않는 raw instruction 관측이다. 근거는
  `09_validation/reports/multiarch-input-20260921/direct-target-entry-frame-operand-observations.json`과
  `09_validation/reports/multiarch-input-20260921/direct-target-entry-exit-structure-audit.json`에
  보존했다.
- 원본 `_start` entry transition과 startup direct-call 네 개씩을 raw bytes·symbol·xref로
  검증했다. direct-call source 후보 범위 교차에서 m68k source 1,127개가 원본 `__text` gap
  66개에 있어 함수 경계 review 대상으로 보존했고, gap 자체를 missing function·code/data
  오류로 단정하지 않는다. 근거는
  `09_validation/reports/multiarch-input-20260921/direct-call-function-candidate-coverage.json`과
  `09_validation/reports/multiarch-input-20260921/m68k-direct-call-outside-function-candidates.json`에
  보존했다.
- m68k의 66개 direct-call source gap은 시작·끝 item과 첫·마지막 call endpoint를 원본
  big-endian bytes로 대조했다. endpoint 표본 120개의 BSR/JSR target은 Python 계산과 type-17
  xref에 일치하며, 1,127개 source 전체의 즉시 다음 item은 원본 code item으로 같은 gap 안에
  있다. 이는 static adjacency·boundary 관측일 뿐 call return·reachability·function ownership·
  ABI·동작을 확정하지 않는다. 근거는
  `09_validation/reports/multiarch-input-20260921/m68k-direct-call-gap-boundary-endpoints-audit.json`와
  `09_validation/reports/multiarch-input-20260921/m68k-gap-direct-call-next-item-audit.json`에 보존했다.
- 양 아키텍처 startup direct-call 네 개씩의 바로 앞·call·바로 뒤 code item도 원본 bytes와
  대조했다. 이 인접 명령 관측은 인자값·calling convention·ABI·return value·side effect를
  확정하지 않는다. 근거는
  `09_validation/reports/multiarch-input-20260921/startup-direct-call-adjacency-audit.json`에 보존했다.
- startup callee 여덟 entry는 raw symbol·원본 code item·IDA 후보 시작점에 일치한다. SPARC
  네 entry의 같은 opening bytes pattern은 ABI가 아닌 entry boundary 관측으로 보존한다. 근거는
  `09_validation/reports/multiarch-input-20260921/startup-callee-entry-candidate-audit.json`에 보존했다.
- SPARC 후보 범위 밖 direct-call source 28개는 원본 `__text`의 단일 gap
  0xf0003aa4–0xf0004e70에 있고, 모든 CALL instruction을 원본 big-endian bytes와 대조했다.
  이 gap도 missing function·code/data 오류·ABI·동작의 증거가 아닌 함수 경계 review 대상으로
  유지한다. 근거는
  `09_validation/reports/multiarch-input-20260921/sparc-direct-call-outside-function-candidates.json`에
  보존했다.
- 같은 SPARC gap의 CALL 28개는 source window·delay slot·post-delay item·Python `disp30`
  target·type-17 xref·target code entry를 모두 원본 big-endian bytes로 대조했다. target은
  현재 IDA 후보 시작점이지만, delay-slot 실행·call return·gap ownership·reachability·ABI·동작은
  미확정이다. 근거는
  `09_validation/reports/multiarch-input-20260921/sparc-gap-direct-call-window-audit.json`에 보존했다.
- 모든 고유 direct-call target entry도 원본 bytes로 대조했다. m68k 2,313개와 SPARC 2,607개의
  target을 lexical-exit 후보 분류와 연결했으나, raw entry pattern과 IDA mnemonic은 function
  boundary·prologue semantics·calling convention·ABI·인자·반환값·동작의 증거가 아니다. 근거는
  `09_validation/reports/multiarch-input-20260921/direct-call-target-entry-observations.json`에 보존했다.
- 이 SPARC gap 직전 후보는 raw branch·delay slot 뒤에서 끝나며, Python으로 계산한 branch
  target은 gap 밖이다. gap으로 들어오는 direct control xref 152개는 모두 gap 내부 source에
  있다. 이 관측은 function boundary·runtime reachability·interrupt behavior·ABI·동작을
  확정하지 않는다. 근거는
  `09_validation/reports/multiarch-input-20260921/sparc-direct-call-gap-boundary-observation.json`에
  보존했다.
- 후보 함수 시작점과 일치하지 않은 m68k direct-call target 다섯 건은 모두 raw symbol
  `_mini_mon` 0x4093976이며, source BSR.L과 target first code item을 원본 big-endian bytes로
  대조했다. 이 결과는 direct-call destination과 code-item start만 뒷받침하며 함수 경계·ABI·
  인자·반환·callee semantics는 미확정으로 유지한다. 근거는
  `09_validation/reports/multiarch-input-20260921/m68k-direct-call-target-noncandidate-review.json`에
  보존했다.
- `_mini_mon` 0x4093976은 raw symbol·BSR.L 다섯 개·target `4e56fefc`·이후 첫 lexical
  `UNLK`/`RTS` pair `4e5e`/`4e75`를 원본 big-endian bytes와 대조했다. 이것은 제한된 함수
  경계 evidence이고, control-flow reachability·전체 extent·ABI·인자·반환·동작은 미확정으로
  유지한다. 근거는
  `09_validation/reports/multiarch-input-20260921/m68k-mini-mon-boundary-evidence.json`에 보존했다.
- 같은 `_mini_mon` 제한 구간의 prologue·register save/restore·lexical exit 및 `a6` relative
  code item 20개도 원본 bytes와 대조했다. positive/negative offsets는 frame-layout 가설의
  근거일 뿐 인자·local variable·ABI·type·value·동작을 확정하지 않는다. 근거는
  `09_validation/reports/multiarch-input-20260921/m68k-mini-mon-frame-access-observation.json`에
  보존했다.
- `_mini_mon` entry부터 첫 lexical `RTS` 직후까지의 연속 text item 347개는 원본 bytes와
  대조했지만 code 346개와 data item `02d6` 하나를 포함한다. 따라서 그 bounded range를 연속
  code 또는 완전한 function extent로 확정하지 않는다. 근거는
  `09_validation/reports/multiarch-input-20260921/m68k-mini-mon-bounded-text-layout-audit.json`에
  보존했다.
- m68k 0x409ce56–0x409ce5c 원본 6 bytes는 독립 big-endian decoder에서 sequential instruction
  후보를 낼 수 있으나, code/data·도달성을 판별하지 못한다. IDA unknown state를 유지하고 DB는
  수정하지 않는다. 근거는
  `09_validation/reports/multiarch-input-20260921/m68k-unknown-independent-decoder-observation.json`에
  보존했다.
- 함수 후보 전체 lexical-exit 감사에서 m68k 3,214개 중 3,019개, SPARC 5,075개 중 4,936개가
  원본 return opcode를 포함한다. lexical-exit 부재 후보의 terminal direct branch·jump/call·BSR
  및 SPARC delay-slot window도 원본 bytes로 분류했으며, 이는 함수 경계·제어 흐름 review 근거일
  뿐 runtime target·reachability·ABI·동작은 미확정이다. 근거는
  `09_validation/reports/multiarch-input-20260921/function-candidate-lexical-exit-audit.json`과
  `09_validation/reports/multiarch-input-20260921/noexit-terminal-direct-branch-audit.json`에 보존했다.
- m68k register-indirect terminal jump 16개는 provenance window로 제한 분류했고, indexed
  dispatch 후보 8개 뒤의 contiguous code-start pointer word 112개를 원본 big-endian bytes와
  대조했다. pointer run은 complete dispatch table·index bound·runtime target을 확정하지 않는다.
  근거는 `09_validation/reports/multiarch-input-20260921/m68k-indexed-jump-pointer-run-audit.json`에
  보존했다.
- 후속 JSR·remaining-window 감사를 포함한 no-exit terminal raw-coverage closure에서 m68k
  195개와 SPARC 139개 candidate 모두가 raw encoding 또는 bounded raw-window 감사에 배정됐고,
  미배정은 0개다. 이는 terminal byte/window coverage의 종료일 뿐 transfer semantics·path
  reachability·함수 경계·ABI·return behavior·동작은 미확정이다. 근거는
  `09_validation/reports/multiarch-input-20260921/noexit-terminal-raw-coverage-closure-audit.json`에
  보존했다.

다음 작업:

수집한 원본 바이너리와 원본 바이트에서 유도한 분석 출력만으로 함수 경계·제어 흐름·ABI
가설을 제한적으로 검증하는 일이 후속 단계다.
이번 실행에서는 다음 단계 구현으로 넘어가지 않았다.
