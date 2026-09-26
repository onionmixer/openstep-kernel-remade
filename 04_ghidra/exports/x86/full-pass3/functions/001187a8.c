/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001187a8 */

int _unp_connect(short *param_1,int param_2)

{
  int iVar1;
  short *psVar2;
  int local_8;
  
  iVar1 = *(int *)(param_2 + 4) + param_2;
  if (*(int *)(param_2 + 4) + -0xc + (int)*(short *)(param_2 + 8) == 0x70) {
    return 0x28;
  }
  *(undefined1 *)(*(short *)(param_2 + 8) + iVar1) = 0;
  iVar1 = _lookupname(iVar1 + 2,1,1,0,&local_8);
  if (iVar1 != 0) {
    return iVar1;
  }
  if (*(int *)(local_8 + 0x28) != 6) {
    iVar1 = 0x26;
    goto LAB_0011884e;
  }
  psVar2 = *(short **)(local_8 + 0x20);
  if (psVar2 != (short *)0x0) {
    if (*param_1 != *psVar2) {
      iVar1 = 0x29;
      goto LAB_0011884e;
    }
    if (((*(byte *)(*(int *)(param_1 + 6) + 10) & 4) == 0) ||
       (((*(byte *)(psVar2 + 1) & 2) != 0 &&
        (psVar2 = (short *)_sonewconn(psVar2), psVar2 != (short *)0x0)))) {
      iVar1 = _unp_connect2(param_1,psVar2);
      goto LAB_0011884e;
    }
  }
  iVar1 = 0x3d;
LAB_0011884e:
  _vn_rele(local_8);
  return iVar1;
}

