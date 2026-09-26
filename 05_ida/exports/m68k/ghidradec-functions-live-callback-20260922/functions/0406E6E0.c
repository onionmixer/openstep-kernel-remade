
undefined4 _fd_set_sector_size(int param_1,int param_2)

{
  int *piVar1;
  
  piVar1 = (int *)_fd_get_sectsize_info(*(undefined4 *)(param_1 + 0x17a));
  if (*piVar1 != 0) {
    do {
      if (param_2 == *piVar1) break;
      piVar1 = piVar1 + 3;
    } while (*piVar1 != 0);
    if (*piVar1 != 0) {
      *(int *)(param_1 + 0x186) = *piVar1;
      *(int *)(param_1 + 0x18a) = piVar1[1];
      *(int *)(param_1 + 0x18e) = piVar1[2];
      *(uint *)(param_1 + 0x192) =
           *(int *)(param_1 + 0x16e) * *(int *)(param_1 + 0x18c) * (uint)*(byte *)(param_1 + 0x16c);
      *(uint *)(param_1 + 0x176) = *(uint *)(param_1 + 0x176) & 0xfffffffd | 1;
      return 0;
    }
  }
  return 1;
}

