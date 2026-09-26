/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00129c60 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint _tcp_mss(int param_1,ushort param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  iVar3 = *(int *)(param_1 + 0x20);
  iVar2 = *(int *)(iVar3 + 0x24);
  if (iVar2 == 0) {
    if (*(int *)(iVar3 + 0xc) != 0) {
      *(undefined2 *)(iVar3 + 0x28) = 2;
      *(undefined4 *)(iVar3 + 0x2c) = *(undefined4 *)(iVar3 + 0xc);
      _rtalloc(iVar3 + 0x24);
    }
    iVar2 = *(int *)(iVar3 + 0x24);
    if (iVar2 == 0) {
      return __tcp_mssdflt;
    }
  }
  iVar1 = *(int *)(iVar3 + 0x1c);
  uVar5 = (int)*(short *)(*(int *)(iVar2 + 0x2c) + 10) - 0x28;
  if (0x400 < (int)uVar5) {
    uVar5 = uVar5 & 0xfffffc00;
  }
  iVar3 = _in_localaddr(*(undefined4 *)(iVar3 + 0xc));
  if (iVar3 == 0) {
    uVar5 = _min(uVar5,__tcp_mssdflt);
  }
  if ((param_2 != 0) && ((int)(uint)param_2 < (int)uVar5)) {
    uVar5 = (uint)param_2;
  }
  if ((int)uVar5 < 0x20) {
    uVar5 = 0x20;
  }
  if (((int)uVar5 < (int)(uint)*(ushort *)(param_1 + 0x18)) || (uVar4 = uVar5, param_2 != 0)) {
    uVar4 = (uint)*(ushort *)(iVar1 + 0x3e);
    if (uVar5 <= uVar4) {
      uVar4 = _min(uVar4,0xffff);
      _sbreserve(iVar1 + 0x3c,(uVar4 / uVar5) * uVar5);
      uVar4 = uVar5;
    }
    *(short *)(param_1 + 0x18) = (short)uVar4;
    if (uVar4 < *(ushort *)(iVar1 + 0x26)) {
      uVar5 = _min((uint)*(ushort *)(iVar1 + 0x26),0xffff);
      _sbreserve(iVar1 + 0x24,(uVar5 / uVar4) * uVar4);
    }
  }
  *(short *)(param_1 + 0x54) = (short)uVar4;
  return uVar4;
}

