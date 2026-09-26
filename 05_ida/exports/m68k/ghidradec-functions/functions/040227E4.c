
void _ip_mloopback(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined2 uVar2;
  byte *pbVar3;
  
  iVar1 = _m_copy(param_2,0,1000000000);
  if (iVar1 != 0) {
    pbVar3 = (byte *)(*(int *)(iVar1 + 4) + iVar1);
    pbVar3[10] = 0;
    pbVar3[0xb] = 0;
    uVar2 = _in_cksum(iVar1,(*pbVar3 & 0xf) << 2);
    *(undefined2 *)(pbVar3 + 10) = uVar2;
    _looutput(param_1,iVar1,param_3);
  }
  return;
}
