# 디컴파일러 한계 기록

- `_vm_fault`의 decompiler C는 여러 `return 10`, `return 0`, `return iVar9`를 표현한다.
  원본은 공통 epilogue로 향하는 `jmp 0x00173580`을 사용하므로, 본 보고서는 각 jump
  직전의 EAX 설정을 독립적으로 확인했다.
- object와 map-entry field의 이름·타입은 export C만으로 확정하지 않았다. 본문에서 확인한
  것은 offset, load/store, bit test 및 직접 call 순서다.
- `_vm_object_shadow`의 output pointer 갱신은 명령으로 확인했지만, 생성 object의 이후
  모든 caller-side 참조 count 정책은 아직 범위 밖이다.
- `vm_fault_copy_entry`의 allocation 재시도는 보였으나 `thread_sleep` 이후 wake 원인과
  scheduler-level 진행성은 별도 동시성 검토가 필요하다.
