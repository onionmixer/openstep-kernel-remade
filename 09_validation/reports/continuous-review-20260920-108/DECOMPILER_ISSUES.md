# 디컴파일러 한계 기록

- `+0x28` offset은 map object와 map entry 모두에서 나타난다. export C의 type recovery를
  근거로 두 field를 동일시하지 않았다. register provenance와 allocator/caller context를
  원시 명령으로 분리했다.
- `vm_page_startup`의 descriptor layout과 boot input structure layout은 아직 완전히
  검증하지 않았다. 보고서는 loop의 address arithmetic과 write만 기록한다.
- `pmap_bootstrap`의 PDE/PTE bit 이름과 processor semantics는 명령의 bit 조작으로부터
  추정하지 않았다. CR3/CR0 write와 immediate value만 확정했다.
