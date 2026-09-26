/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00108384 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _crfree(short *param_1)

{
  short sVar1;
  undefined4 uVar2;
  short **ppsVar3;
  short *psStack_14;
  undefined4 uStack_10;
  
  ppsVar3 = (short **)&stack0xfffffff4;
  uStack_10 = 0x108391;
  uVar2 = _splhigh();
  sVar1 = *param_1;
  *param_1 = sVar1 + -1;
  if (sVar1 == 1) {
    uStack_10 = 0x2a;
    ppsVar3 = &psStack_14;
    psStack_14 = param_1;
    _kfree();
    __cractive = __cractive + -1;
  }
  *(undefined4 *)((int)ppsVar3 + -4) = uVar2;
  *(undefined4 *)((int)ppsVar3 + -8) = 0x1083b7;
  _splx();
  return;
}

