
void _unp_scan(undefined4 *param_1,code *param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  do {
    puVar3 = param_1;
    if (param_1 == (undefined4 *)0x0) {
      return;
    }
    for (; puVar3 != (undefined4 *)0x0; puVar3 = (undefined4 *)*puVar3) {
      if ((*(sword *)((int)puVar3 + 10) == 0xc) && (*(sword *)(puVar3 + 2) != 0)) {
        uVar2 = (uint)(int)*(sword *)(puVar3 + 2) >> 2;
        iVar1 = 0;
        puVar3 = (undefined4 *)(puVar3[1] + (int)puVar3);
        if (uVar2 != 0) {
          do {
            (*param_2)(*puVar3);
            iVar1 = iVar1 + 1;
            puVar3 = puVar3 + 1;
          } while (iVar1 < (int)uVar2);
        }
        break;
      }
    }
    param_1 = (undefined4 *)param_1[0x1f];
  } while( true );
}

