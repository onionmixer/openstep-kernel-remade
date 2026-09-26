
bool _badblock(int param_1,uint param_2)

{
  bool bVar1;
  
  bVar1 = *(uint *)(param_1 + 0x24) <= param_2;
  if (bVar1) {
    _printf(aBadBlockD,param_2);
    _fserr(param_1,aBadBlock);
  }
  return bVar1;
}
