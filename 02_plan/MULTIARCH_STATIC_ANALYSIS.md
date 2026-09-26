# m68k·SPARC 원본 커널 정적 분석 계획

## 범위와 입력

2026-09-21 사용자 지시에 따라 OPENSTEP 4.2J 설치 ISO에서 확보한 m68k·SPARC
`mach_kernel`을 별도 정적 분석 대상으로 둔다. 입력의 원본 ISO, UFS 경로, Fat Mach-O
슬라이스와 해시는 [OS42J provenance](../03_original/installation-media/os42j/provenance.json)에
고정한다.

CD 구조 확인을 위해 사용자가 지정한 `OPENSTEP_BOOTCD` 작업 공간의 UFS 읽기 도구와
문서만 사용했다. 커널 의미·타입·제어 흐름의 근거에는 그 작업 공간의 분석물이나 외부
코드를 사용하지 않는다. 원본 커널 바이트와 그 바이트에서 직접 만든 분석 출력만 사용한다.

구현, 소스 복원, 빌드, QEMU, 재부팅 및 다른 동적 실행은 이 계획의 범위 밖이다.

## byte order 불변식

사용자 지정 규칙: Intel i386은 little-endian이고 m68k와 SPARC는 big-endian이다.

| 대상 | Mach-O magic 바이트 | metadata parser | 분석 시 금지 |
|---|---|---|---|
| i386 | `CE FA ED FE` | little-endian | m68k·SPARC 입력에 i386 byte order 적용 |
| m68k | `FE ED FA CE` | big-endian | i386 load command·nlist·주소 필드 해석 재사용 |
| SPARC | `FE ED FA CE` | big-endian | i386 load command·nlist·주소 필드 해석 재사용 |

각 대상의 Mach-O header, load command, section, relocation, nlist, Objective-C metadata의
다중 바이트 필드는 해당 표의 byte order로 파싱한다. 역어셈블러/디컴파일러의 processor와
endianness 설정도 원본 magic 및 CPU type과 대조해 기록한다. 한 아키텍처의 함수 경계,
타입, 호출 규약 또는 의미를 다른 아키텍처의 확정 근거로 사용하지 않는다.

## 분석 산출물 격리

| 종류 | m68k | SPARC | x86와의 관계 |
|---|---|---|---|
| 원본 | `03_original/m68k/` | `03_original/sparc/` | x86 원본을 입력으로 사용하지 않음 |
| 원시 Mach-O inventory | `03_original/m68k/inventory/` | `03_original/sparc/inventory/` | 서로의 JSON·TSV를 합치지 않음 |
| Ghidra project/export | `04_ghidra/projects/m68k-os42j.*`, `04_ghidra/exports/m68k/` | `04_ghidra/projects/sparc-os42j.*`, `04_ghidra/exports/sparc/` | `x86-full`과 별개 project/run ID |
| IDA database/export | `05_ida/databases/m68k-os42j.i64`, `05_ida/exports/m68k/` | `05_ida/databases/sparc-os42j.i64`, `05_ida/exports/sparc/` | x86 DB·snapshot·export를 열거나 수정하지 않음 |
| 검증 보고서 | `09_validation/reports/m68k-*` | `09_validation/reports/sparc-*` | 합산 coverage·함수 수를 만들지 않음 |

모든 분석 run은 시작 전에 선택한 원본의 SHA-256, Fat slice CPU type, Mach-O magic,
endianness를 함께 기록하고, 종료 뒤에도 같은 해시를 다시 확인한다. 경로·해시·CPU type이
다르면 결과를 다른 아키텍처 자료로 취급하고 인용하거나 병합하지 않는다.

## 순서와 산출물

1. 원본 컨테이너와 분리 슬라이스의 SHA-256·크기·Fat entry 범위를 Python으로 다시 검증한다.
2. 대상별 big-endian raw Mach-O inventory를 만든다. header, segment, section, symbol,
   문자열의 원본 파일 offset 및 가상주소를 분리해 기록한다.
3. 대상별 독립 Ghidra 프로젝트를 만들고 CPU/endianness/loader 설정 및 입력 SHA-256을 남긴다.
4. 모든 load 영역의 listing, code/data/undefined 분류, 함수·fragment별 assembly와
   decompiler 출력을 내보낸다.
5. 원본 섹션 범위를 분모로 coverage, 누락 entry, 함수 밖 instruction, export 실패를
   대상별로 검증한다.

각 단계는 확보한 정적 자료만 판정한다. 의미 정확성, ABI, 소스 복원 및 실행 결과를
완료로 표시하지 않는다.
