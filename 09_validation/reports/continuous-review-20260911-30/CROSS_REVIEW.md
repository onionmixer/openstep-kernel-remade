# 보고서30 교차검토 및 root 재검증

reviewer `/root/vm_contract_review27`는 계획 단계부터 읽기 전용으로 검토했다.
Codex 의견은 원본 증거가 아니며, root가 정본 ASM/Python으로 재확인했다.

## 코딩 전 검토

- free PT reuse는 zero-fill을 하지 않는다는 지적을 원본 0x190d53→0x190e20에서
  확인했다. NP PTE 잔여와 유효 wired count를 분리한다.
- descriptor의 kernel PV VA는 GC/경쟁 정리에서 사용되므로 0인 채로 두지 않는다.
  기존 PT backing의 kernel PV/wired PTE·국소 count를 합성 선행조건으로 준비했다.
  전체 kernel mapping의 계수나 생성으로 확대하지 않는다.
- free sentinel/tail과 free/total count 초기화가 필요하다. report29는 active PT
  상태만 준비한다. root 코드에서 최초 deallocate 전에 자기 링크/0/1을 설정하고
  PLAN에 구체 원본 주소를 보완했다.
- vm_map_find 비영 결과의 kmem 1 반환과 physical-page 부족의 wait/sleep 경로를
  분리했다. 세 번째 expand 진입 중지의 완료된 실패 반환은 두 번이며, 세 번째
  body를 실행하거나 호출자가 최종 실패 반환했다고 세지 않는다.
- 신규 성공의 kernel map/object/zone/page/wiring/PTE/extension 의존성은
  PT_CONTRACTS.md에 원본 주소로 연결했다. 재사용으로 대체하지 않는다.

## 실행 중 잘못된 기대값 수정

초기 VA 고갈 반복 시험에서 root 전체 바이트 불변 assert가 실패했다. root는
Python으로 실제 차이를 확인했다: active A root PDE index 770이
0x402003 → 0x402023으로 바뀌었으며 차이는 Accessed bit 0x20이었다. B root는
불변이었다. 정상 kernel 접근의 단조 A 설정만 허용하고, user PDE 변경이나 다른
bit 차이를 허용하지 않도록 executor와 audit 범위를 좁혀 수정했다.

고갈 입력은 재사용용 wired PT backing 등록을 수행하지 않도록 별도 초기 상태로
분리했다. 초기 보고서29 준비 이력과 최종 고갈 입력이 같다고 쓰지 않는다.

## 후속 audit 검토와 실제 재현

reviewer가 다음 누락을 지적했다.

1. contract_globals의 전후 불변만 검사하여 일관되게 잘못된 managed bounds 등을
   기록한 자료를 허용했다.
2. PDE invalidation의 Present=0만 검사해 RW/U 등 다른 bit까지 지운 자료를 허용했다.
3. 재사용된 startup/seed 준비 trace와 map lock init 등 일부 이력 검산이 빠져 있었다.

root는 정상 JSON의 메모리 복사에서 모든 단계의 managed upper bound를 0으로
바꾸는 오류와, 최초 PDE low byte clear를 6 대신 0으로 바꾸고 이어지는 상태를
일관되게 변경하는 오류가 수정 전 통과함을 직접 재현했다. reviewer도 읽기 전용
메모리 복사에서 PDE/startup 누락을 확인했다. 원본/정본 JSON 파일은 훼손하지 않았다.

수정: 전역값의 초기 독립 기대값과 kernel pmap/root 연결 검사, 원본 `AND 0xfe`를
before PDE byte에서 직접 도출, 준비 trace의 nonempty/entry/error/stop 검사,
실제 준비 stack 및 kmem/find 진입 인자 관찰을 추가했다. inactive root에 대한
CPU write는 허용 영역에서 제외했다.

map lock 초기화 trace를 새로 검사하면서 기존 공통 checker가 지원하지 않는
memset 간접 jump를 만났다. 임의 간접 분기를 허용하지 않고 원본 PUSH 12와
raw jump table에 한정한 별도 lock_init_trace 검사를 추가했다. reviewer는
원본 분기와 이 한정 조건이 맞는지 다시 읽어 확인했다.

## NP-skip 추가의 별도 코딩 전 검토

root는 범위 밖 residue 보존만으로 실제 NP-skip 실행을 주장할 수 없음을 구분했다.
추가 코딩 전에 reviewer에게 section 첫 NP VM 묶음의 원본 pmap_remove 호출을
검토받았다. 이후 실제 0x18f8b4→0x18f8b9와 deallocate 인자 0/0을 관찰하고,
PT active 유지·NP residue 보존·TLB counter 증가를 검산했다. removed count를
pmap_remove EAX의 반환값으로 오인하지 않는다.

정상 전체 matrix와 음성 대조, 최종 재현·보존 검증은 root가 실행한다.
reviewer의 정적 확인 자체를 실행/독립 하드웨어 성공 증거로 사용하지 않는다.
