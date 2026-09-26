# 76차 — 원본 zone collect/reclaim·GC 및 VM 반환 wrapper

직전 75차 checkpoint를 재검증한 뒤 회수 경로를 이어서 분석한다. 다른 프로젝트 소스와
복원 코드는 참고하지 않는다. Ghidra 스킬을 보존 원본 asm/C 대조에 적용한다.

대상은 zone_collect(0x16a7f4), zone_free_space_reclaim(0x16ab34), zone_gc(0x16b970),
zone_reclaim(0x16bad0), consider_zone_gc(0x16ba88), gc_control(0x17c428),
kmem_free(0x173e90), vm_map_remove(0x1765ac)의 보존 본문이다.

검증할 계약: zone 원소 이전·병합과 accounting, 페이지 경계 분할 및 hint/link/count,
호출자가 보유한 lock의 소비, VM 해제 전 next 보존, 상위 GC gate와 직접 하위 wrapper의
반환값·범위 조정. 원본 하위 vm_map_delete 전체와 실제 주소 재사용은 미검증 경계다.

Python으로 원본 Mach-O 매핑·심볼·재디코딩·분기·크기/비트·해시를 계산한다.
수치 예시는 유한 산술이며 실제 allocator 실행이나 emulator가 아니다.
원본·DB·기존 export·이전 보고서·복원 코드는 수정하지 않는다. 구현·빌드·포팅·새 실행
검증 프로그램·동적 실행·새 독립 계획 교차검토는 수행하지 않는다.
