# IDA Pro 분석

- `snapshots/`: 기존 DB 두 개의 보존용 복사본. 자동 갱신/편집하지 않는다.
- `databases/`: 실제 분석용 작업 DB. 보존본을 복제해서 사용했다.
- `exports/<arch>/`: functions, names, structs, xrefs, pseudocode 등 텍스트 결과.
- `notes/`: import/분석 설정, 버전, 실패 및 수동 판정 기록.

스냅샷 이름은 `ps2-mach_kernel.i64`, `matrox-mach_kernel.i64`이다.
복사 전후의 원본 해시와 stat이 안정적인지 검사하지만,
작업 DB를 열어 autoanalysis 완료 및 Hex-Rays 사용 가능 상태를 확인했다.
DB가 보고한 입력 경로는 기록된 원본 위치와 일치했으며 image base는 `0x100000`이었다.
그러나 내부 바이트 패치 여부는 독립 검증하지 못했으므로 기준 자료는 원본 SHA를 확인한 Ghidra export다.
기존 DB 안의 이름/타입/주석은 이전 분석자의 해석이며 원본 심볼과 구별한다.

실행 전 대상 DB·원본 SHA-256·processor·bitness·image base를 확인한다.
autoanalysis 완료 후 결과를 읽고 IDAPython은 현대 `ida_*` API를 사용한다.
IDA 버전, decompiler 버전/가용 여부, 적용 스크립트, 분석 범위를 기록한다.

현재 자료:

- `databases/x86-full.i64`, `databases/x86-matrox-review.i64`: 작업 복사본.
- `exports/x86/full-pass1/batch-*.json`: PS2 DB 대상 주소별 Hex-Rays 원시 응답.
- `exports/x86/alternate-db/batch-*.json`: 실패 주소 및 추가 진입점의 Matrox DB 재시도 응답.
- `exports/x86/index.json`: 요청 주소, DB별 성공·오류, 결과 경로·해시.
- `exports/x86/functions/*.c`: 성공한 보조 pseudocode.
- `exports/x86/failures.json`: 양쪽 DB에서 출력 확보에 실패한 주소.
- `databases/m68k-os42j.i64`, `exports/m68k/initial-*.json`: OPENSTEP 4.2J m68k
  원본의 별도 32비트 big-endian 초기 autoanalysis DB와 함수·segment 인벤토리.
- `databases/sparc-os42j.i64`, `exports/sparc/initial-*.json`: OPENSTEP 4.2J SPARC
  원본의 별도 32비트 big-endian 초기 autoanalysis DB와 함수·segment 인벤토리. 이 DB는
  별도 probe로 확인한 `-psparcb` 설정으로만 생성했다.
- `databases/sparc-os42j-ida-loader-little-endian-rejected.i64`와
  `exports/sparc/failures/`: 자동 Mach-O loader가 `sparcl`/little-endian DB를 만든
  거부 기록이다. 이 DB의 함수·타입·디컴파일 결과는 분석 근거로 사용하지 않는다.

MCP의 함수 열거·assembly export·바이트 조회는 실행 승인 정책으로 거부되었다.
허용된 주소별 decompile로 자료를 확보했으며, 요청 주소 집합은 Ghidra와 원본 메타데이터에서 가져왔다.
따라서 독립적인 IDA 전체 분석 export로 보고하지 않는다.
성공 주소 4,519개, 실패 주소 244개를 보존했다. 실패를 Ghidra 결과로 바꿔 IDA 성공으로 집계하지 않는다.
전체 바이너리의 assembly는 Ghidra listing과 별도 Capstone 원시 바이트 listing을 참조한다.
Ghidra와 다른 결과는 후속 근거 대조 대상이며, pseudocode는 GCC 2.7용 복원 소스가 아니다.

m68k·SPARC의 함수 수는 IDA 자동분석 후보 수이며, 서로 또는 x86 함수 수와 합산하지 않는다.
원본 해시, Mach-O CPU type·magic, processor, `inf_is_be()`, DB 경로는 run마다 함께
검증한다.
