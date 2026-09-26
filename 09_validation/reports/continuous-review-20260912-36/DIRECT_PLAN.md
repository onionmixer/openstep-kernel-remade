# GC 이후 직접 pmap_enter — 별도 보조 실험 계획

코딩 전에 vm_contract_review27의 읽기 전용 교차검토를 받았고 root가 원본
0019065c.asm, 00190cfc.asm, 0018b964.asm 및 기존 감사 코드를 직접 확인했다.
검토 결과를 신뢰만 하고 채택하지 않는다. 별도의 원본 바이트/쓰기/상태 감사가 필요하다.

## 명시적 경계

fresh34 전체 기록과 확정34가 일치하는 live UC에서 caller stack/GPR/flags만
설정하고 pmap_enter(PMAP, VA, DATA, 3, 0)를 호출한다. UC 교체/context 복구,
숨은 예외 필드 수정, CR3 API reload, 객체/페이지/zone/PDE 초기화는 금지한다.
예외는 종류와 관계없이 실패다. 실제 fault 입력/handler/retry 경로와 별도다.
prefix 동등성은 producer 전체 row 비교에 의존하고 새 독립 감사는 이 경계에서 시작한다.

DATA active 금지는 vm_fault의 별도 검사다. pmap_enter 신규 관리 mapping은
vm_page active/busy/object를 접근하지 않고 pg_desc의 PV를 갱신한다.
단일 CPU·고정 소유권 전제이며 동시 회수 방지 계약을 입증하지 않는다.
0x18b964는 IPL 읽기이고 pmap mutex 획득이 아니다.

## 검사할 계약

- 원래 free PT는 비었고 PG/KE/EXT는 GC가 반환한 상태 그대로다.
- NP PDE residue를 보존하고 1907ac→expand→1907b1→PDE 재검사를 실행한다.
- 실제 zone pop/delete/reinsert/pop으로 KE, 최종 zone pop으로 EXT,
  vm_page_alloc으로 PG를 반환받는 지점을 연결한다. PG만 zero/wire한다.
- 190ef4의 PDE 설치와 190aa7의 kernel PTE 다음 user PTE 설치를 raw store로 검사한다.
  DATA descriptor attr3은 보존되지만 user PTE A/D로 복사되지 않는다.
- DATA payload/vm_page/OBJ를 보존하되 pg_desc PV owner/VA/next 갱신은 허용한다.
- EAX는 성공 코드로 가정하지 않는다. 실제 RET/stack/매핑/통계/소유권으로 검사한다.
- 성공하더라도 기존 DATA vm_fault 전이·IRETD·copy retry·native IDT·동시성·전체
  boot ownership의 증거로 확대하지 않는다. 보고서36 본래 경로는 계속 미완료다.

Python으로 모든 계산을 한다. 첫 진단 후 독립 감사·훼손 대조·재현·보존을 수행한다.
기존 확정 산출물, 원본, 분석 DB 및 07_kernel은 수정하지 않는다.
