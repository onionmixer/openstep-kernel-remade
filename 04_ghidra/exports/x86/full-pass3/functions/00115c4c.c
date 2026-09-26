/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00115c4c */

void _sorflush(int param_1)

{
  ushort uVar1;
  int iVar2;
  code *pcVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 local_1c [6];
  
  iVar2 = *(int *)(param_1 + 0xc);
  if ((*(byte *)(param_1 + 0x38) & 1) != 0) {
    do {
      *(byte *)(param_1 + 0x38) = *(byte *)(param_1 + 0x38) | 2;
      _sleep(param_1 + 0x38);
    } while ((*(byte *)(param_1 + 0x38) & 1) != 0);
  }
  *(byte *)(param_1 + 0x38) = *(byte *)(param_1 + 0x38) | 1;
  uVar4 = _splimp();
  _socantrcvmore(param_1);
  uVar1 = *(ushort *)(param_1 + 0x38);
  *(ushort *)(param_1 + 0x38) = uVar1 & 0xfffe;
  if ((uVar1 & 2) != 0) {
    *(ushort *)(param_1 + 0x38) = uVar1 & 0xfffc;
    _wakeup(param_1 + 0x38);
  }
  puVar6 = (undefined4 *)(param_1 + 0x24);
  puVar7 = local_1c;
  for (iVar5 = 6; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar7 = *puVar6;
    puVar6 = puVar6 + 1;
    puVar7 = puVar7 + 1;
  }
  _bzero((undefined4 *)(param_1 + 0x24),0x18);
  _splx(uVar4);
  if (((*(byte *)(iVar2 + 10) & 0x10) != 0) &&
     (pcVar3 = *(code **)(*(int *)(iVar2 + 4) + 0x10), pcVar3 != (code *)0x0)) {
    (*pcVar3)(local_1c[3]);
  }
  _sbrelease(local_1c);
  return;
}

