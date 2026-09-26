
void _safe_prf(undefined4 param_1)

{
  char cVar1;
  char *pcStack_8;
  
  pcStack_8 = unk_40B373A;
  _prf(param_1,&stack0x00000008,8,&pcStack_8);
  *pcStack_8 = '\0';
  pcStack_8 = unk_40B373A;
  cVar1 = unk_40B373A[0];
  while (cVar1 != '\0') {
    cVar1 = *pcStack_8;
    pcStack_8 = pcStack_8 + 1;
    _miniMonPutchar((int)cVar1);
    cVar1 = *pcStack_8;
  }
  return;
}

