
void _od_buf_alloc(void)

{
  int iVar1;
  
  iVar1 = _kmem_alloc_wired(_kernel_map,&_od_label,0x1c48);
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aOdLabelAlloc);
  }
  iVar1 = _kmem_alloc_wired(_kernel_map,&_od_bad_block,0x3000);
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aOdBadBlockAllo);
  }
  iVar1 = _kmem_alloc_wired(_kernel_map,&_od_bitmap,0x10000);
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aOdBitmapAlloc);
  }
  return;
}

