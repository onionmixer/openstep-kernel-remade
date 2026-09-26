# 남은 전체 분석

[report51의 전체 미완료 목록](../continuous-review-20260912-51/OPEN_ITEMS.md)을 유지한다. 이번 module orchestration 본문 검토는 transitive callee 및 실제 module 수명/동시성 검증 완료가 아니다.

## 직접 이어갈 핵심

- `kern_serv_load_objc`, `kern_serv_shutdown`, `FUN_00194890`에서 module 주소·출처, 등록 반환값·실패 처리, callback 유무, 메모리 해제와 직렬화 순서를 확인한다.
- 사전 조회에 `defs[i]`를 그대로 전달하는 원본과 name 기반 class lookup 사이의 인자/출처 불일치를 실제 입력으로 규명한다. 올바른 중복 방지나 관찰된 원본 버그로 성급히 확정하지 않는다.
- section loader의 범위 검증과 module size 진행성, pre-PDO/구형 class·protocol/method list 변환, version 및 pointer 보정을 확인한다.
- add/removeHeader, add/removeClass, category 추가·제거, 관계 설치와 Protocol fixup의 실제 효과·실패/회수·cache 일관성을 연결한다.
- 외부 callback의 `(class, category-or-zero)` ABI와 직접 IMP lifecycle의 `(class, selector[, header])`, callback 재진입·동시성·반환 중단을 실제 연속 상태로 검증한다.
- selector unlink 뒤 module 메모리 해제·재사용과 기존 selector/class/protocol 참조의 수명, original-name 복원 없이 unload하는 정책을 확인한다.

report50의 문자열 입력·pool/보호·signed strcmp, NXHash/NXMap 연속 실행·소유권·원본 선언, 구조체/포인터 반환 누락과 실제 GCC 2.7 ABI 의무도 남는다. 독립 계획 검토 미수신 조건으로 신규 실행/검증 코드와 복원 구현은 보류 상태다.

## 전체 범위 유지

전체 함수별 의미 원장·과거 증거 등록, IDA 독립 바이트/DB/export, fragments·경고·타입/ABI, PD 참조·재사용·다중 backing·aging/PT GC, native RF/IDT/IRETD/fault, scheduler/context/FPU, 메모리 소유권·pager/COW/alias/PV, 장치/MMIO/interrupt/TLB/cache를 유지한다.

IPC/MIG/BSD/VFS/UFS/network/DriverKit/kernserv, 공개 소스 계보, 실제 GCC 2.7 툴체인·전체 컴파일·Mach-O 링크·부팅과 SPARC/후속 아키텍처별 검증도 미완료다.
