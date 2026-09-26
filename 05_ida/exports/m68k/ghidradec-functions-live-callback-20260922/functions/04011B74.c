
sword * _pffindtype(int param_1,int param_2)

{
  int *piVar1;
  sword *psVar2;
  
  piVar1 = _domains;
  while( true ) {
    if (piVar1 == (int *)0x0) {
      return (sword *)0x0;
    }
    if (param_1 == *piVar1) break;
    piVar1 = (int *)piVar1[7];
  }
  psVar2 = (sword *)piVar1[5];
  while( true ) {
    if ((sword *)piVar1[6] <= psVar2) {
      return (sword *)0x0;
    }
    if ((*psVar2 != 0) && (param_2 == *psVar2)) break;
    psVar2 = psVar2 + 0x17;
  }
  return psVar2;
}

