/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017cabc */

undefined4 _vnode_pager_findpage(undefined4 *param_1,uint *param_2)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int local_c;
  
  puVar4 = param_1;
  if (param_1 == (undefined4 *)0x0) {
    if ((undefined4 **)DAT_001e7288 == &DAT_001e7288) {
      return 5;
    }
    param_1 = DAT_001e7288;
    puVar4 = DAT_001e7288;
  }
  do {
    _lock_write(puVar4 + 0xd);
    if (puVar4[6] == 0) {
      _lock_done(puVar4 + 0xd);
      iVar2 = -1;
    }
    else {
      iVar2 = 0;
      local_c = puVar4[9];
      if (local_c < 0) {
        local_c = local_c + 7;
      }
      local_c = local_c >> 3;
      while( true ) {
        iVar3 = puVar4[5] + 7;
        if (iVar3 < 0) {
          iVar3 = puVar4[5] + 0xe;
        }
        if (iVar3 >> 3 <= local_c) goto LAB_0017cb98;
        if (*(char *)(local_c + puVar4[4]) != -1) break;
        local_c = local_c + 1;
      }
      iVar2 = 0;
      do {
        iVar3 = iVar2;
        if (iVar2 < 0) {
          iVar3 = iVar2 + 7;
        }
      } while ((((uint)(int)*(char *)((iVar3 >> 3) + local_c + puVar4[4]) >>
                 (iVar2 + (iVar3 >> 3) * -8 & 0x1fU) & 1) != 0) && (iVar2 = iVar2 + 1, iVar2 < 8));
LAB_0017cb98:
      iVar2 = iVar2 + local_c * 8;
      if ((int)puVar4[5] <= iVar2) {
                    /* WARNING: Subroutine does not return */
        _panic(s_vnode_pager_allocpage_001e0e5c);
      }
      if ((int)puVar4[8] < iVar2) {
        puVar4[8] = iVar2;
      }
      iVar3 = iVar2;
      if (iVar2 < 0) {
        iVar3 = iVar2 + 7;
      }
      pbVar1 = (byte *)((iVar3 >> 3) + puVar4[4]);
      *pbVar1 = *pbVar1 | (byte)(1 << ((char)iVar2 + (char)(iVar3 >> 3) * -8 & 0x1fU));
      puVar4[6] = puVar4[6] + -1;
      puVar4[9] = iVar2;
      _lock_done(puVar4 + 0xd);
    }
    if (iVar2 != -1) {
      *(byte *)param_2 = *(byte *)(puVar4 + 0xc);
      *param_2 = (uint)(byte)*param_2 | iVar2 << 8;
      return 0;
    }
    puVar5 = DAT_001e7288;
    if ((undefined4 **)puVar4 != &DAT_001e7288) {
      puVar5 = (undefined4 *)*puVar4;
    }
    puVar4 = puVar5;
    if (param_1 == puVar5) {
      return 5;
    }
  } while( true );
}

