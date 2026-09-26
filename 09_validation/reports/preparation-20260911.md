# 준비 검증 — 2026-09-11

Kind: preparation. 커널 기능/부팅 검증 결과가 아니다.

| 검사 | 결과 |
|---|---|
| 로컬 기준 커널 두 출처의 SHA-256 비교 | 일치: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890 |
| 원본 크기/형식 | 1,117,920 bytes; 32-bit little-endian Mach-O; CPU type 7, subtype 3 |
| 빌드 문자열 | NeXT Mach 4.2; mk-183.34.4; RELEASE_I386; Jan 26 1999 |
| 원본/스냅샷 해시 검증 | 4개 출처 기록 검사 통과. 기준 커널 복사본 1개 + IDA DB 복사본 2개 |
| Mach-O 파싱 및 저장 결과 재검증 | 통과. load command 7개; 세그먼트·섹션·심볼·문자열 인벤토리 생성 |
| 심볼 집계 | nlist 3,751개; 정의된 외부 심볼 3,751개. 함수 수로 해석하지 않음 |
| 기존 독립 도구와 비교 | ../openstep-emu10k1/tools/kernel_symbols.py와 외부 심볼 이름 전체 집합 일치: 3,751개 |
| 도구/작업 구조 | Python 문법 검사, 상대 미러 링크, 최상위 디렉터리 숫자 prefix 검사 통과 |
| 바이너리/IDA DB git ignore | 세 보존 파일 모두 커밋 제외 확인 |
| 공개 소스 수집 | GitHub 2개 + SourceForge 4개 파일 모두 DNS 오류. 다운로드 미완료 |
| Ghidra 분석/IDA 재분석 | 미실행. 기존 IDA DB 내부의 입력 해시/분석 내용은 아직 미검증 |
| 커널 빌드/부팅 | 미실행 |

재검증 명령(프로젝트 루트):

```sh
python3 10_tools/prepare.py --verify
python3 ../openstep-emu10k1/tools/kernel_symbols.py 03_original/x86/binaries/mach_kernel
```

스냅샷은 원래 파일을 이동하거나 덮지 않고 보존했다.
공개 소스 수집 성공 경로는 실제 네트워크 다운로드로 검증하지 못했다.
