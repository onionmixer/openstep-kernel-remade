
/* WARNING: Removing unreachable block (ram,0xf002cd90) */
/* WARNING: Removing unreachable block (ram,0xf002cd70) */
/* WARNING: Removing unreachable block (ram,0xf002ce00) */
/* WARNING: Removing unreachable block (ram,0xf002ccc8) */

undefined8 _rtalloc(int *param_1,undefined *param_2)

{
  sword sVar1;
  bool bVar2;
  undefined *puVar3;
  int iVar4;
  undefined4 unaff_l0;
  int iVar5;
  undefined4 unaff_l1;
  undefined4 *puVar6;
  int *piVar7;
  undefined4 unaff_l3;
  uint uVar8;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  uint uVar9;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  code *pcVar10;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
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
  iVar4 = *param_1;
  uVar9 = (uint)*(word *)(param_1 + 1);
  if ((((iVar4 == 0) || (*(int *)(iVar4 + 0x2c) == 0)) || ((*(word *)(iVar4 + 0x24) & 1) == 0)) &&
     (uVar9 < 0x11)) {
    bVar2 = true;
    (**(code **)(_afswitch + uVar9 * 8))(param_1 + 1,(undefined *)((int)register0x00000038 + -0x10))
    ;
    uVar8 = *(uint *)((int)register0x00000038 + -0x10);
    puVar3 = DAT_f0135000;
    pcVar10 = *(code **)(_afswitch + uVar9 * 8 + 4);
    param_2 = _rthost;
    _splnet();
    piVar7 = param_1 + 1;
loc_F002CCD4:
    puVar6 = *(undefined4 **)(param_2 + (uVar8 & 7) * 4);
    if (puVar6 != (undefined4 *)0x0) {
      iVar4 = puVar6[1];
      do {
        iVar5 = (int)puVar6 + iVar4;
        if (*(uint *)((int)puVar6 + iVar4) == uVar8) {
          if ((*(word *)(iVar5 + 0x24) & 1) == 0) {
            puVar6 = (undefined4 *)*puVar6;
          }
          else if ((*(word *)(*(int *)(iVar5 + 0x2c) + 0xc) & 1) == 0) {
            puVar6 = (undefined4 *)*puVar6;
          }
          else {
            iVar4 = iVar5 + 4;
            if (bVar2) {
              _bcmp(iVar4,piVar7,0x10);
              if (iVar4 == 0) {
                sVar1 = *(sword *)(iVar5 + 0x26);
loc_F002CD88:
                *(sword *)(iVar5 + 0x26) = sVar1 + 1;
                _splx(puVar3);
                if (piVar7 == (int *)_wildcard) {
                  sRamf0135288 = sRamf0135288 + 1;
                  *param_1 = iVar5;
                }
                else {
                  *param_1 = iVar5;
                }
                goto locret_F002CE1C;
              }
              puVar6 = (undefined4 *)*puVar6;
            }
            else if (*(word *)(iVar5 + 4) == uVar9) {
              iVar4 = iVar5 + 4;
              (*pcVar10)(iVar4,piVar7);
              if (iVar4 != 0) {
                sVar1 = *(sword *)(iVar5 + 0x26);
                goto loc_F002CD88;
              }
              puVar6 = (undefined4 *)*puVar6;
            }
            else {
              puVar6 = (undefined4 *)*puVar6;
            }
          }
        }
        else {
          puVar6 = (undefined4 *)*puVar6;
        }
        if (puVar6 == (undefined4 *)0x0) break;
        iVar4 = puVar6[1];
      } while( true );
    }
    uVar8 = *(uint *)((int)register0x00000038 + -0xc);
    if (bVar2) {
      bVar2 = false;
      param_2 = _rtnet;
      goto loc_F002CCD4;
    }
    if (piVar7 != (int *)_wildcard) {
      uVar8 = 0;
      piVar7 = (int *)_wildcard;
      goto loc_F002CCD4;
    }
    _splx(puVar3);
    sRamf0135286 = sRamf0135286 + 1;
  }
locret_F002CE1C:
  return CONCAT44(param_2,param_1);
}
