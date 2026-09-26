
/* WARNING: Removing unreachable block (ram,0xf0046acc) */
/* WARNING: Removing unreachable block (ram,0xf0046bd0) */
/* WARNING: Removing unreachable block (ram,0xf0046b98) */
/* WARNING: Removing unreachable block (ram,0xf0046ab0) */
/* WARNING: Removing unreachable block (ram,0xf0046a80) */
/* WARNING: Removing unreachable block (ram,0xf0046a54) */
/* WARNING: Removing unreachable block (ram,0xf00469e4) */
/* WARNING: Removing unreachable block (ram,0xf0046eb0) */
/* WARNING: Removing unreachable block (ram,0xf0046e8c) */
/* WARNING: Removing unreachable block (ram,0xf0046e40) */
/* WARNING: Removing unreachable block (ram,0xf0046dd4) */
/* WARNING: Removing unreachable block (ram,0xf0046d64) */
/* WARNING: Removing unreachable block (ram,0xf0046d34) */
/* WARNING: Removing unreachable block (ram,0xf0046cc8) */
/* WARNING: Removing unreachable block (ram,0xf00468f0) */
/* WARNING: Removing unreachable block (ram,0xf0046ce8) */
/* WARNING: Removing unreachable block (ram,0xf0046d54) */
/* WARNING: Removing unreachable block (ram,0xf0046d84) */
/* WARNING: Removing unreachable block (ram,0xf0046e1c) */
/* WARNING: Removing unreachable block (ram,0xf0046e70) */
/* WARNING: Removing unreachable block (ram,0xf0046ea8) */
/* WARNING: Removing unreachable block (ram,0xf0046c1c) */
/* WARNING: Removing unreachable block (ram,0xf0046a04) */
/* WARNING: Removing unreachable block (ram,0xf0046a70) */
/* WARNING: Removing unreachable block (ram,0xf0046aa4) */
/* WARNING: Removing unreachable block (ram,0xf0046b58) */
/* WARNING: Removing unreachable block (ram,0xf0046bb4) */
/* WARNING: Removing unreachable block (ram,0xf0046bd8) */
/* WARNING: Removing unreachable block (ram,0xf0046ef4) */
/* WARNING: Removing unreachable block (ram,0xf00468d8) */

undefined8 sub_F00468C0(int param_1,int param_2,int param_3)

