
/* WARNING: Removing unreachable block (ram,0xf00b9ecc) */
/* WARNING: Removing unreachable block (ram,0xf00b9ebc) */
/* WARNING: Removing unreachable block (ram,0xf00b9edc) */
/* WARNING: Removing unreachable block (ram,0xf00b9e80) */
/* WARNING: Removing unreachable block (ram,0xf00b9e44) */
/* WARNING: Removing unreachable block (ram,0xf00b9f08) */
/* WARNING: Removing unreachable block (ram,0xf00b9f00) */
/* WARNING: Removing unreachable block (ram,0xf00b9e60) */
/* WARNING: Removing unreachable block (ram,0xf00b9e78) */
/* WARNING: Removing unreachable block (ram,0xf00b9e9c) */
/* WARNING: Removing unreachable block (ram,0xf00b9eec) */
/* WARNING: Removing unreachable block (ram,0xf00b9eac) */
/* WARNING: Removing unreachable block (ram,0xf00b9d48) */
/* WARNING: Removing unreachable block (ram,0xf00b9cd8) */

undefined8 _zsioctl(uint param_1,int param_2,undefined4 *param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  byte bVar3;
  undefined4 unaff_l0;
  undefined *puVar4;
  undefined4 unaff_l1;
  int iVar5;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined *puVar6;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar7;
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
  iVar1 = (param_1 & 0x1f) * 0x88;
  puVar4 = _zs_tty + iVar1;
  iVar5 = *(int *)(_zs_tty + iVar1 + 0x34);
  puVar6 = puVar4;
  (**(code **)(DAT_f010b8dc + (char)_zs_tty[iVar1 + 0x47] * 0x30))(puVar4,param_2,param_3,param_4);
  bVar7 = false;
  if ((int)puVar6 < 0) {
    puVar6 = puVar4;
    _ttioctl(puVar4,param_2,param_3,param_4);
    bVar7 = (int)puVar6 < 0;
  }
  if (bVar7) {
    if (param_2 == 0x20007479) {
      uVar2 = 0x82;
loc_F00B9ECC:
      _zsmctl(puVar4,uVar2,1);
      puVar6 = (undefined *)0x0;
    }
    else {
      if (0x20007479 < param_2) {
        if (param_2 == 0x4004746a) {
          _zsmctl(puVar4,0,3);
          puVar6 = (undefined *)0x0;
          _zstodm();
          *param_3 = puVar4;
          goto locret_F00B9F1C;
        }
        if (param_2 < 0x4004746b) {
          if (param_2 == 0x2000747a) {
            _splzs();
            uVar2 = *(undefined4 *)(iVar5 + 0x10);
            bVar3 = *(byte *)(iVar5 + 0x25) & 0xef;
          }
          else {
            puVar6 = (undefined *)0x19;
            if (param_2 != 0x2000747b) goto locret_F00B9F1C;
            _splzs();
            uVar2 = *(undefined4 *)(iVar5 + 0x10);
            bVar3 = *(byte *)(iVar5 + 0x25) | 0x10;
          }
          *(byte *)(iVar5 + 0x25) = bVar3;
          _zszwrite(uVar2,5);
          puVar6 = (undefined *)0x0;
          _spl0();
          goto locret_F00B9F1C;
        }
        if (param_2 != 0x40047a00) {
          puVar6 = (undefined *)0x19;
          if (param_2 == 0x40047a02) {
            puVar6 = (undefined *)0x0;
          }
          goto locret_F00B9F1C;
        }
loc_F00B9F18:
        puVar6 = (undefined *)0x0;
        goto locret_F00B9F1C;
      }
      if (param_2 == -0x7ffb8b93) {
        uVar2 = *param_3;
        _dmtozs(uVar2);
      }
      else {
        if (param_2 < -0x7ffb8b92) {
          if (param_2 == -0x7ffb8b95) {
            uVar2 = *param_3;
            _dmtozs(uVar2);
            _zsmctl(puVar4,uVar2,2);
            puVar6 = (undefined *)0x0;
            goto locret_F00B9F1C;
          }
          puVar6 = (undefined *)0x19;
          if (param_2 != -0x7ffb8b94) goto locret_F00B9F1C;
          uVar2 = *param_3;
          _dmtozs(uVar2);
          goto loc_F00B9ECC;
        }
        if (param_2 == -0x7ffb85ff) goto loc_F00B9F18;
        if (param_2 != 0x20007478) {
          puVar6 = (undefined *)0x19;
          goto locret_F00B9F1C;
        }
        uVar2 = 0;
      }
      _zsmctl(puVar4,uVar2,0);
      puVar6 = (undefined *)0x0;
    }
    goto locret_F00B9F1C;
  }
  if (param_2 < -0x7ff98bf5) {
    if (param_2 < -0x7ff98bf7) {
      if (-0x7ffb8b81 < param_2) goto locret_F00B9F1C;
      iVar1 = -0x7ffb8b83;
      goto loc_F00B9D3C;
    }
  }
  else {
    if (-0x7fdb8bea < param_2) goto locret_F00B9F1C;
    iVar1 = -0x7fdb8bec;
loc_F00B9D3C:
    if (param_2 < iVar1) goto locret_F00B9F1C;
  }
  _zsparam(puVar4);
locret_F00B9F1C:
  return CONCAT44(param_2,puVar6);
}
