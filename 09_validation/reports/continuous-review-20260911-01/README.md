# 연속 추가검토 — 복구 주소의 포인터 출처와 간접 호출

대상: OPENSTEP 4.2 mk-183.34.4 / x86, 검토일 2026-09-11.
원본 SHA-256: `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`.
앞선 검토: [신중한 추가검토](../cautious-followup-20260911/README.md).

## 이번에 달라진 판정

앞서 포인터 출처를 미확정으로 남긴 복구 주소 저장 후보 36곳 모두에 대해,
**현재 thread 포인터가 함수 인자를 거쳐 해당 저장 명령에 도달하는 정상 호출 경로**를 확인했다.
기존 직접 로드 사례 14곳을 포함하여 검사한 50곳 모두 이 출처 연결 근거를 갖게 되었다.
이는 아래 호출 규약·정적 테이블 가정하의 결과이며 모든 실행 상태에 대한 증명은 아니다.

이전 보고서를 덮어쓰지 않고 이 문서에서 근거의 진전을 기록한다.
복구 진입점의 출처 확인과 실제 fault 후 스택·레지스터 복구 검증은 다른 항목이다.
후자는 아직 끝나지 않았으며 전체 분석을 완료 처리하지 않는다.

Ghidra·IDA 스킬을 사용하되 이번 증거는 보존된 Ghidra listing과 원본 파일의 독립 재해석이다.
라이브 Ghidra/IDA DB 편집이나 커널 구현 변경은 하지 않았다.
모든 주소 연산·비트 연산·집계·데이터 흐름 계산은 Python으로 수행했다.

## P01 — 현재 thread에서 PC emulation까지의 연결

원본 `_catch_trap`의 `0x001870de` 호출 직전 첫 번째 인자는
`_active_threads`의 메모리 위치 `0x001e8b54`에서 읽은 포인터다.
이 인자는 `_PCexception` (`0x001a13a0`)으로 전달된다.

이후 다음 관계를 원본 instruction 기반으로 추적했다.

```text
_active_threads
  └─ _catch_trap → _PCexception(thread, state)
       ├─ _PCemulateREAL(thread, state)
       │    ├─ 직접 호출 helper
       │    └─ 원본 inst_table의 간접 호출 handler → 직접 호출 helper
       └─ _PCemulatePROT(thread, state)
            └─ 직접 호출 helper → 추가 helper
```

`_PCexception`의 REAL 호출 위치는 `0x001a14bb`, PROT 호출 위치는 `0x001a14c9`다.
각 호출에서 첫 번째 인자가 그대로 전달된다. PC 함수군의 후보 저장 36곳은
자신의 첫 번째 인자에서 나온 포인터의 `+0x74`에 복구 주소를 저장한다.

검사는 함수 내부 분기를 따라 레지스터와 스택 인자 슬롯의 출처를 전파한다.
다른 경로에서 출처가 충돌하면 확정값을 버리고 unknown으로 병합하며,
부분 레지스터 쓰기나 지원하지 않는 레지스터 변경도 기존 출처를 무효화한다.
단순히 명령 파일의 앞쪽에서 같은 레지스터 이름을 찾은 결과가 아니다.

검사한 분석 단위 33개에서 처리하지 못한 명시적 CFG 이탈 간선은 0개였다.
이 수치는 fault·interrupt·비지역 복귀까지 모델링했다는 의미가 아니다.
정상 CALL은 반환 가능성의 과대 근사로 취급하고, 실제 비복귀 함수의 후속 경로를 증명하지 않는다.

각 저장 위치까지의 호출 경로는 [주소별 출처 연결](dispatch-and-provenance-paths.json)의
`candidate_links`에 있고, 함수 내부 결과는 [데이터 흐름](provenance-flow.json)에 있다.

## P02 — 직접 호출 검색에서 빠질 수 있는 명령 handler 테이블 확인

`_PCemulateREAL`은 `0x001a2635`에서 opcode byte에 `0x70`을 더하고,
`0x001a2650`에서 zero-extended index로 `0x001e4b80`의 포인터 테이블을 읽는다.
`0x001a2668`의 `CALL EAX`에는 동일한 첫 번째 thread 인자가 전달된다.

Python으로 원본의 256개 little-endian 포인터를 읽고 byte wraparound를 반영했다.
nonzero 슬롯은 6개이며 모두 확보된 함수 진입점이다.

| opcode | 원본 handler 진입점 | 참고 소스의 역할 대응 |
|---|---|---|
| `0x9c` | `0x001a27b0` | PUSHF |
| `0x9d` | `0x001a28a0` | POPF |
| `0xcd` | `0x001a20d4` | INTn |
| `0xcf` | `0x001a29dc` | IRET |
| `0xfa` | `0x001a26c8` | CLI |
| `0xfb` | `0x001a2734` | STI |

