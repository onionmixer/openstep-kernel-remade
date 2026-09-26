# 독립 CPU 모델 대조 시도와 QEMU RF 수정 근거

상태: **Bochs guest 실행 전 실패. RF 대조는 미실행이다.** QEMU의 기존 RF 계약 실패와
원본 kernel handler/retry 검증 미완료 상태는 그대로 유지한다. 원본·기존 보고서37·
Ghidra/IDA DB·07_kernel은 변경하지 않았다. 계산과 진단 자료 생성은 Python을 사용했다.

## Bochs 실제 실행 시도

기존 report37의 BIOS/tables/code/data를 해시 일치하는 별도 파일로 복사했다.
CPU pentium/단일 CPU, host disk·NIC 없이 내부 debugger의 physical breakpoint와
linear memory 읽기만 계획했다. 설정 파일은 [bochsrc](bochsrc), debugger 명령은
[debugger.rc](debugger.rc), 실행 기록 수집기는 [run_bochs.py](run_bochs.py)다.

| 시도 | 확인한 결과 |
|---|---|
| `case-2` | textconfig와 wx display 조합을 설치 Bochs가 거부했다. root 설정 오류다. |
| `case-2-wx` | config_interface를 wx로 명시하자 설정 단계는 진행했지만 GTK 화면 초기화가 실패했다. Xvfb 로그에는 로컬 소켓 bind/listener 생성 실패가 있다. |
| `case-2-nogui` | Xvfb 없이 직접 실행했으나 설치 Bochs가 nogui display 미제공을 보고했다. |

각 프로세스는 종료 코드1로 끝났으며 timeout은 아니었다. debugger frame dump는 없다.
RF=0 또는 RF=1을 Bochs에서 관찰했다고 주장하지 않는다. 다른 IF/DF 사례는 동일한
실행 전 제약을 반복할 뿐이므로 아직 실행하지 않았다. 호스트 X11 디렉터리 권한 변경,
TCP/RFB 서버 대체, 패키지 설치 또는 보안 제한 해제를 시도하지 않았다.

앞선 xvfb-run/bochs --help의 종료 성공은 화면 초기화 가능성의 증거가 아니었다.
실제 실행 실패로 그 판단을 정정했다. A20 초기값도 CPU 관찰에 도달하지 못해 미검증이다.

## QEMU upstream에서 확인한 관련 결함 수정

공식 QEMU 커밋
[`69cb498c56263a5ae484fd4fef920d3d3eea04c8`](https://github.com/qemu/qemu/commit/69cb498c56263a5ae484fd4fef920d3d3eea04c8)은
fault 예외에서 저장되는 EFLAGS.RF 처리를 수정한다. 공식
[커밋 알림](https://lists.gnu.org/archive/html/qemu-commits/2024-06/msg00024.html)은
2024-06-08 staging 반영과 같은 commit 식별자를 기록한다.

root가 공식 diff의 protected-mode 경로를 직접 읽었다. 이전 경로는 계산된 현재
EFLAGS를 그대로 stack에 넣었고, 수정 경로는 fault 분류에 따라 RF를 설정한 값을
저장한다. page fault는 추가된 fault 분류에서 제외되는 예외가 아니다. 64-bit 경로도
별도 수정됐지만 현재 probe는32-bit protected mode다. 반복 문자열 명령에 관한
translate.c 주석은 별도 한계이며, 이번 fault 명령은 REP가 아닌 FS byte-store다.

**판정:** report37의 saved RF 부재와 일치하는 upstream 결함 수정 근거를 확보했다.
이는 커널 복원 코드가 아니라 실행기 계약을 의심해야 할 구체적 근거다. 다만 현재
설치된 Ubuntu QEMU6.2 패키지에 대한 정확한 소스/백포트 대응은 미확인이다.
version-pinned 원문 raw URL 접근 실패를 최신 소스로 대신하여 설치 바이너리의
원인을 확정하지 않는다. QEMU 또는 Bochs를 수정하거나 업데이트하지 않았다.

### 설치 패키지 대응 확인

[package-identity.json](package-identity.json)에 dpkg-query, ELF note 및 APT의
원시 응답을 보존했다. 설치 qemu-system-x86과 source qemu의 버전은 모두
`1:6.2+dfsg-2ubuntu6.31`이며, 설치 i386 실행기의 Build ID는
`faa3fb644f96716891240fc2a490cac093759cc1`이다. 실행 파일 SHA-256도 별도로 기록했다.

APT source 인덱스에는 정확히 같은 버전이 있다. `apt-get --print-uris source`는
그 orig/debian/dsc 파일 URI·크기·SHA512를 반환했다. 출력이 길어 처음 확인 때 일부가
잘렸으므로 Python으로 전체 응답을 수집해 해당 버전 존재를 다시 확인했다.

이후 `source-package`에서 download-only를 실행했지만 `kr.archive.ubuntu.com`의
DNS 해석 실패로 종료 코드100을 반환했다. 대응 소스가 없다는 뜻이 아니며,
현재는 다운로드된 소스/patch 내용으로 수정 포함 여부를 검사하지 못했다.
APT 설정·패키지 설치 상태는 바꾸지 않았다.

## 검토 경계와 후속 작업

코딩 전 교차검토의 A20 전제와 physical/linear 구분을 반영했다. handler 첫 명령
전에 raw CPU frame을 읽도록 계획했으며, retry 이후 PUSHFD가 덮어쓰는 최종 stack을
원래 RF frame으로 읽지 않는다. Ghidra 스킬에 따라 저장된 원본 명령 근거와 합성
시험의 해석을 분리하고 DB에는 쓰지 않았다.

설치 패키지의 소스/수정 이력 대조, 실행 가능한 독립 CPU 모델의 확보 및 실제 frame
관찰이 남아 있다. 그 뒤 원본 GC RAM 상태 이전과 원본 handler→IRETD→retry로
연결해야 한다. [전체 잔여 분석 의무](../continuous-review-20260912-36/OPEN_ITEMS.md)는
축소하지 않는다. 이번 환경 제약은 전체 분석 작업의 중단 사유로 처리하지 않는다.

진단 수집기의 종료 코드0은 실패 기록 수집 완료를 뜻할 뿐, guest 실행 성공이 아니다.
각 시도 디렉터리는 stale dump 방지를 위해 재사용하지 않으며 기존 경로 재실행은 거부한다.
