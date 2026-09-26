# 남은 분석 — 상위 loader 검토 이후

[report52의 전체 미완료 목록](../continuous-review-20260912-52/OPEN_ITEMS.md)을 유지한다. 그중 load/shutdown/부팅 반복문의 호출 순서와 반환값 소비는 이번에 본문 수준으로 확인했다. 원본 분석 전체가 완료된 것은 아니다.

## 직접 이어갈 항목

- `0x001d12a8`, `0x001d12bc`의 함수 포인터 테이블 소유자, 실제 dispatch/MIG 경로, 요청 길이·타입·포트·header 인자의 출처와 검증을 연결한다.
- 모듈 이미지의 매핑·relocation·메모리 보호·해제 주체를 확인한다. 서버 구조체 해제와 이미지 해제를 혼동하지 않는다.
- header 저장 후 등록이 거절되는 경우의 상위 정책, 종료 요청·실행 중 callback·잔존 class/selector 참조 사이의 수명과 직렬화를 확인한다.
- 부팅 descriptor의 생성자, count의 유효 범위와 실제 header 주소를 확인한다. `_probeNativeDevices` 호출 창을 전체 DriverKit 분석 완료로 확대하지 않는다.
- 섹션 helper의 입력 사전 검증 담당자와 `strncmp` 등 하위 서비스 계약을 확인한다. 검색 본문에 없는 검사를 호출자도 하지 않는다고 가정하지 않는다.
- report52의 `defs[i]` 사전 조회 인자/출처 불일치, 모듈 record 진행성, 구형 class/protocol/method list 변환과 version별 pointer 보정을 유지한다.
- add/removeHeader·class·category, 관계 설치, Protocol fixup 및 cache 갱신의 실제 효과·실패 처리·소유권을 연결한다.
- callback ABI, 직접 IMP lifecycle, 재진입 및 unload 이후 selector/class/protocol 참조를 연속 상태에서 검증한다.

## 전체 범위

함수별 의미 검증 원장과 과거 증거 등록, IDA 독립 바이트/DB/export, fragments·경고·타입/ABI는 미완료다. NXHash/NXMap/문자열의 연속 상태·소유권과 실제 선언 문제도 남는다.

PD 참조·재사용·다중 backing·aging/PT GC, native RF/IDT/IRETD/fault retry, scheduler/context/FPU, VM 소유권·pager/COW/alias/PV, 장치/MMIO/IRQ/TLB/cache 검증을 유지한다.

IPC/MIG/BSD/VFS/UFS/network/DriverKit/kernserv 전체 계약, 공개 소스 계보, 실제 GCC 2.7 툴체인·전체 컴파일·Mach-O 링크·부팅, SPARC/후속 아키텍처별 원본 검증은 완료되지 않았다.

독립 계획 검토가 새로 확보되지 않아 신규 실행/검증 프로그램과 복원 구현은 보류한다. 이번 정적 증거는 이를 대체하지 않는다.
