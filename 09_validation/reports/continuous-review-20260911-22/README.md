# 신중한 추가 검토 22 — 사용자 매핑 전환과 정상 copyin

## 판정

원본 root 비교/CR3 쓰기 조각으로 합성 사용자 매핑을 전환한 뒤, 전체
`_copyin`/`_copyinmsg`의 정상 경로 384시험이 통과했다. 초기 이중 매핑뿐 아니라
사용자와 커널의 같은 오프셋이 서로 다른 물리 메모리를 가리키는 조건을 검사했다.

이는 **혼합 세그먼트 합성 상태의 정상 경로 검증**이다. 실제 부팅, 전체
문맥 전환, 사용자 권한 집행 또는 fault 복구가 검증됐다는 뜻은 아니다.
커널 원본 결함 판정이나 전체 분석 완료 판정도 하지 않는다.

코딩 전에 독립 Codex 계획 교차검토를 수행했고, 원본 assembly 및 Python 계산으로
지적을 재확인했다. 이후 추가 검토가 발견한 시험 패턴의 약점도 수정하고 재실행했다.
모델의 승인이나 동의는 정확성 근거로 사용하지 않았다.

## 결과 요약

| 항목 | 보강 후 결과 |
|---|---:|
| 원본 root 선택 구간 실행 | 4단계 |
| 실제 CR3 쓰기 분기 / 같은 root 생략 분기 | 3 / 1 |
| memory API와 원본 FS 읽기 구분 검사 | 4통과 |
| 전체 copyin/copyinmsg 정상 호출 | 384통과 |
| 그중 source 페이지 경계 횡단 | 80 |
| 잘못된 두 번째 페이지 alias 예측과 구별 | 80 |
| 길이 0 대조 | 48 |
| copy 명령 방문 / 고유 명령 시작점 | 19,400 / 151 |
| 실행된 FS→ES REP 명령 위치 | 6 |
| 잘못된 직접 물리 source 모델과 구별 | 336 |

수치, 주소, 페이지 인덱스, 비트 연산, 예상 바이트 및 해시는 모두 Python으로 계산했다.
도구 버전과 CPU 제어 레지스터 값은 JSON에 기록했다. Unicorn의 기본 CPU/TLB 모드를
실제 OPENSTEP CPU 사양이라고 가정하지 않았다.

## 코딩 전 계획 및 교차검토

[PLAN.md](PLAN.md)는 새 시험 코드 작성 전에 만든 범위·통과 조건·독립 확인 기록이다.
주요 채택 조건은 다음과 같다.

- 초기 low/high PDE가 같은 table을 공유하므로, root와 변경할 low table을 모두 별도 복제한다.
- 원본 CR3 쓰기 자체를 register API 호출로 대체하지 않는다. 동일 root 분기도 검사한다.
- DS/ES/SS의 높은 base와 FS의 낮은 base를 구분한다. CS가 flat인 합성 상태는 명시한다.
- `_copyin` 긴 경로의 인자 슬롯 변경 및 짧은 성공의 recover 유지 동작을 보존한다.
- memory API의 주소 해석은 실행 관찰로 확인한다. code-cache helper와 하드웨어 TLB 효과를 혼동하지 않는다.

[CROSS_REVIEW.md](CROSS_REVIEW.md)에 사후 검토와 수정 근거도 보존했다.
최초 패턴은 페이지마다 같은 내용이 반복되어 페이지 선택 오류를 놓칠 수 있었다.
그 통과 결과를 충분한 검증으로 채택하지 않았다. 보강 후 각 컨텍스트의 페이지 간
같은 오프셋 바이트가 모두 다름을 확인했고, 잘못된 페이지 alias 예측도 따로 검사했다.

## 원본 구간과 합성 상태의 경계

기존 보고서21의 fixture와 원본 `_pmap_bootstrap`을 사용해 초기 paging을 설정했다.
원본 GDT relocation 구간을 실행하고, `_start`의 `0x00186117..0x00186124` 구간으로
DS/ES/SS를 설정했다. 원본 MOV FS 명령도 실행했다.

선택 상태는 CS=`0x48`, DS/ES/SS=`0x10`, FS=`0x50`이다.
**실제 `_start`의 `0x00186110` far jump를 실행하지 않았으므로 CS는 flat이다.**
이 의도적인 혼합 상태에서 코드와 데이터의 고정 매핑을 유지하며 정상 copy 의미를
분리해 시험했다. 실제 kernel CPU 상태 전체를 재현한 것으로 부르지 않는다.

사용자용 root/table 생성은 harness가 수행한 합성 작업이다. 실제 사용자 pmap
생성 함수의 결과라고 주장하지 않는다. 원본 초기 root에서 복제한 다음 낮은 버퍼용
table만 별도 분리했으며, 다음 매핑을 Python walker로 검사했다.

| 컨텍스트 | 낮은 선형 주소 → 물리 주소 | 높은 커널 선형 주소 → 물리 주소 |
|---|---|---|
| A | `0x600000 → 0x900000` | `0xc0600000 → 0x600000` |
| B | `0x600000 → 0xa00000` | `0xc0600000 → 0x600000` |

