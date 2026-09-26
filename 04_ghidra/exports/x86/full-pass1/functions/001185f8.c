/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001185f8 */

int _unp_attach(short *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar3 = _unpst_sendspace;
  uVar4 = _unpst_recvspace;
  if ((*param_1 != 1) && (uVar3 = _unpdg_sendspace, uVar4 = _unpdg_recvspace, *param_1 != 2)) {
                    /* WARNING: Subroutine does not return */
    _panic(s_unp_attack__bad_so_type_001db3ec);
  }
  iVar1 = _soreserve(param_1,uVar3,uVar4);
  if (iVar1 == 0) {
    puVar2 = (undefined4 *)_kalloc(0x24);
    _bzero(puVar2,0x24);
    *(undefined4 **)(param_1 + 4) = puVar2;
    *puVar2 = param_1;
    iVar1 = 0;
  }
  return iVar1;
}

