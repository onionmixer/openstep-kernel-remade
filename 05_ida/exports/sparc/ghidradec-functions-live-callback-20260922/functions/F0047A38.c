
/* WARNING: Removing unreachable block (ram,0xf0047aa8) */
/* WARNING: Removing unreachable block (ram,0xf0047a64) */

sqword sub_F0047A38(undefined4 param_1,uint param_2)

{
  word wVar1;
  undefined4 unaff_l0;
  undefined *puVar2;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 *puVar3;
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
  if (dword_F012F56C == 0) {
    dword_F012F56C = 1;
    puVar2 = _stable;
    puVar3 = (undefined4 *)_stable._0_4_;
    do {
      if (puVar3 != (undefined4 *)0x0) {
        wVar1 = *(word *)(puVar3 + 2);
        do {
          if ((wVar1 & 0x80) == 0) {
            if (puVar3[0xb] == 3) {
              _bflush(puVar3 + 1,0xffffffff,0xffffffff);
              goto loc_F0047AB0;
            }
            puVar3 = (undefined4 *)*puVar3;
          }
          else {
loc_F0047AB0:
            puVar3 = (undefined4 *)*puVar3;
          }
          if (puVar3 == (undefined4 *)0x0) break;
          wVar1 = *(word *)(puVar3 + 2);
        } while( true );
      }
      puVar2 = (undefined *)((int)puVar2 + 4);
      if (_stable + 0x3f < puVar2) goto loc_F0047AD4;
      puVar3 = *(undefined4 **)puVar2;
    } while( true );
  }
locret_F0047AD8:
  return (qword)param_2 << 0x20;
loc_F0047AD4:
  dword_F012F56C = 0;
  goto locret_F0047AD8;
}

