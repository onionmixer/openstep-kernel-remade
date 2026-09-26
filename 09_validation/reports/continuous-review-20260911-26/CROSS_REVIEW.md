# Codex 검토와 원본 재확인

코딩 전 검토자는 `/root/trap_plan_review`이다. 원본 resident·pmap 경로와 의존
상태를 읽기 전용으로 검토했고 root는 관련 ASM·원본 바이트·소스를 직접 대조했다.
초기 검토 및 통계/object 초기화 제한은 PLAN에 코딩 전 기록했다.

채택한 조건:

- 같은 물리 frame의 권한 교정은 원본 pmap_enter로 수행. fault 이후 API PTE
  수정·함수 반환 mock은 금지. 활성 pmap에서 INVLPG FS 경로를 확인.
- object ref/resident count는 원본 WORD. 미초기화 template의 object_init 대신
  합성 객체임을 명시하고 원본 page_insert로 hash/memq를 구성.
- pmap 통계를 PTE 개수로 추정하지 않음. 미사용 합성 입력과 전체 root 통계
  정합을 구분. 메모리 hook의 좌표는 실제 pmap root 읽기로 positive calibration.
- 성공은 recover helper를 호출하지 않고 원래 fault 명령을 재실행. 실패 경로의
  DF-clear/recover=0 규약을 성공에 잘못 적용하지 않음.

사후 검토에서 지적된 사항은 다음과 같이 보강했다.

- 다른 root의 payload 보존만으로 page table까지 보존했다고 주장하지 않도록
  두 root의 low/high PDE/PTE를 전후 기록. PDE A 및 PTE A/D 비트와 나머지
  주소·권한을 구분해 대조.
- PTE store attempt뿐 아니라 실제 memory-write hook과 최종 mapping을 대조.
- frame 전체 불변만 비교하지 않고 최초 frame을 fault 스냅샷의 기대 layout과 대조.
- object 전체·hash bucket 전체·uthread·필수 milestone 도달을 검사.
- 초기 unqueued descriptor의 제한을 명시. 별도 코딩 전 검토 후 원본 activate로
  초기 active queue를 만드는 대조를 추가. dequeue 시 page 자신의 next/prev를
  0으로 지우지 않는 원본을 고려해 header/count/flag와 최종 복원을 검사.

검토자는 원본 합류 주소를 처음 잘못 적은 후 `0x19080a`로 정정했다. root는
원본 `0x1907f8`의 분기 대상을 확인했고 잘못된 `0x190808`은 사용하지 않았다.
Codex 의견·정정 자체는 증명이 아니며, 실행 trace와 독립 Python 검산을 근거로 삼았다.
검토자는 파일 수정이나 에뮬레이션을 수행하지 않았다.
