# x86 전체 분석 자료 확보 결과

2026-09-11. 대상은 OPENSTEP 4.2 / mk-183.34.4 / RELEASE_I386이다.
원본 SHA-256은 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`이다.

전체 역어셈블·디컴파일 **자료 확보와 누락 검사**를 완료했다.
이는 원본 소스의 유일한 복원, 모든 함수의 의미 이해, 디컴파일러 해석의 정확성,
GCC 2.7 빌드 또는 부팅 성공을 뜻하지 않는다. `07_kernel` 구현은 진행하지 않았다.

## 검증 결과

수치는 Python 검증 결과 [audit.json](audit.json), [evidence-audit.json](evidence-audit.json)을 따른다.

| 항목 | 결과 |
|---|---:|
| Ghidra 일반 함수 분류 항목 | 4,761 |
| 별도 인위적 분석 조각 | 492 |
| assembly와 pseudocode를 확보한 분석 단위 | 5,253 |
| 최종 Ghidra export 실패 | 0 |
| 원본 `__text` 크기 | 851,436바이트 |
| 명령 / 데이터 / 정렬 분류 | 824,512 / 6,368 / 20,556바이트 |
| 미표현 바이트 / 비정렬 미분류 구간 / 소속 없는 명령 구간 | 0 / 0 / 0 |
| 원본 코드 심볼·ObjC IMP 누락 | 없음 |
| 확보한 Objective-C 메서드 진입점 | 1,137 |
| 경고가 포함된 함수·분석 조각 | 884 |
| IDA 보조 pseudocode 성공 / 실패 주소 | 4,519 / 244 |

모든 Ghidra 메모리 블록의 listing 연속성과 code-unit 목록의 일치를 검사했다.
함수·분석 조각별 assembly 주소 범위가 선언된 본문 바이트와 일치하고,
각 단위에 실제 디컴파일러 출력이 존재함을 검사했다.
독립적인 Capstone linear listing의 원시 바이트는 원본 `__text` 전체와 일치한다.
Capstone linear decode는 데이터·정렬도 명령처럼 해석할 수 있으므로 코드/데이터 구분의 정답으로 쓰지 않는다.
영역 분류는 정적 분석 결과이며, 이 검사가 실행 가능한 모든 동작의 의미를 증명하지는 않는다.

최종 Ghidra export 파일 15,770개와 추출 참고 파일 2,489개의 해시를 재검증했다.
공개 소스의 고정 commit·아카이브 해시 및 로컬 원본·IDA 스냅샷 해시도 확인했다.
IDA 실패 주소 244개 모두에 Ghidra pseudocode가 있다. IDA 자체 실패 상태는 그대로 유지했다.

## 자료 위치

| 자료 | 위치 |
|---|---|
| 기준 바이너리·원시 Mach-O/심볼/문자열 인벤토리 | `03_original/x86/` |
| 원본에서 추출한 Objective-C 메타데이터·헤더 근거 | `03_original/x86/inventory/objc.json` |
| Ghidra 저장 프로젝트 | `04_ghidra/projects/x86-full.gpr` |
| 최종 Ghidra listing·함수·참조·타입·설정 | `04_ghidra/exports/x86/full-pass5/` |
| Ghidra 실행·분석 로그 | `04_ghidra/notes/full-pass*.log` |
| IDA 작업 DB·보존 스냅샷 | `05_ida/databases/`, `05_ida/snapshots/` |
| IDA 주소별 결과·DB별 원시 응답·실패 기록 | `05_ida/exports/x86/` |
| 원시 바이트 전체 linear disassembly | `09_validation/static/full-analysis/text-linear.asm` |
| 코드 누락 보완·데이터 오인 수정 계획 | `09_validation/static/full-analysis/gap-actions.json` |
| 공개 Git 소스·추출 Darwin 소스 | `01_resources/upstream/` |
| 소스 출처·해시·추출 파일별 해시 | `01_resources/manifests/` |

위 경로는 프로젝트 루트 기준이다. Ghidra 함수별 파일명은 주소이며,
이름·범위는 `functions.json`, `analysis_fragment` 여부도 같은 목록에 있다.
이전 pass와 최초 누락 기록은 이력으로 보존하며 현재 판정에는 사용하지 않는다.
`full-pass3`에는 보완 스크립트 입력 누락 실패가 있으므로 수정 완료 pass로 취급하지 않는다.
최종 기준은 `full-pass5`와 이 디렉터리의 독립 검증 결과다.

## 한계와 후속 검토

- `__analysis_fragment_*`는 자료 누락을 막기 위한 인위적인 분석 단위다.
  no-return 추론 뒤의 명령, fault recovery 블록 등의 본래 제어 흐름·레지스터 문맥은 재결합해야 한다.
  별도의 실제 함수나 정확한 함수 프로토타입이 복원되었다는 뜻이 아니다.
- [decompiler-warnings.json](decompiler-warnings.json)에 no-return, 호출 규약 미상,
  겹치는 전역 심볼, 간접 jump의 call 해석, 타입 전파 등 경고를 보존했다.
  출력 성공은 경고 해소나 의미적 동등성 검증이 아니다.
- Ghidra가 자동 적용한 `mac_osx` 타입과 `gcc` compiler spec은 분석 설정이다.
  OPENSTEP/GCC 2.7 ABI의 확정 근거로 사용하지 않는다.
- IDA의 독립 함수 열거·assembly export·바이트 읽기 MCP는 승인 정책으로 거부되었다.
  허용된 주소별 decompile만 사용했다. IDA DB 내부 바이트 패치 여부는 미검증이다.
  따라서 IDA 자료는 보조이며 양 도구가 독립적으로 전체 분석에 성공했다고 주장하지 않는다.
- LLVM 도구는 구형 LC_UNIXTHREAD flavor를 처리하지 못해 실패했다.
  실패 로그를 원본 인벤토리 아래 보존하고, 독립 바이트 listing에는 Capstone을 사용했다.
- 원래 주석·매크로·파일 배치는 바이너리만으로 확정할 수 없다.
  소스 계보·함수/타입/ABI 대응, GCC 2.7 실제 빌드와 부팅 검증은 후속 작업이다.
- SPARC와 미확정 후속 CPU는 이번 분석 범위가 아니다.

## 재검증

프로젝트 루트에서 실행한다. 계산은 모두 Python으로 수행한다.

```sh
python3 10_tools/prepare.py --verify
python3 10_tools/verify_full_analysis.py
python3 10_tools/verify_evidence.py
```

`verify_full_analysis.py`는 최종 분석 파일을 읽고 이 디렉터리의 감사·해시 목록을 갱신한다.
이후 `verify_evidence.py`는 그 목록, 전체 mapped listing, 참고 소스 및 IDA 출력 해시를 검사한다.
검증 스크립트 자체가 함수의 의미적 정확성을 판정하지는 않는다.
`audit_full.py`와 `objc_inventory.py`의 Ghidra 비교는 최초 pass 기준 진단용이다.
