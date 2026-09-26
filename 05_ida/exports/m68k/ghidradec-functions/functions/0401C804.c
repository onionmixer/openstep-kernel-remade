
void sub_401C804(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar1 = _if_type(param_2,a10mbEthernet);
  iVar2 = _strcmp(uVar1);
  if (iVar2 == 0) {
    uVar1 = _kalloc(0xe);
    uVar3 = _if_name(param_2);
    uVar4 = _if_unit(param_2);
    uVar1 = _if_attach(0,sub_401C67E,sub_401C310,sub_401C642,sub_401C41E,uVar3,uVar4,
                       aInternetProtoc_0,0x5dc,2,0x1000,uVar1);
    iVar2 = _if_private(uVar1);
    *(undefined4 *)(iVar2 + 10) = param_2;
    uVar1 = _if_private(uVar1);
    _if_control(param_2,&_IFCONTROL_GETADDR,uVar1);
    _printf(aIpProtocolEnab,uVar3,uVar4,a10mbEthernet);
  }
  return;
}
