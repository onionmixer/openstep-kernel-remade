
void _sendsig(undefined4 param_1,int param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  int iStack_18;
  undefined4 uStack_14;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  
  puVar1 = (undefined4 *)*dword_40B57D4;
  iVar4 = *(int *)((int)_active_u + 0x142);
  if ((iVar4 == 0) && (*(int *)((int)_active_u + 0x132) << 0x20 - param_2 < 0)) {
    iVar2 = *(int *)((int)_active_u + 0x13e);
    *(undefined4 *)((int)_active_u + 0x142) = 1;
  }
  else {
    iVar2 = puVar1[0xf];
  }
  iStack_10 = param_2;
  if ((param_2 == 4) || (param_2 - 7U < 2)) {
    iStack_c = dword_40B57D4[0x1b];
    dword_40B57D4[0x1b] = 0;
  }
  else {
    iStack_c = 0;
  }
  iStack_8 = iVar2 + -0x18;
  iVar3 = _copyoutmsg(&iStack_10,iVar2 + -0x24,0xc);
  if (iVar3 == 0) {
    uStack_24 = param_3;
    uStack_20 = puVar1[0xf];
    uStack_1c = *(undefined4 *)((int)puVar1 + 0x42);
    iStack_18 = (int)*(sword *)(puVar1 + 0x10);
    uStack_14 = *puVar1;
    iStack_28 = iVar4;
    iVar4 = _copyoutmsg(&iStack_28,iVar2 + -0x18,0x18);
    if (iVar4 == 0) {
      puVar1[0xf] = iVar2 + -0x24;
      *(undefined4 *)((int)puVar1 + 0x42) = param_1;
      return;
    }
  }
  *(undefined4 *)((int)_active_u + 0x3a) = 0;
  *(uint *)(*_active_u + 0x20) = *(uint *)(*_active_u + 0x20) & 0xfffffff7;
  *(uint *)(*_active_u + 0x24) = *(uint *)(*_active_u + 0x24) & 0xfffffff7;
  *(uint *)(*_active_u + 0x1c) = *(uint *)(*_active_u + 0x1c) & 0xfffffff7;
  _psignal(*_active_u,4);
  return;
}
