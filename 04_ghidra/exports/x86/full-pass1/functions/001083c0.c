/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001083c0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

short * _crcopy(short *param_1)

{
  short sVar1;
  short *psVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 *puVar5;
  short *psVar6;
  short *psVar7;
  
  psVar2 = (short *)_kalloc();
  _bzero(psVar2,0x2a);
  *psVar2 = *psVar2 + 1;
  __cractive = __cractive + 1;
  puVar5 = &stack0xfffffff0;
  psVar6 = param_1;
  psVar7 = psVar2;
  for (iVar4 = 10; iVar4 != 0; iVar4 = iVar4 + -1) {
    *(undefined4 *)psVar7 = *(undefined4 *)psVar6;
    psVar6 = psVar6 + 2;
    psVar7 = psVar7 + 2;
  }
  *psVar7 = *psVar6;
  uVar3 = _splhigh();
  sVar1 = *param_1;
  *param_1 = sVar1 + -1;
  if (sVar1 == 1) {
    puVar5 = &stack0xffffffe8;
    _kfree();
    __cractive = __cractive + -1;
  }
  *(undefined4 *)(puVar5 + -4) = uVar3;
  *(undefined4 *)(puVar5 + -8) = 0x108423;
  _splx();
  *psVar2 = 1;
  return psVar2;
}

