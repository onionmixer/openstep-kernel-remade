/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011a3e8 */

uint * _getblk(uint param_1,uint param_2,uint param_3)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  uint *puVar4;
  undefined4 uVar5;
  
  if (param_1 == 0) {
    _printf(s_vp_0x_x__blkno_0x_x__size_0x_x_001db58a,0,param_2,param_3);
                    /* WARNING: Subroutine does not return */
    _panic(s_getblk__Illegal_vnode_pointer_001db5aa);
  }
  uVar1 = param_2;
  if ((int)param_2 < 0) {
    uVar1 = param_2 + 7;
  }
  uVar1 = ((int)uVar1 >> 3) + param_1 & 0xf;
LAB_0011a432:
  do {
    for (puVar4 = (uint *)(&DAT_001e8884)[uVar1 * 3]; puVar4 != (uint *)(&_bufhash + uVar1 * 0xc);
        puVar4 = (uint *)puVar4[1]) {
      if (((puVar4[9] == param_2) && (puVar4[0x10] == param_1)) && ((*puVar4 & 0x10000) == 0)) {
        uVar2 = _splhigh();
        if ((*puVar4 & 8) == 0) {
          _splx(uVar2);
          uVar2 = _splbio();
          *(uint *)(puVar4[4] + 0xc) = puVar4[3];
          *(uint *)(puVar4[3] + 0x10) = puVar4[4];
          *(byte *)puVar4 = (byte)*puVar4 | 8;
          _splx(uVar2);
          if ((puVar4[5] == param_3) || (iVar3 = _brealloc(puVar4,param_3), iVar3 != 0)) {
            *puVar4 = *puVar4 | 0x8000;
            return puVar4;
          }
        }
        else {
          *puVar4 = *puVar4 | 0x40;
          uVar5 = 0x15;
          _sleep((uint)puVar4);
          _splx(uVar2,puVar4,uVar5);
        }
        goto LAB_0011a432;
      }
    }
    puVar4 = (uint *)_getnewbuf();
    _bfree(puVar4);
    *(uint *)(puVar4[2] + 4) = puVar4[1];
    *(uint *)(puVar4[1] + 8) = puVar4[2];
    FUN_0011b244(puVar4,param_1);
    *(undefined2 *)((int)puVar4 + 0x1e) = *(undefined2 *)(param_1 + 0x2c);
    puVar4[9] = param_2;
    *(undefined2 *)(puVar4 + 7) = 0;
    puVar4[10] = 0;
    puVar4[1] = (&DAT_001e8884)[uVar1 * 3];
    puVar4[2] = (uint)(&_bufhash + uVar1 * 0xc);
    *(uint **)((&DAT_001e8884)[uVar1 * 3] + 8) = puVar4;
    (&DAT_001e8884)[uVar1 * 3] = puVar4;
    iVar3 = _brealloc(puVar4,param_3);
    if (iVar3 != 0) {
      return puVar4;
    }
  } while( true );
}

