
undefined8 sub_F00478C4(uint param_1,int param_2,int param_3)

{
  sword sVar1;
  int iVar2;
  undefined4 unaff_l0;
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
  puVar3 = *(undefined4 **)(_stable + (((param_1 & 0xffff) >> 8) + (param_1 & 0xff) & 0xf) * 4);
  if (puVar3 != (undefined4 *)0x0) {
    sVar1 = *(sword *)((int)puVar3 + 0x42);
    do {
      if (sVar1 == (sword)param_1) {
        if (puVar3[0xb] == param_3) {
          iVar2 = puVar3[0xe];
          if ((iVar2 == 0) || (param_2 == 0)) {
loc_F0047974:
            iVar2 = puVar3[0xe];
            goto loc_F0047978;
          }
          if (iVar2 == param_2) {
loc_F0047990:
            sVar1 = *(sword *)((int)puVar3 + 10);
          }
          else {
            if (iVar2 == 0) {
              iVar2 = puVar3[0xe];
loc_F0047978:
              if (iVar2 == 0) {
                if (param_2 == 0) goto loc_F0047990;
                puVar3 = (undefined4 *)*puVar3;
              }
              else {
                puVar3 = (undefined4 *)*puVar3;
              }
              goto loc_F00479A0;
            }
            if (*(int *)(iVar2 + 0x1c) != *(int *)(param_2 + 0x1c)) {
              iVar2 = puVar3[0xe];
              goto loc_F0047978;
            }
            (**(code **)(*(int *)(iVar2 + 0x1c) + 0x6c))(iVar2,param_2);
            if (iVar2 == 0) goto loc_F0047974;
            sVar1 = *(sword *)((int)puVar3 + 10);
          }
          *(sword *)((int)puVar3 + 10) = sVar1 + 1;
          goto locret_F00479B0;
        }
        puVar3 = (undefined4 *)*puVar3;
      }
      else {
        puVar3 = (undefined4 *)*puVar3;
      }
loc_F00479A0:
      if (puVar3 == (undefined4 *)0x0) goto loc_f00479ac;
      sVar1 = *(sword *)((int)puVar3 + 0x42);
    } while( true );
  }
  puVar3 = (undefined4 *)0x0;
locret_F00479B0:
  return CONCAT44(param_2,puVar3);
loc_f00479ac:
  puVar3 = (undefined4 *)0x0;
  goto locret_F00479B0;
}

