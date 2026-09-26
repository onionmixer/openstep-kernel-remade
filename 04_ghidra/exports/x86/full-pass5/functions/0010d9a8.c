/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010d9a8 */

undefined4 _soo_select(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = *(int *)(param_1 + 0x18);
  uVar1 = _splnet();
  if (param_2 == 1) {
    if ((((*(short *)(iVar2 + 0x24) != 0) || ((*(byte *)(iVar2 + 6) & 0x20) != 0)) ||
        (*(short *)(iVar2 + 0x20) != 0)) || (*(short *)(iVar2 + 0x56) != 0)) {
      _splx(uVar1);
      return 1;
    }
LAB_0010da80:
    iVar2 = iVar2 + 0x24;
  }
  else {
    if (param_2 < 2) {
      if (param_2 != 0) goto LAB_0010da8c;
      if ((*(short *)(iVar2 + 0x58) != 0) || ((*(byte *)(iVar2 + 6) & 0x40) != 0)) {
        _splx(uVar1);
        return 1;
      }
      goto LAB_0010da80;
    }
    if (param_2 != 2) goto LAB_0010da8c;
    iVar3 = (uint)*(ushort *)(iVar2 + 0x42) - (uint)*(ushort *)(iVar2 + 0x40);
    iVar4 = (uint)*(ushort *)(iVar2 + 0x3e) - (uint)*(ushort *)(iVar2 + 0x3c);
    if (iVar3 < iVar4) {
      iVar4 = iVar3;
    }
    if ((((0 < iVar4) &&
         (((*(byte *)(iVar2 + 6) & 2) != 0 || ((*(byte *)(*(int *)(iVar2 + 0xc) + 10) & 4) == 0))))
        || ((*(byte *)(iVar2 + 6) & 0x10) != 0)) || (*(short *)(iVar2 + 0x56) != 0)) {
      _splx(uVar1);
      return 1;
    }
    iVar2 = iVar2 + 0x3c;
  }
  _sbselqueue(iVar2);
LAB_0010da8c:
  _splx(uVar1);
  return 0;
}

