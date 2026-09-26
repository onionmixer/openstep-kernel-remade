/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017cbad */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_0017cbad(void)

{
  byte *pbVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int unaff_EBX;
  int unaff_EBP;
  undefined4 *unaff_ESI;
  undefined4 *puVar6;
  
  do {
    if ((int)unaff_ESI[8] < unaff_EBX) {
      unaff_ESI[8] = unaff_EBX;
    }
    iVar3 = unaff_EBX;
    if (unaff_EBX < 0) {
      iVar3 = unaff_EBX + 7;
    }
    pbVar1 = (byte *)((iVar3 >> 3) + unaff_ESI[4]);
    *pbVar1 = *pbVar1 | (byte)(1 << ((char)unaff_EBX + (char)(iVar3 >> 3) * -8 & 0x1fU));
    unaff_ESI[6] = unaff_ESI[6] + -1;
    unaff_ESI[9] = unaff_EBX;
    _lock_done();
    puVar6 = unaff_ESI;
    while( true ) {
      if (unaff_EBX != -1) {
        puVar2 = *(uint **)(unaff_EBP + 0xc);
        *(byte *)puVar2 = *(byte *)(puVar6 + 0xc);
        *puVar2 = (uint)(byte)*puVar2 | unaff_EBX << 8;
        return 0;
      }
      unaff_ESI = DAT_001e7288;
      if ((undefined4 **)puVar6 != &DAT_001e7288) {
        unaff_ESI = (undefined4 *)*puVar6;
      }
      if (*(undefined4 **)(unaff_EBP + 8) == unaff_ESI) {
        return 5;
      }
      _lock_write();
      if (unaff_ESI[6] != 0) break;
      _lock_done();
      unaff_EBX = -1;
      puVar6 = unaff_ESI;
    }
    iVar5 = 0;
    iVar3 = unaff_ESI[9];
    if (iVar3 < 0) {
      iVar3 = iVar3 + 7;
    }
    *(int *)(unaff_EBP + -8) = iVar3 >> 3;
    iVar3 = unaff_ESI[5];
    while( true ) {
      iVar4 = iVar3 + 7;
      if (iVar4 < 0) {
        iVar4 = iVar3 + 0xe;
      }
      if (iVar4 >> 3 <= *(int *)(unaff_EBP + -8)) goto LAB_0017cb98;
      if (*(char *)(*(int *)(unaff_EBP + -8) + unaff_ESI[4]) != -1) break;
      *(int *)(unaff_EBP + -8) = *(int *)(unaff_EBP + -8) + 1;
    }
    iVar5 = 0;
    do {
      iVar3 = iVar5;
      if (iVar5 < 0) {
        iVar3 = iVar5 + 7;
      }
      *(int *)(unaff_EBP + -4) =
           (int)*(char *)((iVar3 >> 3) + *(int *)(unaff_EBP + -8) + unaff_ESI[4]);
    } while (((*(uint *)(unaff_EBP + -4) >> (iVar5 + (iVar3 >> 3) * -8 & 0x1fU) & 1) != 0) &&
            (iVar5 = iVar5 + 1, iVar5 < 8));
LAB_0017cb98:
    unaff_EBX = iVar5 + *(int *)(unaff_EBP + -8) * 8;
    if ((int)unaff_ESI[5] <= unaff_EBX) {
                    /* WARNING: Subroutine does not return */
      _panic(s_vnode_pager_allocpage_001e0e5c);
    }
  } while( true );
}

