
void _vnode_pager_init(void)

{
  _vstruct_zone = _zinit(0x18,240000,_page_size,0,aVnodePagerStru);
  dword_40B4DF8 = &dword_40B4DF4;
  dword_40B4DF4 = &dword_40B4DF4;
  return;
}

