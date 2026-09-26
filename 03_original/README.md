# 기준 바이너리

`x86/binaries/mach_kernel`은 기존 로컬 보관본의 복사본이다.
`manifest.json`에 원래 위치, 크기, SHA-256, 스냅샷 상태가 기록된다.
`prepare.py`는 기존 보존 파일을 다른 내용으로 덮어쓰지 않는다.
`sparc/`, `m68k/`, `future_arch/`는 아키텍처별 기준 파일 경로다. `sparc/`와
`m68k/`의 현재 기준 파일은 OPENSTEP 4.2J 설치 ISO의 UFS `/mach_kernel` Fat
컨테이너에서 직접 분리한 원본 슬라이스다. 컨테이너·UFS 경로·해시·오프셋은
`installation-media/os42j/provenance.json`에 기록한다.

`x86/inventory/`의 `macho.json`, `symbols.tsv`, `strings.tsv`는
`10_tools/prepare.py`로 직접 파싱한 원시 인벤토리이다.
함수 경계·타입·호출 관계의 Ghidra/IDA 분석 결과가 아니다.
문자열 offset은 파일 offset이고, symbols의 value와 sections의 address는 가상주소다.
심볼 항목에는 data/debug/undefined도 포함될 수 있다. 그 개수는 함수 수가 아니다.

`objc.json`은 로컬 SDK 구조 정의와 원본 바이트에서 추출한 Objective-C 메타데이터이다.
그 안의 Ghidra 누락 비교는 최초 `full-pass1` 기준 발견 기록이며,
보완 후 최종 누락 여부는 `09_validation/reports/full-analysis/audit.json`을 따른다.
`inventory/llvm/`에는 구형 LC_UNIXTHREAD flavor를 처리하지 못한 LLVM 실행 실패 기록이 있다.
독립적인 원시 바이트 역어셈블은 `09_validation/static/full-analysis/text-linear.asm`을 참조한다.
