# 110차 연속 검토 — pmap physical mapping chain

## 판정

원본 명령으로 pmap의 physical-range bucket과 추가 mapping node의 생성·제거를 확인했다.
`pmap_init`는 `pv_entry_zone` 전역을 설정한다. `_pmap_enter`는 physical address가
`0x001e247c..0x001e2480` 범위 안일 때 page-size-derived index로 `0x001f7ab0` 기반
bucket을 찾는다.

bucket `+0x04`가 0이면 `_pmap_enter`는 map pointer와 virtual address를 bucket fields에
직접 기록한다. 이미 nonzero이면 `pv_entry_zone`에서 node를 할당하고, node `+0x08`에
virtual address, `+0x04`에 map pointer를 기록한 후 node를 bucket `+0x00` list head에
연결한다. allocation 실패 시 lock을 해제하고 page-table lookup 경로로 재시도한다.

`_pmap_remove_all`은 같은 derived bucket에서 primary fields와 node list를 읽는다. list
node는 link/field 세 dword를 bucket에 복사하거나 node를 `pv_entry_zone`으로 반환해
제거한다. 모든 mapping을 제거한 뒤 bucket `+0x04`를 0으로 만들고, PTE words를 clear한
후 local pmap update helper를 호출한다.

이 결과는 node field의 C type 또는 PV라는 이름을 확정하지 않는다. 다만 original
allocation zone symbol과 load/store/link sequence로 record lifetime을 확인한다.

## 미해결

`pmap_enter`는 additional-node path에서 local temporary-node slot이 0일 때 saved SPL
value로 `_splx`를 호출하고 `pv_entry_zone`에서 node를 얻은 뒤 lookup start로 되돌아간다.
이는 raw body에 `zalloc` failure test가 있는 경로가 아니므로, allocation-failure
rollback 또는 scheduler progress로 확대 해석하지 않는다. `pmap_enter`와
`pmap_remove_all`의 SPL/lock progress, `pmap_copy_on_write`·protect·remove의 모든 shared
chain 변형, physical-range 밖 mapping은 계속 조사 대상이다.
