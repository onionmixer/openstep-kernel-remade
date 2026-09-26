
undefined4 *
_clntkudp_create(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  undefined *puVar7;
  undefined auStack_3c [4];
  int iStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  *(undefined4 *)(_active_threads + 0x180) = 1;
  iVar3 = _kalloc(0x78);
  _bzero(iVar3,0x78);
  puVar1 = (undefined4 *)(iVar3 + 4);
  if (_clntkudpxid == 0) {
    _getthetime(auStack_3c);
    _clntkudpxid = iStack_38;
  }
  *(undefined **)(iVar3 + 8) = _udp_ops;
  *(int *)(iVar3 + 0xc) = iVar3;
  uVar4 = _authkern_create();
  *puVar1 = uVar4;
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = 2;
  uStack_28 = param_2;
  uStack_24 = param_3;
  _clntkudp_init(puVar1,param_1,param_4,param_5);
  uVar4 = _kalloc(0x2260);
  *(undefined4 *)(iVar3 + 0x68) = uVar4;
  iVar5 = _mclgetx(sub_402DC58,0,uVar4,0x2260,1);
  if (iVar5 != 0) {
    iVar2 = iVar3 + 0x34;
    _xdrmbuf_init(iVar2,iVar5,0);
    iVar6 = _xdr_callhdr(iVar2,&uStack_34);
    if (iVar6 == 0) {
      _printf(aClntkudpCreate);
      _m_freem(iVar5);
    }
    else {
      uVar4 = (**(code **)(*(int *)(iVar3 + 0x38) + 0x10))(iVar2);
      *(undefined4 *)(iVar3 + 100) = uVar4;
      _m_free(iVar5);
      iVar5 = _socreate(2,(undefined4 *)(iVar3 + 0x14),2,0x11);
      if (iVar5 == 0) {
        iVar5 = sub_402E54E(*(undefined4 *)(iVar3 + 0x14));
        if (iVar5 == 0) {
          *(undefined4 *)(_active_threads + 0x180) = 0;
          return puVar1;
        }
        puVar7 = aClntkudpCreate_1;
      }
      else {
        puVar7 = aClntkudpCreate_0;
      }
      _printf(puVar7,iVar5);
    }
  }
  *(undefined4 *)(_active_threads + 0x180) = 0;
  _kfree(*(undefined4 *)(iVar3 + 0x68),0x2260);
  _crfree(*(undefined4 *)(iVar3 + 0x74));
  _kfree(iVar3,0x78);
  return (undefined4 *)0x0;
}

