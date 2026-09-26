/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c72c0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_001c72c0(int param_1,undefined4 param_2,uint param_3,undefined4 *param_4)

{
  uint uVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  uint uVar6;
  byte bVar7;
  ushort uVar8;
  undefined4 uVar9;
  int iVar10;
  undefined2 uVar11;
  uint uVar12;
  undefined4 *puVar13;
  undefined4 *puVar14;
  uint local_44 [8];
  undefined4 local_24 [8];
  
  if ((*(int *)(param_1 + 0x23c) == 0) || (*(int *)(param_1 + 0x240) == 0)) {
    uVar9 = _objc_msgSend(param_1,PTR_s_name_001f9228);
    _IOLog("%s: No vpcode to run.\n",uVar9);
    return 0;
  }
  if (param_4 == (undefined4 *)0x0) {
    _memset(local_44,0,0x40);
  }
  else {
    _memset(local_44,0,0x20);
    puVar13 = param_4;
    puVar14 = local_24;
    for (iVar10 = 8; iVar10 != 0; iVar10 = iVar10 + -1) {
      *puVar14 = *puVar13;
      puVar13 = puVar13 + 1;
      puVar14 = puVar14 + 1;
    }
  }
  uVar12 = 0;
  bVar3 = false;
  bVar2 = false;
  bVar4 = false;
LAB_001c73f0:
  if (((int)param_3 < 0) || (*(uint *)(param_1 + 0x240) <= param_3)) {
    uVar9 = _objc_msgSend(param_1,PTR_s_name_001f9228,param_3);
    _IOLog("%s: program counter is out of range: 0x%x.\n",uVar9);
    return 0;
  }
  uVar1 = *(uint *)(*(int *)(param_1 + 0x23c) + param_3 * 4);
  uVar6 = param_3 + 1;
  if ((uVar1 >> 0x1a & 0x20) != 0) {
    uVar12 = *(uint *)(*(int *)(param_1 + 0x23c) + (param_3 + 1) * 4);
    uVar6 = param_3 + 2;
  }
  param_3 = uVar6;
  uVar11 = (undefined2)uVar1;
  bVar7 = (byte)(uVar1 >> 0x10);
  switch(uVar1 >> 0x1a) {
  case 1:
    uVar12 = local_44[uVar1 >> 0x15 & 0xf];
    if (*(uint *)(param_1 + 0x240) <= uVar12) {
      uVar9 = _objc_msgSend(param_1,PTR_s_name_001f9228,uVar12);
      _IOLog("%s: load address is out of range: 0x%x.\n",uVar9);
      return 0;
    }
    local_44[uVar1 >> 0x10 & 0xf] = *(uint *)(*(int *)(param_1 + 0x23c) + uVar12 * 4);
    goto LAB_001c73f0;
  case 2:
    *(undefined1 *)(param_1 + 0x250) = 1;
    goto LAB_001c73f0;
  case 3:
    uVar12 = local_44[uVar1 >> 0x15 & 0xf];
    iVar10 = *(int *)(param_1 + 0x248);
    if ((iVar10 == 0) || (*(uint *)(param_1 + 0x24c) <= uVar12)) {
      uVar9 = _objc_msgSend(param_1,PTR_s_name_001f9228,iVar10 + uVar12);
      _IOLog("%s: invalid video ram address: 0x%x.\n",uVar9);
      return 0;
    }
    goto LAB_001c7674;
  case 4:
    uVar12 = local_44[uVar1 >> 0x10 & 0xf];
    if (*(uint *)(param_1 + 0x240) <= uVar12) {
      uVar9 = _objc_msgSend(param_1,PTR_s_name_001f9228,uVar12);
      _IOLog("%s: store address is out of range: 0x%x.\n",uVar9);
      return 0;
    }
    goto LAB_001c76af;
  case 5:
    local_44[uVar1 >> 0xb & 0xf] = local_44[uVar1 >> 0x15 & 0xf] + local_44[uVar1 >> 0x10 & 0xf];
    goto LAB_001c73f0;
  case 6:
    local_44[uVar1 >> 0xb & 0xf] = local_44[uVar1 >> 0x15 & 0xf] - local_44[uVar1 >> 0x10 & 0xf];
    goto LAB_001c73f0;
  case 7:
    uVar12 = local_44[uVar1 >> 0x10 & 0xf];
    iVar10 = *(int *)(param_1 + 0x248);
    if ((iVar10 == 0) || (*(uint *)(param_1 + 0x24c) <= uVar12 * 4)) {
      uVar9 = _objc_msgSend(param_1,PTR_s_name_001f9228,iVar10 + uVar12);
      _IOLog("%s: invalid video ram address: 0x%x.\n",uVar9);
      return 0;
    }
    goto LAB_001c7770;
  case 8:
    local_44[uVar1 >> 0xb & 0xf] = local_44[uVar1 >> 0x15 & 0xf] & local_44[uVar1 >> 0x10 & 0xf];
    goto LAB_001c73f0;
  case 9:
    local_44[uVar1 >> 0xb & 0xf] = local_44[uVar1 >> 0x15 & 0xf] | local_44[uVar1 >> 0x10 & 0xf];
    goto LAB_001c73f0;
  case 10:
    local_44[uVar1 >> 0xb & 0xf] = local_44[uVar1 >> 0x15 & 0xf] ^ local_44[uVar1 >> 0x10 & 0xf];
    goto LAB_001c73f0;
  case 0xb:
    local_44[uVar1 >> 0xb & 0xf] = local_44[uVar1 >> 0x15 & 0xf] << (bVar7 & 0x1f);
    goto LAB_001c73f0;
  case 0xc:
    local_44[uVar1 >> 0xb & 0xf] = local_44[uVar1 >> 0x15 & 0xf] >> (bVar7 & 0x1f);
    goto LAB_001c73f0;
  case 0xd:
    local_44[uVar1 >> 0x10 & 0xf] = local_44[uVar1 >> 0x15 & 0xf];
    goto LAB_001c73f0;
  case 0xe:
    uVar12 = local_44[uVar1 >> 0x15 & 0xf];
    goto LAB_001c79b0;
  case 0xf:
    uVar12 = local_44[uVar1 >> 0x15 & 0xf] - local_44[uVar1 >> 0x10 & 0xf];
    goto LAB_001c79b0;
  default:
    uVar9 = _objc_msgSend(param_1,PTR_s_name_001f9228,uVar1,param_3);
    _IOLog("%s: Unrecognized opcode: 0x%08x; pc: 0x%x\n",uVar9);
    return 0;
  case 0x11:
    break;
  case 0x12:
    bVar5 = bVar2;
    goto joined_r0x001c7a60;
  case 0x13:
    bVar5 = bVar3;
    goto joined_r0x001c7a60;
  case 0x14:
    bVar5 = bVar4;
joined_r0x001c7a60:
    if (!bVar5) goto LAB_001c73f0;
    break;
  case 0x15:
    if (bVar2) goto LAB_001c73f0;
    break;
  case 0x16:
    if (bVar3) goto LAB_001c73f0;
    break;
  case 0x17:
    if (bVar4) goto LAB_001c73f0;
    break;
  case 0x18:
    bVar7 = in(uVar11);
    local_44[uVar1 >> 0x10 & 0xf] = (uint)bVar7;
    goto LAB_001c73f0;
  case 0x19:
    out(uVar11,(char)local_44[uVar1 >> 0x10 & 0xf]);
    LOCK();
    _DAT_001e873c = _DAT_001e873c + 1;
    UNLOCK();
    goto LAB_001c73f0;
  case 0x1a:
    uVar8 = in(uVar11);
    local_44[uVar1 >> 0x10 & 0xf] = (uint)uVar8;
    goto LAB_001c73f0;
  case 0x1b:
    out(uVar11,(short)local_44[uVar1 >> 0x10 & 0xf]);
    LOCK();
    _DAT_001e8740 = _DAT_001e8740 + 1;
    UNLOCK();
    goto LAB_001c73f0;
  case 0x1c:
    _objc_msgSend(param_1,PTR_s_jumpTo_withInitialSRegs__001f9578,uVar1 & 0x3ffffff,local_24);
    goto LAB_001c73f0;
  case 0x1d:
    if (param_4 == (undefined4 *)0x0) {
      return param_1;
    }
    puVar13 = local_24;
    for (iVar10 = 8; iVar10 != 0; iVar10 = iVar10 + -1) {
      *param_4 = *puVar13;
      puVar13 = puVar13 + 1;
      param_4 = param_4 + 1;
    }
    return param_1;
  case 0x21:
  case 0x22:
    local_44[uVar1 >> 0x10 & 0xf] = uVar12;
    goto LAB_001c73f0;
  case 0x23:
    if (*(uint *)(param_1 + 0x240) <= uVar12) {
      uVar9 = _objc_msgSend(param_1,PTR_s_name_001f9228,uVar12);
      _IOLog("%s: load address is out of range: 0x%x.\n",uVar9);
      return 0;
    }
    iVar10 = *(int *)(param_1 + 0x23c);
    goto LAB_001c7674;
  case 0x24:
    if (*(uint *)(param_1 + 0x240) <= uVar12) {
      uVar9 = _objc_msgSend(param_1,PTR_s_name_001f9228,uVar12);
      _IOLog("%s: store address is out of range: 0x%x.\n",uVar9);
      return 0;
    }
LAB_001c76af:
    *(uint *)(*(int *)(param_1 + 0x23c) + uVar12 * 4) = local_44[uVar1 >> 0x15 & 0xf];
    goto LAB_001c73f0;
  case 0x25:
    local_44[uVar1 >> 0x10 & 0xf] = local_44[uVar1 >> 0x15 & 0xf] + uVar12;
    goto LAB_001c73f0;
  case 0x26:
    local_44[uVar1 >> 0x10 & 0xf] = uVar12 - local_44[uVar1 >> 0x15 & 0xf];
    goto LAB_001c73f0;
  case 0x27:
    local_44[uVar1 >> 0x10 & 0xf] = local_44[uVar1 >> 0x15 & 0xf] - uVar12;
    goto LAB_001c73f0;
  case 0x28:
    local_44[uVar1 >> 0x10 & 0xf] = local_44[uVar1 >> 0x15 & 0xf] & uVar12;
    goto LAB_001c73f0;
  case 0x29:
    local_44[uVar1 >> 0x10 & 0xf] = local_44[uVar1 >> 0x15 & 0xf] | uVar12;
    goto LAB_001c73f0;
  case 0x2a:
    local_44[uVar1 >> 0x10 & 0xf] = local_44[uVar1 >> 0x15 & 0xf] ^ uVar12;
    goto LAB_001c73f0;
  case 0x2b:
    _IODelay(uVar12);
    goto LAB_001c73f0;
  case 0x2c:
    iVar10 = *(int *)(param_1 + 0x248);
    if ((iVar10 == 0) || (*(uint *)(param_1 + 0x24c) <= uVar12)) {
      uVar9 = _objc_msgSend(param_1,PTR_s_name_001f9228,iVar10 + uVar12);
      _IOLog("%s: invalid video ram address: 0x%x.\n",uVar9);
      return 0;
    }
LAB_001c7674:
    local_44[uVar1 >> 0x10 & 0xf] = *(uint *)(iVar10 + uVar12 * 4);
    goto LAB_001c73f0;
  case 0x2d:
    iVar10 = *(int *)(param_1 + 0x248);
    if ((iVar10 == 0) || (*(uint *)(param_1 + 0x24c) <= uVar12 * 4)) {
      uVar9 = _objc_msgSend(param_1,PTR_s_name_001f9228,iVar10 + uVar12);
      _IOLog("%s: invalid video ram address: 0x%x.\n",uVar9);
      return 0;
    }
LAB_001c7770:
    *(uint *)(iVar10 + uVar12 * 4) = local_44[uVar1 >> 0x15 & 0xf];
    goto LAB_001c73f0;
  case 0x2f:
    uVar12 = local_44[uVar1 >> 0x15 & 0xf] - uVar12;
    goto LAB_001c79b0;
  case 0x30:
    uVar12 = uVar12 - local_44[uVar1 >> 0x15 & 0xf];
LAB_001c79b0:
    bVar4 = false;
    bVar2 = false;
    bVar3 = false;
    if (uVar12 == 0) {
      bVar4 = true;
    }
    else if ((int)uVar12 < 1) {
      bVar3 = true;
    }
    else {
      bVar2 = true;
    }
    goto LAB_001c73f0;
  case 0x39:
    out(uVar11,(char)uVar12);
    LOCK();
    _DAT_001e873c = _DAT_001e873c + 1;
    UNLOCK();
    goto LAB_001c73f0;
  case 0x3b:
    goto switchD_001c7453_caseD_3b;
  }
  param_3 = uVar1 & 0x3ffffff;
  goto LAB_001c73f0;
switchD_001c7453_caseD_3b:
  out(uVar11,(short)uVar12);
  LOCK();
  _DAT_001e8740 = _DAT_001e8740 + 1;
  UNLOCK();
  goto LAB_001c73f0;
}

