
uint sub_40386C0(uint param_1)

{
  uint *puVar1;
  uint uVar2;
  uint *puVar3;
  uint *puVar4;
  
  puVar1 = (uint *)(_lf_svnode_hash + (param_1 & 0x3f) * 4);
  uVar2 = *puVar1;
  puVar3 = puVar1;
  do {
    if (uVar2 == 0) {
      puVar4 = (uint *)_kalloc(0x10);
      *puVar4 = param_1;
      puVar4[1] = 0;
      puVar4[2] = 0;
      *(sword *)(param_1 + 6) = *(sword *)(param_1 + 6) + 1;
loc_4038714:
      puVar4[3] = *puVar1;
      *puVar1 = (uint)puVar4;
loc_403871A:
      return *puVar1;
    }
    puVar4 = (uint *)*puVar3;
    if (param_1 == *puVar4) {
      if (puVar1 == puVar3) goto loc_403871A;
      *puVar3 = puVar4[3];
      goto loc_4038714;
    }
    puVar3 = puVar4 + 3;
    uVar2 = *puVar3;
  } while( true );
}
