
int _unp_attach(sword *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar3 = _unpst_sendspace;
  uVar4 = _unpst_recvspace;
  if ((*param_1 != 1) && (uVar3 = _unpdg_sendspace, uVar4 = _unpdg_recvspace, *param_1 != 2)) {
                    /* WARNING: Subroutine does not return */
    _panic(aUnpAttackBadSo);
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
