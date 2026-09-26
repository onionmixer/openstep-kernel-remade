/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001934ec */

void _sendsig(undefined4 param_1,int param_2,undefined4 param_3)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  ushort *puVar8;
  int iVar9;
  uint uVar10;
  int local_60;
  uint local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  uint local_30;
  undefined4 local_2c;
  undefined4 local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  int local_10;
  undefined4 local_c;
  int local_8;
  
  iVar7 = _active_threads;
  iVar9 = *(int *)(*(int *)(_active_threads + 0x28) + 0x70);
  if (iVar9 == 0) {
    puVar8 = (ushort *)_thread_user_state(_active_threads);
  }
  else {
    puVar8 = (ushort *)(iVar9 + 0x84);
  }
  uVar10 = _active_u[0x53];
  if ((uVar10 == 0) && (((int)_active_u[0x4f] >> ((char)param_2 - 1U & 0x1f) & 1U) != 0)) {
    uVar5 = _active_u[0x52];
    _active_u[0x53] = 1;
  }
  else {
    uVar5 = *(uint *)(puVar8 + 0x22);
  }
  local_60 = uVar5 - 0x48;
  local_10 = param_2;
  if ((param_2 == 4) || (param_2 == 8)) {
    local_c = *(undefined4 *)(DAT_001e875c + 0x74);
    *(undefined4 *)(DAT_001e875c + 0x74) = 0;
  }
  else {
    local_c = 0;
  }
  local_8 = local_60;
  iVar9 = _copyout(&local_10,uVar5 - 0x54,0xc);
  if (iVar9 == 0) {
    piVar6 = *(int **)(*(int *)(iVar7 + 0x28) + 0xec);
    iVar9 = 0;
    if (piVar6 != (int *)0x0) {
      iVar9 = *piVar6;
    }
    if ((iVar9 == 0) || (7 < *(uint *)(iVar9 + 0x84))) {
      iVar9 = 0;
    }
    else {
      iVar9 = iVar9 + 0x88 + *(uint *)(iVar9 + 0x84) * 0x84;
    }
    if ((iVar9 != 0) && (*(int *)(iVar9 + 0x48) != 0)) {
      uVar10 = uVar10 | 2;
      *(undefined4 *)(iVar9 + 0x48) = 0;
    }
    local_54 = param_3;
    local_50 = *(undefined4 *)(puVar8 + 0x16);
    local_4c = *(undefined4 *)(puVar8 + 0x10);
    local_48 = *(undefined4 *)(puVar8 + 0x14);
    local_44 = *(undefined4 *)(puVar8 + 0x12);
    local_40 = *(undefined4 *)(puVar8 + 8);
    local_3c = *(undefined4 *)(puVar8 + 10);
    local_38 = *(undefined4 *)(puVar8 + 0xc);
    local_34 = *(undefined4 *)(puVar8 + 0x22);
    local_30 = (uint)puVar8[0x24];
    local_2c = *(undefined4 *)(puVar8 + 0x20);
    local_28 = *(undefined4 *)(puVar8 + 0x1c);
    local_24 = (uint)puVar8[0x1e];
    if ((puVar8[0x21] & 2) == 0) {
      uVar1 = puVar8[6];
      uVar2 = puVar8[4];
      uVar3 = puVar8[2];
      uVar4 = *puVar8;
    }
    else {
      uVar1 = puVar8[0x28];
      uVar2 = puVar8[0x26];
      uVar3 = puVar8[0x2a];
      uVar4 = puVar8[0x2c];
      *(uint *)(puVar8 + 0x20) = *(uint *)(puVar8 + 0x20) & 0xfffdffff;
    }
    local_14 = (uint)uVar4;
    local_18 = (uint)uVar3;
    local_1c = (uint)uVar2;
    local_20 = (uint)uVar1;
    local_58 = uVar10;
    iVar9 = _copyout(&local_58,local_60,0x48);
    if (iVar9 == 0) {
      *(undefined4 *)(puVar8 + 0x1c) = param_1;
      puVar8[0x1e] = 99;
      *(uint *)(puVar8 + 0x22) = uVar5 - 0x54;
      puVar8[0x24] = 0x6b;
      puVar8[6] = 0x6b;
      puVar8[4] = 0x6b;
      puVar8[2] = 0;
      *puVar8 = 0;
      return;
    }
  }
  _active_u[0x10] = 0;
  *(uint *)(*_active_u + 0x20) = *(uint *)(*_active_u + 0x20) & 0xfffffff7;
  *(uint *)(*_active_u + 0x24) = *(uint *)(*_active_u + 0x24) & 0xfffffff7;
  *(uint *)(*_active_u + 0x1c) = *(uint *)(*_active_u + 0x1c) & 0xfffffff7;
  _psignal(*_active_u,(char *)0x4);
  return;
}

