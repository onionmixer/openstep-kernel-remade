# Bochs 독립 RF 대조 — 코딩 전 계획

보고서37의 QEMU RF 불일치를 별도 CPU 모델에서 조사한다. 원본 OPENSTEP handler
전체 실행이 아니라 동일한 합성 fixture의 대조다. 기존 보고서37 전체 checkpoint를
Python으로 먼저 검증하고, 그 BIOS/tables/code/data를 변경 없이 복사한다.

설치된 Bochs2.7, CPU pentium, 단일 CPU를 사용한다. wx 화면은 별도 Xvfb에 연결하며
TCP listener·host disk·NIC·host 장치 pass-through는 사용하지 않는다. 기존 설치만
사용하며 패키지 설치나 host 설정 변경을 하지 않는다.

코딩 전 vm_contract_review27에게 읽기 전용 교차검토를 요청했다. 검토자는 BIOS가
A20을 직접 켜지 않으므로 QEMU와 Bochs의 reset 상태가 같다고 추정하지 말라고
지적했다. root는 초기 register/segment/control 상태와 실제 breakpoint 도달을 확인한다.
초기 A20이 달라 부팅하지 못하면 그 실패를 보존하고 RF 관찰값을 만들지 않는다.

Bochs 내부 physical breakpoint로 handler 진입 및 main의 출력 직후를 관찰한다.
CPU register나 guest RAM/frame을 설정하는 디버거 명령은 사용하지 않는다.
writemem은 guest의 linear memory를 호스트 진단 파일로 읽는 명령이다.
각 PF의 원시 CPU frame, handler가 복사한 record, retry 결과, 코드/테이블/데이터를
덤프하고 둘을 연결한다. 실제 명령 지원·stop 위치를 로그로 확인한다.

QEMU 전용 f4 exit 전에 debugger로 종료한다. 프로세스에는 별도 wall timeout을
설정하고, 이 작업이 만든 process group만 정리한다. 종료 코드만으로 성공을 판단하지 않는다.
다른 IF/DF 조건에도 같은 검사를 수행한다. RF 계약 성공 여부는 실제 원시 frame으로
판정하며 PUSHFD로 대체하지 않는다. 모든 계산·크기·주소·해시는 Python을 사용한다.

참고: 설치된 `/usr/share/doc/bochs/examples/bochsrc.gz` 및
[Bochs 공식 디버거 문서](https://bochs.sourceforge.io/doc/docbook/user/internal-debugger.html).
온라인 최신 문서의 존재만으로 설치 버전의 동작을 확정하지 않는다.

원본 GC 상태 이전, 원본 handler/retry 및 전체 잔여 분석은 완료로 처리하지 않는다.
