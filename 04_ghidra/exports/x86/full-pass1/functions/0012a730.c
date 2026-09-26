/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012a730 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _tcp_close(undefined4 *param_1)

{
  undefined *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  
  puVar1 = (undefined *)param_1[8];
  uVar2 = *(undefined4 *)(puVar1 + 0x1c);
  puVar3 = (undefined4 *)*param_1;
  while (puVar3 != param_1) {
    puVar3 = (undefined4 *)*puVar3;
    piVar4 = (int *)puVar3[1];
    iVar5 = piVar4[5];
    *(int *)(*piVar4 + 4) = piVar4[1];
    *(int *)piVar4[1] = *piVar4;
    _m_freem(iVar5);
  }
  if (param_1[7] != 0) {
    _m_free(param_1[7] & 0xffffff80);
  }
  _kfree(param_1,0x6c);
  *(undefined4 *)(puVar1 + 0x20) = 0;
  _soisdisconnected(uVar2);
  if (_tcp_last_inpcb == puVar1) {
    _tcp_last_inpcb = (undefined *)&_tcb;
  }
  _in_pcbdetach(puVar1);
  _DAT_001eed84 = _DAT_001eed84 + 1;
  return 0;
}

