
undefined4 _svckudp_send(undefined4 *param_1,uint *param_2)

{
  uint *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  undefined2 uVar5;
  undefined4 uVar6;
  
  puVar1 = *(uint **)((int)param_1 + 0x2e);
  uVar6 = 0;
  while ((*puVar1 & 1) != 0) {
    *puVar1 = *puVar1 | 2;
    _sleep(puVar1,0x17);
  }
  *puVar1 = *puVar1 | 1;
  piVar3 = (int *)_mclgetx(sub_402FAAA,puVar1,*(undefined4 *)((int)param_1 + 0x2a),0x2260,1);
  if (piVar3 == (int *)0x0) {
    sub_402FAAA(puVar1);
  }
  else {
    _xdrmbuf_init(puVar1 + 9,piVar3,0);
    *param_2 = puVar1[1];
    iVar4 = _xdr_replymsg(puVar1 + 9,param_2);
    if (iVar4 == 0) {
      _printf(aSvckudpSendXdr);
      _m_freem(piVar3);
    }
    else {
      uVar5 = (**(code **)(puVar1[10] + 0x10))(puVar1 + 9);
      if (*piVar3 == 0) {
        *(undefined2 *)(piVar3 + 2) = uVar5;
      }
      iVar4 = _ku_sendto_mbuf(*param_1,piVar3,(int)param_1 + 0xe);
      if (iVar4 == 0) {
        uVar6 = 1;
      }
    }
    puVar2 = (undefined4 *)puVar1[0xb];
    if (puVar2 != (undefined4 *)0x0) {
      (*(code *)*puVar2)(puVar2);
    }
  }
  return uVar6;
}
