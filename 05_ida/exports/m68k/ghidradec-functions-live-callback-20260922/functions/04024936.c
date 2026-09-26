
undefined4 _tcp_close(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  
  puVar2 = (undefined4 *)param_1[8];
  uVar3 = puVar2[6];
  puVar1 = (undefined4 *)*param_1;
  while (param_1 != puVar1) {
    puVar1 = (undefined4 *)*puVar1;
    piVar4 = (int *)puVar1[1];
    iVar5 = piVar4[5];
    *(int *)(*piVar4 + 4) = piVar4[1];
    *(int *)piVar4[1] = *piVar4;
    _m_freem(iVar5);
  }
  if (param_1[7] != 0) {
    _m_free(param_1[7] & 0xffffff80);
  }
  _kfree(param_1,0x6c);
  puVar2[7] = 0;
  _soisdisconnected(uVar3);
  if (puVar2 == _tcp_last_inpcb) {
    _tcp_last_inpcb = &_tcb;
  }
  _in_pcbdetach(puVar2);
  dword_40BBD40 = dword_40BBD40 + 1;
  return 0;
}

