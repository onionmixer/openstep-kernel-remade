
void _icmp_send(byte *param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined2 uVar4;
  sword sVar5;
  
  uVar2 = (uint)param_1 & 0xffffff80;
  uVar3 = *param_1 & 0xf;
  *(uint *)(uVar2 + 4) = uVar3 * 4 + *(int *)(uVar2 + 4);
  sVar5 = (sword)(uVar3 * 4);
  *(sword *)(uVar2 + 8) = *(sword *)(uVar2 + 8) - sVar5;
  iVar1 = uVar2 + *(int *)(uVar2 + 4);
  *(undefined2 *)(iVar1 + 2) = 0;
  uVar4 = _in_cksum(uVar2,(int)*(sword *)(param_1 + 2) + uVar3 * -4);
  *(undefined2 *)(iVar1 + 2) = uVar4;
  *(uint *)(uVar2 + 4) = *(int *)(uVar2 + 4) + uVar3 * -4;
  *(sword *)(uVar2 + 8) = sVar5 + *(sword *)(uVar2 + 8);
  _ip_output(uVar2,param_2,0,0,0);
  return;
}

