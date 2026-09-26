
void _fssleep(int param_1,uint param_2)

{
  if ((param_2 & 1) == 0) {
    if ((param_2 & 2) == 0) {
                    /* WARNING: Subroutine does not return */
      _panic(&aFssleep);
    }
    if (*(int *)(param_1 + 200) <= *(int *)(param_1 + 0x90)) {
      do {
        _sleep((int *)(param_1 + 200),0x1a);
      } while (*(int *)(param_1 + 200) <= *(int *)(param_1 + 0x90));
    }
  }
  else if (*(int *)(param_1 + 0xcc) +
           (*(int *)(param_1 + 0xc4) << (*(uint *)(param_1 + 0x60) & 0x3f)) <=
           *(int *)(param_1 + 0x88)) {
    do {
      _sleep((int *)(param_1 + 0xcc),0x1a);
    } while (*(int *)(param_1 + 0xcc) +
             (*(int *)(param_1 + 0xc4) << (*(uint *)(param_1 + 0x60) & 0x3f)) <=
             *(int *)(param_1 + 0x88));
  }
  return;
}
