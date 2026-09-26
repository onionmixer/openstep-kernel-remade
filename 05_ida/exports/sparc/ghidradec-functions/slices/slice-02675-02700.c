/* GHIDRADEC_FUNCTION index=2675 start=0xf00b23a8 */

/* WARNING: Removing unreachable block (ram,0xf00b23b8) */

undefined8 _mmwrite(sword param_1,undefined4 param_2)

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
  _mmrw(iVar1,param_2,1);
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=2676 start=0xf00b23c8 */

/* WARNING: Removing unreachable block (ram,0xf00b25bc) */
/* WARNING: Removing unreachable block (ram,0xf00b251c) */
/* WARNING: Removing unreachable block (ram,0xf00b24e8) */
/* WARNING: Removing unreachable block (ram,0xf00b24ac) */
/* WARNING: Removing unreachable block (ram,0xf00b2480) */
/* WARNING: Removing unreachable block (ram,0xf00b24d0) */
/* WARNING: Removing unreachable block (ram,0xf00b2504) */
/* WARNING: Removing unreachable block (ram,0xf00b2524) */
/* WARNING: Removing unreachable block (ram,0xf00b2420) */
/* WARNING: Removing unreachable block (ram,0xf00b2544) */

undefined8 _mmrw(uint param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 unaff_l0;
  int *piVar3;
  undefined4 unaff_l1;
  int iVar4;
  uint uVar5;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar6;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
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
  iVar4 = 0;
  iVar6 = 0;
  if (0 < (int)param_2[5]) {
    param_1 = param_1 & 0xff;
    piVar3 = (int *)*param_2;
    do {
      iVar1 = piVar3[1];
      if (iVar1 == 0) {
        iVar1 = param_2[1];
        *param_2 = piVar3 + 2;
        param_2[1] = iVar1 + -1;
        if (-1 < iVar1 + -1) goto loc_F00B2598;
        _panic(&aMmrw);
        iVar1 = param_2[5];
      }
      else {
        if (param_1 == 1) {
          iVar6 = param_2[2];
          _uiomove(iVar6,iVar1,param_3,param_2);
          iVar4 = iVar1;
        }
        else {
          if (param_1 < 2) {
            if (param_1 == 0) {
              uVar5 = param_2[2] & ~_page_mask;
              if ((uint)param_2[2] < _mem_size) {
                uVar2 = _page_mask;
                _splvm();
                *(undefined4 *)((int)register0x00000038 + -0xc) =
                     *(undefined4 *)(_kernel_map + 0x14);
                iVar4 = _kernel_map;
                _vm_map_find(_kernel_map,0,0,(undefined *)((int)register0x00000038 + -0xc),
                             _page_size,1);
                if (iVar4 == 0) {
                  _pmap_enter(*(undefined4 *)(_kernel_map + 0x24),
                              *(undefined4 *)((int)register0x00000038 + -0xc),uVar5,3,1);
                  iVar6 = param_2[2] - uVar5;
                  iVar4 = _page_size - iVar6;
                  _min(iVar4,piVar3[1]);
                  iVar6 = *(int *)((int)register0x00000038 + -0xc) + iVar6;
                  _uiomove(iVar6,iVar4,param_3,param_2);
                  _vm_map_remove(_kernel_map,*(int *)((int)register0x00000038 + -0xc),
                                 *(int *)((int)register0x00000038 + -0xc) + _page_size);
                  _splx(uVar2);
                  iVar1 = param_2[5];
                  goto loc_F00B259C;
                }
                _splx(uVar2,*(undefined4 *)((int)register0x00000038 + -0xc));
              }
              iVar6 = 0xe;
              break;
            }
          }
          else if ((param_1 == 2) && (iVar4 = iVar1, param_3 == 0)) {
            iVar6 = 0;
            break;
          }
          if (iVar6 != 0) break;
          *piVar3 = *piVar3 + iVar4;
          piVar3[1] = piVar3[1] - iVar4;
          param_2[2] = param_2[2] + iVar4;
          param_2[5] = param_2[5] - iVar4;
        }
loc_F00B2598:
        iVar1 = param_2[5];
      }
loc_F00B259C:
      if ((iVar1 < 1) || (iVar6 != 0)) break;
      piVar3 = (int *)*param_2;
    } while( true );
  }
  return CONCAT44(param_2,iVar6);
}
/* GHIDRADEC_FUNCTION index=2677 start=0xf00b25d0 */

/* WARNING: Removing unreachable block (ram,0xf00b25f0) */

undefined8 _peek(undefined4 param_1,undefined4 param_2)

{
  word wVar1;
  undefined8 *puVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar3;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
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
  *(undefined4 *)((int)register0x00000038 + 0x44) = param_1;
  puVar2 = &unk_F0131790;
  dword_F013178C = _nofault;
  _nofault = &unk_F0131790;
  _setjmp();
  if (puVar2 == (undefined8 *)0x0) {
    wVar1 = **(word **)((int)register0x00000038 + 0x44);
    *(int *)((int)register0x00000038 + -0xc) = (int)(sword)wVar1;
    uVar3 = (uint)wVar1;
  }
  else {
    uVar3 = 0xffffffff;
  }
  _nofault = (undefined8 *)dword_F013178C;
  return CONCAT44(param_2,uVar3);
}
/* GHIDRADEC_FUNCTION index=2678 start=0xf00b2640 */

/* WARNING: Removing unreachable block (ram,0xf00b2660) */

undefined8 _peekc(undefined4 param_1,undefined4 param_2)

{
  byte bVar1;
  undefined8 *puVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar3;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
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
  *(undefined4 *)((int)register0x00000038 + 0x44) = param_1;
  puVar2 = &unk_F0131790;
  dword_F013178C = _nofault;
  _nofault = &unk_F0131790;
  _setjmp();
  if (puVar2 == (undefined8 *)0x0) {
    bVar1 = **(byte **)((int)register0x00000038 + 0x44);
    *(int *)((int)register0x00000038 + -0xc) = (int)(char)bVar1;
    uVar3 = (uint)bVar1;
  }
  else {
    uVar3 = 0xffffffff;
  }
  _nofault = (undefined8 *)dword_F013178C;
  return CONCAT44(param_2,uVar3);
}
/* GHIDRADEC_FUNCTION index=2679 start=0xf00b26a8 */

/* WARNING: Removing unreachable block (ram,0xf00b26cc) */

undefined8 _peekl(undefined4 param_1,undefined4 param_2)

