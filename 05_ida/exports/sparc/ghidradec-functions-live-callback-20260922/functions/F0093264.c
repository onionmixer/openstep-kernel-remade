
/* WARNING: Removing unreachable block (ram,0xf0093680) */
/* WARNING: Removing unreachable block (ram,0xf009361c) */
/* WARNING: Removing unreachable block (ram,0xf0093530) */
/* WARNING: Removing unreachable block (ram,0xf00934e0) */
/* WARNING: Removing unreachable block (ram,0xf00933b8) */
/* WARNING: Removing unreachable block (ram,0xf0093378) */
/* WARNING: Removing unreachable block (ram,0xf0093304) */
/* WARNING: Removing unreachable block (ram,0xf00932cc) */
/* WARNING: Removing unreachable block (ram,0xf00932c0) */
/* WARNING: Removing unreachable block (ram,0xf00932f0) */
/* WARNING: Removing unreachable block (ram,0xf009335c) */
/* WARNING: Removing unreachable block (ram,0xf00933a8) */
/* WARNING: Removing unreachable block (ram,0xf00933ec) */
/* WARNING: Removing unreachable block (ram,0xf0093520) */
/* WARNING: Removing unreachable block (ram,0xf0093544) */
/* WARNING: Removing unreachable block (ram,0xf0093654) */
/* WARNING: Removing unreachable block (ram,0xf0093698) */
/* WARNING: Removing unreachable block (ram,0xf00932ac) */
/* WARNING: Removing unreachable block (ram,0xf00933cc) */
/* WARNING: Removing unreachable block (ram,0xf0093400) */
/* WARNING: Heritage AFTER dead removal. Example location: o1 : 0xf0093304 */
/* WARNING: Removing unreachable block (ram,0xf00933f8) */
/* WARNING: Restarted to delay deadcode elimination for space: register */

