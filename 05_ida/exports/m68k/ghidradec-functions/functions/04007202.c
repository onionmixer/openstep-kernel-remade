
uint * _new_posix_proc(uint param_1)

{
  uint *puVar1;
  
  puVar1 = *(uint **)(_posix_proc_hash + (param_1 & 0x3f) * 4);
  while( true ) {
    if (puVar1 == (uint *)0x0) {
      puVar1 = (uint *)_kalloc(0x1e);
      *puVar1 = param_1;
      *(undefined4 *)((int)puVar1 + 0x1a) = *(undefined4 *)(_posix_proc_hash + (param_1 & 0x3f) * 4)
      ;
      *(uint **)(_posix_proc_hash + (param_1 & 0x3f) * 4) = puVar1;
      return puVar1;
    }
    if (param_1 == *puVar1) break;
    puVar1 = *(uint **)((int)puVar1 + 0x1a);
  }
  return (uint *)0x0;
}
