/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00137690 */

undefined4 _svckudp_send(undefined4 *param_1,uint *param_2)

{
  uint *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined2 uVar4;
  undefined4 uVar5;
  int *piVar6;
  boolean_t bVar7;
  int iVar8;
  undefined4 local_8;
  
  puVar1 = (uint *)param_1[0xc];
  local_8 = 0;
  uVar5 = _splimp();
  while ((*puVar1 & 1) != 0) {
    *puVar1 = *puVar1 | 2;
    _sleep((uint)puVar1);
  }
  *(byte *)puVar1 = (byte)*puVar1 | 1;
  _splx(uVar5);
  piVar6 = (int *)_mclgetx(FUN_00137994,puVar1,param_1[0xb],0x2260,1);
  if (piVar6 == (int *)0x0) {
    uVar2 = *puVar1;
    *puVar1 = uVar2 & 0xfffffffe;
    if ((uVar2 & 2) != 0) {
      *puVar1 = uVar2 & 0xfffffffc;
      _wakeup(puVar1);
    }
  }
  else {
    _xdrmbuf_init(puVar1 + 9,piVar6,0);
    *param_2 = puVar1[1];
    bVar7 = _xdr_replymsg();
    if (bVar7 == 0) {
      _printf(s_svckudp_send__xdr_replymsg_faile_001dd1f0);
      _m_freem(piVar6);
    }
    else {
      uVar4 = (**(code **)(puVar1[10] + 0x10))(puVar1 + 9);
      if (*piVar6 == 0) {
        *(undefined2 *)(piVar6 + 2) = uVar4;
      }
      iVar8 = _ku_sendto_mbuf(*param_1,piVar6,param_1 + 4);
      if (iVar8 == 0) {
        local_8 = 1;
      }
    }
    puVar3 = (undefined4 *)puVar1[0xb];
    if (puVar3 != (undefined4 *)0x0) {
      (*(code *)*puVar3)(puVar3);
    }
  }
  return local_8;
}

