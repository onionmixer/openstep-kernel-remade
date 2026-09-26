
void _leavegroup(sword param_1)

{
  sword *psVar1;
  
  psVar1 = (sword *)(*(int *)(_active_u + 0x1a) + 10);
  while( true ) {
    if ((sword *)(*(int *)(_active_u + 0x1a) + 0x2a) <= psVar1) {
      return;
    }
    if (param_1 == *psVar1) break;
    psVar1 = psVar1 + 1;
  }
  for (; psVar1 < (sword *)(*(int *)(_active_u + 0x1a) + 0x28); psVar1 = psVar1 + 1) {
    *psVar1 = psVar1[1];
  }
  *psVar1 = -1;
  return;
}

