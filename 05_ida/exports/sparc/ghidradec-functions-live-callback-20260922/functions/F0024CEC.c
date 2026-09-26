
/* WARNING: Removing unreachable block (ram,0xf0024f08) */
/* WARNING: Removing unreachable block (ram,0xf0024eec) */
/* WARNING: Removing unreachable block (ram,0xf0024ed0) */
/* WARNING: Removing unreachable block (ram,0xf0024ea0) */
/* WARNING: Removing unreachable block (ram,0xf0024d70) */
/* WARNING: Removing unreachable block (ram,0xf0024e70) */
/* WARNING: Removing unreachable block (ram,0xf0024dc8) */
/* WARNING: Removing unreachable block (ram,0xf0024e88) */
/* WARNING: Removing unreachable block (ram,0xf0024d78) */
/* WARNING: Removing unreachable block (ram,0xf0024ea8) */
/* WARNING: Removing unreachable block (ram,0xf0024d88) */
/* WARNING: Removing unreachable block (ram,0xf0024d3c) */
/* WARNING: Removing unreachable block (ram,0xf0024d14) */
/* WARNING: Removing unreachable block (ram,0xf0024db8) */

undefined8 _brealloc(uint *param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 unaff_l0;
  uint *puVar6;
  undefined4 unaff_l1;
  uint uVar7;
  uint uVar8;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
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
  if (param_2 == param_1[5]) {
    param_1 = (uint *)0x1;
  }
  else {
    uVar2 = *param_1;
    if ((uVar2 & 0x200) == 0) {
      if ((int)param_2 < (int)param_1[5]) {
        if ((uVar2 & 0x20000) != 0) {
          _panic(aBrealloc);
        }
      }
      else {
        uVar5 = param_1[0x10];
        *param_1 = uVar2 & 0xfffffffd;
        if (uVar5 != 0) {
          (**(code **)(*(int *)(uVar5 + 0x1c) + 0x80))();
          if ((int)uVar5 < 0) {
            _panic(aCouldnTDetermi);
          }
          uVar8 = param_1[9];
          uVar2 = param_2;
          div(param_2,uVar5);
          uVar3 = uVar8;
          if ((int)uVar8 < 0) {
            uVar3 = uVar8 + 7;
          }
          iVar4 = (param_1[0x10] + ((int)uVar3 >> 3) & 0xf) * 0xc;
          puVar6 = *(uint **)(_bufhash + iVar4 + 4);
loc_F0024E10:
          if (puVar6 != (uint *)(_bufhash + iVar4)) {
            iVar1 = (int)puVar6 - (int)param_1;
            do {
              if (iVar1 == 0) {
                puVar6 = (uint *)puVar6[1];
              }
              else if (puVar6[0x10] == param_1[0x10]) {
                if ((*puVar6 & 0x10000) == 0) {
                  uVar3 = puVar6[5];
                  if (uVar3 == 0) {
                    puVar6 = (uint *)puVar6[1];
                  }
                  else {
                    uVar7 = puVar6[9];
                    if ((int)(uVar8 + uVar2 + -1) < (int)uVar7) {
                      puVar6 = (uint *)puVar6[1];
                    }
                    else {
                      div(uVar3,uVar5);
                      iVar1 = uVar7 + uVar3;
                      if ((int)uVar8 < iVar1) {
                        _splusclock();
                        if ((*puVar6 & 8) != 0) {
                          *puVar6 = *puVar6 | 0x40;
                          _sleep(puVar6,0x15);
                          _splx(iVar1);
                          puVar6 = *(uint **)(_bufhash + iVar4 + 4);
                          goto loc_F0024E10;
                        }
                        _splx();
                        _spltty();
                        *(uint *)(puVar6[4] + 0xc) = puVar6[3];
                        *(uint *)(puVar6[3] + 0x10) = puVar6[4];
                        *puVar6 = *puVar6 | 8;
                        _splx();
                        if ((*puVar6 & 0x200) != 0) goto loc_F0024D88;
                        *puVar6 = *puVar6 | 0x10000;
                        _brelse(puVar6);
                        puVar6 = (uint *)puVar6[1];
                      }
                      else {
                        puVar6 = (uint *)puVar6[1];
                      }
                    }
                  }
                }
                else {
                  puVar6 = (uint *)puVar6[1];
                }
              }
              else {
                puVar6 = (uint *)puVar6[1];
              }
              iVar1 = (int)puVar6 - (int)param_1;
              if (puVar6 == (uint *)(_bufhash + iVar4)) break;
            } while( true );
          }
        }
      }
      _allocbuf(param_1,param_2);
    }
    else {
      _bwrite(param_1);
      param_1 = (uint *)0x0;
    }
  }
  return CONCAT44(param_2,param_1);
loc_F0024D88:
  _bwrite(puVar6);
  puVar6 = *(uint **)(_bufhash + iVar4 + 4);
  goto loc_F0024E10;
}

