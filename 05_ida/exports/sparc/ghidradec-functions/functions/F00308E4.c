
/* WARNING: Removing unreachable block (ram,0xf0030bac) */
/* WARNING: Removing unreachable block (ram,0xf0030ac8) */
/* WARNING: Removing unreachable block (ram,0xf0030a2c) */
/* WARNING: Removing unreachable block (ram,0xf0030aac) */
/* WARNING: Removing unreachable block (ram,0xf0030ad0) */
/* WARNING: Removing unreachable block (ram,0xf0030c44) */
/* WARNING: Removing unreachable block (ram,0xf00309d4) */

undefined8 _in_pcbconnect(int param_1,int param_2)

{
  sword sVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 unaff_l0;
  undefined *puVar6;
  int *piVar7;
  undefined4 unaff_l1;
  undefined *puVar8;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar9;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar10;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
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
  puVar6 = (undefined *)0x0;
  puVar8 = (undefined *)(param_2 + *(int *)(param_2 + 4));
  if (*(sword *)(param_2 + 8) != 0x10) {
    uVar9 = 0x16;
    goto locret_F0030C68;
  }
  uVar9 = 0x2f;
  if (*(sword *)(param_2 + *(int *)(param_2 + 4)) != 2) goto locret_F0030C68;
  if (*(sword *)(puVar8 + 2) == 0) {
loc_F0030B70:
    uVar9 = 0x31;
  }
  else {
    if (_in_ifaddr == (undefined *)0x0) {
      iVar3 = *(int *)(param_1 + 0x14);
    }
    else if (*(int *)(puVar8 + 4) == 0) {
      uVar9 = *(undefined4 *)(_in_ifaddr + 4);
loc_F0030974:
      *(undefined4 *)(puVar8 + 4) = uVar9;
      iVar3 = *(int *)(param_1 + 0x14);
    }
    else if (*(int *)(puVar8 + 4) == -1) {
      if ((*(word *)(*(int *)(_in_ifaddr + 0x20) + 0xc) & 2) != 0) {
        uVar9 = *(undefined4 *)(_in_ifaddr + 0x14);
        goto loc_F0030974;
      }
      iVar3 = *(int *)(param_1 + 0x14);
    }
    else {
      iVar3 = *(int *)(param_1 + 0x14);
    }
    if (iVar3 == 0) {
      iVar3 = *(int *)(param_1 + 0x24);
      puVar6 = (undefined *)0x0;
      piVar7 = (int *)(param_1 + 0x24);
      if (iVar3 == 0) {
loc_F00309EC:
        iVar3 = *(int *)(param_1 + 0x1c);
      }
      else {
        if (*(int *)(param_1 + 0x2c) != *(int *)(puVar8 + 4)) {
          sVar1 = *(sword *)(iVar3 + 0x26);
loc_F00309C8:
          if (sVar1 == 1) {
            _rtfree(iVar3);
            *piVar7 = 0;
          }
          else {
            *(sword *)(iVar3 + 0x26) = sVar1 + -1;
            *piVar7 = 0;
          }
          goto loc_F00309EC;
        }
        if ((*(word *)(*(int *)(param_1 + 0x1c) + 2) & 0x10) != 0) {
          sVar1 = *(sword *)(iVar3 + 0x26);
          goto loc_F00309C8;
        }
        iVar3 = *(int *)(param_1 + 0x1c);
      }
      iVar4 = *piVar7;
      if ((*(word *)(iVar3 + 2) & 0x10) == 0) {
        if ((iVar4 == 0) || (*(int *)(iVar4 + 0x2c) == 0)) {
          *(undefined2 *)(param_1 + 0x28) = 2;
          *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(puVar8 + 4);
          _rtalloc(piVar7);
          iVar4 = *piVar7;
        }
        else {
          iVar4 = *piVar7;
        }
      }
      bVar10 = true;
      if (iVar4 != 0) {
        iVar3 = *(int *)(iVar4 + 0x2c);
        bVar10 = true;
        if (((iVar3 != 0) && (bVar10 = true, (*(word *)(iVar3 + 0xc) & 8) == 0)) &&
           (bVar10 = _in_ifaddr == (undefined *)0x0, puVar6 = _in_ifaddr, !bVar10)) {
          iVar4 = *(int *)(_in_ifaddr + 0x20);
          while (bVar10 = puVar6 == (undefined *)0x0, iVar4 != iVar3) {
            puVar6 = *(undefined **)(puVar6 + 0x40);
            if (puVar6 == (undefined *)0x0) {
              bVar10 = true;
              break;
            }
            iVar4 = *(int *)(puVar6 + 0x20);
          }
        }
      }
      if (bVar10) {
        uVar2 = *(undefined2 *)(puVar8 + 2);
        *(undefined2 *)(puVar8 + 2) = 0;
        puVar6 = puVar8;
        _ifa_ifwithdstaddr();
        *(undefined2 *)(puVar8 + 2) = uVar2;
        bVar10 = false;
        if (puVar6 == (undefined *)0x0) {
          puVar6 = (undefined *)((int)register0x00000038 + -0xc);
          *(undefined4 *)((int)register0x00000038 + -0xc) = *(undefined4 *)(puVar8 + 4);
          _in_netof();
          _in_iaonnetof();
          bVar10 = puVar6 == (undefined *)0x0;
        }
        if (bVar10) {
          puVar6 = _in_ifaddr;
        }
        if (bVar10 && _in_ifaddr == (undefined *)0x0) {
          uVar9 = 0x31;
          goto locret_F0030C68;
        }
        uVar5 = *(uint *)(puVar8 + 4);
      }
      else {
        uVar5 = *(uint *)(puVar8 + 4);
      }
      if ((((uVar5 & 0xf0000000) == 0xe0000000) && (iVar3 = *(int *)(param_1 + 0x3c), iVar3 != 0))
         && (iVar3 = *(int *)(iVar3 + *(int *)(iVar3 + 4)), iVar3 != 0)) {
        bVar10 = _in_ifaddr == (undefined *)0x0;
        puVar6 = _in_ifaddr;
        if (!bVar10) {
          iVar4 = *(int *)(_in_ifaddr + 0x20);
          while (bVar10 = puVar6 == (undefined *)0x0, iVar4 != iVar3) {
            puVar6 = *(undefined **)(puVar6 + 0x40);
            if (puVar6 == (undefined *)0x0) {
              bVar10 = true;
              break;
            }
            iVar4 = *(int *)(puVar6 + 0x20);
          }
        }
        if (bVar10) goto loc_F0030B70;
      }
      uVar9 = *(undefined4 *)(puVar8 + 4);
    }
    else {
      uVar9 = *(undefined4 *)(puVar8 + 4);
    }
    *(undefined4 *)((int)register0x00000038 + -0xc) = uVar9;
    iVar3 = *(int *)(param_1 + 0x14);
    if (iVar3 == 0) {
      iVar3 = *(int *)(puVar6 + 4);
    }
    *(int *)((int)register0x00000038 + -0x10) = iVar3;
    iVar3 = *(int *)(param_1 + 8);
    _in_pcblookup(iVar3,(undefined *)((int)register0x00000038 + -0xc),*(undefined2 *)(puVar8 + 2),
                  (undefined *)((int)register0x00000038 + -0x10),*(undefined2 *)(param_1 + 0x18),0);
    uVar9 = 0x30;
    if (iVar3 == 0) {
      if ((*(word *)(*(int *)(*(int *)(param_1 + 0x1c) + 0xc) + 10) & 4) == 0) {
        iVar3 = *(int *)(param_1 + 0x14);
      }
      else {
        iVar3 = *(int *)(param_1 + 0x14);
        if (*(sword *)(puVar8 + 2) == *(sword *)(param_1 + 0x18)) {
          if (iVar3 == 0) {
            if (*(int *)(puVar6 + 4) == *(int *)(puVar8 + 4)) {
              uVar9 = 0x3d;
              goto locret_F0030C68;
            }
            iVar3 = *(int *)(param_1 + 0x14);
          }
          else {
            uVar9 = 0x3d;
            if (iVar3 == *(int *)(puVar8 + 4)) goto locret_F0030C68;
          }
        }
      }
      if (iVar3 == 0) {
        if (*(sword *)(param_1 + 0x18) == 0) {
          _in_pcbbind(param_1,0);
          uVar9 = *(undefined4 *)(puVar6 + 4);
        }
        else {
          uVar9 = *(undefined4 *)(puVar6 + 4);
        }
        *(undefined4 *)(param_1 + 0x14) = uVar9;
        uVar9 = *(undefined4 *)(puVar8 + 4);
      }
      else {
        uVar9 = *(undefined4 *)(puVar8 + 4);
      }
      *(undefined4 *)(param_1 + 0xc) = uVar9;
      uVar9 = 0;
      *(undefined2 *)(param_1 + 0x10) = *(undefined2 *)(puVar8 + 2);
    }
  }
locret_F0030C68:
  return CONCAT44(param_2,uVar9);
}
