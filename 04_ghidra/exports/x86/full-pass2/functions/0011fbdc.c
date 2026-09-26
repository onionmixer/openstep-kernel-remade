/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011fbdc */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0011fbdc(undefined4 param_1,undefined4 param_2,short *param_3)

{
  undefined4 uVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  undefined1 local_2c [4];
  undefined4 local_28;
  undefined1 local_24;
  undefined1 local_23;
  char local_22 [6];
  byte local_1c;
  undefined1 local_16;
  undefined1 local_15;
  
  iVar2 = _if_private(param_1);
  uVar1 = *(undefined4 *)(iVar2 + 0x14);
  if (*param_3 == 0) {
    _bcopy(param_3 + 1,local_22,6);
    _DAT_001db89c = (ushort)param_3[7] >> 8 | param_3[7] << 8;
    if (_DAT_001db89c == 0x608) {
      _nb_write(param_2,0,2,&DAT_001db8a0);
      pbVar3 = (byte *)_if_private(param_1);
      if ((*pbVar3 & 1) == 0) {
        local_1c = local_1c & 0x7f;
      }
      else {
        local_1c = local_1c | 0x80;
        local_16 = 0x82;
        local_15 = 0x70;
      }
    }
    goto LAB_0011fd60;
  }
  if (*param_3 != 2) {
    _nb_free(param_2);
    return 0x2f;
  }
  local_28 = *(undefined4 *)(param_3 + 2);
  iVar2 = _if_private(param_1,param_2,&local_28,local_22,local_2c);
  iVar2 = _if_private(param_1,*(undefined4 *)(iVar2 + 0x10));
  iVar2 = _arpresolve(param_1,iVar2 + 8);
  if (iVar2 == 0) {
    return 0;
  }
  pbVar3 = (byte *)_if_private(param_1);
  if ((*pbVar3 & 1) == 0) {
LAB_0011fd38:
    local_1c = local_1c & 0x7f;
  }
  else if (local_22[0] < '\0') {
    local_1c = local_1c | 0x80;
    local_16 = 0xc2;
    local_15 = 0x70;
  }
  else {
    iVar2 = _if_private(param_1);
    if (-1 < local_22[0]) {
      iVar2 = _NXHashGet(*(undefined4 *)(iVar2 + 4),local_22);
      pbVar3 = (byte *)0x0;
      if (iVar2 != 0) {
        pbVar3 = (byte *)(iVar2 + 0xc);
      }
      if (pbVar3 == (byte *)0x0) goto LAB_0011fd38;
      _bcopy(pbVar3,&local_16,*pbVar3 & 0x1f);
      local_1c = local_1c | 0x80;
    }
  }
  _DAT_001db89c = 8;
LAB_0011fd60:
  _nb_grow_top(param_2,8);
  _nb_write(param_2,0,8,&DAT_001db896);
  iVar2 = _if_private(param_1);
  local_24 = *(undefined1 *)(iVar2 + 0x18);
  local_23 = 0x40;
  iVar2 = _if_output(uVar1,param_2,&local_24);
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

