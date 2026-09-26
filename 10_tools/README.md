# 준비·분석·검증 도구

준비 도구는 Python 3 표준 라이브러리와 Git을 사용한다. 어느 디렉터리에서 실행해도
스크립트 위치로 프로젝트 루트를 찾는다. sudo가 필요하지 않다.

```sh
python3 10_tools/prepare.py
python3 10_tools/prepare.py --verify
python3 10_tools/fetch_sources.py
```

`prepare.py`는 최초 원본 해시를 고정하여 복사본 변경을 감지한다.
기존 IDA DB가 후속 작업으로 변경되면 기존 스냅샷을 덮지 않고 중단한다.
새 스냅샷은 다른 이름과 새로운 획득 기록으로 추가해야 한다.
`--verify`는 파일을 수정하지 않는다.

`fetch_sources.py`는 각 자료를 독립적으로 시도하고 하나라도 실패하면 종료 코드 1이다.
Git checkout은 origin/clean status/commit을 검사하며 자동 pull/reset하지 않는다.
기존 `.part`가 남으면 네트워크 요청 전에 전체 아카이브를 검증한다.
정상 파일이면 완료 파일로 이름을 바꾸며 다시 다운로드하지 않는다.
실제로 손상된 `.part`는 그대로 보존하고 오류를 표시한다. 이 경우 보존/이동 후 재시도한다.
완료한 자료는 재다운로드하지 않고 hash/commit을 확인한다.
Darwin 아카이브는 실제 헤더로 gzip/plain tar를 구분하고 모든 tar 멤버 데이터를 읽어 검증한다.
gzip이면 압축 스트림 CRC도 검사한다. 배포 파일명은 유지하며 실제 형식은 manifest에 기록한다.
`kernel-1.tar.gz`, `driverkit-139.1-1.tar.gz`는 이번 수집본에서 plain tar임을 확인했다.
웹 페이지를 소스 압축 파일로 저장한 경우 성공 처리하지 않는다.
`fetch_sources.py` 자체는 압축 해제·빌드·실기 반영을 수행하지 않는다.

## 전체 분석 도구

- `extract_references.py`: 검증된 Darwin 아카이브를 새 디렉터리에 추출하고 모든 파일 해시 기록.
  기존 추출 디렉터리가 있으면 병합·덮어쓰기하지 않고 중단한다.
- `run_ghidra.py`: 로컬 Ghidra 12.1을 프로젝트 내부 설정 경로로 headless 실행.
  현재 설치 경로와 프로젝트 이름을 사용하므로 다른 환경에서는 먼저 설정을 확인한다.
- `ghidra/ExportKernel.java`: 전체 listing·함수/분석 조각·타입·참조·옵션 export.
- `ghidra/RepairAndAudit.java`, `CompleteCode.java`, `MarkPointerArrays.java`: 작업 DB의
  누락 entry, 코드 조각, 데이터 오인을 보완한 스크립트. 원본 바이트는 수정하지 않는다.
- `audit_full.py`: Capstone을 사용한 원시 바이트 전체 linear listing 및 최초 pass 진단.
- `objc_inventory.py`: 원본 ObjC 메타데이터 파싱. Ghidra 누락 비교는 최초 pass 기준.
- `prepare_gap_actions.py`: 원본 바이트·분석 이력에서 보완 작업 목록 작성. Capstone 필요.
- `consolidate_ida.py`: 보존된 IDA 원시 응답을 주소별로 색인. 실패 상태도 유지.
- `verify_full_analysis.py`: 최종 `full-pass5`의 본문·출력·원본 코드 영역 누락 검증 및 해시 기록.
- `verify_evidence.py`: 전체 mapped listing, 최종 export 해시, 소스 수집·추출 해시,
  IDA 출력 해시 및 실패 주소의 Ghidra 자료 존재 여부를 검사.
- `collect_llvm.py`: LLVM 실행 기록 수집. 이번 바이너리는 legacy thread flavor로 실패했으므로
  이 출력은 성공한 disassembly가 아니다.

주요 산출물과 한계는 [전체 분석 보고서](../09_validation/reports/full-analysis/README.md)를 따른다.
분석 스크립트는 GCC 2.7로 빌드할 커널 소스가 아니라 호스트용 도구다.
주소 변환·개수·크기·coverage 등 계산은 사용자 요구에 따라 Python에서 수행한다.
