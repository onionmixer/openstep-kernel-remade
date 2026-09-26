/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012a504 */

void _tcp_respond(int param_1,undefined4 *param_2,undefined4 *param_3,uint param_4,uint param_5,
                 undefined1 param_6)

{
  undefined4 uVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int local_c;
  int local_8;
  
  local_8._0_2_ = 0;
  local_c = 0;
  if (param_1 != 0) {
    iVar4 = *(int *)(*(int *)(param_1 + 0x20) + 0x1c);
    iVar3 = (uint)*(ushort *)(iVar4 + 0x2a) - (uint)*(ushort *)(iVar4 + 0x28);
    local_8 = (uint)*(ushort *)(iVar4 + 0x26) - (uint)*(ushort *)(iVar4 + 0x24);
    if (iVar3 < local_8) {
      local_8 = iVar3;
    }
    local_c = *(int *)(param_1 + 0x20) + 0x24;
  }
  if (param_3 == (undefined4 *)0x0) {
    param_3 = (undefined4 *)_m_get(0,2);
    if (param_3 == (undefined4 *)0x0) {
      return;
    }
    *(undefined2 *)(param_3 + 2) = 0x28;
    puVar5 = (undefined4 *)((int)param_3 + param_3[1]);
    for (iVar4 = 10; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar5 = *param_2;
      param_2 = param_2 + 1;
      puVar5 = puVar5 + 1;
    }
    param_2 = (undefined4 *)((int)param_3 + param_3[1]);
    param_6 = 0x10;
  }
  else {
    _m_freem(*param_3);
    *param_3 = 0;
    param_3[1] = (int)param_2 - (int)param_3;
    *(undefined2 *)(param_3 + 2) = 0x28;
    uVar1 = param_2[4];
    param_2[4] = param_2[3];
    param_2[3] = uVar1;
    uVar2 = *(undefined2 *)((int)param_2 + 0x16);
    *(undefined2 *)((int)param_2 + 0x16) = *(undefined2 *)(param_2 + 5);
    *(undefined2 *)(param_2 + 5) = uVar2;
  }
  param_2[1] = 0;
  *param_2 = 0;
  *(undefined1 *)(param_2 + 2) = 0;
  *(undefined2 *)((int)param_2 + 10) = 0x1400;
  param_2[6] = param_5 >> 0x18 | (param_5 & 0xff0000) >> 8 | (param_5 & 0xff00) << 8 |
               param_5 << 0x18;
  param_2[7] = param_4 >> 0x18 | (param_4 & 0xff0000) >> 8 | (param_4 & 0xff00) << 8 |
               param_4 << 0x18;
  *(undefined1 *)(param_2 + 8) = 0x50;
  *(undefined1 *)((int)param_2 + 0x21) = param_6;
  *(ushort *)((int)param_2 + 0x22) = (ushort)local_8 >> 8 | (ushort)local_8 << 8;
  *(undefined2 *)((int)param_2 + 0x26) = 0;
  uVar2 = _in_cksum(param_3,0x28);
  *(undefined2 *)(param_2 + 9) = uVar2;
  *(undefined2 *)((int)param_2 + 2) = 0x28;
  *(undefined1 *)(param_2 + 2) = _tcp_ttl;
  _ip_output(param_3,0,local_c,0,0);
  return;
}

