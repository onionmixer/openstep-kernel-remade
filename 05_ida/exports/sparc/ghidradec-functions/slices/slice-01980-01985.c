/* GHIDRADEC_FUNCTION index=1980 start=0xf0092dd0 */

/* WARNING: Removing unreachable block (ram,0xf0092df0) */
/* WARNING: Removing unreachable block (ram,0xf0092dd8) */

undefined8 _sdsize(sword param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  iVar1 = (int)param_1;
  sub_F0092E34();
  if (iVar1 == 0) {
    iVar1 = -1;
  }
  else {
    _objc_msgSend(iVar1,paBlocksize);
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=1981 start=0xf0092ee8 */

/* WARNING: Removing unreachable block (ram,0xf0092f10) */
/* WARNING: Removing unreachable block (ram,0xf0092ef0) */

undefined8 _sgopen(sword param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar2;
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
  iVar1 = (int)param_1;
  sub_F0093234();
  if (iVar1 == 0) {
    uVar2 = 6;
  }
  else {
    _objc_msgSend();
    uVar2 = -(uint)(iVar1 != 0) & 0x10;
  }
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=1982 start=0xf0092f2c */

/* WARNING: Removing unreachable block (ram,0xf0092f54) */
/* WARNING: Removing unreachable block (ram,0xf0092f34) */

undefined8 _sgclose(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  iVar1 = (int)(sword)param_1;
  sub_F0093234();
  if (iVar1 == 0) {
    param_1 = 6;
  }
  else {
    _objc_msgSend();
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1983 start=0xf0092f64 */

/* WARNING: Removing unreachable block (ram,0xf0093218) */
/* WARNING: Removing unreachable block (ram,0xf00931e0) */
/* WARNING: Removing unreachable block (ram,0xf0093138) */
/* WARNING: Removing unreachable block (ram,0xf00931d0) */
/* WARNING: Removing unreachable block (ram,0xf00930b4) */
/* WARNING: Removing unreachable block (ram,0xf00930cc) */
/* WARNING: Removing unreachable block (ram,0xf0093108) */
/* WARNING: Removing unreachable block (ram,0xf00930e4) */
/* WARNING: Removing unreachable block (ram,0xf0093160) */
/* WARNING: Removing unreachable block (ram,0xf0093098) */
/* WARNING: Removing unreachable block (ram,0xf00931a0) */
/* WARNING: Removing unreachable block (ram,0xf0093124) */
/* WARNING: Removing unreachable block (ram,0xf00931b8) */
/* WARNING: Removing unreachable block (ram,0xf00931f0) */
/* WARNING: Removing unreachable block (ram,0xf0093174) */
/* WARNING: Removing unreachable block (ram,0xf0092f6c) */
/* WARNING: Heritage AFTER dead removal. Example location: o3 : 0xf0093108 */
/* WARNING: Restarted to delay deadcode elimination for space: register */

undefined8 _sgioctl(sword param_1,int param_2)

{
  undefined uVar1;
  undefined (*pauVar2) [22];
  uint uVar3;
  int iVar4;
  char cVar6;
  uint uVar5;
  undefined (*pauVar7) [13];
  undefined (*pauVar8) [10];
  uint *puVar9;
  undefined (*pauVar10) [17];
  undefined8 in_o2_3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar11;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  puVar9 = (uint *)((qword)in_o2_3 >> 0x20);
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
  uVar3 = (uint)param_1;
  sub_F0093234();
  pauVar2 = paSettargetLunIs;
  uVar11 = 0;
  if (uVar3 == 0) {
    uVar11 = 6;
    goto locret_F009322C;
  }
  pauVar10 = (undefined (*) [17])paEnableautosens;
  if (param_2 != 0x20007302) {
    if (param_2 < 0x20007303) {
      if (param_2 == -0x7fef8cf4) {
        _suser();
        _objc_msgSend(uVar3,paSetscsi3target,(int)((qword)*(undefined8 *)puVar9 >> 0x20),
                      (int)*(undefined8 *)puVar9,(int)((qword)*(undefined8 *)(puVar9 + 2) >> 0x20));
      }
      else {
        if (-0x7fef8cf4 < param_2) {
          if (param_2 != -0x3fa78cff) {
            if (param_2 != -0x3fa38cf2) {
              uVar11 = 0x16;
              goto locret_F009322C;
            }
            puVar9 = (uint *)0x0;
          }
          sub_F0093264(uVar3,puVar9);
          uVar11 = uVar3;
          goto locret_F009322C;
        }
        if (param_2 != -0x7ffd8d00) {
          if (param_2 == -0x7ffb8cfa) {
            _objc_msgSend(uVar3,paSetcontroller,*puVar9);
            if (uVar3 != 0) {
              uVar11 = 0x13;
            }
          }
          else {
            uVar11 = 0x16;
          }
          goto locret_F009322C;
        }
        cVar6 = '\0';
        uVar1 = *(undefined *)puVar9;
        _suser();
        _objc_msgSend(uVar3,pauVar2,uVar1,(int)in_o2_3,(int)cVar6);
      }
      if (uVar3 != 0) {
        uVar11 = 0xd;
      }
      goto locret_F009322C;
    }
    if (param_2 == 0x40047307) {
      _objc_msgSend(uVar3,paAutosense);
      *puVar9 = (uint)(uVar3 != 0);
      goto locret_F009322C;
    }
    if (0x40047307 < param_2) {
      if (param_2 == 0x40047309) {
        _objc_msgSend(uVar3,paController);
      }
      else {
        if (0x40047308 < param_2) {
          if (param_2 == 0x4010730d) {
            uVar5 = uVar3;
            pauVar7 = paScsi3Target;
            _objc_msgSend();
            *(qword *)puVar9 = CONCAT44(uVar5,pauVar7);
            pauVar8 = paScsi3Lun;
            _objc_msgSend();
            *(qword *)(puVar9 + 2) = CONCAT44(uVar3,pauVar8);
          }
          else {
            uVar11 = 0x16;
          }
          goto locret_F009322C;
        }
        _objc_msgSend(uVar3,paController);
      }
      _objc_msgSend();
      *puVar9 = uVar3;
      goto locret_F009322C;
    }
    pauVar10 = paDisableautosen;
    if (param_2 != 0x20007303) {
      iVar4 = 0x20007304;
      if (param_2 == 0x20007304) {
        _suser();
        if (iVar4 == 0) {
          uVar11 = (uint)*(char *)(dword_F0133DDC + 0x38);
        }
        else {
          _objc_msgSend(uVar3,paResetscsibus);
          if (uVar3 != 0) {
            uVar11 = 5;
          }
        }
      }
      else {
        uVar11 = 0x16;
      }
      goto locret_F009322C;
    }
  }
  _objc_msgSend(uVar3,pauVar10);
  if (uVar3 != 0) {
    uVar11 = 0x16;
  }
locret_F009322C:
  return CONCAT44(param_2,uVar11);
}
/* GHIDRADEC_FUNCTION index=1984 start=0xf00936ac */

undefined8 _volopen(undefined4 param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar1;
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
  uVar1 = 0x10;
  if (unk_F0131250 == '\0') {
    unk_F0131250 = '\x01';
    uVar1 = 0;
  }
  return CONCAT44(param_2,uVar1);
}

