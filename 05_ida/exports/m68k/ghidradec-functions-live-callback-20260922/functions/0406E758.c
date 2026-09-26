
undefined (*) [84] _fd_get_sectsize_info(int param_1)

{
  undefined (**ppauVar1) [84];
  int *piVar2;
  
  piVar2 = &_fd_density_sectsize;
  if (off_40B13A2 != (undefined (*) [84])0x0) {
    ppauVar1 = &off_40B13A2;
    do {
      if (param_1 == *piVar2) {
        return *ppauVar1;
      }
      ppauVar1 = ppauVar1 + 2;
      piVar2 = piVar2 + 2;
    } while (*ppauVar1 != (undefined (*) [84])0x0);
  }
                    /* WARNING: Subroutine does not return */
  _panic(aFdSectsizeInfo);
}