undefined4 sub_F0093264(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  undefined8 in_o0_1;
  undefined4 *puVar4;
  undefined8 uVar3;
  uint uVar5;
  undefined4 unaff_l0;
  uint uVar6;
  undefined4 unaff_l1;
  uint uVar7;
  undefined4 uVar8;
  undefined4 unaff_l3;
  uint uVar9;
  undefined4 unaff_l4;
  undefined4 uVar10;
  undefined4 unaff_l5;
  int iVar11;
  undefined4 unaff_l6;
  uint uVar12;
  undefined4 unaff_l7;
  bool bVar13;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar14;
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
  uVar1 = (uint)((qword)in_o0_1 >> 0x20);
  puVar4 = (undefined4 *)in_o0_1;
  uVar6 = 0;
  iVar11 = 0;
  uVar12 = 0;
  uVar9 = 0;
  bVar13 = false;
  uVar10 = 0;
  if (puVar4 == (undefined4 *)0x0) {
    if (param_1 == (undefined4 *)0x0) {
      _IOPanic(DAT_f01124f0);
    }
    else {
      uVar6 = param_1[6];
      iVar11 = param_1[4];
      uVar12 = param_1[5];
    }
  }
  else {
    uVar6 = puVar4[5];
    iVar11 = puVar4[3];
    uVar12 = puVar4[4];
  }
  _objc_msgSend(uVar1);
  _objc_msgSend();
  if (uVar1 < uVar6) {
    return 0x16;
  }
  uVar7 = uVar12;
  if (uVar6 == 0) {
loc_F009339C:
    uVar8 = 0;
    if (puVar4 == (undefined4 *)0x0) {
      _bzero((undefined *)((int)register0x00000038 + -0xf0));
      _objc_msgSend(uVar1);
      *(undefined8 *)((int)register0x00000038 + -0xf0) = in_o0_1;
      _objc_msgSend(uVar1);
      *(undefined8 *)((int)register0x00000038 + -0xe8) = in_o0_1;
      *(undefined4 *)((int)register0x00000038 + -0xe0) = *param_1;
      *(undefined4 *)((int)register0x00000038 + -0xdc) = param_1[1];
      *(undefined4 *)((int)register0x00000038 + -0xd8) = param_1[2];
      uVar5 = *(uint *)((int)register0x00000038 + -0xc4);
      *(undefined4 *)((int)register0x00000038 + -0xd4) = param_1[3];
      *(bool *)((int)register0x00000038 + -0xd0) = param_1[4] == 0;
      *(uint *)((int)register0x00000038 + -0xcc) = uVar9;
      *(undefined4 *)((int)register0x00000038 + -200) = param_1[7];
      uVar9 = ((uint)param_1[0x14] >> 0x17 ^ 1) << 0x1f;
      *(uint *)((int)register0x00000038 + -0xc4) = uVar5 & 0x7fffffff | uVar9;
      uVar6 = ((uint)param_1[0x14] >> 0x16 & 1) << 0x1e;
      *(uint *)((int)register0x00000038 + -0xc4) = uVar5 & 0x3fffffff | uVar9 | uVar6;
      uVar12 = ((uint)param_1[0x14] >> 0x15 & 1) << 0x1d;
      *(uint *)((int)register0x00000038 + -0xc4) = uVar5 & 0x1fffffff | uVar9 | uVar6 | uVar12;
      *(uint *)((int)register0x00000038 + -0xc4) =
           uVar5 & 0x1ffffff0 | uVar9 | uVar6 | uVar12 | *(byte *)(param_1 + 0x14) & 0xf;
      _objc_msgSend(uVar1,0,(undefined *)((int)register0x00000038 + -0xf0),uVar7,uVar10,0x24);
      param_1[8] = uVar1;
      *(undefined *)(param_1 + 9) = *(undefined *)((int)register0x00000038 + -0xbc);
      iVar2 = *(int *)((int)register0x00000038 + -0xb8);
      param_1[0x11] = iVar2;
      if ((int)param_1[6] < iVar2) {
        param_1[0x11] = param_1[6];
      }
      uVar3 = *(undefined8 *)((int)register0x00000038 + -0xb0);
      puVar4 = param_1 + 0x12;
loc_F0093654:
      uVar10 = (undefined4)((qword)uVar3 >> 0x20);
      _ns_time_to_timeval(uVar10,(int)uVar3,puVar4);
      bVar14 = !bVar13;
      if (iVar11 != 0) goto loc_F0093690;
      if (iVar2 != 0) {
        bVar14 = true;
        if (!bVar13) goto loc_F0093690;
        _copyout(uVar7,(int)uVar3,iVar2);
        uVar8 = uVar10;
      }
    }
    else {
      _bzero((undefined *)((int)register0x00000038 + -0x80));
      _objc_msgSend(uVar1);
      if (uVar1 == 0) {
        if (puVar4 < (undefined4 *)0x20) {
          *(char *)((int)register0x00000038 + -0x80) = (char)in_o0_1;
          _objc_msgSend(0);
          if (puVar4 < (undefined4 *)0x8) {
            *(char *)((int)register0x00000038 + -0x7f) = (char)in_o0_1;
            *(undefined4 *)((int)register0x00000038 + -0x7c) = *puVar4;
            *(undefined4 *)((int)register0x00000038 + -0x78) = puVar4[1];
            uVar12 = *(uint *)((int)register0x00000038 + -100);
            *(undefined4 *)((int)register0x00000038 + -0x74) = puVar4[2];
            *(bool *)((int)register0x00000038 + -0x70) = puVar4[3] == 0;
            *(uint *)((int)register0x00000038 + -0x6c) = uVar9;
            *(undefined4 *)((int)register0x00000038 + -0x68) = puVar4[6];
            uVar9 = ((uint)puVar4[0x13] >> 0x17 ^ 1) << 0x1f;
            *(uint *)((int)register0x00000038 + -100) = uVar12 & 0x7fffffff | uVar9;
            uVar1 = ((uint)puVar4[0x13] >> 0x16 & 1) << 0x1e;
            *(uint *)((int)register0x00000038 + -100) = uVar12 & 0x3fffffff | uVar9 | uVar1;
            uVar6 = ((uint)puVar4[0x13] >> 0x15 & 1) << 0x1d;
            *(uint *)((int)register0x00000038 + -100) = uVar12 & 0x1fffffff | uVar9 | uVar1 | uVar6;
            *(uint *)((int)register0x00000038 + -100) =
                 uVar12 & 0x1ffffff0 | uVar9 | uVar1 | uVar6 | *(byte *)(puVar4 + 0x13) & 0xf;
            _objc_msgSend(0,puVar4,(undefined *)((int)register0x00000038 + -0x80),uVar7,uVar10,
                          puVar4 + 9);
            puVar4[7] = 0;
            *(undefined *)(puVar4 + 8) = *(undefined *)((int)register0x00000038 + -0x5c);
            iVar2 = *(int *)((int)register0x00000038 + -0x58);
            puVar4[0x10] = iVar2;
            if ((int)puVar4[5] < iVar2) {
              puVar4[0x10] = puVar4[5];
            }
            uVar3 = *(undefined8 *)((int)register0x00000038 + -0x50);
            puVar4 = puVar4 + 0x11;
            goto loc_F0093654;
          }
          uVar8 = 0x16;
        }
        else {
          uVar8 = 0x16;
        }
      }
      else {
        uVar8 = 0x16;
      }
    }
  }
  else {
    _objc_msgSend();
    _objc_msgSend(uVar1,puVar4,(undefined *)((int)register0x00000038 + -0x18));
    uVar10 = _kernel_map;
    bVar13 = true;
    uVar9 = uVar6;
    if ((undefined4 *)0x1 < puVar4) {
      uVar9 = (int)puVar4 + (uVar6 - 1) & -(int)puVar4;
    }
    _objc_msgSend(uVar1,puVar4,uVar6,(undefined *)((int)register0x00000038 + -0x1c),
                  (undefined *)((int)register0x00000038 + -0x20));
    uVar7 = uVar1;
    if ((iVar11 != 1) || (_copyin(uVar12,puVar4,uVar6), uVar1 == 0)) goto loc_F009339C;
    uVar8 = 0xe;
  }
  bVar14 = !bVar13;
loc_F0093690:
  if (!bVar14) {
    _IOFree();
  }
  return uVar8;
}

