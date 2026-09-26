# 연속 추가검토 — 원본 명령 실행과 fault 복구

대상: OPENSTEP 4.2 mk-183.34.4 / x86. 검토일: 2026-09-11.
원본 SHA-256: `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`.
선행 작업: [복구 포인터 출처 검토](../continuous-review-20260911-01/README.md).

## 이번 진전과 전체 판정

이전 단계는 복구 주소 저장 50곳의 정상 호출 경로상 포인터 출처를 연결했다.
이번에는 그중 copy/accessor 함수군의 실제 원본 명령을 Python/Unicorn에서 실행하고,
오류 경로에 들어간 뒤 원래 호출자에게 돌아오는지 검사했다.

**14개 함수의 제한된 검사 267개가 통과했다.**
그러나 실제 IDT·인터럽트 진입·IRETD 또는 커널 부팅을 검증한 것은 아니다.
또한 저장된 IDA C에서 원본의 source/destination 세그먼트와 다른 표현을 추가 발견했다.
따라서 전체 분석의 완전성은 여전히 미확정이며 목표를 완료 처리하지 않는다.

Ghidra·IDA 분석 스킬에 따라 원본 바이트, 보존된 도구 출력, 테스트 해석을 구분했다.
모든 계산·주소 변환·집계·에뮬레이터 제어는 Python으로 수행했다.
원본, 기존 export, 기존 Ghidra/IDA DB와 커널 구현은 변경하지 않았다.

## E01 — 복구 fragment와 원래 호출자의 스택을 실제 명령으로 연결

검사 대상:

- `_copyin`, `_copyinmsg`, `_copywithin`, `_copyout`, `_copyoutmsg`
- `_copystr`, `_copyinstr`, `_copyoutstr`
- `_fuword`, `_fubyte`, `_fuibyte`, `_suword`, `_subyte`, `_suibyte`

원본 Mach-O의 파일 바이트를 별도 에뮬레이터 메모리에 로드했다.
임의의 보존 레지스터 값, 유효한 스택과 인자, 독립된 source/destination 페이지를 준비했다.
각 실행은 명령 수와 시간 상한을 가지며 호출자 복귀 주소에 도착하지 않으면 실패한다.

fault 검사에서는 다음 절차를 사용했다.

1. unmapped 페이지 접근으로 에뮬레이터 메모리 fault를 발생시키거나,
   지정한 접근 명령 직전에 명시적인 synthetic fault를 주입한다.
2. 그 시점의 레지스터와 `thread + 0x74`의 복구 목적지를 저장한다.
3. **원본 `FUN_001924a0` 복구 helper도 실제로 실행**한다.
   합성 예외 프레임과 별도 임시 스택을 사용해 EIP·CS·EFLAGS 변경 및 recover 해제를 확인한다.
4. 저장된 범용 레지스터를 복원하고 갱신된 프레임의 EIP/EFLAGS로 복구 fragment를 실행한다.
5. 원래 함수의 공통 에필로그까지 따라가서 반환값·호출자 ESP·EBX/ESI/EDI/EBP를 검사한다.

단계 4의 interrupt-frame 복원은 harness가 모델링한 것이며 실제 IRETD 실행이 아니다.
즉, 원본 helper와 landing/epilogue는 실행했지만 전체 trap 기계 동작은 별도 검증 대상이다.

모든 검사에서 호출자 스택과 보존 레지스터가 일치했다.
fault 뒤 copy/string 함수는 `0xe`, scalar 접근 함수는 `0xffffffff`를 반환하고 recover를 지웠다.
로컬 참고 헤더 `kernel/bsd/sys/errno.h`에서 `EFAULT`는 14로 정의되어 있다.
DF를 처음부터 설정한 scalar fault 사례도 포함했고, helper 실행 후 DF가 지워짐을 확인했다.

| 검사 종류 | 개수 |
|---|---:|
| 일반 복사 성공 | 120 |
| 페이지 경계/미매핑에 의한 복사 fault | 50 |
| 문자열 복사 성공 | 15 |
| 페이지 경계/미매핑에 의한 문자열 fault | 18 |
| scalar 접근 성공 | 30 |
| 미매핑 scalar 접근 fault | 12 |
| 미검사 FS 명령 위치에 대한 synthetic fault | 22 |
| 합계 | 267 |

성공 사례는 165개, fault 사례는 102개이며, 후자 중 실제 미매핑 접근은 80개다.
fault 시 실행된 복구 목적지는 14개다. PC emulation 쪽의 나머지 복구 목적지는 이번 실행 범위 밖이다.

원본 helper 실행 trace, fault 시 레지스터, recover 쓰기 및 원래 함수의 trace는
[실행 결과](fault-execution.json)에 보존했다.
정렬되지 않은 접근은 에뮬레이터가 같은 명령에 여러 invalid-memory callback을 발생시킬 수 있다.
이 경우 PC와 레지스터가 동일한지 확인하고 callback을 보존했으며, 이를 여러 커널 fault로 세지 않았다.

## E02 — 명령 위치 coverage와 도달하지 않는 정렬 루프

검사 대상 함수들의 FS 메모리 operand를 가진 원본 instruction 시작점은 46개다.
그중 44개 위치에서 fault 후 복구를 검사했다. 일반 메모리 접근 fault까지 포함한
고유 fault instruction 위치는 58개다.
이 분모는 해당 함수군의 FS 명령이지 전체 커널의 모든 fault 가능 지점이 아니다.

