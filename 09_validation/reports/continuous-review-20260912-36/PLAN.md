# 보고서36 계획 — GC 반환 자원의 실제 재사용

상태: 코딩 전 원본·독립 검토 후 진단/행렬/감사를 진행한다. 아직 완료가 아니다.
전체 목표를 유지하며 원본·DB/export·기존 보고서·07_kernel을 변경하지 않는다.
모든 계산·주소·계수·해시는 Python으로 처리한다.

## 새 실행 경계

확정34와 같은 fault/write/remove/GC를 새로 실행하고 전체34 result를 동일
scenario의 확정34 result와 정확 비교한다. 새36 GC helper는34의 source에서
case diagnostic write 제거, live CPU/result 반환, main 생략 및 보존 dirty_prefix
명시적 import만 허용한다. 허용 변환 외 차이를 Python으로 검사한다.
확정34 producer/main/save를 실행하지 않는다.

GC live CPU에서 같은 copyout/copyoutmsg를 재호출한다. N.S.prepare는버퍼와
recover/전역을 초기화하므로 사용하지 않는다. caller stack710000의 STOP/src/dst/
length, callee GPR, ESP, flags만 새 입력으로 지정한다. src는VA+101이고 dest는
기존100/1100, length1이다. 소스 메모리는 변경하지 않는다. 기존src100의값과
새src101의값은 Python으로 다름을 확인해 최종 재시도 쓰기를 식별한다.
실제NP 관찰 후 error/EIP/CS/EFLAGS의 명시적 합성 프레임과 ESP만 입력한다.
그 뒤 state correction/코드 patch/mock/별도 CR3 reload를 하지 않는다.

## 코딩 전 교차검토와 원본 정정

vm_contract_review27에게 독립 계획 검토를 요청하고 root가 원본을 직접 읽었다.
DATA는 이미 resident/dirty이고 freePT queue는 empty다. 이 경로는 EXT freePT
queue의 직접 재사용이 아니라 신규 wired PT 생성 경로에서 GC가 반환한
PG/EXT/map entry를 재사용하는 경우다. PDE residue6/26을임의로0으로바꾸지않는다.

DATA payload/객체resident 보존과 metadata 전 과정 불변을 혼동하지 않는다.
1720d6의 기존PAGE lookup 뒤1725f0..172620에서 active제거,17266f busy설정,
17344c pmap_enter 동안active아님, 이후17b8cc 재활성화와1734bd busy해제가 예상된다.
KO는ref1/res0에서 시작하며 PG free 및 KE/EXT zone 반환 상태를 그대로 소비한다.
PT zero 실행은 실제 원본 store로 확인하고 DATA zero 실행과 구분한다.

## 증거 및 검증 gate

단일 진단으로 재진입조건/예상하지 못한 분기·대기·쓰기영역을 확인한 후 행렬을
진행한다. 새 원본 trace·writes·milestone raw snapshot/args/CPU·zero chunks,
실제NP와 프레임 입력 및 재시도쓰기를 기록한다. prefault writes도관찰하되
실패한메모리명령의 hook은 committed write로오인하지않는다.

독립감사는 prefix provenance/입력경계, 원본 decoding/stack/store cardinality,
메모리replay·중간DATA queue/busy와PG/zone/PTE·최종상태를 검사한다.
필요한 새로운 opcode/경로는 검토없이 whitelist에넣지않는다. 훼손대조·새실행
재현·원본/이전보고서보존·최종manifest까지 끝나야 범위내확정한다.

native IDT/error/frame/실TLB/cache·모든GPR/flags/EA·다중CPU/전체ownership,
자원부족/PD/aging/pager/COW/boot/장치, 전체기존소비자/IDA/ABI/공개소스계보,
GCC2.7 구현·실컴파일·링크·부팅과후속아키텍처 의무는계속미완료로유지한다.

## 첫 진단의 예상 밖 예외 — 성공으로 우회하지 않음

새 copy 호출은 원본189d1b에서 멈췄지만 관찰 vector는 예상14가 아니라8이었다.
latest-prefault.json에 원본 trace/CPU/쓰기와전후상태를남겼고 assertion을유지했다.
이 상태를 page fault로 다시 이름 붙이거나 합성handler에 밀어넣지 않는다.

설치된Unicorn2.1.4의공식source를읽고별도코딩전교차검토를요청했다. old_exception
잔류가 후속PF를DF로만드는지 kernel과분리된최소paging실험으로검증할계획이다.
별도UC의첫NP/반복NP/중간NOP/freshUC/context_restore대조를수행하고CPU공개상태와
RAM동등성을기록한다. context_restore는최소실험의대조일뿐커널연속실행에적용하지않는다.
설치라이브러리수정·내부CPU필드patch·호스트프로세스메모리쓰기·검사완화는하지않는다.
backend제약확인과실제커널의native double fault 판정을구분한다.
