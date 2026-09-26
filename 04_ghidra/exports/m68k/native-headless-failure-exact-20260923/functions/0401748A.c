
int _vfs_getmajor(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < (int)(_vfsNVFS + -0x40ae796) >> 3) {
    do {
      (&DAT_040b3444)[iVar1 >> 3] =
           (byte)(1 << (iVar1 + (iVar1 >> 3) * -8 & 0x3fU)) | (&DAT_040b3444)[iVar1 >> 3];
      iVar1 = iVar1 + 1;
    } while (iVar1 < (int)(_vfsNVFS + -0x40ae796) >> 3);
  }
  iVar1 = _vfs_getnum(&DAT_040b3444,0x10);
  if (iVar1 == -1) {
    iVar1 = _vfs_fixedmajor(param_1);
  }
  else {
    iVar1 = iVar1 + 0x80;
  }
  return iVar1;
}

