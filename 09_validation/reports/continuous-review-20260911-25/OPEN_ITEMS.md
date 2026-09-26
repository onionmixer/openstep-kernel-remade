# 잔여 분석 — 보고서25 이후

[보고서24의 전체 잔여 의무](../continuous-review-20260911-24/OPEN_ITEMS.md)를
그대로 계승한다. 해당 목록의 의무를 삭제하거나 이번 fixture 범위로 축소하지 않는다.

이번에 추가 확인한 범위:

- 합성 VM entry를 원본 lookup이 발견하고 current protection으로 쓰기를 거절.
- miss=1과 구별되는 원본 KERN_PROTECTION_FAILURE=2, vm_fault 조기 반환,
  원본 recover/IRETD/EFAULT 연결.
- 원본 lock_init과 경합 없는 read-lock 해제, 빠른 hint와 목록 탐색의 분리.
- VM page와 하드웨어 PTE page 크기를 맞춘 범위·권한 모델.

여전히 미완료인 핵심:

- native IDT 전달·CPU frame/error code 생성, CPL 전환·대체 스택·다른 예외.
- 원본 vm_fault의 page-in 성공과 fault 명령 재시작. 이번 protection3 대조는
  lookup의 권한 검사 뒤에서 중단했으므로 **성공 반환 자체를 실행하지 않았다.**
- 실제 VM 페이지 경계의 부분 복사, 비연속 물리 페이지, 원본 사용자 pmap/map
  생성 및 전체 문맥 전환. 이번 합성 entry/list는 원본 map 생성 전체가 아니다.
- 나머지 FS/descriptor 불변 조건, 모든 recover 수명, 부팅 잔여 경로, ABI/타입/
  함수 경계, CPU 부작용 모델 통합, 동시성/장치, IDA 독립 대조와 교정안 재추출,
  공개 소스 대응 및 복원 명세는 보고서24 목록과 동일하게 남는다.

다음 분석은 이번 권한 허용 지점 이후 원본 VM object/page 경로의 조건을 조사하고,
원본 map/pmap 생성과 연결하는 데 필요한 상태를 코딩 전 교차검토해야 한다.
단순히 fault 이후 메모리 매핑을 API로 고쳐 놓고 원본 page-in 성공으로 부르지 않는다.

GCC 2.7 구현·컴파일·링크·부팅 및 후속 아키텍처는 별도 단계이며 미완료다.
