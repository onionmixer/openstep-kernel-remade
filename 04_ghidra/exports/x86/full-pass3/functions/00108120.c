/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00108120 */

int _setgroups(int param_1,gid_t *param_2)

{
  uint *puVar1;
  undefined4 uVar2;
  undefined1 uVar3;
  int iVar4;
  undefined2 *puVar5;
  undefined2 *puVar6;
  undefined2 local_44 [32];
  
  puVar1 = *(uint **)(DAT_001e875c + 0x12);
  iVar4 = _suser();
  puVar6 = DAT_001e875c;
  puVar5 = (undefined2 *)0x0;
  if (iVar4 != 0) {
    if (*puVar1 < 0x11) {
      iVar4 = _crdup(*(undefined4 *)(_active_u + 0x1c));
      uVar3 = _copyin(puVar1[1],local_44,*puVar1 * 4);
      *(undefined1 *)(DAT_001e875c + 0x34) = uVar3;
      if (*(char *)(DAT_001e875c + 0x34) == '\0') {
        puVar5 = (undefined2 *)(iVar4 + 10);
        puVar6 = local_44;
        if (local_44 < local_44 + *puVar1 * 2) {
          do {
            *puVar5 = *puVar6;
            puVar6 = puVar6 + 2;
            puVar5 = puVar5 + 1;
          } while (puVar6 < local_44 + *puVar1 * 2);
        }
        uVar2 = *(undefined4 *)(_active_u + 0x1c);
        *(int *)(_active_u + 0x1c) = iVar4;
        _crfree(uVar2);
        iVar4 = *(int *)(_active_u + 0x1c);
        for (puVar6 = (undefined2 *)(iVar4 + 10 + *puVar1 * 2);
            puVar5 = (undefined2 *)(iVar4 + 0x2a), puVar6 < puVar5; puVar6 = puVar6 + 1) {
          *puVar6 = 0xffff;
          iVar4 = *(int *)(_active_u + 0x1c);
        }
      }
      else {
        puVar5 = (undefined2 *)_crfree(iVar4);
      }
    }
    else {
      *(undefined1 *)(DAT_001e875c + 0x34) = 0x16;
      puVar5 = puVar6;
    }
  }
  return (int)puVar5;
}