{
  undefined8 *puVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar2;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
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
  *(undefined4 *)((int)register0x00000038 + 0x44) = param_1;
  *(undefined4 *)((int)register0x00000038 + 0x48) = param_2;
  puVar1 = &unk_F0131790;
  dword_F013178C = _nofault;
  _nofault = &unk_F0131790;
  _setjmp();
  if (puVar1 == (undefined8 *)0x0) {
    **(undefined4 **)((int)register0x00000038 + 0x48) =
         **(undefined4 **)((int)register0x00000038 + 0x44);
    uVar2 = 0;
  }
  else {
    uVar2 = 0xffffffff;
  }
  _nofault = (undefined8 *)dword_F013178C;
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=2680 start=0xf00b2718 */

/* WARNING: Removing unreachable block (ram,0xf00b2768) */
/* WARNING: Removing unreachable block (ram,0xf00b273c) */

undefined8 _pokel(undefined4 param_1,undefined4 param_2)

{
  undefined8 *puVar1;
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
  *(undefined4 *)((int)register0x00000038 + 0x44) = param_1;
  *(undefined4 *)((int)register0x00000038 + 0x48) = param_2;
  puVar1 = &unk_F0131790;
  dword_F013178C = _nofault;
  _nofault = &unk_F0131790;
  _setjmp();
  uVar2 = 1;
  if (puVar1 == (undefined8 *)0x0) {
    _pokefault = -1;
    **(undefined4 **)((int)register0x00000038 + 0x44) =
         *(undefined4 *)((int)register0x00000038 + 0x48);
    _flush_writebuffers_to(*(undefined4 *)((int)register0x00000038 + 0x44));
    uVar2 = (uint)(_pokefault == 1);
  }
  _pokefault = 0;
  _nofault = (undefined8 *)dword_F013178C;
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=2681 start=0xf00b27a0 */

/* WARNING: Removing unreachable block (ram,0xf00b27f0) */
/* WARNING: Removing unreachable block (ram,0xf00b27c4) */

undefined8 _poke(undefined4 param_1,undefined4 param_2)

{
  undefined8 *puVar1;
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
  *(undefined4 *)((int)register0x00000038 + 0x44) = param_1;
  *(sword *)((int)register0x00000038 + -10) = (sword)param_2;
  puVar1 = &unk_F0131790;
  dword_F013178C = _nofault;
  _nofault = &unk_F0131790;
  _setjmp();
  uVar2 = 1;
  if (puVar1 == (undefined8 *)0x0) {
    _pokefault = -1;
    **(undefined2 **)((int)register0x00000038 + 0x44) =
         *(undefined2 *)((int)register0x00000038 + -10);
    _flush_writebuffers_to(*(undefined4 *)((int)register0x00000038 + 0x44));
    uVar2 = (uint)(_pokefault == 1);
  }
  _pokefault = 0;
  _nofault = (undefined8 *)dword_F013178C;
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=2682 start=0xf00b2828 */

/* WARNING: Removing unreachable block (ram,0xf00b2878) */
/* WARNING: Removing unreachable block (ram,0xf00b284c) */

undefined8 _pokec(undefined4 param_1,undefined4 param_2)

{
  undefined8 *puVar1;
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
  *(undefined4 *)((int)register0x00000038 + 0x44) = param_1;
  *(char *)((int)register0x00000038 + -9) = (char)param_2;
  puVar1 = &unk_F0131790;
  dword_F013178C = _nofault;
  _nofault = &unk_F0131790;
  _setjmp();
  uVar2 = 1;
  if (puVar1 == (undefined8 *)0x0) {
    _pokefault = -1;
    **(undefined **)((int)register0x00000038 + 0x44) = *(undefined *)((int)register0x00000038 + -9);
    _flush_writebuffers_to(*(undefined4 *)((int)register0x00000038 + 0x44));
    uVar2 = (uint)(_pokefault == 1);
  }
  _pokefault = 0;
  _nofault = (undefined8 *)dword_F013178C;
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=2683 start=0xf00b28b0 */

/* WARNING: Removing unreachable block (ram,0xf00b2a34) */
/* WARNING: Removing unreachable block (ram,0xf00b2970) */
/* WARNING: Removing unreachable block (ram,0xf00b2928) */
/* WARNING: Removing unreachable block (ram,0xf00b28ec) */
/* WARNING: Removing unreachable block (ram,0xf00b28e0) */
/* WARNING: Removing unreachable block (ram,0xf00b291c) */
/* WARNING: Removing unreachable block (ram,0xf00b2934) */
/* WARNING: Removing unreachable block (ram,0xf00b29d8) */
/* WARNING: Removing unreachable block (ram,0xf00b2a6c) */
/* WARNING: Removing unreachable block (ram,0xf00b28c8) */
/* WARNING: Removing unreachable block (ram,0xf00b2ab4) */

int * _getmemlist(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  undefined4 unaff_l0;
  uint uVar7;
  int *piVar8;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  int iVar9;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar10;
  bool bVar11;
  bool bVar12;
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
  if (dword_F011DD24 == (int *)0x0) {
    dword_F011DD24 = (int *)_prom_alloc();
    dword_F0131798 = 0x1000;
  }
  _prom_nextnode(0);
  iVar3 = _searchpromtree();
  if (iVar3 != 0) {
    if (dword_F011DD20 != 0) {
      _printf(aFoundSSAtNodeX);
    }
    uVar4 = _getproplen(iVar3);
    iVar5 = .udiv();
    if (iVar5 != 0) {
      uVar7 = iVar5 * 0x18;
      if (dword_F0131798 < uVar7) {
        _panic(aMemlistsTooBig);
      }
      for (; piVar1 = dword_F011DD24, 0 < (int)uVar7; uVar7 = uVar7 - 1) {
        uRam00000000 = 0;
      }
      dword_F0131798 = dword_F0131798 + iVar5 * -0x18;
      dword_F011DD24 = dword_F011DD24 + iVar5 * 6;
      if (dword_F0131798 < uVar4) {
        _panic(aMemlistsTooBig_0);
      }
      piVar8 = dword_F011DD24;
      if (0 < (int)uVar4) {
        *(undefined *)dword_F011DD24 = 0;
      }
      iVar9 = 0;
      dword_F0131798 = dword_F0131798 - uVar4;
      dword_F011DD24 = (int *)((int)dword_F011DD24 + uVar4);
      _prom_getprop(iVar3);
      if (0 < iVar5) {
        do {
          if (dword_F011DD20 != 0) {
            _printf(aChunkDAddrXBus);
          }
          if (*piVar8 == 0) {
            iVar3 = 0;
            bVar12 = false;
            bVar11 = iVar9 == 0;
            bVar10 = iVar9 < 0;
            if (0 < iVar9) {
              piVar6 = piVar1;
              do {
                if (*piVar6 != 0) break;
                bVar12 = SBORROW4(iVar9,iVar3);
                bVar11 = iVar9 == iVar3;
                bVar10 = iVar9 - iVar3 < 0;
                if ((uint)piVar8[1] < (uint)piVar6[1]) goto loc_F00B2AE0;
                iVar3 = iVar3 + 1;
                piVar6 = piVar6 + 6;
              } while (iVar3 < iVar9);
              bVar12 = SBORROW4(iVar9,iVar3);
              bVar11 = iVar9 == iVar3;
              bVar10 = iVar9 - iVar3 < 0;
            }
loc_F00B2AE0:
            if (!bVar11 && bVar10 == bVar12) {
              piVar6 = piVar1 + iVar9 * 6;
              iVar2 = iVar9;
              do {
                iVar2 = iVar2 + -1;
                *(undefined8 *)piVar6 = *(undefined8 *)(piVar6 + -6);
                *(undefined8 *)(piVar6 + 2) = *(undefined8 *)(piVar6 + -4);
                *(undefined8 *)(piVar6 + 4) = *(undefined8 *)(piVar6 + -2);
                piVar6 = piVar6 + -6;
              } while (iVar3 < iVar2);
            }
            *(qword *)(piVar1 + iVar3 * 6) = (qword)(uint)piVar8[1];
            *(qword *)(piVar1 + iVar3 * 6 + 2) = (qword)(uint)piVar8[2];
          }
          iVar9 = iVar9 + 1;
          piVar8 = piVar8 + 3;
        } while (iVar9 < iVar5);
      }
      iVar3 = 1;
      piVar8 = piVar1;
      if (iVar5 < 2) {
        return piVar1;
      }
      do {
        piVar6 = piVar8 + 6;
        if (*piVar6 == 0) {
          if (piVar8[7] != 0) {
            piVar8[4] = (int)piVar6;
          }
        }
        else {
          piVar8[4] = (int)piVar6;
        }
        iVar3 = iVar3 + 1;
        piVar8 = piVar6;
      } while (iVar3 < iVar5);
      return piVar1;
    }
  }
  return (int *)0x0;
}
/* GHIDRADEC_FUNCTION index=2684 start=0xf00b2bac */

/* WARNING: Removing unreachable block (ram,0xf00b2c08) */
/* WARNING: Removing unreachable block (ram,0xf00b2be0) */
/* WARNING: Removing unreachable block (ram,0xf00b2bcc) */
/* WARNING: Removing unreachable block (ram,0xf00b2bf4) */
/* WARNING: Removing unreachable block (ram,0xf00b2c1c) */
/* WARNING: Removing unreachable block (ram,0xf00b2bc0) */

undefined8 _searchpromtree(int param_1,undefined4 param_2,undefined *param_3)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar1;
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
  *param_3 = 0;
  _prom_getprop(param_1,&aName_2,param_3);
  _strcmp(param_3,param_2);
  iVar1 = param_1;
  if (((param_3 != (undefined *)0x0) &&
      ((_prom_nextnode(), iVar1 == 0 || (_searchpromtree(), iVar1 == 0)))) &&
     ((_prom_childnode(), param_1 == 0 || (_searchpromtree(), iVar1 = param_1, param_1 == 0)))) {
    iVar1 = 0;
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=2685 start=0xf00b2c3c */

/* WARNING: Removing unreachable block (ram,0xf00b2c60) */

undefined8 _path_getdecodefunc(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined *puVar1;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar2;
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
  puVar1 = _dev_path_opstab;
  do {
    if (param_1 == 0) {
      iVar2 = 0;
locret_F00B2C88:
      return CONCAT44(param_2,iVar2);
    }
    if (*(int *)puVar1 == 0) {
      iVar2 = 0;
      goto locret_F00B2C88;
    }
    iVar2 = *(int *)(param_1 + 0xc);
    _strcmp();
    if (iVar2 == 0) {
      iVar2 = *(int *)((int)puVar1 + 4);
      goto locret_F00B2C88;
    }
    puVar1 = (undefined *)((int)puVar1 + 0x10);
  } while( true );
}
/* GHIDRADEC_FUNCTION index=2686 start=0xf00b2c90 */

/* WARNING: Removing unreachable block (ram,0xf00b2cd4) */
/* WARNING: Removing unreachable block (ram,0xf00b2cac) */

undefined8 _path_getencodefunc(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined *puVar1;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar2;
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
  if (dword_F011DDA0 != 0) {
    _printf(aPathGetencodef,*(undefined4 *)(param_1 + 0xc));
  }
  puVar1 = _dev_path_opstab;
  do {
    if (param_1 == 0) {
      iVar2 = 0;
locret_F00B2CFC:
      return CONCAT44(param_2,iVar2);
    }
    if (*(int *)puVar1 == 0) {
      iVar2 = 0;
      goto locret_F00B2CFC;
    }
    iVar2 = *(int *)(param_1 + 0xc);
    _strcmp();
    if (iVar2 == 0) {
      iVar2 = *(int *)((int)puVar1 + 8);
      goto locret_F00B2CFC;
    }
    puVar1 = (undefined *)((int)puVar1 + 0x10);
  } while( true );
}
/* GHIDRADEC_FUNCTION index=2687 start=0xf00b2d04 */

/* WARNING: Removing unreachable block (ram,0xf00b2d28) */

undefined8 _path_getmatchfunc(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined *puVar1;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar2;
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
  puVar1 = _dev_path_opstab;
  do {
    if (param_1 == 0) {
      iVar2 = 0;
locret_F00B2D50:
      return CONCAT44(param_2,iVar2);
    }
    if (*(int *)puVar1 == 0) {
      iVar2 = 0;
      goto locret_F00B2D50;
    }
    iVar2 = *(int *)(param_1 + 0xc);
    _strcmp();
    if (iVar2 == 0) {
      iVar2 = *(int *)((int)puVar1 + 0xc);
      goto locret_F00B2D50;
    }
    puVar1 = (undefined *)((int)puVar1 + 0x10);
  } while( true );
}
/* GHIDRADEC_FUNCTION index=2688 start=0xf00b2ef0 */

/* WARNING: Removing unreachable block (ram,0xf00b2fc8) */
/* WARNING: Removing unreachable block (ram,0xf00b2f88) */
/* WARNING: Removing unreachable block (ram,0xf00b2f64) */
/* WARNING: Removing unreachable block (ram,0xf00b2fa4) */
/* WARNING: Removing unreachable block (ram,0xf00b2fd8) */
/* WARNING: Removing unreachable block (ram,0xf00b2f44) */

undefined8 _path_to_devi(char *param_1,undefined4 param_2)

{
  char cVar1;
  char cVar2;
  undefined4 unaff_l0;
  undefined *puVar3;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined *puVar4;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  puVar4 = _top_devinfo;
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
  if (param_1 == (char *)0x0) {
    puVar4 = (undefined *)0x0;
  }
  else {
    for (; (*param_1 != '\0' && (*param_1 == '/')); param_1 = param_1 + 1) {
    }
    if (dword_F011DDA0 != 0) {
      _printf(aPathS,param_1);
    }
    if (*param_1 != '\0') {
      puVar3 = puVar4;
      do {
        sub_F00B2D58(param_1,(undefined *)((int)register0x00000038 + -0x88));
        if (dword_F011DDA0 != 0) {
          _printf(aNameSRemainder,(undefined *)((int)register0x00000038 + -0x88),param_1);
        }
        if (*param_1 == '@') {
          param_1 = param_1 + 1;
          sub_F00B2D58(param_1,(undefined *)((int)register0x00000038 + -0x108));
        }
        else {
          *(undefined *)((int)register0x00000038 + -0x108) = 0;
        }
        if (dword_F011DDA0 != 0) {
          _printf(aAddrspecSRemai,(undefined *)((int)register0x00000038 + -0x108),param_1);
        }
        puVar4 = (undefined *)((int)register0x00000038 + -0x88);
        sub_F00B2E94(puVar4,(undefined *)((int)register0x00000038 + -0x108),puVar3);
        if (puVar4 == (undefined *)0x0) break;
        cVar1 = *param_1;
        while ((cVar2 = *param_1, cVar1 != '\0' && (param_1 = param_1 + 1, cVar2 != '/'))) {
          cVar1 = *param_1;
        }
        puVar3 = puVar4;
      } while (*param_1 != '\0');
    }
  }
  return CONCAT44(param_2,puVar4);
}
/* GHIDRADEC_FUNCTION index=2689 start=0xf00b302c */

/* WARNING: Removing unreachable block (ram,0xf00b3030) */

undefined8 _path_to_nodeid(int param_1,undefined4 param_2)

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
  _path_to_devi();
  uVar1 = 0xffffffff;
  if (param_1 != 0) {
    uVar1 = *(undefined4 *)(param_1 + 0x28);
  }
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=2690 start=0xf00b3050 */

undefined8 _path_to_subdev(byte *param_1,undefined4 param_2)

{
  byte bVar1;
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
  bVar1 = *param_1;
  while( true ) {
    param_1 = param_1 + 1;
    if (bVar1 == 0) break;
    if ((int)((uint)bVar1 * 0x1000000) >> 0x18 == 0x3a) goto locret_F00B3084;
    bVar1 = *param_1;
  }
  param_1 = (byte *)0x0;
locret_F00B3084:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2691 start=0xf00b308c */

/* WARNING: Removing unreachable block (ram,0xf00b309c) */

undefined8 _get_part_from_path(char *param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar1;
  char *pcVar2;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  char *pcVar3;
  
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
  iVar1 = 0;
  if (param_1 != (char *)0x0) {
    pcVar2 = param_1;
    _strlen();
    pcVar2 = param_1 + (int)pcVar2;
    do {
      pcVar3 = pcVar2;
      pcVar2 = pcVar3 + -1;
      if (pcVar2 == param_1) break;
    } while (*pcVar2 != ':');
    if ((pcVar2 == param_1) || (iVar1 = (int)*pcVar3, iVar1 == 0)) {
      iVar1 = 0;
    }
    else if ((iVar1 - 0x61U & 0xff) < 0x1a) {
      iVar1 = iVar1 + -0x61;
    }
    else if ((iVar1 - 0x30U & 0xff) < 10) {
      iVar1 = iVar1 + -0x30;
    }
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=2692 start=0xf00b31b0 */

/* WARNING: Removing unreachable block (ram,0xf00b31f8) */
/* WARNING: Removing unreachable block (ram,0xf00b31e4) */

undefined8 _path_findnodebyname(undefined4 param_1,undefined4 param_2,int param_3)

{
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
  *(undefined4 *)((int)register0x00000038 + -0x18) = param_1;
  *(undefined4 *)((int)register0x00000038 + -0x10) = param_2;
  *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
  if (dword_F011DDA0 != 0) {
    _printf(aWalkTreeAtXSLo,param_3,*(undefined4 *)(param_3 + 0xc));
  }
  _walk_devs(param_3,sub_F00B3124,(undefined *)((int)register0x00000038 + -0x18));
  return CONCAT44(param_2,*(undefined4 *)((int)register0x00000038 + -0xc));
}
/* GHIDRADEC_FUNCTION index=2693 start=0xf00b320c */

/* WARNING: Removing unreachable block (ram,0xf00b3458) */
/* WARNING: Removing unreachable block (ram,0xf00b3418) */
/* WARNING: Removing unreachable block (ram,0xf00b33e8) */
/* WARNING: Removing unreachable block (ram,0xf00b3330) */
/* WARNING: Removing unreachable block (ram,0xf00b32e4) */
/* WARNING: Removing unreachable block (ram,0xf00b32c0) */
/* WARNING: Removing unreachable block (ram,0xf00b3314) */
/* WARNING: Removing unreachable block (ram,0xf00b33cc) */
/* WARNING: Removing unreachable block (ram,0xf00b33f4) */
/* WARNING: Removing unreachable block (ram,0xf00b3444) */
/* WARNING: Removing unreachable block (ram,0xf00b3478) */
/* WARNING: Removing unreachable block (ram,0xf00b3274) */

undefined8 _devi_to_path(int *param_1,undefined4 param_2)

{
  code *pcVar1;
  char cVar2;
  undefined6 *puVar3;
  undefined *puVar4;
  int iVar5;
  undefined4 unaff_l0;
  int *piVar6;
  undefined4 unaff_l1;
  int *piVar7;
  int *piVar8;
  undefined4 unaff_l3;
  char cVar9;
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
  iVar5 = 0;
  piVar6 = param_1;
  if (*(char *)param_1 != '\0') {
    cVar9 = *(char *)param_1;
    do {
      if (cVar9 < ':') goto loc_F00B3258;
      piVar6 = (int *)((int)piVar6 + 1);
      cVar9 = *(char *)piVar6;
    } while (cVar9 != '\0');
  }
  cVar9 = *(char *)piVar6;
loc_F00B3258:
  cVar2 = *(char *)piVar6;
  while ((cVar9 != '\0' && ((byte)(cVar2 - 0x30U) < 10))) {
    .umul(iVar5,10);
    *(char *)piVar6 = '\0';
    piVar6 = (int *)((int)piVar6 + 1);
    cVar9 = *(char *)piVar6;
    iVar5 = iVar5 + -0x30 + (int)cVar2;
    cVar2 = *(char *)piVar6;
  }
  cVar9 = '\0';
  if (*(char *)piVar6 != '\0') {
    cVar9 = *(char *)piVar6;
  }
  piVar6 = param_1;
  _path_findnodebyname(param_1,iVar5,_top_devinfo);
  if (dword_F011DDA0 != 0) {
    _printf(aPathToDeviPath,piVar6);
  }
  *(char *)param_1 = '\0';
  if (piVar6 != (int *)0x0) {
    if (dword_F011DDA0 == 0) {
      piVar7 = (int *)*piVar6;
    }
    else {
      _printf(aPathToDeviDevi,piVar6[3],*piVar6);
      piVar7 = (int *)*piVar6;
    }
    if (piVar7 != (int *)0x0) {
      do {
        pcVar1 = (code *)*piVar6;
        _path_getencodefunc();
        if (pcVar1 == (code *)0x0) {
          pcVar1 = _obio_encode_reg;
        }
        piVar8 = piVar6;
        (*pcVar1)(piVar6,(undefined *)((int)register0x00000038 + -0x208));
        if (piVar8 != (int *)0xffffffff) {
          if (piVar8 < (int *)0x80000000) {
            cVar2 = *(char *)((int)register0x00000038 + -0x208);
            if (piVar8 == (int *)0x0) {
              *(char *)param_1 = '\0';
              goto locret_F00B3480;
            }
loc_F00B33B4:
            if (cVar2 == '\0') {
              puVar3 = &aSS_4;
              puVar4 = (undefined *)piVar6[3];
loc_F00B33E8:
              _sprintf((undefined *)((int)register0x00000038 + -0x108),puVar3,puVar4,param_1);
            }
            else {
              _sprintf((undefined *)((int)register0x00000038 + -0x108),aSSS,piVar6[3],
                       (undefined *)((int)register0x00000038 + -0x208),param_1);
            }
          }
          else {
            cVar2 = *(char *)((int)register0x00000038 + -0x208);
            if (piVar8 != (int *)0xfffffffe) goto loc_F00B33B4;
            if (cVar2 != '\0') {
              puVar3 = &aSS_3;
              puVar4 = (undefined *)((int)register0x00000038 + -0x208);
              goto loc_F00B33E8;
            }
          }
          _strcpy(param_1,(undefined *)((int)register0x00000038 + -0x108));
          if (dword_F011DDA0 != 0) {
            _printf(aNameS,param_1);
          }
        }
        piVar8 = (int *)*piVar7;
        piVar6 = piVar7;
        piVar7 = piVar8;
      } while (piVar8 != (int *)0x0);
    }
    if (cVar9 != 0) {
      piVar6 = param_1;
      _strlen(param_1);
      _sprintf((char *)((int)param_1 + (int)piVar6),&aC_1,(int)cVar9);
    }
    if (dword_F011DDA0 != 0) {
      _printf(aNameS_0,param_1);
    }
  }
locret_F00B3480:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2694 start=0xf00b3520 */

/* WARNING: Removing unreachable block (ram,0xf00b363c) */
/* WARNING: Removing unreachable block (ram,0xf00b3600) */
/* WARNING: Removing unreachable block (ram,0xf00b35c0) */
/* WARNING: Removing unreachable block (ram,0xf00b35ac) */
/* WARNING: Removing unreachable block (ram,0xf00b35e8) */
/* WARNING: Removing unreachable block (ram,0xf00b3618) */
/* WARNING: Removing unreachable block (ram,0xf00b3594) */
/* WARNING: Removing unreachable block (ram,0xf00b3540) */

undefined8 _obio_encode_reg(int *param_1,undefined *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar3;
  undefined4 uVar4;
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
  if (dword_F011DFB8 != 0) {
    _printf(aObioEncodeRegE,param_1[3]);
  }
  if ((param_2 != (undefined *)0x0) && (*param_2 = 0, param_1 != (int *)0x0)) {
    if (*param_1 == 0) {
      uVar3 = 0xffffffff;
      goto locret_F00B3648;
    }
    iVar2 = param_1[10];
    if (1 < iVar2 + 1U) {
      _getproplen(iVar2,&aReg_2);
      puVar1 = (undefined4 *)param_1[10];
      _getlongprop(puVar1,&aReg_3);
      if (puVar1 == (undefined4 *)0x0) {
        if (dword_F011DFB8 != 0) {
          _printf(aNoAddrQualifie,param_1[10]);
          uVar3 = 1;
          goto locret_F00B3648;
        }
      }
      else {
        uVar3 = *puVar1;
        uVar4 = puVar1[1];
        _kfree(puVar1,iVar2);
        _sprintf(param_2,&aXX,uVar3,uVar4);
        if (dword_F011DFB8 != 0) {
          _printf(aAddrXRegAddrXR,uVar4,puVar1[1],param_2);
        }
      }
      uVar3 = 1;
      goto locret_F00B3648;
    }
    if (dword_F011DFB8 != 0) {
      _printf(aObioEncodeRegI,param_1[3]);
    }
  }
  uVar3 = 0;
locret_F00B3648:
  return CONCAT44(param_2,uVar3);
}
/* GHIDRADEC_FUNCTION index=2695 start=0xf00b3650 */

/* WARNING: Removing unreachable block (ram,0xf00b373c) */
/* WARNING: Removing unreachable block (ram,0xf00b36b4) */
/* WARNING: Removing unreachable block (ram,0xf00b368c) */
/* WARNING: Removing unreachable block (ram,0xf00b36a0) */
/* WARNING: Removing unreachable block (ram,0xf00b3710) */
/* WARNING: Removing unreachable block (ram,0xf00b36dc) */
/* WARNING: Removing unreachable block (ram,0xf00b3654) */

undefined8 _obio_match(int param_1,char *param_2)

{
  char cVar1;
  char cVar2;
  char *pcVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar6;
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
  pcVar3 = param_2;
  _atou();
  cVar1 = *param_2;
  cVar2 = *param_2;
  while ((cVar1 != '\0' && (param_2 = param_2 + 1, cVar2 != ','))) {
    cVar1 = *param_2;
    cVar2 = *param_2;
  }
  _atou(param_2);
  uVar4 = *(undefined4 *)(param_1 + 0x28);
  _getproplen(uVar4,&aReg_4);
  puVar5 = *(undefined4 **)(param_1 + 0x28);
  _getlongprop(puVar5,&aReg_5);
  if (puVar5 == (undefined4 *)0x0) {
    if (dword_F011DFB8 != 0) {
      _printf(aNoAddrQualifie_0,*(undefined4 *)(param_1 + 0x28));
    }
    uVar6 = 0;
  }
  else {
    if (dword_F011DFB8 != 0) {
      _printf(aBustypeDAddrXR,pcVar3,param_2,**(undefined4 **)(param_1 + 0x14),
              (*(undefined4 **)(param_1 + 0x14))[1]);
    }
    uVar6 = 0;
    if (pcVar3 == (char *)*puVar5) {
      uVar6 = (uint)(param_2 == (char *)puVar5[1]);
    }
    _kfree(puVar5,uVar4);
  }
  return CONCAT44(puVar5,uVar6);
}
/* GHIDRADEC_FUNCTION index=2696 start=0xf00b374c */

/* WARNING: Removing unreachable block (ram,0xf00b3770) */
/* WARNING: Removing unreachable block (ram,0xf00b3758) */

undefined8 _esp_identify(int param_1,undefined4 param_2)

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
  undefined4 uVar2;
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
  iVar1 = param_1;
  _strcmp(param_1,&unk_F011E2B0);
  if (iVar1 != 0) {
    _strcmp(param_1,aSunwEsp);
    uVar2 = 0;
    if (param_1 != 0) goto locret_F00B3798;
  }
  uVar2 = 1;
  _nesp = _nesp + 1;
locret_F00B3798:
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=2697 start=0xf00b37a0 */

/* WARNING: Removing unreachable block (ram,0xf00b38ec) */
/* WARNING: Removing unreachable block (ram,0xf00b38d0) */
/* WARNING: Removing unreachable block (ram,0xf00b3da0) */
/* WARNING: Removing unreachable block (ram,0xf00b3d70) */
/* WARNING: Removing unreachable block (ram,0xf00b3cb8) */
/* WARNING: Removing unreachable block (ram,0xf00b3c20) */
/* WARNING: Removing unreachable block (ram,0xf00b3b64) */
/* WARNING: Removing unreachable block (ram,0xf00b3a68) */
/* WARNING: Removing unreachable block (ram,0xf00b3a44) */
/* WARNING: Removing unreachable block (ram,0xf00b3a14) */
/* WARNING: Removing unreachable block (ram,0xf00b39e0) */
/* WARNING: Removing unreachable block (ram,0xf00b3968) */
/* WARNING: Removing unreachable block (ram,0xf00b3880) */
/* WARNING: Removing unreachable block (ram,0xf00b385c) */
/* WARNING: Removing unreachable block (ram,0xf00b380c) */
/* WARNING: Removing unreachable block (ram,0xf00b3870) */
/* WARNING: Removing unreachable block (ram,0xf00b3924) */
/* WARNING: Removing unreachable block (ram,0xf00b39b0) */
/* WARNING: Removing unreachable block (ram,0xf00b3a04) */
/* WARNING: Removing unreachable block (ram,0xf00b3a3c) */
/* WARNING: Removing unreachable block (ram,0xf00b3a58) */
/* WARNING: Removing unreachable block (ram,0xf00b3b44) */
/* WARNING: Removing unreachable block (ram,0xf00b3b8c) */
/* WARNING: Removing unreachable block (ram,0xf00b3cac) */
/* WARNING: Removing unreachable block (ram,0xf00b3cc0) */
/* WARNING: Removing unreachable block (ram,0xf00b3d94) */
/* WARNING: Removing unreachable block (ram,0xf00b3da8) */
/* WARNING: Removing unreachable block (ram,0xf00b38e4) */
/* WARNING: Removing unreachable block (ram,0xf00b3828) */
/* WARNING: Removing unreachable block (ram,0xf00b37e8) */

undefined8
_esp_attach(int *param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  uint *puVar2;
  int *piVar3;
  char cVar5;
  int iVar4;
  byte bVar6;
  undefined uVar7;
  uint uVar8;
  int *piVar9;
  undefined4 *puVar10;
  undefined *puVar11;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar12;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar13;
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
  iVar12 = 0;
  bVar14 = 0 < _nesp;
  param_1[0xb] = 0;
  if (bVar14) {
    if (2 < param_1[4]) {
      uVar13 = 0xffffffff;
      goto locret_F00B3DB4;
    }
    if (param_1[6] == 0) {
      uVar13 = 0xffffffff;
      goto locret_F00B3DB4;
    }
    puVar10 = (undefined4 *)param_1[5];
    iVar1 = puVar10[1];
    _map_regs(iVar1,puVar10[2],*puVar10);
    if (iVar1 == 0) {
      puVar11 = aEspDUnableToMa;
    }
    else {
      puVar2 = *(uint **)param_1[5];
      _dma_alloc(puVar2,((int *)param_1[5])[1]);
      if (puVar2 != (uint *)0x0) {
        if (*puVar2 >> 0x1c == 4) {
          *puVar2 = *puVar2 & 0xffffff7f;
          uVar8 = *puVar2;
        }
        else {
          uVar8 = *puVar2;
        }
        piVar3 = (int *)0x1b8;
        *puVar2 = uVar8 & 0xfffffeff;
        _kalloc();
        iVar4 = iRam00000048;
        if (piVar3 != (int *)0x0) {
          _bzero();
          iVar4 = _iopbmap;
          _rmalloc(_iopbmap,0x10);
          piVar3[0x12] = iVar4;
          iVar4 = piVar3[0x12];
          if (piVar3 != (int *)0x0) {
            if (piVar3[0x12] != 0) {
              *(undefined *)(piVar3 + 0xc) = 0;
              piVar9 = _esp_softc;
              bVar14 = _esp_softc == (int *)0x0;
              piVar3[10] = 0;
              if (bVar14) {
                _esp_softc = piVar3;
                _timeout(_esp_watch,0,_hz);
              }
              else {
                for (; piVar9[10] != 0; piVar9 = (int *)piVar9[10]) {
                }
                piVar9[10] = (int)piVar3;
              }
              if (param_1 != (int *)0x0) {
                iVar12 = param_1[10];
                piVar9 = param_1;
                while (((_getprop(iVar12,DAT_f011e308._0_4_,0xffffffff), iVar12 < 1 &&
                        (piVar9 != _top_devinfo)) && (piVar9 = (int *)*piVar9, piVar9 != (int *)0x0)
                       )) {
                  iVar12 = piVar9[10];
                }
              }
              if (iVar12 < 0x4c4b41) {
                param_2 = 0;
              }
              else {
                param_2 = iVar12 + 4999999;
                .div();
              }
              if (6 < (param_2 - 2 & 0xff)) {
                _esplog(piVar3,3,aBadClockFreque);
                *(undefined *)((int)piVar3 + 0x7a) = 0xff;
                param_2 = 4;
                iVar12 = 20000000;
              }
              *(char *)((int)piVar3 + 0x3d) = (char)param_2;
              .div(iVar12,1000);
              uVar8 = 1000000000;
              .div(1000000000,iVar12);
              *(sword *)((int)piVar3 + 0x3e) = (sword)uVar8;
              cVar5 = *(char *)((int)piVar3 + 0x3d);
              .umul(cVar5,(uVar8 & 0xffff) * 0x1e02);
              .div();
              cVar5 = cVar5 + '\x7f';
              .udiv();
              *(char *)(piVar3 + 0x10) = cVar5;
              iVar4 = *(int *)param_1[7];
              _ipltospl();
              piVar3[0x2d] = iVar4;
              piVar9 = _esp_softc;
              iVar12 = 0;
              if (0 < iVar4) {
                iVar12 = iVar4;
              }
              if (_esp_softc != (int *)0x0) {
                *_esp_softc = iVar12;
                while (piVar9 = (int *)piVar9[10], piVar9 != (int *)0x0) {
                  *piVar9 = iVar12;
                }
              }
              piVar3[1] = (int)_esp_start;
              piVar3[3] = (int)_esp_abort;
              piVar3[2] = (int)_esp_reset;
              piVar3[4] = (int)_esp_getcap;
              piVar3[5] = (int)_esp_setcap;
              piVar3[6] = (int)_scsi_std_pktalloc;
              piVar3[7] = (int)_scsi_std_dmaget;
              piVar3[8] = (int)_scsi_std_pktfree;
              piVar3[9] = (int)_scsi_std_dmafree;
              piVar3[0xb] = (int)param_1;
              *(undefined *)((int)piVar3 + 0x32) = 7;
              if (param_1 != (int *)0x0) {
                uVar8 = param_1[10];
                piVar9 = param_1;
                while( true ) {
                  _getprop(uVar8,DAT_f011e2d8._0_4_,0xffffffff);
                  if (uVar8 == 0xffffffff) {
                    uVar8 = piVar9[10];
                    _getprop(uVar8,DAT_f011e2d8._28_4_,0xffffffff);
                  }
                  if ((uVar8 != 7) && (uVar8 < 8)) {
                    _esplog(piVar3,6,aInitiatorScsiI,uVar8);
                    *(char *)((int)piVar3 + 0x32) = (char)uVar8;
                  }
                  if (((uVar8 < 0x80000000) || (piVar9 == _top_devinfo)) ||
                     (piVar9 = (int *)*piVar9, piVar9 == (int *)0x0)) break;
                  uVar8 = piVar9[10];
                }
              }
              if ((_scsi_options & 0x40) == 0) {
                piVar3[0x27] = iVar1;
              }
              else {
                *(byte *)((int)piVar3 + 0x32) = *(byte *)((int)piVar3 + 0x32) | 0x10;
                piVar3[0x27] = iVar1;
              }
              piVar3[0x28] = (int)puVar2;
              piVar9 = (int *)piVar3[0xb];
              *(byte *)((int)piVar3 + 0x32) =
                   *(byte *)((int)piVar3 + 0x32) | (byte)_espconf & 0xf8 | 0x40;
              *(undefined *)(piVar3 + 0x1f) = 0xff;
              iVar12 = piVar9[10];
              while( true ) {
                _getprop(iVar12,DAT_f011e308._20_4_,0xffffffff);
                if (iVar12 == -1) {
                  piVar9 = (int *)*piVar9;
                }
                else {
                  *(byte *)(piVar3 + 0x1f) = *(byte *)(piVar3 + 0x1f) & (byte)iVar12;
                  piVar9 = (int *)*piVar9;
                }
                if (piVar9 == _top_devinfo) break;
                iVar12 = piVar9[10];
              }
              if ((*(byte *)(piVar3 + 0x1f) == 0xff) || ((*(byte *)(piVar3 + 0x1f) & 0x30) == 0)) {
                *(undefined *)(piVar3 + 0x1f) = 0x1f;
              }
              piVar3[0x2b] = -0x100000;
              *(undefined2 *)((int)piVar3 + 0xb2) = 0xffff;
              *(undefined2 *)(piVar3 + 0x2c) = 0xffff;
              _addintr(*(undefined4 *)param_1[7],_esp_poll,param_1[3],param_1[0xb],param_4,param_5);
              _adddma(*(undefined4 *)param_1[7]);
              _report_dev(param_1);
              *(undefined *)(iVar1 + 0x2c) = 10;
              *(undefined *)((int)piVar3 + 0x76) = 0x2d;
              if ((*(byte *)(iVar1 + 0x2c) & 0xf) == 10) {
                *(char *)((int)piVar3 + 0x33) = (char)_espconf2;
                *(undefined *)(iVar1 + 0x30) = 5;
                iVar12 = 0;
                do {
                  iVar4 = iVar12 + 1;
                  *(char *)((int)piVar3 + iVar12 + 0x34) = (char)_espconf3;
                  iVar12 = iVar4;
                } while (iVar4 < 8);
                if ((param_2 & 0xff) < 6) {
                  *(byte *)(iVar1 + 0x2c) = *(byte *)((int)piVar3 + 0x33);
                  uVar7 = 2;
                }
                else {
                  bVar6 = *(byte *)((int)piVar3 + 0x33) | 0x40;
                  *(byte *)((int)piVar3 + 0x33) = bVar6;
                  *(byte *)(iVar1 + 0x2c) = bVar6;
                  *(undefined *)((int)piVar3 + 0x76) = 0x19;
                  uVar7 = 5;
                }
                *(undefined *)((int)piVar3 + 0x31) = uVar7;
                *(char *)(iVar1 + 0x30) = (char)_espconf3;
              }
              else {
                *(undefined *)((int)piVar3 + 0x31) = 0;
              }
              iVar12 = param_1[10];
              _getprop(iVar12,off_F011E330,0xffffffff);
              if (iVar12 != -1) {
                *(char *)(piVar3 + 0xf) = *(char *)(piVar3 + 0xf) + '\x01';
              }
              _esp_internal_reset(piVar3,0x1f);
              _scsi_config(piVar3,param_1);
              _scsa_config(piVar3);
              uVar13 = 0;
              goto locret_F00B3DB4;
            }
            iVar4 = piVar3[0x12];
          }
        }
        if (iVar4 == 0) {
          puVar11 = aDataStructures;
        }
        else {
          puVar11 = aCmdAreas;
        }
        _printf(aEspDNoSpaceFor,0,puVar11);
        if (piVar3 != (int *)0x0) {
          _kfree(piVar3,0x1b8);
        }
        _dma_free(puVar2);
        uVar13 = 0xffffffff;
        goto locret_F00B3DB4;
      }
      puVar11 = aEspDCannotFind;
    }
    _printf(puVar11,0);
  }
  uVar13 = 0xffffffff;
locret_F00B3DB4:
  return CONCAT44(param_2,uVar13);
}
/* GHIDRADEC_FUNCTION index=2698 start=0xf00b3dbc */

/* WARNING: Removing unreachable block (ram,0xf00b3eac) */
/* WARNING: Removing unreachable block (ram,0xf00b3ea4) */
/* WARNING: Removing unreachable block (ram,0xf00b3e60) */
/* WARNING: Removing unreachable block (ram,0xf00b3e98) */
/* WARNING: Removing unreachable block (ram,0xf00b3e44) */
/* WARNING: Removing unreachable block (ram,0xf00b3e1c) */

undefined8 _esp_start(int param_1,undefined4 param_2)

{
  byte bVar1;
  sword sVar2;
  uint uVar3;
  undefined4 unaff_l0;
  undefined4 *puVar4;
  undefined4 unaff_l1;
  int iVar5;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar6;
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
  sVar2 = *(sword *)(param_1 + 8);
  bVar1 = *(byte *)(param_1 + 10);
  puVar4 = *(undefined4 **)(param_1 + 4);
  if ((*(word *)(param_1 + 0x5c) & 1) != 0) {
    if ((*(uint *)puVar4[0x28] >> 0x1c < 10) ||
       (uVar3 = 0x40000000, *(uint *)puVar4[0x28] >> 0x1c != 10)) {
      uVar3 = 0x1000000;
    }
    if (uVar3 <= *(uint *)(param_1 + 0x40)) {
      uVar6 = 0xffffffff;
      goto locret_F00B3EB8;
    }
  }
  uVar6 = *puVar4;
  _splr(uVar6);
  iVar5 = (int)(sword)((word)bVar1 | sVar2 << 3);
  if (puVar4[iVar5 + 0x2e] == 0) {
    puVar4[iVar5 + 0x2e] = param_1;
    puVar4[0x21] = puVar4[0x21] + 1;
    _esp_init_cmd(param_1);
    if ((*(uint *)(param_1 + 0x14) & 1) == 0) {
      if ((puVar4[0x20] == 0) && (*(char *)((int)puVar4 + 0x41) == '\0')) {
        _esp_ustart(puVar4,iVar5);
      }
    }
    else {
      _esp_runpoll(puVar4,iVar5);
    }
    _splx(uVar6);
    uVar6 = 1;
  }
  else {
    uVar6 = 0;
    _splx();
  }
locret_F00B3EB8:
  return CONCAT44(param_2,uVar6);
}
/* GHIDRADEC_FUNCTION index=2699 start=0xf00b3ec0 */

/* WARNING: Removing unreachable block (ram,0xf00b40b8) */
/* WARNING: Removing unreachable block (ram,0xf00b4004) */
/* WARNING: Removing unreachable block (ram,0xf00b3f0c) */
/* WARNING: Removing unreachable block (ram,0xf00b3fa8) */
/* WARNING: Removing unreachable block (ram,0xf00b400c) */
/* WARNING: Removing unreachable block (ram,0xf00b40c0) */
/* WARNING: Removing unreachable block (ram,0xf00b3ed8) */

undefined8 _esp_abort(undefined4 *param_1,undefined *param_2)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined4 unaff_l0;
  undefined4 *puVar6;
  undefined4 unaff_l1;
  word wVar7;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar8;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar9;
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
  puVar6 = (undefined4 *)*param_1;
  uVar2 = *puVar6;
  wVar7 = (word)*(byte *)((int)param_1 + 6) | *(sword *)(param_1 + 1) << 3;
  _splr(uVar2);
  if ((*(char *)((int)puVar6 + 0x41) != '\0') && (*(word *)((int)puVar6 + 0xb2) == wVar7)) {
    _splx(uVar2);
    uVar8 = 0;
    puVar4 = param_2;
    goto locret_F00B40C8;
  }
  if (param_2 == (undefined *)0x0) {
    param_2 = *(undefined **)((int)puVar6 + ((int)((uint)wVar7 << 0x10) >> 0xe) + 0xb8);
  }
  iVar3 = (int)((uint)wVar7 << 0x10) >> 0xe;
  puVar4 = *(undefined **)((int)puVar6 + iVar3 + 0xb8);
  if (puVar4 == (undefined *)0x0) {
    param_2 = (undefined *)0x0;
  }
  if (param_2 == (undefined *)0x0) {
loc_F00B3F9C:
    bVar9 = param_2 == (undefined *)0x0;
  }
  else {
    bVar9 = param_2 == (undefined *)0x0;
    if ((param_2 == puVar4) && (bVar9 = param_2 == (undefined *)0x0, param_2[0x29] == '\0')) {
      *(undefined4 *)((int)puVar6 + iVar3 + 0xb8) = 0;
      param_2[0x28] = 5;
      puVar6[0x21] = puVar6[0x21] + -1;
      (**(code **)(param_2 + 0x10))(param_2);
      param_2 = (undefined *)0x0;
      goto loc_F00B3F9C;
    }
  }
  if (bVar9) {
    _splx(uVar2);
    uVar8 = 1;
    puVar4 = param_2;
    goto locret_F00B40C8;
  }
  *(undefined4 *)((int)puVar6 + ((int)((uint)wVar7 << 0x10) >> 0xe) + 0xb8) = 0;
  bVar9 = (*(word *)(param_2 + 0x5c) & 0x10) != 0;
  if (bVar9) {
    puVar6[0x22] = puVar6[0x22] + -1;
  }
  puVar4 = (undefined *)((int)register0x00000038 + -0x78);
  puVar6[0x21] = puVar6[0x21] + -1;
  _esp_makeproxy_cmd(puVar4,param_1,6);
  puVar5 = puVar4;
  _esp_start();
  if (puVar5 == (undefined *)0x1) {
    if (*(char *)((int)register0x00000038 + -0x50) != '\0') {
      iVar3 = puVar6[0x21];
      goto loc_F00B4060;
    }
    if (*(char *)((int)register0x00000038 + -0xd) != '\x01') {
      iVar3 = puVar6[0x21];
      goto loc_F00B4060;
    }
    uVar8 = 1;
    param_2[0x28] = 5;
    (**(code **)(param_2 + 0x10))(param_2);
    cVar1 = *(char *)((int)puVar6 + 0x41);
  }
  else {
    iVar3 = puVar6[0x21];
loc_F00B4060:
    puVar6[0x21] = iVar3 + 1;
    if (bVar9) {
      puVar6[0x22] = puVar6[0x22] + 1;
      *(word *)(param_2 + 0x5c) = *(word *)(param_2 + 0x5c) | 0x10;
    }
    *(undefined **)((int)puVar6 + ((int)((uint)wVar7 << 0x10) >> 0xe) + 0xb8) = param_2;
    uVar8 = 0;
    cVar1 = *(char *)((int)puVar6 + 0x41);
  }
  if (cVar1 == '\0') {
    _esp_ustart(puVar6,(int)(sword)wVar7 + 1U & 0x3f);
  }
  _splx(uVar2);
locret_F00B40C8:
  return CONCAT44(puVar4,uVar8);
}

