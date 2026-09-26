
undefined4 _insert_posix_proc(uint *param_1,uint param_2)

{
  uint *puVar1;
  
  puVar1 = *(uint **)(_posix_proc_hash + (param_2 & 0x3f) * 4);
  while( true ) {
    if (puVar1 == (uint *)0x0) {
      *param_1 = param_2;
      *(undefined4 *)((int)param_1 + 0x1a) =
           *(undefined4 *)(_posix_proc_hash + (param_2 & 0x3f) * 4);
      *(uint **)(_posix_proc_hash + (param_2 & 0x3f) * 4) = param_1;
      return 1;
    }
    if (param_2 == *puVar1) break;
    puVar1 = *(uint **)((int)puVar1 + 0x1a);
  }
  return 0;
}
