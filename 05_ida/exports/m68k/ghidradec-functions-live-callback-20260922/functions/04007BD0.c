
undefined4 _suser(void)

{
  undefined4 uVar1;
  
  if (**(int **)(*(int *)(_active_threads + 0xc) + 0x30) == 0) {
    uVar1 = 0;
  }
  else if (*(sword *)(*(int *)(_active_u + 0x1a) + 2) == 0) {
    *(word *)(_active_u + 0x23a) = *(word *)(_active_u + 0x23a) | 2;
    uVar1 = 1;
  }
  else {
    *(undefined *)(dword_40B57D4 + 100) = 1;
    uVar1 = 0;
  }
  return uVar1;
}

