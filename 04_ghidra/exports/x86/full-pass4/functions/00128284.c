/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00128284 */

undefined4 _rip_output(undefined4 *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  short sVar4;
  undefined4 uVar5;
  int iVar6;
  
  sVar4 = 0;
  iVar1 = *(int *)(param_2 + 8);
  if ((*(short *)(iVar1 + 0x2e) == 0xff) || (puVar3 = param_1, *(short *)(iVar1 + 0x2e) == 2)) {
    iVar6 = *(int *)((int)param_1 + param_1[1] + 0xc);
    iVar2 = _in_ifaddr;
    if (iVar6 != 0) {
      for (; (iVar2 != 0 && (*(int *)(iVar2 + 4) != iVar6)); iVar2 = *(int *)(iVar2 + 0x40)) {
      }
      iVar6 = 0;
      if (iVar2 != 0) {
        iVar6 = *(int *)(iVar2 + 0x20);
      }
      if (iVar6 == 0) {
        uVar5 = 0x31;
        goto LAB_001283a4;
      }
    }
    *(undefined4 *)((int)param_1 + param_1[1] + 0x10) = *(undefined4 *)(iVar1 + 0x10);
  }
  else {
    for (; puVar3 != (undefined4 *)0x0; puVar3 = (undefined4 *)*puVar3) {
      sVar4 = sVar4 + *(short *)(puVar3 + 2);
    }
    puVar3 = (undefined4 *)_m_get(0,2);
    if (puVar3 == (undefined4 *)0x0) {
      uVar5 = 0x37;
LAB_001283a4:
      _m_freem(param_1);
      return uVar5;
    }
    puVar3[1] = 0x68;
    *(undefined2 *)(puVar3 + 2) = 0x14;
    *puVar3 = param_1;
    iVar6 = puVar3[1];
    *(undefined1 *)((int)puVar3 + iVar6 + 1) = 0;
    *(undefined2 *)((int)puVar3 + iVar6 + 6) = 0;
    *(undefined1 *)((int)puVar3 + iVar6 + 9) = *(undefined1 *)(iVar1 + 0x2e);
    *(short *)((int)puVar3 + iVar6 + 2) = sVar4 + 0x14;
    param_1 = puVar3;
    if ((*(byte *)(iVar1 + 0x4c) & 1) == 0) {
      *(undefined4 *)((int)puVar3 + iVar6 + 0xc) = 0;
    }
    else {
      if (*(short *)(iVar1 + 0x1c) != 2) {
        uVar5 = 0x2f;
        goto LAB_001283a4;
      }
      *(undefined4 *)((int)puVar3 + iVar6 + 0xc) = *(undefined4 *)(iVar1 + 0x20);
    }
    *(undefined4 *)((int)puVar3 + iVar6 + 0x10) = *(undefined4 *)(iVar1 + 0x10);
    *(undefined1 *)((int)puVar3 + iVar6 + 8) = 0xff;
  }
  uVar5 = _ip_output(param_1,*(undefined4 *)(iVar1 + 0x34),iVar1 + 0x38,
                     *(ushort *)(param_2 + 2) & 0x10 | 0x22,*(undefined4 *)(iVar1 + 0x50));
  return uVar5;
}

