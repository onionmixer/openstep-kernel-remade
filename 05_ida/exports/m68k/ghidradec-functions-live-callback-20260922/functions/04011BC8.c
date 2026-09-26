
sword * _pffindproto(int param_1,int param_2,int param_3)

{
  int *piVar1;
  sword *psVar2;
  sword *psVar3;
  sword *psVar4;
  
  psVar2 = (sword *)0x0;
  piVar1 = _domains;
  if (param_1 == 0) {
    return (sword *)0x0;
  }
  while( true ) {
    if (piVar1 == (int *)0x0) {
      return (sword *)0x0;
    }
    if (param_1 == *piVar1) break;
    piVar1 = (int *)piVar1[7];
  }
  psVar3 = (sword *)piVar1[5];
  if (psVar3 < (sword *)piVar1[6]) {
    psVar4 = psVar3 + 3;
    do {
      if ((param_2 == *psVar4) && (param_3 == *psVar3)) {
        return psVar3;
      }
      if ((((param_3 == 3) && (*psVar3 == 3)) && (*psVar4 == 0)) && (psVar2 == (sword *)0x0)) {
        psVar2 = psVar3;
      }
      psVar4 = psVar4 + 0x17;
      psVar3 = psVar3 + 0x17;
    } while (psVar3 < (sword *)piVar1[6]);
    return psVar2;
  }
  return (sword *)0x0;
}

