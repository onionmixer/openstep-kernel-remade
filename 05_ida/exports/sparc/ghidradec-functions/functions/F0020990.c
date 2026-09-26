
/* WARNING: Removing unreachable block (ram,0xf0020a40) */
/* WARNING: Removing unreachable block (ram,0xf0020a14) */

sword * _sbcompress(sword *param_1,undefined4 *param_2,undefined4 *param_3)

{
  sword sVar1;
  undefined4 *puVar2;
  sword sVar3;
  uint uVar4;
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
  do {
    while( true ) {
      puVar2 = param_2;
      if (puVar2 == (undefined4 *)0x0) {
        return param_1;
      }
      if (*(sword *)(puVar2 + 2) != 0) break;
loc_F0020A40:
      _m_free();
      param_2 = puVar2;
    }
    if (param_3 == (undefined4 *)0x0) {
      sVar3 = *param_1;
    }
    else {
      uVar4 = param_3[1];
      if (uVar4 < 0x7d) {
        if ((uint)puVar2[1] < 0x7d) {
          if (uVar4 + (int)*(sword *)(param_3 + 2) + (int)*(sword *)(puVar2 + 2) < 0x7d) {
            if (*(sword *)((int)param_3 + 10) == *(sword *)((int)puVar2 + 10)) {
              _bcopy((int)puVar2 + puVar2[1],(int)param_3 + (int)*(sword *)(param_3 + 2) + uVar4);
              *(sword *)(param_3 + 2) = *(sword *)(param_3 + 2) + *(sword *)(puVar2 + 2);
              *param_1 = *param_1 + *(sword *)(puVar2 + 2);
              goto loc_F0020A40;
            }
            sVar3 = *param_1;
          }
          else {
            sVar3 = *param_1;
          }
        }
        else {
          sVar3 = *param_1;
        }
      }
      else {
        sVar3 = *param_1;
      }
    }
    sVar1 = param_1[2];
    *param_1 = sVar3 + *(sword *)(puVar2 + 2);
    param_1[2] = sVar1 + 0x80;
    if (0x7c < (uint)puVar2[1]) {
      param_1[2] = sVar1 + 0x480;
    }
    if (param_3 == (undefined4 *)0x0) {
      *(undefined4 **)(param_1 + 6) = puVar2;
    }
    else {
      *param_3 = puVar2;
    }
    param_2 = (undefined4 *)*puVar2;
    *puVar2 = 0;
    param_3 = puVar2;
  } while( true );
}
