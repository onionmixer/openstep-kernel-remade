
void _pmap_page_protect(undefined4 param_1,int param_2)

{
  if (param_2 == 5) {
loc_4098EE2:
    _pmap_copy_on_write(param_1);
  }
  else {
    if (param_2 < 6) {
      if (param_2 == 1) goto loc_4098EE2;
    }
    else if (param_2 == 7) {
      return;
    }
    _pmap_remove_all(param_1);
  }
  return;
}