{
  sword sVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  word wVar7;
  uint uVar8;
  undefined4 unaff_l0;
  int *piVar9;
  undefined4 unaff_l1;
  int iVar10;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  int iVar11;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 *puVar12;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  iVar11 = 0;
  if (*(int *)(param_2 + 8) != 0) {
    _printf(aFifoRdwrNonZer);
  }
  puVar12 = *(undefined4 **)(param_1 + 0x30);
  while ((*(word *)(puVar12 + 0x10) & 1) != 0) {
    *(word *)(puVar12 + 0x10) = *(word *)(puVar12 + 0x10) | 0x10;
    _sleep(puVar12,10);
  }
  *(word *)(puVar12 + 0x10) = *(word *)(puVar12 + 0x10) | 1;
  if (param_3 == 1) {
    uVar4 = *(uint *)(param_2 + 0x14);
    if (dword_F010F398 < uVar4) {
      iVar11 = 0x16;
    }
    else {
      if (uVar4 == 0) {
        wVar7 = *(word *)(puVar12 + 0x10);
        goto loc_F0046ECC;
      }
      sVar1 = *(sword *)((int)puVar12 + 0x82);
loc_F0046950:
      if (sVar1 == 0) goto loc_F0046C0C;
      uVar8 = puVar12[0x1f];
      if (uVar4 + uVar8 <= _fifoinfo) {
        sVar1 = *(sword *)(puVar12 + 0x21);
loc_F0046A3C:
        if ((int)sVar1 - (int)*(sword *)((int)puVar12 + 0x86) != puVar12[0x1f]) {
          _printf(aFifoWritePtrMi);
        }
        if (dword_F010F39C < *(sword *)((int)puVar12 + 0x86)) {
          _printf(aFifoWriteRptrT);
        }
        iVar10 = (int)*(sword *)((int)puVar12 + 0x8a);
        iVar2 = iVar10;
        .umul(iVar10,dword_F010F39C);
        if (iVar2 < *(sword *)(puVar12 + 0x21)) {
          _printf(aFifoWriteWptrT,(int)*(sword *)(puVar12 + 0x21),iVar10);
          goto loc_F0046AAC;
        }
        sVar1 = *(sword *)((int)puVar12 + 0x8a);
        while( true ) {
          iVar2 = (int)sVar1;
          .umul(iVar2,dword_F010F39C);
          if (uVar4 <= (uint)(iVar2 - *(sword *)(puVar12 + 0x21))) break;
          puVar3 = puVar12;
          sub_F0047104();
          if (puVar3 == (undefined4 *)0x0) {
            uVar4 = *(uint *)(param_2 + 0x14);
            goto loc_F0046BFC;
          }
          *puVar3 = 0;
          if (puVar12[0x1a] == 0) {
            puVar12[0x1a] = puVar3;
          }
          else {
            *(undefined4 **)puVar12[0x1b] = puVar3;
          }
          puVar12[0x1b] = puVar3;
loc_F0046AAC:
          sVar1 = *(sword *)((int)puVar12 + 0x8a);
        }
        piVar9 = (int *)puVar12[0x1a];
        for (iVar2 = (int)*(sword *)(puVar12 + 0x21); dword_F010F39C <= iVar2;
            iVar2 = iVar2 - dword_F010F39C) {
          piVar9 = (int *)*piVar9;
        }
        for (; uVar4 != 0; uVar4 = uVar4 - uVar8) {
          uVar8 = uVar4;
          if ((uint)(dword_F010F39C - iVar2) < uVar4) {
            uVar8 = dword_F010F39C - iVar2;
          }
          iVar11 = (int)piVar9 + iVar2;
          _uiomove(iVar11,uVar8,1,param_2);
          if (iVar11 != 0) {
            wVar7 = *(word *)(puVar12 + 0x10);
            goto loc_F0046ECC;
          }
          iVar2 = 0;
          puVar12[0x1f] = puVar12[0x1f] + uVar8;
          *(sword *)(puVar12 + 0x21) = *(sword *)(puVar12 + 0x21) + (sword)uVar8;
          piVar9 = (int *)*piVar9;
        }
        _smark(puVar12,0x42);
        if ((*(word *)(puVar12 + 0x22) & 1) != 0) {
          *(word *)(puVar12 + 0x22) = *(word *)(puVar12 + 0x22) & 0xfffe;
          _wakeup((int)puVar12 + 0x82);
        }
        if (puVar12[0x1c] != 0) {
          _selwakeup(puVar12[0x1c],*(word *)(puVar12 + 0x22) & 4);
          _thread_deallocate(puVar12[0x1c]);
          puVar12[0x1c] = 0;
          *(word *)(puVar12 + 0x22) = *(word *)(puVar12 + 0x22) & 0xfffb;
        }
loc_F0046BFC:
        if (uVar4 == 0) {
          wVar7 = *(word *)(puVar12 + 0x10);
          goto loc_F0046ECC;
        }
        sVar1 = *(sword *)((int)puVar12 + 0x82);
        goto loc_F0046950;
      }
      if ((*(word *)(param_2 + 0x10) & 4) == 0) {
        if ((_fifoinfo < uVar4) && (uVar8 < _fifoinfo)) goto loc_F0046A2C;
        wVar7 = *(word *)(puVar12 + 0x10);
        *(word *)(puVar12 + 0x22) = *(word *)(puVar12 + 0x22) | 2;
        *(word *)(puVar12 + 0x10) = wVar7 & 0xfffe;
        if ((wVar7 & 0x10) != 0) {
          *(word *)(puVar12 + 0x10) = wVar7 & 0xffee;
          _wakeup(puVar12);
        }
        uVar5 = 0x1a;
        puVar3 = puVar12 + 0x20;
        while( true ) {
          _sleep(puVar3,uVar5);
          if ((*(word *)(puVar12 + 0x10) & 1) == 0) break;
          *(word *)(puVar12 + 0x10) = *(word *)(puVar12 + 0x10) | 0x10;
          uVar5 = 10;
          puVar3 = puVar12;
        }
        *(word *)(puVar12 + 0x10) = *(word *)(puVar12 + 0x10) | 1;
        uVar4 = *(uint *)(param_2 + 0x14);
        goto loc_F0046BFC;
      }
      if ((_fifoinfo < uVar4) && (uVar8 < _fifoinfo)) {
loc_F0046A2C:
        uVar4 = _fifoinfo - puVar12[0x1f];
        sVar1 = *(sword *)(puVar12 + 0x21);
        goto loc_F0046A3C;
      }
loc_F0046C80:
      iVar11 = 0x23;
      if ((*(uint *)(*_active_u + 0x14) & 0x4000) != 0) {
        iVar11 = 0xb;
      }
    }
  }
  else {
    uVar4 = *(uint *)(param_2 + 0x14);
    if (uVar4 == 0) {
      wVar7 = *(word *)(puVar12 + 0x10);
      goto loc_F0046ECC;
    }
    uVar8 = puVar12[0x1f];
    if (uVar8 == 0) {
      do {
        if (*(sword *)(puVar12 + 0x20) == 0) {
          wVar7 = *(word *)(puVar12 + 0x10);
          goto loc_F0046ECC;
        }
        if ((*(word *)(param_2 + 0x10) & 4) != 0) goto loc_F0046C80;
        wVar7 = *(word *)(puVar12 + 0x10);
        *(word *)(puVar12 + 0x22) = *(word *)(puVar12 + 0x22) | 1;
        *(word *)(puVar12 + 0x10) = wVar7 & 0xfffe;
        if ((wVar7 & 0x10) != 0) {
          *(word *)(puVar12 + 0x10) = wVar7 & 0xffee;
          _wakeup(puVar12);
        }
        uVar5 = 0x1a;
        puVar3 = (undefined4 *)((int)puVar12 + 0x82);
        while( true ) {
          _sleep(puVar3,uVar5);
          if ((*(word *)(puVar12 + 0x10) & 1) == 0) break;
          *(word *)(puVar12 + 0x10) = *(word *)(puVar12 + 0x10) | 0x10;
          uVar5 = 10;
          puVar3 = puVar12;
        }
        uVar8 = puVar12[0x1f];
        *(word *)(puVar12 + 0x10) = *(word *)(puVar12 + 0x10) | 1;
      } while (uVar8 == 0);
      sVar1 = *(sword *)(puVar12 + 0x21);
    }
    else {
      sVar1 = *(sword *)(puVar12 + 0x21);
    }
    if ((int)sVar1 - (int)*(sword *)((int)puVar12 + 0x86) != puVar12[0x1f]) {
      _printf(aFifoReadPtrMis);
    }
    if (dword_F010F39C < *(sword *)((int)puVar12 + 0x86)) {
      _printf(aFifoReadRptrTo);
    }
    iVar10 = (int)*(sword *)((int)puVar12 + 0x8a);
    iVar2 = iVar10;
    .umul(iVar10,dword_F010F39C);
    if (iVar2 < *(sword *)(puVar12 + 0x21)) {
      _printf(aFifoReadWptrTo,(int)*(sword *)(puVar12 + 0x21),iVar10);
    }
    iVar2 = (int)*(sword *)((int)puVar12 + 0x86);
    iVar10 = puVar12[0x1a];
    if (uVar8 < uVar4) {
      uVar4 = uVar8;
    }
    while (uVar4 != 0) {
      uVar8 = uVar4;
      if ((uint)(dword_F010F39C - iVar2) < uVar4) {
        uVar8 = dword_F010F39C - iVar2;
      }
      iVar11 = iVar10 + iVar2;
      _uiomove(iVar11,uVar8,0,param_2);
      if (iVar11 != 0) {
        wVar7 = *(word *)(puVar12 + 0x10);
        goto loc_F0046ECC;
      }
      uVar4 = uVar4 - uVar8;
      puVar12[0x1f] = puVar12[0x1f] - uVar8;
      iVar6 = *(word *)((int)puVar12 + 0x86) + uVar8;
      *(sword *)((int)puVar12 + 0x86) = (sword)iVar6;
      iVar2 = 0;
      if (dword_F010F39C < iVar6 * 0x10000 >> 0x10) {
        _printf(aFifoReadRptrAf);
      }
      if (*(sword *)((int)puVar12 + 0x86) == dword_F010F39C) {
        *(undefined2 *)((int)puVar12 + 0x86) = 0;
        sub_F0047258(iVar10,puVar12);
        puVar12[0x1a] = iVar10;
        *(sword *)(puVar12 + 0x21) = *(sword *)(puVar12 + 0x21) - (sword)dword_F010F39C;
      }
    }
    _smark(puVar12,4);
    if ((*(word *)(puVar12 + 0x22) & 2) != 0) {
      *(word *)(puVar12 + 0x22) = *(word *)(puVar12 + 0x22) & 0xfffd;
      _wakeup(puVar12 + 0x20);
    }
    if (puVar12[0x1d] == 0) {
      wVar7 = *(word *)(puVar12 + 0x10);
      goto loc_F0046ECC;
    }
    _selwakeup(puVar12[0x1d],*(word *)(puVar12 + 0x22) & 8);
    _thread_deallocate(puVar12[0x1d]);
    puVar12[0x1d] = 0;
    *(word *)(puVar12 + 0x22) = *(word *)(puVar12 + 0x22) & 0xfff7;
  }
  wVar7 = *(word *)(puVar12 + 0x10);
loc_F0046ECC:
  *(word *)(puVar12 + 0x10) = wVar7 & 0xfffe;
  if ((wVar7 & 0x10) != 0) {
    *(word *)(puVar12 + 0x10) = wVar7 & 0xffee;
    _wakeup(puVar12);
  }
  *(undefined4 *)(param_2 + 8) = 0;
  return CONCAT44(param_2,iVar11);
loc_F0046C0C:
  iVar11 = 0x20;
  _psignal(*_active_u,0xd);
  wVar7 = *(word *)(puVar12 + 0x10);
  goto loc_F0046ECC;
}
