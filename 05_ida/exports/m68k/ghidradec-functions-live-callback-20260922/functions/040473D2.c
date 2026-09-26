
undefined4 _ast_check(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  byte *pbVar5;
  byte bVar6;
  int iVar7;
  word wVar8;
  sword sVar10;
  int *piVar11;
  bool bVar12;
  bool bVar13;
  bool bVar14;
  bool bVar15;
  bool bVar16;
  uint uVar9;
  
  iVar4 = _processor_ptr;
  iVar7 = _active_threads;
  uVar9 = *(uint *)(_processor_ptr + 0x110);
  bVar15 = 1 < uVar9;
  if (uVar9 != 1) {
    if ((int)uVar9 < 2) {
      bVar14 = false;
      bVar12 = (int)uVar9 < 0;
      bVar13 = true;
      bVar16 = false;
      if (uVar9 != 0) {
loc_4047590:
                    /* WARNING: Subroutine does not return */
        _panic(aAstCheckBadPro);
      }
    }
    else {
      bVar15 = 3 < uVar9;
      bVar14 = SBORROW4(3,uVar9);
      bVar12 = (int)(3 - uVar9) < 0;
      bVar13 = uVar9 == 3;
      bVar16 = bVar15;
      if (3 < (int)uVar9) goto loc_4047590;
    }
    goto loc_404759C;
  }
  iVar1 = *_active_u;
  if ((iVar1 != 0) &&
     (((*(char *)(iVar1 + 0x17) != '\0' ||
       (((_active_threads != 0 &&
         (uVar9 = *(uint *)(*(int *)(_active_threads + 0x80) + 0x72) | *(uint *)(iVar1 + 0x18),
         uVar9 != 0)) &&
        (((*(byte *)(iVar1 + 0x2b) & 0x10) != 0 ||
         ((uVar9 & ~(*(uint *)(iVar1 + 0x1c) | *(uint *)(iVar1 + 0x20))) != 0)))))) &&
      (_need_ast = _need_ast | 0x20, _need_ast != 0)))) {
    pbVar5 = (byte *)(*(int *)(_active_threads + 0x24) + 0x54);
    *pbVar5 = *pbVar5 | 0x10;
  }
  _need_ast = *(uint *)(iVar7 + 0x174) | _need_ast;
  if (_need_ast != 0) {
    pbVar5 = (byte *)(*(int *)(_active_threads + 0x24) + 0x54);
    *pbVar5 = *pbVar5 | 0x10;
  }
  bVar12 = (int)_need_ast < 0;
  bVar13 = _need_ast == 0;
  bVar14 = false;
  uVar9 = _need_ast;
  bVar16 = false;
  if (!bVar13) goto loc_404759C;
  if (((*(byte *)(iVar7 + 0x4b) & 2) == 0) && (*(int *)(iVar4 + 0x104) < 1)) {
    iVar1 = *(int *)(iVar4 + 0x128);
    if ((*(byte *)(iVar1 + 0x15b) & 2) == 0) {
      bVar14 = false;
      bVar12 = *(int *)(iVar4 + 0x120) < 0;
      bVar13 = *(int *)(iVar4 + 0x120) == 0;
      bVar16 = false;
      if (!bVar13) goto loc_404759C;
      bVar14 = false;
      bVar12 = *(int *)(iVar1 + 0x104) < 0;
      iVar4 = *(int *)(iVar1 + 0x104);
      bVar13 = iVar4 == 0;
      bVar16 = false;
      if (iVar4 < 1) goto loc_404759C;
      uVar9 = *(uint *)(iVar1 + 0x100);
      piVar11 = (int *)(iVar1 + uVar9 * 8);
      if (piVar11 == (int *)*piVar11) {
        piVar11 = (int *)(iVar1 + uVar9 * 8);
        if (-1 < (int)uVar9) {
          do {
            if (piVar11 != (int *)*piVar11) break;
            piVar11 = piVar11 + -2;
            wVar8 = (word)(uVar9 >> 0x10);
            sVar10 = (sword)uVar9 + -1;
            uVar9 = CONCAT22(wVar8,sVar10);
          } while ((sVar10 != -1) || (uVar9 = (uint)wVar8 * 0x10000 - 1, wVar8 != 0));
        }
        *(uint *)(iVar1 + 0x100) = uVar9;
      }
      uVar2 = *(uint *)(iVar1 + 0x100);
      uVar3 = *(uint *)(iVar7 + 0x54);
      bVar15 = uVar2 < uVar3;
      bVar14 = SBORROW4(uVar2,uVar3);
      bVar12 = (int)(uVar2 - uVar3) < 0;
      bVar13 = uVar2 == uVar3;
      bVar16 = bVar15;
      if ((int)uVar2 < (int)uVar3) goto loc_404759C;
    }
    else {
      uVar2 = *(uint *)(iVar1 + 0x100);
      uVar3 = *(uint *)(iVar7 + 0x54);
      uVar9 = *(uint *)(iVar7 + 0x5c);
      if (((uVar9 == 2) || (2 < (int)uVar9)) || (uVar9 != 1)) {
        if (((*(int *)(iVar1 + 0x104) == 0) || (bVar15 = uVar3 < uVar2, (int)uVar2 < (int)uVar3)) ||
           (((int)uVar2 <= (int)uVar3 && (*(int *)(iVar4 + 0x120) != 0)))) goto loc_4047512;
      }
      else if (((*(int *)(iVar4 + 0x120) != 0) || (*(int *)(iVar1 + 0x104) < 1)) ||
              (bVar15 = uVar3 < uVar2, (int)uVar2 < (int)uVar3)) {
loc_4047512:
        uVar2 = *(uint *)(iVar7 + 0x5c);
        bVar15 = 2 < uVar2;
        bVar14 = SBORROW4(2,uVar2);
        bVar12 = (int)(2 - uVar2) < 0;
        bVar13 = false;
        bVar16 = bVar15;
        if (uVar2 == 2) {
          *(undefined4 *)(iVar4 + 0x120) = 1;
          bVar12 = false;
          bVar13 = false;
          bVar14 = false;
          bVar16 = false;
        }
        goto loc_404759C;
      }
    }
  }
  _need_ast = _need_ast | 4;
  uVar9 = _need_ast;
  bVar14 = false;
  bVar12 = (int)_need_ast < 0;
  bVar13 = _need_ast == 0;
  bVar16 = false;
  if (!bVar13) {
    pbVar5 = (byte *)(*(int *)(_active_threads + 0x24) + 0x54);
    bVar6 = *pbVar5;
    bVar13 = (bVar6 & 0x10) == 0;
    *pbVar5 = bVar6 | 0x10;
  }
loc_404759C:
  return CONCAT22((sword)(uVar9 >> 0x10),
                  (word)(byte)(bVar15 << 4 | bVar12 << 3 | bVar13 << 2 | bVar14 << 1 | bVar16));
}