실행되지 않은 FS 명령은 다음과 같다.

- `_copyout`의 `0x00189da9`
- `_copyoutmsg`의 `0x00189f51`

두 명령은 source를 정렬하기 위한 앞부분 복사의 dword 루프 안에 있다.
정상 진입에서 source 잔여 정렬값 `r`이 0이면 이 구간을 건너뛰고,
그렇지 않으면 복사할 정렬 바이트 수는 `4-r`다.
Python으로 `r`의 가능한 값 1, 2, 3을 열거하면 `(4-r) >> 2`는 모두 0이다.
원본은 먼저 DEC/CMP 조건을 검사하므로 해당 dword 루프 본문에 진입하지 않는다.

원본의 정확한 마스크·감산·레지스터 전달·shift·초기 JMP·DEC/CMP/JNZ 주소를 검증했다.
중간에 EDX를 바꾸는 명령이 없는지와 루프 본문으로의 직접 분기 전임자도 확인했다.
따라서 이 두 위치는 단순 테스트 실패가 아니라 **정상 진입의 정렬 불변식상 비실행 경로**로 기록했다.
임의 PC 변경, 스택 손상 또는 외부에서 중간으로 뛰어드는 경우까지 배제한 전역 증명은 아니다.

주소별 목록은 [메모리 접근 coverage](memory-access-coverage.json), 정적 계산과 명령 근거는
`fault-execution.json`의 `normal_entry_unreachable_fs_heads`에 있다.

## E03 — 성공 시 남는 recover는 이번에 발견한 원본 동작

짧은 복사 경로에서는 정상 반환 후에도 복구 주소가 남는다.
`_copyin`, `_copyinmsg`, `_copywithin`, `_copyout`, `_copyoutmsg`에서
길이 0, 1, 15의 검사에 이 동작이 나타났으며 해당 성공 사례는 60개다.

예를 들어 `_copyin`은 복구 주소를 먼저 저장하고,
짧은 복사 후 `0x00189a83`에서 `0x00189b29`의 공통 에필로그로 직접 이동한다.
이 경로는 `0x00189b08`에서 시작하는 recover 해제 블록을 지나지 않는다.
같은 흐름은 보존된 Ghidra/IDA C 및 로컬 Darwin `machdep/i386/fault_copy.c`에도 나타난다.

따라서 이를 디컴파일러가 `clear_recover()`를 누락한 오류라고 판정하지 않는다.
호출자/후속 trap과의 수명 관계를 조사하기 전에는 실제 악용 가능성이나 커널 결함의 영향도 단정하지 않는다.
복원 과정에서 “모든 성공 반환은 recover를 지워야 한다”는 임의의 가정을 넣어 원본과 다르게 만들면 안 된다.

추가로 byte fetch 함수는 원본의 MOVSX에 따라 byte 값을 부호 확장한다.
`0x80`과 `0xff` 입력을 포함해 확인했으며, 이를 무조건 unsigned byte 반환으로 바꾸면 안 된다.

## E04 — 저장된 IDA C의 반복 복사 세그먼트 표현 불일치

`_copyin`과 `_copyinmsg`의 반복 복사 명령에서 원본 바이트와 Capstone/Ghidra listing은
**destination ES, source FS**로 표현된다.
그러나 보존된 IDA C는 `__writefsbyte(..., __readfsbyte(...))` 또는
`__writefsdword(..., __readfsdword(...))`처럼 destination까지 FS 접근으로 표시한다.

이 불일치는 해당 함수들의 6개 명령 위치에서 확인했다.
주소, 원본 instruction bytes, 독립 decode와 해당 IDA C 행을
[세그먼트 표현 비교](segment-rendering-review.json)에 기록했다.

이번에는 기반 IDA DB의 실제 입력 바이트/함수 경계를 새로 검증하지 않았으므로
원인을 Hex-Rays 엔진 자체의 결함으로 단정하지 않는다.
확정 가능한 것은 **현재 보존된 IDA C가 원본의 세그먼트 관계와 다르다**는 점이다.
이번 에뮬레이션은 zero-base flat segment를 사용했으므로 그 통과 결과로
세그먼트 selector·권한·limit 의미까지 올바르다고 인증할 수 없다.

## 재현 및 잔여 작업

```sh
python3 -B 09_validation/reports/continuous-review-20260911-02/fault_execution.py
```

환경: Python 3.10.12, Unicorn 2.1.4, Capstone 4.0.2.
호스트 커널을 실행하거나 수정하지 않는다. 도구가 내보낸 C를 컴파일해 시험한 것도 아니다.
원본 명령의 fixture 검증이므로 GCC 2.7 빌드·실기/가상머신 부팅 검증과는 별도다.

다음 검토 대상:

1. PC emulation 복구 fragment의 부분 descriptor/stack 처리 및 원래 함수로의 실패 복귀.
2. 실제 trap entry/IRETD와 세그먼트 권한·limit·DF를 포함한 프레임 계약.
3. 짧은 성공 복사 뒤 recover 수명의 호출자 문맥.
4. 새 E04와 선행 R01/R02/F01의 잘못된 도구 표현을 분석 작업본에서 어떻게 교정할지 검증.
5. 기존 타입·callback·IDA 입력 검증·간접 제어 이동 등의 미해결 항목.

이번 단계는 실제 증거가 증가한 진전이다. 미해결 범위를 축소하여 전체 목표 완료로 바꾸지 않는다.
