
/* WARNING: Removing unreachable block (ram,0xf0024bf4) */
/* WARNING: Removing unreachable block (ram,0xf0024bc8) */
/* WARNING: Removing unreachable block (ram,0xf0024b7c) */
/* WARNING: Removing unreachable block (ram,0xf0024b4c) */
/* WARNING: Removing unreachable block (ram,0xf0024b34) */
/* WARNING: Removing unreachable block (ram,0xf0024a94) */
/* WARNING: Removing unreachable block (ram,0xf0024b10) */
/* WARNING: Removing unreachable block (ram,0xf0024b3c) */
/* WARNING: Removing unreachable block (ram,0xf0024b54) */
/* WARNING: Removing unreachable block (ram,0xf0024b94) */
/* WARNING: Removing unreachable block (ram,0xf0024bd0) */
/* WARNING: Removing unreachable block (ram,0xf0024c2c) */
/* WARNING: Removing unreachable block (ram,0xf0024a88) */

undefined8 _getblk(uint *param_1,uint *param_2,uint param_3)

{
  uint *puVar1;
  undefined *puVar2;
  uint *puVar3;
  int iVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint *puVar5;
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
  if (param_1 == (uint *)0x0) {
    _printf(aVp0xXBlkno0xXS,0,param_2,param_3);
    _panic(aGetblkIllegalV);
  }
  puVar1 = param_2;
  if ((int)param_2 < 0) {
    puVar1 = (uint *)((int)param_2 + 7);
  }
  iVar4 = ((uint)((int)param_1 + ((int)puVar1 >> 3)) & 0xf) * 0xc;
  puVar2 = _bufhash;
  puVar5 = (uint *)(_bufhash + iVar4);
  puVar1 = *(uint **)(_bufhash + iVar4 + 4);
loc_F0024AD4:
  do {
    if (puVar1 != puVar5) {
      puVar2 = (undefined *)puVar1[9];
      while( true ) {
        if ((uint *)puVar2 == param_2) {
          puVar2 = (undefined *)puVar1[0x10];
          if ((uint *)puVar2 == param_1) {
            puVar2 = (undefined *)*puVar1;
            if (((uint)puVar2 & 0x10000) == 0) {
              _splusclock();
              if ((*puVar1 & 8) != 0) {
                *puVar1 = *puVar1 | 0x40;
                _sleep(puVar1,0x15);
                _splx();
                puVar1 = *(uint **)(_bufhash + iVar4 + 4);
                goto loc_F0024AD4;
              }
              _splx(puVar2);
              _spltty();
              *(uint *)(puVar1[4] + 0xc) = puVar1[3];
              *(uint *)(puVar1[3] + 0x10) = puVar1[4];
              *puVar1 = *puVar1 | 8;
              _splx();
              if ((puVar1[5] == param_3) ||
                 (puVar3 = puVar1, _brealloc(puVar1,param_3), puVar3 != (uint *)0x0)) {
                *puVar1 = *puVar1 | 0x8000;
                goto locret_F0024C40;
              }
              puVar1 = *(uint **)(_bufhash + iVar4 + 4);
              puVar2 = (undefined *)0x0;
              goto loc_F0024AD4;
            }
            puVar1 = (uint *)puVar1[1];
          }
          else {
            puVar1 = (uint *)puVar1[1];
          }
        }
        else {
          puVar1 = (uint *)puVar1[1];
        }
        if (puVar1 == puVar5) break;
        puVar2 = (undefined *)puVar1[9];
      }
    }
    _getnewbuf();
    _bfree();
    *(uint *)(*(uint *)((int)puVar2 + 8) + 4) = *(uint *)((int)puVar2 + 4);
    *(uint *)(*(uint *)((int)puVar2 + 4) + 8) = *(uint *)((int)puVar2 + 8);
    sub_F002565C(puVar2,param_1);
    *(undefined2 *)((int)puVar2 + 0x1e) = *(undefined2 *)(param_1 + 0xb);
    *(uint **)((int)puVar2 + 0x24) = param_2;
    *(undefined2 *)((int)puVar2 + 0x1c) = 0;
    *(uint *)((int)puVar2 + 0x28) = 0;
    *(uint *)((int)puVar2 + 4) = *(uint *)(_bufhash + iVar4 + 4);
    *(uint **)((int)puVar2 + 8) = puVar5;
    *(undefined **)(*(int *)(_bufhash + iVar4 + 4) + 8) = puVar2;
    *(undefined **)(_bufhash + iVar4 + 4) = puVar2;
    puVar3 = (uint *)puVar2;
    _brealloc(puVar2,param_3);
    puVar1 = (uint *)puVar2;
    if (puVar3 != (uint *)0x0) {
locret_F0024C40:
      return CONCAT44(param_2,puVar1);
    }
    puVar1 = *(uint **)(_bufhash + iVar4 + 4);
    puVar2 = (undefined *)0x0;
  } while( true );
}