포인터·opcode 매핑은 원본 바이트와 명령에서 확인한 사실이다.
역할 이름은 로컬 `01_resources/upstream/darwin01/kernel/machdep/i386/pc_support/PCemulateREAL.c`의
`inst_table`과 대조한 해석이며 함수 전체가 해당 참고 소스와 동일하다는 주장은 아니다.
테이블 슬롯 주소·해시도 JSON에 보존했다.

이 테이블 간선을 포함해야 PUSHF/POPF/IRET 계열 wrapper 및 helper의
복구 필드 저장을 현재 thread까지 연결할 수 있다.
실행 중 이 테이블이 변경되지 않는다는 전역 증명은 아직 수행하지 않았다.

## P03 — 검사 패턴을 넓혀 놓친 쓰기를 별도 목록화

이전 검사는 코드 주소 즉시값을 저장하는 MOV 중심이었다.
이번에는 모든 인식 instruction에서 명시적 메모리 operand의 displacement가 `0x74`이고
쓰기 속성이 있는 경우를 수집했다. MOV뿐 아니라 OR 같은 read-modify-write도 포함한다.

| 원본 명령의 분류 | 개수 |
|---|---:|
| 전체 명시적 `+0x74` 쓰기 | 211 |
| source가 즉시값 | 158 |
| 위 즉시값 중 알려진 함수 진입점 | 50 |
| 위 즉시값 중 0 | 102 |
| 위 즉시값 중 그 밖의 값 | 6 |
| source가 레지스터 | 53 |

이 표는 **211개의 thread 복구 쓰기**를 뜻하지 않는다.
inode·IPC task·PCB·PC monitor 등의 다른 구조도 같은 오프셋을 사용한다.
특히 PC emulation 안에서도 monitor 상태에 대한 `OR [reg+0x74], reg`가 있어
오프셋이나 함수 이름만으로 복구 필드라고 분류하면 안 된다.
0을 쓰는 명령도 모두 recover 해제라고 확정한 것이 아니다.

[확장 쓰기 목록](all-explicit-displacement74-writes.json)에 소유 함수, 주소, 명령, 쓰기 크기를 기록했다.
레지스터 기반 저장의 개별 구조체 출처 검토와 displacement 없이 계산된 별칭 주소 검사는 남아 있다.
이 목록은 검사 공백을 드러내기 위한 것이며 새 복구 경로 53개를 발견했다는 뜻이 아니다.

## 재현과 검증의 한계

프로젝트 루트에서 다음을 실행한다.

```sh
python3 -B 09_validation/reports/continuous-review-20260911-01/recovery_flow.py
```

Python 3.10.12 / Capstone 4.0.2에서 수행했다.
분석기 자체의 frame 인자, 현재 thread 로드, 부분 레지스터 무효화,
CALL 보존/파괴, 경로 충돌 및 부분 stack 쓰기 검사 7개가 통과했다.
이 작은 검사들이 분석기 전체의 정확성을 증명하지는 않는다.

명시적인 모델 가정:

- 정상 호출 시 cdecl의 보존 레지스터와 호출자 ESP가 유지된다.
- callee가 별칭 포인터를 통해 호출자 인자 슬롯을 임의로 덮어쓰지 않는다.
- 원본의 함수 포인터 테이블 값에 대한 경로를 분석하며 런타임 변조는 모델링하지 않는다.
- fault·interrupt·비지역 복귀를 실행하지 않는다. 실제 복구 지점으로의 동적 재진입은 후속 검토 대상이다.
- 함수 경계는 저장된 listing을 사용한다. 이 검사만으로 경계가 모두 맞다고 결론 내리지 않는다.

미지의 값이나 경로를 성공으로 대체하지 않았다. 검사 입력 파일 해시와 실행 환경은
`provenance-flow.json`에 함께 기록했다. 원본·기존 export·기존 DB는 수정하지 않았다.

## 전체 목표의 미해결 상태

이번 검토로 **후보 36곳의 정상 호출 경로상 기반 포인터 출처**를 보강했다.
하지만 [선행 상세보고서](../deep-review-20260911/README.md)의 문제 전체를 해결한 것은 아니다.
특히 다음은 여전히 완료를 막는 분석 항목이다.

1. 각 fault 지점에서 복구 fragment로 진입할 때 스택·레지스터·세그먼트 및 오류 반환의 일치.
2. 확장 쓰기 목록의 구조체 출처와 계산된 별칭·간접 저장 경로.
3. 비지역/예외 복귀에 따른 잘못된 C fallthrough와 R01 이웃 함수 혼입.
4. R02 ObjC forwarding의 padding 오인 및 잘못된 instruction 경계.
5. CPU 특권 동작·ObjC dispatch·문맥 전환·자체 수정 코드의 정확한 계약.
6. IDA containing function·실제 입력 바이트 대조와 실패/중복 출력의 정리.
7. 실제 callback/fragment 분류 및 나머지 타입·디컴파일 경고의 의미 검증.

다음 우선 검토는 복구 fragment의 원래 실행 문맥과 실패 경로 연결이다.
전체 목표는 활성 상태로 유지한다. 현재 증거로 “분석이 완벽하다”는 판정은 할 수 없다.
