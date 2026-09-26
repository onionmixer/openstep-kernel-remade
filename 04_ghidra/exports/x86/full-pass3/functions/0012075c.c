/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012075c */

int FUN_0012075c(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  iVar2 = _if_private(param_1);
  uVar1 = *(undefined4 *)(iVar2 + 0x14);
  uVar3 = _if_mtu(param_1);
  iVar2 = _if_getbuf(uVar1);
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  else {
    _nb_shrink_top(iVar2,8);
    uVar4 = _nb_size(iVar2);
    if (uVar3 < uVar4) {
      iVar5 = _nb_size(iVar2);
      _nb_shrink_bot(iVar2,iVar5 - uVar3);
    }
  }
  return iVar2;
}

