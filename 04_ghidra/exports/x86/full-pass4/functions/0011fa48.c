/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011fa48 */

int FUN_0011fa48(undefined4 param_1,undefined4 param_2,short *param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 local_1c [4];
  undefined4 local_18;
  undefined1 local_14 [12];
  ushort local_8 [2];
  
  iVar2 = _if_private(param_1);
  uVar1 = *(undefined4 *)(iVar2 + 0xc);
  if (*param_3 == 0) {
    _bcopy(param_3 + 1,local_14,0xe);
  }
  else {
    if (*param_3 != 2) {
      _nb_free(param_2);
      return 0x2f;
    }
    local_18 = *(undefined4 *)(param_3 + 2);
    iVar2 = _if_private(param_1,param_2,&local_18,local_14,local_1c);
    uVar3 = _if_private(param_1,*(undefined4 *)(iVar2 + 8));
    iVar2 = _arpresolve(param_1,uVar3);
    if (iVar2 == 0) {
      return 0;
    }
    local_8[0] = 0x800;
  }
  local_8[0] = local_8[0] >> 8 | local_8[0] << 8;
  _nb_grow_top(param_2,0xe);
  _nb_write(param_2,0xc,2,local_8);
  iVar2 = _if_output(uVar1,param_2,local_14);
  if (iVar2 == 0) {
    iVar4 = _if_opackets(param_1);
    _if_opackets_set(param_1,iVar4 + 1);
  }
  else {
    iVar4 = _if_oerrors(param_1);
    _if_oerrors_set(param_1,iVar4 + 1);
  }
  return iVar2;
}

