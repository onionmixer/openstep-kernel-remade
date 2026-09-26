
void _file_init(void)

{
  dword_40B59C8 = &_file_list;
  _file_list = &_file_list;
  _file_zone = _zinit(0x22,_max_file * 0x22,0,0,aFileStructs);
  return;
}
