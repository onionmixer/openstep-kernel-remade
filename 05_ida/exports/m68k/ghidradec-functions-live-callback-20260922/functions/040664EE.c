
void sub_40664EE(int param_1,int param_2)

{
  if ((((*(uint *)(param_2 + 0xc) & 1) != 0) || ((*(uint *)(param_2 + 7) & 0xfffffff) >> 0x18 == 0))
     && (((*(uint *)(param_2 + 0xc) & 1) == 0 || ((*(uint *)(param_2 + 7) & 0x3ffffff) >> 0x18 == 0)
         ))) {
    _cache_flush(*(undefined4 *)(param_2 + 4),*(undefined4 *)(param_2 + 8),
                 *(undefined4 *)(param_1 + 0x20));
    *(uint *)(param_2 + 0xc) = *(uint *)(param_2 + 0xc) | 2;
    return;
  }
                    /* WARNING: Subroutine does not return */
  _panic(aDmaPrepBadDmaB);
}

