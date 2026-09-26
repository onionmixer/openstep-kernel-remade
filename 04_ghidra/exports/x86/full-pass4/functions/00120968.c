/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00120968 */

undefined4 FUN_00120968(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  size_t sVar3;
  void *pvVar4;
  void *pvVar5;
  int iVar6;
  int iVar7;
  
  iVar1 = _if_getbuf(param_1);
  if (iVar1 == 0) {
    _nb_free(param_2);
    uVar2 = 1;
  }
  else {
    sVar3 = _nb_size(param_2);
    pvVar4 = (void *)_nb_map(iVar1);
    pvVar5 = (void *)_nb_map(param_2);
    _bcopy(pvVar5,pvVar4,sVar3);
    iVar6 = _nb_size(iVar1);
    iVar7 = _nb_size(param_2);
    _nb_shrink_bot(iVar1,iVar6 - iVar7);
    _nb_free(param_2);
    uVar2 = _if_output(param_1,iVar1,param_3);
  }
  return uVar2;
}

