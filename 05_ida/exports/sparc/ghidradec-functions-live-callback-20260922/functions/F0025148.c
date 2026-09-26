
/* WARNING: Removing unreachable block (ram,0xf00252a4) */
/* WARNING: Removing unreachable block (ram,0xf0025274) */
/* WARNING: Removing unreachable block (ram,0xf0025250) */
/* WARNING: Removing unreachable block (ram,0xf0025224) */
/* WARNING: Removing unreachable block (ram,0xf0025178) */
/* WARNING: Removing unreachable block (ram,0xf002520c) */
/* WARNING: Removing unreachable block (ram,0xf0025248) */
/* WARNING: Removing unreachable block (ram,0xf002526c) */
/* WARNING: Removing unreachable block (ram,0xf002529c) */
/* WARNING: Removing unreachable block (ram,0xf00252b4) */
/* WARNING: Removing unreachable block (ram,0xf002516c) */

undefined8 _blkflush(uint param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 unaff_l0;
  uint uVar5;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  uint *puVar6;
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
  uVar1 = param_1;
  (**(code **)(*(int *)(param_1 + 0x1c) + 0x80))();
  if ((int)uVar1 < 0) {
    _panic(aCouldnTDetermi_0);
  }
  udiv(param_3,uVar1);
  iVar4 = param_2;
  if (param_2 < 0) {
    iVar4 = param_2 + 7;
  }
  iVar4 = (param_1 + (iVar4 >> 3) & 0xf) * 0xc;
  puVar6 = *(uint **)(_bufhash + iVar4 + 4);
loc_F00251BC:
  if (puVar6 == (uint *)(_bufhash + iVar4)) {
locret_F00252CC:
    return CONCAT44(param_2,param_1);
  }
  uVar2 = puVar6[0x10];
  do {
    if (uVar2 == param_1) {
      if ((*puVar6 & 0x10000) == 0) {
        uVar2 = puVar6[5];
        if (uVar2 == 0) {
          puVar6 = (uint *)puVar6[1];
        }
        else {
          uVar5 = puVar6[9];
          if (param_2 + param_3 + -1 < (int)uVar5) {
            puVar6 = (uint *)puVar6[1];
          }
          else {
            div(uVar2,uVar1);
            iVar3 = uVar5 + uVar2;
            if (param_2 < iVar3) {
              _splusclock();
              uVar2 = *puVar6;
              if ((uVar2 & 8) != 0) {
                *puVar6 = uVar2 | 0x40;
                _sleep(puVar6,0x15);
                _splx(iVar3);
                puVar6 = *(uint **)(_bufhash + iVar4 + 4);
                goto loc_F00251BC;
              }
              if ((uVar2 & 0x200) != 0) break;
              _splx(iVar3);
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
    if (puVar6 == (uint *)(_bufhash + iVar4)) goto locret_F00252CC;
    uVar2 = puVar6[0x10];
  } while( true );
  _splx(iVar3);
  _spltty();
  *(uint *)(puVar6[4] + 0xc) = puVar6[3];
  *(uint *)(puVar6[3] + 0x10) = puVar6[4];
  *puVar6 = *puVar6 | 8;
  _splx();
  _bwrite(puVar6);
  puVar6 = *(uint **)(_bufhash + iVar4 + 4);
  goto loc_F00251BC;
}