이어지는 페이지도 독립 검사했다. 낮은 buffer PTE table과 높은 buffer PTE table은
다르며, 코드·스택·GDT·시험용 메타데이터의 필요한 매핑도 확인했다.
U/S·write 비트 검사는 page-table 내용 검사이지 CPL3 접근 권한의 실행 검증이 아니다.
PAE가 켜진 상태는 이번 two-level walker의 범위 밖으로 두고 거부한다.

## 원본 root 선택과 디컴파일 누락

`_switch_context`에서 아래 구간만 원본 실행한다.

```text
0018d3e7  MOV EAX,[EAX+0x1c]
0018d3ea  CMP [EDX+0x1c],EAX
0018d3ed  JZ 0018d3f2
0018d3ef  MOV CR3,EAX
```

각 메모리 operand의 입력 구조는 합성 fixture이다. 초기 root→A→B→B→A로
실행하며, B→B에서는 CR3 쓰기 주소에 도달하지 않음을 확인했다.
전체 `_switch_context`의 스레드 선택, LDT/TSS 설정, 스택 전환은 실행하지 않았다.

보고서18의 보존된 Ghidra export를 대조하면 위 원본 명령의 raw-pcode는 있지만
대응 high-pcode는 없고 함수 전체의 명시적 CR3 varnode 쓰기도 없다.
해당 C는 canonical C와 정규화 후 일치한다. 새 Ghidra 실행이나 DB 교정은 하지 않았다.

FS scalar 읽기는 현재 root의 사용자 패턴을 읽었다. Python으로 이전 root를 계속
사용했을 때의 값을 예측하면 root가 실제로 바뀐 단계에서는 다른 값이고, 같은 root
단계에서는 같다. 따라서 선택한 조건에서는 CR3 변경을 생략해도 같은 동작이라는
해석이 성립하지 않는다. 이는 하드웨어 TLB의 모든 동작을 검증한 결과는 아니다.

## memory API 검사와 전체 복사

API `mem_read`로 buffer 오프셋을 직접 읽은 값과, 원본 FS scalar 명령이 같은
오프셋을 읽은 값이 다름을 매 단계 확인했다. 후자는 현재 root의 Python page walk가
예측한 사용자 물리 페이지와 일치했다. 이 시험에서 API는 backing 물리 메모리 검사에
사용했다. 모든 Unicorn backend/API 모드의 의미를 일반화한 결론은 아니다.

전체 함수 시험은 DF=0, 길이 0/1/15/16/17/19/31/64, 정렬과 source 페이지 경계를
포함한다. 각 호출에서 다음을 확인했다.

- 전체 커널 목적지 버퍼가 예상 내용과 같고, 다른 위치의 guard 바이트가 유지됨.
- 사용자 A/B 버퍼 모두 변경되지 않음.
- 반환값, 반환주소, 반환 후 ESP 및 callee-saved 레지스터가 예상과 같음.
- 짧은 정상 호출의 recover 유지와 긴 정상 호출의 recover 해제가 원본 흐름과 같음.
- CR3 선택 조각·FS scalar·copy의 방문 PC backing 바이트가 실행 후 원본과 같음.

마지막 검사는 bootstrap/segment 설정 전체의 이번 새 trace 검사나 실제
instruction-fetch 변환의 독립 증명은 아니다. 또한 guard 검사는 지정한 버퍼
범위이며 전체 물리 RAM에 예상 밖 쓰기가 없다는 전수 검사는 아니다.

잘못된 직접 물리 source 모델과 잘못된 두 번째 페이지 alias 모델은 명시적인
Python 반사실 예측이다. 실제로 컴파일한 디컴파일 C 또는 전체 raw-pcode 실행으로
부르지 않는다. 결과는 복원 시 사용자 주소와 커널 주소의 문맥을 구분해야 한다는
근거이지, 기존 C 표현의 모든 가능한 외부 주소 변환 규약을 부정하는 증거가 아니다.

## 보존·재현 및 남은 범위

원본 바이너리·기존 분석 산출물·정본 및 기존 실험 Ghidra 프로젝트를 읽기 전용 해시
검사했다. 원본, 기존 보고서, Ghidra/IDA DB 및 `07_kernel`을 변경하지 않았다.
새 보고서 디렉터리의 코드/문서/결과만 추가했다.

```sh
python3 -B 09_validation/reports/continuous-review-20260911-22/user_mapping_review.py
python3 -B 09_validation/reports/continuous-review-20260911-22/verify_artifacts.py
```

[실행 코드](user_mapping_review.py), [최종 실행·원본/pcode 대조 결과](user-mapping-review.json),
[실행 전 보존 검사](preservation-before.json), [입력 해시](input-hashes.json),
[보존 검사 코드](verify_artifacts.py), [최종 보존 검사](verification.json),
[산출물 해시](artifact-hashes.json).

남은 작업: 실제 사용자 pmap 생성·전체 문맥 전환과 최종 CS 상태, fault 진입/복구,
POP FS 출처, 사용자 권한/세그먼트 limit, copyout 방향, 비동기 인터럽트 및 실제
TLB/캐시 효과. GCC 2.7 구현·빌드·부팅과 canonical 분석 교정도 이번 작업에 포함하지 않았다.
