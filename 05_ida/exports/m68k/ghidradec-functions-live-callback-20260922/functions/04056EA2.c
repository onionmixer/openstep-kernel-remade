
void _kern_serv_log(int *param_1,int param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  
  iVar1 = *param_1;
  if ((param_2 <= *(int *)(iVar1 + 0x30)) && (*(int *)(iVar1 + 0x24) != 0)) {
    puVar2 = *(undefined4 **)(iVar1 + 0x28);
    *(int *)(iVar1 + 0x28) = *(int *)(iVar1 + 0x28) + 0x20;
    if (*(int *)(iVar1 + 0x28) == *(int *)(iVar1 + 0x2c)) {
      *(int *)(iVar1 + 0x28) = *(int *)(iVar1 + 0x28) + -0x20;
    }
    else {
      *puVar2 = param_3;
      puVar2[1] = param_4;
      puVar2[2] = param_5;
      puVar2[3] = param_6;
      puVar2[4] = param_7;
      puVar2[5] = param_8;
      uVar4 = *_event_middle;
      uVar3 = CONCAT31((uint3)*_eventc_m | (uint3)(((uint)*_eventc_h << 0x10) >> 8),*_eventc_l) &
              0xfffff;
      if (((uVar3 ^ uVar4) & 0x80000) != 0) {
        uVar4 = uVar4 + 0x80000;
      }
      puVar2[6] = uVar3 | uVar4;
      puVar2[7] = param_2;
      if (*(int *)(iVar1 + 0x18) != 0) {
        _kern_serv_callout(param_1,sub_4056F98,iVar1);
      }
    }
  }
  return;
}

