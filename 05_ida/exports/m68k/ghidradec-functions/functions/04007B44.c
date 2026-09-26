
undefined4 _entergroup(sword param_1)

{
  sword *psVar1;
  
  psVar1 = (sword *)(*(int *)(_active_u + 0x1a) + 10);
  if (psVar1 < (sword *)(*(int *)(_active_u + 0x1a) + 0x2a)) {
    do {
      if (param_1 == *psVar1) {
        return 0;
      }
      if (*psVar1 == -1) {
        *psVar1 = param_1;
        return 0;
      }
      psVar1 = psVar1 + 1;
    } while (psVar1 < (sword *)(*(int *)(_active_u + 0x1a) + 0x2a));
  }
  return 0xffffffff;
}
