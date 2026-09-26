
void _sbcompress(sword *param_1,undefined4 *param_2,undefined4 *param_3)

{
  uint uVar1;
  sword sVar2;
  undefined4 *puVar3;
  
loc_4014540:
  do {
    while( true ) {
      puVar3 = param_2;
      if (puVar3 == (undefined4 *)0x0) {
        return;
      }
      sVar2 = *(sword *)(puVar3 + 2);
      if (sVar2 != 0) break;
      param_2 = (undefined4 *)_m_free(puVar3);
    }
    if (((param_3 != (undefined4 *)0x0) && (uVar1 = param_3[1], uVar1 < 0x7d)) &&
       ((uint)puVar3[1] < 0x7d)) {
      if (((int)sVar2 + (int)*(sword *)(param_3 + 2) + uVar1 < 0x7d) &&
         (*(sword *)((int)puVar3 + 10) == *(sword *)((int)param_3 + 10))) {
        _bcopy((int)puVar3 + puVar3[1],(int)param_3 + (int)*(sword *)(param_3 + 2) + uVar1,
               (int)sVar2);
        *(sword *)(param_3 + 2) = *(sword *)(puVar3 + 2) + *(sword *)(param_3 + 2);
        *param_1 = *(sword *)(puVar3 + 2) + *param_1;
        param_2 = (undefined4 *)_m_free(puVar3);
        goto loc_4014540;
      }
    }
    *param_1 = *(sword *)(puVar3 + 2) + *param_1;
    sVar2 = param_1[2];
    param_1[2] = sVar2 + 0x80;
    if (0x7c < (uint)puVar3[1]) {
      param_1[2] = sVar2 + 0x480;
    }
    if (param_3 == (undefined4 *)0x0) {
      *(undefined4 **)(param_1 + 6) = puVar3;
    }
    else {
      *param_3 = puVar3;
    }
    param_2 = (undefined4 *)*puVar3;
    *puVar3 = 0;
    param_3 = puVar3;
  } while( true );
}

