
void _mon_boot(int param_1)

{
  _strcat(_boot_param,&_boot_dev);
  _strcat(_boot_param,&asc_40AC3DC);
  if (_boot_info != '\0') {
    _strcat(_boot_param,&_boot_info);
    _strcat(_boot_param,&asc_40AC3DC);
  }
  _strcat(_boot_param,&_boot_file);
  _strcat(_boot_param,&asc_40AC3DC);
  if (param_1 != 0) {
    _strcat(_boot_param,param_1);
    _strcat(_boot_param,&asc_40AC3DC);
  }
  _strcat(_boot_param,_boot_args);
  _mon_call(_boot_param);
  return;
}
