# Ghidra 분석

- `projects/`: 로컬 Ghidra 프로젝트(.gpr/.rep). 커밋 제외.
- `exports/x86/`, `exports/m68k/`, `exports/sparc/`, `exports/future_arch/`: 함수 목록, 타입, xref, 디컴파일 텍스트.
- `notes/`: 로딩 설정·분석 옵션·예외 및 수동 판정.

현재 x86 기준은 `exports/x86/full-pass5/`, 저장 프로젝트는 `projects/x86-full.gpr`이다.
Ghidra 12.1 headless, Mach-O loader, `x86:LE:32:default`, compiler spec `gcc`를 사용했다.
이 compiler spec 선택은 GCC 2.7 빌드 검증이 아니다.

m68k와 SPARC의 OPENSTEP 4.2J 입력은 각각 `projects/m68k-os42j.*`·`exports/m68k/`와
`projects/sparc-os42j.*`·`exports/sparc/`에만 기록한다. 두 대상은 big-endian이며,
x86 project·export·함수 수와 병합하지 않는다.

- `manifest.json`: 원본 SHA-256, image base, 버전·설정값, 최종 export 상태.
- `whole-program.asm`, `code-units.tsv`, `memory-blocks.json`: 전체 매핑 영역 listing 및 분류.
- `functions.json`, `functions/<address>.c`, `.asm`, `.json`: 모든 함수·분석 조각의 결과와 본문 범위.
- `symbols.tsv`, `references.tsv`, `data-types.json`: 심볼·참조·도구 타입 해석.
- `coverage.json`, `failures.json`: 도구 단계의 범위·실패 기록.
- `notes/full-pass*.log`, `notes/full-pass*-script.log`: 실행 기록.

최종 독립 검증은 [전체 분석 보고서](../09_validation/reports/full-analysis/README.md)를 따른다.
export manifest의 `coverage_audit_complete: false`는 exporter가 독립 검증을 수행하지 않는다는 뜻이며,
후속 Python 검증 결과는 `09_validation/reports/full-analysis/audit.json`에 분리했다.
`progress.json`은 중간 스냅샷이므로 최종 합계에는 `manifest.json`을 사용한다.

`__analysis_fragment_*`는 함수 밖 코드의 자료 확보를 위한 인위적인 분석 단위다.
실제 callable 함수나 확정된 ABI로 취급하지 않는다. 기존 함수의 no-return 추론으로
누락된 후속 명령, fault recovery 경로 등은 원래 문맥과 함께 재검토해야 한다.
자동 적용된 `mac_osx` 타입 자료도 OPENSTEP ABI의 확정 근거가 아니다.

MCP Ghidra 연결 대신 설치된 Ghidra를 `10_tools/run_ghidra.py`로 실행했다.
설정·캐시·임시 파일은 프로젝트 안의 `projects/runtime/`에 저장하며 사용자 HOME은 변경하지 않는다.
이전 pass는 발견·수정 이력으로 보존한다. `full-pass3`는 수정 입력 누락으로
보완이 적용되지 않은 재export이며 최종 기준으로 쓰지 않는다.
실제 코드 보완은 `full-pass4`, 남은 주소 테이블 분류 및 설정·타입 export는 `full-pass5`에 반영했다.

후속 MCP 접속 시에도 먼저 로드된 프로그램 목록과 대상 바이너리 해시를 확인한다.
Mach-O loader가 원본 세그먼트/주소를 보존했는지 `03_original` 인벤토리와 대조한다.
Ghidra 버전, loader/language/compiler spec, 분석 옵션, 원본 SHA-256, image base,
실행 날짜, 성공/실패 범위를 `notes/<run-id>.md`에 기록한다.
함수·타입·xref는 작은 범위로 조회하고 pagination 누락을 확인한다.

후속 서브시스템별 export 이름은 `<arch>/<subsystem>/<address>_<symbol>.<c|json|txt>`를 권장한다.
주소 변환이나 rebase를 했다면 원본 VA와 분석 VA의 관계를 기록한다.
디컴파일 텍스트를 곧바로 07_kernel의 복원 소스로 간주하지 않는다.
서로 다른 도구의 해석이 다르면 `06_reconstruction/evidence/`에서 비교한다.
