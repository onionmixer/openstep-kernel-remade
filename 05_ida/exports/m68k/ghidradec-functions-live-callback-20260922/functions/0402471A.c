
void _tcp_respond(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 param_4,
                 undefined4 param_5,undefined param_6)

{
  undefined4 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  
  uVar3 = 0;
  iVar6 = 0;
  if (param_1 != 0) {
    iVar6 = *(int *)(*(int *)(param_1 + 0x20) + 0x18);
    iVar4 = (uint)*(word *)(iVar6 + 0x28) - (uint)*(word *)(iVar6 + 0x26);
    iVar6 = (uint)*(word *)(iVar6 + 0x24) - (uint)*(word *)(iVar6 + 0x22);
    if (iVar4 < iVar6) {
      iVar6 = iVar4;
    }
    uVar3 = (undefined2)iVar6;
    iVar6 = *(int *)(param_1 + 0x20) + 0x20;
  }
  if (param_3 == (undefined4 *)0x0) {
    param_3 = (undefined4 *)_m_get(0,2);
    if (param_3 == (undefined4 *)0x0) {
      return;
    }
    *(undefined2 *)(param_3 + 2) = 0x28;
    puVar5 = (undefined4 *)(param_3[1] + (int)param_3);
    *puVar5 = *param_2;
    puVar5[1] = param_2[1];
    puVar5[2] = param_2[2];
    puVar5[3] = param_2[3];
    puVar5[4] = param_2[4];
    puVar5[5] = param_2[5];
    puVar5[6] = param_2[6];
    puVar5[7] = param_2[7];
    puVar5[8] = param_2[8];
    puVar5[9] = param_2[9];
    param_2 = (undefined4 *)(param_3[1] + (int)param_3);
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
  *(undefined *)(param_2 + 2) = 0;
  *(undefined2 *)((int)param_2 + 10) = 0x14;
  param_2[6] = param_5;
  param_2[7] = param_4;
  *(undefined *)(param_2 + 8) = 0x50;
  *(undefined *)((int)param_2 + 0x21) = param_6;
  *(undefined2 *)((int)param_2 + 0x22) = uVar3;
  *(undefined2 *)((int)param_2 + 0x26) = 0;
  uVar3 = _in_cksum(param_3,0x28);
  *(undefined2 *)(param_2 + 9) = uVar3;
  *(undefined2 *)((int)param_2 + 2) = 0x28;
  *(undefined *)(param_2 + 2) = byte_40AEB6F;
  _ip_output(param_3,0,iVar6,0,0);
  return;
}

