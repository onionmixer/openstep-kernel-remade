
void _adb_talk(sword param_1,word param_2,undefined4 *param_3,uint *param_4)

{
  uint uVar1;
  word unaff_D2w;
  uint *puVar2;
  
  puVar2 = (uint *)(_slot_id + 0x2208028);
  sub_40645EA(unaff_D2w & 0xcff | param_1 << 0xc | 0xc00 | (param_2 & 3) << 8,0,0,1);
  if ((*puVar2 & 8) == 0) {
    *param_4 = 0;
  }
  else {
    uVar1 = *(uint *)(_slot_id + 0x2208038) >> 3;
    *param_4 = uVar1;
    if (uVar1 != 0) {
      *param_3 = *(undefined4 *)(_slot_id + 0x2208080);
    }
    if (4 < (int)*param_4) {
      param_3[1] = *(undefined4 *)(_slot_id + 0x2208088);
    }
  }
  return;
}

