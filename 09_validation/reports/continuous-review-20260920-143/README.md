# 143차 연속 검토 — vnode truncate/dealloc의 추가 간접 pager dispatch

`_vnode_pager_truncate`는 input low byte로 `0x001e7294` indexed table에서 EDI를 읽고,
`[EDI+8]`을 local에 저장한다. dispatch path에서 이 local을 ESI로 읽어 `[ESI+0x1c]`,
그 결과의 `+0x18` dword를 EAX로 읽고 `0x0017dc39 CALL EAX`를 실행한다.

`_vnode_dealloc`에는 table indexed load `0x0017dd29 MOV ESI,[EAX*4+0x001e7294]`와
별도 `0x0017e0a6 CALL EAX`가 있다. 이 report는 두 명령의 raw dataflow 조각을 보존하며,
dealloc path에서 table record와 indirect target의 full SSA provenance는 확정하지 않는다.

따라서 pager dispatch는 pagein/pageout의 `+0x74/+0x78` vector 외에도 truncate/dealloc
경로의 `CALL EAX`를 포함한다. callback type, runtime table selection, error meaning,
and all branches remain separate analysis work.

