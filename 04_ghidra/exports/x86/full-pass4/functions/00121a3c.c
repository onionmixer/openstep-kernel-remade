/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00121a3c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _rtalloc(int *param_1)

{
  code *pcVar1;
  undefined4 *puVar2;
  bool bVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  uint *puVar7;
  int *piVar8;
  undefined *local_24;
  uint local_10;
  uint local_c;
  uint local_8;
  
  piVar8 = param_1 + 1;
  uVar6 = (uint)*(ushort *)(param_1 + 1);
  iVar5 = *param_1;
  if ((((iVar5 == 0) || (*(int *)(iVar5 + 0x2c) == 0)) || ((*(byte *)(iVar5 + 0x24) & 1) == 0)) &&
     (uVar6 < 0x11)) {
    (*(code *)(&_afswitch)[uVar6 * 2])(piVar8,&local_c);
    pcVar1 = (code *)(&PTR__null_netmatch_001db794)[uVar6 * 2];
    local_10 = local_c;
    local_24 = &_rthost;
    bVar3 = true;
    uVar4 = _splnet();
LAB_00121ab7:
    for (puVar2 = *(undefined4 **)(local_24 + (local_10 & 7) * 4); puVar2 != (undefined4 *)0x0;
        puVar2 = (undefined4 *)*puVar2) {
      puVar7 = (uint *)((int)puVar2 + puVar2[1]);
      if (((*puVar7 == local_10) && ((puVar7[9] & 1) != 0)) &&
         ((*(byte *)(puVar7[0xb] + 0xc) & 1) != 0)) {
        if (bVar3) {
          iVar5 = _bcmp(puVar7 + 1,piVar8,0x10);
          if (iVar5 == 0) goto LAB_00121b1b;
        }
        else if ((uVar6 == (ushort)puVar7[1]) && (iVar5 = (*pcVar1)(puVar7 + 1,piVar8), iVar5 != 0))
        {
LAB_00121b1b:
          *(short *)((int)puVar7 + 0x26) = *(short *)((int)puVar7 + 0x26) + 1;
          _splx(uVar4);
          if (piVar8 == (int *)&_wildcard) {
            _DAT_001e98b8 = _DAT_001e98b8 + 1;
          }
          *param_1 = (int)puVar7;
          return;
        }
      }
    }
    if (bVar3) {
      bVar3 = false;
      local_24 = &_rtnet;
      local_10 = local_8;
      goto LAB_00121ab7;
    }
    if (piVar8 != (int *)&_wildcard) {
      piVar8 = (int *)&_wildcard;
      local_10 = 0;
      goto LAB_00121ab7;
    }
    _splx(uVar4);
    _DAT_001e98b6 = _DAT_001e98b6 + 1;
  }
  return;
}

