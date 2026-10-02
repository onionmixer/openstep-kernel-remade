# 복원 작업계획

실행 계획은 [복원 작업계획](RECONSTRUCTION_PLAN.md)을 따른다(2026-10-01, D011).

## 목표와 판정

기준은 `03_original/x86/`의 mk-183.34.4 커널이며, 현재 Ubuntu/Linux 커널은 대상이 아니다.
온전한 복원은 실제 컴파일·링크 가능한 소스와 재현 가능한 빌드 설명,
OPENSTEP 유저랜드·커널 서버/DriverKit ABI 호환, 대상 환경의 부팅·회귀검증을 포함한다.
원본 바이트와의 동일성은 별도 목표이며 빌드 성공 또는 함수 이름 일치로 대체하지 않는다.
복원이 불명확한 코드, 미해결 심볼과 임시 stub은 명시적으로 기록한다.
최종 소스는 **GCC 2.7에서 컴파일 가능해야 한다**. 실제 해당 컴파일러로 전체 컴파일·링크한
결과를 필수 검증으로 삼는다. [호환 기준](../08_build/GCC27_COMPATIBILITY.md)은 모든 대상 CPU에 적용한다.

| 단계 | 작업 | 완료 조건 / 산출물 |
|---|---|---|
| P0 준비 | 구조 생성, 로컬 원본/IDA 보존, 공개 소스 수집, 타깃 식별 | 원본 해시 검증 + 세 소스의 고정 revision/아카이브 및 출처 기록. 수집·추출·파일별 해시 기록 완료; 상세 계보 대조는 P2 |
| P1 x86 지형도 | Mach-O mapping, 심볼 분류, Ghidra와 IDA로 함수/타입/호출 관계 확인 | 같은 바이너리 해시·주소체계의 분석 export, 함수/데이터 구별, 미식별 영역 목록 |
| P2 계보 대조 | NeXTMach/Mach4/Darwin의 서브시스템·함수 대응, SDK 헤더 대조 | 함수별 후보 경로·증거·차이·신뢰도, ABI/구조체 필드 대응표 |
| P3 빌드 기반 | GCC 2.7 세부 버전/NeXT 수정판·target 고정, C/Objective-C, asm, Mach-O linker, MIG, generated headers, 커널 config 확인 | 실제 GCC 2.7로 C/asm/ObjC/MIG probe가 필요한 ABI/객체 형식으로 생성됨. 버전·옵션·해시 고정 |
| P4 x86 복원 | 기반 헤더→기계의존부→공통 Mach→BSD→DriverKit/서버→링크 통합 | 07_kernel 전체 소스·생성 코드를 GCC 2.7로 컴파일하고 Mach-O 커널로 링크. 빌드 로그·미해결 항목·함수 증거 목록 |
| P5 x86 검증 | 정적 ABI/차분, 기존 커널 부팅 baseline, 복원 커널 부팅, 회귀 | 콘솔·루트 마운트·init·다중 프로세스·VM·IPC·파일/네트워크·모듈의 로그와 결과 |
| P6 SPARC | 해당 플랫폼 원본·SDK·부트 계약 확보, endian/MMU/trap/context ABI 복원 | SPARC용 GCC 2.7 빌드와 해당 플랫폼 기준의 부팅 검증; x86 결과로 대체하지 않음 |
| P7 후속 CPU | “mach 아키텍처” 의미 확정 후 별도 기준 바이너리와 플랫폼 확보 | m68k를 뜻한다면 CPU/보드/부트 ROM·MMU·예외 프레임까지 명세 후 복원 |

## x86 작업 순서

사용자 지정 선행 조건은 [전체 분석 우선](FULL_ANALYSIS.md)이다.
전체 자료 확보 결과는 [분석 보고서](../09_validation/reports/full-analysis/README.md)를 참조한다.
아래 소스 복원 순서는 자료 확보 이후에 적용하며, 이번 실행에서는 구현하지 않았다.

1. CPU subtype, load commands, 주소/파일 오프셋, entry state, 심볼·ObjC metadata를 조사한다.
2. task/thread/processor, VM/pmap, IPC/MIG, BSD proc/vnode/socket 등 타입과 ABI를 먼저 고정한다.
3. locore/startup, GDT/IDT, trap/interrupt, context switch, pmap, clock/FPU 경로를 복원한다.
4. scheduler/locks, IPC, VM/pager, BSD syscalls/VFS/UFS/network를 통합한다.
5. DriverKit의 ObjC 런타임 의존성, autoconfiguration, Mach-O kernel server loader와 드라이버 계약을 대조한다.
6. 원본의 config·심볼 노출·정렬·링크 순서·MIG 생성물을 맞추고 전체 링크/부팅으로 진행한다.

서브시스템별로 `06_reconstruction/subsystems.tsv`를 갱신한다.
함수명 일치만으로 구현을 가져오지 않는다. 상수, 타입 offset, 호출 관계, 분기/오류 경로,
side effect를 대조하며 채택 근거를 함수 단위로 남긴다.

## 빌드/검증 전략

OPENSTEP 네이티브 도구 체계와 Linux 호스트 크로스 도구 체계를 비교해 먼저 가능한 경로를 확정한다.
어느 경로에서도 최종 커널 컴파일러는 GCC 2.7이며, 호환성 검사를 초기 P3부터 적용한다.
현대 GCC/Clang의 존재는 NeXT Mach-O와 구형 Objective-C ABI 지원의 증거가 아니다.
Linux 커널 헤더나 ELF 크로스 컴파일러를 그대로 커널 빌드 환경으로 간주하지 않는다.
먼저 기존 커널이 부팅하는 테스트 환경을 baseline으로 고정한다.
복원 커널은 별도 테스트 디스크/이미지와 복구 가능한 부트 항목에서 검증한다.
이번 준비 단계에서는 실기 커널 교체·재부팅을 수행하지 않는다.

함수/바이트 coverage는 분모를 기록하고, data·padding·미식별 code를 구별한다.
심볼 수를 함수 개수나 복원 진행률로 계산하지 않는다.
